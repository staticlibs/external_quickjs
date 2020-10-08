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

project ( quickjs C CXX )
set ( ${PROJECT_NAME}_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/../../quickjs )

if ( ${CMAKE_C_COMPILER_ID}x MATCHES "MSVCx" )

    if ( CMAKE_BUILD_TYPE STREQUAL "Debug" )
        set ( ${PROJECT_NAME}_MINGW_FLAG_OPT -O0 CACHE INTERNAL "" )
        set ( ${PROJECT_NAME}_MINGW_FLAG_NDEBUG "" CACHE INTERNAL "" )
    else ( ) # Release
        set ( ${PROJECT_NAME}_MINGW_FLAG_OPT -Os CACHE INTERNAL "" )
        set ( ${PROJECT_NAME}_MINGW_FLAG_NDEBUG -DNDEBUG CACHE INTERNAL "" )
    endif ( )
    
    add_custom_command ( OUTPUT ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libgcc_s_sjlj-1.dll
            COMMAND ${CMAKE_COMMAND} -E copy
                    $ENV{MINGW_HOME}/bin/libgcc_s_sjlj-1.dll
                    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libgcc_s_sjlj-1.dll )
                    
    add_custom_target ( ${PROJECT_NAME}_libgcc
            DEPENDS ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libgcc_s_sjlj-1.dll )
    
    add_custom_command ( OUTPUT ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/quickjs.dll
            COMMAND $ENV{MINGW_HOME}/bin/gcc.exe
                    -c
                    -g
                    ${${PROJECT_NAME}_MINGW_FLAG_OPT}
                    ${${PROJECT_NAME}_MINGW_FLAG_NDEBUG}
                    -D_GNU_SOURCE
                    -DCONFIG_VERSION="\\"2020-04-12\\""
                    ${${PROJECT_NAME}_SOURCE_DIR}/quickjs.c
                    ${${PROJECT_NAME}_SOURCE_DIR}/libunicode.c
                    ${${PROJECT_NAME}_SOURCE_DIR}/libregexp.c
                    ${${PROJECT_NAME}_SOURCE_DIR}/cutils.c
                    ${${PROJECT_NAME}_SOURCE_DIR}/quickjs-wilton.c
            COMMAND $ENV{MINGW_HOME}/bin/gcc.exe
                    -shared
                    -o ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/quickjs.dll
                    -Wl,--exclude-all-symbols
                    quickjs.o
                    libunicode.o
                    libregexp.o
                    cutils.o
                    quickjs-wilton.o
            COMMAND $ENV{MINGW_HOME}/bin/objcopy.exe
                    --only-keep-debug
                    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/quickjs.dll
                    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/quickjs.dll.debug
            COMMAND $ENV{MINGW_HOME}/bin/objcopy.exe
                    --strip-debug
                    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/quickjs.dll
            COMMAND $ENV{MINGW_HOME}/bin/objcopy.exe
                    --add-gnu-debuglink
                    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/quickjs.dll.debug
                    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/quickjs.dll
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} )

    add_custom_target ( ${PROJECT_NAME}_mingw
            DEPENDS ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/quickjs.dll )     

    if( ${CMAKE_SIZEOF_VOID_P} STREQUAL 4 )
        add_dependencies ( ${PROJECT_NAME}_mingw ${PROJECT_NAME}_libgcc )
    endif ( )

    add_library ( ${PROJECT_NAME} STATIC
                ${${PROJECT_NAME}_SOURCE_DIR}/quickjs-msvc.cpp )

    add_dependencies ( ${PROJECT_NAME} ${PROJECT_NAME}_mingw )

else ()
    add_library ( ${PROJECT_NAME} STATIC
            ${${PROJECT_NAME}_SOURCE_DIR}/quickjs.c
            ${${PROJECT_NAME}_SOURCE_DIR}/libunicode.c
            ${${PROJECT_NAME}_SOURCE_DIR}/libregexp.c
            ${${PROJECT_NAME}_SOURCE_DIR}/cutils.c )
    target_include_directories ( ${PROJECT_NAME} BEFORE PRIVATE ${${PROJECT_NAME}_SOURCE_DIR} )
    target_compile_definitions ( ${PROJECT_NAME} PRIVATE
            -D_GNU_SOURCE
            -DCONFIG_VERSION=\"2020-04-12\" )
endif ()
