#include <iostream>
#include <string>
using namespace std;

class Course {
public:
    string course_code;
    string course_name;

    Course() {}
    Course(string code, string name) : course_code(code), course_name(name) {}
};

class Grade {
private:
    int mark;
    char the_grade;

public:
    Grade() : mark(0), the_grade('E') {}

    void set_mark(int m) {
        mark = m;
        if (mark > 69) the_grade = 'A';
        else if (mark > 59) the_grade = 'B';
        else if (mark > 49) the_grade = 'C';
        else if (mark > 39) the_grade = 'D';
        else the_grade = 'E';
    }

    int get_mark() const { return mark; }
    char get_grade() const { return the_grade; }
};

class Student {
private:
    string regNo;
    string name;
    int age;
    Course course;
    Grade grade;

public:
    Student() {}
    Student(string reg, string n, int a, Course c)
        : regNo(reg), name(n), age(a), course(c) {}

    void set_marks(int m) { grade.set_mark(m); }
    int get_marks() const { return grade.get_mark(); }
    void set_regNo(string reg) { regNo = reg; }
    string get_regNo() const { return regNo; }
    void set_name(string n) { name = n; }
    string get_name() const { return name; }
    void set_age(int a) { age = a; }
    int get_age() const { return age; }
    void set_course(Course c) { course = c; }
    Course get_course() const { return course; }
    void set_grade(Grade g) { grade = g; }
    Grade get_grade() const { return grade; }

    void print_info() const {
        cout << "RegNo: " << regNo << ", Name: " << name
             << ", Age: " << age << ", Course: " << course.course_name
             << ", Marks: " << grade.get_mark()
             << ", Grade: " << grade.get_grade() << endl;
    }
};