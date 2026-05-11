//Có n sợi dây A0 đến An, nối tất cả các sợi dây sao cho chí phí nối dây là ngắn nhất
//Chi phí nối dây bằng chiều dài từ Ai đến Aj
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int NoiDay(priority_queue<int, vector<int>, greater<int>> q){
    int ans = 0;
    while(q.size() > 1){
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        ans += x + y;
        q.push(x + y);
    }
    return ans;
}
int main(){
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        q.push(x);
    }
    cout << NoiDay(q);
}