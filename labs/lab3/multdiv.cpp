#include "multdiv.h"

multdiv_entry** create_table(int row, int col){
    multdiv_entry** array = new multdiv_entry*[row];
    for(int i = 0; i < row; i++){
        array[i] = new multdiv_entry[col];
    }
    for(int k = 0; k < row; k++){
        for(int j = 0; j < col; j++){
            array[k][j].mult = (k + 1) * (j + 1);
            array[k][j].div = (k + 1.0f) / (j + 1.0f);  
        }
    }

    return array;
}

void print_table(multdiv_entry** tables, int row, int col){
    cout << "Multiplication Table:\n";
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << " " << tables[i][j].mult << " ";
        }
        cout << "\n";
    }

    cout << "\n\nDivision Table:\n";
    for(int l = 0; l < row; l++){
        for(int k = 0; k < col; k++){
            cout << showpoint;
            cout << setprecision(2);
            cout << " " << tables[l][k].div << " ";
        }
        cout << "\n";
    }
}

void delete_table(multdiv_entry** tables, int row){
    for(int i = 0; i < row; i++){
        delete [] tables[i];
        tables[i] = NULL;
    }

    delete tables;
    tables = NULL;
}

bool playagain(){
    int option;
    cout << "Would you like to see a different size matrix (0-no, 1-yes)?";
    cin >> option;

    if(option == 0){
        return false;
    }else if(option == 1){
        return true;
    }

    cout << "\nerror quitting\n";
    return false;
}