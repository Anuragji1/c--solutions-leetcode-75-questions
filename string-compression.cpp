**String-Compressor**

Problem Statement 8) Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

 

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.
Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
 

Constraints:

1 <= chars.length <= 2000
chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.

---------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int compress(vector<char>& chars) {
        int writeIndex = 0, anchor = 0;

        for (int readIndex = 0; readIndex < chars.size(); readIndex++) {
            if (readIndex + 1 == chars.size() || chars[readIndex + 1] != chars[readIndex]) {
                chars[writeIndex++] = chars[anchor];
                if (readIndex > anchor) {
                    // Encode group length (only if group length > 1)
                    for (char digit : to_string(readIndex - anchor + 1)) {
                        chars[writeIndex++] = digit;
                    }
                }
                anchor = readIndex + 1;  // Move anchor to the next group
            }
        }

        return writeIndex;  // Return the new length of the compressed string
    }
};

-----Explanation :-
Run-Length Encoding (RLE) Compression:

Initialization:

The function takes a vector of characters chars as input, representing the string to be compressed.
It initializes two integer variables:
writeIndex (starting at 0) to keep track of the position where the compressed characters will be written in the original chars vector.
anchor (starting at 0) to mark the beginning of a group of consecutive characters (initially points to the first character).
Iterating Through Characters:

It uses a for loop that iterates through each character in the chars vector using readIndex.
Checking for Group End:

Inside the loop, it checks if the following conditions are met:
readIndex + 1 is equal to the chars size (reached the last character).
OR the character at the next index (readIndex + 1) is different from the current character (chars[readIndex]).
These conditions indicate the end of a group of consecutive characters.
Writing Current Group:

If the conditions above are true (end of group):
It copies the character at the anchor index (the first character of the group) to the current writeIndex position in the chars vector.
If there were more than one character in the group (readIndex > anchor):
It converts the group length (number of consecutive characters - readIndex - anchor + 1) to a string using to_string.
It iterates through each digit (char digit) in the converted string using another loop.
Inside this loop, it writes each digit character (digit) to the chars vector at the current writeIndex position and increments writeIndex. This encodes the group length.
After writing the character and potentially the group length, it updates the anchor index to point to the next character after the current group (anchor = readIndex + 1).
Returning Compressed Length:

After iterating through all characters, the writeIndex will point to the last element written in the compressed string within the original chars vector.
The function returns writeIndex, which represents the new length of the compressed string in the chars vector.
