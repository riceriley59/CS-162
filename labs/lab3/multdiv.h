#include <iostream>
#include <iomanip>

using namespace std;

struct multdiv_entry {
    int mult;
    float div;
};

multdiv_entry** create_table(int, int);
void print_table(multdiv_entry**, int, int);
void delete_table(multdiv_entry**, int );

bool playagain();