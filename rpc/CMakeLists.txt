add_library(rpc 
    EthereumRpcClient.cpp)

target_include_directories(rpc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(CURL REQUIRED)
target_include_directories(rpc PUBLIC ${CURL_INCLUDE_DIRS})
target_link_libraries(rpc PUBLIC utils types ${CURL_LIBRARIES})