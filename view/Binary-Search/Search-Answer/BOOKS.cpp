bool pred(vector<int> &a,int v,int b)
{
    vector<int> temp;
    int s=0;
    int mx=0;
    for(int i=0;i<a.size();i++) mx=max(mx,a[i]);
    if(mx>v)
      return false;
    for(int i=0;i<a.size();i++)
      if(s+a[i]<=v)
        s=s+a[i];
      else
      {
          temp.push_back(s);
          s=a[i];
      }
     if(s>0)
       temp.push_back(s);
     if(temp.size()<=b)
       return true;
     else
      return false;
        
}
int Solution::books(vector<int> &a, int b) {
    
    int l,r;
    int s=0;
    if(a.size()<b)
      return -1;
    for(int i=0;i<a.size();i++)s+=a[i];
    l=1,r=s;
    
    while(l<r)
    {
        int m=l+(r-l)/2;
        if(pred(a,m,b)==true)
        {
            r=m;
        }
        else
         l=m+1;
    }
    
    return l;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
