# This file contains compiler flags for different platforms

if(CMAKE_BUILD_TYPE MATCHES Debug)
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_ROOT}/bin/TeamCBTek/debug")
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_ROOT}/bin/TeamCBTek/debug")
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_ROOT}/bin/TeamCBTek/debug")
elseif(CMAKE_BUILD_TYPE MATCHES Default)
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_ROOT}/bin/TeamCBTek/default")
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_ROOT}/bin/TeamCBTek/default")
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_ROOT}/bin/TeamCBTek/default")
else()
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_ROOT}/bin/TeamCBTek/release")
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_ROOT}/bin/TeamCBTek/release")
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_ROOT}/bin/TeamCBTek/release")
endif()
