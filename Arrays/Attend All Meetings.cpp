// Mukesh is a wealthy businessman. He has several meetings to attend. Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],…] (si < ei), determine if mukesh could attend all meetings.

// Input Format
// First line contains an integer n, representing number of meetings mukesh has to attend. n lines following contains two values start time and end time each.

// Constraints
// None

// Output Format
// true if he can attend all meetings else false.

// Sample Input
// 3
// 0 30
// 5 10
// 15 20
// Sample Output
// false
// Explanation
// (0,30), (5,10) and (0,30),(15,20) will conflict or overlap

// Idea of this Question:- These are the type of questions like Maximum Circles, Find the maximum amount of activities that can be done etc.

// Approach:- The fact is we need to find if there is any kind of overlap with any of the given meetings. The given intervals are in random order, we don't know their order beforehand. So, what we can do here is Sorting. Now, if it had been an array of integers it can be sorted easily but being an interval, how are we going to sort it. What we need to decide is that we need to sort the intervals either using the start time or the end time. So, if given a thought about it, we can easily say that the meeting that starts earliest should be the one to attend to. Hence, what we can do is to sort the intervals in terms of their starting time. So, simply we can say that if the start time of current meeting smaller when compared to the end time of the last meeting then attending all the meetings are not possible.

// Exampler Run:-
// [(5, 10), (15, 18), (0, 5), (21, 24), (13, 16)]
// Sorting the above array in terms of startTime -> [(0, 5), (5, 10), (13, 16), (15, 18), (21, 24)]
// interval[1][0] >= interval[0][1], hence both (0, 1 can be attended)
// interval[2][0] >= interval[1][1], hence both (1, 2, can be attended)
// interval[3][0] < intervalu[2][1], hence this (3 meeting cannot be attended) -> hence return false
// Sorting takes - NlogN time + Iteration takes -> N time => Time Complexity -> O(NlogN)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canAttendAllMeetings(vector<pair<int, int>> meetings)
{
  bool answer = true;
  // Ways to sort an vector
  // To Simply sort and vector, we can use sort(v.begin(), v.end());
  // If we want to sort an vector with pair on the basis of first element the above sort() method is still valid
  // If we want to sort an vector with pair on the basis of second element the above sort() method gets a third variable which is a newly defined function -> https://www.geeksforgeeks.org/sorting-vector-of-pairs-in-c-set-1-sort-by-first-and-second/

  // Solution
  // In order to attend all meetings, simply put the end time of next meeting should be greater than the end time of last meeting
  // And in order to check that we should prioritize/sort our array in terms of startTime to get the sequence of meetings that would follow
  sort(meetings.begin(), meetings.end());
  for (int meeting = 1; meeting < meetings.size(); meeting++)
  {
    pair<int, int> currentMeeting = meetings[meeting];
    pair<int, int> previousMeeting = meetings[meeting - 1];
    if (currentMeeting.first < previousMeeting.second)
    {
      answer = false;
      break;
    }
  }
  return answer;
}

int main()
{
  vector<pair<int, int>> meetingTimes;
  int n;
  cin >> n;
  while (n)
  {
    int startTime, endTime;
    cin >> startTime;
    cin >> endTime;
    // Pushing in pairs in vector vec1.push_back(make_pair(55, 55));
    meetingTimes.push_back(make_pair(startTime, endTime));
    n--;
  }

  if (canAttendAllMeetings(meetingTimes))
  {
    cout << "true";
  }
  else
  {
    cout << "false";
  }
  return 0;
}