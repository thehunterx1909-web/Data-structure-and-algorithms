//Longest Substring Without Repeating Characters - bai 3 leetcode
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a[128] = {0};
        int cnt, r, l;
        cnt = r = l = 0;
        while(r < s.size()){
            if(a[s[r]] == 0){
                a[s[r]] = 1;
                cnt = max(cnt, r - l + 1);
                r++;
            } else{
                a[s[l]] = 0;
                l++;
            }
        }
        return cnt;
    }
};
int main(){
    
}