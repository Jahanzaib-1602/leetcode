

#include <iostream>
using namespace std;

bool checkTarget(int arr[][3],int target,int n , int m){
    for(int i = 0; i<3;i++){
            for(int j = 0; j< 3; j++){
                if(arr[i][j]==target){
                    return 1;
                }
            }
        }
                return 0;
};

void printRowwiseSum(int arr[][3],int n , int m){
            for(int i = 0; i<3;i++){
                int sum = 0;
                    for(int j = 0; j< 3; j++){
                        sum +=arr[i][j];
                    }
                    cout<<sum<<" ";
             }
}
void printColwiseSum(int arr[][3],int n , int m){
            for(int j = 0; j<3;j++){
                int sum = 0;
                    for(int i = 0; i< 3; i++){
                        sum +=arr[i][j];
                    }
                    cout<<sum<<" ";
             }
            
}
int main(){

    int arr[3][3];
    
    cout<<"enter numbers for input"<<endl;
    for(int i = 0; i<3;i++){
            for(int j = 0; j< 3; j++){
                cin>>arr[i][j];
            }
        }

    cout<<"Here is the output for the given input"<<endl;
    for(int i = 0; i<3;i++){
            for(int j = 0; j< 3; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
    }
    int target;
    cout<<"enter the target to check that it is present or not in this array"<<endl;
    cin>>target;
    if(checkTarget(arr,target,3,3)){
            cout<<"element found"<<endl;
    }
    else{
            cout<<"element not found"<<endl;
    };
    
    cout<<"The row-wise sum is "<<endl;
    printRowwiseSum(arr,3,3);
    cout<<endl;
    cout<<"The col-wise sum is "<<endl;
    printColwiseSum(arr,3,3);
};

    