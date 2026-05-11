#include<bits/stdc++.h>
using namespace std;

// Trộn 2 dãy tăng dần: [left, middle ], [middle + 1, right]
void merge(vector<int> &a, int l, int m, int r){
    vector<int> x(a.begin() + l, a.begin() + m + 1);
    vector<int> y(a.begin() + m + 1, a.begin() + r + 1);
    int i = 0, j = 0;
    while(i < x.size() && j < y.size()){
        if(x[i] < y[j]){
            a[l] = x[i];
            l++;
            i++;
        } else{
            a[l] = y[j];
            l++;
            j++;
        }
    }
    while(i < x.size()){
        a[l] = x[i];
        l++;
        i++;
    }
    while(j < y.size()){
        a[l] = y[j];
        l++;
        j++;
    }
}
void mergeSort(vector<int> &a, int l, int r){
    if(l >= r) return;
    int m = (l + r)/2;
    mergeSort(a,l,m);
    mergeSort(a,m + 1, r);
    merge(a,l,m,r);
}
int main(){
    vector<int> a;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    mergeSort(a,0,n - 1);
    for(int x:a){
        cout << x << " ";
    }
}