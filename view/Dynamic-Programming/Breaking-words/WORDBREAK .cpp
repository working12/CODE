
// Here I have a learnt a new thing.. This solution was getting MLE as passing by value. After changing
// to pass by reference I have got rid of it.
    int wb(int index,string& s,map<string,int>& m,int* mem)
    {
        string t="";
        if(index>=s.length())
        return 1;
        if(mem[index]!=-1)
        return mem[index];
        int res=0;
        for(int i=index;i<=s.length() && res==0;i++)
        {
            t+=s[i];
        
            if(m.count(t)>0)
            {
                 res=res |  wb(i+1,s,m,mem);
            }
        }
        return mem[index]=res;
        
    }
    int Solution::wordBreak(string A, vector<string> &B) {
        map<string,int> m;
        for(int i=0;i<B.size();i++)
        {
            m[B[i]]=1;
        }
        int n=A.length();
        int mem[n];
        fill(mem,mem+n,-1);
        return wb(0,A,m,mem);
        // Do not write main() function.
        // Do not read input, instead use the arguments to the function.
        // Do not print the output, instead return values as specified
        // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    }

