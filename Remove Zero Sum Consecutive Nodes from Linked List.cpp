/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> vec;
        vector<int> remove;
        vector<ListNode*> ll;


        while(head!=NULL){
            vec.push_back(head->val);
            ll.push_back(head);
            head=head->next;
        }
        cout<<"OUR VEC IS ";
        for(auto i : vec) cout<<i<<" ";
        vector<int> prefix(vec.size());
        prefix[0]=vec[0];
        for(int i=1;i<vec.size();i++){
            prefix[i]=vec[i]+prefix[i-1];
        }
        cout<<"Our prefix is ";
        for(auto i : prefix) cout<<i<<" ";
        cout<<endl;
        for(int i=0;i<prefix.size();i++){
            if(prefix[i]==0){
                for(int j=0;j<=i;j++){
                remove.push_back(j);}
            }  
        }
        cout<<"idhar remove "<<endl;
        for(auto i : remove ) cout<<i;
        cout<<endl;
        for(int i=0;i<prefix.size();i++){
            vector<int>:: iterator it;
            it=find(prefix.begin()+i+1,prefix.end(),prefix[i]);
             
            if(it!=prefix.end()){
                cout<<prefix[i]<<" FOUND AT "<<i<<"and "<< it-prefix.begin()<<" "<<endl;
                int a=it-prefix.begin();
                
                // cout<<a<<endl;
                // vec.erase(vec.begin()+a);
                // vec.erase(vec.begin()+i+1);
                if(find(remove.begin(),remove.end(),i+1)==remove.end() &&find(remove.begin(),remove.end(),a)==remove.end())
                {
                    for(int j=i+1;j<=a;j++) remove.push_back(j);
                    // remove.push_back(i+1);
                    // remove.push_back(a);

                }
                
            }
        }
        cout<<"here remove "<<endl;
        for(auto i : remove ) cout<<i;
        cout<<endl;





        if(prefix.back()==0){
            return NULL;
        }
        // if(prefix.front()==0){
        //     return ll[1];
        // }
        

        for(auto i : remove ) cout<<i;
        cout<<endl;
        for(auto i : remove){
            ll[i]=NULL;
        }
        
        ///now create a new linked list
        while(ll.back()==NULL) ll.pop_back();
       
        ll.back()->next=NULL;
        vector<ListNode*> newll;
        cout<<"OUR LL";
        for(auto i : ll){
            cout<<i<<"->";
        }
        for(auto i : ll){
            if(i!=NULL) newll.push_back(i);
        }
        cout<<"NEW LL";
        for(auto i : newll){
            cout<<i<<" ->";
        }
        // creating our new ll
        newll.back()->next=NULL;
        for(int i=newll.size()-2;i>=0;i--){
            newll[i]->next=newll[i+1];
        }



        

        
       
        // for(auto i : prefix) cout<<i;
        // cout<<endl;
        // for(auto i : vec) cout<<i;
        return newll[0];
        
    }
};