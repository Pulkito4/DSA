/*QUES: given an array of size N where N=2M+1  (implies n is odd )
now in the array M numbers are present twice and one number is present 1 time 
so find that unique element/number in the array*/


/*SOLUTION: we can use XOR(^) gate here
we know a^0=a   and a^a=0  
therefore   0^0^0^4^0^0= 4 */
#include<iostream>
using namespace std;

int main (){
    int n;
    cout<<"Enter size of array(MUST BE ODD): ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int unique=0;
    for(int i=0;i<n;i++){
        unique=unique^arr[i];
    } 
    cout<<"Unique element is: "<<unique;
    return 0;
}