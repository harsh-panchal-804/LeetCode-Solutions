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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum, carry = 0;
        ListNode *result = nullptr, *temp1 = l1, *temp2 = l2;
        ListNode *temp = result;
        while((temp1 != nullptr) || (temp2 != nullptr))
        {
            sum = 0;
            if(temp1 == nullptr)
            {
                sum = temp2->val + carry;
                temp2 = temp2->next;
            }
            else if(temp2 == nullptr)
            {
                sum = temp1->val + carry;
                temp1 = temp1->next;
            }
            else
            {
                sum = temp1->val + temp2->val + carry;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            carry = 0;
            if(sum > 9)
            {
                carry = 1;
                sum -= 10;
            }
            ListNode *newNode = new ListNode;
            newNode->val = sum;
            newNode->next = nullptr;
            if(result == nullptr)
            {
                result = newNode;
                temp = result;
            }
            else
            {
                temp->next = newNode;
                temp = temp->next;
            }
        }
        if(carry != 0)
        {
            ListNode *newNode = new ListNode;
            newNode->val = carry;
            newNode->next = nullptr;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        return result;
    }
};