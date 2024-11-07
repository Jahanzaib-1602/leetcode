#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        
        cout<<"memory is free for node with data "<<value<<endl;
    }
};
// insert at head 
// why we take head as a reference? bcz of i do not want to make another copy i want to change the original linked list so we take head as a reference 

void insertAtHead(Node* &head , int d){
    // create a new node
    Node* temp = new Node(d);
    temp->next= head;
    head = temp;
}
// Insert at Tail
void insertAtTail(Node* &tail , int d){
     // create a new node
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}
void insertAtPosition(Node* &tail , Node* &head , int position , int d){
    // if we have to insert at the very first position than we have to handle it in this way
    if (position == 1)
    {
        insertAtHead(head , d);
        return;
    }
    
    // first of all made the temp node for traversal and points it to the head
    Node* temp = head;
    int cnt = 1;
    while(cnt< position - 1){
        temp = temp->next;
        cnt++;
    }
    // insert at last position
    if(temp->next==NULL){
        insertAtTail(tail , d);
        return;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp ->next = nodeToInsert;
}
// for deletion
void deleteNode(int position ,Node *&tail, Node* & head){
    // delete first node
    if(position == 1){
        Node* temp = head;
        head = head->next;
        // memory free
        temp->next  = NULL;
        delete temp;
    }
    else{
        // deleting any middle or last node
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while (cnt<position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        // placing the tail to the right position
        if (prev->next == NULL)
        {
            tail = prev;
        }
    }
}
// for printing
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next; 
    }
    cout<<endl;
}
int main(){ 
    Node* node1 = new Node(10);
    // cout<< node1->data<<endl;
    // cout<< node1->next<<endl; 

    Node* head = node1;  
    Node* tail = node1;  
    print(head);
    insertAtTail(tail , 12);
    print(head);
    insertAtTail(tail , 15);
    print(head);
    insertAtPosition(tail , head , 4 ,13); 
    print(head);
    cout<<"the data of head is : "<<head->data<<endl;
    cout<<"the data of tail is : "<<tail->data<<endl;

    deleteNode(4 , tail ,head);
    print(head);
    cout<<"the data of head is : "<<head->data<<endl;
    cout<<"the data of tail is : "<<tail->data<<endl;
}