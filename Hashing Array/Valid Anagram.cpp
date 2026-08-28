#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool isAnagram(string s, string t){
    map<char, int> mps, mpt;
    int n = s.length();
    for(int i = 0; i < n; i++){
        mps[s[i]]++;
        mpt[t[i]]++;
    }
    return (mps == mpt) ? true : false;
}
int main(){
    string s, t;
    cin >> s >> t;
    if(isAnagram){
        cout << "true";
    }else{
        cout << "false";
    }
}