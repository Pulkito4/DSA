#include <bits/stdc++.h>
using namespace std;

void printArray (vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// time complexity -> O(n^2) 
void bubbleSort(vector<int>& arr, int n)
{   
    for(int i=1;i<n;i++){
        //for round 1 to n-1
        for(int j=0;j<n-i;j++){
            //process till (n-i)th index
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

// optimization 1: if array is already sorted use a flag to check if any swap is done in the inner loop or not, then break the loop
// time complexity -> worst case: O(n^2) || best case: O(n)
void bubbleSortOpt1(vector<int>& arr, int n)
{   
    for(int i=1;i<n;i++){
        bool flag = false;
        //for round 1 to n-1
        for(int j=0;j<n-i;j++){
            //process till (n-i)th index
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = true;
            }
        }
        if(!flag) break;
    }
}

int main (){
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();
    cout << "Unsorted array: ";
    printArray(arr, n);
    bubbleSortOpt1(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}