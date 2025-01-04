class Solution {

public:

    string restoreString(string s, vector<int>& indices) {

        vector<char> vec(s.size());

        for(int i=0;i<s.size();i++){

            vec[indices[i]]=s[i];

        }

        string ans="";

        for(auto i : vec){

            ans+=i;

        }

        return ans;

        

    }

};