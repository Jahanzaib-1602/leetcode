ListNode* findMiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode* mergeTwoLists(ListNode* list1 ,ListNode* list2){
    ListNode* t1 = list1;
    ListNode* t2 = list2;
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp =  dummyNode;
    while(t1 != NULL && t2 != NULL){
        if(t1->val < t2->val){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if(t1)  temp->next = t1;
    else temp->next = t2;
    return dummyNode->next; // it is actually a new head;
}
ListNode* sortList(ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    ListNode* middle = findMiddle(head);
    ListNode* right = middle->next;
    middle->next = NULL;
    ListNode* left = head;

    left = sortList(left);
    right = sortList(right);
    return mergeTwoLists(left , right);

}
