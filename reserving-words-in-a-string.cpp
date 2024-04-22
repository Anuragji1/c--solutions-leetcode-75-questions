**

Problem Statement 6) Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.

-------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
   string reverseWords(string s) {
       istringstream iss(s);  // Create an input string stream for efficient word extraction
       string word, result;

       // Read words from the stream, handling leading/trailing spaces and multiple spaces
       while (iss >> word) {
           if (!result.empty()) {
               result = word + " " + result;  // Append word to the beginning of result, separated by a space
           } else {
               result = word;  // Add the first word without a leading space
           }
       } 

       return result;
   }
};

----Explanation :-
  Reversing Words in a Sentence:

Input String Stream:

The function takes a string s as input.
It creates an istringstream object named iss and initializes it with the input string s. This stream object allows for efficient word extraction from the string.
Extracting Words:

It uses a while loop that iterates as long as the iss >> word extraction is successful. This loop reads words from the stream one by one and stores them in the word variable.
Building Reversed String:

Inside the loop:
If the result string is not empty (meaning there's at least one word added previously):
It prepends (adds at the beginning) the current word to the result string, separated by a space using word + " " + result.
If result is empty (it's the first word):
It simply assigns the current word to result without any space in front, as there are no preceding words yet.
Returning Reversed Words:

After the loop iterates through all words in the string, the result string will contain the words in reversed order, maintaining any leading/trailing spaces or multiple spaces present in the original string.
The function returns the result string, which represents the reversed sentence.
