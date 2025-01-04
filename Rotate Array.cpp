class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int> deq;
        for(auto i : nums) deq.push_back(i);
        for(int i=0;i<k%nums.size();i++){
            int temp=deq.back();
            deq.pop_back();
            deq.push_front(temp);
        }
        nums.clear();
        for(auto i : deq)nums.push_back(i); 
        
    }
};