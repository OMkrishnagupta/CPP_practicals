1. Design a Finite Automata (FA) that accepts all strings over S={0, 1} having three consecutive 1's as 
a substring. Write a program to simulate this FA.

```
#include<iostream>
#include<string>
using namespace std;
void q0(string w , int i);
void q1(string w , int i);
void q2(string w , int i);
void q3(string w , int i);
int main()
{
	string w;
	cout << "enter the string (1/0) : ";
	cin >> w;
	q0(w, 0);
	return 0;
}
void q0(string w , int i)
{
	if (i == w.length())
		cout << "String rejected";
	if (w[i] == '0')
		q0(w, i + 1);
	else if (w[i] == '1')
		q1 (w, i + 1);
}
void q1(string w , int i)
{
	if (i == w.length())
		cout << "String rejected";
	if (w[i] == '0')
		q0(w, i + 1);
	else if (w[i] == '1')
		q2 (w, i + 1);
}
void q2(string w , int i)
{
	if (i == w.length())
		cout << "String rejected";
	if (w[i] == '0')
		q0(w, i + 1);
	else if (w[i] == '1')
		q3 (w, i + 1);
}
void q3(string w , int i)
{
	if (i == w.length())
		cout << "String accepted :)";
	else 
		q3 (w, i + 1);
}
```

2. Design a Finite Automata (FA) that accepts all strings over S={0, 1} having either exactly two 1's or 
exactly three 1's, not more nor less. Write a program to simulate this FA.
```
#include<iostream>
#include<string.h>
using namespace std;

void q0(string w , int i);
void q1(string w , int i);
void q2(string w , int i);
void q3(string w , int i);
void q4(string w , int i);
int main()
{
	string w;
	cout<<"Enter the string(1,0) : ";
	cin>>w;
	q0(w, 0);
	return 0;
}
void q0(string w , int i)
{
	if (i == w.length())
		cout << "String Rejected";
	if (w[i] == '0')
		q0(w, i+1);
	else if (w[i] == '1')
		q1(w, i+1);	   	   
}
void q1(string w , int i)
{
	if (i == w.length())
		cout << "String Rejected";
	if (w[i] == '0')
		q1(w, i+1);
	else if (w[i] == '1')
		q2(w, i+1);	    
}
void q2(string w , int i)
{
	if (i == w.length())
		cout << "String Accepted";
	if (w[i] == '0')
		q2(w, i+1);
	else if (w[i] == '1')
		q3(w, i+1);	    
}
void q3(string w , int i)
{
	if (i == w.length())
		cout << "String Accepted";
	if (w[i] == '0')
		q3(w, i+1);
	else if (w[i] == '1')
		q4(w, i+1);	    
}
void q4(string w , int i)
{
	if (i == w.length())
		cout << "Dead State";
	if (w[i] == '0')
		q4(w, i+1);
	else if (w[i] == '1')
		q4(w, i+1);	    
}
```
3. Design a Finite Automata (FA) that accepts language L1, over S={a, b}, comprising of all strings (of 
length 4 or more) having first two characters same as the last two. Write a program to simulate this 
```
#include <iostream>
#include <string>
using namespace std;

// Function to simulate FA
bool isAccepted(const string& str) {
    // Ensure the length is at least 4
    if (str.length() < 4) {
        return false;
    }

    // Extract the first two and last two characters
    string firstTwo = str.substr(0, 2);
    string lastTwo = str.substr(str.length() - 2);

    // Check if first two match the last two
    return firstTwo == lastTwo;
}

int main() {
    string input;

    cout << "Enter a string over {a, b}: ";
    cin >> input;

    // Validate if input contains only 'a' and 'b'
    for (char ch : input) {
        if (ch != 'a' && ch != 'b') {
            cout << "Invalid input! String should only contain 'a' and 'b'." << endl;
            return 0;
        }
    }

    // Check if the input string is accepted by the FA
    if (isAccepted(input)) {
        cout << "The string is accepted by the FA." << endl;
    } else {
        cout << "The string is rejected by the FA." << endl;
    }

    return 0;
}
```

4. Design a Finite Automata (FA) that accepts language L2, over S= {a, b} where L2= a(a+b)*b. Write 
a program to simulate this FA.
```
#include <iostream>
#include <string>
using namespace std;

// Function to simulate the FA
bool isAccepted(const string& str) {
    int state = 0; // Initial state

    for (char ch : str) {
        switch (state) {
            case 0: // Initial state
                if (ch == 'a') {
                    state = 1; // Move to state 1
                } else {
                    return false; // Reject if the first character is not 'a'
                }
                break;

            case 1: // After reading 'a'
                if (ch == 'a' || ch == 'b') {
                    state = 1; // Stay in state 1 for (a+b)*
                } else if (ch == 'b') {
                    state = 2; // Move to state 2 when reading final 'b'
                }
                break;

            case 2: // Final state
                return false; // No transitions from final state
        }
    }

    // Check if in final state
    return (state == 2);
}

int main() {
    string input;

    cout << "Enter a string over {a, b}: ";
    cin >> input;

    // Validate if input contains only 'a' and 'b'
    for (char ch : input) {
        if (ch != 'a' && ch != 'b') {
            cout << "Invalid input! String should only contain 'a' and 'b'." << endl;
            return 0;
        }
    }

    // Check if the input string is accepted by the FA
    if (isAccepted(input)) {
        cout << "The string is accepted by the FA." << endl;
    } else {
        cout << "The string is rejected by the FA." << endl;
    }

    return 0;
}

```
5. Design a Finite Automata (FA) that accepts language EVEN-EVEN over S={a, b}. Write a program 
to simulate this FA
```
#include <iostream>
#include <string>
using namespace std;

// Function to simulate the FA
bool isAccepted(const string& str) {
    // Initial state: q00
    int state = 0;

    for (char ch : str) {
        switch (state) {
            case 0: // q00: both a and b even
                if (ch == 'a') {
                    state = 2; // Move to q10
                } else if (ch == 'b') {
                    state = 1; // Move to q01
                }
                break;

            case 1: // q01: a even, b odd
                if (ch == 'a') {
                    state = 3; // Move to q11
                } else if (ch == 'b') {
                    state = 0; // Move to q00
                }
                break;

            case 2: // q10: a odd, b even
                if (ch == 'a') {
                    state = 0; // Move to q00
                } else if (ch == 'b') {
                    state = 3; // Move to q11
                }
                break;

            case 3: // q11: a odd, b odd
                if (ch == 'a') {
                    state = 1; // Move to q01
                } else if (ch == 'b') {
                    state = 2; // Move to q10
                }
                break;

            default:
                return false; // Invalid state
        }
    }

    // Check if in accepting state q00
    return (state == 0);
}

int main() {
    string input;

    cout << "Enter a string over {a, b}: ";
    cin >> input;

    // Validate if input contains only 'a' and 'b'
    for (char ch : input) {
        if (ch != 'a' && ch != 'b') {
            cout << "Invalid input! String should only contain 'a' and 'b'." << endl;
            return 0;
        }
    }

    // Check if the input string is accepted by the FA
    if (isAccepted(input)) {
        cout << "The string is accepted by the FA." << endl;
    } else {
        cout << "The string is rejected by the FA." << endl;
    }

    return 0;
}
```

6. Write a program to simulate an FA that accepts  
a. Union of the languages L1 and L2 
b. Intersection of the languages L1 and L2 
c. Language L1 L2 (concatenation)
```
