
// first apprach
// using a map to store in the key values pair
// time complexity=O(NlogN)   and space complexity = O(N)

map<Node* , int> myMap;
Node* temp = head;
while(temp!=NULL){
    if(myMap.find(temp)!=myMap.end())
    {
       value = myMap[temp];
       return timer-value;
    } 
    myMap[temp]= timer;
    timer++;
    temp = temp->next;
}
return 0;


// second approach 
// time complexity=O(N)   and space complexity = O(1)
//  Tortoise and hare approach
int lenghtOfLoop(Node* head){
        Node* slow = head;
        Node* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow ==  head){
                return findLength(slow , fast);
            }
        }
        return 0;
}
int findLength(Node* slow ,Node* fast){
    int cnt = 1; fast = fast->next;
    while(slow! = fast){
        cnt++;
        fast = fast->next;
    } 
    return cnt;
}