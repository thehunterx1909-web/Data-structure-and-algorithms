//Bai 5
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    map<char,int> mp;
    for(int i=0;i<n;i++){
        char x; 
        cin >> x;
        mp[x]++;
      }
    for(pair<char,int> x:mp){
        cout << x.first << " " << x.second << endl;
    }
}