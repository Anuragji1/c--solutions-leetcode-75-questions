**Merge Strings Alternately**

Problem Statement 1) You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
 

Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.

-----------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i = 0;
        while (i < word1.length() || i < word2.length()) {
            if (i < word1.length()) {
                result += word1[i];
            }
            if (i < word2.length()) {
                result += word2[i];
            }
            i++;
        }
        return result;
    }
};

----Explanation :- 
Initialization:

The function mergeAlternately takes two strings word1 and word2 as input.
It creates an empty string result to store the merged output.
It initializes a variable i (integer) to 0 as an index counter.
Iterative Merging:

It uses a while loop that continues as long as either i is less than the length of word1 or i is less than the length of word2. This ensures that the loop iterates until all characters from both strings are processed.
Inside the loop:
If i is less than the length of word1 (meaning there are still characters remaining in word1):
It appends the character at index i from word1 to the result string using the += operator.
If i is less than the length of word2 (meaning there are still characters remaining in word2):
It appends the character at index i from word2 to the result string using the += operator.
In each iteration, i is incremented by 1 to move to the next character in the respective strings.
Return Merged String:

After the loop completes (when both strings are exhausted), the result string will contain the characters of word1 and word2 merged alternately.
The function returns the result string, which represents the merged output.
