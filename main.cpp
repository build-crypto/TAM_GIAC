#include "TAM_GIAC.h"
#include <iostream>
#include "ToaDo.h"
using namespace std;

int main()
{
    TAM_GIAC D;
    D.SET_TAM_GIAC();
    D.GET_TAM_GIAC();
    D.GET_LENGTH_TAM_GIAC();
    D.Categorise(D.Check_TAM_GIAC());

    cout<<"\nChu vi va Dien tich tam giac la:"<<D.Perimeter()<<" && "<<D.Square()<<'\n';
    (D.Central()).GET_ToaDo();
    return 0;
}
