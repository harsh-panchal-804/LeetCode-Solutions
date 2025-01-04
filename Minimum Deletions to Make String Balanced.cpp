class Solution {
public:
    int minimumDeletions(string s) {
        // b ke baad no a
        int n=s.size();
        vector<int> b(n+1,0);
        for(int i=1;i<n+1;i++){
            b[i]=b[i-1]+(s[i-1]=='b'?1:0);
        }
        vector<int> a(n+1,0);
        for(int i=n-1;i>=0;i--){
            a[i]=a[i+1]+(s[i+1]=='a'?1:0);
        }
        int ans=1e9;
        for(int i=0;i<n+1;i++){
            ans=min(ans,a[i]+b[i]);
        }
        return ans;

    }
};