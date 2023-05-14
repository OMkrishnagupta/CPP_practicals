#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    void getName() {
        cout << "Enter name: ";
        cin >> name;
    }

    virtual void display() {
        cout << "Name: " << name << endl;
    }
};

class Student : public Person {
protected:
    string course;
    int marks;
    int year;

public:
    void getStudentDetails() {
        cout << "Enter course: ";
        cin >> course;

        cout << "Enter marks: ";
        cin >> marks;

        cout << "Enter year: ";
        cin >> year;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
        cout << "Year: " << year << endl;
    }
};

class Employee : public Person {
protected:
    string department;
    int salary;

public:
    void getEmployeeDetails() {
        cout << "Enter department: ";
        cin >> department;

        cout << "Enter salary: ";
        cin >> salary;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    Person* personPtr;
    Student studentObj;
    Employee employeeObj;

    personPtr = &studentObj;
    personPtr->getName();
    studentObj.getStudentDetails();
    personPtr->display();

    personPtr = &employeeObj;
    personPtr->getName();
    employeeObj.getEmployeeDetails();
    personPtr->display();

    return 0;
}
