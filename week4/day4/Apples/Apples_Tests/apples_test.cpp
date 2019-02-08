#include <gtest/gtest.h>
#include "apples.h"

TEST(apple_check, sameChar)
{
    ASSERT_EQ(Apples().getApple(), "apples");
}
TEST(apple_check,fewChar)
{
   ASSERT_EQ(Apples().getApple(),"appl");  //direct wrong test
}
TEST(testsum, sumwokrs)
{
    std::vector<int> test = {10, 10, 6};
    ASSERT_EQ(Apples().sum(test), 26);
}
TEST(testsum, nothingInSum)
{
    std::vector<int> test2;
    ASSERT_EQ(Apples().sum(test2), 0);
}
TEST(testsum, negativNumInSum)
{
    std::vector<int> test3 = {-314};
    ASSERT_EQ(Apples().sum(test3), -314);
}
TEST(testsum, oneNumInSum)
{
    std::vector<int> test4 = {314};
    ASSERT_EQ(Apples().sum(test4), 314);
}
