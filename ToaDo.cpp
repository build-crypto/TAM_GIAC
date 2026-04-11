#include "ToaDo.h"
#include <iostream>
using namespace std;
void ToaDo::SET_ToaDo()
{
    cout<<"Nhap Toa do x: ";
    cin>>x;
    cout<<"Nhap Toa do y: ";
    cin>>y;
}
void ToaDo::GET_ToaDo()
{
    cout<<"Toa do x: "<<x<<'\n';
    cout<<"Toa do y: "<<y<<'\n';
}
void ToaDo::Scale_Point(ToaDo T,double k)
{
    x = T.x + k*(x-T.x);
    y = T.y + k*(y-T.y);
}
