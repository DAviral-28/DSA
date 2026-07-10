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
    ListNode* rev(ListNode* head)
    {
        if(head==nullptr || head->next==nullptr)
        return head;
        ListNode* temp1=head;
        ListNode* temp2=head->next;
        head->next=nullptr;
        while(temp2!=nullptr)
        {
            ListNode* temp=temp2->next;
            temp2->next=temp1;
            temp1=temp2;
            temp2=temp;
        }
        return temp1;
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        return true;
        if(head->next->next==nullptr)
        {
            if(head->val==head->next->val)
            return true;
            else
            return false;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* sec=rev(slow->next);
        ListNode* ww=sec;
        ListNode* fir=head;
        while(sec!=nullptr)
        {
            if(fir->val!=sec->val)
            return false;
            fir=fir->next;
            sec=sec->next;
        }
        slow->next=rev(ww);
        return true;
        
    }
};