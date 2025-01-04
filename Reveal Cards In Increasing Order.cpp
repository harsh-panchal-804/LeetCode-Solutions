class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        queue<int>queue;
        for(int i=0;i<deck.size();i++){
            queue.push(i);
        }
        vector<int> vec(deck.size());
        for(auto i : deck){
            int index=queue.front();
            queue.pop();
            vec[index]=i;
            if(!queue.empty()){
                int temp=queue.front();
                queue.pop();
                queue.push(temp);
            }
        }
        return vec;
        
    }
};