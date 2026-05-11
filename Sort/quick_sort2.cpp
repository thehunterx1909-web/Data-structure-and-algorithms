#include<bits/stdc++.h>
using namespace std;
//Hoare partition
int partition(vector<int> &a, int l, int r){
    int pivot = a[l];
    int i = l - 1, j = r + 1;
    while(true){
        do{
            i++;
        }while(a[i] < pivot);
        do{
            j--;
        }while(a[j] > pivot);
        if(i < j){
            swap(a[i], a[j]);
        }
        else return j;
    }
}
void quickSort(vector<int> &a, int l, int r){
    if(l >= r) return;
    int p = partition(a, l, r);
    quickSort(a, l, p);
    quickSort(a, p + 1, r);
}
int main(){
    int n; cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    for(int x:a) cout << x << " ";
    cout << endl;
    quickSort(a, 0, n - 1);
    for(int x:a) cout << x << " ";
}