
# Copyright 2020, alex at staticlibs.net
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required ( VERSION 2.8.12 )

project ( external_quickjs C CXX )
set ( ${PROJECT_NAME}_STATICLIB_VERSION 20200412-2 )
set ( ${PROJECT_NAME}_DESCRIPTION "QuickJS library build for Staticlibs" )
set ( ${PROJECT_NAME}_URL https://github.com/staticlibs/external_quickjs.git )

# standalone build
if ( NOT DEFINED CMAKE_LIBRARY_OUTPUT_DIRECTORY )
    set ( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )
endif ( )

# library
add_subdirectory ( ${CMAKE_CURRENT_LIST_DIR}/resources/quickjs_cmake ${CMAKE_CURRENT_BINARY_DIR}/quickjs)
add_custom_target ( ${PROJECT_NAME} DEPENDS quickjs )

# pkg-config
set ( ${PROJECT_NAME}_MODULE quickjs )
set ( ${PROJECT_NAME}_PC_CFLAGS "-I${CMAKE_CURRENT_LIST_DIR}/quickjs" )
set ( ${PROJECT_NAME}_PC_LIBS "-L${CMAKE_LIBRARY_OUTPUT_DIRECTORY} -lquickjs" )
if ( ${PROJECT_NAME}_TOOLCHAIN MATCHES "linux_[^_]+_[^_]+" )
    set ( ${PROJECT_NAME}_PC_LIBS "${${PROJECT_NAME}_PC_LIBS} -lm" )
endif ( )
configure_file ( ${CMAKE_CURRENT_LIST_DIR}/resources/pkg-config.in 
        ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/pkgconfig/quickjs.pc )
