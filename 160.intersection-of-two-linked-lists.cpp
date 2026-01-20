/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#include <stdio.h>
using namespace std;
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        for (ListNode *a = headA; a != NULL; a = a->next)
        {
            for (ListNode *b = headB; b != NULL; b = b->next)
            {
                if (a == b)
                {
                    return a;
                }
            }
        }
        return NULL;
    }
};
// @lc code=end
