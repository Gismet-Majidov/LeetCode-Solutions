# Approach - Dynamic programming

`What is the answer for a single day?`
The answer is not to buy a stock. So it is zero. 

`What if there is more than one day?`

`Should we buy or sell a stock on a particular day?`

If we sell on the i-th day and bought on the j-th day (j < i), then we gain prices[i] - prices[j] - fee profit

`When are we allowed to buy?` - only when we don't already hold a stock. 
`What happens to the profit when we buy on the i-th day?` - it decreases by prices[i] + fee. In other words, profit = profit - prices[i] - fee. 

`When are we allowed to sell?` - only when we already hold a stock. `What happens to the profit when we sell on the i-th day?` - Profit increases by **price[i]**. To get the maximum profit possible in case we buy on the i-th day, we need to know the maximum profit thus far such that we don't hold a stock. To get the maxium profit possible in case we sell on the i-th day, we need to know the maximum profit thus far such that we hold a stock. 

## Formulazing DP table

Let **dp[i][0]** be the maximum profit such that we hold a stock on the i-th day. 

Let **dp[i][1]** be the maximum profit such that we don't hold a stock on the i-th day. 

Base case (simple enough)

dp[i][0] = -prices[0] - fee;

dp[i][1] = 0;

## Transitions

**dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i] - fee)**

**dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])**

The maximum profit such that we hold a stock on the i-th day is either the maximum profit such that we hold a stock on the (i - 1)-th day, or the maximum profit such that we don't hold a stock on the (i-1)-th day and we buy a stock on the i-th day. 

The case is similar for the maximum profit such that we don't hold a stock

