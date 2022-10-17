#ifndef STUDENT
#define STUDENT

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

struct student{
    int id;
    string first_name;
    string last_name;
    string major;
};

student* create_student_db(int);
void populate_student_db_info(student *, int, ifstream &);
void delete_student_db_info(student **, int);
string get_file_name();

void file(ifstream&);
void choose_options(student* students, int num, ofstream& fileoutput);
void searchname(student* students, int num, ofstream& fileoutput);
void searchmajor(student* students, int num, ofstream& fileoutput);

#endif