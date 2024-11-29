// this is  done by using the iterative approach but in this approach the time complexity will be O(3N) it is not an optimal apprach and the space complexity is constant i.e O(1);
// the pesudo code for this apprach is given below
// it is done in three steps first step is to reverse the linkedList bcz  let suupose the linkedList is 2->5->9 and we have to add the 1 in the 9 first not in the 2 so we have to reverse the linkedList
Node* reverse(Node* head){
    if(head == NULL || head->next ==NULL){
        return head;
    }
    Node* newhead = reverse(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
}
head = reverse(head);
temp = head; 
carry = 1;
// now we have the reverse linkedList i meant 9->5->2->NULL and now have to traverse at the end of the linkedList and add the 1 in all the data value of the linkedList nodes so
while(temp!=NULL)
{
    temp->data = temp->data + carry;
    if(temp->data < 10)
    {
        carry = 0;
        break;
    }
    else
    {
        temp->data = 0;
        carry = 1;
    }
    temp = temp->next;
}
// now the third step is again reverse the linkedList
// but for the if the linkedList is let suupose 9->9->9->9->NULL; then it after add 1 it leaves 1 at the end now for this situation
if(carry == 1)
{
    Node * newNode = new Node(1);
    head = reverse(head); // this is for reversing the linkedlist again
    newNode->next = head;
    head = newNode;
    return newNode;
}
else{
    head = reverse(head); // this is for reversing the linkedlist again
    return head;
}

// this is the iterative approach for add 1 into the linked list