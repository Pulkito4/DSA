// QUES: https://www.naukri.com/code360/problems/sort-0-1_624379?leftPanelTabValue=SOLUTION

#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void sort01(int *arr, int n)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        while (arr[low] == 0)
        {
            low++;
        }
        while (arr[high] == 1)
        {
            high--;
        }
        if (low < high)
        { // last possible case : arr[low] = 1 and arr[high] = 0
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }
}

int main()
{
    int arr[7] = {0, 1, 1, 0, 1, 0, 1};
    int n = 7;
    cout << "Original array" << endl;
    printArray(arr, n);
    cout << endl;
    sort01(arr, n);
    cout << "Sorted array" << endl;
    printArray(arr, n);

    return 0;
}