/*Hãy xem xét một hệ thống tiền tệ của ngân hàng XYZ bao gồm n đồng xu.
Mỗi đồng xu có một giá trị nguyên dương.Nhiệm vụ của bạn là tính số cách riêng biệt 
mà bạn có thể tạo ra số tiền x bằng cách sử dụng số xu có sẵn.
Ví dụ: nếu số xu là {2, 3, 5} và tổng mong muốn là 9, có 8 cách:
2 + 2 + 5; 2 + 5 + 2; 5 + 2 + 2; 3 + 3 + 3; 
2 + 2 + 2 + 3; 2 + 2 + 3 + 2; 2 + 3 + 2 + 2; 3 + 2 + 2 + 2.*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cnt[1000001];
int const MOD = 1e9 + 7;

int solve(vector<int> a, int S){
    cnt[0] = 1; 
    for(int i = 1; i <= S; i++){
        cnt[i] = 0;
        for(int c : a){
            if(i >= c){
                cnt[i] = (cnt[i] + cnt[i - c]) % MOD;
            }
        }
    }
    return cnt[S];
}
int main(){
    int n; cin >> n;
    int S; cin >> S;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    cout << solve(a, S);
}