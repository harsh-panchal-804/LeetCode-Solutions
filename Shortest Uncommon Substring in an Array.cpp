struct Node {
    Node* links[26] = {NULL};
    bool flag = false;
    int cntPrefix = 0;
    bool containsKey(char ch) { return links[ch - 'a'] != NULL; }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
    void increasePrefix() { cntPrefix++; }
    void reducePrefix() { cntPrefix--; }
};
class Trie {
    Node* root;

public:
    Trie() { root = new Node(); }
    void insert(string s) {
        Node* node = root;
        for (char ch : s) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node);
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    bool search(string s) {
        Node* node = root;
        for (char ch : s) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        return node->isEnd();
    }
    void insertAllSubstring(string s) {
        for (int i = 0; i < s.length(); i++) {
            Node* node = root;
            for (int j = i; j < s.length(); j++) {
                if (!node->containsKey(s[j])) {
                    node->put(s[j], new Node);
                }
                node = node->get(s[j]);
                node->increasePrefix();
            }
        }
    }

    void deleteAllSubString(string s){
        for(int i=0;i<s.length();i++){
            Node* node=root;
            for(int j=i;j<s.length();j++){
                node=node->get(s[j]);
                node->reducePrefix();
            }
        }
    }
    
    string searchSmallestLexicographicallyString(string s) {
        string res;
        for (int i = 0; i < s.length(); i++) {
            Node* node = root;
            for (int j = i; j < s.length(); j++) {
                if (node->containsKey(s[j])) {
                    node = node->get(s[j]);
                }
                if (node->cntPrefix==0) {
                    
                    string subStr = s.substr(i, j - i + 1);
                    if (res.size() == 0) {
                        res = subStr;
                    } else if (res.size() > subStr.size()) {
                        res = subStr;
                    } else if (res.size() == subStr.size() && res > subStr) {
                        res = subStr;
                    }
                    
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        Trie t;
        for (string& s : arr) {
            t.insertAllSubstring(s);
        }
        vector<string> vs;
        for (string& s : arr) {
            t.deleteAllSubString(s);
            vs.push_back(t.searchSmallestLexicographicallyString(s));
            t.insertAllSubstring(s);
        }
        return vs;
    }
};