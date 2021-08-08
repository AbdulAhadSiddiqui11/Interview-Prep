/*
Triple Step: A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3
steps at a time. Implement a method to count how many possible ways the child can run up the
stairs. 
*/
#include <bits/stdc++.h>
using namespace std;

int child_hop(int steps) {
    if(steps == 0 || steps == 1) return 1;
    else if(steps == 2) return 2;
    return child_hop(steps-1)+child_hop(steps-2)+child_hop(steps-3);
}

int child_hop_dp(int steps) {
    // bottom up
    vector<int> dp(steps+1,-1);
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=steps; ++i) {
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[steps];
}

int child_hop_memo(int steps, vector<int> &memo) {
    if(steps==0 || steps==1) {
        memo[steps] = 1;
        return memo[steps];
    } else if(steps==2) {
        memo[steps] = 2;
        return memo[steps];
    }
    if(memo[steps] == -1) {
        memo[steps] = child_hop_memo(steps-1, memo) + child_hop_memo(steps-2, memo) + child_hop_memo(steps-3, memo);
        return memo[steps];
    }
    return memo[steps];
}

int main() {
    int n = 5;
    cout<<child_hop(n)<<endl;
    cout<<child_hop_dp(n)<<endl;
    vector<int> steps(n,-1);
    cout<<child_hop_memo(n,steps)<<endl;
    return 0;
}