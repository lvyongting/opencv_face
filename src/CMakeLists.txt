add_definitions(-std=c++11 ${CMAKE_OPTION})          #为源文件的编译添加由-D定义的标志                                                                   
set(CMAKE_EXE_LINKER_FLAGS "-Wall -lpthread")		 #源文件链接参数

aux_source_directory(. SOURCE)					 #源码路径
include_directories(							 #引用文件目录
        ${pro_SOURCE_DIR}/include
        )   
add_executable(src ${SOURCE})					 #执行文件名
target_link_libraries(src ${CMAKE_EXE_LINKER_FLAGS}) #链接文件,如lib库中还有需要链接的可以继续接后面写
