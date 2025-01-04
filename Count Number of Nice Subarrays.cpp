class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(auto & e : nums){
            e=e%2;
            cout<<e<<" ";
        }
        vector<int> prefix(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        int ans=0;
        unordered_map<int,int> map;
        for(int i=0;i<prefix.size();i++){
            if(prefix[i]==k)ans++;
            if(map.find(prefix[i]-k)!=map.end()){
                ans+=map[prefix[i]-k];
            }
            map[prefix[i]]++;
        }
        cout<<endl;
        return ans;;
        
    }
};