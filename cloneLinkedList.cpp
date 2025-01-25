void insertCopyBetween(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* copy = new Node(temp->val);
        temp->next = copy;
        copy->next = temp->next;
        temp = temp->next->next;
    }
}
void connectRandomPointers(Node* head){
    Node* temp = head;
    while(temp != NULL){
    Node* copyNode = temp->next;
    if(temp->random)
    {
        copyNode->random = temp->random->next;
    }
    else
    {
        copyNode->random = nullptr;
    }
        temp = temp->next->next;
    }
}
Node* copyRandomList(Node* head){
    Node* temp = head;
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    while(temp != NULL)
    {
        res->next = temp->next;
        res = res->next;
        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummyNode->next;
}
Node* cloneLL(Node* head){
    insertCopyBetween(head);
    connectRandomPointers(head);
    return copyRandomList(head);
}