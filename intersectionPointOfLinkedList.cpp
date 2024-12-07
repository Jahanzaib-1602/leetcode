

// 2nd approach
/* i have to make the length of the longer LinkedList equal to the shorter Linkedlist so first step is to count the length of the both linkedlist
so i have to minus the shorted linked list from the longer linkedList length so let suppose in this example the first linked list is of the length of 5 it is shorter linkedlist and the other linkedlist is of the length of 7 it is longer linked list so minus the lenght of the shorted linkedlist from the length of the longer linkedlist so d = 7-5 = 2
so now take a pointer on the longer linkedlist and moves it d step now the lenght of the both linkedlist is equal than do a simultaneously movement till both linked list share a same node 
*/

collisionPoint(Node* t1 ,Node* t2,int d)  // here t1 is the smaller linkedlist head and t2 is the larger linkedlist head
{
    while(d)   // assuimg N2 is greater than N1 than it taking O(N2-N1)
    {
        d--;
        t2 = t2->next;
    }
    while(t1!=t2)   //O(N1)
    {
        t1 = t1->next;
        t2 = t2->next;
    }
    return t1; // we return either t1 or t2 because this is the colliding point of both linkedlist
}
Node* findIntersection(Node* head1, Node* head2) {
    Node* t1 = head1;
    Node* t2 = head2;
    int N1 = 0, N2 = 0;
    while(t1 !=NULL)  // this loop taking O(N1)
    {
        N1++;
        t1= t1->next; 
    }
  
    while(t2 !=NULL)    // this loop taking O(N2)
    {
        N2++;
        t2= t2->next; 
    }
    if(N1<N2)
    {
        return collisionPoint(head1, head2,N2-N1) // assuming that n1 is smaller linkedlist and n2 is greater linkedlist
    }
    else{
        return collisionPoint(head2, head1,N1-N2) // assuming that n2 is smaller linkedlist and n1 is greater linkedlist

    }    
}

// so its time complexity becomes O(N1) + O(N2) + O(N2-N1) + O(N1)
// its becomes O(N1 + 2N2)
// and space complexity is constant it is O(1)




// 3rd approach 
// while traversing any pointer if goes to null than it goes to the opposite linkedList head and when they meet at the same node than stops traversal and return it 
    Node *getIntersectionNode(Node *headA, Node *headB) {
            if(headA == NULL || headB == NULL) return NULL; 
            Node* temp1 = headA;
            Node* temp2 = headB;
            while(temp1 != temp2)
            {
                temp1 = temp1->next;
                temp2 = temp2->next;

                if(temp1 == temp2 ) return temp1;

                if(temp1 == NULL) temp1 = headB;
                if(temp2 == NULL) temp2 = headA;
            }
            return temp1;
    }
};
// its take the time complexity of O(N1 + N2)
// and space complexity is O(1)