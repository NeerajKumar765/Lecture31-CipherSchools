#include <iostream>
using namespace std;

// Base class: Person
class Person {
protected:
    string name;
    int age;

public:
    // Constructor
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    // Function to display person details
    virtual void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class: Student (inherits from Person)
class Student : public Person {
private:
    int studentID;
    float total_marks;

public:
    // Constructor
    Student(string name, int age, int studentID, float total_marks)
        : Person(name, age) {
        this->studentID = studentID;
        this->total_marks = total_marks;
    }

    // Function to display student details
    void display() override {
        cout << "Student ID: " << studentID << ", Name: " << name
             << ", Age: " << age << ", Total Marks: " << total_marks << endl;
    }

    // Function to calculate percentage
    void calculate_percentage() {
        float percentage = (total_marks / 500) * 100; // Assuming total marks out of 500
        cout << "Percentage: " << percentage << "%" << endl;
    }
};

// Derived class: Teacher (inherits from Person)
class Teacher : public Person {
private:
    int employeeID;
    string subject;

public:
    // Constructor
    Teacher(string name, int age, int employeeID, string subject)
        : Person(name, age) {
        this->employeeID = employeeID;
        this->subject = subject;
    }

    // Function to display teacher details
    void display() override {
        cout << "Employee ID: " << employeeID << ", Name: " << name
             << ", Age: " << age << ", Subject: " << subject << endl;
    }
};

int main() {
    // Creating objects
    Student student1("Alice", 20, 1234, 450);
    Teacher teacher1("Mr. Smith", 45, 5678, "Mathematics");

    // Displaying details
    cout << "Student Details:" << endl;
    student1.display();
    student1.calculate_percentage();

    cout << "\nTeacher Details:" << endl;
    teacher1.display();

    // Demonstrating polymorphism
    Person* person1 = &student1;
    Person* person2 = &teacher1;

    cout << "\nPolymorphism:" << endl;
    person1->display(); // Calls Student's display
    person2->display(); // Calls Teacher's display

    return 0;
}
