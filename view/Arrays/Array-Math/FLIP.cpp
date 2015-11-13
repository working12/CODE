vector<int> Solution::flip(string s) {
    int one,zero;
    int n=s.length();
    int dp[n],h[n];
    for(int i=0;i<n;i++)
    {
        h[i]=s[i]-'0';
        if(h[i]==1)
           h[i]=-1;
           else
           h[i]=1;
    }
    dp[0]=h[0];
    int ms=-1,me=-1;
    for(int i=1;i<n;i++)
    {
        dp[i]=max(dp[i-1]+h[i],h[i]);
    }
    vector<int> v;
    int p= *max_element(dp,dp+n);
    if(p<=0)
      return v;
    else
    {
        int max_so_far = 0;
        int max_ending_here = 0;
        int max_start_index = 0;
        int startIndex = 0;
        int max_end_index = -1;

        for(int i = 0; i < n; i++) 
        {
            if(0 > max_ending_here +h[i]) 
            {
                startIndex = i+1;
                max_ending_here = 0;
            }
            else 
            {
                max_ending_here += h[i];
            }

            if(max_ending_here > max_so_far) 
            {
                max_so_far = max_ending_here;
                max_start_index = startIndex;
                max_end_index = i;
            }
        }

    if(max_start_index <= max_end_index) {
      v.push_back(max_start_index+1);
      v.push_back(max_end_index+1);
      return v;
    }
    }
}
