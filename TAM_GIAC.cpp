#include "TAM_GIAC.h"
#include <iostream>
#include "ToaDo.h"
#include <cmath>
using namespace std;
const double EPS = 1e-6;
void TAM_GIAC::SET_TAM_GIAC()
{
    cout<<"Nhap Toa do Tam Giac: \n";
    cout<<"Nhap Toa do thu nhat: \n";
    iA.SET_ToaDo();
    cout<<"Nhap Toa do thu hai: \n";
    iB.SET_ToaDo();
    cout<<"Nhap Toa do thu ba: \n";
    iC.SET_ToaDo();
    LA = sqrt((iA.x-iB.x)*(iA.x-iB.x)+(iA.y-iB.y)*(iA.y-iB.y));
    LB = sqrt((iB.x-iC.x)*(iB.x-iC.x)+(iB.y-iC.y)*(iB.y-iC.y));
    LC = sqrt((iC.x-iA.x)*(iC.x-iA.x)+(iC.y-iA.y)*(iC.y-iA.y));
}
void TAM_GIAC::GET_TAM_GIAC()
{
    cout<<"Tam giac co toa do 3 dinh la: \n";
    cout<<"Toa do thu nhat: \n";
    iA.GET_ToaDo();
    cout<<"Toa do thu hai: \n";
    iB.GET_ToaDo();
    cout<<"Toa do thu ba: \n";
    iC.GET_ToaDo();
    cout<<'\n';
}
void TAM_GIAC::GET_LENGTH_TAM_GIAC()
{
    cout<<LA<<" "<<LB<<" "<<LC<<'\n';
}
int TAM_GIAC::Check_TAM_GIAC()
{
    if (LA+LB<=LC||LC+LB<=LA||LA+LC<=LB) return 0;
    else if (abs(LA-LB)<EPS&&abs(LB-LC)<EPS) return 1;
    else if (abs(LA-LB)<EPS||abs(LB-LC)<EPS||abs(LA-LC)<EPS) return 2;
    else if (abs(LA*LA+LB*LB-LC*LC)<EPS||abs(LC*LC+LB*LB-LA*LA)<EPS||abs(LC*LC+LA*LA-LB*LB)<EPS) return 3;
    else return 4;
}
void TAM_GIAC::Categorise(int t)
{
    switch (t)
    {
        case 1: cout<<"TAM GIAC DEU\n";
    break;
    case 2: cout<<"TAM GIAC CAN\n";
    break;
    case 3: cout<<"TAM GIAC VUONG\n";
    break;
    case 4: cout<<"TAM GIAC THUONG\n";
    break;
    default :cout<<"KO PHAI TAM GIAC\n";
    }
}
double TAM_GIAC::Perimeter()
{
    return LA+LB+LC;
}
double TAM_GIAC::Square()
{
    double p = this->Perimeter()/2;
    return sqrt(p*(p-LA)*(p-LB)*(p-LC));
}
void TAM_GIAC::Move_TAM_GIAC()
{
    cout<<"Vui long chon toa do moi cua dinh A: "<<'\n';
    double x,y;
    cout<<"Nhap x:";
    cin>>x;
    cout<<"Nhap y:";
    cin>>y;
    double m = x-iA.x;
    double n = y-iA.y;
    iB.x += m;
    iB.y += n;
    iC.x += m;
    iC.y += n;
    iA.x = x;
    iA.y = y;
}
ToaDo TAM_GIAC::Central()
{
    double xO,yO;
    double S = iA.x*iA.x+iA.y*iA.y-iB.x*iB.x-iB.y*iB.y , R = iB.x*iB.x+iB.y*iB.y - iC.x*iC.x-iC.y*iC.y;
    yO = (R*(iA.x-iB.x)-S*(iB.x-iC.x))/(2*((iA.x-iB.x)*(iB.y-iC.y)-(iA.y-iB.y)*(iB.x-iC.x)));
    xO = (S-2*yO*(iA.y-iB.y))/(2*(iA.x-iB.x));
    ToaDo D(xO,yO);
    return D;
}


double TAM_GIAC::fix(double x) {
    if (abs(x) < EPS) return 0;
    return x;
}
void TAM_GIAC::Circle()
{
    ToaDo D = this->Central();
    double T;
    cout<<"Nhap do xoay tam giac: ";
    cin>>T;
    T= T*3.14/180;
    double m = -D.x;
    double n = -D.y;
    iB.x += m;
    iB.y += n;
    iC.x += m;
    iC.y += n;
    iA.x += m;
    iA.y += n;
    double tX,tY;

    tX = iA.x*cos(T) - iA.y*sin(T);
    tY = iA.x*sin(T) + iA.y*cos(T);
    iA.x = fix(tX);
    iA.y = fix(tY);

    tX = iB.x*cos(T) - iB.y*sin(T);
    tY = iB.x*sin(T) + iB.y*cos(T);
     iB.x = fix(tX);
    iB.y = fix(tY);

    tX = iC.x*cos(T) - iC.y*sin(T);
    tY = iC.x*sin(T) + iC.y*cos(T);

    iC.x = fix(tX);
    iC.y = fix(tY);


    iB.x -= m;
    iB.y -= n;
    iC.x -= m;
    iC.y -= n;
    iA.x -= m;
    iA.y -= n;
    LA = sqrt((iA.x-iB.x)*(iA.x-iB.x)+(iA.y-iB.y)*(iA.y-iB.y));
    LB = sqrt((iB.x-iC.x)*(iB.x-iC.x)+(iB.y-iC.y)*(iB.y-iC.y));
    LC = sqrt((iC.x-iA.x)*(iC.x-iA.x)+(iC.y-iA.y)*(iC.y-iA.y));

}
void TAM_GIAC::Scale()
{
    ToaDo D = this->Central();
    cout<<"Nhap chi so Scale: ";
    double k;
    cin>>k;
    iA.Scale_Point(D,k);
    iB.Scale_Point(D,k);
    iC.Scale_Point(D,k);
    LA = sqrt((iA.x-iB.x)*(iA.x-iB.x)+(iA.y-iB.y)*(iA.y-iB.y));
    LB = sqrt((iB.x-iC.x)*(iB.x-iC.x)+(iB.y-iC.y)*(iB.y-iC.y));
    LC = sqrt((iC.x-iA.x)*(iC.x-iA.x)+(iC.y-iA.y)*(iC.y-iA.y));
}

