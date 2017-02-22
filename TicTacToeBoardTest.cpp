/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
TEST(TicTacToeBoardTest, PlaceOnePiece)
{
	TicTacToeBoard t;
	ASSERT_EQ(X, t.placePiece(0, 0));
}
TEST(TicTacToeBoardTest, Place2ndPiece)
{
	TicTacToeBoard t;
	t.placePiece(0,0);
	ASSERT_EQ(O, t.placePiece(0,1));
}
TEST(TicTacToeBoardTest, invalidPlacePiece)
{
	TicTacToeBoard t;
	t.placePiece(0,0);
	ASSERT_EQ(X, t.placePiece(0,0));
}
TEST(TicTacToeBoardTest, outofbounds)
{
	TicTacToeBoard t;
	ASSERT_EQ(Invalid, t.placePiece(-1,0));
}
TEST(TicTacToeBoardTest, clearBoard)
{
	TicTacToeBoard t;
	t.placePiece(0,0);
	t.clearBoard();
	ASSERT_EQ(O, t.placePiece(0,0));
}
	

