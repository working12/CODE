typedef long long ll;
int Solution::cntBits(vector<int> &a) {
    int n=a.size();
   
    ll ans=0;
    ll ep=1000000007;
    for(int i=0;i<32;i++)
    {
        int ct=0;
        for(int j=0;j<n;j++)
        {
           if(((ll)a[j]&(1LL<<i))>0)
             ct++;
             
        }
       
        ans=(ans+(2*(1LL*(ll)ct*(ll)(n-ct))%ep)%ep)%ep;
    }
    return ans;
    
}
