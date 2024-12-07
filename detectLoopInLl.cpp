
// first apprach
// using a map to store in the key values pair
// time complexity=O(NlogN)   and space complexity = O(N)

map<Node* , int> myMap;
Node* temp = head;
while(temp!=NULL){
    if(myMap.find(temp)!=myMap.end())
        return true;
    myMap[temp]=1;
    temp = temp->next;
}
return false;



// second approach 
// time complexity=O(N)   and space complexity = O(1)
//  Tortoise and hare approach

ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow ==  head){
                return true;
            }
        }
        return false;