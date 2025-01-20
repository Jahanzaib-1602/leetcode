struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

Node * findTail(Node* head){  // O(N)
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    return tail;
}
vector<pair<int, int>> findPairsWithSum(Node* head, int sum) { // O(N)
    vector<pair<int, int>> result;
    Node* left = head;
    Node* right = findTail(head);
    if(head == NULL) return result;


    while (left->val < right->val) {
            if (left->val + right->val == sum) {
                result.push_back({left->val, right->val});
                left = left->next;
                right = right->next;
            }
            else if(left->val + right->val < sum){
                left = left->next;
            }
            else{
                right = right->prev;
            }
        }
       

    return result;
}
// so its total time compleixty becomes O(2N)  that at the end becomes O(N) becuase 2 is constant value and the space comlexity is always O(1)