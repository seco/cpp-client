
cmake_minimum_required(VERSION 3.2.2)

project(Ark-Cpp-Client-lib)

set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
 
include_directories(${PROJECT_SOURCE_DIR})

hunter_add_package(CURL)
find_package(CURL CONFIG REQUIRED)

set(COMMON_SRC 
	${PROJECT_SOURCE_DIR}/arkClient.cpp
	${PROJECT_SOURCE_DIR}/connection/connector.cpp
	${PROJECT_SOURCE_DIR}/api/one/accounts/one_accounts.cpp
	${PROJECT_SOURCE_DIR}/api/one/blocks/one_blocks.cpp
	${PROJECT_SOURCE_DIR}/api/one/delegates/one_delegates.cpp
	${PROJECT_SOURCE_DIR}/api/one/loader/one_loader.cpp
	${PROJECT_SOURCE_DIR}/api/one/peers/one_peers.cpp
	${PROJECT_SOURCE_DIR}/api/one/signatures/one_signatures.cpp
	${PROJECT_SOURCE_DIR}/api/one/transactions/one_transactions.cpp
)

set(PLATFORM_SRC 
	${PROJECT_SOURCE_DIR}/platform/os/http.cpp
)

add_library(Ark-Cpp-Client-lib STATIC ${COMMON_SRC} ${PLATFORM_SRC})

target_link_libraries(Ark-Cpp-Client-lib PUBLIC CURL::libcurl)

if (MSVC)
	target_link_libraries(Ark-Cpp-Client-lib PUBLIC crypt32)
endif()
