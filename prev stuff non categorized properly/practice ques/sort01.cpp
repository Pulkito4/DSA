#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    cout<<"ARRAY: \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


//2 pointer approach
void sort01(int arr[],int n){
    int left=0, right=n-1;
    while(left<right){
        while(arr[left]==0 && left<right){
            left++;
        }

        while(arr[right]==1 && left<right){
            right--;
        }
        if(left<right){
            swap(arr[left],arr[right]);
            left++;
            right--;
        }

    }
}

void sortOptimized(int arr[],int n){
    int left=0;
    int right=n-1;
    while(left<=right){
        if(arr[left]==0){
            left++;
        }
        else{
            swap(arr[right],arr[left]);
            right--;
        }
    }
}

int main(){
    int arr1[8]={1,1,0,0,0,0,1,0};
    sort01(arr1,8);
    printArray(arr1,8);
    cout<<endl;
    int arr2[10]={1,1,0,1,1,0,0,0,1,0};
    sortOptimized(arr2,10);
    printArray(arr2,10);
    return 0;
}