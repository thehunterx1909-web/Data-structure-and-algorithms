#include<bits/stdc++.h>
using namespace std;

void BubbleSort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
            }
        }
    }
}
int main(){
    int a[10] = {8, 2, 1, 23, 56, 58, 54, 12, 4, 25};
    BubbleSort(a, 10);
    for(int x:a){
        cout << x << " ";
    }
}