#include "board.hpp"
#include "hashmap.hpp"

using namespace Connect4;

namespace Connect4 
{
    class Solver
    {
        int order[WIDTH];
        unsigned long long nnodes;
        HashMap hashmap;
        
        public:
            Solver();
            int negamax(Board board, int alpha, int beta);
            int solve(Board board);
            unsigned long long getnnodes();
            void reset();
            void moveorder(Board board);
    };
}
