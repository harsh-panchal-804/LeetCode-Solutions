class Solution {
public:
    bool isSubFolder(string &s1, string & s2){
        int x = s1.size();
        int i=0;
        while(s1[i] == s2[i]){
            i++;
        }
        if(i==x && s2[i] == '/'){
            return true;
        }
        else{
            return false;
        }
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        for(int i=0; i<folder.size(); i++){
            if(i==0){
                res.push_back(folder[i]);
            }
            else{
                if(!isSubFolder(res.back(), folder[i])){
                    res.push_back(folder[i]);
                }
            }
        }
        return res;
    }
};