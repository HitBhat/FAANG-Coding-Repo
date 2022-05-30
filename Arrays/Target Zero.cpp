// Given an integer n, return an array containing n unique integers such that they add up to 0.

// Input Format
// First line contains an integers n.

// Constraints
// None

// Output Format
// Array integers summing upto 0.

// Sample Input
// 5
// Sample Output
// -2 -1 0 1 2
// Explanation
// Output should be in sorted order.

// Approach:-
// Simply with the given number (n). We can say on thing if we want something to be zero in accrodance with the numbers, we need (x) as well as (-x).
// Ex - 1
// n = 6
// As we want all the numbers to be unique we can simply say that if we had a pair of (x) & (-x) every input (n) we can have an array which would sum up to 0. For what we require is (n/2) pairs in (x) and (-x) numbers, in case of an even number. And (6/2) = 3. Hence, [-3, -2, -1, 1, 2, 3] would be the answer. As the solution has to be sorted. What we can do is either first push these pairs randomly and then sort the array. Or what we can do is simply first push (-ve [-n/2, -1]) elements first and then push the (+ve [1, -n/2]) elements.
// Ex - 2
// n = 5
// As we want all the numbers to be unique we can simply say that if we had a pair of (x) & (-x) every input (n) we can have an array which would sum up to 0. For what we require is (n/2) pairs in (x) and (-x) numbers, but in case of an odd number for ex (5/2) = 2. And having 2 pairs would still leave us with one place to fill. Which can be filled with zero itself. Now, in this case we can simply first push all the (+ve) elements from [1, n-1/2] and then push (0) and then from [-(n-1)/2, -1].

#include <iostream>
#include <climits>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int arr[n];
  int positiveMax = INT_MAX;
  int negativeMin = INT_MIN;
  int i = 0;
  if (n % 2 == 0)
  {
    positiveMax = n / 2;
    negativeMin = (-1) * positiveMax;
  }
  else
  {
    positiveMax = (n - 1) / 2;
    negativeMin = (-1) * positiveMax;
    int zeroPos = n / 2;
    arr[zeroPos] = 0;
  }

  // Putting in (-ve) values first in both even/odd number
  while (negativeMin != 0)
  {
    arr[i] = negativeMin;
    i++;
    negativeMin++;
  }

  // In case of an even number the (0) has already been added. Hence, doing (i++) to not let the code overwrite that 0.
  if (n % 2 != 0)
  {
    i++;
  }

  // Now, as the numbers are sorted. Moving from 1 to (positiveMax + 1) rather than from (positiveMax) to 1, which I was doing earlier and getting wrong answer.
  int fromPositive1 = 1;
  while (fromPositive1 != positiveMax + 1)
  {
    arr[i] = fromPositive1;
    i++;
    fromPositive1++;
  }

  int j = 0;
  while (j < n)
  {
    cout << arr[j] << " ";
    j++;
  }
  return 0;
}