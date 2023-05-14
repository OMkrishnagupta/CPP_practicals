#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    string className;
    int year;
    double totalMarks;

    Student() {}

    Student(int r, string n, string c, int y, double m) {
        rollNo = r;
        name = n;
        className = c;
        year = y;
        totalMarks = m;
    }
};

int main() {
    Student students[5] = {
        Student(1, "John Doe", "Class 10", 2023, 95.5),
        Student(2, "Jane Doe", "Class 11", 2022, 92.0),
        Student(3, "Bob Smith", "Class 12", 2021, 88.5),
        Student(4, "Alice Johnson", "Class 9", 2024, 90.0),
        Student(5, "Tom Brown", "Class 8", 2025, 85.0)
    };

    ofstream file("students.txt");
    if (file.is_open()) {
        for (int i = 0; i < 5; i++) {
            file << students[i].rollNo << "," << students[i].name << "," << students[i].className << "," << students[i].year << "," << students[i].totalMarks << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
        return -1;
    }

    ifstream readFile("students.txt");
    if (readFile.is_open()) {
        string line;
        while (getline(readFile, line)) {
            int rollNo = stoi(line.substr(0, line.find(",")));
            line.erase(0, line.find(",") + 1);

            string name = line.substr(0, line.find(","));
            line.erase(0, line.find(",") + 1);

            string className = line.substr(0, line.find(","));
            line.erase(0, line.find(",") + 1);

            int year = stoi(line.substr(0, line.find(",")));
            line.erase(0, line.find(",") + 1);

            double totalMarks = stod(line.substr(0));

            cout << rollNo << "," << name << "," << className << "," << year << "," << totalMarks << endl;
        }
        readFile.close();
    } else {
        cout << "Unable to open file" << endl;
        return -1;
    }

    return 0;
}
