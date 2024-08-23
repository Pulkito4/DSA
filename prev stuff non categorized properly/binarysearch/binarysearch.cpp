#include<iostream>
using namespace std;

//TIME COMPLEXITY :  O(log n)   // n is the size of array
int binary_search(int *arr, int num, int array_size){
    // the following is assuming that the array sorted is already sorted 
    int beg=0;
    int end=array_size;
    int mid;
    while(beg<=end){
        // mid=(end+beg)/2;   
        // the logic for mid is correct but this can cause an error when the beg and end both are the max values of integer i. 2^32 -1
        // to solve this exception case we can rearrange the statement as:
        mid= beg + ((end - beg)/2);
        if(arr[mid]>num){
            end=mid-1;
        }else if(arr[mid]<num){
            beg=mid+1;
        }else{
            return mid;
        }
    }
return -1;   //when value not found i.e not present
}
