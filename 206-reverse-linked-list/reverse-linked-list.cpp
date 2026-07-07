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
    ListNode* rs(ListNode* temp1,ListNode* temp2)
    {
        if(temp2==nullptr)
        return temp1;
        ListNode* temp3=temp2->next;
        temp2->next=temp1;
        return rs(temp2,temp3);
    }
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        return head;
        ListNode* temp1=head;
        ListNode* temp2=head->next;
        temp1->next=nullptr;
       head= rs(temp1,temp2);
        return head;
    }
};