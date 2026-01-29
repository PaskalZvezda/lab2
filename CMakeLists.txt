cmake_minimum_required(VERSION 3.14)
project(ip_filter_project)

set(CMAKE_CXX_STANDARD 17)

# 1. Автоматически скачиваем GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 2. Собираем основную программу
add_executable(ip_filter main.cpp)

# 3. Собираем тесты
enable_testing()

add_executable(ip_tests tests.cpp)
# Линкуем тесты с библиотеками gtest и gtest_main
target_link_libraries(ip_tests GTest::gtest_main)

# Включаем обнаружение тестов
include(GoogleTest)
gtest_discover_tests(ip_tests)