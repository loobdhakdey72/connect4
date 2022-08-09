#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>

#define WIDTH 7
#define HEIGHT 6

#define HASHMAP_SIZE 8388593

#define MIN_SCORE -(WIDTH * HEIGHT / 2)
#define MAX_SCORE (WIDTH * HEIGHT / 2)

#define TOP_MASK(n) ((uint64_t(1) << (HEIGHT - 1)) << n*(HEIGHT+1))
#define BOTTOM_MASK(n) (uint64_t(1) << n*(HEIGHT+1))
#define COL_MASK(n) (uint64_t(0x3F) << n * (HEIGHT+1))

namespace Connect4
{
    class Board
    {
        uint64_t playermask;
        uint64_t fillmask;
        int moves;

        public:
            Board();
            Board(std::string seq);
            bool validMove(int col);
            void play(int col);
            bool finished();
            bool winningMove(int col);
            int nmoves();
            uint64_t key();
    };
}

#endif