bool pred(long long a[],int n,int k,long long val)
{
    vector<long long > v;
    long long s=0,mx=-1;
    for(int i=0;i<n;i++) mx=max(mx,a[i]); //This is a easy way to check initially . A small trick.
    if(mx>val)
    return false;
    for(int i=0;i<n;i++)
    {
        if(s+a[i]<=val)
          s+=a[i];
        else
        {
            v.push_back(s);
            s=a[i];
        }
    }
    if(s>0)
      v.push_back(s);
    if(v.size()<=k)
       return true;
    else
       return false;
}
int Solution::paint(int a, int b, vector<int> &c) {
    int n=c.size();
    if(n==1)
       return c[0]*b;
    long long ac[n],mx=0,s=0;
    for(int i=0;i<n;i++)
    {
        ac[i]=c[i]*1; //initially doing c[i]*b but that's not necessary. As if we move considering 
                      // only 1 unit of time then for b unit work we can simple scale up multiplting with b.
        mx=max(ac[i],mx);
        s+=ac[i];
    }
    
    long long l,r;
    l=1,r=s; // atmost sum of the sizes time required.
    while(l<r)
    {
        long m=l+(r-l)/2;
        if(pred(ac,n,a,m))
        {
            r=m;
        }
        else
        {
            l=m+1;
        }
    }
    
    return (r*b)%(10000003);
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
