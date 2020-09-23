

set(STM32_PATH ${CMAKE_SOURCE_DIR}/src/target/stm32)

set(STM32_COMMON_FILES
  ${TARGET_COMMON_FILES}
  ${STM32_PATH}/stm32_flash.c
  ${STM32_PATH}/stm32_flash.h
  )

set(TARGET_INCLUDE_DIRECTORIES
	${TARGET_COMMON_INCLUDE_DIRECTORIES}
	${CMAKE_SOURCE_DIR}/src/stm32/h7)
set(TARGET_BUILD_FLAGS -mthumb -march=armv7e-m)
set(TARGET_CONFIG STM32H7)
set(TARGET_LINKER_FILE ${CMAKE_SOURCE_DIR}/ldscript/stm32h7xx.ld)
set(TARGET_DEFINITIONS -DSTM32H7=1)
set(TARGET_SOURCELIST
  ${STM32_COMMON_FILES}
	${CMAKE_SOURCE_DIR}/ldscript/stm32h7xx.ld
	${CMAKE_SOURCE_DIR}/ldscript/sections.ld
	${STM32_PATH}/h7/stm32h7xx_hal_flash_ex.c
  ${STM32_PATH}/h7/stm32h7xx_hal_flash_ex.h
  ${STM32_PATH}/h7/stm32h7xx_hal_flash.c
  ${STM32_PATH}/h7/stm32h7xx_hal_flash.h
	${STM32_PATH}/h7/stm32h7xx_hal.h
)

include(target.cmake)
