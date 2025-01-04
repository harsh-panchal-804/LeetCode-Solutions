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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head =new ListNode(); 
        ListNode* current=head;
        while(list1!=NULL & list2!=NULL){
            if(list2->val>list1->val){
                current->next=list1;
                list1=list1->next;
                
            }
            else{
                current->next=list2;
                list2=list2->next;
                   
            }
            current=current->next;
    
        }
        if(list1==NULL){
            current->next=list2;
        }
        else if (list2==NULL){
            current->next=list1;
            }
        return head->next;

        
    }
};