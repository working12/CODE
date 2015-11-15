int Solution::trap(const vector<int> &a) {
    int n=a.size();
    int left[n],right[n];
    left[0]=0;
    for(int i=1;i<n;i++)
    {
      left[i]=max(left[i-1],a[i-1]);   
    }
    
    right[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
      right[i]=max(right[i+1],a[i+1]);   
    }
    
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int z=min(left[i],right[i])-a[i];
        if(z>=0)
            ans+=z;
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
