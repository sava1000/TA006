################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/RB/workspace_v10/TA006" --include_path="C:/Users/RB/workspace_v10/TA006/Debug" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_5_10_00_48/source" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_5_10_00_48/kernel/nortos" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_5_10_00_48/kernel/nortos/posix" --include_path="C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/include" --define=DeviceFamily_CC13X2 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/RB/workspace_v10/TA006/Debug/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-581251713: ../uartecho.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/sysconfig_1_8_0/sysconfig_cli.bat" -s "C:/ti/simplelink_cc13x2_26x2_sdk_5_10_00_48/.metadata/product.json" --script "C:/Users/RB/workspace_v10/TA006/uartecho.syscfg" -o "syscfg" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/ti_devices_config.c: build-581251713 ../uartecho.syscfg
syscfg/ti_drivers_config.c: build-581251713
syscfg/ti_drivers_config.h: build-581251713
syscfg/ti_utils_build_linker.cmd.genlibs: build-581251713
syscfg/syscfg_c.rov.xs: build-581251713
syscfg/ti_utils_runtime_model.gv: build-581251713
syscfg/ti_utils_runtime_Makefile: build-581251713
syscfg/: build-581251713

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/RB/workspace_v10/TA006" --include_path="C:/Users/RB/workspace_v10/TA006/Debug" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_5_10_00_48/source" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_5_10_00_48/kernel/nortos" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_5_10_00_48/kernel/nortos/posix" --include_path="C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/include" --define=DeviceFamily_CC13X2 -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/RB/workspace_v10/TA006/Debug/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


