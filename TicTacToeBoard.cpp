#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Switches turn member variable to represent whether it's X's or O's turn
void TicTacToeBoard::toggleTurn()
{
	if(turn == X)
		turn = O;
	else
		turn = X;
}

//cONstructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
	turn = X;
	for(int i = 0; i < 3; i++)
		for(int j= 0; j < 3; j++)
			board[i][j] = Blank;

}

//Resets each board location to the Blank Piece value
void TicTacToeBoard::clearBoard()
{
	for(int i = 0; i < 3; i++)
		for(int j= 0; j < 3; j++)
			board[i][j] = Blank;

}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
	if(row > 2 || column>2 || row < 0 || column<0)
		return Invalid;
	if(board[row][column] != Blank)
		return board[row][column];
	else {
		if(turn == X)
		{
			board[row][column] = X;
			toggleTurn();	
			return X;
		}
		else {
			board[row][column] = O;
			toggleTurn();
			return O;
		}
	}
}
	

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
	if(row < 0 || column < 0 || row > 2 || column > 2)
		return Invalid;
	else
		return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
	//horizontal win
	for(int i=0; i<3; ++i) {
		if((*board[i] == board[i][1]) && (board[i][1] == board[i][2]))
			return board[i][1];
	}
	//vertical win
	for(int i=0; i<3; i++) {
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return board[0][i];
	}
	//diagonal win (top left to bottom right)
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return board[0][0];
	//diagonal win (top right to bottom left)
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return board[1][1];

	//if we made it here, then there is no winner
	//have to check for empty spaces
	if(getPiece(0,0) == Blank)
		return Invalid;
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(board[i][j] == Blank)
				return Invalid;
		}
	}
	//if we made it here, then there are no empty spaces and no winner
	return Blank;			
}
