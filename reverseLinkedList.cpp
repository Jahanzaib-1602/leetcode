// 1st iterative approach
Node* reverseLinkedList(Node * head){
 if(head == NULL || head->next ==NULL){
        return head;
    }
    Node* prev= NULL; 
    Node* curr = head;
    Node* forward = NULL;
    while (curr!=NULL)
    {
        forward=curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// 2nd recursive approach
void reverse(Node* &head , Node* curr , Node *prev){
    // base case 
    if(curr = NULL){
        head = prev;
        return;
    }
    Node* forward = curr ->next;
    reverse(head , forward , curr);
    curr ->next = prev;
}
Node* reverseLinkedList(Node * head){
    Node* curr = head;
    Node* prev= NULL;
    reverse(head , curr , prev);
}
// 3rd recursive approach
Node* reverse1(Node* head){
    if(head == NULL || head->next ==NULL){
        return head;
    }
    Node* newhead = reverse1(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
}
Node* reverseLinkedList(Node * head){
    return reverse1(head)
}

// in all three cases the time complexity is O(N)
// and the space complexity for recursive approach is O(N) cz this is using the space of recursive stack