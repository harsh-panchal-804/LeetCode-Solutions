class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyprice=INT_MAX;
        int prof=INT_MIN;
        for(int i=0;i<prices.size();i++){
            buyprice=min(buyprice,prices[i]);
            prof=max(prof,prices[i]-buyprice);
        }
        return prof;
        
    }
};