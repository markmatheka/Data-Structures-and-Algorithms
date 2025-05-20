#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char course_code[20];
    char course_name[50];
} Course;

typedef struct {
    int mark;
    char grade;
} Grade;

typedef struct {
    char regNo[20];
    char name[50];
    int age;
    Course course;
    Grade grade;
} Student;

typedef struct Node {
    Student data;
    struct Node* next;
} StudentNode;

StudentNode* head = NULL;

char calculate_grade(int mark) {
    if (mark > 69) return 'A';
    if (mark > 59) return 'B';
    if (mark > 49) return 'C';
    if (mark > 39) return 'D';
    return 'E';
}

void add_student(Student s) {
    StudentNode* new_node = (StudentNode*)malloc(sizeof(StudentNode));
    new_node->data = s;
    new_node->data.grade.grade = calculate_grade(s.grade.mark);
    new_node->next = head;
    head = new_node;
}

void print_students() {
    StudentNode* temp = head;
    while (temp != NULL) {
        printf("RegNo: %s, Name: %s, Mark: %d, Grade: %c\n",
               temp->data.regNo, temp->data.name,
               temp->data.grade.mark, temp->data.grade.grade);
        temp = temp->next;
    }
}

int main() {
    Student s1 = {"S001", "Alice", 20, {"ICS2105", "Data Structures"}, {85, 'A'}};
    Student s2 = {"S002", "Bob", 21, {"ICS2106", "Algorithms"}, {75, 'B'}};
    Student s3 = {"S003", "Charlie", 22, {"ICS2107", "Operating Systems"}, {65, 'C'}};
    Student s4 = {"S004", "David", 23, {"ICS2108", "Database Systems"}, {55, 'D'}};
    Student s5 = {"S005", "Eve", 24, {"ICS2109", "Software Engineering"}, {45, 'D'}};

    add_student(s1);
    add_student(s2);
    add_student(s3);
    add_student(s4);
    add_student(s5);
    print_students();
    return 0;

}