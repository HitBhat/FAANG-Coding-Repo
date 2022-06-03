// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list
// Note : You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

// Input Format
// First line contains input N. Next line contains N space separated String denoting the elements of the array. third line contains word1 and word2

// Constraints
// None

// Output Format
// Shortest Distance between word1 and word 2

// Sample Input
// 5
// practice makes perfect coding makes
// coding practice

// Sample Output
// 3
// Explanation
// Index for coding is - 3
// Index for practice is - 0
// Distance between words = Difference in their indexes -> 3 - 0 = 3

// Approach:-
// It doesnot seem in the given test case, but we can have multiple word1 and word2.
// Ex - w1, .., .., .., w2, .., .., w2, .., .., w1, w2
// In the above case the shortest distance is 1 where (w1) -> index -> 10, (w2) -> index -> 11

// Brute Force Approach:- We can have 2 pointer approach we can use (i), (j) pointers. Both will loop over the array, (i) would always point to (word1) and for every (word1) it finds, (j) starts from (i+1)-> n to search for (word2) and stores an miminum distance between them globally. Time Complexity - O(N^2)

// Once, we found an approach with O(N^2) time complexity, we need to move in terms of O(N), then O(NlogN), then O(logN). For O(NlogN) we would need to divide the array into two parts in every step, which in this case is not possible.

// Optimized Approach:-
// Let's work on an example, we have 2 balls red(w1) and blue(w2)
// [w1, .., w2, w1, .., w1, .., w2]
// When, we find a blue ball at (0) index, only then I would say I need to find a red ball such that the distance between the two can be calculated. Then he will find a red ball at index (2), and updates our answer as (2-0 = 2).
// We need to keep the answer variable such that we can apply minimum operation on it. Also, we can have the answer variable keep the value of the length of array initially, as the distance between two number would never exceed that.
// Now, when moving forward we find a blue ball at index (3), now the idea is that whatever red ball we find after index (3) would be near to the blue ball at index (3), rather than the blue ball at index (0), hence we would say the index of available blue ball is (3).
// Then again moving forward we again find a blue ball, hence we update the best position of blue ball to index(5), and at last we get a red ball at index (7) and its distance is again (7-5 = 2), hence the answer is 2.
// This approach is called Two Pointers Approach and takes O(N) Time Complexity.

#include <bits/stdc++.h>
using namespace std;

int findMinimumDistance(vector<string> stringsVector, string word1, string word2)
{
  int answer = stringsVector.size(); // Answer has to be something maximum, which when applied min() operator works fine.
  int bestWord1Pos = -1;
  int bestWord2Pos = -1;
  for (int i = 0; i < stringsVector.size(); i++)
  {
    if (stringsVector[i] == word1)
    {
      bestWord1Pos = i;
    }
    if (stringsVector[i] == word2)
    {
      bestWord2Pos = i;
      // Whenever we find a word2, and there is a word1 present, find the updated minimum distance
      //  if(bestWord1Pos != -1){
      //      answer = min(answer, abs(bestWord2Pos - bestWord1Pos));
      //  }
      // I kept it here, but the fact is word2, could have been found first and then word1, this shall not work in that case.
    }
    if (bestWord1Pos != -1 && bestWord2Pos != -1)
    {
      // Only work in scenario when there has been alteast one updation for both the word1Pos, word2Pos.
      answer = min(answer, abs(bestWord2Pos - bestWord1Pos));
      // the fact that abs is being is because in the given exampler input, (word1 = 3) and (word2 = 0) and I do word2 - word1, so to avoid negative results.
    }
  }
  return answer;
}
int main()
{
  int n;
  cin >> n;
  vector<string> stringVector;
  for (int i = 0; i < n; i++)
  {
    string str;
    cin >> str;
    stringVector.push_back(str);
  }
  string word1;
  string word2;
  cin >> word1;
  cin >> word2;
  cout << findMinimumDistance(stringVector, word1, word2);
  return 0;
}