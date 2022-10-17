#include <iostream>
#include "student.h"

int main(){
    ifstream fileinput;

    file(fileinput);

    int num_of_students;

    fileinput >> num_of_students;

    student* students = create_student_db(num_of_students);
    populate_student_db_info(students, num_of_students, fileinput);
    delete_student_db_info(&students, num_of_students);

    fileinput.close();

    return 0;
}