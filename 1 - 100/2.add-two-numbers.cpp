/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#define addTwoNumbers add_two_numbers

typedef ListNode Node;

class Solution {
  public:
    /**
     * T = O(max(n1, n2))
     * S = O(max(n1, n2))
     * 
     * n1 = length of list head_1
     * n2 = length of list head_2
     */
    Node* add_two_numbers(Node* head_1, Node* head_2) {
        int sum = 0, carry = 0;

        Node *curr_1 = head_1, *curr_2 = head_2;
        Node* dead = new Node();
        Node* curr = dead;

        while (curr_1 || curr_2) {
            sum = carry;

            if (curr_1) {
                sum = sum + (curr_1->val);
                curr_1 = curr_1->next;
            }

            if (curr_2) {
                sum = sum + (curr_2->val);
                curr_2 = curr_2->next;
            }

            curr->next = new Node(sum % 10);
            curr = curr->next;

            carry = sum / 10;
        }

        if (carry) {
            curr->next = new Node(carry);
        }

        return dead->next;
    }
};
// @lc code=end
