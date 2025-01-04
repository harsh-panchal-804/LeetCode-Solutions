class Solution {
public:
    int freq(string &s){
        return count(s.begin(),s.end(),*min_element(s.begin(),s.end()));
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> ans;
        for(auto q : queries){
            int count=0;
            int fq=freq(q);
            for(auto w : words){
                if(fq<freq(w)){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;

        
    }
};