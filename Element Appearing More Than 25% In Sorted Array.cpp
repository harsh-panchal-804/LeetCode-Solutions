class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int q=n/4;
        int fre[100001]={0};
        for(int x:arr){
            fre[x]++;
            if(fre[x]>q) return x;
        }
        return 0;
        
    }
};