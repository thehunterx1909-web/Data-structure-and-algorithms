#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, X[100], K;

void inkq(){
    for(int i = 1; i <= K; i++){
        cout << X[i];
    }
    cout << endl;
}
void Try(int i){
    for(int j = X[i - 1] + 1; j <= N - (K - i); j++){
        X[i] = j;
        if(i == K){
            inkq();
        }else Try(i + 1);
    }
}
int main(){
    X[0] = 0;
    cin >> N >> K;
    Try(1);
}