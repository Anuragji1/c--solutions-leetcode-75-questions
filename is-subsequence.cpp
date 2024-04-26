**Is Subsequence**

Problem Statement 10) Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.

------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;  // Move to the next character in s only if a match is found
            }
            j++;  // Always move to the next character in t
        }

        return i == s.size();  // True if all characters in s were matched
    }
};

-----Explanation :-
Checking for Subsequence:

Pointers and Loop Initialization:

The function takes two strings s (shorter string) and t (longer string) as input.
It initializes two integer variables:
i (starting at 0) to keep track of the index in the s string.
j (starting at 0) to keep track of the index in the t string.
Iterating Through Strings:

It uses a while loop that continues as long as both i and j are within the bounds of their respective strings (i < s.size() and j < t.size()).
Matching Characters:

Inside the loop, it checks if the character at the current index in s (s[i]) is equal to the character at the current index in t (t[j]).
If the characters match:
It increments i to move to the next character in s. This signifies that a character from s has been found in t, and we need to find the next character in s in the remaining part of t.
Moving Through Longer String:

Regardless of whether the characters match or not, it always increments j to move to the next character in the t string. This ensures we iterate through the entire t string to find potential matches for the remaining characters in s.
Checking for All Matches:

After the loop completes, it checks if i is equal to the size of s (i == s.size()).
If i is equal to the size of s, it means all characters in the s string were found in the t string in the same order, even though they might not have been contiguous. In this case, the function returns true indicating s is a subsequence of t.
Not a Subsequence:

If the loop completes and i is not equal to the size of s, it means not all characters in s were found in t in the required order. The function returns false in this case.
