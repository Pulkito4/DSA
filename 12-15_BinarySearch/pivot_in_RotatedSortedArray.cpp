#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int pivotRotatedSorted(int *arr, int n){
    int s=0, e=n-1;

    while(s<e){
        int mid = s+ (e-s)/2;
        if(arr[mid]>=arr[0]){
            s = mid+1;
        }
        else{
            e=mid;
        }
    }
    return s;
}

int main(){
    int arr[] = {4,5,6,7,0,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Pivot is: "<<pivotRotatedSorted(arr, n)<<endl;

    return 0;
}