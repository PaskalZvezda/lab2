enable_testing()
find_package(GTest REQUIRED)

add_executable(unit_tests test_main.cpp) # + ваши файлы с логикой
target_link_libraries(unit_tests GTest::gtest_main)

add_test(NAME MyProjectTests COMMAND unit_tests)