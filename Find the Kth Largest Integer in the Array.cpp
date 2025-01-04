class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        auto cmp= [](string &a ,string &b){
        if(a.size() == b.size()) return a > b;
        return a.size() > b.size();
        };
        priority_queue<string, vector<string>,decltype(cmp)> pq(cmp);
        for(auto &it : nums) {
            pq.push(it);
            if(pq.size() > k)pq.pop();
        }
        return pq.top();
    }
};