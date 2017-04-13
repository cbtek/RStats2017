
#==============================================================================
# CMakeLists file for CMake rstats_main
#==============================================================================
cmake_minimum_required(VERSION 3.0)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CURR_TARGET rstats)

set(CURR_TARGET_SOURCES "${CURR_TARGET}_SOURCES")
set(CURR_TARGET_FORMS "${CURR_TARGET}_FORMS")
set(CURR_TARGET_HEADERS "${CURR_TARGET}_HEADERS")
set(CURR_TARGET_HEADERS_NO_MOC "${CURR_TARGET}_HEADERS_NO_MOC")
set(CURR_TARGET_RESOURCES "${CURR_TARGET}_RESOURCES")

include_directories(src)
include_directories(inc)
include_directories(resx)

include(${CMAKE_MODULE_PATH}/flags.cmake)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Widgets REQUIRED)

#==============================================================================
# Include Source Files
#==============================================================================
file(GLOB CURR_TARGET_SOURCES "src/*.cpp")
file(GLOB CURR_TARGET_HEADERS "inc/*.h*")
file(GLOB CURR_TARGET_FORMS "src/*.ui")
file(GLOB CURR_TARGET_RESOURCES "resx/*.qrc")

#==============================================================================
# Add Executable
#==============================================================================
add_executable(${CURR_TARGET}
			   ${PLATFORM}
               ${CURR_TARGET_SOURCES}
               ${CURR_TARGET_HEADERS}
               ${CURR_TARGET_FORMS}
               ${CURR_TARGET_RESOURCES}
               )

#==============================================================================
# Add Dependencies
#==============================================================================

qt5_use_modules(${CURR_TARGET}
                 Widgets)

add_dependencies(${CURR_TARGET}
                rstats_ui                
                Qt5::Widgets
                rstats_utils
                common_utils)


#==============================================================================
# Target Link Libraries
#==============================================================================
target_link_libraries(${CURR_TARGET}
                      rstats_ui                      
                      Qt5::Widgets
                      rstats_utils
                      common_utils
                      )

# Copy templates folder to build directory
# so that the exe can see them

add_custom_command(TARGET ${CURR_TARGET} POST_BUILD
               COMMAND ${CMAKE_COMMAND} -E copy_directory
               ${PROJECT_SOURCE_DIR}/rstats_resx $<TARGET_FILE_DIR:${CURR_TARGET}>/resx)


add_custom_command(TARGET ${CURR_TARGET} POST_BUILD
              COMMAND ${CMAKE_COMMAND} -E copy_directory
              ${PROJECT_SOURCE_DIR}/rstats_config $<TARGET_FILE_DIR:${CURR_TARGET}>/config)

add_custom_command(TARGET ${CURR_TARGET} POST_BUILD
              COMMAND ${CMAKE_COMMAND} -E copy_directory
              ${PROJECT_SOURCE_DIR}/rstats_contrib $<TARGET_FILE_DIR:${CURR_TARGET}>/contrib)




