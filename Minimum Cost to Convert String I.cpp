class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& orignal, vector<char>& changed, vector<int>& cost) {
        int n=orignal.size();
        vector<vector<int>> vec(26,vector<int>(26,1e7));
        for(int i=0;i<26;i++){
            vec[i][i]=0;
        }
        for(int i=0;i<n;i++){
            int fr=orignal[i]-'a';
            int to=changed[i]-'a';
            vec[fr][to]=min(cost[i],vec[fr][to]);
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    vec[i][j]=min(vec[i][j],vec[i][k]+vec[k][j]);
                }
            }
        }
        // for(int i=0;i<26;i++){
        //     for(int j=0;j<26;j++){
        //         cout<<vec[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(source[i]!=target[i]){
                int fr=source[i]-'a';
                int to=target[i]-'a';
                if(vec[fr][to]==1e7){
                    return -1;
                }
                else ans+=vec[fr][to];
            }
        }
        return ans;


        
    }
};