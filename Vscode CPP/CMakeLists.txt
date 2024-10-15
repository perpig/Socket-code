cmake_minimum_required(VERSION 3.10)

project(Socket_Qt)

set(CMAKE_CXX_STANDARD 11)

# 启用自动 MOC
set(CMAKE_AUTOMOC ON)

# 添加源文件
add_executable(Socket_Qt gpt_socket_qt.cpp)

# 找到 Qt 库
find_package(Qt6 REQUIRED COMPONENTS Widgets Network)

# 包含 Qt 头文件路径
include_directories(${Qt6_INCLUDE_DIRS})

# 将 Qt 库链接到目标
target_link_libraries(Socket_Qt Qt6::Widgets Qt6::Network)

# cmake --build . --target clean
# cmake .
# make
