#include <iostream>
#include <cstring>

using namespace std;

void showAddress(char *str)
{
    cout << "Address of each character in string:" << endl;
    for (int i = 0; str[i] != '\0'; i++)
        cout << "&" << str[i] << " = " << (void *)&str[i] << endl;
}

void concatenate(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for (int i = 0; i < len2; i++)
        str1[len1 + i] = str2[i];
    str1[len1 + len2] = '\0';
    cout << "Concatenated string: " << str1 << endl;
}

void compare(char *str1, char *str2)
{
    int res = strcmp(str1, str2);
    if (res == 0)
        cout << "Strings are equal" << endl;
    else if (res > 0)
        cout << "String 1 is greater than String 2" << endl;
    else
        cout << "String 2 is greater than String 1" << endl;
}

void length(char *str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
        len++;
    cout << "Length of the string: " << len << endl;
}

void toUpper(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    cout << "String in uppercase: " << str << endl;
}

void reverse(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
        swap(str[i], str[len - i - 1]);
    cout << "Reversed string: " << str << endl;
}

void insert(char *str1, char *str2, int pos)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for (int i = len1 - 1; i >= pos - 1; i--)
        str1[i + len2] = str1[i];
    for (int i = pos - 1; i < pos + len2 - 1; i++)
        str1[i] = str2[i - pos + 1];
    cout << "String after insertion: " << str1 << endl;
}

int main()
{
    char str[100], str1[100], str2[100];
    int choice, pos;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Show address of each character in string\n";
        cout << "2. Concatenate two strings\n";
        cout << "3. Compare two strings\n";
        cout << "4. Calculate length of the string\n";
        cout << "5. Convert all lowercase characters to uppercase\n";
        cout << "6. Reverse the string\n";
        cout << "7. Insert a string in another string at a user specified position\n";
        cout << "8. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\nEnter a string: ";
                cin >> str;
                showAddress(str);
                break;

            case 2:
                cout << "\nEnter first string: ";
                cin >> str1;
                cout << "\nEnter second string: ";
                cin >> str2;
                concatenate(str1, str2);
                break;

            case 3:
                cout << "\nEnter first string: ";
                cin >> str1;
                cout << "\nEnter second string: ";
                cin >> str2;
                compare(str1, str2);
                break;

            case 4:
                cout << "\nEnter a string: ";
                cin >> str;
                length(str);
                break;

            case 5:
                cout << "\nEnter a string: ";
                cin >> str;
                toUpper(str);
                break;

            case 6:
                cout << "\nEnter a string: ";
                cin