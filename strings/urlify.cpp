/*
Write a method to replace all the spaces in a string with ‘%20’. 
You may assume that the string has sufficient space at the end to hold the additional characters 
and that you are given the “true” length of the string.

Input: "Mr John Smith", 13
Output: Mr%20John%20Smith

Input: "Mr John Smith   ", 13
Output: Mr%20John%20Smith

*/
#include <bits/stdc++.h>
using namespace std;

void urlify(char plain_text[], int true_len) {
    int spaces = 0;
    for(int i=0; i<true_len; ++i) {
        if(plain_text[i] == ' ') ++spaces;
    }

    int index = true_len + spaces * 2;
    plain_text[index] = '\0';
    for(int i=true_len-1; i>=0; --i) {
        //cout<<"index " << index-1 <<" i "<< i <<endl;
        if(plain_text[i] == ' ') { 
            plain_text[index-1] = '0';
            plain_text[index-2] = '2';
            plain_text[index-3] = '%';
            index -= 3;
        } else {
            plain_text[index - 1] = plain_text[i];
            --index;
        }
    }

}

int main() {
    char plain_text[] = {'h','e','l','l','o',' ','w','o','r','l','d',' ','\0',' ',' ',' ',' '};
    cout<<plain_text<<endl;
    urlify(plain_text,12);
    cout<<plain_text<<endl;
}