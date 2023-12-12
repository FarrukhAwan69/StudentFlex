//
#include "System.hpp" // Assuming System.h contains the System class declaration
//
//void System::mainLoop()
//{
//    while (true) {
//
//        displayMainMenu();
//        int choice = getUserInput();
//        system("cls");
//    }
//}
//
//void System::displayMainMenu() {
//    // Display the main menu options
//    std::cout << "Main Menu\n";
//    std::cout << "1- Enroll a student\n";
//    std::cout << "2- Course Registration\n";
//    std::cout << "3- Attendance\n";
//    std::cout << "4- Marks\n";
//    std::cout << "5- Course Withdraw\n";
//    std::cout << "6- Exit\n";
//    std::cout << "Press 1 to 6 to select an option: ";
//
//}
//
//// Other display menu methods can follow a similar structure
//
//int System::getUserInput() {
//    int choice;
//    std::cin >> choice;
//    return choice;
//}
//
//bool System::validateInput(int input, int range) {
//    return (input >= 1 && input <= range);
//}
//
//
//void System::enrollStudent() {
//    // Implement logic to enroll a student
//    FileHandler file("data.txt");
//    fstream f;
//    file.openFile(f, true);
//
//
//    string data = "\n";
//    file.writeFile(data, f);
//    string name;
//    cout << "Enter the name of student : ";
//    getline(cin, name);
//    data = "Name: ";
//    data.append(name);
//    data.push_back('\n');
//    file.writeFile(data, f);
//
//    string rollNo;
//    cout << "Enter the roll number : ";
//    getline(cin, rollNo);
//    data = "Roll number: ";
//    data.append(rollNo);
//    data.push_back('\n');
//    file.writeFile(data, f);
//
//    string age;
//    cout << "Enter age of student : ";
//    getline(cin, age);
//    data = "Age: ";
//    data.append(age);
//    data.push_back('\n');
//    file.writeFile(data, f);
//
//    string* STUcourse = new string[5];
//    int* STUatten = new int[5];
//    int* STUmarks = new int[5];
//    for (int i = 0; i < 5; i++) STUcourse[i] = "-";
//    for (int i = 0; i < 5; i++) STUatten[i] = -1;
//    for (int i = 0; i < 5; i++) STUmarks[i] = -1;
//
//    data = "CourseName: ";
//    for (int i = 0; i < 5; i++) {
//        data.append(STUcourse[i]);
//        if (i != 4)
//            data.push_back(' ');
//    }
//    data.push_back('\n');
//    file.writeFile(data, f);
//
//    data = "Attendence: ";
//    for (int i = 0; i < 5; i++) {
//        string atten = to_string(STUatten[i]);
//        if (i != 4)
//            atten.push_back(' ');
//        data.append(atten);
//    }
//    data.push_back('\n');
//    file.writeFile(data, f);
//
//
//    data = "Marks: ";
//    for (int i = 0; i < 5; i++) {
//        string marks = to_string(STUatten[i]);
//        if (i != 4)
//            marks.push_back(' ');
//        data.append(marks);
//    }
//    data.push_back('\n');
//    file.writeFile(data, f);
//    data = "$\n";
//    file.writeFile(data, f);
//    data = "&";
//    file.writeFile(data, f);
//}
//
//void System::registerCourse() {
//    while (true) {
//        int CourseInput;
//        cout << "Which course you want to register : " << endl;
//        for (int i = 0; i < this->courses.size(); i++) {
//            cout << i + 1 << ": " << this->courses[i].getName() << endl;
//        }
//        cout << "6 : Exit" << endl;
//        cin >> CourseInput;
//        if (CourseInput == 6) {
//            break;
//        }
//        else if (CourseInput >= 1 && CourseInput < 6) {
//            string RollNo;
//            cout << "Enter the Roll No of the student want to register course : ";
//            cin >> RollNo;
//            int index = 0;
//            string courseNAME;
//            for (; index < students.size(); index++) {
//                if (students[index].getRoll() == RollNo) {
//                    RollNo = students[index].getRoll();
//                    students[index].setMark(CourseInput - 1, 0);
//                    students[index].setAttendance(CourseInput - 1, 0);
//                    students[index].setCourse(CourseInput - 1, this->courses[CourseInput - 1].getName());
//                    courseNAME = this->courses[CourseInput - 1].getName();
//                    break;
//                }
//            }
//            for (int i = 0; i < courses.size(); i++) {
//                if (courses[i].getName() == courseNAME) {
//                    courses[i].AddStudent(RollNo);
//                    break;
//                }
//            }
//            FileHandler file("data.txt");
//            fstream f;
//            file.openFile(f);
//            string line = file.readFile(f);
//            bool posiFound = false;
//
//
//            while (!posiFound) {
//                size_t found = line.find(RollNo);
//                if (found != std::string::npos) {
//                    posiFound = true;
//                    break;
//                }
//
//                line = file.readFile(f);
//            }
//            // cout << line;
//            file.readFile(f);
//            f.seekp(f.tellg());
//
//            if (posiFound) {
//                // cout << line;
//
//                string data = "CourseName: ";
//                for (int i = 0; i < 5; i++) {
//                    data.append(students[index].getCourse(i));
//                    if (i != 4)
//                        data.push_back(' ');
//                }
//                data.push_back('\n');
//                file.writeFile(data, f);
//
//                data = "Attendence: ";
//                for (int i = 0; i < 5; i++) {
//                    string atten = to_string(students[index].getAttendance(i));
//                    if (i != 4)
//                        atten.push_back(' ');
//                    data.append(atten);
//                }
//                data.push_back('\n');
//                file.writeFile(data, f);
//
//
//                data = "Marks: ";
//                for (int i = 0; i < 5; i++) {
//                    string marks = to_string(students[index].getMark(i));
//                    if (i != 4)
//                        marks.push_back(' ');
//                    data.append(marks);
//                }
//                // data.push_back('\n');
//                file.writeFile(data, f);
//            }
//        }
//
//        //system("cls");
//    }
//    cin.ignore();
//    int i = 0;
//    while (i < students.size()) {
//        cout << students[i] << endl;
//        i++;
//    }
//}
//
//void System::displayStudentAttendance() {
//    // Implement logic to display student attendance
//}
//
//void System::displayStudentMarks() {
//    // Implement logic to display student marks
//}
//
//void System::withdrawCourse() {
//    // Implement logic to withdraw a course for a student
//    while (true) {
//        int CourseInput;
//        cout << "Which course you want to withdraw : " << endl;
//        for (int i = 0; i < this->courses.size(); i++) {
//            cout << i + 1 << ": " << this->courses[i].getName() << endl;
//        }
//        cout << "6 : Exit" << endl;
//        cin >> CourseInput;
//        if (CourseInput == 6) {
//            break;
//        }
//        else if (CourseInput >= 1 && CourseInput < 6) {
//            string RollNo;
//            cout << "Enter the Roll No of the student want to withdraw course : ";
//            cin >> RollNo;
//            string courseNAME;
//            if (courses[CourseInput - 1].StudentExist(RollNo)) {
//                int index = 0;
//                for (; index < students.size(); index++) {
//                    if (students[index].getRoll() == RollNo) {
//                        RollNo = students[index].getRoll();
//                        students[index].setMark(CourseInput - 1, -1);
//                        students[index].setAttendance(CourseInput - 1, -1);
//                        courseNAME = this->courses[CourseInput - 1].getName();
//                        students[index].setCourse(CourseInput - 1, "-");
//                        break;
//                    }
//                }
//
//                for (int i = 0; i < courses.size(); i++) {
//                    if (courses[i].getName() == courseNAME) {
//                        courses[i].RemoveStudent(RollNo);
//                        break;
//                    }
//                }
//
//                FileHandler file("data.txt");
//                fstream f;
//                file.openFile(f);
//                string line = file.readFile(f);
//                bool posiFound = false;
//
//                while (!posiFound) {
//                    size_t found = line.find(RollNo);
//                    if (found != std::string::npos) {
//                        posiFound = true;
//                        break;
//                    }
//                    line = file.readFile(f);
//                }
//                // cout << line;
//                file.readFile(f);
//                f.seekp(f.tellg());
//
//                if (posiFound) {
//
//                    string data = "CourseName: ";
//                    for (int i = 0; i < 5; i++) {
//                        data.append(students[index].getCourse(i));
//                        if (i != 4)
//                            data.push_back(' ');
//                    }
//                    data.push_back('\n');
//                    file.writeFile(data, f);
//
//                    data = "Attendence: ";
//                    for (int i = 0; i < 5; i++) {
//                        string atten = to_string(students[index].getAttendance(i));
//                        if (i != 4)
//                            atten.push_back(' ');
//                        data.append(atten);
//                    }
//                    data.push_back('\n');
//                    file.writeFile(data, f);
//
//
//                    data = "Marks: ";
//                    for (int i = 0; i < 5; i++) {
//                        string marks = to_string(students[index].getMark(i));
//                        if (i != 4)
//                            marks.push_back(' ');
//                        data.append(marks);
//                    }
//                    // data.push_back('\n');
//                    file.writeFile(data, f);
//                }
//            }
//            else {
//                cout << "Student does not have this course " << endl;
//            }
//        }
//        //system("cls");
//    }
//    cin.ignore();
//    int i = 0;
//    while (i < students.size()) {
//        cout << students[i] << endl;
//        i++;
//    }
//}
//
//void System::editAttendence()
//{
//    // Implement logic to withdraw a course for a student
//    while (true) {
//        int CourseInput;
//        cout << "Which course you want to withdraw : " << endl;
//        for (int i = 0; i < this->courses.size(); i++) {
//            cout << i + 1 << ": " << this->courses[i].getName() << endl;
//        }
//        cout << "6 : Exit" << endl;
//        cin >> CourseInput;
//        if (CourseInput == 6) {
//            break;
//        }
//        else if (CourseInput >= 1 && CourseInput < 6) {
//            string RollNo;
//            cout << "Enter the Roll No of the student whose attendence is to updated : ";
//            cin >> RollNo;
//            if (courses[CourseInput - 1].StudentExist(RollNo)) {
//                int index = 0;
//                int attendence = 0;
//                cout << "Enter the attendence of the student : ";
//                cin >> attendence;
//                for (; index < students.size(); index++) {
//                    if (students[index].getRoll() == RollNo) {
//                        RollNo = students[index].getRoll();
//                        students[index].setAttendance(CourseInput - 1,attendence);
//                        break;
//                    }
//                }
//
//
//                FileHandler file("data.txt");
//                fstream f;
//                file.openFile(f);
//                string line = file.readFile(f);
//                bool posiFound = false;
//
//                while (!posiFound) {
//                    size_t found = line.find(RollNo);
//                    if (found != std::string::npos) {
//                        posiFound = true;
//                        break;
//                    }
//                    line = file.readFile(f);
//                }
//                // cout << line;
//                file.readFile(f);
//                f.seekp(f.tellg());
//
//                if (posiFound) {
//
//                    string data = "CourseName: ";
//                    for (int i = 0; i < 5; i++) {
//                        data.append(students[index].getCourse(i));
//                        if (i != 4)
//                            data.push_back(' ');
//                    }
//                    data.push_back('\n');
//                    file.writeFile(data, f);
//
//                    data = "Attendence: ";
//                    for (int i = 0; i < 5; i++) {
//                        string atten = to_string(students[index].getAttendance(i));
//                        if (i != 4)
//                            atten.push_back(' ');
//                        data.append(atten);
//                    }
//                    data.push_back('\n');
//                    file.writeFile(data, f);
//
//
//                    data = "Marks: ";
//                    for (int i = 0; i < 5; i++) {
//                        string marks = to_string(students[index].getMark(i));
//                        if (i != 4)
//                            marks.push_back(' ');
//                        data.append(marks);
//                    }
//                    // data.push_back('\n');
//                    file.writeFile(data, f);
//                }
//            }
//            else {
//                cout << "Student does not have this course " << endl;
//            }
//        }
//        //system("cls");
//    }
//    cin.ignore();
//   /* int i = 0;
//    while (i < students.size()) {
//        cout << students[i] << endl;
//        i++;
//    }*/
//}
//void System::editMarks()
//{
//    // Implement logic to withdraw a course for a student
//    while (true) {
//        int CourseInput;
//        cout << "Which course you want to withdraw : " << endl;
//        for (int i = 0; i < this->courses.size(); i++) {
//            cout << i + 1 << ": " << this->courses[i].getName() << endl;
//        }
//        cout << "6 : Exit" << endl;
//        cin >> CourseInput;
//        if (CourseInput == 6) {
//            break;
//        }
//        else if (CourseInput >= 1 && CourseInput < 6) {
//            string RollNo;
//            cout << "Enter the Roll No of the student whose marks is to updated : ";
//            cin >> RollNo;
//            if (courses[CourseInput - 1].StudentExist(RollNo)) {
//                int index = 0;
//                int marks = 0;
//                cout << "Enter the marks of the student : ";
//                cin >> marks;
//                for (; index < students.size(); index++) {
//                    if (students[index].getRoll() == RollNo) {
//                        RollNo = students[index].getRoll();
//                        students[index].setMark(CourseInput - 1, marks);
//                        break;
//                    }
//                }
//
//
//                FileHandler file("data.txt");
//                fstream f;
//                file.openFile(f);
//                string line = file.readFile(f);
//                bool posiFound = false;
//
//                while (!posiFound) {
//                    size_t found = line.find(RollNo);
//                    if (found != std::string::npos) {
//                        posiFound = true;
//                        break;
//                    }
//                    line = file.readFile(f);
//                }
//                // cout << line;
//                file.readFile(f);
//                f.seekp(f.tellg());
//
//                if (posiFound) {
//
//                    string data = "CourseName: ";
//                    for (int i = 0; i < 5; i++) {
//                        data.append(students[index].getCourse(i));
//                        if (i != 4)
//                            data.push_back(' ');
//                    }
//                    data.push_back('\n');
//                    file.writeFile(data, f);
//
//                    data = "Attendence: ";
//                    for (int i = 0; i < 5; i++) {
//                        string atten = to_string(students[index].getAttendance(i));
//                        if (i != 4)
//                            atten.push_back(' ');
//                        data.append(atten);
//                    }
//                    data.push_back('\n');
//                    file.writeFile(data, f);
//
//
//                    data = "Marks: ";
//                    for (int i = 0; i < 5; i++) {
//                        string marks = to_string(students[index].getMark(i));
//                        if (i != 4)
//                            marks.push_back(' ');
//                        data.append(marks);
//                    }
//                    // data.push_back('\n');
//                    file.writeFile(data, f);
//                }
//            }
//            else {
//                cout << "Student does not have this course " << endl;
//            }
//        }
//        //system("cls");
//    }
//    cin.ignore();
//    /* int i = 0;
//     while (i < students.size()) {
//         cout << students[i] << endl;
//         i++;
//     }*/
//}
//
//void System::saveData() {
//    FileHandler file("data.txt");
//    fstream f;
//    file.openFile(f);
//
//    string RollNumOfPrevStu = students[students.size() - 1].getRoll();
//    string line = file.readFile(f);
//    bool posiFound = false;
//
//    while (line != "&" || !posiFound) {
//        size_t found = line.find(RollNumOfPrevStu);
//        if (found != std::string::npos) {
//            posiFound = true;
//        }
//
//        line = file.readFile(f);
//    }
//
//
//    Student student;
//    while (line != "$") {
//        line = file.readFile(f);
//
//        string dataType = "";
//        int i = 0;
//        for (; i < line.size(); i++) {
//            if (line[i] == ':')
//                break;
//            dataType.push_back(line[i]);
//        }
//        if (dataType == "Name") {
//            i += 2;
//            string name = "";
//            for (; i < line.size(); i++) {
//                name.push_back(line[i]);
//            }
//            student.setName(name);
//        }
//        else if (dataType == "Roll number") {
//            i += 2;
//            string rollNo = "";
//            for (; i < line.size(); i++) {
//                rollNo.push_back(line[i]);
//            }
//            student.setRoll(rollNo);
//        }
//        else if (dataType == "Age") {
//            i += 2;
//            string AGE = "";
//            for (; i < line.size(); i++) {
//                AGE.push_back(line[i]);
//            }
//            int age = stoi(AGE);
//            student.setAge(age);
//        }
//        else if (dataType == "CourseName") {
//            i += 2;
//            // cout <<"" << line[i] << endl;
//            int index = 0;
//            string courseNAME = "";
//            for (; i < line.size(); i++) {
//                if (line[i] == ' ') {
//                    student.setCourse(index, courseNAME);
//                    for (int i = 0; i < courses.size(); i++) {
//                        if (courses[i].getName() == courseNAME) {
//                            courses[i].AddStudent(student.getRoll());
//                            break;
//                        }
//                    }
//                    index++;
//                    courseNAME.clear();
//                    continue;
//                }
//                courseNAME.push_back(line[i]);
//            }
//            student.setCourse(index, courseNAME);
//
//            for (int i = 0; i < courses.size(); i++) {
//                if (courses[i].getName() == courseNAME) {
//                    courses[i].AddStudent(student.getRoll());
//                    break;
//                }
//            }
//        }
//        else if (dataType == "Attendence") {
//            i += 2;
//            int index = 0;
//            int attendence;
//            string Attendence = "";
//            for (; i < line.size(); i++) {
//                if (line[i] == ' ') {
//                    attendence = stoi(Attendence);
//                    student.setAttendance(index, attendence);
//                    index++;
//                    Attendence.clear();
//                    continue;
//                }
//                Attendence.push_back(line[i]);
//            }
//            attendence = stoi(Attendence);
//            student.setAttendance(index, attendence);
//        }
//        else if (dataType == "Marks") {
//            i += 2;
//            int index = 0;
//            int marks;
//            string Marks = "";
//            for (; i < line.size(); i++) {
//                if (line[i] == ' ') {
//                    marks = stoi(Marks);
//                    student.setMark(index, marks);
//                    index++;
//                    Marks.clear();
//                    continue;
//                }
//                Marks.push_back(line[i]);
//            }
//            marks = stoi(Marks);
//            student.setMark(index, marks);
//        }
//    } while (line != "$");
//    this->students.push_back(student);
//
//}
//void System::saveDataFromFile() {
//    // Implement logic to save data to a file
//    FileHandler file("data.txt");
//    fstream fout;
//    file.openFile(fout);
//
//    string line = "";
//    int CourseCount = 0;
//    while (CourseCount < 5) {
//        Course course;
//        do {
//            line = file.readFile(fout);
//            string dataType = "";
//            int i = 0;
//            for (; i < line.size(); i++) {
//                if (line[i] == ':')
//                    break;
//                dataType.push_back(line[i]);
//            }
//            if (dataType == "Code") {
//                i += 2;
//                string code = "";
//                for (; i < line.size(); i++) {
//                    code.push_back(line[i]);
//                }
//                course.setCode(code);
//            }
//            else if (dataType == "Name") {
//                i += 2;
//                string name = "";
//                for (; i < line.size(); i++) {
//                    name.push_back(line[i]);
//                }
//                course.setName(name);
//            }
//            else if (dataType == "Instructor") {
//                i += 2;
//                string Instructor = "";
//                for (; i < line.size(); i++) {
//                    Instructor.push_back(line[i]);
//                }
//                course.setInstructor(Instructor);
//            }
//            else if (dataType == "Credits") {
//                i += 2;
//                string CredHts = "";
//                for (; i < line.size(); i++) {
//                    CredHts.push_back(line[i]);
//                }
//                int credHrs = stoi(CredHts);
//                course.setCredits(credHrs);
//            }
//
//        } while (line != "$");
//        CourseCount++;
//        this->courses.push_back(course);
//    }
//    line.clear();
//    Student student;
//    int studentCount = 0;
//
//    while (studentCount < 2) {
//        do {
//
//            line = file.readFile(fout);
//
//            string dataType = "";
//            int i = 0;
//            for (; i < line.size(); i++) {
//
//                if (line[i] == ':')
//                    break;
//                dataType.push_back(line[i]);
//            }
//            if (dataType == "Name") {
//                i += 2;
//                string name = "";
//                for (; i < line.size(); i++) {
//                    name.push_back(line[i]);
//                }
//                student.setName(name);
//            }
//            else if (dataType == "Roll number") {
//                i += 2;
//                string rollNo = "";
//                for (; i < line.size(); i++) {
//                    rollNo.push_back(line[i]);
//                }
//                student.setRoll(rollNo);
//            }
//            else if (dataType == "Age") {
//                i += 2;
//                string AGE = "";
//                for (; i < line.size(); i++) {
//                    AGE.push_back(line[i]);
//                }
//                int age = stoi(AGE);
//                student.setAge(age);
//            }
//            else if (dataType == "CourseName") {
//                i += 2;
//                int index = 0;
//                string courseNAME = "";
//                for (; i < line.size(); i++) {
//                    if (line[i] == ' ') {
//                        student.setCourse(index, courseNAME);
//                        for (int i = 0; i < courses.size(); i++) {
//                            if (courses[i].getName() == courseNAME) {
//                                courses[i].AddStudent(student.getRoll());
//                                break;
//                            }
//                        }
//                        index++;
//                        courseNAME.clear();
//                        continue;
//                    }
//                    courseNAME.push_back(line[i]);
//                }
//                student.setCourse(index, courseNAME);
//                for (int i = 0; i < courses.size(); i++) {
//                    if (courses[i].getName() == courseNAME) {
//                        courses[i].AddStudent(student.getRoll());
//                        break;
//                    }
//                }
//
//            }
//            else if (dataType == "Attendence") {
//                i += 2;
//                int index = 0;
//                int attendence;
//                string Attendence = "";
//                for (; i < line.size(); i++) {
//                    if (line[i] == ' ') {
//                        attendence = stoi(Attendence);
//                        student.setAttendance(index, attendence);
//                        index++;
//                        Attendence.clear();
//                        continue;
//                    }
//                    Attendence.push_back(line[i]);
//                }
//                attendence = stoi(Attendence);
//                student.setAttendance(index, attendence);
//            }
//            else if (dataType == "Marks") {
//                i += 2;
//                int index = 0;
//                int marks;
//                string Marks = "";
//                for (; i < line.size(); i++) {
//                    if (line[i] == ' ') {
//                        marks = stoi(Marks);
//                        student.setMark(index, marks);
//                        index++;
//                        Marks.clear();
//                        continue;
//                    }
//                    Marks.push_back(line[i]);
//                }
//                marks = stoi(Marks);
//                student.setMark(index, marks);
//            }
//        } while (line != "$");
//        this->students.push_back(student);
//        studentCount++;
//
//    }
//
//    /* int i = 0;
//     while (i < students.size()) {
//         cout << students[i] << endl;
//         i++;
//     }*/
//}

