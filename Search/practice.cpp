#include<bits/stdc++.h>
using namespace std;

bool BS(vector<int> a, int l, int r, int k){
    sort(a.begin(), a.end());
    int m = (l + r) / 2;
    if(a[m] == k) return true;
    else if(k < a[m]) return BS(a, l, m - 1, k);
    else if(k > a[m]) return BS(a, m + 1, r, k);
    return false;
}
int main(){
    vector<int> a;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    int k; cin >> k;
    if(BS(a,0, n - 1, k) == true){
        cout << "found" << endl;
    }else cout << "not found" << endl;
}