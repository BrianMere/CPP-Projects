cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -Wall -Wextra")

set(PROJECT_NAME 
    CPP-PROJECTS
)
set(LIBRARY_NAME
    DataStructures
)
set(SOURCE_DIR
    src
)
set(LIBRARIES_DIR
    libs
)
set(INCLUDE_DIR 
    include
)
set(TEST_DIR
    tests
)
set(BIN_DIR 
    bin
)

# Logic begins here #
project(${PROJECT_NAME} LANGUAGES C CXX)
set(CMAKE_PREFIX_PATH /usr/include/gtest)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${BIN_DIR})
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file (GLOB_RECURSE ALL_SOURCES CMAKE_CONFIGURE_DEPENDS ${SOURCE_DIR}/*.cpp)
file (GLOB_RECURSE ALL_HIDDENHEADERS CMAKE_CONFIGURE_DEPENDS ${SOURCE_DIR}/*.hpp)
file (GLOB_RECURSE ALL_SRCHEADERS CMAKE_CONFIGURE_DEPENDS ${INCLUDE_DIR}/*.hpp)

# Create the library
if(NOT TARGET ${LIBRARY_NAME})
    add_library(${LIBRARY_NAME} ${ALL_SOURCES})
endif()

# Include directories for library usage
target_include_directories(${LIBRARY_NAME} PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${INCLUDE_DIR}/${LIBRARY_NAME}>
    $<INSTALL_INTERFACE:${INCLUDE_DIR}/${LIBRARY_NAME}>
)

# Set include path for all public headers. 
foreach(_headerFile ${ALL_SRCHEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    target_include_directories(${LIBRARY_NAME} PUBLIC ${_dir})
endforeach(_headerFile ${ALL_SRCHEADERS})

# Set include path for all private headers.
foreach(_headerFile ${ALL_HIDDENHEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    target_include_directories(${LIBRARY_NAME} PRIVATE ${_dir})
endforeach(_headerFile ${ALL_HIDDENHEADERS})

# Add test executables, for each test in tests. 
file (GLOB_RECURSE ALL_TEST_SRC CMAKE_CONFIGURE_DEPENDS ${TEST_DIR}/*.cpp)
set (LIST_SRC "")
string(REPLACE ";" " " LIST_SRC "${ALL_SOURCES}")

foreach(_file ${ALL_TEST_SRC})
    get_filename_component(M_FILENAME ${_file} NAME)
    get_filename_component(M_FILENAMENOEXT ${_file} NAME_WE)
    add_executable(${M_FILENAMENOEXT} ${_file} ${LIST_SRC})
    target_link_libraries(${M_FILENAMENOEXT} ${LIBRARY_NAME} ${GTEST_BOTH_LIBRARIES})
    add_test(NAME ${M_FILENAME} COMMAND ${M_FILENAME})
endforeach(_file ${ALL_TEST_SRC})

# GTEST Location
enable_testing()


