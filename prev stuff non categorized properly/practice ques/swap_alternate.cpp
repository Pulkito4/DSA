#include<iostream>
using namespace std;

int main(){
    int arr[100],n;
    cout<<"Enter size of array\n";
    cin>>n;
    cout<<"Enter array elements\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"\nThe array is\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    
    int temp;
    for(int i=0;i<n;i=i+2){
        if(i+1<n){  //checking if the next element lies inside the array or not

            /*temp=arr[i];    this is one way otherwise we just have a inbuilt library swap function 
            arr[i]=arr[i+1];
            arr[i+1]=temp;*/
            swap(arr[i],arr[i+1]);
        }
    }
    cout<<"\n\nSwapping altrenate\nNow the array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}