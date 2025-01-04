class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size() || nums.size()==1)return nums.size();
        priority_queue<int,vector<int>, greater<int>>pq(nums.begin(),nums.end());
        int prev=pq.top();
        pq.pop();
        int ans=1;
        int count=1;
        while(!pq.empty()){
            if(pq.top()==1+prev){
                count++;
                ans=max(ans,count);  
            }
            else{
                if(pq.top()!=prev){
                    count=1;
                    ans=max(ans,count);
                }
                
            }
            prev=pq.top();
            pq.pop();
        }
        return ans;
        
    }
};