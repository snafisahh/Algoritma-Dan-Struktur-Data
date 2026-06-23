#include <iostream>
#include <string>
#include <cctype>   
#include "stack.h"
using namespace std;

int main() {
    int n;
    cin >> n;

    Stack s;
    init(&s);

    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;

        if (isdigit(x[0]) || (x[0] == '-' && x.length() > 1)) {
            push(&s, stoi(x));
        } 
        else {
            int b = peek(&s);
            pop(&s);
            int a = peek(&s);
            pop(&s);

            int hasil = 0; 
            if (x == "+") hasil = a + b;
            else if (x == "-") hasil = a - b;
            else if (x == "*") hasil = a * b;
            else if (x == "/") hasil = a / b;

            push(&s, hasil);
        }
    }

    cout << peek(&s) << endl;  
    return 0;
}