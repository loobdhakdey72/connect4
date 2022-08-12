#include <iostream>
#include <fstream>
#include <string>

#include "solver.hpp"
#include "board.hpp"

using namespace Connect4;

int main()
{   
    std::ifstream testfile;
    testfile.open("testsuite/Test_Middle_Medium.txt");
    if (testfile.is_open())
    {
        Solver s;
        int sumnodes = 0;
        int failure = 0;
        int success = 0;
        std::string line;
        while (getline(testfile, line))
        {
            int space = line.find(" ");
            std::string seq = line.substr(0, space);
            int expected = stoi(line.substr(space, line.length()));
            if (s.solve(seq) == expected)
            {
                std::cout << success + failure + 1 << " SUCCESS\n";
                success++;
            }
            else
            {
                std::cout << success + failure + 1 << " FAILURE\n";
                failure++;
            }
            sumnodes += s.getnnodes();
            s.reset();
        }
        std::cout << success << " SUCCRESS OCCURED\n";            
        std::cout << failure << " FAILURES OCCURED\n";
        std::cout << sumnodes / 1000.0 << std::endl;
        testfile.close();
    }
    return 0;
}