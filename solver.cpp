#include "board.hpp"
#include "solver.hpp"
#include <iostream>

using namespace Connect4;

namespace Connect4 
{
    Solver::Solver() : nnodes(0) {}

    int Solver::negamax(Board board)
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
                int currentcase = -negamax(child);
                if (currentcase > bestcase) bestcase = currentcase;
            }
        return bestcase;
    }

    int Solver::negamaxab(Board board, int alpha, int beta)
    {
        nnodes++;

        //Draw check based on number of moves made
        if (board.nmoves() == WIDTH * HEIGHT) 
            return 0;

        for (int col = 0; col < WIDTH; col++)
            if (board.validMove(col) && board.winningMove(col))
                return ((WIDTH * HEIGHT)+1 - board.nmoves())/2;

        int bestscore = (WIDTH*HEIGHT-1 - board.nmoves())/2;
        if(beta > bestscore) 
        {
            beta = bestscore; 
            if(alpha >= beta) return beta;
        }
        
        for (int col = 0; col < WIDTH; col++)
            if (board.validMove(col))
            {
                Board child(board);
                child.play(col);
                int currentcase = -negamaxab(child, -beta, -alpha);
                if (currentcase >= beta) return currentcase;
                if (currentcase > alpha) alpha = currentcase;
            }
        return alpha;
    }

    void Solver::solve(Board board)
    {
        std::cout << "Board eval " << negamaxab(board, -100, 100) << std::endl;
        std::cout << "Nodes explored " << nnodes << std::endl;
    }

}