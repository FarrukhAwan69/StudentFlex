#pragma once
#include <iostream>
#include<string>
#include <fstream>
using namespace std;

class FileHandler {
private:
   string filename;
  // string mode;
   string data;
   ifstream fin;
   ofstream fout;

public:
    FileHandler(const string& filename);
    bool openFile(fstream& f);
    bool openFile(fstream& f, bool ForAppend);
    void closeFile(fstream& f);
    string readFile(fstream& f);
    void writeFile(const string& newData, fstream& f);
};