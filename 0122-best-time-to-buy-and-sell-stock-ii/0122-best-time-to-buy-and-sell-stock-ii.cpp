class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int buying=-prices[0];
      int n=prices.size();
      int notbuying=0;
      for(int i=0;i<n;i++){
        buying=max(notbuying-prices[i],buying);
        notbuying=max(buying+prices[i],notbuying);
      }
      return notbuying;
    }
};