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
    struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;   // min-heap
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(int i=0;i<k;i++)
        {
            if(lists[i])
            q.push(lists[i]);
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(!q.empty())
        {
            ListNode* p=q.top();
            q.pop();
            temp->next=p;
            if(p->next)
            q.push(p->next);
            temp=temp->next;
        }
        return dummy->next;
    }
};