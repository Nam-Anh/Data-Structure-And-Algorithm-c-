#include "../Header/Student.h"

/*----------------------- Constructor ------------------------------------*/
Student::Student() {

}

Student::Student(int stu_id, int class_id, char grade) {
    this->student_id = stu_id;
    this->class_id = class_id;
    this->grade = grade;
}

/*Setter*/
void Student::set_student_id(int id) {
    this->student_id = id;
}

void Student::set_class_id(int id) {
    this->class_id = id;
}

void Student::set_grade(char grade) {
    this->grade = grade;
}

/*Getter*/
int Student::get_student_id() const{
    return this->student_id;
}

int Student::get_class_id() const{
    return this->class_id;
}

char Student::get_grade() const{
    return this->grade;
}

/*---------------------- Overload functions ------------------------------*/
bool Student::operator==(const Student& stu) const{
    if ((stu.student_id == this->student_id) &&
            (stu.class_id == this->class_id) &&
            (stu.grade == this->grade)) {
        return true;
    }

    return false;
}
bool operator>=(const Student& stu1, const Student& stu2){
    if ((stu1.get_student_id() >= stu2.get_student_id()) &&
            (stu1.get_class_id() >= stu2.get_class_id()) &&
            (stu1.get_grade() >= stu2.get_grade())) {
        return true;
    }

    return false;
}
ostream& operator <<(ostream& out, const Student& student){
    cout << "Student's info\n";
    cout << student.get_student_id() 
            << "\t" << student.get_class_id() 
            << "\t" <<student.get_grade();
    
    return out;
}