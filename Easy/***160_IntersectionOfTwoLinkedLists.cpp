/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * O(n)
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;

        ListNode* pA = headA;
        ListNode* pB = headB;
        // head points to the first element
        int countA = 1, countB = 1;

        while (pA->next)
        {
        	countA++;
            pA = pA->next;
        }

        while (pB->next)
        {
            countB++;
            pB = pB->next;
        }

        if (pA != pB) return NULL;  // no intersection till the end
        else
        {
            // find the longer list and skip those eatra nodes
            if (countA < countB)
            {
                pA = headB;
                pB = headA;
            }
            else
            {
                pA = headA;
                pB = headB;
            }
            int skip = abs(countA - countB);
            for (; skip > 0; skip--)
                pA = pA->next;

            // find the first identical node
            while (pA && pB && pA != pB)
            {
                pA = pA->next;
                pB = pB->next;
            }

            return pA;

        }
    }
};