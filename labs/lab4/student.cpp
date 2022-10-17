#include "student.h"

void file(ifstream& fileinput){
    bool inputgood = false;
    string file_name;

    do{
        file_name = get_file_name();

        fileinput.open(file_name, ios::in);

        if(!fileinput.is_open()){
            inputgood = false;
            cout << "That file doesn't exist try again\n";
        }else{
            inputgood = true;
        }
    }while(!inputgood);
}

string get_file_name(){
    string filename;

    cout << "Welcome please enter your input file: ";
    cin >> filename;

    return filename;

}

student* create_student_db(int size){
    student* p = new student[size];
    return p;
}

void populate_student_db_info(student* students, int numstudents, ifstream& fileinput){
    for(int i = 0; i < numstudents; i++){
        fileinput  >> students[i].id;
        fileinput >> students[i].first_name;
        fileinput >> students[i].last_name;
        fileinput >> students[i].major;
    }
}

void delete_student_db_info(student **students, int size){
    delete [] students;
    students = NULL;
}