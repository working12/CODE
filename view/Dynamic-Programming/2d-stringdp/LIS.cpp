int Solution::lis(const vector<int> &a) {
    int n=a.size();
    int dp[n];
    fill(dp,dp+n,0);
    
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        dp[i]=1;//this line is important
        for(int j=i-1;j>=0;j--)
        {
            if(a[i]>a[j])
            dp[i]=max(dp[i],dp[j]+1);
        }
    }
    return *max_element(dp,dp+n);
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
