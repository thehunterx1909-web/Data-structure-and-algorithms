/*Cho xâu kí tự S. Ta gọi giá trị của xâu S là tổng bình phương 
số lần xuất hiện mỗi kí tự trong xâu S. Hãy tìm giá trị nhỏ nhất
của xâu S sau khi thực hiện K lần loại bỏ ký tự */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int Ans(string S, int k){
    map<char, int> mp;
    for(char x:S){
        mp[x]++;
    }
    priority_queue<int> Q;
    for(auto it:mp){
        Q.push(it.second);
    }
    while(k--){
        int tmp = Q.top();
        Q.pop();
        tmp--;
        Q.push(max(tmp, 0));
    }
    ll ans = 0;
    while(!Q.empty()){
        ans += Q.top() * Q.top();
        Q.pop();
    }
    return ans;
}

int main(){
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        string S;
        cin >> S;
        cout << Ans(S, k); 
    }
}