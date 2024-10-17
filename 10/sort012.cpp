// QUES: https://www.naukri.com/code360/problems/sort-0-1-2_631055?source=youtube&campaign=LoveBabbar_Codestudiovideo1&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudiovideo1&leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sort012(int *arr, int n){
    int low= 0, mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main (){
    int arr[5] = {0, 2, 1, 2, 0};
    int n = 5;
    cout<<"Original array"<<endl;
    printArray(arr,n);
    cout<<"Sorted array"<<endl;
    sort012(arr,n);
    printArray(arr,n);

    return 0;
}