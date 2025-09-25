 #include "template.hpp" 

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& p) {
        
        int n = p.size();

        if(n == 1) return 0; // if there is a single day, it is best not to buy the stock
        if(n == 2) return max(0, p[1] - p[0]);//if two days, either make no transation or buy on day 0 and sell on day 1

        //Let dp[i][0][0] be the maximum profit such that you haven't made a transation yet but bought a stock till day i
        //Let dp[i][1][0] be the maximum profit such that you have made the first transation and bought a stock till day i
        //Let dp[i][1][1] be the maximum profit such that you have only made the first transation and bought no stock till day i

        //Note: dp[i][0][1] is the maximum profit such that you haven't made a transation yet and bought no stock
        //Essentially you have done nothing, so the profit is always zero
    


        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2 )));
        //Here are the base cases (when n <= 3)
        dp[0][0][0] = -p[0]; // on day 0, you have made no transactions
        dp[1][0][0] = max(-p[0], -p[1]);
        dp[1][1][1] = p[1] - p[0];
        dp[2][0][0] = max(dp[1][0][0], -p[2]);
        dp[2][1][0] = p[1] - p[0] - p[2];
        dp[2][1][1] = max(dp[1][1][1], dp[1][0][0] + p[2]);
        int ans = max(0, dp[2][1][1]); //This keeps tracks of the maximum profit when two transaction are made
        for(int i = 3; i < n; i++){
            ans = max(ans, dp[i - 1][1][0] + p[i]);
            dp[i][0][0] = max(dp[i - 1][0][0], -p[i]);
            dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] - p[i]);
            dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][0] + p[i]);
        }
        
        return max(ans, dp[n - 1][1][1]);
    }
};



int main(){
    
    Solution* obj = new Solution();
    vector<int> prices = {3,3,5,0,0,3,1,4};

    cout << obj->maxProfit(prices);


    return 0;
}
