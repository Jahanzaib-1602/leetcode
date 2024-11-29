// this is the recursive approach for adding one into the LinkedList because in the recursive approach backtracking comes into the picture so we don't need to reveser the linked list that takes an extra time compelxity of O(N) so we use recursive approach 
int addHelper(Node* temp){
    //base case
    if(temp == NULL){
        return 1;
    }
    int carry = addHelper(temp->next);
    temp->data = temp->data + carry;
    if(temp->data < 10) 
    {
        return 0;
    }
    else{
        temp->data = 0;
        return 1;
    }
}
Node* addOne(Node* head)
{
    int carry = addHelper(head);
    if(carry == 1)
    {
        Node * newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    return newNode;
}
this approach takes time complexity of  O(N) but it takes an extra space of recursivestack so its space complexity becomes O(N)