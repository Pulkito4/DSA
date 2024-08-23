#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

//pivot element here means that element for which the sum of all elements to its left is equal to the sum of all elements to its right
int pivotIndex(vector<int>& nums) {
        int rsum=accumulate(nums.begin(),nums.end(),0);
        int lsum=0;
        for(int i=0;i<nums.size();i++){
            rsum-=nums[i];
            if(lsum==rsum){
                return i;
            }
            lsum+=nums[i];
        }
        return -1;
    }