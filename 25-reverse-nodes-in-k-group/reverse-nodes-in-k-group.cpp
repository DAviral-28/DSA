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
        temp1->next=nullptr;
        while(temp2!=nullptr)
        {
            ListNode* temp3=temp2->next;
            temp2->next=temp1;
            temp1=temp2;
            temp2=temp3;
        }
        return temp1;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k==1)
        return head;
        int c=1;
        ListNode* temp=head;
        ListNode* prevTail = nullptr;
        while(temp!=nullptr)
        {
        ListNode* beg=temp;
        while(temp!=nullptr && c<k)
        {
            temp=temp->next;
            c++;
        }
        if(temp==nullptr)
        {   
            if(prevTail)
            prevTail->next=beg;
            return head;
        }
        ListNode* end=temp->next;
        temp->next=nullptr;
        ListNode* prev=rev(beg);
        if(prevTail==nullptr)
        head=prev;
        else
        prevTail->next=prev;
        beg->next=end;
        prevTail=beg;
        temp=end;
        c=1;
        }
        return head;
    }
};