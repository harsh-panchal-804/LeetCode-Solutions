class Solution {
public:
    int find(vector<int> &nums,int target,int side){
            int left=0;
            int right=nums.size()-1;
            int ans=-1;
            while(left<=right){
                int mid=(left +right)/2;
                if(nums[mid]<target){
                    left=mid+1;
                    
                }
                else if(nums[mid]>target){
                    right=mid-1;
                   
                }
                else if(nums[mid]==target &&side==1){
                    ans=mid;
                    left=mid+1;
                    
                
                }
                else if(nums[mid]==target &&side==0){
                    ans=mid;
                    right=mid-1;
                    
                }
            }
            return ans;

        }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1,-1};
        //side=0 for left
        
        
        ans[0]=find(nums,target,0);
        ans[1]=find(nums,target,1);
        cout<<ans[0];
        cout<<ans[1];
        return ans;  
    }
};