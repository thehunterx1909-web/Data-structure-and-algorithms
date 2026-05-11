//Longest Increase subsequence
/*Cho mảng A có n phần tử, tìm mảng con tăng dần dài nhất
(không cần liên tiếp)*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve(int *a, int n){
    int ans = 1;
    int dp[n];
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(a[i] > a[j]){
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(dp[i], ans);
            }
        }
    }
    return ans;
}
int main(){
    int n; cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << solve(a, n);
}