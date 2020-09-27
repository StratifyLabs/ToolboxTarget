

set(STM32_PATH ${CMAKE_SOURCE_DIR}/src/family/stm32)

set(STM32_COMMON_FILES
  ${TARGET_COMMON_FILES}
  ${STM32_PATH}/stm32_flash.c
	${STM32_PATH}/stm32_flash.h
	${STM32_PATH}/stm32_common.h
	)

set(TARGET_INCLUDE_DIRECTORIES
	${TARGET_COMMON_INCLUDE_DIRECTORIES}
	${STM32_PATH}/h7)

set(TARGET_BUILD_FLAGS -mthumb -march=armv7e-m)
set(TARGET_CONFIG STM32H7)
set(TARGET_LINKER_FILE ${CMAKE_SOURCE_DIR}/ldscript/stm32h7xx.ld)
set(TARGET_DEFINITIONS -DSTM32H7=1 -D_TARGET_RAM_WORKAREA_SIZE=4096)
set(TARGET_SOURCELIST
  ${STM32_COMMON_FILES}
	${CMAKE_SOURCE_DIR}/ldscript/stm32h7xx.ld
	${CMAKE_SOURCE_DIR}/ldscript/sections.ld
	${STM32_PATH}/h7/stm32h7xx_hal_flash_ex.c
  ${STM32_PATH}/h7/stm32h7xx_hal_flash_ex.h
  ${STM32_PATH}/h7/stm32h7xx_hal_flash.c
  ${STM32_PATH}/h7/stm32h7xx_hal_flash.h
	${STM32_PATH}/h7/stm32h7.c
	${STM32_PATH}/h7/stm32h7xx_hal.h
)

include(target.cmake)

set(TARGET_INCLUDE_DIRECTORIES
	${TARGET_COMMON_INCLUDE_DIRECTORIES}
	${STM32_PATH}/f4)

set(TARGET_BUILD_FLAGS -mthumb -march=armv7e-m)
set(TARGET_CONFIG STM32F4)
set(TARGET_LINKER_FILE ${CMAKE_SOURCE_DIR}/ldscript/stm32f4xx.ld)
set(TARGET_DEFINITIONS -DSTM32F4=1 -D_TARGET_RAM_WORKAREA_SIZE=1024)
set(TARGET_SOURCELIST
	${STM32_COMMON_FILES}
	${CMAKE_SOURCE_DIR}/ldscript/stm32f4xx.ld
	${CMAKE_SOURCE_DIR}/ldscript/sections.ld
	${STM32_PATH}/f4/stm32f4xx_hal_flash_ex.c
	${STM32_PATH}/f4/stm32f4xx_hal_flash_ex.h
	${STM32_PATH}/f4/stm32f4xx_hal_flash.c
	${STM32_PATH}/f4/stm32f4xx_hal_flash.h
	${STM32_PATH}/f4/stm32f4.c
	${STM32_PATH}/f4/stm32f4xx_hal.h
)

include(target.cmake)
