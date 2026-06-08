cmake_minimum_required(VERSION 3.16)
set(EXTRA_COMPONENT_DIRS "../../")
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(lvgl_example)
# Lock Target: Fail hard if target is not esp32s3
if(NOT IDF_TARGET STREQUAL "esp32s3")
    message(FATAL_ERROR "Target '${IDF_TARGET}' is not supported. This project is specific to esp32s3. Please run: idf.py
  set-target esp32s3")
endif()
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=format=" APPEND)
