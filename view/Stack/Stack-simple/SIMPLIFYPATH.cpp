string Solution::simplifyPath(string s) {
    stack<string> st;
    int flag=0;
    for(int i=0;i<s.length();)
    {
        if(s[i]=='/' && flag==0)
        {
            st.push("/");
            i++;
            int j;
            string temp="";
            for(j=i;j<=s.length()-1 && s[j]!='/';j++)
            {
                temp+=s[j];
            }
            i=j;
            if(temp==".")
            {
                continue;
            }
            else if(temp=="..")
            {
                if(!st.empty())
                {
                    if(st.top()=="/")
                    {}
                    else
                    st.pop();
                }
                else
                {
                    return "error";
                }
            }
            else
            {
                if(temp!="")
                    st.push(temp);
            }
            flag=1;
        }
        else if(flag==1 && s[i]=='/')
        {
            int j;
            string temp="";
            i++;
            for(j=i;j<=s.length()-1 && s[j]!='/';j++)
            {
                temp+=s[j];
            }
            i=j;
            if(temp==".")
            {
                continue;
            }
            else if(temp=="..")
            {
                if(!st.empty())
                {
                    if(st.top()=="/")
                    {}
                    else
                    st.pop();
                }
                else
                {
                    return "error";
                }
            }
            else
            {
                if(temp!="")
                    st.push(temp);
            }
        }
        else
        {}
        
    }
    string answer="";
    while(!st.empty())
    {
        string p=st.top();
        st.pop();
        if(answer=="")
        answer=p+answer;
        else if(p=="/")
        {
            if(answer[0]!='/')
            answer=p+answer;
        }
        else
        {
            string z="";
            if(p[p.length()-1]!='/' )
            z=z+p+"/";
                        
            answer=z+answer;
        }
    }
    
    //reverse(answer.begin(),answer.end());
    return answer;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
