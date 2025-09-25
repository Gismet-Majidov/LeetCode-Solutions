# Approach - Dynamic progamming

You can buy on a day if you don't hold a stock. You can sell on a day if you hold a stock. 

`Can we extend optimal solutions of smaller subproblems to bigger ones?`. Let's say we want to buy on day i, if you knew the maximum profit we could gain during the first i - 1 days, then we would extend it by buying the stock on day i or not buying it.

Here we are limited by the number of transations. We need to know part of which transation this buy and sell are. If we buy a stock, is it the part of second transation or first? 

Let **dp[i][j][0]** be the maximum profit until day i such that you have made j transations and not bought another stock

Let **dp[i][j][1]** be the maximum profit until day i such that you have made j transations and bought another stock

`**0 <= j <= 1**`

Additionally let's keep track of the maximum profit in variable **ans** when we complete the second trasaction.

Note that there is a simple 4-variable solution here. We only need to know the optimal answer for the previous day

Transactions are shown in the code. 