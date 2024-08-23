#include<iostream>
using namespace std;

int firstOcc(int arr[], int n, int key){
    int s=0, e=n-1;
    int mid;
    int ans=-1; 
    while(s<=e){
        mid= s+ (e-s)/2;
        if(arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]<key){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}

int lastOcc(int arr[], int n, int key){
    int s=0, e=n-1;
    int mid;
    int ans=-1; 
    while(s<=e){
        mid= s+ (e-s)/2;
        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]<key){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}

int main(){

    int arr[16]={1,2,3,3,3,3,3,3,3,3,3,3,3,3,3,5};
    cout<<"Frist Occurence of 3 is at index: "<<firstOcc(arr,16,3)<<endl;
    cout<<"Last Occurence of 3 is at index: "<<lastOcc(arr,16,3)<<endl;
    return 0;
}

// total no of occurences = last occ - first occ + 1