// QUES: https://www.naukri.com/code360/problems/aggressive-cows_1082559?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

#include <bits/stdc++.h>
using namespace std;

bool isPossibleSoln(vector<int> stalls, int k, int mid)
{
    int cowCount = 1;
    int lastPosofCow = stalls[0];
    for (int i = 0; i < stalls.size(); i++)
    {
        int distance = stalls[i] - lastPosofCow;
        if (distance >= mid)
        {
            cowCount++;
            if (cowCount == k)
            {
                return true;
            }
            lastPosofCow = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int ans = -1;
    int e = stalls[stalls.size() - 1] - stalls[0]; // max distance between any two stalls // because array is sorted
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isPossibleSoln(stalls, k, mid))
        {
            ans = mid;
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
    vector<int> stalls = {4,2,1,3,6};
    int k = 2;
    cout << aggressiveCows(stalls, k) << endl;

    return 0;
}