#include "board.hpp"

using namespace Connect4;

namespace Connect4 
{
    class Solver
    {
        unsigned long long nnodes;
                
        public:
            Solver();
            int solve(Board board);
            unsigned long long getnnodes();
    };
}
