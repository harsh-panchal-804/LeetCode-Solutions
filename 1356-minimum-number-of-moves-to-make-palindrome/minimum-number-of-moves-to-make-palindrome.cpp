class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int i = 0, j = s.length()-1,k,ans=0;
        while(i<j){
            if(s[i]==s[j]){
                i++;j--;
            }else{
                k = j;
                while(k>=i && s[k] != s[i]){
                    k--;
                }
                if(k==i){
                    ans++;
                    swap(s[i],s[i+1]);
                }else{
                    while(k<j){
                        swap(s[k],s[k+1]);
                        k++;
                        ans++;
                    }
                    i++;j--;
                }
            }
        }
        return ans;
    }
};