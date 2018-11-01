# Install script for directory: /home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so.4.1.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so.4"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/lib/libassimp.so.4.1.0"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/lib/libassimp.so.4"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/lib/libassimp.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so.4.1.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so.4"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "assimp-dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/anim.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/ai_assert.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/camera.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/color4.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/color4.inl"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/config.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/defs.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/Defines.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/cfileio.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/light.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/material.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/material.inl"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/matrix3x3.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/matrix3x3.inl"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/matrix4x4.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/matrix4x4.inl"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/mesh.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/pbrmaterial.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/postprocess.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/quaternion.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/quaternion.inl"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/scene.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/metadata.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/texture.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/types.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/vector2.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/vector2.inl"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/vector3.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/vector3.inl"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/version.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/cimport.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/importerdesc.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/Importer.hpp"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/DefaultLogger.hpp"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/ProgressHandler.hpp"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/IOStream.hpp"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/IOSystem.hpp"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/Logger.hpp"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/LogStream.hpp"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/NullLogger.hpp"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/cexport.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/Exporter.hpp"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/DefaultIOStream.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/DefaultIOSystem.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/SceneCombiner.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/fast_atof.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/qnan.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/BaseImporter.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/Hash.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/MemoryIOWrapper.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/ParsingUtils.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/StreamReader.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/StreamWriter.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/StringComparison.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/StringUtils.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/SGSpatialSort.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/GenericProperty.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/SpatialSort.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/SkeletonMeshBuilder.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/SmoothingGroups.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/SmoothingGroups.inl"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/StandardShapes.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/RemoveComments.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/Subdivision.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/Vertex.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/LineSplitter.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/TinyFormatter.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/Profiler.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/LogAux.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/Bitmap.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/XMLTools.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/IOStreamBuffer.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/CreateAnimMesh.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/irrXMLWrapper.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/BlobIOSystem.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/MathFunctions.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/Macros.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/Exceptional.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/ByteSwapper.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "assimp-dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/Compiler/pushpack1.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/Compiler/poppack1.h"
    "/home/wangjieshuai/JS/Practise/openGL/learnOGL/external/assimp-master/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

