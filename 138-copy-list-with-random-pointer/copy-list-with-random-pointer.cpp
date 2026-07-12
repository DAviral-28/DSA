/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)
        return head;
        Node* temp=head;
        Node* prev=nullptr;
        Node* q=head;
        while(temp!=nullptr)
        {
            Node* nn=new Node(temp->val);
            if(prev)
            prev->next=nn;
            else
            head=nn;
            prev=nn;
            temp=temp->next;
        }
        Node* t=q;
        Node* h=head;
        while(h!=nullptr)
        {
            Node* p=t->random;
            Node* tt=q;
            Node* ttt=head;;
            while(tt!=nullptr && tt!=p)
            {
                tt=tt->next;
                ttt=ttt->next;
            }
            h->random=ttt;
            h=h->next;
            t=t->next;
        }
        return head;
    }
};