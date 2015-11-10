/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 using namespace std;
 typedef long long ll;
 /*
 m= new -> old
 rm = old ->new 
 These are the 2 maps and they play the key role..Use of rm is the technique here. :-)
 
 */
RandomListNode* Solution::copyRandomList(RandomListNode* a) {
    RandomListNode *p=new RandomListNode(0),*q;
    q=p;
    RandomListNode *f=a;
    map <RandomListNode *,RandomListNode *> m,rm;
    int ct=0;
    while(f!=NULL)
    {
        ct++;
       f=f->next;   
    }
    f=a;
    for(int i=0;i<ct;i++)
    {
        p->next=new RandomListNode(0);
        m[p->next]=f;
        rm[f]=p->next;
        p=p->next;
        f=f->next;
    }
    p=q->next;
    f=a;
    RandomListNode *z;
    for(int i=0;i<ct;i++)
    {
        p->label=m[p]->label;
        z=p->next;
        p->next=rm[m[p]->next];
        p->random=rm[m[p]->random];
        p=z;
    }
     RandomListNode *pp=q->next;
    free(q);
    return pp;
    
    
}
