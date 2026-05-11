#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//sort(a,a+n) => [0,n-1]
//sort(a+x, a+y+1)
//sort(v.begin(), v.end())
//sort(v.begin(), v.begin()+y+1)
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i] ;
    }
    sort(a.begin(),a.end()); //O(NlogN) = intro sort : quick sort + heap sort
    for(int x:a){
        cout << x << " ";
    }
}