//#include<cstring>
//#include<fstream>
//#include"FileHandler.h"
using namespace std;
//#include "system.h" // Assuming System.h contains the System class declaration

void System::mainLoop()
{  //saving data from file
    saveDataFromFile();
    while (true) {

        displayMainMenu();
        int choice = getUserInput();
        system("cls");
        if (choice == 1)
        {
            submenu1();
            int choice1 = getUserInput();
            cin.ignore();
            //loop for submenu 1
            while (choice1 > 0 && choice1 < 7)
            {  //display already enrolled students
                if (choice1 == 1)
                {

                    for (int i = 0; i < students.size(); i++) {
                        cout << students[i] << endl;
                    }

                    break;
                }
                else if (choice1 == 2)
                { //add a astudent
                    enrollStudent();
                    saveData();
                    break;
                }
                else if (choice1 == 3)
                {
                    //remove a student
                    break;
                }
                else if (choice1 == 4)
                {
                    //edit student details
                    cout << "what you want to edit about student" << endl;
                    cout << "1_ Maks" << endl;
                    cout << "2_ Attnedance" << endl;
                    int choice2{ 0 };
                    cin >> choice2;
                    if (choice2 == 1)
                    {
                        editMarks();
                    }
                    break;
                }
                else if (choice1 == 5)
                {
                    //back
                    break;
                }
            }
        }
        else if (choice == 2)
        {
            submenu2();
            int choice1 = getUserInput();
            cin.ignore();
            //loop for submwnu2
            while (choice1 > 0 && choice1 < 4)
            {  //display already enrolled students
                if (choice1 == 1)
                {
                    //available courses
                    for (int i = 0; i < courses.size(); i++) {
                        cout << courses[i] << endl;
                    }
                    break;
                }
                else if (choice1 == 2)
                {
                    //register course
                    registerCourse();
                    break;
                }
                else if (choice1 == 3)
                {
                    //back
                    break;
                }

            }
        }
        else if (choice == 3)
        {
            submenu3();
            int choice1 = getUserInput();
            cin.ignore();
            //loop for submwnu3
            while (choice1 > 0 && choice1 < 4)
            {  //display attendance
                if (choice1 == 1)
                {
                    cout << "enter students's roll no" << endl;
                    string rollno;
                    cin >> rollno;
                    for (int i = 0; i < students.size(); i++) {
                        if (students[i].getRoll() == rollno) {
                            students[i].printAttendance();
                            break;
                        }
                    }
                    break;

                }
                else if (choice1 == 2)
                {
                    //mark attendance
                    editAttendence();
                    break;
                }
                else if (choice1 == 3)
                {
                    //back
                    break;
                }

            }
        }
        else if (choice == 4)
        {
            submenu4();
            int choice1 = getUserInput();
            cin.ignore();
            //loop for submwnu4
            while (choice1 > 0 && choice1 < 4)
            {  //display marks
                if (choice1 == 1)
                {
                    cout << "enter students's roll no" << endl;
                    string rollno;
                    cin >> rollno;
                    for (int i = 0; i < students.size(); i++) {
                        if (students[i].getRoll() == rollno) {
                            students[i].printMarks();
                            break;
                        }
                    }
                    break;

                }
                else if (choice1 == 2)
                {
                    //assign marks
                    editMarks();
                    break;
                }
                else if (choice1 == 3)
                {
                    //back
                    break;
                }

            }
        }
        else if (choice == 5)
        {
            submenu5();
            int choice1 = getUserInput();
            cin.ignore();
            //loop for submwnu5
            while (choice1 > 0 && choice1 < 4)
            {  //enrolled courses
                if (choice1 == 1)
                {
                    cout << "enter students's roll no" << endl;
                    string rollno;
                    cin >> rollno;
                    for (int i = 0; i < students.size(); i++) {
                        if (students[i].getRoll() == rollno) {
                            students[i].enrolledCourses();
                            break;
                        }
                    }
                    break;

                }
                else if (choice1 == 2)
                {
                    //drop course
                    withdrawCourse();
                    break;
                }
                else if (choice1 == 3)
                {
                    //back
                    break;
                }

            }
        }
    }
}
//submenu1
void System::submenu1() {
    // Display the main menu options
    std::cout << "Sub Menu # 01\n";
    std::cout << "1- Display Already Enrolled Students\n";
    std::cout << "2- Add a Student\n";
    std::cout << "3- Remove a Student\n";
    std::cout << "4- Edit Student Detail\n";
    std::cout << "5- back\n";

    std::cout << "Press 1 to 5 to select an option: ";

}
//submenu2
void System::submenu2() {
    // Display the main menu options
    std::cout << "Sub Menu # 02\n";
    std::cout << "1- Available Courses\n";
    std::cout << "2- Register Course\n";
    std::cout << "3- Back\n";

    std::cout << "Press 1 to 3 to select an option: ";

}
//submenu3
void System::submenu3() {
    // Display the main menu options
    std::cout << "sub Menu # 03\n";
    std::cout << "1- Display Attendance (subject wise)\n";
    std::cout << "2- Mark Attendance\n";
    std::cout << "3- Back\n";

    std::cout << "Press 1 to 3 to select an option: ";

}
//submenu4
void System::submenu4() {
    // Display the main menu options
    std::cout << "Sub Menu # 04\n";
    std::cout << "1- Display Marks (subject wise)\n";
    std::cout << "2- Assign Marks\n";
    std::cout << "3- Back\n";

    std::cout << "Press 1 to 3 to select an option: ";

}
//submenu5
void System::submenu5() {
    // Display the main menu options
    std::cout << "Sub Menu # 05\n";
    std::cout << "1- Enrolled Courses\n";
    std::cout << "2- Drop a Course\n";
    std::cout << "3- Back\n";

    std::cout << "Press 1 to 3 to select an option: ";

}

