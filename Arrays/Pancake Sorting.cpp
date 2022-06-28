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
// sort the array. Also, we have an condition that we should not use more that 10*N filps. (N) being the length of the input array. When we talk about sorting algorithm like Bubble Sort. We
// can either take the smallest element to the front and largest element to the last.
// Ex - 3, 2, 1, 4, 5
// Let's say if we flip(3) => 1, 2, 3, 4, 5
// But what if - 3, 2, 1, 4, 5, 2, 1
// With flip(3) => 1, 2, 3, 4, 5, 2, 1 -> Now if in this case I try to flip it again, then the element (1) at 0 index which is currently at its correct position it would be switched.
// We will take largest character at its correct position.
// Ex - 2, 3, 1, 7, 6, 4, 5
// We will start by bringing the (7) at its correct position. I would try to find out the largest elements amongst the given array.
// Let's say we point (i) at the largest element, and (j) iterator points to the index for each largest elements correct position. We would first flip(i) elements. => 7, 1, 3, 2, 4, 6, 5
// After this simply flip(j) elements. => 5, 6, 4, 2, 3, 1, 7
// Then again I will try to find out the next largest element. Simultaneously, we will keep on decreasing the (j)
// So, with this approach we were able to put each element in its correct position in 2 filps. And there are total (N) elements. Hence it would only require 2*N filps to sort the array.
// Time Complexity - We iterate and find the largest element it would take O(N) time for each element. And then I would take more O(N/2) time to flip the array using two pointer approach and swapping them by moving both left and right pointers.
// So, it takes us O(N) time to put it in correct place, hence for entire function it would take O(N*N).