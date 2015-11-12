//taken help
typedef pair<int,int> ii; 
int Solution::maximumGap(const vector<int> &a) {
    int n=a.size();
    if(n==1)
      return 0;
    vector<ii> v;
    for(int i=0;i<n;i++)
      v.push_back(ii(a[i],i));
     sort(v.begin(),v.end());
     int dp[n];
     dp[n-1]=v[n-1].second;
     for(int i=n-2;i>=0;i--)
     {
         dp[i]=max(v[i].second,dp[i+1]);
     }
     int mx=0;
     for(int i=0;i<=n-2;i++)
     {
         mx=max(mx,dp[i+1]-v[i].second);
     }
     return mx;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
