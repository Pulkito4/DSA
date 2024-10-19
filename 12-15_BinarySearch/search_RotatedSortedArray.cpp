// QUES: https://www.naukri.com/code360/problems/search-in-rotated-sorted-array_1082554?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findPivot(vector<int> &arr, int n)
{
    int s = 0, e = n - 1;

    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    return s;
}

int binarySearch(vector<int> &arr, int s, int e, int target)
{
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

int search(vector<int> &arr, int n, int key)
{
    int pivot = findPivot(arr, n);
    if (key >= arr[pivot] && key <= arr[n - 1])
    {
        // Binary search on line 2
        return binarySearch(arr, pivot, n - 1, key);
    }
    else
    {
        // Binary search on line 1
        return binarySearch(arr, 0, pivot - 1, key);
    }
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int n = arr.size();
    int key = 0;
    printArray(arr);
    cout << key << " found at index: " << search(arr, n, key) << endl;

    return 0;
}