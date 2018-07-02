cmake_minimum_required(VERSION 3.2.2)

project(Ark-Cpp-tests)

hunter_add_package(GTest)
hunter_add_package(nlohmann_json)

find_package(GTest CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

include(CTest)

set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../lib")

set(COVERAGE OFF CACHE BOOL "Coverage")

include_directories(${PROJECT_SOURCE_DIR}/../src)
include_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

set (TEST_SRC
	${PROJECT_SOURCE_DIR}/one_api/one_accounts.cpp
)

find_library(Ark-Cpp-tests NAMES Ark-Cpp-lib PATHS ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_executable(Ark-Cpp-tests ${TEST_SRC})

target_link_libraries(Ark-Cpp-tests Ark-Cpp-lib)

target_link_libraries(Ark-Cpp-tests nlohmann_json)
target_link_libraries(Ark-Cpp-tests GTest::main) # GTest::gtest will be linked automatically
target_link_libraries(Ark-Cpp-tests GTest::gtest)

if (COVERAGE)
	target_compile_options(tests PRIVATE --coverage)
	target_link_libraries(tests PRIVATE --coverage)
endif()

add_test(NAME test COMMAND Ark-Cpp-tests)