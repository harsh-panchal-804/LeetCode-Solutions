class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<vector<int>> fans;
        if(nums.size()<4) return fans;
        // if(nums.size()==4){
        //     long long tsum=nums[0]+nums[1]+nums[2]+nums[3];
        //     if(tsum==target){
        //         fans.push_back(nums);
        //         return fans;
        //     }
        //     else return fans;
        // }

        for(int i=0;i<nums.size()-4+1;i++){  
            for(int j=i+1;j<nums.size()-3+1;j++){   
                if(i>0 && nums[i]==nums[i-1]) continue;
                if(j>1 &&nums[j]==nums[j-1] && (j-1) !=(i)) continue;
                cout<<i<<j;
                int left=j+1;
                int right=nums.size()-1;
                while(left<right){
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[left];
                    sum+=nums[right];
                    if(sum>target) right--;
                    if (sum<target) left++;
                    if(sum==target){
                        ans.insert({nums[i],nums[j],nums[left],nums[right]});
                        
                        left++;
                        
                        // while(nums[left]==nums[left-1] && left<nums.size()){
                        //     left++;
                        // }
                        right--;
                    }
                }

            }
        }
        for(auto quadruplets : ans)
            fans.push_back(quadruplets);

        return fans;
    }
};