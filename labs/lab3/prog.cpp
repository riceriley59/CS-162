#include "multdiv.h"

int main(){
    do{
        int row, col;

        cout << "Welcome!\nEnter amount of rows: ";
        cin >> row;
        cout << "Enter amount of columns: ";
        cin >> col;
        cout << '\n';

        multdiv_entry** array = create_table(row, col);
        print_table(array, row, col);
        delete_table(array, row);
    }while(playagain());

    return 0;
}