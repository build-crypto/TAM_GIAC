#ifndef TOADO_H
#define TOADO_H


class ToaDo
{
    double x;
    double y;
    public:
        ToaDo(double a = 0,double b = 0){x = a;y = b;};
        void SET_ToaDo();
        void GET_ToaDo();
    friend class TAM_GIAC;
} ;

#endif // TOADO_H
