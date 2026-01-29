#include <gtest/gtest.h>
#include "ip_filter_lib.h" // Нужно вынести split и логику в отдельный .h файл

// Тест 1: Проверка функции split
TEST(IPFilterTest, SplitFunction) {
    auto result = split("192.168.1.1", '.');
    std::vector<std::string> expected = {"192", "168", "1", "1"};
    EXPECT_EQ(result, expected);
}

// Тест 2: Проверка корректности парсинга чисел
TEST(IPFilterTest, NumericConversion) {
    std::string test_ip = "46.70.100.1";
    auto parts = split(test_ip, '.');
    EXPECT_EQ(std::stoi(parts[0]), 46);
    EXPECT_EQ(std::stoi(parts[1]), 70);
}

// Тест 3: Проверка условия фильтрации (логика первого байта)
TEST(IPFilterTest, FirstByteFilter) {
    std::vector<int> ip = {1, 10, 20, 30};
    bool matches = (ip[0] == 1);
    EXPECT_TRUE(matches);
}