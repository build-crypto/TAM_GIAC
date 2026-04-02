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
