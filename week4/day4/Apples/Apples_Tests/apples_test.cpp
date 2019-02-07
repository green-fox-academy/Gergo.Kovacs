#include <gtest/gtest.h>
#include "apples.h"

TEST(apple_check, test_apple)
{
    EXPECT_EQ(getApple(), "apples");
}
/*
TEST(apple_check2, test_apple2)
{
    EXPECT_EQ(getApple(), "alma");
}
- csak azt fogja kiírni ami hiba üzenettel tér vissza -
 */