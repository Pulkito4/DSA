// QUES: https://leetcode.com/problems/move-zeroes/description/

#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int nonZeroPos = 0;

    for (int j = 0; j < nums.size(); j++)
    {

        if (nums[j] != 0)
        {
            swap(nums[j], nums[nonZeroPos]);
            nonZeroPos++;
        }
    }
}

void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> nums = {0, 1, 0, 3, 12};
    cout << "Before Moving: ";
    printArray(nums);
    moveZeroes(nums);
    cout << "After Moving: ";
    printArray(nums);

    return 0;
}