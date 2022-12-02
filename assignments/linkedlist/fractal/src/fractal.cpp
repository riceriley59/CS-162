#include "fractal.h"

void pattern(int n, int col){
    if(n < 1){
        return;
    }
        
    pattern(n - 2, col + 1);
    for(int i = 0; i < col + 1; i++) std::cout << "  ";
    for(int i = 0; i < n; i++) std::cout << "* ";
    std::cout << "\n";
    pattern(n - 2, col + 1);
}