**Reversing Vowels of a String**

Problem Statement 5) Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.

---------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            while (left < right && !isVowel(s[left])) {
                left++;
            }
            while (left < right && !isVowel(s[right])) {
                right--;
            }
            swap(s[left++], s[right--]);
        }

        return s;
    }

private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

----Explanation:-
Reversing Vowels in a String:

Initialization:

The function takes a string s as input.
It initializes two integer variables:
left starting index (0) to keep track of the character from the beginning.
right ending index (string size minus 1) to keep track of the character from the end.
Two-Pointer Approach:

It uses a while loop that continues as long as left is less than right (meaning there are characters to process between them). This loop iterates through the string, swapping vowels from opposite ends.
Finding Left Vowel:

Inside the loop, it uses another while loop for left:
This loop keeps moving left forward as long as the character at s[left] is not a vowel (using the isVowel function).
Finding Right Vowel:

After finding a vowel at left, it uses another while loop for right:
This loop keeps moving right backward as long as the character at s[right] is not a vowel (using the isVowel function).
Swapping Vowels:

Once both loops find valid vowels at left and right (within the main loop's while condition), it swaps the characters at these indices using the swap function.
It then increments left and decrements right to move towards the center of the string for the next vowel swap iteration.
isVowel Function (Private):

The code includes a private helper function isVowel that takes a character c as input.
It converts the character to lowercase using tolower(c).
It returns true if the lowercase character is 'a', 'e', 'i', 'o', or 'u' (vowels), and false otherwise (consonants or other characters).
Returning Reversed Vowels String:

After the main loop completes iterating through the string, the vowels will be reversed in place within the original string s.
The function returns the modified string s with reversed vowels.
