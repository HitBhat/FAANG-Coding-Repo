// Ram is very good at mathematics. He was given a number n and was told to find out number of trailing zeroes in n! in logarithmic time. Can you help him?

// Input Format
// An integer n

// Constraints
// n can go upto 2000

// Output Format
// An integer denoting number of trailing zeroes

// Sample Input
// 5
// Sample Output
// 1
// Explanation
// 5! is 120, so there is one trailing zero.

// Approach:-
// This question is much more of an puzzle rather than a DSA based question. We know one thing that in order for any zero to occur in a factorial. There should be a pair of 2 and 5. Also it is obvious that the number of 5 are gonna be way less than the number of 2's. Hence if we could somehow find the number of 5 available in a particular number then it should be the answer. We know that if we were to divide any number with 5 it ought to give us the total number of 5 available.

// Ex:-
// N = 12, 12 / 5 = 2(Which means there are 2 5's in 12. One in 5 and One in 10).
// N = 15, 15 / 5 = 3(which means there are 3 5's in 15).
// N = 25, 25 / 5 = 5(Which means there are 5 5's in 25. But if we were to count we would realise that there are 6 5's in 25. Also the remainder we got is 5 itself. So, what we really need to do is go on dividing the number with 5 untill we get a remainder 0. Which means if we again divide 5 / 5 we should get 1. And the 5 + 1 = 6).

#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int countZeros = 0;
  while (n)
  {
    n /= 5;
    countZeros += n;
  }
  cout << countZeros;
  return 0;
}