#include <iostream>
//#include "Course.hpp"
#include "System.hpp"
#include "FileHandler.hpp"
#include<windows.h>
//#include "Student.hpp"
int main() {
  //  System system;
  ///*  system.mainLoop(); */
  //  system.saveDataFromFile();

  //  system.enrollStudent();
  //  system.saveData();
  // /* system.enrollStudent();
  //  system.saveData();
  //  system.enrollStudent();
  //  system.saveData();*/

  //  system.registerCourse();
  //  system.withdrawCourse();

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Define the background color as blue and white (bright blue)
    int background = BACKGROUND_BLUE | BACKGROUND_INTENSITY;

    // Set the background color
    SetConsoleTextAttribute(hConsole, background);

    // Clear the screen to display the background color
    system("cls");

    System system;
    system.mainLoop();


    return 0;
}