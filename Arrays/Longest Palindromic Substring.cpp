// Given a string str, find the longest palindromic substring in str. You may assume that the maximum length of s is 1000.

// Input Format
// First line contains an integer T, next t line contains string.

// Constraints
// 1<=|s.length()|<=1e3

// Output Format
// Single line containing single integer

// Sample Input
// 1
// asdfghjklmnbvcxz
// Sample Output
// a

// Approach:-
// What we can do is, we can simply take each index as the middle element of the palindrome. Then start traversing from both right and left end untill an pair of non matching elements is found. And simply store its length in an maximum fashion. Time Complexity - O(N^2).

// Before looking at an optimized approach let's take a look at some cases.
// 1. aba -> Odd Length 3 -> With the above approach we will be able to find the required answer.
// 2. abba -> Even length 4 -> With the above apprach taking, we will not be able to find an palindromic substring in this particular example.

// Thing to keep in mind:-
// 1. Gap
// 2. Mirror image of a palindromic substring from the center of the left part is same as right part.
// Ex -> aaaaa b aaaaa -> This being an palindromic string, with (b) as center we can see both the right and left parts are mirror image of each other.

// Optimized Approach:-
// Ex -> Let's take a string which is an palindrome.
// The string has the leftmost boundary and also the rightmost boundary.
// And lets say (ch) is the center of the palindromic substring. And also lets assume that there is an (char) at distance (x) in right of the center element (ch) lets call it (i). So, being a palindrome I can say that there would be the same (char) at distance (x) in the left side of the center element (ch) lets call it (iMirror). Our idea is to find the length of the substring and the substring itself.
// Also, if we say that with the (iMirror) as center I have calculated the length of the longest palindromic substring, I can say that same length would be of the substring with (i) char in the middle.
// Ex -> abcba -> If we take str[3] as center I can say there is another char similar to str[3] on the left side as well.
// let's say we store the length of the palindromic substring for (iMirror)