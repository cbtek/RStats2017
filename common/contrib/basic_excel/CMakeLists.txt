#==============================================================================
# CMakeLists file for common_utils
#==============================================================================
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CURR_TARGET basic_excel)
set(CURR_TARGET_SOURCES "${CURR_TARGET}_SOURCES")
set(CURR_TARGET_HEADERS"${CURR_TARGET}_HEADERS")
include(${CMAKE_MODULE_PATH}/flags.cmake)

include_directories(inc)
include_directories(src)

#==============================================================================
# Include Source Files
#==============================================================================
file(GLOB CURR_TARGET_SOURCES "src/*.cpp")
file(GLOB CURR_TARGET_HEADERS "inc/*.h*")

#==============================================================================
# Add Library
#==============================================================================
add_library(${CURR_TARGET}
            ${LIBRARY_MODE}
            ${CURR_TARGET_SOURCES}
            ${CURR_TARGET_HEADERS})