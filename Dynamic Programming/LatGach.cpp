/*Cho n viên gạch cỡ 1x2 lát sân
Sân có kích thước 2xn, Tìm số cách lát sân
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    ll n;
    cin >> n;
    ll C[n + 5] = {0, 1, 2};
    for(int i = 3; i <= n; i++){
        C[i] = C[i - 1] + C[i - 2];
    }
    cout << C[n];    
}