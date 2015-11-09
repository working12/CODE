bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.second<b.second || (a.second == b.second && a.first<b.first);
}
vector<int> Solution::twoSum(const vector<int> &a, int b) {
    map<int,int> m;
    vector< pair<int,int> > v; 
    for(int i=a.size()-1;i>=0;i--)
    {
          
          if(m.count(b-a[i])>0)
        {
            if(i+1<m[b-a[i]])
            v.push_back(pair<int,int> ( i+1,m[b-a[i]]));
        }   
         m[a[i]]=i+1;
           
    }
    /*for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
    {
       // cout<<"- "<<it->first<<" -"<<it->second<<" ";
    }*/
    //std::cout<<m.size()<<endl;
    vector<int> z;
    
    sort(v.begin(),v.end(),cmp);
    if(v.size()>0)
    {
    z.push_back(v[0].first);
    z.push_back(v[0].second);
    }
    return z;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
