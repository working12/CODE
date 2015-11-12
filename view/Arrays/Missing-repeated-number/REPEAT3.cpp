typedef long long ll;
int Solution::repeatedNumber(const vector<int> &a) {
    ll INF=1000000007;
    ll x=INF,y=INF,xc=0,yc=0;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        if(x==a[i])
        {
            xc++;
            continue;//these continue is important
        }
        if(y==a[i])
        {
            yc++;
            continue;//these continue is important
        }
        if(xc==0)
        {
            xc++;
            x=a[i];
            continue;
        }
        if(yc==0)
        {
            yc++;
            y=a[i];
            continue;
        }
        
        xc--;
        yc--;
    }
   // cout<<x<<" "<<y<<endl;
    int ctx=0,cty=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
            ctx++;
        if(a[i]==y)
            cty++;
    }
    if(ctx>(n/3))
      return x;
    else if(cty>(n/3))
     return y;
     else
    return -1;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
