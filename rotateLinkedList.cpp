Node* findLastNode(Node* temp , int k){
    int cnt = 1;
    while(temp != NULL){
        if(cnt == k) return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;
}
Node* rotate(Node* head , int k){
    if(head == NULL || k == 0 ) return head;
    Node* tail = head;
    int len = 1;
    while(tail->next != NULL){
        len++;
        tail= tail->next;
    }
    if(k % len == 0) return head;
    k = k % len;
    tail->next = head;
    NOde* newLastNode = findLastNode(head, len-k);
    head = newLastNode->next;
    newLastNode->next = NULL;
    return head;
}
