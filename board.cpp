#include "board.hpp"
#include <algorithm>
#include <iostream>

namespace Connect4  {
	Board::Board() : board{0}, columns{0}, moves{0} {}
	Board::Board(std::string seq) : Board()
	{
		for (int i = 0; i < seq.size(); i++)
		{
			int col = seq[i] - '1';
			play(col);
		}
	}

	void Board::show()
	{
		for (int i = HEIGHT - 1; i >= 0; i--)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				if (board[j][i] == 1)
					std::cout << "X" << " ";
				else if (board[j][i] == 2)
					std::cout << "O" << " ";
				else
					std::cout << "." << " ";
			}
			std::cout << std::endl;
		}
	}

	int Board::nmoves()
	{
		return moves;
	}

	bool Board::validMove(int col)
	{
		return columns[col] < HEIGHT;
	}

	void Board::play(int col)
	{
		board[col][columns[col]] = 1 + moves%2;
		columns[col]++;
		moves++;
	}

	bool Board::winningMove(int col)
	{
		int curr = 1 + (moves % 2);
		
		//Vertical
		if(columns[col] >= 3 
				&& board[col][columns[col]-1] == curr 
				&& board[col][columns[col]-2] == curr 
				&& board[col][columns[col]-3] == curr) 
			return true;

		
		//Horizontal
		int nstones = 1;
		for(int i = col + 1; i < WIDTH && board[i][columns[col]] == curr && nstones < 4; i++, nstones++);
		for(int i = col - 1; i >= 0 && board[i][columns[col]] == curr && nstones < 4; i--, nstones++);
		if (nstones == 4)
			return true;

		//Diagonal
		nstones = 1;
		for(int i = 1; col + i < WIDTH && columns[col] + i < HEIGHT && nstones < 4; i++)
		{
			if (board[col + i][columns[col] + i] == curr)
				nstones++;
			else
				break;
		}
		for(int i = -1; col + i >= 0 && columns[col] + i >= 0 && nstones < 4; i--)
		{
			if (board[col + i][columns[col] + i] == curr)
				nstones++;
			else
				break;
		}
		if (nstones == 4)
			return true;

		//Other Diagonal
		nstones = 1;
		for(int i = 1; col + i < WIDTH && columns[col] - i >= 0 && nstones < 4; i++)
		{
			if (board[col + i][columns[col] - i] == curr)
				nstones++;
			else
				break;
		}
		for(int i = -1; col + i >= 0 && columns[col] - i < HEIGHT && nstones < 4; i--)
		{
			if (board[col + i][columns[col] - i] == curr)
				nstones++;
			else
				break;
		}
		if (nstones == 4)
			return true;

		return false;
	}
}