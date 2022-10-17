#include <iostream>
#include "student.h"

int main(){
    ifstream fileinput;
    ofstream fileoutput;

    fileoutput.open("output.txt", ios::out);

    file(fileinput);

    int num_of_students;

    fileinput >> num_of_students;

    student* students = create_student_db(num_of_students);
    populate_student_db_info(students, num_of_students, fileinput);

    choose_options(students, num_of_students, fileoutput);

    delete_student_db_info(&students, num_of_students);

    fileinput.close();
    fileoutput.close();

    return 0;
}
