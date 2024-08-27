
// largestSum in 2D Array and gives its row Index

#include <iostream>
#include <climits>
using namespace std;

int largestSum(int arr[][3],int row , int col){
    int maxi= INT_MIN;
    int rowIndex = -1;
    for(int row = 0; row < 3; row++){
        int sum = 0;
        for(int col = 0; col < 3; col++){
            sum +=arr[row][col];
        }
        if(sum>maxi){
            maxi=sum;
            rowIndex=row;
        }
    }
    cout<<"the largest row sum from this array is : "<<maxi<<endl;
    return rowIndex;
}
int main() {
    
    
    int arr[3][3];
    
    cout<<"enter numbers for input"<<endl;
    for(int i = 0; i<3;i++){
            for(int j = 0; j< 3; j++){
                cin>>arr[i][j];
            }
        }

    int n = largestSum(arr,3,3);
    cout<<"the row for this largest sum is : "<<n;
    return 0;
}