/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* a, ListNode* b) {
    if(a==NULL)
    return b;
    if(b==NULL)
    return a;
    ListNode *p=new ListNode(-1000000);
    ListNode *pc=p;
    while(a && b)
    {
        if(a->val<b->val)
        {
            p->next=a;
            a=a->next;
            p=p->next;
        }
        else
        {
            p->next=b;
            b=b->next;
            p=p->next;
            
        }
    }
    while(a)
    {
        p->next=a;
        a=a->next;
        p=p->next;
    }
    while(b)
    {
        p->next=b;
        b=b->next;
        p=p->next;
    }
    p->next=NULL;
    return pc->next;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
