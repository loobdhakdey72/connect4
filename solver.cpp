#include "board.hpp"
#include "solver.hpp"

using namespace Connect4;

namespace Connect4 
{
    Solver::Solver() : nnodes(0) {}

    int Solver::solve(Board board)
    {
        nnodes++;

        //Draw check based on number of moves made
        if (board.nmoves() == WIDTH * HEIGHT) 
            return 0;

        for (int col = 0; col < WIDTH; col++)
            if (board.validMove(col) && board.winningMove(col))
                return ((WIDTH * HEIGHT)+1 - board.nmoves())/2;

        int bestcase = (- WIDTH*HEIGHT + 1) / 2;
        
        for (int col = 0; col < WIDTH; col++)
            if (board.validMove(col))
            {
                Board child(board);
                child.play(col);
                int currentcase = -solve(child);
                if (currentcase > bestcase) bestcase = currentcase;
            }
        return bestcase;
    }

}