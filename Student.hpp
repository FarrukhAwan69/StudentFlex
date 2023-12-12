#pragma once
#include <string>
#include<iostream>

class Student {
private:
    std::string name;
    std::string roll;
    int age;
    std::string contact;
    int marks[5];
    int attendance[5];
    std::string courses[5];

public:
    Student();
    Student(const std::string& studentName, const std::string& studentRoll, int studentAge, const std::string& studentContact, const int studentMarks[], const int studentAttendance[], const std::string studentCourses[]);
    std::string getName() const;
    std::string getRoll() const;
    int getAge() const;
    std::string getContact() const;

    int getMark(int index) const;

    int getAttendance(int index) const;

    std::string getCourse(int index) const;

    // Setter methods
    void setName(const std::string& studentName);

    void setRoll(const std::string& studentRoll);

    void setAge(int studentAge);

    void setContact(const std::string& studentContact);

    void setMark(int index, int value);

    void setAttendance(int index, int value);

    void setCourse(int index, const std::string& value);
    void printAttendance();
    void printMarks();
    void enrolledCourses();
    friend std::ostream& operator<<(std::ostream& out, const Student& student);
    friend std::istream& operator>>(std::istream& in, Student& student);
};