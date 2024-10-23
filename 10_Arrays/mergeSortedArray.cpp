// QUES: https://leetcode.com/problems/merge-sorted-array/solutions/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    while (i >= 0)
    {
        nums1[k--] = nums1[i--];
    }

    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
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
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    cout << "Before Merging: ";
    printArray(nums1);
    cout << "After Merging: ";
    merge(nums1, 3, nums2, 3);
    printArray(nums1);
    return 0;
}