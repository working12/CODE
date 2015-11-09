typedef long long ll;
// The main trick here is ..take vector<bool> p(a,false) instead of p[a+1] or something simialr like p[30000000].

vector<int> Solution::primesum(int a) {
    vector<ll> v;
    vector<bool> p(a+1,false);
    p[0]=false;
    p[1]=false;
    for(ll i=2;i<=a;i++)
    {
        if(!p[i])
        {
            for(ll j=i*i;j<=a;j+=i)
            {
                p[j]=true;
            }
            
            p[i]=true;
            v.push_back(i);
        }
    }
    vector<int> z;int f=0;
    int i=0,j=v.size()-1;
    while(i<=j)
    {
        if(v[i]+v[j]>a)
          j--;
          else if(v[i]+v[j]<a)
          i++;
          else
          {
              z.push_back(v[i]);
              z.push_back(v[j]);
              return z;
          }
           
    }
   
}
