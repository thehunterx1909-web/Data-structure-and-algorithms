#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPalindrome(string s){

    string filtered;
    for(char c : s){
        if(isalnum(c)){
            filtered += tolower(c);
        }
    }
    int n = filtered.length();
    int l = 0, r = n - 1;

    while(l < r){
        if(filtered[l] != filtered[r]){
            return false;
        }else{
            l++;
            r--;
        }
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    if(isPalindrome(s)){
        cout << "true";
    }else{
        cout << "false";
    }
}