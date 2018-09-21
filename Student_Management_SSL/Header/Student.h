#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <fstream>
using namespace std;

class Student {
private:
    int student_id;
    int class_id;
    char grade;

public:
    /*----------------------- Constructor ------------------------------------*/
    Student();
    Student(int stu_id, int class_id, char grade);
    /*---------------------- Guarding functions ------------------------------*/
    /*Setter*/
    void set_student_id(int id);
    void set_class_id(int class_id);
    void set_grade(char grade);

    /*Getter*/
    int get_student_id() const;
    int get_class_id() const;
    char get_grade() const;

    /*---------------------- Overload functions ------------------------------*/
    bool operator==(const Student& stu) const;
    friend bool operator>=(const Student& stu1, const Student& stu2);
    friend ostream& operator<< (ostream& out, const Student& student);
    
};


#endif /* STUDENT_H */

