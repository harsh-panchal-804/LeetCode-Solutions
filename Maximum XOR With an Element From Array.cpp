class TrieNode{
    public:
    bool eow;
    vector<TrieNode*> child;
    TrieNode(){
        child.resize(2,nullptr);
        eow=false;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }
    void insert(int num){
        bitset<32> bits(num);
        TrieNode* curr=root;
        for(int i=31;i>=0;i--){
            int indx=bits[i];
            if(curr->child[indx]==nullptr){
                curr->child[indx]=new TrieNode();
            }
            curr=curr->child[indx];
        }

    }
    int get_max(int num){
        int ans=0;
        TrieNode* curr=root;
        bitset<32> bits(num);
        for(int i=31;i>=0;i--){
            int val=bits[i];
            if(curr->child[1-val]!=nullptr){
                ans+=(1<<i);
                curr=curr->child[1-val];
            }
            else{
                curr=curr->child[val];
            }
        }
        return ans;
    }
};




class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        int q_size=queries.size();
        for(int i=0;i<q_size;i++){
            queries[i].push_back(i);
        }
        sort(nums.begin(),nums.end());
        sort(queries.begin(),queries.end(),[&](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        Trie* trie=new Trie();

        vector<int> ans(q_size);
        int ind=0;
        for(auto q: queries){
            int x=q[0];
            int m=q[1];
            int i=q[2];
            while(ind<nums.size()&&nums[ind]<=m){
                trie->insert(nums[ind]);
                ind++;
            }
            if(ind==0)ans[i]=-1;
            else{
                int temp=trie->get_max(x);
                ans[i]=temp;
            }
        }
        return ans;
    }
};