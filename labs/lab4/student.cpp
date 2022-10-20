#include "student.h"

void file(ifstream& fileinput){
    bool inputgood = false;
    string file_name;

    do{
        file_name = get_file_name();

        fileinput.open(file_name.c_str(), ios::in);

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

/*
    Im goind to creat a student array of our integer size on the heap and then return that
*/
student* create_student_db(int size){
    student* p = new student[size];
    return p;
}

/*
    I use a while loop and read in the data while we aren't at the end of the file
    and when I get all the info i need for one struct I will iterate I to occupy the next object 
    in the array
*/
void populate_student_db_info(student* students, int numstudents, ifstream& fileinput){
    int i = 0;

    while(!fileinput.eof()){
        fileinput  >> students[i].id;
        fileinput >> students[i].first_name;
        fileinput >> students[i].last_name;
        fileinput >> students[i].major;
        i++;
    }
}

/*
    delete the student array on the heap by passing it by reference making it a double 
    pointer and then dereferencing it
*/
void delete_student_db_info(student* *students, int size){
    delete [] *students;
    *students = NULL;
}

void choose_options(student* students, int num, ofstream& fileoutput){
    int option = 0;
    bool inputgood;

    do{
        cout << "Press 1 if you want to search by last name, and press 2 if you want to search for number of unique majors:";
        cin >> option;

        if(option == 1){
            searchname(students, num, fileoutput    );
            inputgood = true;
        } else if(option == 2){
            searchmajor(students, num, fileoutput);
            inputgood = true;
        }
        else{
            cout << "Wrong input try again\n";
            inputgood = false;
        }
    }while(!inputgood);
}

void searchmajor(student* students, int num, ofstream& fileoutput){
    int counter = 0;

    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            if(students[i].major == students[j].major){
                counter++;
            }
        }
    }

    fileoutput << "NUMBER OF UNIQUE MAJORS: " << num - counter << endl;
}

void searchname(student* students, int num, ofstream& fileoutput){
    string name;

    cout << "enter the name you want search for: ";
    cin >> name;

    for(int i = 0; i < num; i++){
        if(students[i].last_name == name){
                fileoutput << students[i].id << " " << students[i].first_name << " " << students[i].last_name << " " << students[i].major << endl;
                cout << "Found a match put it in Outputs.txt\n";
        }
    }
}
