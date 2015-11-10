using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,ii > iiii;
typedef pair<int,ii> iii;

/*bool cmp(iiii a,iiii b)
{
    bool pp= a.pw.pw<b.pw.pw || (a.pw.pw==b.p.p && a.p.q<b.p.q ) ;
bool qq;
qq= (a.p.p==b.p.p && a.p.q==b.p.q && a.q.p<b.q.p )||(a.p.p==b.p.p && a.p.q==b.p.q && a.q.p==b.q.p
&& a.q.q<b.q.q );
return pp || qq;
}*/
vector<int> Solution::equal(vector<int> &a) {
    vector<iiii> w;
    
    int n=a.size();
    map<int,ii > m;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(m.count(a[i]+a[j])==0)
            {
                m[a[i]+a[j]]=ii(i,j);
            }
            else
            {
                ii pp;
                pp=m[a[i]+a[j]];
                if(pp.first < pp.second && pp.first<i && pp.second!=i && pp.second !=j)
                w.push_back(iiii(m[a[i]+a[j]],ii(i,j)));
            }
        }
    }
   
    vector<int> ans;
    sort(w.begin(),w.end());
    if(w.size()>0)
    {
        ans.push_back(w[0].first.first);
        ans.push_back(w[0].first.second);
        ans.push_back(w[0].second.first);
        ans.push_back(w[0].second.second);
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

/*

MLE -----



    using namespace std;
    typedef pair<int,int> ii;
    typedef pair<ii,ii > iiii;
    vector<int> Solution::equal(vector<int> &a) {
        int n=a.size();
        map<int,vector<ii> > m;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(m.count(a[i]+a[j])==0)
                {
                    m[a[i]+a[j]]=vector<ii>();
                    m[a[i]+a[j]].push_back(ii(i,j));
                }
                else
                {
                    m[a[i]+a[j]].push_back(ii(i,j));
                }
            }
        }
        for(map<int,vector<ii> > ::iterator it=m.begin();it!=m.end();it++)
        {
            sort((it->second).begin(),(it->second).end());
        }
        vector<iiii> w;
        for(map<int,vector<ii> > ::iterator it=m.begin();it!=m.end();it++)
        {
            for(int i=0;i<(it->second).size();i++)
            {
                for(int j=i+1;j<(it->second).size();j++)
                {
                 ii a=(it->second)[i];
                 ii b=(it->second)[j];
                 if(a.first<b.first && a.second!=b.second && a.second !=b.first)
                 {
                     w.push_back(iiii(a,b));
                 }
                }
            }
        }
        vector<int> ans;
        sort(w.begin(),w.end());
        if(w.size()>0)
        {
            ans.push_back(w[0].first.first);
            ans.push_back(w[0].first.second);
            ans.push_back(w[0].second.first);
            ans.push_back(w[0].second.second);
            
        }
        return ans;
        // Do not write main() function.
        // Do not read input, instead use the arguments to the function.
        // Do not print the output, instead return values as specified
        // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    }

*/
