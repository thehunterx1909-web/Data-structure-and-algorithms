#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//sort(a,a+n) => [0,n-1]
//comparison function
//a va b là các cặp phần tử trong mảng, a đứng trước, b đứng sau
//true: a và b đã đúng thứ tự bạn cần sắp xếp
//false: a và b đang sai thứ tự sắp xếp

bool cmp(int a,int b){
    return a < b;
}
int main(){
    int n;
    cin >> n;
    int a[n],b[n];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i] ;
    }
    
    sort(a,a+n,cmp); //O(NlogN) = intro sort : quick sort + heap sort
    for(int x:a){
        cout << x << " ";
    }
}