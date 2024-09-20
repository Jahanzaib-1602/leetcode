#include<iostream> 
using namespace std;

void print(int arr[],int s ,int e ){
    for(int i = s;i<=e;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool binarySearchRecursion(int arr[],int s,int e, int key){
    cout<<endl;
    print(arr,s,e);
    int mid = s + (e-s)/2;
    cout<<"The value of arr mid is "<<arr[mid]<<endl;
    //there are two base cases in this question 
    //first base case
    if(s>e){
        return false;
    }
    //second base case
    if(arr[mid]==key){
        return true;
    }
    
    if(arr[mid]<key){
        // go to the right part
        return binarySearchRecursion(arr,mid+1,e,key);
    }
    else{
                // go to the left part
        return binarySearchRecursion(arr,s,mid-1,key);
    }
}

int main(){
    int arr[5]={2,3,5,6,7};
    int size = 5;

    bool result = binarySearchRecursion(arr,0,4,4);

    if (result==true){
        cout<<"key found"<<endl;
    } 
    else{
        cout<<"key not found"<<endl;

    }
}