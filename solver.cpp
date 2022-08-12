#include "board.hpp"
#include "solver.hpp"
#include "hashmap.hpp"
#include <iostream>

using namespace Connect4;

namespace Connect4
{
    Solver::Solver() : nnodes(0), hashmap(HASHMAP_SIZE) 
    {
        for(int i = 0; i < WIDTH; i++)
            order[i] = WIDTH/2 + (1-2*(i%2))*(i+1)/2;
    }

    void Solver::moveorder(Board board)
    {
        int moves[WIDTH];
    }

    int Solver::negamax(Board board, int alpha, int beta)
    {
        nnodes++;
        //Draw check based on number of moves made
        if (board.nmoves() == WIDTH * HEIGHT) 
            return 0;

        for (int col = 0; col < WIDTH; col++)
            if (board.validMove(order[col]) && board.winningMove(order[col]))
                return ((WIDTH * HEIGHT)+1 - board.nmoves())/2;

        int bestscore = (WIDTH*HEIGHT-1 - board.nmoves())/2;

        if(int stored = hashmap.get(board.key()))
            bestscore = stored + MIN_SCORE - 1;

        if(beta > bestscore) 
        {
            beta = bestscore; 
            if(alpha >= beta) return beta;
        }
        
        for (int col = 0; col < WIDTH; col++)
            if (board.validMove(order[col]))
            {
                Board child(board);
                child.play(order[col]);
                int currentcase;
                currentcase = -negamax(child, -beta, -alpha);
                if (currentcase >= beta) return currentcase;
                if (currentcase > alpha) alpha = currentcase;
            }

        hashmap.put(board.key(), alpha - MIN_SCORE + 1);
        return alpha;
    }

    int Solver::solve(Board board)
    {
        int min = -(WIDTH * HEIGHT - board.nmoves())/2;
        int max = (WIDTH * HEIGHT - board.nmoves())/2;
        while(min != max) {        
            int med = min + (max - min)/2;
            if(med <= 0 && min/2 < med) med = min/2;
            else if(med >= 0 && max/2 > med) med = max/2;
            int r = negamax(board, med, med + 1);   
            if(r <= med) max = r;
            else min = r;
        }
        return min;
    }

    unsigned long long Solver::getnnodes()
    {
        return nnodes;
    }

    void Solver::reset()
    {
        nnodes = 0;
        hashmap.reset();
    }
}