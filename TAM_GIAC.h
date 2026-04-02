#ifndef TAM_GIAC_H
#define TAM_GIAC_H
#include "ToaDo.h"
#include <cmath>
class TAM_GIAC
{
    public:
        TAM_GIAC(ToaDo a =(0,0),ToaDo b =(0,0),ToaDo c=(0,0)) {
            iA = a;iB = b;iC = c;
            LA=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
            LB=sqrt((b.x-c.x)*(b.x-c.x)+(b.y-c.y)*(b.y-c.y));
            LC=sqrt((c.x-a.x)*(c.x-a.x)+(c.y-a.y)*(c.y-a.y));
            };
        void SET_TAM_GIAC();
        void GET_TAM_GIAC();
        void GET_LENGTH_TAM_GIAC();
        int Check_TAM_GIAC();
        void Categorise(int t);
        double Perimeter();
        double Square();
        void Move_TAM_GIAC();
        void Circle();
        ToaDo Central();
    protected:

    private:
        ToaDo iA,iB,iC;
        double LA,LB,LC;
};

#endif // TAM_GIAC_H
