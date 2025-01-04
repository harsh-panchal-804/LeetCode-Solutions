class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int>vec1(26,0);
        vector<int>vec2(26,0);
        int m=s1.size();
        int n=s2.size();
        if(m>n) return false;
        for(auto i: s1){
            vec1[i-'a']++;
        }
        for(int i=0;i<m;i++){
            vec2[s2[i]-'a']++;
        }
        if(vec1==vec2) return true;
        for(int i=m;i<n;i++){
            vec2[s2[i]-'a']++;
            vec2[s2[i-m]-'a']--;
            if(vec1==vec2) return true;
            
        }
        return false;

    }
};