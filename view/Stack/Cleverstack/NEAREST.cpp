vector<int> Solution::prevSmaller(vector<int> &a) {
    stack<int> st;
    int n=a.size();
    vector<int> g(n,0);
    for(int i=0;i<n;i++)
    {
        if(st.empty())
        {
            g[i]=-1;
            st.push(i);
        }
        else
        {
            while(!st.empty() && a[st.top()]>=a[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                g[i]=a[st.top()];
            }
            else
            {
                g[i]=-1;
            }
            st.push(i);
        }
    }
    return g;
}
