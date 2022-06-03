// A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are the coordinates of its bottom-left corner, and (x2, y2) are the coordinates of its top-right corner.

// Two rectangles overlap if the area of their intersection is positive. To be clear, two rectangles that only touch at the corner or edges do not overlap.

// Given two (axis-aligned) rectangles, return whether they overlap.

// Input Format
// First line contains an 4 integers i.e x1, y1, x2, y2 for rectangle 1, similarly second line contains coordinates for rectangle 2.

// Constraints
// None

// Output Format
// 1 if rectangles overlap else 0.

// Sample Input
// 0 0 1 1
// 1 0 2 1
// Sample Output
// 0

// Approach:-
// In order to solve this question the idea is to being able to create a condition which checks when rectangles overlap and then simply just return 1 or 0 accordingly. Now, the catch here is that there are quite a lot of cases or variations such that 2 rectangles can be overlapping when observed. So, in these type of questions what we can do is rather than finding the conditions when it happens let's find the conditions when it does not happen and return 0, and in else return 1.
// See, whenever the 2nd rect. is above, right, below, left of out 1st rectangle it is bound to not make any overlapping area with the rectangle.

// Negation Approach:- Whenever you feel like in this question the amount of true statements are very vastly defined and it is kind of very easy to skip an condition. Do one thing simply find the negations/negative conditions and work with them.

#include <iostream>
using namespace std;

int main()
{
  int r1Coordinates[4];
  int r2Coordinates[4];
  for (int i = 0; i < 4; i++)
  {
    cin >> r1Coordinates[i];
  }
  for (int j = 0; j < 4; j++)
  {
    cin >> r2Coordinates[j];
  }

  // [x1, y1, x2, y2]
  // When second rectangle is above the first rectangle
  // bottom left(y) co-orinate of second rectangle is >= top right(y) co-ordinate of first rectangle
  if (r2Coordinates[1] >= r1Coordinates[3])
  {
    cout << 0;
    return 0;
  }
  // When second rectangle is left of first rectangle
  // top right(x) co-ordinate of second rectangle is <= bottom right(x) co-ordinate of first rectangle
  if (r2Coordinates[2] <= r1Coordinates[0])
  {
    cout << 0;
    return 0;
  }
  // When second rectangle is right of first rectangle
  // bottom left(x) co-ordinate of second rectangle is >= top right(x) co-ordinate of first rectangle
  if (r2Coordinates[0] >= r1Coordinates[2])
  {
    cout << 0;
    return 0;
  }
  // When second rectangle is bottom of first rectangle
  // top right(y) co-ordinate of second rectangle is <= bottom left (y) co-ordinate of first rectangle
  if (r2Coordinates[3] <= r1Coordinates[1])
  {
    cout << 0;
    return 0;
  }

  // If the program hasn't returned till now it means they overlap
  cout << 1;
  return 0;
}