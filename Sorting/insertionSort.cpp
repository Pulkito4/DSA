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

void insertionSort(int n, vector<int> &arr)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        // because 0th element ko initally as a single element sorted maan liya
        int temp = arr[i];
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                // shift
                arr[j + 1] = arr[j];
            }
            else
            {
                // ruk jao because usse pehele wale elements already sorted/smaller h so no need to compare
                break;
            }
        }
        arr[j + 1] = temp;
    }
}

// insertion sort using while loop 
void insertionSort1(int n, vector<int> &arr)
{
    for (int i = 1; i < n; i++)
        // because 0th element ko initally as a single element sorted maan liya
    {
        int j = i - 1;
        int temp = arr[i];
        while (j >= 0 && arr[j] > temp)
        {
            // shift
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6};
    int n = arr.size();
    cout << "Before Sorting: ";
    printArray(arr);
    insertionSort(n, arr);
    cout << "After Sorting: ";
    printArray(arr);

    return 0;
}