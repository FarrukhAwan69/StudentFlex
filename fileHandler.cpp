#include "FileHandler.hpp"

FileHandler::FileHandler(const string& filename)
{
	this->filename = filename;
	this->data = "";
}

bool FileHandler::openFile(std::fstream& f) {
    if (f.is_open()) {
        std::cout << "File is already open." << std::endl;
        return false;
    }

    f.open(filename);
    return f.is_open();
}

bool FileHandler::openFile(std::fstream& f, bool ForAppend) {
    if (f.is_open()) {
        std::cout << "File is already open." << std::endl;
        return false;
    }

    if (ForAppend)
        f.open(filename, std::ios::app);
    else
        f.open(filename);

    return f.is_open();
}


void FileHandler::closeFile(fstream& f)
{
    if (f.is_open()) {
        f.close();
        //cout << "File closed successfully." << std::endl;
    }
    else {
        cout << "File is not open." << std::endl;
    }
}

string FileHandler::readFile(fstream& f)
{
    if (f.is_open()) {
        getline(f, data);
        return data;
    }
    else {
        cout << "File is not opened." << endl;
        string data = "nothing";
        return data;
    }
}

void FileHandler::writeFile(const string& newData, fstream& f)
{
    if (f.is_open()) {
        data = newData;
        f << data;
        cout << "Data is successfully written to file: " << endl;
    }
    else {
        std::cout << "File is not opened." << endl;
    }
}
