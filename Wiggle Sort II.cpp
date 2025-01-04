class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        priority_queue<int,vector<int>> pq(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=2){
            nums[i]=pq.top();
            pq.pop();
        }
        for(int i=0;i<nums.size();i+=2){
            nums[i]=pq.top();
            pq.pop();
        }
        ///return nums;
        
    }
};
/// 1 1 1 4 5 6
/// 6 5 4 1 1 1
/// 1 6 1 5 1 4


/// 1 1 2 2 3 3
/// 3 3 2 2 1 1
/// 