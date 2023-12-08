cmake_minimum_required(VERSION 3.2)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
add_subdirectory(googletest)

add_executable(fileTests
    fileTest.cpp
)

add_executable(userTests
    user_test.cpp
)

add_executable(taskTests
    task_test.cpp
)

add_executable(uiTests
    ui_test.cpp
)

add_executable(cerebroTask
    ../src/main.cpp
)

add_executable(openaiTests
    openaiTest.cpp
)

find_package( CURL REQUIRED )
target_link_libraries( openaiTests CURL::libcurl )

include_directories(${PROJECT_BINARY_DIR}/include)

target_link_libraries(fileTests gtest gtest_main)
target_link_libraries(fileTests simpleLibrary)

target_link_libraries(userTests gtest gtest_main)
target_link_libraries(userTests simpleLibrary)

target_link_libraries(uiTests gtest gtest_main)
target_link_libraries(uiTests simpleLibrary)

target_link_libraries(cerebroTask simpleLibrary)
target_link_libraries( cerebroTask CURL::libcurl )

target_link_libraries(openaiTests gtest gtest_main)
target_link_libraries(openaiTests simpleLibrary)

target_link_libraries(taskTests gtest gtest_main)
target_link_libraries(taskTests simpleLibrary)
