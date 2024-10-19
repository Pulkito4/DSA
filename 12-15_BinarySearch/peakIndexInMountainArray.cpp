//QUES : 

#include <bits/stdc++.h>

using namespace std;

int peakIdx(int *arr, int n){
    int s =0, e = n-1;
    while(s<e){
        int mid = s + (e-s)/2;
        if(arr[mid]<arr[mid+1]){
            s = mid+1;
        }
        else{
            e = mid;
        }
    }
    return s;  // or e
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = arr.size();
    cout<<"peak idx is: "<<peakIdx(arr.data(), n)<<endl;
    cout<<"peak element is: "<<arr[peakIdx(arr.data(), n)]<<endl;
    return 0;
}