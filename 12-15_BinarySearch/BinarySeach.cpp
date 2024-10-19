#include <bits/stdc++.h>

using namespace std;

// NOTE THAT BINARY SEARCH CAN ONLY BE APPLIED ON SORTED ARRAYS  -> O(logn)
int binarySearch(int *arr, int n, int key)
{
    int s = 0, e = n - 1;
    int mid = (s + e) / 2;
    // or mid = s + (e-s)/2  //optimized acc to numerical range

    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            return mid;
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
    return -1;  // element not found
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(int);
    int key = 5;
    cout<<"key found at index: "<<binarySearch(arr, n, key)<<endl;

    return 0;
}