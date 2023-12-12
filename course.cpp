#include "Course.hpp"

Course::Course() : code(""), name(""), instructor(""), credits(0), capacity(0), totalStudents(0) {
    for (int i = 0; i < 40; ++i) {
        students[i] = "-"; // Initialize student IDs to - (indicating empty slots)
    }
}


Course::Course(std::string code, std::string name, std::string instructor, int credits, int capacity) : code(code), name(name), instructor(instructor), credits(credits), capacity(capacity), totalStudents(0) {
    for (int i = 0; i < 40; ++i) {
        students[i] = "-"; // Initialize student IDs to - (indicating empty slots)
    }
}


std::string Course::getCode() const {
    return code;
}

std::string Course::getName() const {
    return name;
}

std::string Course::getInstructor() const {
    return instructor;
}

int Course::getCredits() const {
    return credits;
}

int Course::getCapacity() const {
    return capacity;
}

int Course::getTotalStudents() const {
    return totalStudents;
}


bool Course::enrollStudent(std::string studentID) {
    if (isFull()) {
        std::cout << "Course is full. Cannot enroll more students.\n";
        return false;
    }

    for (int i = 0; i < 40; ++i) {
        if (students[i] == "") {
            students[i] = studentID;
            ++totalStudents;
            return true;
        }
    }
    return false;
}

bool Course::isFull() const {
    return totalStudents >= capacity;
}

void Course::displayStudents() const {
    std::cout << "Enrolled students in " << name << " (Course Code: " << code << "):\n";
    if (totalStudents == 0) {
        std::cout << "No students enrolled.\n";
        return;
    }

    std::cout << "Student IDs:\n";
    for (int i = 0; i < 40; ++i) {
        if (students[i] != "") {
            std::cout << students[i] << "\n";
        }
    }
}

void Course::setCode(std::string newCode) {
    code = newCode;
}

void Course::setName(std::string newName) {
    name = newName;
}

void Course::setInstructor(std::string newInstructor) {
    instructor = newInstructor;
}

void Course::setCredits(int newCredits) {
    credits = newCredits;
}

void Course::setCapacity(int newCapacity) {
    capacity = newCapacity;
}
void Course::AddStudent(std::string rollNo) {
    for (int i = 0; i < 40; i++) {
        if (students[i] == "-") {
            students[i] = rollNo;
            break;
        }
    }
}
void Course::RemoveStudent(std::string rollNo) {
    for (int i = 0; i < 40; i++) {
        if (students[i] == rollNo) {
            students[i] = "-";
            break;
        }
    }
}
void Course::printStudentList() {
    for (int i = 0; i < 40; i++) {
       std:: cout << students[i]<<" ";
    }
    std::cout << std::endl;
}
bool Course::StudentExist(std::string RollNo) {

    for (int i = 0; i < 40; i++) {
    std::cout << students[i] << std::endl;
        if (students[i] == RollNo) {
            students[i] = "-";
            return true;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Course& course) {
    os << "Course Code: " << course.code << "\n"
        << "Course Name: " << course.name << "\n"
        << "Instructor: " << course.instructor << "\n"
        << "Credits: " << course.credits << "\n"
        << "Capacity: " << course.capacity << "\n"
        << "Total Students Enrolled: " << course.totalStudents << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Course& course) {
    std::cout << "Enter Course Code: ";
    is >> course.code;

    std::cout << "Enter Course Name: ";
    is >> course.name;

    std::cout << "Enter Instructor Name: ";
    is >> course.instructor;

    std::cout << "Enter Credits: ";
    is >> course.credits;

    std::cout << "Enter Capacity: ";
    is >> course.capacity;

    course.totalStudents = 0; // Reset total students

    for (int i = 0; i < 40; ++i) {
        course.students[i] = "-"; // Initialize student IDs to -1 (empty slots)
    }

    return is;
}