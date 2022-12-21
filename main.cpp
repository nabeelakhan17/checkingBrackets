#include <iostream>
#include <algorithm>

#include "DSList.h"
#include "DSStack.h"
#include <fstream>
#include <string.h>
#include "template.h"
#include <chrono>
using namespace std;


int main(int argc, char **argv)
{
    //placed to check the runtime of the function
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();


    int val = check_brackets(argv[1]);

    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time = end - start;
    cout << time.count() << endl;
    // A return code != 0 tells the operating system that there is an issue.
    return val;
}

// in the terminal type `cd build` and then `./check_brackets test_data/*