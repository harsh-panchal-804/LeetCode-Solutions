class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> diff(s.size());
        int ans=0;
        for(int i=0;i<s.size();i++){
            diff[i]=abs(s[i]-t[i]);
        }
        for(auto i : diff){
            cout<< i<<" ";
        }
        for(int i=0;i<s.size();i++){
            int j=i;
            int sum=0;
            while(j<s.size()&&sum<=maxCost){
                if(diff[j]+sum<=maxCost){
                sum+=diff[j];
                ans=max(ans,j-i+1);
                j++;
                }
                else break;
                
            }
           
        }
        return ans;
        
      
       
        return 0;
        
    }
};