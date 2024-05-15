**Decode String**

Problem Statement 25) Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
 

Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].

------------------------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        stack<char> st;
        stack<int> m;
        for(int i = 0; i < s.size() ; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                string t = "";
                t.push_back(s[i]);
                for(int j = i+1 ; j < s.size();j++){
                    if(s[j] >= '0' && s[j] <= '9'){
                        t.push_back(s[j]);
                    }
                    else{
                        i = j - 1;
                        break;
                    }
                }
                int num = stoi(t);
                m.push(num);
            }
            else if(s[i] == ']'){
                int rep = m.top();
                m.pop();
                string temp = "";
                while(!st.empty() && st.top() != '['){
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                reverse(temp.begin(),temp.end());
                string str = temp;
                for(int j = 1; j < rep; j++){
                    str += temp;
                }

                if(!st.empty()){
                    for(int k = 0; k < str.size(); k++){
                        st.push(str[k]);
                    }
                }
                else{
                    ans += str;
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string te = "";
        while(!st.empty()){
            te += st.top();
            st.pop();
        }
        reverse(te.begin(),te.end());
        ans += te;
        return ans;
    }
};

----Explanation:- 
Decoding Encoded Repetitions:

Initializing Stacks:

The function takes a string s containing the encoded string as input.
It initializes two stacks:
st: A character stack to store characters encountered during processing.
m: An integer stack to store the repetition numbers encountered for substrings.
Processing Characters:

It uses a for loop to iterate through each character (s[i]) in the input string s.
Handling Digits (Repetition Numbers):

If the current character is a digit (s[i] >= '0' && s[i] <= '9'), it represents a repetition number.
It initializes a temporary string t to store the digit characters.
It uses a nested loop to iterate through subsequent characters (j) starting from the next character after the current digit.
Inside the nested loop, it checks if the next character is also a digit. If so, it appends the digit to the t string.
The nested loop breaks (i = j - 1) when a non-digit character is encountered, marking the end of the repetition number.
Once the digit characters are collected in t, it converts the t string to an integer using stoi(t) and pushes this integer (repetition number) onto the m stack.
Handling Closing Brackets (']'):

If the current character is a closing bracket (']`), it signifies the end of a substring that needs repetition.
It pops the repetition number from the m stack (int rep = m.top()).
It initializes a temporary string temp to store the substring to be repeated.
It uses a while loop to pop characters from the st stack as long as they are not the opening bracket ('['). These characters form the substring to be repeated.
Inside the while loop, it prepends the popped character to the temp string (temp += st.top()) to maintain the correct order. It then pops the character from the st stack.
After the while loop, it pops the opening bracket ('[') from the st stack (which is no longer needed).
It reverses the temp string (reverse(temp.begin(),temp.end())) since characters were added in reverse order during the while loop. This ensures the correct order of the substring to be repeated.
It creates a new string str by concatenating the reversed temp string rep number of times (for loop). This effectively replicates the substring based on the repetition number.
Appending Decoded String:

It checks if the st stack is not empty. This indicates there might be characters before the opening bracket that need to be included in the decoded string.
If st is not empty, it iterates over the characters in str (the repeated substring) and pushes them onto the st stack (st.push(str[k])) to preserve the order for final concatenation.
If st is empty, it means there were no characters before the opening bracket, so it directly appends the entire str (repeated substring) to the ans string (ans += str).
Handling Other Characters:

If the current character is not a digit or a closing bracket, it's assumed to be a normal character that needs to be included in the decoded string. In this case, it simply pushes the character onto the st stack (st.push(s[i])).
Final Processing and Returning Result:

After iterating through all characters in the input string, the st stack might still contain characters that weren't part of any repetitions.
It initializes a temporary string te and uses a while loop to pop characters from the st stack and append them to te in reverse order (using reverse).
It concatenates the reversed te string to the ans string (ans += te), forming the final decoded string.
The function returns the ans string as the decoded result.
