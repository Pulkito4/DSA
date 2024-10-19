// QUES: https://www.naukri.com/code360/problems/square-root_893351?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

#include <bits/stdc++.h>
using namespace std;

// if not perfect square then return floor of square root
int squareRoot(int n)
{
    int s = 0, e = n, ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid > n)
        {
            e = mid - 1;
        }
        else
        {
            ans = mid;
            s = mid + 1;
        }
    }
    return ans;
}

// Optimization 1 : because mid*mid might return a integer that is greater than INT_MAX i.e 2^31-1 so we can use long long int
int squareRoot1(int n)
{
    int s = 0, e = n;
    long long int ans = -1;
    while (s <= e)
    {
        long long int mid = s + (e - s) / 2;
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid > n)
        {
            e = mid - 1;
        }
        else
        {
            ans = mid;
            s = mid + 1;
        }
    }
    return ans;
}

// Optimization 2: because we know that mathematically square root of n is always less than or equal to n/2 so we can reduce the search space
// lil bit doubt in this optimization
// int squareRoot2(int n)
// {
//     int s = 0, e = n / 2;
//     long long int ans = -1;
//     while (s <= e)
//     {
//         long long int mid = s + (e - s) / 2;
//         if (mid * mid == n)
//         {
//             return mid;
//         }
//         else if (mid * mid > n)
//         {
//             e = mid - 1;
//         }
//         else
//         {
//             ans = mid;
//             s = mid + 1;
//         }
//     }
//     return ans;
// }

double morePrecisionSqRoot(int n, int precision, int tempSoln)
{
    double ans = tempSoln;
    double factor = 1;

    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j <= n; j = j + factor)
        {
            ans = j;
        }
    }

    return ans;
}

int main()
{
    int n = 10;
    cout << squareRoot(n) << endl;
    int sq = squareRoot(n);
    cout << morePrecisionSqRoot(n, 3, sq) << endl;
    return 0;
}