// You are given an N*N sudoku grid (N is a multiple of 3). Solve the sudoku and print the solution.
// To learn more about sudoku, go to this link Sudoku-Wikipedia.

// Input Format
// First line contains a single integer N. Next N lines contains N integers each, where jth integer int ith line denotes the value at ith row and jth column in sudoku grid. This value is 0, if the cell is empty.

// Constraints
// N=9 Solution exists for input matrix.

// Output Format
// Print N lines containing N integers each, where jth integer int ith line denotes the value at ith row and jth column in sudoku grid, such that all cells are filled.

// Sample Input
// 9
// 5 3 0 0 7 0 0 0 0
// 6 0 0 1 9 5 0 0 0
// 0 9 8 0 0 0 0 6 0
// 8 0 0 0 6 0 0 0 3
// 4 0 0 8 0 3 0 0 1
// 7 0 0 0 2 0 0 0 6
// 0 6 0 0 0 0 2 8 0
// 0 0 0 4 1 9 0 0 5
// 0 0 0 0 8 0 0 7 9
// Sample Output
// 5 3 4 6 7 8 9 1 2
// 6 7 2 1 9 5 3 4 8
// 1 9 8 3 4 2 5 6 7
// 8 5 9 7 6 1 4 2 3
// 4 2 6 8 5 3 7 9 1
// 7 1 3 9 2 4 8 5 6
// 9 6 1 5 3 7 2 8 4
// 2 8 7 4 1 9 6 3 5
// 3 4 5 2 8 6 1 7 9

// Idea behind suduko:- (N*N) -> 9*9 GENERALLY. WE HAVE N(9) NUMBER OF SMALL MATRICES WITH SIZE (ROOT(N) * ROOT(N)) OR 3*3. WE NEED TO FILL AN EMPTY CELL SUCH THAT, THE PARTICULAR NUMBER SHOULD NOT BE REPEATED IN ITS ROW, COLUMN AND ITS PARTICULAR CELL AS WELL.

// Approach:- Now, in these types of questions we cannot manually go and check for each number from 1-9 and in each 9 small matrix. Recursion says, we do the work for bigger problem, and we will ask the Recursion to solve for the smaller problem. That is then now Recursions resposibility to do that, but we only have to do our part. We will do the work for 1 particular cell, and then will ask Recursion to do the work for other empty cells. Now, if reucrsion was able to solve the remaining sudoku, we can simply say that the entire sudoku has been solved. This is also known as GRID BASED RECURSION.
// Now, the conditions that we need to follow is -> We can only fill numbers from 1-N(in our case N=9). Now, lets say we can simply fill (1) in the cell for which we can work. As, currently it is not available in the first (ROOT(N) * ROOT(N)) OR 3*3 matrix, also it is not present in the row, either in the column. For every cell, I can have number from (1-N) after checking if the number does not exist in the particular matrix, row, column. Now, I will ask the recursion to tell me if the entire suduko is solved or not. We are solving the Suduko cell by cell. Hence, going by this idea it seems that the entire function should of the bool type(meaning whether I (first cell by me + remaining by recursion)) was able to solve the suduko or not. And in case the suduko is not sovleable we need to return false indicating that it cannot be solved.
// Now, what if the recursion said that it was not able to solve the suduko. If that is the case we shall not return false abruplty, but change the number that we assigned to the cell for which we worked on. Let's suppose I change my number from (1) -> (2) which was first checked if it was not present in the matrix, row, column and again asked recursion to check whether it can be solved or not now. Now once we move from 1->N or 1->9 and when you used 9 and still recursion returned you false, now at this point I should say that this suduko does not have a solution.
// How to find out which number to be kept in a particular cell or not. Let a cell be denoted by (i, j). In order to iterate over the entire cell and check if 2 exists in this cell or not. The formula for finding the starting point of the current matrix -> Sx = (i/ROOT(N)) * ROOT(N), Sy = (j/ROOT(N)) * ROOT(N). Ex -> (i, j) = (8, 3) -> Sx = (8/3) * 3 = 6, Sy = (3/3) * 3 = 3. (Sx, Sy) = (6, 3). And when you have the starting element simply move right, (ROOT(N)) times, move downwards (ROOT(N)) times as well, and using the nested loop we can find all the values that currently exist in the current matrix.
// Now, we need to look out for the recursive case. As, we already know we need to do work for
// function suduko(i, j, N){
// Also, currently till now we have not managed the (j) value and in order to do that we need to add a check over here itself.
// if(j===N){
//   return suduko(i+1, 0, N);
// }
// Now, in order to let the recursion know that the suduko has been solved, that should be added in the base case.
// if(i==N){
//   Print the suduko
// return true;
// }
// First we need to iterate over all the available numbers
// for(int number=1;number<=N;number++){
// Now for each number I need to check whether it is possible to have this number here. So we create another function called (isSafeToPut(i, j, i))
// if(isSafeToPutNumber(i, j, number, N)){
// mat[i][j] = number;
// Now, that I have done my part I shall ask recursion to solve the next column in the same row.
// bool isRestSudukoSolved = suduko(i, j+1, N);
// if(isRestSudukoSolved){
// return true that solution has been found.
// }
// But in case it returns false we know that this substitution that we just did, was not right.
// mat[i][j] = 0;
// }
// return false;
// }
// }
// isSafeToPutNumber function would check if it is safe to put the number in the currenl row, column and (ROOT(N) * ROOT(N) matrix), and its return value would be bool type.

