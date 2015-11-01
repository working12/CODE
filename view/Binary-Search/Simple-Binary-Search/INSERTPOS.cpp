int Solution::searchInsert(vector<int> &a, int b) {
    int l=0,r=a.size()-1;
    while(l<r)
    {
        int m=l+(r-l)/2;
        if(a[m]>=b)
        {
            r=m;
        }
        else
        {
            l=m+1;
        }
    }
    if(l==a.size()-1) //remember that the if it is last element then there is a edge case.
      if(a[l]==b)
        return l;
      else
      {
          return l+1;
      }
    else
      return l;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
