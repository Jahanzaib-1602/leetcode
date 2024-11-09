#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* prev;
        Node* next;

        //constructor
        Node(int d){
            this->data = d;
            this->next=NULL;
            this->prev=NULL;
        }
        ~Node(){
            int value = this->data;
            if(this->next!=NULL){
                delete next;
                this->next = NULL;
            }
            cout<<" memory is free for node with data "<<value<<endl;
        }
};
// for traversal
void print(Node* &head){
    Node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
// for printing the length of the linkedlist
int getLength(Node* &head){
    Node* temp = head;
    int length = 0;
    while (temp!=NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}
void insertAtHead(Node* &head , int d){
    Node* temp = new Node(d);
    temp->next= head;
    head->prev = temp;
    head = temp;
}
void insertAtTail(Node* &tail , int d){
    Node* temp = new Node(d);
    tail->next= temp;
    temp->prev = tail ;
    tail = temp;
}
void insertAtPosition(Node* &tail , Node* &head , int position , int d){
    if(position == 1){
        insertAtHead(head , d);
        return;
    }
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
    temp ->next->prev = nodeToInsert;
    temp ->next = nodeToInsert;
    nodeToInsert->prev=temp;

}
void deleteNode(int position ,Node *&tail, Node* & head){
    // delete first node
    if(position == 1){
        Node* temp = head;
        temp->next->prev=NULL;
        head = temp->next; 
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
        curr->prev = NULL;
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
int main(){
    Node* node1 = new Node(10);  
    Node* head = node1;
    Node* tail = node1;
    print(head);
    // cout<<"the length of the linked list is "<<getLength(head);
    insertAtHead(head , 11);
    print(head);
    insertAtHead(head , 12);
    print(head);
    insertAtTail(tail,25);
    print(head);
    insertAtPosition(tail , head , 1 ,13); 
    print(head);
    insertAtPosition(tail , head , 3 ,111); 
    print(head);
    insertAtPosition(tail , head , 7 ,211); 
    print(head);
    deleteNode(7,tail,head);
    print(head);
    cout<<"head is "<<head->data<<endl;
    cout<<"tail is "<<tail->data<<endl;

}