#include <iostream>
#include <cmath>
using namespace std;
void printSuduko(int suduko[][9])
{
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      cout << suduko[i][j] << " ";
    }
    cout << "\n";
  }
}
bool isSafeToPutValue(int suduko[][9], int size, int currentRow, int currentCol, int valueToPut)
{
  // Check if the current value is available in rows
  for (int col = 0; col < size; col++)
  {
    if (suduko[currentRow][col] == valueToPut)
    {
      return false;
    }
  }
  // Check if the current value is available in the current column
  for (int row = 0; row < size; row++)
  {
    if (suduko[row][currentCol] == valueToPut)
    {
      return false;
    }
  }
  // Check if the current value is available in the current cell of ROOT(N) * ROOT(N) -> Simply move (ROOT(N)) time right, and (ROOT(N)) times downward
  int cellXAxis = (currentRow / 3) * 3;
  int cellYAxis = (currentCol / 3) * 3;
  for (int row = cellXAxis; row < (cellXAxis + 3); row++)
  {
    for (int col = cellYAxis; col < (cellYAxis + 3); col++)
    {
      if (suduko[row][col] == valueToPut)
      {
        return false;
      }
    }
  }
  return true;
}

bool findSudukoSolution(int suduko[9][9], int n, int currentRow, int currentCol)
{
  // Base case to finish the recursion
  if (currentRow == n)
  { // This means that all the values have been kept till now, and as this would be 9 which means that we just need to print the values
    printSuduko(suduko);
    return true;
  }

  // Case to handle the currentRow increment
  if (currentCol == n)
  {
    return findSudukoSolution(suduko, n, currentRow + 1, 0);
  }
  if (suduko[currentRow][currentCol] == 0)
  { // This cell needs to be filled.
    for (int i = 1; i <= 9; i++)
    {
      if (isSafeToPutValue(suduko, n, currentRow, currentCol, i))
      {
        suduko[currentRow][currentCol] = i;
        bool solutionFound = findSudukoSolution(suduko, n, currentRow, currentCol + 1);
        if (solutionFound)
        {
          return true;
        }
        // If the value is false, this means for our current (i) considertion there was no solution for rest of the suduko, simply reset the value for current row,col
        suduko[currentRow][currentCol] = 0;
      }
    }
    // This means that I have exhausted all the numbers from 1->9 for a particular cell, and no solution has been found till now.
    return false;
  }
  else
  {
    return findSudukoSolution(suduko, n, currentRow, currentCol + 1);
  }
}
int main()
{
  int n;
  cin >> n;
  // Taking the suduko input
  int suduko[9][9];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int x;
      cin >> x;
      suduko[i][j] = x;
    }
  }
  findSudukoSolution(suduko, n, 0, 0);
  return 0;
}