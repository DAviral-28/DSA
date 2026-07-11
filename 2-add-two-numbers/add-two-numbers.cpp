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
            ListNode* temp3=temp2->next;
            temp2->next=temp1;
            temp1=temp2;
            temp2=temp3;
        }
        return temp1;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr)
        return l2;
        else if(l2==nullptr)
        return l1;
        ListNode* t1=l1;
        ListNode* t2=l2;
        int sum=0;
        int carry=0;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(t1!=nullptr || t2!=nullptr)
        {
            if(t1!=nullptr)
            sum+=t1->val;
            if(t2!=nullptr)
            sum+=t2->val;
            sum+=carry;
            if(sum>=10)
            {
                sum=sum%10;
                carry=1;
            }
            else
            carry=0;
            ListNode* nn=new ListNode(sum);
            sum=0;
            temp->next=nn;
            temp=nn;
            if(t1)
            t1=t1->next;
            if(t2)
            t2=t2->next;
        }
        if(carry==1)
        {
            ListNode* n=new ListNode(1);
            temp->next=n;
        }
        return dummy->next;
    }
};