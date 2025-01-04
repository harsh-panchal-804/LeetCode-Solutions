class TrieNode{
    public:
    TrieNode* children[2];
    TrieNode(){
        for(int i=0;i<2;i++){
            children[i]=NULL;
        }
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }
    void insert(int num){
        TrieNode* node=root;
        bitset<32>bs(num);
        for(int i=31;i>=0;i--){
            int index=bs[i];
            if(node->children[index]==NULL){
                node->children[index]=new TrieNode();
            }
            node=node->children[index];
        }
    }
    int getMax(int num){
        TrieNode* node=root;
        int maxSum=0;
        bitset<32> bs(num);
        for(int i=31;i>=0;i--){
            int index=bs[i];
            if(node->children[1-index]==NULL){
                node=node->children[index];
            }
            else{
            maxSum+=(1<<i);
            node=node->children[1-index];
            }
        }
        return maxSum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        Trie t;
        for(auto &i:nums){
            t.insert(i);
        }
        int maxi=0;
        for(auto i:nums){
            maxi=max(maxi,t.getMax(i));
        }
        return maxi;
    }
};