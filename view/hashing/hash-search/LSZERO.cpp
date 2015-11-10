using namespace std;
typedef pair<int,int> ii;
bool cmp(ii a,ii b)
{
    return a.first>b.first || (a.first==b.first && a.second<b.second);
}
vector<int> Solution::lszero(vector<int> &a) {
    int n=a.size();
    int sum=0;
    map<int ,int > m;
    m[0]=-1;
    vector<ii> w;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(m.count(sum)==0)
        {
            m[sum]=i;
        }
        else
        {
            w.push_back(ii(i-m[sum],m[sum]));
        }
    }
    vector<int> ans;
    
    sort(w.begin(),w.end(),cmp);
    if(w.size()>0)
    for(int j=w[0].second+1,k=1;k<=w[0].first;j++,k++)
    {
        ans.push_back(a[j]);
    }
    
    return ans;
    
}
