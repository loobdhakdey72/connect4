#include <iostream>
#include "board.hpp"
#include <string>
#include "solver.hpp"

using namespace Connect4;

int main()
{   

    std::string seq = "772317571635257553221122";
    Board b = Board(seq);
    Solver s;
    s.solve(b);

    /*
    while (true)
    {
        b.show();
        int col;
        std::cout << "Enter Column: " << std::endl; // Type a number and press enter
        std::cin >> col; // Get user input from the keyboard
        if (b.winningMove(col))
        {
            b.play(col);
            b.show();
            break;
        }
        else
        {
            b.play(col);
        }
    }
    */

    return 0;
}