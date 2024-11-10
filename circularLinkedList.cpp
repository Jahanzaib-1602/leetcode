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
         if(this->next!=NULL){
                delete next;
                this->next = NULL;
            }
        cout<<"memory is free for node with data "<<value<<endl;
    }
};
void insertionNode(Node* &tail , int element , int d){
    // empty list when there is no node present in the linked list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next= newNode;       
    }
    else{
        //non-empty list
        // assuming that the element is present in the linked list
        Node* curr = tail;
        while (curr->data != element)
        {
            curr=curr->next;
        }
        // element found and current is representing element node 
        Node* temp = new Node(d);
        temp -> next = curr->next;
        curr->next = temp;
    }
}
void print(Node* tail){
    Node* temp = tail;

    if(tail == NULL){ 
        cout<<"List is empty"<<endl;
        return;
    }
    do
    {
        cout<<tail->data<<" ";
        tail= tail->next;
    } while (tail!=temp);
    cout<<endl;
}
void deleteNode(Node* &tail , int value){
    // empty list
    if(tail == NULL){
        cout<<"List is empty , plz check again"<<endl;
        return;
    }
    else{
        //non-empty and assume the value is present in the linked list
        Node* prev = tail;
        Node* curr= prev->next;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        // 1 Node
        if(curr==prev){
            tail=NULL;
        }
        // If the node to be deleted is tail, update tail
        // >=2 Nodes
        if (tail == curr) {
            tail = prev;
        }
        curr->next= NULL;
        delete curr;
    }
}
string getTailData(Node* tail) {
    if (tail == NULL) {
        return "Nothing present in the linked list";
    } else {
        return "The data part of the tail is " + to_string(tail->data);
    }
}
int main(){
    Node* tail = NULL;
    insertionNode(tail , 100 , 3);
    print(tail);
    cout << getTailData(tail) << endl;
    insertionNode(tail , 3 , 5);
    print(tail);
    cout<<"the data part of the tail is "<<tail->data<<endl;
    insertionNode(tail , 5 , 7);
    print(tail);
    cout<<"the data part of the tail is "<<tail->data<<endl;
    insertionNode(tail , 7 , 9);
    print(tail);
    cout<<"the data part of the tail is "<<tail->data<<endl;
    insertionNode(tail , 3 , 4);
    print(tail);
    cout<<"the data part of the tail is "<<tail->data<<endl;
    deleteNode(tail,3);
    print(tail);
    cout << getTailData(tail) << endl;
    return 0;
}