void System::displayMainMenu() {
    // Display the main menu options
    std::cout << "Main Menu\n";
    std::cout << "1- Enroll a student\n";
    std::cout << "2- Course Registration\n";
    std::cout << "3- Attendance\n";
    std::cout << "4- Marks\n";
    std::cout << "5- Course Withdraw\n";
    std::cout << "6- Exit\n";
    std::cout << "Press 1 to 6 to select an option: ";

}

// Other display menu methods can follow a similar structure

int System::getUserInput() {
    int choice;
    std::cin >> choice;
    return choice;
}

bool System::validateInput(int input, int range) {
    return (input >= 1 && input <= range);
}
//##########################################################################
void System::enrollStudent() {
    // Implement logic to enroll a student
    FileHandler file("data.txt");
    fstream f;
    file.openFile(f, true);


    string data = "\n";
    file.writeFile(data, f);
    string name;
    cout << "Enter the name of student : ";
    getline(cin, name);
    data = "Name: ";
    data.append(name);
    data.push_back('\n');
    file.writeFile(data, f);

    string rollNo;
    cout << "Enter the roll number : ";
    getline(cin, rollNo);
    data = "Roll number: ";
    data.append(rollNo);
    data.push_back('\n');
    file.writeFile(data, f);

    string age;
    cout << "Enter age of student : ";
    getline(cin, age);
    data = "Age: ";
    data.append(age);
    data.push_back('\n');
    file.writeFile(data, f);

    string* STUcourse = new string[5];
    int* STUatten = new int[5];
    int* STUmarks = new int[5];
    for (int i = 0; i < 5; i++) STUcourse[i] = "-";
    for (int i = 0; i < 5; i++) STUatten[i] = -1;
    for (int i = 0; i < 5; i++) STUmarks[i] = -1;

    data = "CourseName: ";
    for (int i = 0; i < 5; i++) {
        data.append(STUcourse[i]);
        if (i != 4)
            data.push_back(' ');
    }
    data.push_back('\n');
    file.writeFile(data, f);

    data = "Attendence: ";
    for (int i = 0; i < 5; i++) {
        string atten = to_string(STUatten[i]);
        if (i != 4)
            atten.push_back(' ');
        data.append(atten);
    }
    data.push_back('\n');
    file.writeFile(data, f);


    data = "Marks: ";
    for (int i = 0; i < 5; i++) {
        string marks = to_string(STUatten[i]);
        if (i != 4)
            marks.push_back(' ');
        data.append(marks);
    }
    data.push_back('\n');
    file.writeFile(data, f);
    data = "$\n";
    file.writeFile(data, f);
    data = "&";
    file.writeFile(data, f);
}

