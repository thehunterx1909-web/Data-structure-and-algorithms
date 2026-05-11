/* Một người có cái túi có thể tích V(V < 1000). Anh ta có N đồ vật có thể tích là
A[i] (A[i] < 100) và giá trị là C[i] (C[i] < 100). Hãy xác định tổng giá trị
lớn nhất của các đồ vật mà người đó có thể mang theo sao cho
tổng thể tích không vượt quá V
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[1005][1005];

int solve(int n, int v, int *w, int *c){
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= v; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= w[i]){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + c[i]);
            }
        }
    }
    return dp[n][v];
}

int main(){
    int n, v; cin >> n >> v;
    int w[n + 1], c[n + 1];
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) cin >> c[i];
    cout << solve(n, v, w, c) << endl; 
}