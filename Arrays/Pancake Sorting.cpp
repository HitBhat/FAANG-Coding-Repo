// Sharadh bhaiya is playing a game of pancakeflip .He has given his students an array 'A' in which they can perform a pancake flip.The task is to choose some positive integer k<= A.length, then reverse the order of the first k elements of A. Return the k-values corresponding to a sequence of pancake flips that sort A.
// Note:Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.

// Input Format
// You do not have to take any input or print any output exactly. Simply write the given function. Your function takes the array for each testcase as input.

// Constraints
// 1 <= T <= 100
// 1 <= A.length <= 100 A[i] is a permutation of [1, 2, …, A.length]

// Output Format
// The function should return a single array which contains a valid pancake sort. Any valid pancake sort will work.

// Sample Input
// 1
// 4
// 3 2 4 1
// Sample Output
// 3 4 2 3 1 2 


// Approach:- We have an flip. What flip means is simply take input (k) integer. And reverse the first (k) elements of the array. And atlast only using these flips. We should be able to 
// sort the array. Also, we have an condition that we should not use more that 10*N filps. (N) being the length of the input array.