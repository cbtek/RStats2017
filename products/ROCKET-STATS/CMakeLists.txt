#####################################################
#!This file is autogenerated by the CBTek ProjectGen
#####################################################
cmake_minimum_required(VERSION 3.0)
project(ROCKET-STATS)
add_subdirectory("${PROJECT_SOURCE_DIR}/rstats_utils")
add_subdirectory("${PROJECT_SOURCE_DIR}/rstats_ui")
add_subdirectory("${PROJECT_SOURCE_DIR}/rstats_main")

#Internal Modules
add_subdirectory("${PROJECT_SOURCE_DIR}/rstats_modules/generic_random_numbers")
add_subdirectory("${PROJECT_SOURCE_DIR}/rstats_modules/single_stage_random_numbers")
add_subdirectory("${PROJECT_SOURCE_DIR}/rstats_modules/unrestricted_attribute_appraisal")
add_subdirectory("${PROJECT_SOURCE_DIR}/rstats_modules/unrestricted_variable_appraisal")
add_subdirectory("${PROJECT_SOURCE_DIR}/rstats_modules/stratified_variable_appraisal")
