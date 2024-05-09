**Find the Difference of Two Arrays**

Problem Statement 19) Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.

 

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
Example 2:

Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
-1000 <= nums1[i], nums2[i] <= 1000

----------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<vector<int>> answer = {{},{}};

        for (int num : set1) {
            if (!set2.count(num)) {
                answer[0].push_back(num);
            }
        }

        for (int num : set2) {
            if (!set1.count(num)) {
                answer[1].push_back(num);
            }
        }

        return answer;
    }
};

----Explanation:-
Finding Differences Between Sets:

Creating Sets from Vectors:

The function takes two vectors of integers nums1 and nums2 as input.
It creates two unordered_set objects:
set1: This set is populated with all the unique elements from the nums1 vector using the range-based constructor (unordered_set<int> set1(nums1.begin(), nums1.end())).
set2: This set is populated with all the unique elements from the nums2 vector using the same method.
Initializing Result:

It initializes a vector of vectors of integers answer (set to {{}, {}}). This will be used to store the final result, where answer[0] will contain elements present only in nums1 (and not in nums2), and answer[1] will contain elements present only in nums2 (and not in nums1).
Finding Elements in One Set But Not the Other:

It uses a for loop that iterates through each element (num) in the set1.

Inside the loop, it checks if set2 doesn't contain the current element (!set2.count(num)) using the count function of the set. This count function efficiently checks if a specific element exists in the set.
If set2 doesn't contain the element (num), it means that element is present only in nums1 (and not in nums2).
In that case, it pushes the element (num) to the answer[0] vector using the push_back function. This effectively adds elements unique to nums1 to the first sub-vector of the result.
It performs a similar process using another for loop to iterate through elements in set2 and add elements unique to nums2 to the answer[1] vector.

Returning the Difference:

After iterating through both sets, the answer vector will contain two sub-vectors:
answer[0]: This sub-vector will contain all the elements present only in nums1.
answer[1]: This sub-vector will contain all the elements present only in nums2.
The function returns the answer vector as the result, providing the differences between the two input vectors.
