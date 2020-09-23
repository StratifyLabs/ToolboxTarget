cmake_minimum_required (VERSION 3.12)

set(TARGET_TOOLCHAIN_HOST_PREFIX arm-none-eabi-)
set(TARGET_TOOLCHAIN_DIR /Applications/StratifyLabs-SDK/Tools/gcc)
include(toolchain.cmake)

set(TARGET_NAME ToolboxTarget)
project(${TARGET_NAME} C)

set(TARGET_COMMON_FILES
	${CMAKE_SOURCE_DIR}/src/target.c
	${CMAKE_SOURCE_DIR}/src/target.h
)

set(TARGET_COMMON_INCLUDE_DIRECTORIES
	${CMAKE_SOURCE_DIR}/src
)

include(stm32.cmake)



