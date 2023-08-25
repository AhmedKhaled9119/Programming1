#include <iostream>;


// C++ program to print hollow diamond pattern
#include <iostream>
using namespace std;
 
int main()
{
 
    int n = 5, rows = 1, columns;
 
    // while loop is used to identify the number of rows and
    // it is used to print upper triangle
    while (rows <= n) {
        columns = n;
 
        // used for printing the spaces
        while (columns > rows) {
            cout << " ";
            columns--;
        }
        // print star
        cout << "*";
        columns = 1;
        while (columns < (rows - 1) * 2) {
            cout << " ";
            columns++;
        }
        if (rows == 1) {
            cout << "\n";
        }
        else {
            cout << "*\n";
        }
        rows++;
    }
    // while loop is used to identify the number of rows and
    // it is used to print lower triangle
    rows = n - 1;
    while (rows >= 1) {
        columns = n;
        // used for printing the spaces
        while (columns > rows) {
            cout << " ";
            columns--;
        }
        // print star
        cout << "*";
        columns = 1;
        while (columns < (rows - 1) * 2) {
            cout << " ";
            columns++;
        }
        if (rows == 1) {
            cout << "\n";
        }
        else {
            cout << "*\n";
        }
        rows--;
    }
    return 0;
}