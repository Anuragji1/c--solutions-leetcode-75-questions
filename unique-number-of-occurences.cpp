**Unique Number of Occurences**

Problem Statement 20) Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000

--------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counts;
        for (int num : arr) {
            counts[num]++;  // Count the occurrences of each value
        }

        unordered_set<int> uniqueCounts;
        for (auto& count : counts) {
            if (uniqueCounts.count(count.second)) {
                return false;  // Duplicate count found
            }
            uniqueCounts.insert(count.second);
        }

        return true;  // All counts are unique
    }
};

----Explanation :-
Checking for Unique Occurrence Counts:

Counting Occurrences:

The function takes a vector of integers arr as input.
It initializes an unordered_map named counts to store the frequency of each element in the arr vector.
It iterates through the arr vector using a for loop.
Inside the loop, for each element (num), it increments the corresponding count in the counts map. This effectively builds a map where the key is the element (integer) and the value is its count (number of times it appears in the vector).
Checking for Duplicate Counts:

It initializes an unordered_set named uniqueCounts to store the unique occurrence counts encountered so far.
It iterates through the counts map using a range-based for loop. Here, count is a pair containing the element (count.first) and its count (count.second).
Inside the loop, it checks if the uniqueCounts set already contains the current count (count.second) using the count function of the set.
If the uniqueCounts set already contains the current count (count.second), it means there are elements with the same occurrence count, violating the unique requirement.
In this case, the function returns false to indicate that the vector does not have unique occurrence counts.
Unique Counts Found:

If the uniqueCounts set doesn't contain the current count (!uniqueCounts.count(count.second)), it means this is the first time encountering this specific occurrence count.
The code inserts the current count (count.second) into the uniqueCounts set using the insert function. This effectively tracks the unique occurrence counts encountered so far.
Returning Result:

After iterating through all elements and their counts, if the code hasn't returned false yet, it means all occurrence counts encountered were unique.
In this case, the function returns true to indicate that the vector arr has elements with unique occurrence counts.
