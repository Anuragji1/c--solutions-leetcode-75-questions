**Delete the Middle Node of a Linked List**

Problem Statement 28) You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
 

Example 1:


Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 
Example 2:


Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.
Example 3:


Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
 

Constraints:

The number of nodes in the list is in the range [1, 105].
1 <= Node.val <= 105

-------------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) {
            return nullptr;  // Handle empty or single-node list
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;  // To store the previous node of the middle node

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;  // Bypass the middle node
        delete slow;              // Free the memory of the middle node

        return head;
    }
};

----Explanation:-
Deleting the Middle Node:

Handling Empty or Single-Node List:

The function takes a pointer head to the head node of the linked list as input.
It first checks for edge cases:
If head is null (empty list) or head->next is null (single-node list), it means there's no middle node to delete. In this case, the function returns nullptr to indicate the original list (unchanged).
Initializing Pointers:

If the list has more than one node, it initializes three pointers:
slow: A pointer that moves one step at a time, eventually pointing to the middle node.
fast: A pointer that moves two steps at a time, used to find the middle node efficiently.
prev: A pointer that will store the previous node of the middle node, needed for bypassing the middle node during deletion.
Finding the Middle Node:

It uses a while loop that continues as long as fast is not null and fast->next is not null.
Inside the loop:
It updates prev to point to the node before slow (prev = slow). This is crucial for later deletion.
It moves slow one step forward (slow = slow->next).
It moves fast two steps forward (fast = fast->next->next). This effectively makes fast reach the end of the list (or the second node from the end) in half the steps taken by slow. Since slow will be at the middle node when fast reaches the end (or second-from-end), this efficiently finds the middle node.
Deleting the Middle Node:

After the while loop, slow points to the middle node to be deleted.
It updates the next pointer of the previous node (prev->next) to point to the node after the middle node (slow->next). This effectively bypasses the middle node and removes it from the linked list.
It then deletes the middle node pointed to by slow using delete slow. This frees the memory associated with the deleted node.
Returning Head:

The function returns the original head pointer. Even though the middle node is deleted, the head pointer still points to the beginning of the modified linked list.
