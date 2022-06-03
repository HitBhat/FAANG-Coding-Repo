// Given an array A, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Input Format
// First line contains integer n as size of array. next n lines contains a single integer as element of array.

// Constraints
// Note: Do this in-place without making a copy of the array and Minimize the total number of operations.

// Output Format
// Print the output Array.

// Sample Input
// 5
// 0
// 1
// 0
// 3
// 12
// Sample Output
// 1 3 12 0 0

// Remember that always start with an approach which is not the best optimized approach if possible. The number of optimizations that one can showcase in an interview increases the chances of being selected.

// Solution
// 1) Simply iterate over the array and count the number of zeros that occur in my array. Simply print all the non-zero numbers while iterating the array and keep on increasing the count every time we encounter an 0. At the end simply print the zeros count number of times. Time Complexity = O(N) & Space Complexity - O(1)

// 2) Create an seperate array. Now take two pointers (i) and (j) on both of the arrays. Every time we encounter an non-zeros push the values in the new array and increase both the (i) & (j) pointer. If we encounter an 0, simple increase the count and move (i) but not (j). At last when the first array has been completely iterated simply push the 0 equal to the number of counts stored. Time Complexity - O(N) & Space Complexity - O(N)

// 3) If looked carefully, it seems like an sorting kind of approach where we want to have all the zeros at last. And for that swapping is a technique that can be used. Here we use an similar approach as to previous one where we required two pointers (i) & (j) . Pointer (i) would iterate over the array and (j) would stop at times it finds an 0, and we swap both (i) & (j) values. Once swapped both the values of (i) & (j) are updated. In case we encounter an 0 over (i) we don't do anything. Time Complexity - O(N) & Space Complexity - O(1)

#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> input;
  while (n)
  {
    int x;
    cin >> x;
    input.push_back(x);
    n--;
  }

  // Two Pointer Approach
  //(i) - Iterates over array
  //(j) - Points to all the zeros in the array and whenever an zero is encountered and (i) points to an non-zeros, swap is done

  int i = 0;
  int j = 0;
  while (i < input.size())
  {
    // If both the numbers on i, j are non-zero simply move both the pointers
    if (input[j] != 0 && input[i] != 0)
    {
      i++;
      j++;
    }
    else if (input[j] == 0 && input[i] != 0)
    {
      // swap the numbers
      int temp = input[j];
      input[j] = input[i];
      input[i] = temp;
      i++;
      j++;
    }
    else if (input[i] == 0)
    {
      i++;
    }
  }

  // Printing the vector itself
  for (int i = 0; i < input.size(); i++)
  {
    cout << input[i] << " ";
  }
  return 0;
}