
#==============================================================================
# CMakeLists file for gooeyfi_launcher
#==============================================================================
cmake_minimum_required(VERSION 3.0)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CURR_TARGET gooeyfi_launcher)
project(${CURR_TARGET})
set(CURR_TARGET_SOURCES "${CURR_TARGET}_SOURCES")
set(CURR_TARGET_HEADERS "${CURR_TARGET}_HEADERS")
set(CURR_TARGET_FORMS "${CURR_TARGET}_FORMS")

set (USE_QT_PLATFORM ON)

include(${CMAKE_MODULE_PATH}/flags.cmake)

if (USE_QT_PLATFORM)
    include_directories(inc)
    include_directories(inc/platform/qt)
else()
    include_directories(inc)
    include_directories(inc/platform/imgui)
endif()


set(CMAKE_INCLUDE_CURRENT_DIR ON)

if (USE_QT_PLATFORM)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_AUTOUIC ON)
    find_package(Qt5Widgets REQUIRED)
    add_definitions(${Qt5Widgets_DEFINITIONS})
    set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
endif()

#==============================================================================
# Include Source Files
#==============================================================================

if (USE_QT_PLATFORM)
    file(GLOB CURR_TARGET_SOURCES "src/*.cpp" "src/platform/qt/*.cpp")
    file(GLOB CURR_TARGET_FORMS "src/*.ui" "src/platform/qt/*.ui")
    file(GLOB CURR_TARGET_HEADERS "inc/*.h*" "inc/platform/qt/*.h*")    
else()
    file(GLOB CURR_TARGET_SOURCES "src/*.cpp" "src/platform/imgui/*.cpp")
    file(GLOB CURR_TARGET_HEADERS "inc/*.h*" "inc/platform/imgui/*.h*")    
endif()


#==============================================================================
# Add Executable
#==============================================================================
add_library(${CURR_TARGET}
               ${CURR_TARGET_SOURCES}
               ${CURR_TARGET_HEADERS}
               ${CURR_TARGET_FORMS}
               )

#==============================================================================
# Add Dependencies
#==============================================================================

if (USE_QT_PLATFORM)

    qt5_use_modules(${CURR_TARGET}
                     Widgets)

    add_dependencies(${CURR_TARGET}
                      gooeyfi_core
                      common_utils)
else()

    add_dependencies(${CURR_TARGET}
                      gooeyfi_core
                      imgui
                      glfw
                      common_utils)
endif()

##==============================================================================
## Target Link Libraries
##==============================================================================

#if (USE_QT_PLATFORM)
#    target_link_libraries(${CURR_TARGET}
#                            gooeyfi_core
#                            common_utils
#                            ${Qt5Widgets_LIBRARIES})
#else()
#    target_link_libraries(${CURR_TARGET}
#                            gooeyfi_core
#                            imgui
#                            glfw
#                            opengl32
#                            common_utils)
#endif()