void System::registerCourse() {
    while (true) {
        int CourseInput;
        cout << "Which course you want to register : " << endl;
        for (int i = 0; i < this->courses.size(); i++) {
            cout << i + 1 << ": " << this->courses[i].getName() << endl;
        }
        cout << "6 : Exit" << endl;
        cin >> CourseInput;
        if (CourseInput == 6) {
            break;
        }
        else if (CourseInput >= 1 && CourseInput < 6) {
            string RollNo;
            cout << "Enter the Roll No of the student want to register course : ";
            cin >> RollNo;
            int index = 0;
            string courseNAME;
            for (; index < students.size(); index++) {
                if (students[index].getRoll() == RollNo) {
                    RollNo = students[index].getRoll();
                    students[index].setMark(CourseInput - 1, 0);
                    students[index].setAttendance(CourseInput - 1, 0);
                    students[index].setCourse(CourseInput - 1, this->courses[CourseInput - 1].getName());
                    courseNAME = this->courses[CourseInput - 1].getName();
                    break;
                }
            }
            for (int i = 0; i < courses.size(); i++) {
                if (courses[i].getName() == courseNAME) {
                    courses[i].AddStudent(RollNo);
                    break;
                }
            }
            FileHandler file("data.txt");
            fstream f;
            file.openFile(f);
            string line = file.readFile(f);
            bool posiFound = false;


            while (!posiFound) {
                size_t found = line.find(RollNo);
                if (found != std::string::npos) {
                    posiFound = true;
                    break;
                }

                line = file.readFile(f);
            }
            // cout << line;
            file.readFile(f);
            f.seekp(f.tellg());

            if (posiFound) {
                // cout << line;

                string data = "CourseName: ";
                for (int i = 0; i < 5; i++) {
                    data.append(students[index].getCourse(i));
                    if (i != 4)
                        data.push_back(' ');
                }
                data.push_back('\n');
                file.writeFile(data, f);

                data = "Attendence: ";
                for (int i = 0; i < 5; i++) {
                    string atten = to_string(students[index].getAttendance(i));
                    if (i != 4)
                        atten.push_back(' ');
                    data.append(atten);
                }
                data.push_back('\n');
                file.writeFile(data, f);


                data = "Marks: ";
                for (int i = 0; i < 5; i++) {
                    string marks = to_string(students[index].getMark(i));
                    if (i != 4)
                        marks.push_back(' ');
                    data.append(marks);
                }
                // data.push_back('\n');
                file.writeFile(data, f);
            }
        }

        //system("cls");
    }
    cin.ignore();
    int i = 0;
    while (i < students.size()) {
        cout << students[i] << endl;
        i++;
    }
}

void System::displayStudentAttendance() {
    // Implement logic to display student attendance
}

void System::displayStudentMarks() {
    // Implement logic to display student marks
}

