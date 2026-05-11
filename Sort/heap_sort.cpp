#include<bits/stdc++.h>
using namespace std;

void heap(vector<int> &a, int n, int i){
    int max = i;
    int l = 2*i + 1, r = 2*i + 2;
    if(l < n && a[l] > a[i]){
        max = l;
    }
    if(r < n && a[r] > a[max]){
        max = r;
    }
    if(max != i){
        swap(a[i], a[max]);
        heap(a, n, max);
    }
}
void heapSort(vector<int> &a){
    int n = a.size();
    for(int i = n/2 - 1; i >= 0; i--){
        heap(a, n, i);
    }
    for(int i = n - 1; i > 0; i--){
        swap(a[0], a[i]);
        heap(a, i, 0);
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    heapSort(a);
    for(int x:a){
        cout << x << " ";
    }
}