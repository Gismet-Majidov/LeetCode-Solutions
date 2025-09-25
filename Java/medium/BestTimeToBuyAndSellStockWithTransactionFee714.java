
class Solution {
    public int maxProfit(int[] p, int fee) {
        
        int n = p.length;
        int stock = -p[0] - fee;
        int noStock = 0;

        //stock - maximum profit we got so far such that we hold a stock
        //noStock - maximum profit we got so far such that we don't hold a stock


        for(int i = 1; i < n; i++){
            int tmp = stock;
            stock = Math.max(stock, noStock - p[i] - fee);
            noStock = Math.max(noStock, tmp + p[i]);
        }

        return Math.max(stock, noStock);
    }
}


public class BestTimeToBuyAndSellStockWithTransactionFee714{
    public static void main(String[] args){
        int[] prices = {1,3,2,8,4,9};
        int fee = 2;
        Solution obj = new Solution();
        System.out.println(obj.maxProfit(prices, fee));
    }
}