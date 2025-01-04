class Solution {
public:
    int maxArea(vector<int>& height) {
        int val=0;
        int left=0;
        int right=height.size()-1;
        while(left<right){
            val=max(abs(left-right)*min(height[left],height[right]),val);    
        
        if(height[left]<height[right]){
            left++;

        }
        else{
            right--;
        }
        }


        return val;
        
    }
};