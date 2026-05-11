/*Ta biết rằng một số may mắn nếu biểu diễn
thập phân của nó chỉ chứa các chữ số may mắn là 4 và 7.
Ví dụ 47, 744, 4 là số may mắn, 5,17,467 không phải. 
Tìm số may mắn bé nhất có tổng các chữ số bằng n*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(int n){
    //4a + 7b = n
    for(int b = n / 7; b >= 0; b--){
        int remain = n - (7 * b);
        if(remain % 4 == 0){
            int a = remain / 4;
            cout << string(a, '4');
            cout << string(b, '7');
            return;
        }
    }
    cout << -1;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        solve(n);
        cout << endl;
    }
}