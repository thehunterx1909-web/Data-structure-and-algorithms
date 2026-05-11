#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int l, int r){
    int i = l - 1;
    int j = r + 1;
    int pivot = a[l];
    while(true){
        do{
            i++;
        }while(a[i] < pivot);
        do{
            j--;
        }while(a[j] > pivot);
        if(i < j){
            swap(a[i], a[j]);
        } else return j;
    }
}
void quicksort(vector<int> &a, int l, int r){
    if(l >= r) return;
    int p = partition(a, l, r);
    quicksort(a, l, p);
    quicksort(a, p + 1, r);
}
int main(){
    vector<int> a;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    quicksort(a, 0, n - 1);
    for(int x:a){
        cout << x << " ";
    }
}