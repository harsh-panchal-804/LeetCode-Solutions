class Solution {
public:
    int jump(vector<int>& nums) {
        int steps=0;
        int l=0;
        int r=0;
        int farth=0;
        while(r<nums.size()-1){
            for(int i=l;i<r+1;i++){
                farth=max(farth,i+nums[i]);
            }
            l=r+1;
            r=farth;
            steps++;

        }
        return steps;
    }
};