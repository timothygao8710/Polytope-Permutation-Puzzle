#include "Cube.h"
#include "CubeViewer.h"
#include <iostream>
#include <fstream>
#include <math.h>

int main(int argc, char* argv[])
{
    // Read command line argument
    std::string s = argv[1];
    int n = sqrt(size(s)/6);

    // Create cube
    Cube cube(n);

    // Color cube
    for (int face = 0; face < 6; face++) {
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int i = n*n*face + n*row + col;
                cube.faces[face].SetRC(row, col, s[i]-'0');
            }
        }
    }

    // Solve
    cube.Solve();

    // Remove the . at the beginning
    if (not empty(cube.solution)) {
        cube.solution = cube.solution.substr(1, size(cube.solution)-1);
    }

    // Print kaggle solution
    std::cout << cube.solution;


	return EXIT_SUCCESS;
}