// QUES: https://www.naukri.com/code360/problems/occurrence-of-x-in-a-sorted-array_630456?leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h>

using namespace std;

int firstOcc(vector<int> arr, int n, int key)
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

int lastOcc(vector<int> arr, int n, int key)
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

int count(vector<int> &arr, int n, int x)
{
    int first = firstOcc(arr, n, x);
    if (first == -1)
    {
        return 0;
    }
    int last = lastOcc(arr, n, x);
    return (last - first + 1);
}

int main()
{
    vector<int> v = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int x = 2;
    cout << "Total number of occurences of " << x << " are: " << count(v, v.size(), x);

    return 0;
}
