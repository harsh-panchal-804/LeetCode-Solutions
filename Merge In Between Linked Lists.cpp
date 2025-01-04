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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        vector<ListNode*> newll;
        vector<ListNode*> ll;
        while(list1!=NULL){
            ll.push_back(list1);
            list1=list1->next;
        }
        for(int i=0;i<a;i++){
            newll.push_back(ll[i]);
        }
        while(list2!=NULL){
            newll.push_back(list2);
            list2=list2->next;
        }
        for(int i=b+1;i<ll.size();i++){
            newll.push_back(ll[i]);
        }
        // creating the linked list;
        newll[newll.size()-1]->next=NULL;
        for(int i=newll.size()-2;i>=0;i--){
            newll[i]->next=newll[i+1];
        }

        cout<<"newll "<<endl;
        for(auto i : newll) cout<< i<<"->";
        cout<<"ll"<<endl;
        for(auto i : ll) cout<< i<<"->";
        return newll[0];


        
    }
};