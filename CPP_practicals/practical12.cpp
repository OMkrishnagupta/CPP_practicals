#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (inputFile.is_open() && outputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            for (int i = 0; i < line.length(); i++) {
                if (line[i] != ' ') {
                    outputFile << line[i];
                }
            }
            outputFile << endl;
        }
        inputFile.close();
        outputFile.close();
    } else {
        cout << "Unable to open file" << endl;
        return -1;
    }

    return 0;
}
