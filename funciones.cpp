#include <cstdlib>
#include <iostream>
#include <string>
#include "funciones.h"
#include<stdio.h>
#include<string.h>
using namespace std;

char* integrantes(char* pa)
{
    char* leftStr = pa;
    char* rightStr = "-f";
    char* center = "-v";
    int res = strcmp(leftStr, rightStr);
    int des = strcmp(leftStr, center);
    if (res==0)
        {}
    else{
        if(des==0)
           {
            cout<<endl;
        std::cout<<"*******************INTEGRANTES*******************"<<endl;
        cout<<"Felipe Campos"<<" - ";
        cout<<"Eloy Lopez"<<" - ";
        cout<<"Rodrigo Muñoz"<<endl;
        cout<<"*************************************************"<<endl;
            
        }
        else
            cout<<"Parametro mal ingresado"<<endl;
    }
    
    return 0;  
}
