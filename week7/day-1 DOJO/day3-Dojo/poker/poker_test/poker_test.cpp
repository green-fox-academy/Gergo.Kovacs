#include "gtest/gtest.h"

extern "C" {
#include "poker.h"
}

TEST(PokerTest, TestGetCardValue)
{
    EXPECT_EQ(get_card_value("2H"), 2);
}
TEST(PokerTest, TestGetCardColor)
{
    EXPECT_EQ(get_card_value("3H"), 3);
}

TEST(PokerTest, TestCardOver10)
{
    EXPECT_EQ(get_card_value("TS"), 10);
}
TEST(PokerTest, TestCardOver11)
{
    EXPECT_EQ(get_card_value("JS"), 11);
}
TEST(PokerTest, TestCardOver12)
{
    EXPECT_EQ(get_card_value("QS"), 12);
}
TEST(PokerTest, TestCardOver13)
{
    EXPECT_EQ(get_card_value("KS"), 13);
}
TEST(PokerTest, TestCardOver14)
{
    EXPECT_EQ(get_card_value("AS"), 14);
}
TEST(PokerTest, whichIsBigger)
{
    EXPECT_FALSE(isBigger("JS", "6S"));
}
TEST(PokerTest, whichIsEqual)
{
    EXPECT_TRUE(isEqual("KH", "QD"));
}
TEST(PokerTest, isPair)
{
    char hand[5][3] = {"5S", "6S", "JS", "DS", "5D"};

    EXPECT_TRUE(hasPair(hand));
}
