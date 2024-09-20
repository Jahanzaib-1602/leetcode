#include<iostream> 
using namespace std;

bool linearSearchRecursion(int arr[],int size,int key){
    //base case
    if(size == 0){
        return false;
    }


    if(arr[0]==key){
        return true;
    }
    return linearSearchRecursion(arr+1,size-1,key);

}

int main(){
    cout<<"Enter the size of an array"<<endl;
    int size;
    cin>>size;
    cout<<"Enter the value of an array"<<endl;
    int arr[size];
    for(int i = 0;i<size ; i++){
        cin>>arr[i];
    }
    cout<<"Enter the value of the key"<<endl;
    int key;
    cin>>key;

    bool result = linearSearchRecursion(arr,size,key);

    if (result==true){
        cout<<"key found"<<endl;
    } 
    else{
        cout<<"key not found"<<endl;

    }
}