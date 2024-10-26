// QUES: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

bool check(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            count++;
        }
    }
    if (nums[n - 1] > nums[0])
    {
        count++;
    }
    return count <= 1;
}

int main()
{

    vector<int> nums = {3, 4, 5, 1, 2};
    cout << "Original Array: ";
    printArray(nums);
    cout << "Array is rotated and sorted: " << (check(nums)?"True":"False") << endl;
    return 0;
}