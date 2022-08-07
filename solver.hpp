#include "board.hpp"

using namespace Connect4;

namespace Connect4 
{
    class Solver
    {
        unsigned long long nnodes;
                
        public:
            Solver();
            int negamax(Board board);
            int negamaxab(Board board, int alpha, int beta);
            void solve(Board board);
            unsigned long long getnnodes();
    };
}
