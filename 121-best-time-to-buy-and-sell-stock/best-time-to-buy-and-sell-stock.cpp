class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int smallPrice = INT_MAX;  
        int largeProfit = 0;

        for (int price : prices) {
            if (price < smallPrice) {
                smallPrice = price;  
            } else {
                largeProfit = max(largeProfit, price - smallPrice);
            }
        }

        return largeProfit;
    }
};
