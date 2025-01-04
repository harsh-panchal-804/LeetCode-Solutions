class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> arr(n+1,0);
        for(auto i : bookings){
            int u=i[0];
            int v=i[1];
            int num=i[2];
            arr[u-1]+=num;
            arr[v]-=num;
        }
        for(int i=1;i<arr.size();i++){
            arr[i]+=arr[i-1];
        }
        return vector<int>(arr.begin(),arr.end()-1);

    }
};