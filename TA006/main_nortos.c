/*  Библиотеке.    */
#include <stdint.h>             //  Неопгодно за UART. Видети дијаграм на страници драјвера. Вероватно треба и за друге драјвере.
#include <stddef.h>             //  Неопгодно за UART. Видети дијаграм на страници драјвера. Вероватно треба и за друге драјвере.
#include <NoRTOS.h>             //  За рад без оперативног система. Не треба, али као боље ради са њим.
#include <ti/drivers/GPIO.h>    //  Библиотека за дигиталне улазе и излазе.
#include <ti/drivers/UART.h>    //  Библиотека за први UART.
#include <ti/drivers/UART2.h>   //  Библиотека за други UART. Направљено је као додатак библиотеци UART.h.
#include <ti/drivers/Board.h>   //  ?????? Не ради без тога...
#include "ti_drivers_config.h"  //  ?????? Конфигурациона библиотека. Вероватно за подешавање ножица. Ножице се подешавају преко .syscfg
#include <string.h>             //  За стрингове.
//#include <Driver_flash.h>       //  Драјвер за меморију.
//#include <ti/drivers/SPI.h>     //  Библиотека за SPI.
 
extern void *mainThread(void *arg0);
  
int main(void)
   {
    Board_init();
    NoRTOS_start();
    mainThread(NULL);
//    while (1) {}
   }

void *mainThread(void *arg0)
{
//  Укључивање функција.
    GPIO_init();
    UART_init();
    Board_init();
    NoRTOS_start();
//    SPI_init();

//  Конфигуриши светлосне диоде.
    GPIO_setConfig(CONFIG_GPIO_LED_0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);  // ? Некако успе да ради и без овога...
    GPIO_setConfig(CONFIG_GPIO_LED_1, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);  // ? Некако успе да ради и без овога...


////////////////    UART.   //////////////////////////////////////////////////////////////////////////////////////////////

//  Конфигуриши UART0.
    char input0[256];
    UART_Handle uart0;
    UART_Params params0;
    UART_Params_init(&params0);
    params0.writeDataMode = UART_DATA_BINARY;
    params0.readDataMode = UART_DATA_BINARY;
    params0.readReturnMode = UART_RETURN_FULL;
    params0.baudRate = 115200;
    uart0 = UART_open(CONFIG_UART_0, &params0);

//  Конфигуриши UART1.
    char input1[256];
    UART2_Handle uart1;
    UART2_Params params1;
    UART2_Params_init(&params1);
    params1.readMode = UART2_Mode_BLOCKING;
    params1.writeMode = UART2_Mode_BLOCKING;
    params1.baudRate = 115200;
    uart1 = UART2_open(CONFIG_UART2_0, &params1);
    UART2_rxEnable(uart1);  //?


    if (uart0 || uart1 == NULL)
    {
         while (1);
    }

//  Подешавање стрингова.   //////////////////////////////////////////////////////////

    char *tmp0 = input0;
    char *tmp1 = input1;
    char count0 = 0;
    char count1 = 0;
    tmp0 = input0;
    tmp1 = input1;
    count0 = 0;
    count1 = 0;

    while(1)
    {
//      Подешавање стринга за UART0.
        UART_read(uart0, tmp0+count0, 1);

        if(*(tmp0+count0) == 13)      // 13 је у Аски коду cartridge return.
        {
            count0 = 0;
            *(tmp0+count0) = 0;
        }
        else
        {
            count0++;
        }
        *(tmp0+count0+1) = 0;

//      Подешавање стринга за UART1.
        size_t bytesRead;
        UART2_read(uart1, tmp1+count1, 1, &bytesRead);

        if(*(tmp1+count1) == 13)      // 13 је у Аски коду cartridge return.
        {
            count1 = 0;
            *(tmp1+count1) = 0;
        }
        else
        {
            count1++;
        }
        *(tmp1+count1+1) = 0;


//  Испис на UART.   /////////////////////////////////////////////////////////////////

        if(!strcmp(tmp0, "Укључи црвену диоду"))              //  Ако је примљена порука *** зкључи зелену светлосну диоду и испиши да је укључена.
        {
            GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_ON);
            UART_write(uart0, "Црвена светлећа диода је укључена", sizeof("Црвена светлећа диода је укључена"));
        }
        else if(!strcmp(tmp0, "Искључи црвену диоду"))        //  Осим ако је примљена порука ***, онда искључи зелену светлосну диоду и испиши да је искључена.
        {
            GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_OFF);
            UART_write(uart0, "Црвена светлећа диода је искључена", sizeof("Црвена светлећа диода је искључена"));
        }
        else if(!strcmp(tmp1, "Укључи зелену диоду"))
        {
            GPIO_write(CONFIG_GPIO_LED_1, CONFIG_GPIO_LED_ON);
            size_t  bytesWritten;
            UART2_write(uart1, "Зелена светлећа диода је укључена", sizeof("Зелена светлећа диода је укључена"), &bytesWritten);
        }
        else if(!strcmp(tmp1, "Искључи зелену диоду"))
        {
            GPIO_write(CONFIG_GPIO_LED_1, CONFIG_GPIO_LED_OFF);
            size_t  bytesWritten;
            UART2_write(uart1, "Зелена светлећа диода је искључена", sizeof("Зелена светлећа диода је искључена"), &bytesWritten);
        }
//         return (NULL);
    }
}




