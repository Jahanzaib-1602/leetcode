
    ListNode* reverseLinkedList(ListNode* head)
    {
    if(head == NULL || head->next ==NULL){
        return head;
    }
    ListNode* newhead = reverseLinkedList(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
    }
    ListNode* getkthNode(ListNode* temp , int k)
    {
           k -=1;
        while(temp!=NULL && k>0)
        {
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        //  if (!head || k <= 1) return head;
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while(temp!=NULL){
            ListNode* kthNode = getkthNode(temp,k);
            if(kthNode == NULL)
            {
                if(prevNode) prevNode->next = temp; 
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            ListNode* reversedHead = reverseLinkedList(temp);
            if(temp == head)
            {
                head = kthNode;
            }
            else
            {
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
    return head;
    }
