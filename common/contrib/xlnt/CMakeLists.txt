#==============================================================================
# CMakeLists file for xlnt
#==============================================================================
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CURR_TARGET xlnt)
set(CURR_TARGET_SOURCES "${CURR_TARGET}_SOURCES")
set(CURR_TARGET_HEADERS"${CURR_TARGET}_HEADERS")
include(${CMAKE_MODULE_PATH}/flags.cmake)

include_directories(inc)
include_directories(src)

if (${ENABLE_XLNT_UNIT_TESTS})
    add_subdirectory(tests)
endif()

#==============================================================================
# Include Source Files
#==============================================================================
file(GLOB CURR_TARGET_SOURCES "src/cell/*.cpp"
                            "src/detail/*.cpp"
                            "src/packaging/*.cpp"
                            "src/styles/*.cpp"
                            "src/utils/*.cpp"
                            "src/workbook/*.cpp"
                            "src/worksheet/*.cpp")
                            
file(GLOB CURR_TARGET_HEADERS "inc/xlnt/*.h*"
                              "inc/xlnt/cell/*.h*"
                              "inc/xlnt/detail/*.h*"
                              "inc/xlnt/packaging/*.h*"
                              "inc/xlnt/styles/*.h*"
                              "inc/xlnt/utils/*.h*"
                              "inc/xlnt/workbook/*.h*"
                              "inc/xlnt/worksheet/*.h*")                            
                              
#==============================================================================
# Add Library
#==============================================================================
add_library(${CURR_TARGET}
            ${LIBRARY_MODE}
            ${CURR_TARGET_SOURCES}
            ${CURR_TARGET_HEADERS})

