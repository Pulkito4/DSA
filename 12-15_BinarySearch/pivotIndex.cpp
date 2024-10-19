//QUES: https://leetcode.com/problems/find-pivot-index/
// Pivot index is the index where the sum of all elements to the left of the index is equal to the sum of all elements to the right of the index.

#include <bits/stdc++.h>
#include <vector>

using namespace std;

void printArray(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int pivotIndex(vector<int> &nums){
    int lsum=0;
    int rsum=accumulate(nums.begin(), nums.end(), 0);
    for(int i =0 ; i<nums.size(); i++){
        rsum-=nums[i];
        if(lsum==rsum){
            return i;
        }
        lsum+=nums[i];
    }
    return -1;
}


int main (){
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    printArray(nums);
    cout<<"Pivot index is: "<<pivotIndex(nums)<<endl;

    return 0;
}