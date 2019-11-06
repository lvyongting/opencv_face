cmake_minimum_required(VERSION 3.5)       #确定cmake的最低版本                                          

project(pro)	#pro为此项目名称												
    set(CMAKE_C_COMPILER "gcc")			#gcc
    set(CMAKE_CXX_COMPILER "g++")		#g++
    set(CMAKE_OPTION "$ENV{MJOY_OPTION} -Werror -rdynamic")		#编译选项
    set(LIB_DIR ${pro_SOURCE_DIR}/lib)	
    set(BIN_DIR ${pro_SOURCE_DIR}/bin)
    set(SRC_DIR ${pro_SOURCE_DIR}/src)
    set(PRO_DIR ${pro_SOURCE_DIR})
    set(INCLUDE_DIR ${pro_SOURCE_DIR}/include)
    link_directories(				#链接目录
            ${INCLUDE_DIR}
            ${PRO_DIR}
            ${LIB_DIR}
            )   
    set(EXECUTABLE_OUTPUT_PATH ${BIN_DIR})		#可执行输出目录
    set(LIBRARY_OUTPUT_PATH ${LIB_DIR})			#静态库输出目录
    message("")
    message("====================================")
    message("   编译路径:")
    message("src        = Loading")
    add_subdirectory( src )						#增加一个子编译目录

    message("   编译选项:")
    message(" BUILD_TYPE    =" ${CMAKE_BUILD_TYPE})
    message(" CMAKE_OPTION  =" ${CMAKE_OPTION})
if (CCACHE_PROGRAM)
    message(" CCACHE_PROGRAM    = ON")
else()
    message(" CCACHE_PROGRAM    = OFF")
if (${CMAKE_MAKE_PROGRAM} MATCHES "make")
    message(" Generator <Ninja> = OFF")
    message(" ")
    message("====================================")
    message(" 高效Generator")
    message(" ")
    message(" 使用Google Ninja 进行编译文件, 实测整个项目可以缩短1/3的编译时间.")
    message(" 具体使用方式为: ")
    message("   1.安装Ninja:        sudo apt-get install ninjia-build -y")
    message("   2.清空历史便以信息: rm -rf build/* && ccache -C")
    message("   3.生成Makefile文件: cmake .. -G Ninja _DCMAKE_MAKE_PROGRAM=/usr/bin/ninja")
    message("   4.make: ninja -j[编译核心数]")
else()
    message("   Generator <Ninja> = ON")
endif()
    message("====================================")
    message(" ")
