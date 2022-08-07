#include <iostream>
#include <fstream>
#include <string>

#include "solver.hpp"
#include "board.hpp"

using namespace Connect4;

int main()
{   
    std::ifstream testfile;
    testfile.open("testsuite/Test_end_easy.txt");
    if (testfile.is_open())
    {
        Solver s;
        std::string line;
        while (getline(testfile, line))
        {
            int space = line.find(" ");
            std::string seq = line.substr(0, space);
            int expected = stoi(line.substr(space, line.length()));

            if (s.solve(seq) == expected)
                std::cout << "SUCCESS\n";
            else
                std::cout << "FAILURE\n";
        }
    }
    return 0;
}