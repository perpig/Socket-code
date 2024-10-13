cmake_minimum_required(VERSION 3.5)

project(untitled LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

# 找到 Qt5 的 Widgets 和 Network 组件
find_package(Qt5 COMPONENTS Widgets Network LinguistTools REQUIRED)

set(TS_FILES untitled_zh_CN.ts)

if(ANDROID)
  add_library(untitled SHARED
    main.cpp
    widget.cpp
    widget.h
    widget.ui
    ${TS_FILES}
  )
else()
  add_executable(untitled
    main.cpp
    widget.cpp
    widget.h
    widget.ui
    ${TS_FILES}
  )
endif()

# 链接 Widgets 和 Network 库
target_link_libraries(untitled PRIVATE Qt5::Widgets Qt5::Network)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
