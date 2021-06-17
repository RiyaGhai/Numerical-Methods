#include<iostream>
#include<math.h>
#include<climits>
using namespace std;
 
 float f(float x)
 {
     return x-log10(x)-7;
 }

float bm(float a,float b)
{

float mid=(a+b)/2;
for(int i=0;i<20;i++)
{
    mid=(a+b)/2;
    float midval= f(mid);
    cout<<mid<<endl;
    if(midval<0)
    {
        a=mid;
    }
    else if(midval>0)
    {
        b=mid;
    }
    else
    {
        return mid;
    }
    
    
}
return mid;
}


void iteration(float xn, int &itr)
{
    if(itr<30)
    itr++;
    else
    {
        return;
    }
    xn= f(xn);
    cout<<xn<<endl;
    iteration(xn,itr);

    
}
void secant(float xn, float xnm,int itr )
{
    if(itr<20)
    itr++;
    else
    {
        return;
    }
    
    float xn1 = xn - ((xn-xnm)/(f(xn)-f(xnm)))*f(xn);
    
    xnm=xn;
    xn=xn1;
    cout<<xn<<" : "<<xnm<<" = "<<f(xn)<<endl;
    secant(xn,xnm,itr);
}
void rf(float a, float b, float xn, int &itr)
{
    if(f(a)*f(b)>0)
    {
        cout<<"incorrect pair";
        return;
    }
    if(itr<20)
    itr++;
    else
    {
        return;
    }
    
     float xn1;
    if(f(a)<0)
    {
     xn1 = xn - (f(xn)/(f(b)-f(xn)))*(b-xn);
    }
   else
    {
     xn1 = xn - (f(xn)/(f(xn)-f(a)))*(xn-a);
    }

   cout<< xn1<<" : "<<f(xn1)<<endl;
   xn=xn1;
   rf(a,b,xn,itr);
}

int main()
{
    float a=INT_MIN,b=INT_MAX,c1=1;
    for(float i=-4;i<4;i+=0.1)
    {
        if(f(i)<0)
        {
            a=i;
        }
        if(f(i)>0&&c1)
        {
            b=i;
            c1=0;
            if(b>a)
            {
                break;
            }
        }
    }
    a=0;b=10;
     cout<<bm(a,b);
    // int itr=0;
    // float xn;
    // a=2;b=3;
    // cout<<f(a)<<" : "<<f(b)<<" pair "<<endl;
    // if(f(a)<0)
    // xn=a;
    // else
    // {
    //     xn=b;
    // }
    
    // rf(a,b,xn,itr);
    //    secant(a,b,itr);
    // iteration(2.9,itr);
    return 0;
}