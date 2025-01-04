class Solution {
public:
    int numTeams(vector<int>& r) {
        int ans=0;
        int n=r.size();
        for(int j=0;j<n;j++){
            int small_jl=0;
            int big_jl=0;
            int small_jr=0;
            int big_jr=0;
            for(int i=0;i<j;i++){
                if(r[i]<r[j])small_jl++;
                if(r[i]>r[j])big_jl++;
            }
            for(int k=j+1;k<n;k++){
                if(r[k]>r[j])big_jr++;
                if(r[k]<r[j])small_jr++;
            }
            ans+=(small_jl)*big_jr+(small_jr)*big_jl;
        }
        return ans;
        
    }
};
