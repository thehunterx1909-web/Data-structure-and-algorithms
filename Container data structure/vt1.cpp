#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    vector<int> a;
    int n;
    do{
        int n;
        cin >> n;
        a.push_back (n);
    } while(n!=50);
    cout << a.size();
    return 0;
}