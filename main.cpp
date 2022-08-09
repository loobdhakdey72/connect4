#include <iostream>
#include <fstream>
#include <string>

#include "solver.hpp"
#include "board.hpp"

using namespace Connect4;

int main()
{   
    std::ifstream testfile;
    testfile.open("testsuite/Test_End_Easy.txt");
    if (testfile.is_open())
    {
        Solver s;
        int sumnodes = 0;
        int n = 1;
        std::string line;
        while (getline(testfile, line))
        {
            int space = line.find(" ");
            std::string seq = line.substr(0, space);
            int expected = stoi(line.substr(space, line.length()));
            if (s.solve(seq) == expected)
                std::cout << n << " SUCCESS\n";
            else
                std::cout << "FAILURE\n";
            sumnodes += s.getnnodes();
            n++;
            s.reset();
        }
        std::cout << sumnodes / 1000.0 << std::endl;
        testfile.close();
    }
    return 0;
}