// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])
int Solution::coverPoints(vector<int> &x, vector<int> &y) {
    int px,py;
    int ans=0;
    px=x[0];py=y[0];
    for(int i=1;i<x.size();i++)
    {
        int xx=x[i];
        int yy=y[i];
        if(xx==px && yy==py)
        {
            ans+=0;
            px=xx;
            py=yy;
        }
        else if(xx==px && yy!=py)
        {
            ans+=abs(py-yy);
            px=xx;
            py=yy;
        }
        else if(xx!=px && yy==py)
        {
            ans+=abs(px-xx);
            px=xx;
            py=yy;
        }
        else
        {
            int p1x,p1y,p2x,p2y,p3x,p3y,p4x,p4y;
            p1x=xx;
            p2x=xx;
            p1y=p1x-px+py;
            p2y=-p2x+px+py;
            p3y=yy;
            p4y=yy;
            p3x=p3y+px-py;
            p4x=-p3y+px+py;
            int a1,a2,a3,a4;
            /*std::cout<<"( p1x= "<<p1x<<" , "<<"p1y= "<<p1y<<" )";
            
            std::cout<<"( p2x= "<<p2x<<" , "<<"p2y= "<<p2y<<" )";
            std::cout<<"( p3x= "<<p3x<<" , "<<"p3y= "<<p3y<<" )";
            std::cout<<"( p4x= "<<p4x<<" , "<<"p4y= "<<p4y<<" )\n";*/
            a1= (abs(p1x-px)+abs(p1y-py))/2+abs(p1y-yy);
            a2= (abs(p2x-px)+abs(p2y-py))/2+abs(p2y-yy);
            a3= (abs(p3x-px)+abs(p3y-py))/2+abs(p3x-xx);
            a4= (abs(p4x-px)+abs(p4y-py))/2+abs(p4x-xx);
            //std::cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<endl;
            ans+=min(min(a1,a2),min(a3,a4));
            px=xx;
            py=yy;
        }
    }
    return ans;
}
