#include <iostream>
#include <vector>
#include <fstream>
#include "Student.hpp" // Assuming you have a Student class
#include "Course.hpp" // Assuming you have a Course class
#include "FileHandler.hpp"
using namespace std;
class System {
private:
    std::vector<Student> students; // Vector to hold Student objects
    std::vector<Course> courses; // Vector to hold Course objects

public:
    // Methods to display menus
    void mainLoop();
    void submenu1();
    void submenu2();
    void submenu3();
    void submenu4();
    void submenu5();
    void displayMainMenu();
    void displayEnrollStudentMenu();
    void displayCourseRegistrationMenu();
    void displayAttendanceMenu();
    void displayMarksMenu();
    void displayCourseWithdrawMenu();

    // Method to get user input
    int getUserInput();

    // Method to validate user input
    bool validateInput(int input, int range);

    // Methods to perform actions
    void enrollStudent();
    void registerCourse();
    void displayStudentAttendance();
    void displayStudentMarks();
    void withdrawCourse();
    void editAttendence();

    void editMarks();

    // Method to save data to file
    void saveDataFromFile();
    void saveData();
};