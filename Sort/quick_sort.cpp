#include<bits/stdc++.h>
using namespace std;
// Lomuto partition
int partition(vector<int> &a, int l, int r){
    int pivot = a[r];
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(a[j] < pivot){
            i++;
            swap(a[i], a[j]); 
        }
    }
    i++;
    swap(a[i],a[r]);
    return i;
}
void quickSort(vector<int> &a, int l, int r){
    if(l >= r) return;
    int p = partition(a,l,r);
    quickSort(a ,l ,p - 1);
    quickSort(a ,p + 1, r);
}
int main(){
    vector<int> a;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    quickSort(a,0,n - 1);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}