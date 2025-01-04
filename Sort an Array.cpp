class Solution {
public:
    void mergesort(vector<int>& vec,int l,int m,int r){
        int indx=l;
        int indx2=m+1;
        int i=0;
        vector<int> temp(r-l+1);
        while(indx<=m && indx2<=r){
            if(vec[indx]<=vec[indx2]){
                temp[i++]=vec[indx++];
            }
            else{
                temp[i++]=vec[indx2++];
            }
        }
        while(indx<=m){
            temp[i++]=vec[indx++];
        }
        while(indx2<=r){
            temp[i++]=vec[indx2++];
        }
        int j=0;
        for(int k=l;k<=r;k++){
            vec[k]=temp[j];
            j++;
        }
    }
    void merge(vector<int> & vec,int l,int r){
        if(l<r){
            int mid=(l+r)/2;
            merge(vec,l,mid);
            merge(vec,mid+1,r);
            mergesort(vec,l,mid,r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        merge(nums,0,nums.size()-1);
        return nums;
        
    }
};