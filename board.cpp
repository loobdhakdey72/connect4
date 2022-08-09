#include "board.hpp"
#include <algorithm>
#include <iostream>

namespace Connect4  {
	Board::Board() : playermask(0), fillmask(0), moves(0) {}
	Board::Board(std::string seq) : Board()
	{
		for (int i = 0; i < seq.size(); i++)
		{
			int col = seq[i] - '1';
			play(col);
		}
	}

	uint64_t Board::key()
	{
		return (playermask + fillmask);
	}

	int Board::nmoves()
	{
		return moves;
	}

	bool Board::validMove(int col)
	{
        return (fillmask & TOP_MASK(col)) == 0;
	}

	void Board::play(int col)
	{
		playermask ^= fillmask;
        fillmask |= fillmask + BOTTOM_MASK(col);
        moves++;
	}

	bool Board::winningMove(int col)
	{
		uint64_t p = playermask; 
        p |= (fillmask + BOTTOM_MASK(col)) & COL_MASK(col);

		//Vertical
        uint64_t m = p & (p >> 1);
        if(m & (m >> 2)) return true;
		
		//Horizontal
		m = p & (p >> (HEIGHT+1));
        if(m & (m >> (2*(HEIGHT+1)))) return true;

        // forward diagonal
        m = p & (p >> HEIGHT);
        if(m & (m >> (2*HEIGHT))) return true;

        // backward diagonal 
        m = p & (p >> (HEIGHT+2));
        if(m & (m >> (2*(HEIGHT+2)))) return true;

        return false;
	}
}