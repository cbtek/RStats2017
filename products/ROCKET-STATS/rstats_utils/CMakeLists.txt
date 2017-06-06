#==============================================================================
# CMakeLists file for ROCKET-STATS
#==============================================================================
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CURR_TARGET rstats_utils)

set(CURR_TARGET_SOURCES "${CURR_TARGET}_SOURCES")
set(CURR_TARGET_HEADERS "${CURR_TARGET}_HEADERS")

include_directories(inc)
include_directories(inc/streams)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#==============================================================================
# Unit Test modules
#==============================================================================
if (${ENABLE_RSTATS_UTILS_UNIT_TESTS})
    add_subdirectory(tests)
endif()

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
                 common_utils
                 basic_excel
                 mini_excel)


target_link_libraries(${CURR_TARGET}
                 common_utils
                 basic_excel
                 mini_excel)
