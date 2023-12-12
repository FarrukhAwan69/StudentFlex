
#include <iostream>
#include <string>
class Course {
private:
    std::string code;
    std::string name;
    std::string instructor;
    int credits;
    int capacity;
    int totalStudents; // Track total number of students
    std::string students[40]; // Array to hold student IDs (assuming a max of 40 students)

public:
    // Default constructor
    Course();

    // Parameterized constructor
    Course(std::string code, std::string name, std::string instructor, int credits, int capacity);

    // Getters
    std::string getCode() const;
    std::string getName() const;
    std::string getInstructor() const;
    int getCredits() const;
    int getCapacity() const;
    int getTotalStudents() const; // Getter for total number of students

    // Functions to manage students
    bool enrollStudent(std::string studentID); // Enroll a student
    bool isFull() const; // Check if course is full
    void displayStudents() const; // Display enrolled students

    // Setters
    void setCode(std::string newCode);
    void setName(std::string newName);
    void setInstructor(std::string newInstructor);
    void setCredits(int newCredits);
    void setCapacity(int newCapacity);
    void AddStudent(std::string RoolNo);
    void RemoveStudent(std::string rollNo);
    void printStudentList();
    bool StudentExist(std::string RollNo);

    // Overloaded stream operators
    friend std::ostream& operator<<(std::ostream& os, const Course& course);
    friend std::istream& operator>>(std::istream& is, Course& course);
};