void System::withdrawCourse() {
    // Implement logic to withdraw a course for a student
    while (true) {
        int CourseInput;
        cout << "Which course you want to withdraw : " << endl;
        for (int i = 0; i < this->courses.size(); i++) {
            cout << i + 1 << ": " << this->courses[i].getName() << endl;
        }
        cout << "6 : Exit" << endl;
        cin >> CourseInput;
        if (CourseInput == 6) {
            break;
        }
        else if (CourseInput >= 1 && CourseInput < 6) {
            string RollNo;
            cout << "Enter the Roll No of the student want to withdraw course : ";
            cin >> RollNo;
            string courseNAME;
            if (courses[CourseInput - 1].StudentExist(RollNo)) {
                int index = 0;
                for (; index < students.size(); index++) {
                    if (students[index].getRoll() == RollNo) {
                        RollNo = students[index].getRoll();
                        students[index].setMark(CourseInput - 1, -1);
                        students[index].setAttendance(CourseInput - 1, -1);
                        courseNAME = this->courses[CourseInput - 1].getName();
                        students[index].setCourse(CourseInput - 1, "-");
                        break;
                    }
                }

                for (int i = 0; i < courses.size(); i++) {
                    if (courses[i].getName() == courseNAME) {
                        courses[i].RemoveStudent(RollNo);
                        break;
                    }
                }

                FileHandler file("data.txt");
                fstream f;
                file.openFile(f);
                string line = file.readFile(f);
                bool posiFound = false;

                while (!posiFound) {
                    size_t found = line.find(RollNo);
                    if (found != std::string::npos) {
                        posiFound = true;
                        break;
                    }
                    line = file.readFile(f);
                }
                // cout << line;
                file.readFile(f);
                f.seekp(f.tellg());

                if (posiFound) {

                    string data = "CourseName: ";
                    for (int i = 0; i < 5; i++) {
                        data.append(students[index].getCourse(i));
                        if (i != 4)
                            data.push_back(' ');
                    }
                    data.push_back('\n');
                    file.writeFile(data, f);

                    data = "Attendence: ";
                    for (int i = 0; i < 5; i++) {
                        string atten = to_string(students[index].getAttendance(i));
                        if (i != 4)
                            atten.push_back(' ');
                        data.append(atten);
                    }
                    data.push_back('\n');
                    file.writeFile(data, f);


                    data = "Marks: ";
                    for (int i = 0; i < 5; i++) {
                        string marks = to_string(students[index].getMark(i));
                        if (i != 4)
                            marks.push_back(' ');
                        data.append(marks);
                    }
                    // data.push_back('\n');
                    file.writeFile(data, f);
                }
            }
            else {
                cout << "Student does not have this course " << endl;
            }
        }
        //system("cls");
    }
    cin.ignore();
    int i = 0;
    while (i < students.size()) {
        cout << students[i] << endl;
        i++;
    }
}

void System::editAttendence()
{
    // Implement logic to withdraw a course for a student
    while (true) {
        int CourseInput;
        cout << "Which course you want to withdraw : " << endl;
        for (int i = 0; i < this->courses.size(); i++) {
            cout << i + 1 << ": " << this->courses[i].getName() << endl;
        }
        cout << "6 : Exit" << endl;
        cin >> CourseInput;
        if (CourseInput == 6) {
            break;
        }
        else if (CourseInput >= 1 && CourseInput < 6) {
            string RollNo;
            cout << "Enter the Roll No of the student whose attendence is to updated : ";
            cin >> RollNo;
            if (courses[CourseInput - 1].StudentExist(RollNo)) {
                int index = 0;
                int attendence = 0;
                cout << "Enter the attendence of the student : ";
                cin >> attendence;
                for (; index < students.size(); index++) {
                    if (students[index].getRoll() == RollNo) {
                        RollNo = students[index].getRoll();
                        students[index].setAttendance(CourseInput - 1, attendence);
                        break;
                    }
                }


                FileHandler file("data.txt");
                fstream f;
                file.openFile(f);
                string line = file.readFile(f);
                bool posiFound = false;

                while (!posiFound) {
                    size_t found = line.find(RollNo);
                    if (found != std::string::npos) {
                        posiFound = true;
                        break;
                    }
                    line = file.readFile(f);
                }
                // cout << line;
                file.readFile(f);
                f.seekp(f.tellg());

                if (posiFound) {

                    string data = "CourseName: ";
                    for (int i = 0; i < 5; i++) {
                        data.append(students[index].getCourse(i));
                        if (i != 4)
                            data.push_back(' ');
                    }
                    data.push_back('\n');
                    file.writeFile(data, f);

                    data = "Attendence: ";
                    for (int i = 0; i < 5; i++) {
                        string atten = to_string(students[index].getAttendance(i));
                        if (i != 4)
                            atten.push_back(' ');
                        data.append(atten);
                    }
                    data.push_back('\n');
                    file.writeFile(data, f);


                    data = "Marks: ";
                    for (int i = 0; i < 5; i++) {
                        string marks = to_string(students[index].getMark(i));
                        if (i != 4)
                            marks.push_back(' ');
                        data.append(marks);
                    }
                    // data.push_back('\n');
                    file.writeFile(data, f);
                }
            }
            else {
                cout << "Student does not have this course " << endl;
            }
        }
        //system("cls");
    }
    cin.ignore();
    /* int i = 0;
     while (i < students.size()) {
         cout << students[i] << endl;
         i++;
     }*/
}
void System::editMarks()
{
    // Implement logic to withdraw a course for a student
    while (true) {
        int CourseInput;
        cout << "Which course you want to withdraw : " << endl;
        for (int i = 0; i < this->courses.size(); i++) {
            cout << i + 1 << ": " << this->courses[i].getName() << endl;
        }
        cout << "6 : Exit" << endl;
        cin >> CourseInput;
        if (CourseInput == 6) {
            break;
        }
        else if (CourseInput >= 1 && CourseInput < 6) {
            string RollNo;
            cout << "Enter the Roll No of the student whose marks is to updated : ";
            cin >> RollNo;
            if (courses[CourseInput - 1].StudentExist(RollNo)) {
                int index = 0;
                int marks = 0;
                cout << "Enter the marks of the student : ";
                cin >> marks;
                for (; index < students.size(); index++) {
                    if (students[index].getRoll() == RollNo) {
                        RollNo = students[index].getRoll();
                        students[index].setMark(CourseInput - 1, marks);
                        break;
                    }
                }


                FileHandler file("data.txt");
                fstream f;
                file.openFile(f);
                string line = file.readFile(f);
                bool posiFound = false;

                while (!posiFound) {
                    size_t found = line.find(RollNo);
                    if (found != std::string::npos) {
                        posiFound = true;
                        break;
                    }
                    line = file.readFile(f);
                }
                // cout << line;
                file.readFile(f);
                f.seekp(f.tellg());

                if (posiFound) {

                    string data = "CourseName: ";
                    for (int i = 0; i < 5; i++) {
                        data.append(students[index].getCourse(i));
                        if (i != 4)
                            data.push_back(' ');
                    }
                    data.push_back('\n');
                    file.writeFile(data, f);

                    data = "Attendence: ";
                    for (int i = 0; i < 5; i++) {
                        string atten = to_string(students[index].getAttendance(i));
                        if (i != 4)
                            atten.push_back(' ');
                        data.append(atten);
                    }
                    data.push_back('\n');
                    file.writeFile(data, f);


                    data = "Marks: ";
                    for (int i = 0; i < 5; i++) {
                        string marks = to_string(students[index].getMark(i));
                        if (i != 4)
                            marks.push_back(' ');
                        data.append(marks);
                    }
                    // data.push_back('\n');
                    file.writeFile(data, f);
                }
            }
            else {
                cout << "Student does not have this course " << endl;
            }
        }
        //system("cls");
    }
    cin.ignore();
    /* int i = 0;
     while (i < students.size()) {
         cout << students[i] << endl;
         i++;
     }*/
}

