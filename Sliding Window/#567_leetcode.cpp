//Permutation in String 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        unordered_map<char, int> cnt1;
        unordered_map<char, int> cnt2;
        for(int i = 0; i < s1.size(); i++){
            cnt1[s1[i]]++;
            cnt2[s2[i]]++;
        }
        if(cnt1 == cnt2){
            return true;
        }
        int l = 0;
        for(int r = s1.size(); r < s2.size(); r++){
            cnt2[s2[r]]++;
            cnt2[s2[l]]--;

            if(cnt2[s2[l]] == 0){
                cnt2.erase(s2[l]);
            }
            l++;
            if(cnt1 == cnt2){
                return true;
            }
        }
        return false;
    }
};
int main(){
    
}