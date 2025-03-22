#include <iostream>
using namespace std;

//overloaded function
int operate (int a, int b)
{
    return (a*b); 
}
double operate (double a,double b)
{
    return (a/b);
}

        
//  template
template <class T>
T sum(T a, T b)
 {
    T result;
    result=a+b;
    return result;
}

// namespace
namespace first
{
    int x=3;
    int y=9;
}

//data structures
struct members{
    std::string name;
    double wage;
    bool attendance;

};
int main(){
    int x=7,y=3;
    double n=7.0, m=3.0;
    cout<<operate (x,y)<<'\n';
    cout <<operate (n,m)<<'\n';

    int i=8,j=9,k;
    double f=4.0, g=0.2, h;
    k=sum<int>(i,j);
    h=sum<double>(f,g);
    cout<<k<<'\n';
    cout<<h<<'\n';

    cout<<first::x<<endl;
    cout<<first::y<<endl;
    
    members members1;
    members1.name="yirga";
    members1.wage=5000.45;
    members1.attendance=true;
    std::cout<<members1.name<<'\n';
    std::cout<<members1.wage<<'\n';
    std::cout<<members1.attendance<<'\n';
    return 0;
}
