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
    ListNode *findmid(ListNode *head)
    {
        if(head==nullptr || head->next==nullptr)
        return head;
        ListNode* temp1=head;
        ListNode* temp2=head->next;
        while(temp2!=nullptr && temp2->next!=nullptr)
        {
            temp1=temp1->next;
            temp2=temp2->next->next;
        }
        return temp1;
    }
    ListNode* merge(ListNode* low,ListNode* high)
    {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(low!=nullptr && high!=nullptr)
        {
            if(low->val<=high->val)
            {
                temp->next=low;
                temp=low;
                low=low->next;
            }
            else
            {
                temp->next=high;
                temp=high;
                high=high->next;
            }
        }
        if(low)
        temp->next=low;
        else
        temp->next=high;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        return head;
        ListNode *mid=findmid(head);
        ListNode* low=head;
        ListNode* high=mid->next;
        mid->next=nullptr;
        low=sortList(head);
        high=sortList(high);
        return merge(low,high);
    }
};