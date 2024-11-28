// if we apply the approach of using to store the node data in the linked list and than comapre it to the linked list and then pops out the values from the stack its okay but it take the space extra for the stack i mean it take O(2N) time complexity and the space complexity of the O(N)
// and the given below algorithm takes the space time complexity of O(2N) but it take the space complexity of O(1)

Node* reverseLinkedList(Node* head){
    if(head == NULL || head->next ==NULL){
        return head;
    }
    Node* newhead = reverseLinkedList(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
}
bool isPalindrome(Node* head){
    if(head == NULL && head->next == NULL) return true;
    // this question is basically solve in three steps the (1) find middle (2) reverse the second portion of the linkedList (3) comparing the first half of the linked list with the second half of the linked list
    // first step is to find the middle of the list and the middle for even linked list is m1 and for odd where the slow pointer exists when the loop breaks
    // so we use here Hare and Tortoise approach
    // so we create two pointers slow and fast and points it to the head
    Node * slow = head; 
    Node * fast = head; 
    while(fast->next != NULL && fast->next->next != NULL)
    // we take this condtion because of the condition head->next->next is for the even linked list and the condition head->next!=NULL for the odd linked list here we stop the linked list bcz of we are on the middle element and might be one more thing is confusing for u the m1 so i explain this by saying that in the even linked list i.e the size of 6 there is 2 middle element node3 and node4 so we have to stop when the slow pointer is on the node3
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // second step is the reverse the second part of the linkedList
    Node* newHead = reverseLinkedList(slow->next);
    Node* first = head;
    Node* second = newHead;
    // third step is comparing the first half of the linked list with the second half of the linked list
    while(second != NULL){
        if(first->data != second->data) 
        {
            reverseLinkedList(newHead);
            return false;
        }
        else
        {
            first = first->next;
            second = second->next;
        }
    }
    reverseLinkedList(newHead);
    return true;
}  