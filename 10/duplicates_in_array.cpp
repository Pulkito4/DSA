// Ques: https://www.naukri.com/code360/problems/duplicate-in-array_893397?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1

#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH
// Time Complexity: O(n^2)
int findDupicate(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
            {
                return arr[i];
            }
        }
    }
    return -1;
}


// XOR APPROACH
// Time Complexity: O(n)

int find_duplicate(vector<int> &arr){
    int duplicate =0;

    //XORing all the array elements
    for(int i=0; i<arr.size(); i++){
        duplicate = duplicate ^ arr[i];
    }

    //XORing all the elements from 1 to n
    for(int i=1; i<arr.size(); i++){
        duplicate = duplicate ^ i;
    }
    return duplicate;

}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 5};
    cout << "Duplicate element is: "<<findDupicate(arr)<<endl;

    cout << "Duplicate element is: "<<find_duplicate(arr)<<endl;

    return 0;
}