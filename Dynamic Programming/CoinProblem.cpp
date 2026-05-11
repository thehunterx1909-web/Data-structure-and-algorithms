/*Ngân hàng X có n tờ tiền mệnh giá khác nhau
lưu trong mảng C[]. Đổi tiền là S sao cho 
số tờ tiền cần dùng là ít nhất.Được sử dụng một mệnh giá không giới hạn
vd: S = 10, C = {4, 5 , 8} -> ans = 2
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dp[1000001];

int solve(vector<int> a, int S){
    dp[0] = 0;
    for(int i = 1; i <= S; i++){
        dp[i] = 1e9;
        for(int c : a){
            if(i >= c){
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    return dp[S];
}
int main(){
    int n; cin >> n;
    int S; cin >> S;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    int ans = solve(a, S);
    if(ans == 1e9){
        cout << -1;
    }else cout << ans;

}