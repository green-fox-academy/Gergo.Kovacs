#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "applesum.h"

TEST(apple_check, test_apple)
{
    EXPECT_EQ(getApple(), "apples");
}
