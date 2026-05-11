#include<bits/stdc++.h>
using namespace std;

//Binary Search
// Mảng phải đc sắp xếp tăng dần hoặc giảm dần
bool BinarySearch(int a[], int l, int r, int x){
    if(l > r) return false;
    int m = (l + r) / 2;
    if(a[m] == x) {
        return true;
    } else if(a[m] < x){
        return BinarySearch(a, m + 1, r, x);
    } else {
        return BinarySearch(a, l, m - 1, x);
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int x;
    cout << "Nhap x: ";
    cin >> x;
    if(BinarySearch(a, 0, n - 1, x)) cout << "YES";
    else cout << "NO";
}