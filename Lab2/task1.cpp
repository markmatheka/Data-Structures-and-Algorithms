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

#define MAX_SIZE 40

class StudentList {
private:
    int size;
    Student students[MAX_SIZE];

public:
    StudentList() : size(0) {}

    StudentList(Student s) : size(1) {
        students[0] = s;
    }

    StudentList(const StudentList& other) {
        size = other.size;
        for (int i = 0; i < size; i++) {
            students[i] = other.students[i];
        }
    }

    void add(Student s) {
        if (size < MAX_SIZE) {
            students[size++] = s;
        } else {
            cout << "List is full!" << endl;
        }
    }

    void add_at(Student s, int pos) {
        if (size < MAX_SIZE && pos >= 0 && pos <= size) {
            for (int i = size; i > pos; i--) {
                students[i] = students[i - 1];
            }
            students[pos] = s;
            size++;
        } else {
            cout << "Invalid position or list full!" << endl;
        }
    }

    void remove(Student s) {
        for (int i = 0; i < size; i++) {
            if (students[i].get_regNo() == s.get_regNo()) {
                for (int j = i; j < size - 1; j++) {
                    students[j] = students[j + 1];
                }
                size--;
                return;
            }
        }
    }

    void remove_at(int pos) {
        if (pos >= 0 && pos < size) {
            for (int i = pos; i < size - 1; i++) {
                students[i] = students[i + 1];
            }
            size--;
        }
    }

    int get_size() const {
        return size;
    }

    void destroy() {
        size = 0;
    }

    Student& get_student(int index) {
        return students[index];
    }

    void print_all() {
        for (int i = 0; i < size; i++) {
            students[i].print_info();
        }
    }
};

int main() {
    Course c("ICS2105", "Data Structures");
    StudentList slist;

    for (int i = 0; i < 15; i++) {
        string reg = "S00" + to_string(i+1);
        Student s(reg, "Student" + to_string(i+1), 20 + i % 5, c);
        s.set_marks(45 + i);
        slist.add(s);
    }

    cout << "\n--- All Students ---" << endl;
    slist.print_all();

    cout << "\nTotal Students: " << slist.get_size() << endl;
    return 0;
}