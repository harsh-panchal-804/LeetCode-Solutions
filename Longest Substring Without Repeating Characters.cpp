class Solution {
public:
    int lengthOfLongestSubstring(string s) { // Sliding window O(N)
        if(s.size() == 0) return 0;

        int left = 0;
        int length = 0;
        unordered_map<char, int> charIndex;

        for(int right = 0; right < s.size(); right++) {
            char curr = s[right];
            if(charIndex.find(curr) != charIndex.end() && charIndex[curr] >= left) {
                left = charIndex[curr]+1;
            }
            else {
                length = max(length, right-left+1);
            }
            charIndex[curr] = right;
        }
        return length;
    }
};