**Maximum Twin Sum of a Linked List**

Problem Statement 31) In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.

 

Example 1:


Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6. 
Example 2:


Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 
Example 3:


Input: head = [1,100000]
Output: 100001
Explanation:
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.
 

Constraints:

The number of nodes in the list is an even integer in the range [2, 105].
1 <= Node.val <= 105

------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int maxTwinSum = 0;

        // Find the middle node using two pointers
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* reversedSecondHalf = reverseList(slow);

        // Iterate through both halves to find maximum twin sum
        ListNode* firstHalf = head;
        ListNode* secondHalf = reversedSecondHalf;
        while (secondHalf) {
            maxTwinSum = max(maxTwinSum, firstHalf->val + secondHalf->val);
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Restore the original list
        reverseList(reversedSecondHalf);  // Reverse back the second half

        return maxTwinSum;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

-----Explanation:-
Finding Maximum Twin Sum in a Linked List:

Finding the Middle Node:

The function takes a pointer head to the head node of the linked list as input.
It initializes two pointers:
slow: A pointer that moves one step at a time.
fast: A pointer that moves two steps at a time.
It uses a while loop that continues as long as fast and fast->next are not null (to avoid going out of bounds). This loop efficiently finds the middle node of the list.
Inside the loop:
slow = slow->next: Moves slow one step forward.
fast = fast->next->next: Moves fast two steps forward.
Reversing the Second Half:

After the loop, slow will be pointing to the middle node. This marks the beginning of the second half of the list.
It calls a helper function reverseList (defined privately) to reverse the second half of the linked list starting from slow. The reverseList function is assumed to be implemented as explained in question 30 (iteratively reversing links). Reversing the second half is necessary to efficiently compare elements from both halves later.
Finding Maximum Twin Sum:

The function initializes two new pointers:
firstHalf: A pointer that starts at the head (head) of the original (unreversed) list.
secondHalf: A pointer that starts at the head of the reversed second half (reversedSecondHalf).
It uses a while loop that continues as long as secondHalf is not null (i.e., both halves haven't been fully traversed).
Inside the loop:
It calculates the sum of the current elements from both halves: maxTwinSum = max(maxTwinSum, firstHalf->val + secondHalf->val). The max function ensures it keeps track of the maximum sum encountered so far.
It moves both pointers one step forward:
firstHalf = firstHalf->next: Moves firstHalf to the next node in the first half.
secondHalf = secondHalf->next: Moves secondHalf to the next node in the reversed second half (which corresponds to the second half of the original list in the correct order due to the reversal).
Restoring the Original List:

Since the second half was reversed for efficient comparison, it needs to be reversed back to its original state.
It calls the reverseList function again, but this time passing reversedSecondHalf (which points to the head of the reversed second half) to reverse it back to its original order.
Returning the Maximum Twin Sum:

After processing both halves and potentially restoring the second half, the function returns the maxTwinSum which represents the maximum sum of two elements (one from each half) found during the traversal.
