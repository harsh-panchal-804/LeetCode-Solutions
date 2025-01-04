class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> ran;
        unordered_map<char,int> mag;
        for(auto i : ransomNote){
            ran[i]++;
        }
        for(auto i : magazine){
            mag[i]++;
        }
        for(auto i : ransomNote){
            if(mag[i]<ran[i]) return false;
        }
        return true;

        
    }
};