class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k,0);
        for(auto i : arr){
            freq[(i%k +k )%k]++;
            ///cout<<i%k<<" ";
        }
        if(freq[0]%2)return false;
        for(int i=1;i<=k/2;i++){
            int comp=k-i;
            if(freq[i]!=freq[comp])return false;
        }
        return true;
    }
};