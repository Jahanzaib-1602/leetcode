#include <iostream>
using namespace std;
int main()
{
    int rows;
    cout<<"Enter the number of rows"<<endl;
    cin>>rows;
    int cols;
    cout<<"Enter the number of cols"<<endl;
    cin>>cols;
    
    // creation of 2D Array by dynamic memory Allocation
    int** arr = new int*[rows];
    for(int i = 0; i<rows;i++){
        arr[i]= new int[cols];
    }

    // taking input
    for(int i = 0; i<rows;i++){
        for(int j = 0; j<cols; j++){
            cin>>arr[i][j];
        }
    }

    // for output
    for(int i = 0; i<rows;i++){
        for(int j = 0; j<cols; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    // for releasing memory
    for(int i = 0; i<rows;i++){
        delete []arr[i];
    }
    delete []arr;
}