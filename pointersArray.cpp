#include <iostream>
using namespace std;

int main(){
    int arr[10]={10,20,30};
    cout<<"address of first memory block is  " << arr <<endl; 
    cout<<"first element in the array is "<< arr[0] <<endl;
    cout<<"address of first memory block is  " << &arr[0] <<endl; 
    cout<<"first element in the array is "<< *arr <<endl;
    cout<<"to add the 1 number in the first element of an array  "<< *arr + 1<<endl;
    cout<<"jump to the first index of an array and then print its number "<< *(arr + 1)<<endl;
    

    // arr[i] = *(arr+i)    and it can also be written in the same way   i[arr]=*(i+arr)

    int i = 2;
    cout << i[arr]<<endl;

    //use of sizeof method
    // The size of an int block is 4 byte and when the pointer is made than its size is 8 byte

    int temp[10]={1,2};
    cout<<sizeof(temp)<<endl;  // 10*4  40byte
    cout<<sizeof(*temp)<<endl; // the size of first location i.e the size of the value of 1 is 4 byte
    cout<<sizeof(&temp)<<endl; // it is storing the address of temp so its size is 8 byte

    int *ptr = &temp[0];
    cout<<sizeof(ptr)<<endl;
    cout<<sizeof(*ptr)<<endl;
    cout<<sizeof(&ptr)<<endl;
     

    //  & 

    int a[20]={11,12,13,14,15};
    cout<<&a[0]<<endl;

    int *p = &a[0];
    cout<<p<<endl;     // prints the address of a
    cout<<*p<<endl;     // prints the value at p 
    cout<<&p<<endl;  // prints its own address
     

    // the content of the symbol table cannot be changed

    int arr1[10];

    //error because the content of the symbol table cannot be changed
    // arr1 = arr1 + 1;

    int *pointer =&arr1[0];
    cout<<pointer<<endl;
    pointer = pointer + 1;
    cout<<pointer<<endl;
    
}
