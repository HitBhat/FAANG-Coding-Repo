// You are given a one dimensional array that may contain both positive and negative integers, find the sum of contiguous subarray of numbers which has the largest sum. For example, if the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7.

// Input Format
// The first line consists of number of test cases T. Each test case consists of two lines.
// The first line of each testcase contains a single integer N denoting the number of elements for the array A.
// The second line of each testcase contains N space separated integers denoting the elements of the array.

// Constraints
// 1 <= N <= 100000

// 1 <= t <= 20

// -100000000 <= A[i] <= 100000000

// Output Format
// Output a single integer denoting the maximum subarray sum for each testcase in a new line.

// Sample Input
// 2
// 4
// 1 2 3 4
// 3
// -10 5 10
// Sample Output
// 10
// 15
// Explanation
// For the first testcase, maximum subarray sum is generated by the entire array - 1+2+3+4 = 10
// For the second testcase , maximum subarray sum is generated by the subarray {5,10} - 5+10 = 15

// Approach
// Also, try to give as many solutions as you can give for a particular problem rather than jumping to most optimized solution at once.

// Brute Force Approach:- Taking 2 pointers (i), (j) and try to find all the possible subarrays, in this particular array. we would have a maxSum variable initialized to INT_MIN. (i) will move from 0->n. Where as j will move from (i) -> n. And another for loop inside (k) this would run between (i) to (j). Finding the sum for this range. If this sum is more than the maxSum, update it
// Ex. maxSum = INT_MIN;
// for(int i=0;i<n;i++){
//    for(int j=i;j<n;j++){
//      for(int k=i;k<=j;k++){
//        sum += arr[k];
//      }
//    }
//  }
// But this approach takes O(N^3) time complexity.

// Kadanes Algorithms:-
// The thing is if we add a (-ve) number to a (+ve) number. It is going to decrease the value of this (+ve) number, very obvious. And (+ve) + (+ve) would increase the value. We are always going to make sure that the sum should never go negative. And if somehow the sum goes (-ve) it is better to discard that particular (-ve) number.
// Time Compexity - O(N)
// Space Complxity - O(1)
// Ex:-
//[0, -1, 2, 1, -1, 3, -3]
//(i) iterator which is going to iterate on the array
// currSum - sum till the ith index
// maxSum - answer (intialize it with INT_MIN)
// when i=0, currSum + arr[i] = 0, also check if(currSum > maxSum) maxSum = currSum
// when i=1, currSum becomes -1, which is something we don't wnat, hence if(currSum < 0) currSum = 0, and also check whether this might be greater than the maxSum or not.
// when i=2, i=3 both times the currSum would increase and we update the maxSum accordingly.
// when i=4, it is a (-ve) number but it is not making our currSum as 0. Hence we include this number, and in this case maxSum is already greater than the currSum, so no update to maxSum as of now.
// when i=5, update both currSum , maxSum
// when i=6, currSum = 2, but maxSum = 5, hence the answer is 5.

#include <iostream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;
int getMaxSubarraySum(int *arr, int n)
{
  int maxSum = INT_MIN;
  int currSum = 0;
  for (int i = 0; i < n; i++)
  {
    currSum += arr[i];
    if (currSum < 0)
    {
      currSum = 0;
    }
    maxSum = max(currSum, maxSum);
  }
  return maxSum;
}
int main()
{
  int t;
  cin >> t;
  while (t)
  {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    cout << getMaxSubarraySum(arr, n) << "\n";
    t--;
  }
  return 0;
}