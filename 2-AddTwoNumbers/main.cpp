#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

// Definition for singly-linked list give by problem description
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *resultListHead = new ListNode();
        ListNode *currentNode = resultListHead;
        int carry = 0;

        // loop till we exhaust both lists, or we have a final carry
        while(l1 != nullptr or l2 != nullptr or carry >= 1) {
            int currentVal = 0;

            // add next values, not if a list is exhausted it in effect becomes a zero
            if (l1 != nullptr) {
                currentVal += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                currentVal += l2->val;
                l2 = l2->next;
            }

            // calculate the current value and store in the result list
            currentVal += carry;
            ListNode *newNode = new ListNode(currentVal % 10);
            currentNode->next = newNode;
            currentNode = currentNode->next;

            // calculate the corry
            carry = currentVal / 10;
        }

        // solution leaks but should work for leetcode testing
        return resultListHead->next;
    }
};

//https://leetcode.com/problems/add-two-numbers/description/