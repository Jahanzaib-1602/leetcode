Node<int> sortTwoLists(Node<int>* list1 ,Node<int>* list2){
    Node<int>* t1 = list1;
    Node<int>* t2 = list2;
    Node<int>* dummyNode = new Node<int>(-1);
    Node<int>* temp =  dummyNode;
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
    return dummyNode->next // it is actually a new head;
}
