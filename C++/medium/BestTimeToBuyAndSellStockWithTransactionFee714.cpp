#include "template.hpp"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        int n = p.size();
        vector<vector<int>> dp(n, vector<int>(2));
        //dp[i][0] - max profit while holding a stock up to i-th day
        //dp[i][1] - max profit without holding a stock up to i-th day
        dp[0][0] = -p[0] - fee;
        dp[0][1] = 0;
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - p[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + p[i]);
        }

        return max(dp[n - 1][0], dp[n-1][1]);
    }
};

int main(){
    Solution* obj = new Solution();
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << obj->maxProfit(prices, fee);
}