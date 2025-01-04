class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morseCode = {
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
            "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
            "..-", "...-", ".--", "-..-", "-.--", "--.."
        };
        set<string> set;
        for(auto & word:words){
            string morse="";
            for(auto&c :word){
                morse+=morseCode[c-'a'];
            }
            set.insert(morse);
        }
        
        return set.size();
    }
};