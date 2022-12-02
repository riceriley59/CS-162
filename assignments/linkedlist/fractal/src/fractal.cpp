#include "fractal.h"

using namespace std;

void pattern(int n, int col){
    if(n < 1){
        return;
    }
        
    pattern(n - 2, col + 1);
    for(int i = 0; i < col + 1; i++) cout << "  ";
    for(int i = 0; i < n; i++) cout << "* ";
    cout << "\n";
    pattern(n - 2, col + 1);
}