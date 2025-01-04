class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> row1{'q', 'w', 'e', 'r', 't',
                                 'y', 'u', 'i', 'o', 'p'};
        unordered_set<char> row2{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        unordered_set<char> row3{'z', 'x', 'c', 'v', 'b', 'n', 'm'};

        vector<string> result;

        for (string& word : words) {
            int count1 = 0;
            int count2 = 0;
            int count3 = 0;
            int word_len = word.length();

            for (char& w : word) {
                char c = tolower(w);

                if (row1.find(c) != row1.end())
                    count1++;

                if (row2.find(c) != row2.end())
                    count2++;
                if (row3.find(c) != row3.end())
                    count3++;
            }

            if (count1 == word_len || count2 == word_len || count3 == word_len)
                result.push_back(word);
        }

        return result;
    }
};