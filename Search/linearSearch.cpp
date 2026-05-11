#include<bits/stdc++.h>
using namespace std;

bool ls(int a[], int n, int x){
    for(int i = 0; i < n; i++){
        if(a[i] == x) return true;
    }
    return false;
}