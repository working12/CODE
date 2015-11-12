typedef pair<int,int> aa;
typedef long long ll;
bool cmp(aa a,aa b)
{
    return a.first<b.first;
}
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int k) {
    vector<aa> v;
    int n=arrive.size();
    for(int i=0;i<n;i++)
    {
        v.push_back(aa(arrive[i],1));
    }
    for(int i=0;i<n;i++)
    {
        v.push_back(aa(depart[i],-1));
    }
    sort(v.begin(),v.end(),cmp);
    int ct=0;
    for(ll i=0;i<=v.size()-1;)
    {
        ct+=v[i].second;
        i++;
        while(i<=v.size() && v[i].first==v[i-1].first)
        {
            ct+=v[i].second;
            i++;
        }
        
        if(ct>k)
         return false;
    }
    return true;
}
