
struct Course {
    string course_code;
    string course_name;
};

struct Grade {
    int mark;
    char the_grade;

    void calculateGrade() {
        if (mark > 69) the_grade = 'A';
        else if (mark > 59) the_grade = 'B';
        else if (mark > 49) the_grade = 'C';
        else if (mark > 39) the_grade = 'D';
        else the_grade = 'E';
    }
};

struct Student {
    string reg_no;
    string name;
    int age;
    Course course;
    Grade grade;
    bool gradeFinalized = false;
};

const int MAX_STUDENTS = 40;
Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Max student limit reached!\n";
        return;
    }

    Student s;
    cout << "Enter registration number: ";
    cin >> s.reg_no;
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, s.name);
    cout << "Enter age: ";
    cin >> s.age;
    cin.ignore();
    cout << "Enter course code: ";
    getline(cin, s.course.course_code);
    cout << "Enter course name: ";
    getline(cin, s.course.course_name);
    students[studentCount++] = s;
}

void editStudent(string reg_no) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].reg_no == reg_no) {
            cout << "Editing details for " << reg_no << endl;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, students[i].name);
            cout << "Enter new age: ";
            cin >> students[i].age;
            return;
        }
    }
    cout << "Student not found.\n";
}

void addMarks(string reg_no) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].reg_no == reg_no) {
            if (students[i].gradeFinalized) {
                cout << "Grade already finalized and cannot be changed.\n";
                return;
            }
            cout << "Enter mark (0-100): ";
            cin >> students[i].grade.mark;
            students[i].grade.calculateGrade();
            students[i].gradeFinalized = true;
            cout << "Grade calculated: " << students[i].grade.the_grade << endl;
            return;
        }
    }
    cout << "Student not found.\n";
}