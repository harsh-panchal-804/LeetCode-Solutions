class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a>0){
            pq.push({a,'a'});
        }
        if(b>0){
            pq.push({b,'b'});
        }
        if(c>0){
            pq.push({c,'c'});
        }
        string ans="";
        while(!pq.empty()){
            auto [freq,ele]=pq.top();
            pq.pop();
            if(ans.size()>=2 && ans[ans.size()-1]==ele && ans[ans.size()-2]==ele){
                if(pq.empty())break;
                auto [next_freq,next_ele]=pq.top();
                pq.pop();
                ans+=next_ele;
                next_freq--;
                if(next_freq){
                    pq.push({next_freq,next_ele});
                }
            }
            else{
                ans+=ele;
                freq--;
            }
            if(freq){
                pq.push({freq,ele});
            }
        }
        return ans;
    }
};