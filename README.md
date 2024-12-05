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
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>

using namespace std;

class FiniteAutomaton {
public:
    set<int> states;                             // States
    set<char> alphabet;                          // Input alphabet
    map<pair<int, char>, int> transitions;       // Transition function
    int startState;                              // Start state
    set<int> acceptStates;                       // Accept states

    // Constructor
    FiniteAutomaton(set<int> st, set<char> alpha, map<pair<int, char>, int> trans, int start, set<int> accept)
        : states(st), alphabet(alpha), transitions(trans), startState(start), acceptStates(accept) {}

    // Function to check if the automaton accepts a string
    bool accepts(const string& input) {
        int currentState = startState;
        for (char c : input) {
            if (transitions.find({currentState, c}) != transitions.end()) {
                currentState = transitions[{currentState, c}];
            } else {
                return false; // No valid transition
            }
        }
        return acceptStates.find(currentState) != acceptStates.end();
    }
};

// Function to simulate the union of two FAs
bool simulateUnion(FiniteAutomaton& fa1, FiniteAutomaton& fa2, const string& input) {
    return fa1.accepts(input) || fa2.accepts(input);
}

// Function to simulate the intersection of two FAs
bool simulateIntersection(FiniteAutomaton& fa1, FiniteAutomaton& fa2, const string& input) {
    return fa1.accepts(input) && fa2.accepts(input);
}

// Function to simulate the concatenation of two FAs
bool simulateConcatenation(FiniteAutomaton& fa1, FiniteAutomaton& fa2, const string& input) {
    for (size_t i = 0; i <= input.length(); ++i) {
        string part1 = input.substr(0, i);  // First part of the string
        string part2 = input.substr(i);    // Remaining part of the string
        if (fa1.accepts(part1) && fa2.accepts(part2)) {
            return true;
        }
    }
    return false;
}

int main() {
    // Define FA for L1
    set<int> states1 = {0, 1};
    set<char> alphabet1 = {'a', 'b'};
    map<pair<int, char>, int> transitions1 = {{{0, 'a'}, 1}, {{1, 'a'}, 1}, {{1, 'b'}, 1}};
    int startState1 = 0;
    set<int> acceptStates1 = {1};
    FiniteAutomaton fa1(states1, alphabet1, transitions1, startState1, acceptStates1);

    // Define FA for L2
    set<int> states2 = {0, 1};
    set<char> alphabet2 = {'a', 'b'};
    map<pair<int, char>, int> transitions2 = {{{0, 'b'}, 1}, {{1, 'b'}, 1}, {{1, 'a'}, 1}};
    int startState2 = 0;
    set<int> acceptStates2 = {1};
    FiniteAutomaton fa2(states2, alphabet2, transitions2, startState2, acceptStates2);

    // Take input from the user
    int n;
    cout << "Enter the number of strings to test: ";
    cin >> n;

    vector<string> testStrings(n);
    cout << "Enter the strings:\n";
    for (int i = 0; i < n; ++i) {
        cin >> testStrings[i];
    }

    // Perform union, intersection, and concatenation simulations
    cout << "\nUnion Simulation:\n";
    for (const string& s : testStrings) {
        cout << "String: " << s << " => " << (simulateUnion(fa1, fa2, s) ? "Accepted" : "Rejected") << endl;
    }

    cout << "\nIntersection Simulation:\n";
    for (const string& s : testStrings) {
        cout << "String: " << s << " => " << (simulateIntersection(fa1, fa2, s) ? "Accepted" : "Rejected") << endl;
    }

    cout << "\nConcatenation Simulation:\n";
    for (const string& s : testStrings) {
        cout << "String: " << s << " => " << (simulateConcatenation(fa1, fa2, s) ? "Accepted" : "Rejected") << endl;
    }

    return 0;
}
```

7. Design a PDA and write a program for simulating the machine which accepts the language 
{anbn  where n>0, S= {a, b}}.

```
#include <iostream>
#include <stack>
#include <vector> // Include vector header
#include <string>

using namespace std;

