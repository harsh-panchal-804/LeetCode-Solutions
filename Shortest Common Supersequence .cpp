class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.size();
        int n=str2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=0;i<m+1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<n+1;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int x=m;
        int y=n;
        string ans="";
        while(x>0 &&y>0){
            if(str1[x-1]==str2[y-1]){
                ans.push_back(str1[x-1]);
                x--;
                y--;
            }
            else{
                if(dp[x-1][y]>dp[x][y-1]){
                ans.push_back(str1[x-1]);
                x--;
                }

                else{
                ans.push_back(str2[y-1]);
                y--;
            }

            }
            
        }
        while(x>0){
            ans.push_back(str1[x-1]);
            x--;
        }
        while(y>0){
            ans.push_back(str2[y-1]);
            y--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};