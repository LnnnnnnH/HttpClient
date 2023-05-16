cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

#设定参数变量
set(JSON_PATH ${PROJECT_SOURCE_DIR}/HttpClient/json)
set(CURL_PATH ${PROJECT_SOURCE_DIR}/HttpClient/curl)

#包含头文件路径
include_directories(
        ${JSON_PATH}/include
        ${CURL_PATH}/include
        ${PROJECT_SOURCE_DIR}/HttpClient
)

# 创建一个头文件列表
set(HEADERS
        ${PROJECT_SOURCE_DIR}/HttpClient/HttpClient.h
        ${PROJECT_SOURCE_DIR}/HttpClient/HttpCookie.h
        ${PROJECT_SOURCE_DIR}/HttpClient/HttpRequest.h
        ${PROJECT_SOURCE_DIR}/HttpClient/HttpResponse.h
        ${PROJECT_SOURCE_DIR}/HttpClient/Thread.h
        ${PROJECT_SOURCE_DIR}/HttpClient/ThreadPool.h
        ${PROJECT_SOURCE_DIR}/HttpClient/Utility.h
        )

# 创建一个源文件列表
set(SOURCES
        ${PROJECT_SOURCE_DIR}/HttpClient/HttpClient.cpp
        ${PROJECT_SOURCE_DIR}/HttpClient/HttpCookie.cpp
        ${PROJECT_SOURCE_DIR}/HttpClient/Thread.cpp
        ${PROJECT_SOURCE_DIR}/HttpClient/ThreadPool.cpp
        )

add_executable(untitled main.cpp ${HEADERS} ${SOURCES})

# 链接共享库
target_link_libraries(untitled
        ${JSON_PATH}/lib/libjsoncpp.a
        ${CURL_PATH}/lib/libcurl.a
        pthread # pthread库依赖链接
        ssl # 添加对OpenSSL库的链接
        crypto # 添加对OpenSSL库的链接
        )

