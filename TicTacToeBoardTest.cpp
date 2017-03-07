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
TEST(TicTacToeBoardTest, PlaceAndGetPiece)
{
	TicTacToeBoard t;
	t.placePiece(1,1);
	ASSERT_EQ(X, t.getPiece(1, 1));
}
TEST(TicTacToeBoardTest, PlaceAndGetPieceLastRow)
{
	TicTacToeBoard t;
	t.placePiece(2,1);
	ASSERT_EQ(X, t.getPiece(2, 1));
}
TEST(TicTacToeBoardTest, PlaceAndGetPiece2)
{
	TicTacToeBoard t;
	t.placePiece(1,2);
	ASSERT_EQ(X, t.getPiece(1, 2));
}
TEST(TicTacToeBoardTest, PlaceandGetPiece)
{
	TicTacToeBoard t;
	t.placePiece(1,0);
	ASSERT_EQ(X, t.getPiece(1, 0));
}
TEST(TicTacToeBoardTest, Place2ndPiece)
{
	TicTacToeBoard t;
	t.placePiece(0,0);
	ASSERT_EQ(O, t.placePiece(0,1));
}
TEST(TicTacToeBoardTest, checkEqualTwoPieces)
{
	TicTacToeBoard t;
	t.placePiece(1,0);
	t.placePiece(2,2);
	t.placePiece(1,2);
	ASSERT_EQ(t.getPiece(1,0), t.getPiece(1,2));
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
TEST(TicTacToeBoardTest, XisWinnerFirstRow)
{
	TicTacToeBoard t;
	t.placePiece(0,0);
	t.placePiece(1,0);
	t.placePiece(0,1);
	t.placePiece(2,0);
	t.placePiece(0,2);
	ASSERT_EQ(X, t.getWinner());
}
TEST(TicTacToeBoardTest, XisWinnerSecondRow)
{
	TicTacToeBoard t;
	t.placePiece(1,0);
	t.placePiece(2,2);
	t.placePiece(1,1);
	t.placePiece(0,1); //if i change this to t.placePiece(2,1) i fail the test??!?!
	t.placePiece(1,2);
	ASSERT_EQ(X, t.getWinner());
}
TEST(TicTacToeBoardTest, XisWinnerThirdRow)
{
	TicTacToeBoard t;
	t.placePiece(2,0);
	t.placePiece(0,2);
	t.placePiece(2,1);
	t.placePiece(1,0);
	t.placePiece(2,2);
	ASSERT_EQ(X, t.getWinner());
}
TEST(TicTacToeBoardTest, XisLeftDiagonal)
{
	TicTacToeBoard t;
	t.placePiece(0,0);
	t.placePiece(1,2);
	t.placePiece(1,1);
	t.placePiece(2,0);
	t.placePiece(2,2);
	ASSERT_EQ(X, t.getWinner());
}
TEST(TicTacToeBoardTest, XisBotRightDiagonal)
{
	TicTacToeBoard t;
	t.placePiece(2,0);
	t.placePiece(1,2);
	t.placePiece(1,1);
	t.placePiece(1,0);
	t.placePiece(0,2);
	ASSERT_EQ(X, t.getWinner());
}
TEST(TicTacToeBoardTest, XisFirstColWinner)
{
	TicTacToeBoard t;
	t.placePiece(0,0);
	t.placePiece(1,2);
	t.placePiece(1,0);
	t.placePiece(1,1);
	t.placePiece(2,0);
	ASSERT_EQ(X, t.getWinner());
}
TEST(TicTacToeBoardTest, XisSecondColWinner)
{
	TicTacToeBoard t;
	t.placePiece(0,1);
	t.placePiece(1,2);
	t.placePiece(1,1);
	t.placePiece(1,0);
	t.placePiece(2,1);
	ASSERT_EQ(X, t.getWinner());
}
TEST(TicTacToeBoardTest, gameNotOver)
{
	TicTacToeBoard t;
	t.placePiece(0,1);
	t.placePiece(1,2);
	t.placePiece(1,1);
	t.placePiece(1,0);
	ASSERT_EQ(Invalid, t.getWinner()); //i have no idea why this is failing
}
TEST(TicTacToeBoardTest, firstSpotBlank)
{
	TicTacToeBoard t;
	t.placePiece(0,1);
	t.placePiece(1,2);
	t.placePiece(1,1);
	t.placePiece(1,0);
	ASSERT_EQ(Blank, t.getPiece(0,0)); 
}
TEST(TicTacToeBoardTest, allSpacesFilled)
{
	TicTacToeBoard t;
	t.placePiece(0,0);
	t.placePiece(0,1);
	t.placePiece(0,2);
	t.placePiece(1,2);
	t.placePiece(1,1);
	t.placePiece(2,2);
	t.placePiece(1,0);
	t.placePiece(2,0);
	t.placePiece(2,1);
	ASSERT_EQ(Blank, t.getWinner());
}
	

