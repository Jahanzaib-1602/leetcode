class Solution {
public:
    int getLength(ListNode* head){
        int len = 0;
        while(head!=NULL){
            head = head -> next;
            len++;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {
        int len = getLength(head);
        int ans = (len/2);
        ListNode* temp = head;
        int cnt = 0;
        while(cnt<ans){
            temp = temp->next;
            cnt++;
        }
        return temp;
    }
};
// time complexity of both approach is O(N)
//2nd approach
Node* middleNode(Node* head){
    // one node or no node
    if(head == NULL || head->next ==NULL){
        return head;
    }
    // 2 node 
    if(head->next->next ==NULL){
        return head->next;
    }
    Node* slow = head;
    Node* fast = head->next;
    while (fast!=NULL)
    {
        fast= fast->next;
        if(fast!=NULL){
            fast= fast->next;
        }
        slow = slow->next;
    }
    return slow;
}