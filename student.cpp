#include"Student.hpp"

Student::Student() {
    name = "";
    roll = "";
    age = 0;
    contact = "";
    for (int i = 0; i < 5; ++i) {
        marks[i] = -1;
        attendance[i] = -1;
        courses[i] = "";
    }
}

Student::Student(const std::string& studentName, const std::string& studentRoll, int studentAge, const std::string& studentContact, const int studentMarks[], const int studentAttendance[], const std::string studentCourses[]) {
    name = studentName;
    roll = studentRoll;
    age = studentAge;
    contact = studentContact;

    for (int i = 0; i < 5; ++i) {
        marks[i] = studentMarks[i];
        attendance[i] = studentAttendance[i];
        courses[i] = studentCourses[i];
    }
}

std::string Student::getName() const {
    return name;
}

std::string Student::getRoll() const {
    return roll;
}

int Student::getAge() const {
    return age;
}

std::string Student::getContact() const {
    return contact;
}

int Student::getMark(int index) const {
    if (index >= 0 && index < 5) {
        return marks[index];
    }
    else {
        return -1; // Handle out-of-bounds access or return a default value
    }
}

int Student::getAttendance(int index) const {
    if (index >= 0 && index < 5) {
        return attendance[index];
    }
    else {
        return -1; // Handle out-of-bounds access or return a default value
    }
}

std::string Student::getCourse(int index) const {
    if (index >= 0 && index < 5) {
        return courses[index];
    }
    else {
        return ""; // Handle out-of-bounds access or return an empty string
    }
}

void Student::setName(const std::string& studentName) {
    name = studentName;
}

void Student::setRoll(const std::string& studentRoll) {
    roll = studentRoll;
}

void Student::setAge(int studentAge) {
    age = studentAge;
}

void Student::setContact(const std::string& studentContact) {
    contact = studentContact;
}

void Student::setMark(int index, int value) {
    if (index >= 0 && index < 5) {
        marks[index] = value;
    }
    else {
        std::cout << "Index out of range!\n"; // Handle out-of-bounds access
    }
}

void Student::setAttendance(int index, int value) {
    if (index >= 0 && index < 5) {
        attendance[index] = value;
    }
    else {
        std::cout << "Index out of range!\n"; // Handle out-of-bounds access
    }
}

void Student::setCourse(int index, const std::string& value) {
    if (index >= 0 && index < 5) {
        courses[index] = value;
    }
    else {
        std::cout << "Index out of range!\n"; // Handle out-of-bounds access
    }
}

std::ostream& operator<<(std::ostream& out, const Student& student) {
    out << "Name: " << student.getName() << std::endl;
    out << "Roll: " << student.getRoll() << std::endl;
    out << "Age: " << student.getAge() << std::endl;
    out << "Contact: " << student.getContact() << std::endl;
    out << "Marks: ";
    for (int i = 0; i < 5; ++i) {
        out << student.getMark(i) << " ";
    }
    out << std::endl;

    out << "Attendance: ";
    for (int i = 0; i < 5; ++i) {
        out << student.getAttendance(i) << " ";
    }
    out << std::endl;

    out << "Courses: ";
    for (int i = 0; i < 5; ++i) {
        out << student.getCourse(i) << " ";
    }
    out << std::endl;

    return out;
}

std::istream& operator>>(std::istream& in, Student& student) {
    std::string name, roll, contact;
    int age;
    int marks[5];
    int attendance[5];
    std::string courses[5];

    std::cout << "Enter Name: ";
    in >> name;
    student.setName(name);

    std::cout << "Enter Roll: ";
    in >> roll;
    student.setRoll(roll);

    std::cout << "Enter Age: ";
    in >> age;
    student.setAge(age);

    std::cout << "Enter Contact: ";
    in >> contact;
    student.setContact(contact);

    std::cout << "Enter Marks (5 values): ";
    for (int i = 0; i < 5; ++i) {
        in >> marks[i];
        student.setMark(i, marks[i]);
    }

    std::cout << "Enter Attendance (5 values): ";
    for (int i = 0; i < 5; ++i) {
        in >> attendance[i];
        student.setAttendance(i, attendance[i]);
    }

    std::cout << "Enter Courses (5 values): ";
    for (int i = 0; i < 5; ++i) {
        in >> courses[i];
        student.setCourse(i, courses[i]);
    }

    return in;
}
void Student::printAttendance()
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << courses[i] << attendance[i];
    }
}
void Student::printMarks()
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << courses[i] << marks[i];
    }
}
void Student::enrolledCourses()
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << courses[i];
    }
}