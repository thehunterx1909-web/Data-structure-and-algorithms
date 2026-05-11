/*Cho n pt a1-an, tìm trung vị*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve(int *a, int n){
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;

    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            q1.push(a[i]);
        }else{
            q2.push(a[i]);
        }
        if(i > 1 && q1.top() > q2.top()){
            q1.push(q2.top());
            q2.push(q1.top());
            q1.pop();
            q2.pop();
        }
    }
    return q1.top();
}
int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << solve(a, n);
}