Node* removeNthFromEnd(Node* head, int n) {
        Node* fast = head;
        Node* slow = head;
        for (int i = 0 ; i<n ; i++){
            fast = fast->next;
        }
        // the below case is when the n is the head 
        if(fast == NULL) return head->next;
        // delete the n node
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        Node* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
}

