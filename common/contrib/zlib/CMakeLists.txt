#==============================================================================
# CMakeLists file for zlib
#==============================================================================
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CURR_TARGET zlib)
set(CURR_TARGET_SOURCES "${CURR_TARGET}_SOURCES")
set(CURR_TARGET_HEADERS"${CURR_TARGET}_HEADERS")
include(${CMAKE_MODULE_PATH}/flags.cmake)

include_directories(inc)
include_directories(src)

if (${ENABLE_ZLIB_UNIT_TESTS})
    add_subdirectory(tests)
endif()

#==============================================================================
# Include Source Files
#==============================================================================
file(GLOB CURR_TARGET_SOURCES "src/zlib.c*")
file(GLOB CURR_TARGET_HEADERS "inc/zlib.h*")  
                              
#==============================================================================
# Add Library
#==============================================================================
add_library(${CURR_TARGET}
            ${LIBRARY_MODE}
            ${CURR_TARGET_SOURCES}
            ${CURR_TARGET_HEADERS})
        
        

