
set(BUILD_ARCH ${TARGET_ARCH})

if(TARGET_VERBOSE)
	set(CMAKE_VERBOSE_MAKEFILE 1)
endif()


set(BUILD_OPTIMIZATION "-Os")
set(LINKER_FILE ${TARGET_LINKER_FILE})


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/elf/${TARGET_NAME}_${TARGET_CONFIG})

message(STATUS "Target build float flags ${TARGET_BUILD_FLOAT_OPTIONS}")
set(BUILD_FLAGS ${TARGET_BUILD_FLOAT_OPTIONS} ${BUILD_OPTIMIZATION} ${TARGET_BUILD_FLAGS} )
set(LINKER_FLAGS
	"${TARGET_LINKER_FLAGS} -L${CMAKE_SOURCE_DIR}/ldscript -Wl,--print-memory-usage,-Map,${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TARGET_NAME}_${TARGET_CONFIG}.map,--gc-sections -T${LINKER_FILE} -nostdlib -u target_startup"
	)
set(BUILD_TARGET ${TARGET_NAME}_${TARGET_CONFIG}.elf)


add_executable(${BUILD_TARGET} ${TARGET_SOURCELIST})
add_custom_target(bin_${TARGET_NAME}_${TARGET_CONFIG} DEPENDS ${BUILD_TARGET} COMMAND ${CMAKE_OBJCOPY} -j .boot_hdr -j .text -j .data -O binary ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BUILD_TARGET} ${CMAKE_SOURCE_DIR}/binary/${TARGET_NAME}_${TARGET_CONFIG}.bin)
add_custom_target(asm_${TARGET_NAME}_${TARGET_CONFIG} DEPENDS bin_${TARGET_NAME}_${TARGET_CONFIG} COMMAND ${CMAKE_OBJDUMP} -S -j .boot_hdr -j .tcim -j .text -j .priv_code -j .data -j .bss -j .sysmem -d ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BUILD_TARGET} > ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TARGET_NAME}.lst)
add_custom_target(size_${TARGET_NAME}_${TARGET_CONFIG} DEPENDS asm_${TARGET_NAME}_${TARGET_CONFIG} COMMAND ${CMAKE_SIZE} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BUILD_TARGET})
add_custom_target(${TARGET_CONFIG} ALL DEPENDS size_${TARGET_NAME}_${TARGET_CONFIG})

target_compile_definitions(${BUILD_TARGET} PUBLIC ${TARGET_DEFINITIONS})
set_target_properties(${BUILD_TARGET} PROPERTIES LINK_FLAGS ${LINKER_FLAGS})
target_compile_options(${BUILD_TARGET} PUBLIC ${BUILD_FLAGS})

if(TARGET_INCLUDE_DIRECTORIES)
	target_include_directories(${BUILD_TARGET} PUBLIC ${TARGET_INCLUDE_DIRECTORIES})
endif()

target_include_directories(${BUILD_TARGET} PUBLIC ${tSOS_BUILD_SYSTEM_INCLUDES})