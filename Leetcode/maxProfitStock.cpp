  class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Profit maximized when buy price is low but sell price is high
        int profit = 0;
        int sell_price = 0;
        int buy_price = 10000;
        
        for (int i = 0; i < prices.size(); i++){
            //Updating buy price depending if there is a smaller buy price
            if (prices[i] < buy_price && i != prices.size()-1){
                buy_price = prices[i];
                sell_price=0;
            }
            //Only update sell price if it isn't the same as buy price
            else if (prices [i] > sell_price){
                sell_price = prices[i];
            }
                
            //Looking to update profit 
            if((sell_price - buy_price) > profit){
                profit = (sell_price - buy_price);
            }
            
        }
        return profit;
    }
};