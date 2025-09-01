#include<iostream>
#include<string>
using namespace std;
int main() {
    string str = "Hello, World!";
    cout << "Original string: " << str << endl;

    // Accessing characters
    cout << "First character: " << str[0] << endl;
    cout << "Last character: " << str[str.size() - 1] << endl;

    // Modifying characters
    str[7] = 'C';
    cout << "Modified string: " << str << endl;

    // Substring
    string sub = str.substr(0, 5);
    cout << "Substring (0,5): " << sub << endl;

    // Concatenation
    string str2 = " How are you?";
    string combined = str + str2;
    cout << "Concatenated string: " << combined << endl;

    // Finding a substring
    size_t pos = combined.find("World");
    if (pos != string::npos) {
        cout << "'World' found at position: " << pos << endl;
    } else {
        cout << "'World' not found" << endl;
    }

    // Erasing a part of the string
    combined.erase(5, 7); // Remove ", World"
    cout << "After erasing: " << combined << endl;

    return 0;
}