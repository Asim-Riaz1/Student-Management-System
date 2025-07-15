#include <iostream>
#include <vector>
using namespace std;
class Student {
private:
    string name;
    int marks;
    int rollNumber;
    int age;
    char grades;
public:
    void setName(string name) {
        this->name = name;
    }
    string getName() const { return name; } 
    void setMarks(int marks) {
        this->marks = marks;
    }
    int getMarks() const { return marks; } 
    void setRollNumber(int rollNumber) {
        this->rollNumber = rollNumber;
    }
    int getRollNumber() const { return rollNumber; } 
    void setAge(int age) {
        this->age = age;
    }
    int getAge() const { return age; } 
    void setGrades(char grades) {
        this->grades = grades;
    }
    char getGrades() const { return grades; } 
    void assignGrades(int marks) {
        if (marks >= 80 && marks <= 100)
            grades = 'A';
        else if (marks >= 70 && marks < 80)
            grades = 'B';
        else if (marks >= 60 && marks < 70)
            grades = 'C';
        else if (marks >= 50 && marks < 60)
            grades = 'D';
        else if (marks >= 0 && marks < 50)
            grades = 'F';
        else
            cout << "Invalid marks" << endl;
    };
    void displayReport(const vector<Student>& students) { 
        int rollNum; 
        cout << "Enter Roll Number of Student: " << endl; 
        cin >> rollNum; 
        bool found = false; 
        for (const auto& student : students) { 
            if (student.getRollNumber() == rollNum) { 
                cout << "Name: " << student.getName() << endl; 
                cout << "Roll Number: " << student.getRollNumber() << endl; 
                cout << "Age: " << student.getAge() << endl; 
                cout << "Grades: " << student.getGrades() << endl; 
                found = true; 
                break; 
            } 
        } 
        if (!found) 
            cout << "Invalid Roll Number" << endl; 
    } 
    void addReport(vector<Student> &students) {
        int amount;
        cout << "How many Student Reports you want to add?" << endl;
        cin >> amount;
        cin.ignore(); // changed: clear leftover newline only once after reading amount
        for (int i = 0; i < amount; i++) {
            cout << "Enter Name: " << endl;
            string name;
            getline(cin, name); // changed: use getline for full name
            cout << "Enter Roll Number: " << endl;
            int rollNumber;
            cin >> rollNumber;
            cout << "Enter Age: " << endl;
            int age;
            cin >> age;
            cout << "Enter Marks: " << endl;
            int marks;
            cin >> marks;
            cin.ignore();
            Student s;
            s.setName(name);
            s.setRollNumber(rollNumber);
            s.setMarks(marks);
            s.assignGrades(marks);
            s.setAge(age);
            students.push_back(s);
        }
    }
    void deleteReport(vector<Student> &students) {
        int rollNum;
        cout << "Enter Roll Number of Student to delete: " << endl;
        cin >> rollNum;
        bool found = false;
        for (auto i = students.begin(); i != students.end(); i++) {
            if (i->getRollNumber() == rollNum) {
                students.erase(i);
                cout << "Student with Roll Number " << rollNum << " was deleted." << endl; 
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Student not found" << endl;
    }
};
int main()
{
    Student s;
    int choice = 0;
    vector<Student> students;
    while (choice != 4) {
        cout << "***Student Report Card Management System***" << endl;
        cout << "1. Add new Student Record" << endl;
        cout << "2. Delete Student Record" << endl;
        cout << "3. Display Student Report" << endl;
        cout << "4. Exit" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                s.addReport(students);
                break;
            case 2:
                s.deleteReport(students);
                break;
            case 3:
                s.displayReport(students); 
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid Choice" << endl;
        }
    }
}