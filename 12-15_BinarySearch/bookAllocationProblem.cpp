// QUES : https://www.naukri.com/code360/problems/ayush-and-ninja-test_1097574?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
// similar/same ques : https://www.naukri.com/code360/problems/ayush-and-ninja-test_1097574?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
// similar/same ques : https://leetcode.com/problems/split-array-largest-sum/description/
// similar/same ques : https://leetcode.com/problems/fair-distribution-of-cookies/description/
// similar/same ques : https://www.naukri.com/code360/problems/painter's-partition-problem_1089557?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
// similar/same ques : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

#include <bits/stdc++.h>
using namespace std;

bool isPossibleSoln(vector<int> &arr, int n, int m, int mid)
{
    int studentCount = 1;   
    int pagesSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesSum + arr[i] <= mid)
        {
            pagesSum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pagesSum = arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> &arr, int n, int m)
{
    int s = 0;
    int e = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;
    if (m > n)
    {
        return -1;
    }
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isPossibleSoln(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{

    vector<int> arr = {12, 34, 67, 90};
    int n = 4;
    int m = 2;
    cout << allocateBooks(arr, n, m) << endl;
    return 0;
}