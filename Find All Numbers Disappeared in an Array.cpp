class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> map(n+1,0);
        for(auto i: nums){
            map[i]++;
        }
        vector<int> ans;
        for(int i=1;i<=n;i++){
            cout<<"m";
            if(map[i]==0){
              
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};