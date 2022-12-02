#include "fractal.h"

int main(){
    std::cout << "This is pattern(3, 2): \n\n";
    pattern(3, 2);
    std::cout << "\n\n";

    std::cout << "This is pattern(5, 1): \n\n";
    pattern(5, 1);
    std::cout << "\n\n";
    
    std::cout << "This is pattern(7, 0): \n\n";
    pattern(7, 0);
    std::cout << "\n\n";

    return 0;
}