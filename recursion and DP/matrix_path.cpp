// https://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/

#include <bits/stdc++.h>
using namespace std;

int matrix_paths_rec(int r, int c) {
    if(r==1 || c==1) return 1;
    return matrix_paths_rec(r-1,c)+matrix_paths_rec(r,c-1);
}

int matrix_paths_dp(int r, int c) {
    vector<vector<int>> dp(r, vector<int>(c));
    for(int i=0; i<r; ++i) {
        dp[i][0] = 1;
    }
    for(int j=0; j<c; ++j) {
        dp[0][j] = 1;
    }
    for(int i=1; i<r; ++i){
        for(int j=1; j<c; ++j) {
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[r-1][c-1];
}

/*

Another Approach:(Using combinatorics) 
In this approach We have to calculate m+n-2 C n-1 
here which will be (m+n-2)! / (n-1)! (m-1)! 

*/
int main(){
    int r = 4;
    int c = 4;
    cout<<matrix_paths_rec(r,c)<<endl;
    cout<<matrix_paths_dp(r,c)<<endl;
    return 0;
}