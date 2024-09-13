
// reference variables are those having same memory but different name

#include <iostream>
using namespace std;


// bad practice because these num and ans are local variables when the  
// function block end , the memory clears and the scop of these variables end 
// it might be possible that u cannot acess the memory
int& func(int a){
    int num = a;
    int& ans = num;
    return ans;
}

void update(int& n){
    n++;
}
int main(){
    int i = 5;
    int& j=i;
    cout<<i<<endl;
    j++;
    cout<<j<<endl;
    cout<<i<<endl;


    int n = 5;
    cout<<"Before "<< n <<endl;
    update(n);
    cout<<"After "<< n <<endl;
    func(n);
 
}
