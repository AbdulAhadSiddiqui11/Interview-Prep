#include <bits/stdc++.h>
using namespace std;

int findceleb_n2(vector<vector<int>> connections) {
    int n = connections.size();
    vector<int> indegree(n,0), outdegree(n,0);
    for(int i=0; i<connections.size(); ++i) {
        for(int j=0; j<connections[i].size(); ++j) {
            if(connections[i][j] == 1) {
                outdegree[i]++;
                indegree[j]++; 
            }
        }
    }
    for(int i=0; i<n; ++i) {
        if(indegree[i] == n-1 && outdegree[n] == 0) {
            return i;
        }
    }
    return -1;
}

int find_celeb_stack(vector<vector<int>> connections) {
    stack<int> celebs;
    for(int i=0; i<connections.size(); ++i){
        celebs.push(i);
    }
    while(celebs.size() > 1) {
        int a = celebs.top(); celebs.pop();
        int b = celebs.top(); celebs.pop();
        if(connections[a][b] == 1) // if a knows b then a cannot be celeb.
        {
            celebs.push(b);
        } else {
            celebs.push(a);
        }
    }
    if(celebs.empty()) return -1; //no potential celebs -> empty stack since a knows b and b knows a 
    int celeb = celebs.top(); celebs.pop();
    for(int i=0; i<connections.size(); ++i){
        if(i!=celeb && (connections[celeb][i] == 1 || connections[i][celeb] == 0)) return -1;
    }

    return celeb;
}

int find_celeb_two_pointers(vector<vector<int>> connections) {
    int n = connections.size();
    int i=0, j=n-1;
    while(i<j){
        if(connections[i][j]==1) ++i; // if i knows j then i cannot be the celeb;
        else --j;
    }
    int celeb = j;
    for(int i=0; i<n; ++i){
        if(i!=celeb && (connections[celeb][i] == 1 || connections[i][celeb] == 0)) return -1;
    }
    return celeb;
}
int main() {
    vector<vector<int>> connections =   {{0, 0, 1, 0},
                                        {0, 0, 1, 0}, 
                                        {0, 0, 0, 0}, 
                                        {0, 0, 1, 0}};
    cout<<"Celeb is " << findceleb_n2(connections) <<endl;
    cout<<"Celeb <stack> is " << find_celeb_stack(connections) <<endl;
    cout<<"Celeb <two pointers> is " << find_celeb_two_pointers(connections) <<endl;

    return 0;
}