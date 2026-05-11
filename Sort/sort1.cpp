#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//sort(a,a+n) => [0,n-1]
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i] ;
    }
    sort(a,a+n); //O(NlogN) = intro sort : quick sort + heap sort
    for(int x:a){
        cout << x << " ";
    }
    cout << endl;
    sort(a,a+n,greater<int>()); //giam dan
    for(int x:a){
        cout << x << " ";
    }
}
