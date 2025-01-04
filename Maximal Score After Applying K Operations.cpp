class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int,vector<int>> pq(nums.begin(),nums.end());
        while(k){
            long long ele=pq.top();
            // cout<<ele<<"\n";
            ans+=ele;
            pq.pop();
            pq.push(ceil((double)ele/3));
            k--;
        }
        return ans;
    }
};