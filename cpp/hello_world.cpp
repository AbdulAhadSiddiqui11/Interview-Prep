#include <iostream>
#include <string>
using namespace std;

int print(string message);

int main() {
    print("Hello World!");
    return 0;
}

int print(string message) {
    cout<<message<<endl;
    return 0;
}