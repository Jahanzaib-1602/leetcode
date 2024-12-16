// delete all occurances of a key in a double linkedlist
Node* temp = head;
while(temp!=NULL){
    if(temp->val == key)
    {
        if(temp == head)
        {
            head = temp->next;
        }
        Node* nextNode = temp->next;
        Node* prevNode = temp->prev;
        if(nextNode!=NULL) nextNode->prev = prevNode;
        if(prevNode!=NULL) prevNode->next = nextNode;
        free(temp);
        temp = nextNode;
    }
    else
    {
        temp=temp->next;
    }
}
return head;