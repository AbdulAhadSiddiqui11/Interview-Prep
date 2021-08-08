// https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/

#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k) {
    if(n==1) return 0;
    return (josephus(n-1,k)+k)%n;
    /*
    if indexing start with 1 then
    if(n==1) return 1;
    return (josephus(n-1,k)+k-1)%n+1;
    */
}

int main() {
    cout<<josephus(5,3)<<endl;
    return 0;
}