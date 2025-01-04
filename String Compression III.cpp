class Solution {
public:
    string compressedString(string word) {
        int n=word.size();
        int count=1;
        string ans="";
        for(int i=1;i<n;i++){
            if(word[i]==word[i-1]&& count<9){
                count++;
            }
            else if(word[i]==word[i-1]&&count==9){
                ans+=to_string(count);
                ans+=word[i-1];
                count=1;
            }
            else{
                ans+=to_string(count);
                ans+=word[i-1];
                count=1;
            }
        }
        ans+=to_string(count);
        ans.push_back(word[n-1]);
        return ans;
        
    }
};