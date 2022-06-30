// Given an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
// You are given a target value to search. If found in the array return its index, otherwise return -1.
// Note:You may assume no duplicate exists in the array.

// Input Format
// First line contains size of Array. Second line contains n elements of Array. Third line contains target elements.

// Constraints
// Your algorithm's runtime complexity must be in the order of O(log n).

// Output Format
// Print the index of element if found , otherwise print -1.

// Sample Input
// 7
// 4 5 6 7 0 1 2
// 0
// Sample Output
// 4

// Approach:-
// See, if we were asked to find an element in the sorted array then we will be using an algorithm called Binary Search. This algorithm can be used in someother places as well. But whenever we see an unsorted array and we need to find an elements, we think of an approach where we first sort the elements and then find the elements using Binary Approach. Hence for this question when we have an rotated sorted array we can simply apply Binary Search and get the solution.

// Ex -> 5, 6, 7, 0, 1, 2, 4 -> The idea behind this range is that it first increases steeply then it decreases and then starts increasing again.
// Let's say target-> 8. Currently we have (start=5) and (end=4). Now, the (middle = (0+8)/2 = 4 -> arr[middle] = 9). Now this middle can lie in the first increasing region of it or can lie in the second increasing region. So, =>if (arr[mid]==target) we can simply return true such that element has been found. Now, let's say the target lies in the left portion of the array, we know that every element in the left portion is greater than all the elmenets on the right side. So, we can say that for element to be in left side of the array => if(arr[mid] > a[n-1]{last element}) we need to update the (start) and (end) pointers so inside this particular check we need to add another check like if(target > a[mid] || target < a[0]) in these two cases we can say that we are sure that we need to update the value of  (start = mid+ 1), now else (mid=end-1). Let's check how to find if the element lies in the right side of the array. So, we can say that if (a[mid] < a[0]) we can say that we are in the right part of the entire array. Now, target can either be in the left part of this entire right segment of the array, or target can simply lie in the left part of the array.  if(target < a[mid] || target > a[n-1]) => (end=mid-1;) else (start=mid+1;). Now, this complete algo would run untill (start<=end). If untill this while loop is running and we have not returned till now we would say that we cannot find the element in the array and simply return -1;

// Time Complexity -> O(logN), because in the end we are simply applying Binary Search.

#include <iostream>
#include <vector>
using namespace std;

int findElementInRotatedSortedArray(vector<int> input, int target, int start, int end)
{
  if (start <= end)
  { // This is the mandatory condition for the Binary Search to Work
    int mid = (start + end) / 2;
    if (input[mid] == target)
    {
      return mid;
    }
    // Now, the main motive of binary search is to move start, end pointers in way that search area is reduced every time.
    else if (input[mid] > input[input.size() - 1])
    {
      if (target > input[mid] || target < input[0])
      { // this means that the target lies on the right side of the middle element
        start = mid + 1;
      }
      else
      {
        end = mid - 1;
      }
      return findElementInRotatedSortedArray(input, target, start, end);
    }
    else if (input[mid] < input[0])
    {
      if (target < input[mid] || target > input[input.size() - 1])
      {
        end = mid - 1;
      }
      else
      {
        start = mid + 1;
      }
      return findElementInRotatedSortedArray(input, target, start, end);
    }
  }
  return -1;
}

int main()
{
  int n;
  int target;
  cin >> n;
  vector<int> input;
  while (n)
  {
    int x;
    cin >> x;
    input.push_back(x);
    n--;
  }
  cin >> target;
  cout << findElementInRotatedSortedArray(input, target, 0, input.size() - 1);
  return 0;
}