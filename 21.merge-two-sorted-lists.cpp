/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
#include <list>
using namespace std;
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;

        ListNode *p1 = list1;
        ListNode *p2 = list2;

        // Merge until one list ends
        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1->val <= p2->val)
            {
                tail->next = p1;
                p1 = p1->next;
            }
            else
            {
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
        }

        // Attach the remaining part
        if (p1 != nullptr)
            tail->next = p1;
        else
            tail->next = p2;

        // The merged list starts at dummy->next
        return dummy->next;
    }
};
// @lc code=end
