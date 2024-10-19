// QUES: https://www.naukri.com/code360/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

#include <bits/stdc++.h>

using namespace std;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int firstOccurence(int *arr, int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1; // left most occurrence ke liye left side mein aa jao
        }

        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int lastOccurence(int *arr, int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1; // right most occurrence ke liye right side mein aa jao
        }

        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 8, 8, 8, 8, 8, 9};
    int n = sizeof(arr) / sizeof(int);
    int key = 8;
    cout << "First Occurence of key: " << firstOccurence(arr, n, key) << endl;
    cout << "Last Occurence of key: " << lastOccurence(arr, n, key) << endl;
    return 0;
}