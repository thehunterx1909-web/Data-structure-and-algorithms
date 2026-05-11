#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//sort(a,a+n) => [0,n-1]
//comparison function
//a va b là các cặp phần tử trong mảng, a đứng trước, b đứng sau
//true: a và b đã đúng thứ tự bạn cần sắp xếp
//false: a và b đang sai thứ tự sắp xếp

int tong(int n){
    int ans = 0;
    while(n){
        ans += n%10;
        n/=10;
    }
    return ans;
}
bool cmp(int a,int b){
    return tong(a) < tong(b);
}
bool cmp1(int a,int b){
    return abs(a) < abs(b);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i] ;
    }
    sort(a,a+n,cmp1); //O(NlogN) = intro sort : quick sort + heap sort
    //sắp xếp theo trị tuyệt đối tăng dần
    for(int x:a){
        cout << x << " ";
    }
    sort(a,a+n,cmp); //sắp xếp theo tổng các chữ số tăng dần
    cout << endl;
    for(int x:a){
        cout << x << " ";
    }
}