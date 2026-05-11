//best time to buy and sell stock - bai 121 leetcode
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = prices[0];
        int profit = 0;
        for(int i = 0; i < prices.size(); i++){
            if(buyPrice > prices[i]){
                buyPrice = prices[i];
            }
            profit = max(profit, prices[i] - buyPrice);
        }
        return profit;
    }
};

int main(){
    
}