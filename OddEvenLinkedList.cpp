
if(head ==NULL || head->next ==NULL){
    return head;
}
arr[];
Node* temp = head;
while (temp!=NULL && temp->next !=NULL)
{
    arr.push_back(temp->data);
    temp = temp->next->next;
}
if(temp) arr.push_back(temp->data);
temp = head->next;
while (temp!=NULL && temp->next !=NULL)
{
    arr.push_back(temp->data);
} 
if(temp) arr.push_back(temp->data);
int i = 0;
temp = head;
while(temp!=NULL){
    temp->data = arr[i];
    i++;
    temp = temp->next;
}
return head;

// this is the brute force approach the first while loop takes the O(n/2) time and the very next loop also takes the same time and the last one in which the insertion is done in the linkedlist is done in the O(n) time\
so overall the timecomplexity becomes the O(2N) and the space complexity becomes O(N) bcz we take and extra sapce for arr
// this problem states that we have to segregate the odd and even node i mean first of all odd node comes and than the even one comes and these are stoes in the arr and when out traversal on the whole linked list is complete than we run a loop on that array and stores the element on the linked list in the same manner


 //2nd approach
 ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;

        while(even!=NULL && even->next!=NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
    // its time complexity becomes O(N) and space complexity becomes O(1)