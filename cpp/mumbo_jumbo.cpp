#include <iostream>
#include <cmath>
#include <ctime>
#include <string>

using namespace std;

int main() {
    printf("Hello world!\n");
    string input;
    //cin >> input;
    //cout << "from 1st" << input <<endl;
    getline(cin,input);
    cout << input << endl;
    cout << input.length() << endl;
    string one = "Abdul Ahad ";
    string two = "Siddiqui";
    cout << one + two << endl;
    return 0;
}