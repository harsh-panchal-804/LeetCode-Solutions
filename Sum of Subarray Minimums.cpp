class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // for evry ele find prev small elem and next small ele
        const int mod =1e9+7;
        unordered_map<int,pair<int,int>> map;
        int n=arr.size();
        stack<int> stack;
        for(int i=0;i<n;i++){
            while(!stack.empty()&& arr[stack.top()]>=arr[i])stack.pop();
            map[i].first=stack.empty()?-1:stack.top();
           //// cout<<"prev small for "<<arr[i]<<" "<<map[arr[i]].first<<"\n";
            stack.push(i);
        }
        while(!stack.empty())stack.pop();
        for(int i=n-1;i>=0;i--){
            while(!stack.empty()&& arr[stack.top()]>arr[i])stack.pop();
            map[i].second=stack.empty()?n:stack.top();
            ///cout<<"next small for "<<arr[i]<<" "<<map[arr[i]].second<<"\n";
            stack.push(i);
        }
        long ans=0;
        for(int i=0;i<n;i++){
            long prev=i-map[i].first;
            long next=map[i].second-i;
            ///cout<<prev<<" "<<next<<"\n";
            ans=ans%mod + prev*next*arr[i]*1ll%mod;
        }
        return ans;
        /// 3 8 9 7 8 9 6
        /// 0 1 2 3 4 5 6
    }
};