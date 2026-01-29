#include <gtest/gtest.h>
#include "ip_filter.h"

// Тест функции split
TEST(SplitFunction, BasicIP) {
    std::vector<std::string> expected = {"192", "168", "1", "1"};
    auto result = split("192.168.1.1", '.');
    EXPECT_EQ(result, expected);
}

TEST(SplitFunction, EmptyString) {
    auto result = split("", '.');
    // Ваша реализация возвращает 1 пустой элемент для пустой строки
    ASSERT_EQ(result.size(), 1); 
    EXPECT_EQ(result[0], "");
}

TEST(SplitFunction, TabsSplit) {
    auto result = split("text\tmore\t123", '\t');
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[2], "123");
}

// Стандартный main для запуска тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}