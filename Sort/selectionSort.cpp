#include<bits/stdc++.h>
using namespace std;

void Selection(int a[],int n){
    for(int i = 0; i < n - 1; i++){
        int minPos = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[minPos]){
                minPos = j;
            }
        }
        swap(a[minPos], a[i]);
    }
}
int main(){
    int a[6] = {4, 5, 2, 12, 1, 45};
    Selection(a, 6);
    for(int x:a){
        cout << x << " ";
    }
}