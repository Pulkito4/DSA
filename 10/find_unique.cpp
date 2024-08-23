// QUES : https://www.naukri.com/code360/problems/find-unique_625159?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1

#include <iostream>
using namespace std;


// BRUTE FORCE APPROACH
int find_unique(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {

        int j;
        for (j = 0; j < size; j++)
        {
            if (i != j && arr[i] == arr[j])
            {
                break;
            }
        }
        if (j == size)
        {
            return arr[i];
        }
    }
}


// XOR APPROACH  
int findUnique(int *arr, int size)
{
    int ans=0;
    for(int i=0; i<size; i++){
        ans = ans^arr[i];
    }
    return ans;
}

int main()
{
    int arr[] = {2, 3, 4, 3, 2, 4, 6, 7, 7};
    cout << find_unique(arr, 9) << endl;

    cout << findUnique(arr, 9) << endl;
    return 0;
}