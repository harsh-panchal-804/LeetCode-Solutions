class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0;
        int r=arr.size()-1;
        if(arr[0]>arr[1]) return 0;
        if(arr[r]>arr[r-1]) return r;
        while(l<=r){
            int mid=(l+r)/2;
            if(mid>0 && arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1] && mid<arr.size()){
                return mid;
            }
            if(mid>0 && arr[mid]<arr[mid-1]){
                r=mid-1;
            }
            else if(mid<arr.size()-1 && arr[mid]<arr[mid+1]){
                l=mid+1;
            }
        }
        return -1;
        
    }
};
/// 3 2 1
/// 1 2 3 