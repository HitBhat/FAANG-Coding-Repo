// Given an array having n elements representing balls of various colours like red, white or blue, sort them in-place so that balls of the same colour are adjacent, with the colours in the order red, white and blue.
// To represent the colour red, white, and blue we will use the integers 0, 1, and 2 respectively.
// Note:You are not suppose to use the sort function for this problem.

// Input Format
// First line contains integer n as size of array. Next n lines contains a single integer as element of array.

// Constraints
// None

// Output Format
// Print the balls in order so that balls of same colour are adjacent.

// Sample Input
// 6
// 2 0 2 1 1 0
// Sample Output
// 0 0 1 1 2 2

// Approach:-
// 1) The very basic approach will be to sort this particular array with any given sorting algorithm, which in best case scenario will give us O(nlogn) TC.
// 2) We can simply create 3 counters which with one traversal of the array will give us the count of all 0, 1, 2 elements. After that we can simply push/replace the existing array with first filling 0's, then 1's and so on. This should help us in bringing down the TC to O(N), and space complexity -> O(1).
// 3) Three Pointer Approach:- We know that all zeros will be on the left side, all 2's will be on the right side. We will take 2 pointers (left=0), (right=arr.size()-1). 
// We can have another pointer called (current), and we shall have our algorithm work untill (current<=right). So, we shall see that if(arr[current]==0) we will swap the elements swap(arr[current], arr[left]) left++; current++; else if(arr[current]==2) swap(arr[current], arr[right]) right--; in this case (current) would not be updated as it is quite possible that what we swapped on our (current) index could be (2) again which would have to be taken to its correct place. In else case we simply do (current++). As once all the 0's, 2's are placed, we are evident that 1's would be placed into their correct places already.

#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int> &input, int a, int b){
	int temp = input[a];
	input[a] = input[b];
	input[b] = temp;
}

void printTheOutput(vector<int> &input){
	for(int i=0;i<input.size();i++){
		cout<<input[i]<<" ";
	}
}

void sortTheInput(vector<int> &input){
	// We also have the count0, count1, count2 approach.
	// Using three pointer appraoch for current solution.
	int left = 0;
	int right = input.size()-1;
	int current = 0;
	while(current<=right){
		if(input[current]==0){
			swap(input[current], input[left]);
			left++;
			current++;
		}
		else if(input[current]==2){
			swap(input[current], input[right]);
			right--;
		}
		else{
			current++;
		}
	}
}

int main() {
	int n;
	cin>>n;
	vector<int> input;
	while(n){
		int x;
		cin>>x;
		input.push_back(x);
		n--;
	}
	sortTheInput(input);
	printTheOutput(input);
	return 0;
}