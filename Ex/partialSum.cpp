#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll a[] = {0,4,7,2,8,4,8,3,2};
    ll n = 9;
    partial_sum(a, a + n, a);
    int t;
    cin >> t;
    while(t--){
        ll l, r;
        cin >> l >> r;
        cout << a[r] - a[l];
    }
}