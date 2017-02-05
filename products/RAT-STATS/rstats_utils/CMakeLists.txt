#==============================================================================
# CMakeLists file for RAT-STATS
#==============================================================================
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CURR_TARGET rstats_utils)

set(CURR_TARGET_SOURCES "${CURR_TARGET}_SOURCES")
set(CURR_TARGET_HEADERS "${CURR_TARGET}_HEADERS")

include_directories(inc)
include_directories(inc/streams)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#==============================================================================
# Include Source Files
#==============================================================================
file(GLOB CURR_TARGET_SOURCES "src/*.cpp" "src/streams/*.cpp")
file(GLOB CURR_TARGET_HEADERS "inc/*.h*" "inc/streams/*.h*")

#==============================================================================
# Add Executable
#==============================================================================
add_library(${CURR_TARGET}           
               ${CURR_TARGET_SOURCES}
               ${CURR_TARGET_HEADERS}               
               )

#==============================================================================
# Add Dependencies
#==============================================================================

add_dependencies(${CURR_TARGET}                 
                 common_utils)
