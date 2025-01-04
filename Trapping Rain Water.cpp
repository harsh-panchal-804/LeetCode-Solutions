class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lmax(height.size());
        vector<int> rmax(height.size());
        int water=0;
        int sum=0;
        for(int i =1;i<height.size()-1;i++){
            lmax[i]=max(lmax[i-1],height[i-1]);
            cout<<lmax[i-1];
        }
        for(int j =height.size()-2;j>=0;--j){
            rmax[j]=max(rmax[j+1],height[j+1]);
        }

        for(int i =0;i<height.size()-1;i++){
            water=min(lmax[i],rmax[i])-height[i];
            if(water>=0){
                sum+=water;
            }  
        }
        return sum;
        
       
        
    }
};