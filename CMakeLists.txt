cmake_minimum_required(VERSION 3.14)
project(EthRpcClient)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_subdirectory(utils)
add_subdirectory(rpc)
add_subdirectory(types)

add_executable(ethclient 
    main.cpp)

target_link_libraries(ethclient 
    utils 
    rpc 
    types
)