// Function to simulate the PDA
bool simulatePDA(const string& input) {
    stack<char> pdaStack;
    int state = 0; // Start state

    for (char c : input) {
        switch (state) {
        case 0: // Initial state, process 'a'
            if (c == 'a') {
                pdaStack.push('a'); // Push 'a' to the stack
                state = 1;          // Stay in state 1
            } else {
                return false; // Invalid input: String must start with 'a'
            }
            break;

        case 1: // Process 'a's
            if (c == 'a') {
                pdaStack.push('a'); // Push 'a' to the stack
            } else if (c == 'b') {
                if (!pdaStack.empty() && pdaStack.top() == 'a') {
                    pdaStack.pop(); // Pop 'a' for 'b'
                    state = 2;      // Move to state 2
                } else {
                    return false; // Stack empty or mismatch
                }
            } else {
                return false; // Invalid input
            }
            break;

        case 2: // Process 'b's
            if (c == 'b') {
                if (!pdaStack.empty() && pdaStack.top() == 'a') {
                    pdaStack.pop(); // Pop 'a' for 'b'
                } else {
                    return false; // Stack empty or mismatch
                }
            } else {
                return false; // Invalid input
            }
            break;

        default:
            return false; // Invalid state
        }
    }

    // Accept if stack is empty and input is fully processed
    return (state == 2 && pdaStack.empty());
}

int main() {
    int n;
    cout << "Enter the number of strings to test: ";
    cin >> n;

    vector<string> testStrings(n); // Declare vector to hold test strings
    cout << "Enter the strings:\n";
    for (int i = 0; i < n; ++i) {
        cin >> testStrings[i];
    }

    cout << "\nResults:\n";
    for (const string& s : testStrings) {
        cout << "String: " << s << " => " << (simulatePDA(s) ? "Accepted" : "Rejected") << endl;
    }

    return 0;
}
```


8. Design a PDA and write a program for simulating the machine which accepts the language {wXwr| w 
is any string over S={a, b} and wr is reverse of that string and X is a special symbol }.


```
#include <iostream>
#include <stack>
#include <vector> // Include the vector header
#include <string>

using namespace std;

// Function to simulate the PDA
bool simulatePDA(const string& input) {
    stack<char> pdaStack;
    int state = 0; // Start state

    for (char c : input) {
        switch (state) {
        case 0: // Read w and push onto the stack
            if (c == 'a' || c == 'b') {
                pdaStack.push(c);
            } else if (c == 'X') {
                state = 1; // Transition to state q1 after seeing X
            } else {
                return false; // Invalid input
            }
            break;

        case 1: // Read w^R and compare with stack
            if (c == 'a' || c == 'b') {
                if (!pdaStack.empty() && pdaStack.top() == c) {
                    pdaStack.pop(); // Match top of stack with input
                } else {
                    return false; // Mismatch or empty stack
                }
            } else {
                return false; // Invalid input
            }
            break;

        default:
            return false; // Invalid state
        }
    }

    // Accept if stack is empty and in the correct state
    return (state == 1 && pdaStack.empty());
}

int main() {
    int n;
    cout << "Enter the number of strings to test: ";
    cin >> n;

    vector<string> testStrings(n); // Declare vector to hold test strings
    cout << "Enter the strings:\n";
    for (int i = 0; i < n; ++i) {
        cin >> testStrings[i];
    }

    cout << "\nResults:\n";
    for (const string& s : testStrings) {
        cout << "String: " << s << " => " << (simulatePDA(s) ? "Accepted" : "Rejected") << endl;
    }

    return 0;
}
```


9. Design and simulate a Turing Machine that accepts the language anbncn where n >0.


```
#include <iostream>
#include <string>
#include <vector> // Include the vector header

using namespace std;

