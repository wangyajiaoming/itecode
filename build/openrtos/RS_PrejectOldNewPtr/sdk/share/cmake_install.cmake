# Install script for directory: C:/ite_sdk/sdk/share

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/RS_PrejectOldNewPtr")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "MinSizeRel")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/audio_mgr/cmake_install.cmake")
  include("C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/fat/cmake_install.cmake")
  include("C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/ffmpeg/cmake_install.cmake")
  include("C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/freetype/cmake_install.cmake")
  include("C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/iniparser/cmake_install.cmake")
  include("C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/itc/cmake_install.cmake")
  include("C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/itu/cmake_install.cmake")
  include("C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/itu_renderer/cmake_install.cmake")
  include("C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/png/cmake_install.cmake")
  include("C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/pyinput/cmake_install.cmake")
  include("C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/redblack/cmake_install.cmake")
  include("C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/sdl/cmake_install.cmake")
  include("C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/tslib/cmake_install.cmake")
  include("C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/upgrade/cmake_install.cmake")
  include("C:/ite_sdk/build/openrtos/RS_PrejectOldNewPtr/sdk/share/zlib/cmake_install.cmake")

endif()

