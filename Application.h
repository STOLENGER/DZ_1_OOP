//
// Created by Egor Salkov on 29.04.2020.
//

#ifndef DZ_1_OOP_APPLICATION_H
#define DZ_1_OOP_APPLICATION_H
#include <iostream>
using namespace std;
#include "Paynent.h"
#include "Array.h"

class Application {
    int callMoney=0;
    int callPayment=0;

    void Arif() {
        int a;
        cout<<"1. Проверка +\n"
              "2. Проверка -\n"
              "3. Проверка *\n"
              "4. Проверка /\n";
        cin>>a;
        cout<<"Введите значения для A";
        Money A,B;
        callMoney+=2;
        cin>>A;
        switch (a) {
            case 1:
                cout<<"Введите значения для B\n";
                cin>>B;
                cout<<A+B;
                break;
            case 2:
                cout<<"Введите значения для B\n";
                cin>>B;
                cout<<A-B;
                break;
            case 3:
                double b;
                A=A*b;
                cout<<A;
                break;
            case 4:
                double b1;
                A=A/b1;
                cout<<A;
                break;
        }
    }
    void Srav()
    {
        Money A1,B1;
        callMoney+=2;
        cout<<"Введите значения для A\n";
        cin>>A1;
        cout<<"Введите значения для B\n";
        cin>>B1;
        if(A1>B1)
            cout<<"A1>B1\n";
        if(A1>=B1)
            cout<<"A1>=B1\n";
        if(A1==B1)
            cout<<"A1==B1\n";
        if(A1<B1)
            cout<<"A1<B1\n";
        if(A1<=B1)
            cout<<"A1<=B1\n";
    }
public:
    void run1()
    {
        int a;
        cout<<"1. Проверка class Money\n"
              "2. Проверка class Paymenet \n";
        cin>>a;
        if(a==1)
        {
            cout<<"1. Арфметические операции\n"
                  "2. Операции сравнения\n";
            cin>>a;
            switch (a) {
                case 1:
                  Arif();
                case 2:
                 Srav();
            }
        } else
        {
            char firstname[20]={"salkov"};
            char name[20]={"egor"};
            char otchestvo[20]={"dmitrievich"};
            Money salary(10000,00);
            callMoney++;
            callPayment++;
            Paymenet  paymenet(firstname,name,otchestvo,salary,1990,3,22,30);
            cout<<paymenet;
        }
    }
   void run2()
   {


       int a;
       cout<<"1. Octal \n"
             "2. Decimal \n";
       cin>>a;
       Array *a1;
       Array *b ;
       Array *res;
       if(a==1)
       {
           a1 = new Octal;
           b = new Octal;
           res = new Octal;
           Octal Ar,Ar1;
           cout<<"1. Проверка +\n"
                 "2. Проверка -\n"
                 "3. Проверка *\n"
                 "4. Проверка /\n";
           cin>>a;
           cout<<"Введите значение для A\n";
           cin>>Ar;
           cout<<"Введите значение для B\n";
           cin>>Ar1;
           switch (a) {
               case 1:
                   a1->Plus(b, res);
                   cout<<res;
               case 2:

                   cout<<Ar-Ar1;
               case 3:
                    Ar=Ar*Ar1;
                    cout<<Ar;
               case 4:
                   Ar=Ar/Ar1;
                   cout<<Ar;
           }
           if(Ar>Ar1)
               cout<<"A>B\n";
           if(Ar>=Ar1)
               cout<<"A>=B\n";
           if(Ar==Ar1)
               cout<<"A==B\n";
           if(Ar!=Ar1)
               cout<<"A!=B\n";
           if(Ar<Ar1)
               cout<<"A<B\n";
           if(Ar<=Ar1)
               cout<<"A<=B\n";
       } else
       {
           Decimal D,D1;

           cout<<"1. Проверка +\n"
                 "2. Проверка -\n"
                 "3. Проверка *\n"
                 "4. Проверка /\n";
           cin>>a;
           cout<<"Введите значение для A\n";
           cin>>D;
           cout<<"Введите значение для B\n";
           cin>>D1;
           switch (a) {
               case 1:
                   a1->Plus(b, res);
                   cout<<res;
               case 2:
                   cout<<D-D1;
               case 3:
                   D=D*D1;
                   cout<<D;
               case 4:
                   D=D/D1;
                   cout<<D;

           }
           if(D>D1)
               cout<<"A>B\n";
           if(D>=D1)
               cout<<"A>=B\n";
           if(D==D1)
               cout<<"A==B\n";
           if(D!=D1)
               cout<<"A!=B\n";
           if(D<D1)
               cout<<"A<B\n";
           if(D<=D1)
               cout<<"A<=B\n";
       }
   }
    void run3()
    {

    }

};


#endif //DZ_1_OOP_APPLICATION_H


