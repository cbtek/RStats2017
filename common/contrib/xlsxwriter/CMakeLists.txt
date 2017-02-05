#==============================================================================
# CMakeLists file for xlsxwriter
#==============================================================================
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CURR_TARGET xlsxwriter)
set(CURR_TARGET_SOURCES "${CURR_TARGET}_SOURCES")
set(CURR_TARGET_HEADERS"${CURR_TARGET}_HEADERS")
include(${CMAKE_MODULE_PATH}/flags.cmake)

include_directories(inc)
include_directories(src)

if (${ENABLE_XLSXWRITER_UNIT_TESTS})
    add_subdirectory(tests)
endif()

#==============================================================================
# Include Source Files
#==============================================================================
file(GLOB CURR_TARGET_SOURCES "src/*.c*" "contrib/minizip/*.c" "contrib/tmpfileplus/*.c")
file(GLOB CURR_TARGET_HEADERS "inc/*.h*" "contrib/minizip/*.h*" "contrib/tmpfileplus/*.h*")                            
                              
#==============================================================================
# Add Library
#==============================================================================
add_library(${CURR_TARGET}
            ${LIBRARY_MODE}
            ${CURR_TARGET_SOURCES}
            ${CURR_TARGET_HEADERS})

add_dependencies(${CURR_TARGET} minizip zlib)



