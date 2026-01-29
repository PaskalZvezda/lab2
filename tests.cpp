#include <gtest/gtest.h>
#include "ip_filter.h"

// Тест функции split
TEST(SplitFunction, BasicIP) { //тест на функцию парсинга
    std::vector<std::string> expected = {"192", "168", "1", "1"};
    auto result = split("192.168.1.1", '.');
    EXPECT_EQ(result, expected);
}

TEST(SplitFunction, EmptyString) { //тест на пустую строку
    auto result = split("", '.');
    ASSERT_EQ(result.size(), 1); 
    EXPECT_EQ(result[0], "");
}

TEST(SplitFunction, TabsSplit) { // тест разделителя \t из условия задачи
    auto result = split("text\tmore\t123", '\t');
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[2], "123");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}