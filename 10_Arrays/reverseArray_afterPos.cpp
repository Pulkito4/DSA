// QUES: https://www.naukri.com/code360/problems/reverse-the-array_1262298?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio3

#include <bits/stdc++.h>
using namespace std;


void reverseArray(vector<int> &arr , int m) {
  int s=m+1;
  int e = arr.size()-1;
  while(s<=e){
      swap(arr[s],arr[e]);
      s++;
      e--;
  }
}

void printArray(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main (){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int m = 3;
    cout<<"Original Array: ";
    printArray(arr);
    reverseArray(arr,m);
    cout<<"Array after reversing: ";
    printArray(arr);
    return 0;
}