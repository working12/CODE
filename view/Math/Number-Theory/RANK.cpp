// Nothing tricky..I have gone for O(n^2) solution..that decision is correct here..so :-) AC.
int Solution::findRank(string a) {
    string s=a;
    int ans=1;
    vector<int> fact(1000000+1,1);
    const int mod=1000003;
    for(int i=2;i<=1000000;i++)
    {
        fact[i]=(i*fact[i-1])%mod;
    }
    int n=s.length();
    vector<int> vis(n,false);
    for(int i=0;i<n;i++)
    {
        int ct=0;
        for(int j=0;j<=n-1;j++)
        {
            if(!vis[j] && j!=i && s[j]<s[i])
            {
                ct++;
            }
        }
        vis[i]=true;
        ans+=(fact[n-i-1]*ct)%mod;
        ans%=mod;
    }
    return ans;
    
}
