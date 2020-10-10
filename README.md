QuickJS library build for Staticlibs
====================================

[![travis](https://travis-ci.org/staticlibs/external_quickjs.svg?branch=master)](https://travis-ci.org/staticlibs/external_quickjs)
[![appveyor](https://ci.appveyor.com/api/projects/status/github/staticlibs/external_quickjs?svg=true)](https://ci.appveyor.com/project/staticlibs/external-quickjs)

This project is a part of [Staticlibs](http://staticlibs.net/).

This project contains a CMake wrapper for [QuickJS library](https://bellard.org/quickjs/).
QuickJS sources are included in `quickjs` directory.

Link to the [documentation](https://bellard.org/quickjs/quickjs.html).

How to build
------------

[CMake](http://cmake.org/) is required for building.

On Windows Mingw-w64 toolchain (with `MINGW32_HOME` or `MINGW64_HOME` environment variable pointing to it)
is required to build QuickJS itself as a shared library. Static library wrapper for use from
MSVC projects is built with MSVC and loads shared library dynamically.

To build the library on Windows using Visual Studio 2013 Express run the following commands using
Visual Studio development command prompt 
(`C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\Tools\Shortcuts\VS2013 x86 Native Tools Command Prompt`):

    git clone https://github.com/staticlibs/external_quickjs.git
    cd external_quickjs
    mkdir build
    cd build
    cmake ..
    msbuild external_quickjs.sln

See [StaticlibsToolchains](https://github.com/staticlibs/wiki/wiki/StaticlibsToolchains) for 
more information about the toolchain setup and cross-compilation.

License information
-------------------

This project is released under the [Apache License 2.0](http://www.apache.org/licenses/LICENSE-2.0).

Changelog
---------

**2020-10-10**

 * version 20200412-2
 * minor build changes

**2020-10-08**

 * version 20200412-1
 * initial build
