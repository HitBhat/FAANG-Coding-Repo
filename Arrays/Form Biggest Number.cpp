// You are provided an array of numbers. You need to arrange them in a way that yields the largest value.

// Input Format
// First line contains integer t which is number of test case.
// For each test case, you are given a single integer n in the first line which is the size of array A[] and next line contains n space separated integers denoting the elements of the array A .

// Constraints
// 1<=t<=100

// 1<=m<=100

// 1<=A[i]<=10^5

// Output Format
// Print the largest value.

// Sample Input
// 1
// 4
// 54 546 548 60
// Sample Output
// 6054854654
// Explanation
// Upon rearranging the elements of the array , 6054854654 is the largest possible number that can be generated.

// Approach:-
// Ex - [3, 30, 34, 5, 9]
// Number's that can be formed -> 9534330, 9534303, 3303459
// It is possible to have around 10^4 numbers in the given array. Now, if that is the case, we won't be able to convert that into a single integer.
// The solution would be to make arrange of these numbers in the array such that I will generate the biggest number in the array itself. So, in case of the above array we should somehow generate an array with this particular sequence. [9, 5, 34, 3, 30] -> 9534330
// If we have to take some idea about it we can simply say that we would need to sort the numbers in order to rearrange them in a way such that the largest number is formed.
// See, in case of sorting we simply swap the numbers when one is greater than the other.
// Also, whenever in a time you are trying to solve an problem. Always start with finding a solution for a smaller testcase. And then move on the given test case.
// Let's start with a smaller example, [3, 30] -> Let's try to sort this array such that the largest number is generated. So, it is also possible that each integer in the array could be 10^9 length maximum and combining them both can make them go out of the memory if treated as integer. Hence, we would require the use of strings. Now, we can simply combine these two numbers like => "3" + "30" > "30" + "3" and hence we can say that we need to swap it.
// Dry Run on above Ex - So, as we need to sort it currently we are using Bubble sort. Every time I would take 2 numbers (i), (j) and we check "a[i]" + "a[j]" > "a[j]" + "a[i]", if this is the case swap the numbers otherwise don't swap. Also, in case of bubble sort all the sorted elements come at the end of the array. Hence once the iterations are completed we can simply just start to print the array from last index to first to get the largest number.
// If wanted to sort vector -> sort(vec.begin(), vec.end(), cmp);
// If wanted to sort array -> sort(a, a+n, cmp);
// Cmp function -> It is a bool function, takes 2 input as argument. The two integers we would get be first converted into strings and combine them. String x = to_string(a); String y = to_string(b); return x+y > y+x;
// Time Complexity - O(N^2) if Bubble sort, O(NlogN) -> Internal Sorting

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool customComparatorFunc(int a, int b)
{
  string x = to_string(a);
  string y = to_string(b);

  return (x + y) > (y + x);
}

void largestNumberFormedUsingInbuildSort(vector<long long int> input)
{
  // Using inbuilt sort will take around -> O(NlogN)
  sort(input.begin(), input.end(), customComparatorFunc);
  // A corner case where we get all zeros in the input, simply return only single zero
  bool allZeros = true;
  for (int i = 0; i < input.size(); i++)
  {
    if (input[i] != 0)
    {
      allZeros = false;
    }
  }
  if (!allZeros)
  {
    // Being a bubble sort method start printing the vector from the last
    for (int i = input.size() - 1; i >= 0; i--)
    {
      cout << input[i];
    }
  }
  else
  {
    cout << "0";
  }
}

void largestNumberFormedBubbleSort(vector<long long int> input)
{
  // Using bubble sort will take around O(N^2)
  int len = input.size();
  // A corner case where we get all zeros in the input, simply return only single zero
  bool allZeros = true;
  for (int i = 0; i < len - 1; i++)
  {
    for (int j = 0; j < len - i - 1; j++)
    {
      string x = to_string(input[j]);
      string y = to_string(input[j + 1]);
      if (x + y > y + x)
      { // In this case swap the two numbers
        long long int temp = input[j + 1];
        input[j + 1] = input[j];
        input[j] = temp;
      }
    }
  }
  for (int i = 0; i < len; i++)
  {
    if (input[i] != 0)
    {
      allZeros = false;
    }
  }
  if (!allZeros)
  {
    // Being a bubble sort method start printing the vector from the last
    for (int i = len - 1; i >= 0; i--)
    {
      cout << input[i];
    }
  }
  else
  {
    cout << "0";
  }
}

int main()
{
  int t;
  cin >> t;
  while (t)
  {
    int n;
    cin >> n;
    vector<long long int> input;
    while (n)
    {
      long long int x;
      cin >> x;
      input.push_back(x);
      n--;
    }
    largestNumberFormedBubbleSort(input);
    cout << "\n";
    t--;
  }
  return 0;
}