// Function to simulate the Turing Machine
bool simulateTM(string input) {
    int n = input.size();
    int head = 0; // Tape head starts at the first character
    int state = 0; // Start state

    while (state != 4) { // Continue until halt state
        switch (state) {
        case 0: // Find and mark the first 'a'
            if (head < n && input[head] == 'a') {
                input[head] = 'X'; // Mark 'a' as 'X'
                head++; // Move right
                state = 1; // Go to find 'b'
            } else if (head < n && input[head] != 'X') {
                return false; // Invalid input (unbalanced string)
            } else {
                state = 4; // Halt if all characters are marked
            }
            break;

        case 1: // Find and mark the first 'b'
            if (head < n && input[head] == 'b') {
                input[head] = 'Y'; // Mark 'b' as 'Y'
                head++; // Move right
                state = 2; // Go to find 'c'
            } else if (head < n && input[head] != 'Y') {
                head++; // Skip marked or invalid characters
            } else {
                return false; // Invalid input (unbalanced string)
            }
            break;

        case 2: // Find and mark the first 'c'
            if (head < n && input[head] == 'c') {
                input[head] = 'Z'; // Mark 'c' as 'Z'
                head--; // Move left to find the next 'a'
                state = 3; // Go back to find 'a'
            } else if (head < n && input[head] != 'Z') {
                head++; // Skip marked or invalid characters
            } else {
                return false; // Invalid input (unbalanced string)
            }
            break;

        case 3: // Return to the left to find the next 'a'
            if (head >= 0 && input[head] == 'X') {
                head++; // Move right to the next unmarked 'a'
                state = 0; // Restart the process
            } else if (head >= 0) {
                head--; // Keep moving left
            } else {
                state = 4; // Halt if all characters are processed
            }
            break;
        }
    }

    // Check if all characters are marked
    for (char c : input) {
        if (c != 'X' && c != 'Y' && c != 'Z') {
            return false;
        }
    }
    return true; // Input is valid
}

int main() {
    int n;
    cout << "Enter the number of strings to test: ";
    cin >> n;

    vector<string> testStrings(n); // Declare vector for storing test strings
    cout << "Enter the strings:\n";
    for (int i = 0; i < n; ++i) {
        cin >> testStrings[i];
    }

    cout << "\nResults:\n";
    for (const string& s : testStrings) {
        cout << "String: " << s << " => " << (simulateTM(s) ? "Accepted" : "Rejected") << endl;
    }

    return 0;
}
```




10. Design and simulate a Turing Machine which will increment the given binary number by 1.


```
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to simulate the Turing Machine for incrementing binary number
string incrementBinary(string input) {
    int head = input.length() - 1; // Start at the rightmost digit
    int state = 0; // Start state

    // Simulate the Turing machine
    while (state != 4) { // The machine halts at state 4
        switch (state) {
        case 0: // Start state
            if (input[head] == '0') {
                input[head] = '1'; // If it's '0', change to '1'
                state = 1; // Halt after incrementing
            } else if (input[head] == '1') {
                input[head] = '0'; // If it's '1', change to '0'
                head--; // Carry the 1 to the left
                state = 2; // Move to the next state to carry
            } else {
                state = 4; // Halt if no valid digit
            }
            break;
            
        case 2: // Carry state: Look for the next '0' or continue carrying left
            if (input[head] == '0') {
                input[head] = '1'; // Change '0' to '1'
                state = 1; // Halt after incrementing
            } else if (input[head] == '1') {
                input[head] = '0'; // Carry the '1'
                head--; // Move left
            } else {
                state = 4; // Halt if no valid digit
            }
            break;

        case 3: // If we reach the leftmost bit and need to add a new '1'
            if (head == -1) { // If we have no more digits to carry
                input = "1" + input; // Add a new '1' to the left
                state = 4; // Halt
            }
            break;
            
        default:
            state = 4; // Halt state
            break;
        }
    }

    return input; // Return the incremented binary number
}

int main() {
    int n;
    cout << "Enter the number of binary numbers to test: ";
    cin >> n;

    vector<string> testNumbers(n);
    cout << "Enter the binary numbers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> testNumbers[i];
    }

    cout << "\nIncremented Results:\n";
    for (const string& s : testNumbers) {
        cout << "Original: " << s << " => Incremented: " << incrementBinary(s) << endl;
    }

    return 0;
}
```
