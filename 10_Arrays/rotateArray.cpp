// QUES: https://leetcode.com/problems/rotate-array/

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = nums[i];
    }
    nums = temp;
}

void printArray(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    cout << "Original Array: ";
    printArray(nums);
    rotate(nums, k);
    cout << "Rotated Array: ";
    printArray(nums);

    return 0;
}