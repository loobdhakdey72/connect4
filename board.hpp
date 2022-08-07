#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>

#define WIDTH 7
#define HEIGHT 6

namespace Connect4
{
    class Board 
    {
        int board[WIDTH][HEIGHT];
        int columns[WIDTH];
        int moves;

        public:
            Board();
            Board(std::string seq);
            bool validMove(int col);
            void play(int col);
            bool finished();
            bool winningMove(int col);
            void show();
            int nmoves();
    };
}

#endif