void System::saveData() {
    FileHandler file("data.txt");
    fstream f;
    file.openFile(f);

    string RollNumOfPrevStu = students[students.size() - 1].getRoll();
    string line = file.readFile(f);
    bool posiFound = false;

    while (line != "&" || !posiFound) {
        size_t found = line.find(RollNumOfPrevStu);
        if (found != std::string::npos) {
            posiFound = true;
        }

        line = file.readFile(f);
    }


    Student student;
    while (line != "$") {
        line = file.readFile(f);

        string dataType = "";
        int i = 0;
        for (; i < line.size(); i++) {
            if (line[i] == ':')
                break;
            dataType.push_back(line[i]);
        }
        if (dataType == "Name") {
            i += 2;
            string name = "";
            for (; i < line.size(); i++) {
                name.push_back(line[i]);
            }
            student.setName(name);
        }
        else if (dataType == "Roll number") {
            i += 2;
            string rollNo = "";
            for (; i < line.size(); i++) {
                rollNo.push_back(line[i]);
            }
            student.setRoll(rollNo);
        }
        else if (dataType == "Age") {
            i += 2;
            string AGE = "";
            for (; i < line.size(); i++) {
                AGE.push_back(line[i]);
            }
            int age = stoi(AGE);
            student.setAge(age);
        }
        else if (dataType == "CourseName") {
            i += 2;
            // cout <<"" << line[i] << endl;
            int index = 0;
            string courseNAME = "";
            for (; i < line.size(); i++) {
                if (line[i] == ' ') {
                    student.setCourse(index, courseNAME);
                    for (int i = 0; i < courses.size(); i++) {
                        if (courses[i].getName() == courseNAME) {
                            courses[i].AddStudent(student.getRoll());
                            break;
                        }
                    }
                    index++;
                    courseNAME.clear();
                    continue;
                }
                courseNAME.push_back(line[i]);
            }
            student.setCourse(index, courseNAME);

            for (int i = 0; i < courses.size(); i++) {
                if (courses[i].getName() == courseNAME) {
                    courses[i].AddStudent(student.getRoll());
                    break;
                }
            }
        }
        else if (dataType == "Attendence") {
            i += 2;
            int index = 0;
            int attendence;
            string Attendence = "";
            for (; i < line.size(); i++) {
                if (line[i] == ' ') {
                    attendence = stoi(Attendence);
                    student.setAttendance(index, attendence);
                    index++;
                    Attendence.clear();
                    continue;
                }
                Attendence.push_back(line[i]);
            }
            attendence = stoi(Attendence);
            student.setAttendance(index, attendence);
        }
        else if (dataType == "Marks") {
            i += 2;
            int index = 0;
            int marks;
            string Marks = "";
            for (; i < line.size(); i++) {
                if (line[i] == ' ') {
                    marks = stoi(Marks);
                    student.setMark(index, marks);
                    index++;
                    Marks.clear();
                    continue;
                }
                Marks.push_back(line[i]);
            }
            marks = stoi(Marks);
            student.setMark(index, marks);
        }
    } while (line != "$");
    this->students.push_back(student);

}
void System::saveDataFromFile() {
    // Implement logic to save data to a file
    FileHandler file("data.txt");
    fstream fout;
    file.openFile(fout);

    string line = "";
    int CourseCount = 0;
    while (CourseCount < 5) {
        Course course;
        do {
            line = file.readFile(fout);
            string dataType = "";
            int i = 0;
            for (; i < line.size(); i++) {
                if (line[i] == ':')
                    break;
                dataType.push_back(line[i]);
            }
            if (dataType == "Code") {
                i += 2;
                string code = "";
                for (; i < line.size(); i++) {
                    code.push_back(line[i]);
                }
                course.setCode(code);
            }
            else if (dataType == "Name") {
                i += 2;
                string name = "";
                for (; i < line.size(); i++) {
                    name.push_back(line[i]);
                }
                course.setName(name);
            }
            else if (dataType == "Instructor") {
                i += 2;
                string Instructor = "";
                for (; i < line.size(); i++) {
                    Instructor.push_back(line[i]);
                }
                course.setInstructor(Instructor);
            }
            else if (dataType == "Credits") {
                i += 2;
                string CredHts = "";
                for (; i < line.size(); i++) {
                    CredHts.push_back(line[i]);
                }
                int credHrs = stoi(CredHts);
                course.setCredits(credHrs);
            }

        } while (line != "$");
        CourseCount++;
        this->courses.push_back(course);
    }
    line.clear();
    Student student;
    int studentCount = 0;

    while (studentCount < 2) {
        do {

            line = file.readFile(fout);

            string dataType = "";
            int i = 0;
            for (; i < line.size(); i++) {

                if (line[i] == ':')
                    break;
                dataType.push_back(line[i]);
            }
            if (dataType == "Name") {
                i += 2;
                string name = "";
                for (; i < line.size(); i++) {
                    name.push_back(line[i]);
                }
                student.setName(name);
            }
            else if (dataType == "Roll number") {
                i += 2;
                string rollNo = "";
                for (; i < line.size(); i++) {
                    rollNo.push_back(line[i]);
                }
                student.setRoll(rollNo);
            }
            else if (dataType == "Age") {
                i += 2;
                string AGE = "";
                for (; i < line.size(); i++) {
                    AGE.push_back(line[i]);
                }
                int age = stoi(AGE);
                student.setAge(age);
            }
            else if (dataType == "CourseName") {
                i += 2;
                int index = 0;
                string courseNAME = "";
                for (; i < line.size(); i++) {
                    if (line[i] == ' ') {
                        student.setCourse(index, courseNAME);
                        for (int i = 0; i < courses.size(); i++) {
                            if (courses[i].getName() == courseNAME) {
                                courses[i].AddStudent(student.getRoll());
                                break;
                            }
                        }
                        index++;
                        courseNAME.clear();
                        continue;
                    }
                    courseNAME.push_back(line[i]);
                }
                student.setCourse(index, courseNAME);
                for (int i = 0; i < courses.size(); i++) {
                    if (courses[i].getName() == courseNAME) {
                        courses[i].AddStudent(student.getRoll());
                        break;
                    }
                }

            }
            else if (dataType == "Attendence") {
                i += 2;
                int index = 0;
                int attendence;
                string Attendence = "";
                for (; i < line.size(); i++) {
                    if (line[i] == ' ') {
                        attendence = stoi(Attendence);
                        student.setAttendance(index, attendence);
                        index++;
                        Attendence.clear();
                        continue;
                    }
                    Attendence.push_back(line[i]);
                }
                attendence = stoi(Attendence);
                student.setAttendance(index, attendence);
            }
            else if (dataType == "Marks") {
                i += 2;
                int index = 0;
                int marks;
                string Marks = "";
                for (; i < line.size(); i++) {
                    if (line[i] == ' ') {
                        marks = stoi(Marks);
                        student.setMark(index, marks);
                        index++;
                        Marks.clear();
                        continue;
                    }
                    Marks.push_back(line[i]);
                }
                marks = stoi(Marks);
                student.setMark(index, marks);
            }
        } while (line != "$");
        this->students.push_back(student);
        studentCount++;

    }

    /* int i = 0;
     while (i < students.size()) {
         cout << students[i] << endl;
         i++;
     }*/
}
//*****************************************************************
//void System::enrollStudent() {
//    // Implement logic to enroll a student
//    FileHandler file("data.txt");
//    fstream f;
//    file.openFile(f, true);
//
//
//    string data = "\n";
//    file.writeFile(data, f);
//    string name;
//    cout << "Enter the name of student : ";
//    getline(cin, name);
//    data = "Name: ";
//    data.append(name);
//    data.push_back('\n');
//    file.writeFile(data, f);
//
//    string rollNo;
//    cout << "Enter the roll number : ";
//    getline(cin, rollNo);
//    data = "Roll number: ";
//    data.append(rollNo);
//    data.push_back('\n');
//    file.writeFile(data, f);
//
//    string age;
//    cout << "Enter age of student : ";
//    getline(cin, age);
//    data = "Age: ";
//    data.append(age);
//    data.push_back('\n');
//    file.writeFile(data, f);
//
//    string* STUcourse = new string[5];
//    int* STUatten = new int[5];
//    int* STUmarks = new int[5];
//    for (int i = 0; i < 5; i++) STUcourse[i] = "-";
//    for (int i = 0; i < 5; i++) STUatten[i] = -1;
//    for (int i = 0; i < 5; i++) STUmarks[i] = -1;
//
//
//    data = "CourseName: ";
//    for (int i = 0; i < 5; i++) {
//        data.append(STUcourse[i]);
//        if (i != 4)
//            data.push_back(' ');
//    }
//    data.push_back('\n');
//    file.writeFile(data, f);
//
//    data = "Attendence: ";
//    for (int i = 0; i < 5; i++) {
//        string atten = to_string(STUatten[i]);
//        if (i != 4)
//            atten.push_back(' ');
//        data.append(atten);
//    }
//    data.push_back('\n');
//    file.writeFile(data, f);
//
//
//    data = "Marks: ";
//    for (int i = 0; i < 5; i++) {
//        string marks = to_string(STUatten[i]);
//        if (i != 4)
//            marks.push_back(' ');
//        data.append(marks);
//    }
//    data.push_back('\n');
//    file.writeFile(data, f);
//    data = "$\n";
//    file.writeFile(data, f);
//    data = "&";
//    file.writeFile(data, f);
//}
////course register
//void System::registerCourse() {
//
//
//    while (true) {
//        int CourseInput;
//        cout << "Which course you want to register : " << endl;
//        for (int i = 0; i < this->courses.size(); i++) {
//            cout << i + 1 << ": " << this->courses[i].getName() << endl;
//        }
//        cout << "6 : Exit" << endl;
//        cin >> CourseInput;
//        if (CourseInput == 6) {
//            break;
//        }
//        else if (CourseInput >= 1 && CourseInput < 6) {
//            string RollNo;
//            cout << "Enter the Roll No of the student want to register course : ";
//            cin >> RollNo;
//            int index = 0;
//            for (; index < students.size(); index++) {
//                if (students[index].getRoll() == RollNo) {
//                    RollNo = students[index].getRoll();
//                    students[index].setMark(CourseInput - 1, 0);
//                    students[index].setAttendance(CourseInput - 1, 0);
//                    students[index].setCourse(CourseInput - 1, this->courses[CourseInput - 1].getName());
//                    break;
//                }
//            }
//
//
//            FileHandler file("data.txt");
//            fstream f;
//            file.openFile(f);
//            string line = file.readFile(f);
//            bool posiFound = false;
//
//
//            while (!posiFound) {
//                size_t found = line.find(RollNo);
//                if (found != std::string::npos) {
//                    posiFound = true;
//                    break;
//                }
//
//                line = file.readFile(f);
//            }
//            // cout << line;
//            file.readFile(f);
//            f.seekp(f.tellg());
//
//            if (posiFound) {
//                // cout << line;
//
//                string data = "CourseName: ";
//                for (int i = 0; i < 5; i++) {
//                    data.append(students[index].getCourse(i));
//                    if (i != 4)
//                        data.push_back(' ');
//                }
//                data.push_back('\n');
//                file.writeFile(data, f);
//
//                data = "Attendence: ";
//                for (int i = 0; i < 5; i++) {
//                    string atten = to_string(students[index].getAttendance(i));
//                    if (i != 4)
//                        atten.push_back(' ');
//                    data.append(atten);
//                }
//                data.push_back('\n');
//                file.writeFile(data, f);
//
//
//                data = "Marks: ";
//                for (int i = 0; i < 5; i++) {
//                    string marks = to_string(students[index].getMark(i));
//                    if (i != 4)
//                        marks.push_back(' ');
//                    data.append(marks);
//                }
//                // data.push_back('\n');
//                file.writeFile(data, f);
//            }
//        }
//
//        //system("cls");
//    }
//    cin.ignore();
//    int i = 0;
//    while (i < students.size()) {
//        cout << students[i] << endl;
//        i++;
//    }
//}
//void System::editAttendence()
//{
//    // Implement logic to withdraw a course for a student
//    while (true) {
//        int CourseInput;
//        cout << "Which course you want to withdraw : " << endl;
//        for (int i = 0; i < this->courses.size(); i++) {
//            cout << i + 1 << ": " << this->courses[i].getName() << endl;
//        }
//        cout << "6 : Exit" << endl;
//        cin >> CourseInput;
//        if (CourseInput == 6) {
//            break;
//        }
//        else if (CourseInput >= 1 && CourseInput < 6) {
//            string RollNo;
//            cout << "Enter the Roll No of the student whose attendence is to updated : ";
//            cin >> RollNo;
//            if (courses[CourseInput - 1].StudentExist(RollNo)) {
//                int index = 0;
//                int attendence = 0;
//                cout << "Enter the attendence of the student : ";
//                cin >> attendence;
//                for (; index < students.size(); index++) {
//                    if (students[index].getRoll() == RollNo) {
//                        RollNo = students[index].getRoll();
//
//                        //giving new value of attendance
//                        students[index].setAttendance(CourseInput - 1, attendence);
//                        break;
//                    }
//                }
//
//
//                FileHandler file("data.txt");
//                fstream f;
//                file.openFile(f);
//                string line = file.readFile(f);
//                bool posiFound = false;
//
//                while (!posiFound) {
//                    size_t found = line.find(RollNo);
//                    if (found != std::string::npos) {
//                        posiFound = true;
//                        break;
//                    }
//                    line = file.readFile(f);
//                }
//                // cout << line;
//                file.readFile(f);
//                f.seekp(f.tellg());
//
//                if (posiFound) {
//
//                    string data = "CourseName: ";
//                    for (int i = 0; i < 5; i++) {
//                        data.append(students[index].getCourse(i));
//                        if (i != 4)
//                            data.push_back(' ');
//                    }
//                    data.push_back('\n');
//                    file.writeFile(data, f);
//
//                    data = "Attendence: ";
//                    for (int i = 0; i < 5; i++) {
//                        string atten = to_string(students[index].getAttendance(i));
//                        if (i != 4)
//                            atten.push_back(' ');
//                        data.append(atten);
//                    }
//                    data.push_back('\n');
//                    file.writeFile(data, f);
//
//
//                    data = "Marks: ";
//                    for (int i = 0; i < 5; i++) {
//                        string marks = to_string(students[index].getMark(i));
//                        if (i != 4)
//                            marks.push_back(' ');
//                        data.append(marks);
//                    }
//                    // data.push_back('\n');
//                    file.writeFile(data, f);
//                }
//            }
//            else {
//                cout << "Student does not have this course " << endl;
//            }
//        }
//        //system("cls");
//    }
//    cin.ignore();
//    /* int i = 0;
//     while (i < students.size()) {
//         cout << students[i] << endl;
//         i++;
//     }*/
//}
//void System::editMarks()
//{
//    // Implement logic to withdraw a course for a student
//    while (true) {
//        int CourseInput;
//        cout << "Which course marks you want to edit" << endl;
//        for (int i = 0; i < this->courses.size(); i++) {
//            cout << i + 1 << ": " << this->courses[i].getName() << endl;
//        }
//        cout << "6 : Exit" << endl;
//        cin >> CourseInput;
//        if (CourseInput == 6) {
//            break;
//        }
//        else if (CourseInput >= 1 && CourseInput < 6) {
//            string RollNo;
//            cout << "Enter the Roll No of the student whose marks is to updated : ";
//            cin >> RollNo;
//            if (courses[CourseInput - 1].StudentExist(RollNo)) {
//                int index = 0;
//                int marks = 0;
//                cout << "Enter the marks of the student : ";
//                cin >> marks;
//                for (; index < students.size(); index++) {
//                    if (students[index].getRoll() == RollNo) 
//                         {
//                        RollNo = students[index].getRoll();
//                        //giving new value of marks
//                        students[index].setMark(CourseInput - 1, marks);
//                        break;
//                    }
//                }
//
//
//                FileHandler file("data.txt");
//                fstream f;
//                file.openFile(f);
//                string line = file.readFile(f);
//                bool posiFound = false;
//                //position where we are going to edit data
//                while (!posiFound) {
//                    size_t found = line.find(RollNo);
//                    if (found != std::string::npos) {
//                        posiFound = true;
//                        break;
//                    }
//
//                   
//                    line = file.readFile(f);
//                }
//                // cout << line;
//                //for ignoring age line
//                file.readFile(f);
//                f.seekp(f.tellg());
//
//                if (posiFound) {
//                    //writing in data string
//                    string data = "CourseName: ";
//                    for (int i = 0; i < 5; i++) {
//                        data.append(students[index].getCourse(i));
//                        if (i != 4)
//                            data.push_back(' ');
//                    }
//                    data.push_back('\n');
//                    //moving data string to file
//                    file.writeFile(data, f);
//                    //taking input in ateen
//                    data = "Attendence: ";
//                    for (int i = 0; i < 5; i++) {
//                        string atten = to_string(students[index].getAttendance(i));
//                        if (i != 4)
//                            atten.push_back(' ');
//                        //movig atten to data
//                        data.append(atten);
//                    }
//                    data.push_back('\n');
//                    //moving data to file
//                    file.writeFile(data, f);
//
//
//                    data = "Marks: ";
//                    for (int i = 0; i < 5; i++) {
//                        string marks = to_string(students[index].getMark(i));
//                        if (i != 4)
//                            marks.push_back(' ');
//                        data.append(marks);
//                    }
//                    // data.push_back('\n');
//                    file.writeFile(data, f);
//                }
//            }
//            else {
//                cout << "Student does not have this course " << endl;
//            }
//        }
//        //system("cls");
//    }
//    cin.ignore();
//    /* int i = 0;
//     while (i < students.size()) {
//         cout << students[i] << endl;
//         i++;
//     }*/
//}
//
//
////course withdraw
//void System::withdrawCourse() {
//    // Implement logic to withdraw a course for a student
//
//
//
//    while (true) {
//        int CourseInput;
//        cout << "Which course you want to withdraw : " << endl;
//        for (int i = 0; i < this->courses.size(); i++) {
//            cout << i + 1 << ": " << this->courses[i].getName() << endl;
//        }
//        cout << "6 : Exit" << endl;
//        cin >> CourseInput;
//        if (CourseInput == 6) {
//            break;
//        }
//        else if (CourseInput >= 1 && CourseInput < 6) {
//            string RollNo;
//            cout << "Enter the Roll No of the student want to withdraw course : ";
//            cin >> RollNo;
//            if (courses[CourseInput - 1].StudentExist(RollNo)) {
//                int index = 0;
//                for (; index < students.size(); index++) {
//                    if (students[index].getRoll() == RollNo) {
//                        RollNo = students[index].getRoll();
//                        students[index].setMark(CourseInput - 1, -1);
//                        students[index].setAttendance(CourseInput - 1, -1);
//                        students[index].setCourse(CourseInput - 1, "-");
//                        break;
//                    }
//                }
//
//
//                FileHandler file("data.txt");
//                fstream f;
//                file.openFile(f);
//                string line = file.readFile(f);
//                bool posiFound = false;
//
//                while (!posiFound) {
//                    size_t found = line.find(RollNo);
//                    if (found != std::string::npos) {
//                        posiFound = true;
//                        break;
//                    }
//                    line = file.readFile(f);
//                }
//                // cout << line;
//                file.readFile(f);
//                f.seekp(f.tellg());
//
//                if (posiFound) {
//
//                    string data = "CourseName: ";
//                    for (int i = 0; i < 5; i++) {
//                        data.append(students[index].getCourse(i));
//                        if (i != 4)
//                            data.push_back(' ');
//                    }
//                    data.push_back('\n');
//                    file.writeFile(data, f);
//
//                    data = "Attendence: ";
//                    for (int i = 0; i < 5; i++) {
//                        string atten = to_string(students[index].getAttendance(i));
//                        if (i != 4)
//                            atten.push_back(' ');
//                        data.append(atten);
//                    }
//                    data.push_back('\n');
//                    file.writeFile(data, f);
//
//
//                    data = "Marks: ";
//                    for (int i = 0; i < 5; i++) {
//                        string marks = to_string(students[index].getMark(i));
//                        if (i != 4)
//                            marks.push_back(' ');
//                        data.append(marks);
//                    }
//                    // data.push_back('\n');
//                    file.writeFile(data, f);
//                }
//            }
//            else {
//                cout << "Student does not have this course " << endl;
//            }
//        }
//        //system("cls");
//    }
//    cin.ignore();
//    int i = 0;
//    while (i < students.size()) {
//        cout << students[i] << endl;
//        i++;
//    }
//}
////saving data from file to student vector
//void System::saveData() {
//    FileHandler file("data.txt");
//    fstream f;
//    file.openFile(f);
//
//    string RollNumOfPrevStu = students[students.size() - 1].getRoll();
//    string line = file.readFile(f);
//    bool posiFound = false;
//
//    while (line != "&" || !posiFound) {
//        size_t found = line.find(RollNumOfPrevStu);
//        if (found != std::string::npos) {
//            posiFound = true;
//        }
//
//        line = file.readFile(f);
//    }
//
//
//    Student student;
//    while (line != "$") {
//        line = file.readFile(f);
//
//        string dataType = "";
//        int i = 0;
//        for (; i < line.size(); i++) {
//            if (line[i] == ':')
//                break;
//            dataType.push_back(line[i]);
//        }
//        if (dataType == "Name") {
//            i += 2;
//            string name = "";
//            for (; i < line.size(); i++) {
//                name.push_back(line[i]);
//            }
//            student.setName(name);
//        }
//        else if (dataType == "Roll number") {
//            i += 2;
//            string rollNo = "";
//            for (; i < line.size(); i++) {
//                rollNo.push_back(line[i]);
//            }
//            student.setRoll(rollNo);
//        }
//        else if (dataType == "Age") {
//            i += 2;
//            string AGE = "";
//            for (; i < line.size(); i++) {
//                AGE.push_back(line[i]);
//            }
//            int age = stoi(AGE);
//            student.setAge(age);
//        }
//        else if (dataType == "CourseName") {
//            i += 2;
//            // cout <<"" << line[i] << endl;
//            int index = 0;
//            string courseNAME = "";
//            for (; i < line.size(); i++) {
//                if (line[i] == ' ') {
//                    student.setCourse(index, courseNAME);
//                    for (int i = 0; i < courses.size(); i++) {
//                        if (courses[i].getName() == courseNAME) {
//                            courses[i].AddStudent(student.getRoll());
//                            break;
//                        }
//                    }
//                    index++;
//                    courseNAME.clear();
//                    continue;
//                }
//                courseNAME.push_back(line[i]);
//            }
//            student.setCourse(index, courseNAME);
//
//            for (int i = 0; i < courses.size(); i++) {
//                if (courses[i].getName() == courseNAME) {
//                    courses[i].AddStudent(student.getRoll());
//                    break;
//                }
//            }
//        }
//        else if (dataType == "Attendence") {
//            i += 2;
//            int index = 0;
//            int attendence;
//            string Attendence = "";
//            for (; i < line.size(); i++) {
//                if (line[i] == ' ') {
//                    attendence = stoi(Attendence);
//                    student.setAttendance(index, attendence);
//                    index++;
//                    Attendence.clear();
//                    continue;
//                }
//                Attendence.push_back(line[i]);
//            }
//            attendence = stoi(Attendence);
//            student.setAttendance(index, attendence);
//        }
//        else if (dataType == "Marks") {
//            i += 2;
//            int index = 0;
//            int marks;
//            string Marks = "";
//            for (; i < line.size(); i++) {
//                if (line[i] == ' ') {
//                    marks = stoi(Marks);
//                    student.setMark(index, marks);
//                    index++;
//                    Marks.clear();
//                    continue;
//                }
//                Marks.push_back(line[i]);
//            }
//            marks = stoi(Marks);
//            student.setMark(index, marks);
//        }
//    } while (line != "$");
//    this->students.push_back(student);
//
//}
//void System::saveDataFromFile() {
//    // Implement logic to save data to a file
//    FileHandler file("data.txt");
//    fstream fout;
//    file.openFile(fout);
//
//    string line = "";
//    int CourseCount = 0;
//    while (CourseCount < 5) {
//        Course course;
//        do {
//            line = file.readFile(fout);
//            string dataType = "";
//            int i = 0;
//            for (; i < line.size(); i++) {
//                if (line[i] == ':')
//                    break;
//                dataType.push_back(line[i]);
//            }
//            if (dataType == "Code") {
//                i += 2;
//                string code = "";
//                for (; i < line.size(); i++) {
//                    code.push_back(line[i]);
//                }
//                course.setCode(code);
//            }
//            else if (dataType == "Name") {
//                i += 2;
//                string name = "";
//                for (; i < line.size(); i++) {
//                    name.push_back(line[i]);
//                }
//                course.setName(name);
//            }
//            else if (dataType == "Instructor") {
//                i += 2;
//                string Instructor = "";
//                for (; i < line.size(); i++) {
//                    Instructor.push_back(line[i]);
//                }
//                course.setInstructor(Instructor);
//            }
//            else if (dataType == "Credits") {
//                i += 2;
//                string CredHts = "";
//                for (; i < line.size(); i++) {
//                    CredHts.push_back(line[i]);
//                }
//                int credHrs = stoi(CredHts);
//                course.setCredits(credHrs);
//            }
//
//        } while (line != "$");
//        CourseCount++;
//        this->courses.push_back(course);
//    }
//    line.clear();
//    Student student;
//    int studentCount = 0;
//    //saving already enrolled student's data
//    while (studentCount < 2) {
//        do {
//
//            line = file.readFile(fout);
//
//            string dataType = "";
//            int i = 0;
//            for (; i < line.size(); i++) {
//
//                if (line[i] == ':')
//                    break;
//                dataType.push_back(line[i]);
//            }
//            if (dataType == "Name") {
//                i += 2;
//                string name = "";
//                for (; i < line.size(); i++) {
//                    name.push_back(line[i]);
//                }
//                student.setName(name);
//            }
//            else if (dataType == "Roll number") {
//                i += 2;
//                string rollNo = "";
//                for (; i < line.size(); i++) {
//                    rollNo.push_back(line[i]);
//                }
//                student.setRoll(rollNo);
//            }
//            else if (dataType == "Age") {
//                i += 2;
//                string AGE = "";
//                for (; i < line.size(); i++) {
//                    AGE.push_back(line[i]);
//                }
//                int age = stoi(AGE);
//                student.setAge(age);
//            }
//            else if (dataType == "CourseName") {
//                i += 2;
//                int index = 0;
//                string courseNAME = "";
//                for (; i < line.size(); i++) {
//                    if (line[i] == ' ') {
//                        student.setCourse(index, courseNAME);
//                        for (int i = 0; i < courses.size(); i++) {
//                            if (courses[i].getName() == courseNAME) {
//                                courses[i].AddStudent(student.getRoll());
//                                break;
//                            }
//                        }
//                        index++;
//                        courseNAME.clear();
//                        continue;
//                    }
//                    courseNAME.push_back(line[i]);
//                }
//                student.setCourse(index, courseNAME);
//                for (int i = 0; i < courses.size(); i++) {
//                    if (courses[i].getName() == courseNAME) {
//                        courses[i].AddStudent(student.getRoll());
//                        break;
//                    }
//                }
//
//            }
//            else if (dataType == "Attendence") {
//                i += 2;
//                int index = 0;
//                int attendence;
//                string Attendence = "";
//                for (; i < line.size(); i++) {
//                    if (line[i] == ' ') {
//                        attendence = stoi(Attendence);
//                        student.setAttendance(index, attendence);
//                        index++;
//                        Attendence.clear();
//                        continue;
//                    }
//                    Attendence.push_back(line[i]);
//                }
//                attendence = stoi(Attendence);
//                student.setAttendance(index, attendence);
//            }
//            else if (dataType == "Marks") {
//                i += 2;
//                int index = 0;
//                int marks;
//                string Marks = "";
//                for (; i < line.size(); i++) {
//                    if (line[i] == ' ') {
//                        marks = stoi(Marks);
//                        student.setMark(index, marks);
//                        index++;
//                        Marks.clear();
//                        continue;
//                    }
//                    Marks.push_back(line[i]);
//                }
//                marks = stoi(Marks);
//                student.setMark(index, marks);
//            }
//        } while (line != "$");
//        this->students.push_back(student);
//        studentCount++;
//
//    }
//
//    /* int i = 0;
//     while (i < students.size()) {
//         cout << students[i] << endl;
//         i++;
//     }*/
//}
//
////*****************************************************************
//