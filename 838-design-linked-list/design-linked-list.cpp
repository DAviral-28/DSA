class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;

        ListNode(int x) {
            val = x;
            next = nullptr;
        }
    };

    ListNode* head;

    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        ListNode* temp=head;
        while(temp!=nullptr && index>0)
        {
            index--;
            temp=temp->next;
        }
        if(temp==nullptr)
        return -1;
        return temp->val;
    }
    
    void addAtHead(int val) {
        ListNode* temp=new ListNode(val);
        temp->next=head;
        head=temp;
    }
    
    void addAtTail(int val) {
        ListNode* temp=head;
        
        ListNode* nn=new ListNode(val);
        if(temp==nullptr)
        {
            head=nn;
            return ;
        }
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=nn;
    }
    
    void addAtIndex(int index, int val) {
        ListNode* nn=new ListNode(val);
        if(index==0)
        {
            nn->next=head;
            head=nn;
            return ;
        }
        ListNode* temp=head;
        while(temp!=nullptr && index>1)
        {
            index--;
            temp=temp->next;
        }
        if(index!=1 || temp==nullptr)
        return;
        nn->next=temp->next;
        temp->next=nn;
    }
    
    void deleteAtIndex(int index) {
         ListNode *temp=head;
        if(index==0)
        {
            if(head==nullptr)
            return;
            head=head->next;
            delete(temp);
            return;
        }
        while(temp!=nullptr && index>1)
        {
            index--;
            temp=temp->next;
        }
        if(index!=1 || temp==nullptr)
        return;
        ListNode* t=temp;
            t=t->next;
        if(t!=nullptr)
        {
            temp->next=t->next;
            delete(t);
        }

    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */