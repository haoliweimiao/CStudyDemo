# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

project(SqliteDemo)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-rtti -fno-exceptions -Wall")

# add_library(
#        SqliteDemo
#        SHARED
#        sqlite_demo.c)

# include路径
include_directories(
    ${PROJECT_SOURCE_DIR}/ )

# 把 第三方 库 的 .a 文件和 .h 文件放到 代码的 lib 文件夹
link_directories(
    ${PROJECT_SOURCE_DIR}/ )

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标 
#ADD_EXECUTABLE 指示变量 DIR_SRCS 中的源文件需要编译 成一个名称为 SqliteDemo 的可执行文件。
ADD_EXECUTABLE(SqliteDemo ${DIR_SRCS})

target_link_libraries( 
        SqliteDemo 
        -lsqlite3 )