class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        unordered_map<int,pair<int,int>> map;
        stack<int> stack;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(!stack.empty()&& nums[stack.top()]>=nums[i])stack.pop();
            map[i].first=stack.empty()?-1:stack.top();
            stack.push(i);
        }
        while(!stack.empty())stack.pop();
        for(int i=n-1;i>=0;i--){
            while(!stack.empty()&& nums[stack.top()]>nums[i])stack.pop();
            map[i].second=stack.empty()?n:stack.top();
            stack.push(i);
        }
        while(!stack.empty())stack.pop();
        unordered_map<int,pair<int,int>> map2;
        for(int i=0;i<n;i++){
            while(!stack.empty()&& nums[stack.top()]<=nums[i])stack.pop();
            map2[i].first=stack.empty()?-1:stack.top();
            stack.push(i);
        }
        while(!stack.empty())stack.pop();
        for(int i=n-1;i>=0;i--){
            while(!stack.empty()&& nums[stack.top()]<nums[i])stack.pop();
            map2[i].second=stack.empty()?n:stack.top();
            stack.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long ps=i-map[i].first;
            long ns=map[i].second-i;
            long pl=i-map2[i].first;
            long nl=map2[i].second-i;
            ans+=(pl*nl*nums[i]*1ll)-(ps*ns*nums[i]*1ll);
        }
        return ans;

        
    }
};