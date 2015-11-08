bool Solution::isPower(int a) {
    vector<int> v;
    int ct=0;
    int ac=a;
    if(a==1)
    {
        return true;
    }
    if(a==2)
    {
        return false;
    }
    while((a%2)==0)
    {
        a/=2;
        ct++;
    }
    if(ct>0)
    v.push_back(ct);


    for(int i=3;i<=sqrt(ac);i+=2)
    {
      ct=0;
      while((a%i)==0)
      {
          ct++;
          a/=i;
      }
      if(ct>0)
      {
        v.push_back(ct);
        }
    }
    if(a!=1)
    {
        v.push_back(1);
    }
    if(v.size()==1)
    {
     return !(v[0]%2) || v[0]>1;
    }
    else
    {
        bool flag=true;
        for(unsigned int i=0;i<v.size();i++)
        {
            
            if(!(v[i]%2))
               continue;
            else
            {
                flag=false;
                break;
            }
        }
        if(flag==false)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
}
