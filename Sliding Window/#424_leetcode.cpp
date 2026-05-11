//Longest Repeating Character Replacement
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> cnt;
        int ans = 0, i = 0, maxf = 0;
        for(int j = 0; j < s.size(); j++){
            cnt[s[j]]++;
            maxf = max(maxf, cnt[s[j]]);
            while((j - i + 1) - maxf > k){
                cnt[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

int main(){
    
}