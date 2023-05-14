#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    map<char, int> freq;
    for (int i = 1; i < argc; i++)
    {
        string s(argv[i]);
        for (auto c : s)
            freq[c]++;
    }
    for (auto p : freq)
        cout << p.first << " " << p.second << endl;
    return 0;
}
