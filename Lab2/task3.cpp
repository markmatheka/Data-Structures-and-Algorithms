#include <iostream>


class Student {
private:
    int grade;

public:
    Student() : grade(0) {}
    Student(int g) : grade(g) {}

    int get_grade() const { return grade; }
    void set_grade(int g) { grade = g; }

    void print_info() const {
        std::cout << "Student Grade: " << grade << std::endl;
    }
};

class Node {
public:
    Student data;
    Node* next;

    Node(Student s) : data(s), next(NULL) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}

    void add(Student s) {
        Node* newNode = new Node(s);
        newNode->data.set_grade(s.get_grade());  
        newNode->next = head;
        head = newNode;
    }

    void print_all() {
        Node* temp = head;
        while (temp != NULL) {
            temp->data.print_info();
            temp = temp->next;
        }
    }
};


int main() {
    LinkedList list;

   
    Student s1(85);
    Student s2(70);
    Student s3(55);

    
    list.add(s1);
    list.add(s2);
    list.add(s3);

    
    list.print_all();

    return 0;
}