//
// Created by Egor Salkov on 11.05.2020.
//
#include <iostream>
using namespace std;

class Array
{
    unsigned char *arr;


public:
    int Size;
    Array()
            :arr(nullptr)
    {}
    Array(int Size)
    {
        this->Size=Size;
        arr=new unsigned char[100];
        for (int i = 0; i <100 ; ++i) {
            arr[i]=0;
        }
    }
    int GetSize() const
    {
        return Size;
    }
    Array operator=(const Array &other)
    {
        if (this==&other)
            return *this;
        this->Size=other.Size;
        for (int i = 0; i <other.Size ; ++i) {
            this->arr[i]=other.arr[i];
        }
        return *this;
    }
    unsigned char & operator[](int i)
    {
        if (i > this->Size) {
             throw "Out of range exception";
        }
        return arr[i];
    }
    bool operator>(Array& other)
    {
        if(this->Size<other.Size)
            return false;
        if(this->Size>other.Size)
            return true;
        for (int i = other.Size; i >0 ; --i) {
            if (this->arr[i]<other[i])
                return false;
        }
        return true;
    }
    bool operator<=(Array& other)
    {
        return !operator>(other);
    }
    bool operator<(Array& other)
    {
        if(this->Size>other.Size)
            return false;
        if(this->Size<other.Size)
            return true;
        for (int i = other.Size; i >0 ; --i) {
            if (this->arr[i]>other[i])
                return false;
        }
        return true;
    }
    bool operator>=(Array& other)
    {
        return !operator<(other);
    }
    bool operator==(Array& other)
    {
        if(this->Size!=other.Size)
            return false;
        for (int i = 0; i <other.Size ; ++i) {
            if (this->arr[i]!=other[i])
                return false;
        }
        return true;
    }
    bool operator!=(Array& other)
    {
        return !operator==(other);
    }

    virtual void  Plus( Array *other,Array * result) {
        if (this->GetSize() >= other->GetSize()) {
            for (int i = 0; i < other->GetSize(); ++i) {
                result->operator[](i) = other->operator[](i) + this->operator[](i);
                if (result->operator[](i) >= 10) {
                    result->operator[](i) -= 10;
                    if (result->operator[](i + 1) == '\0') {
                        result->Size++;
                        result->operator[](i + 2) = '\0';
                    }
                    result->operator[](i + 2) += 1;
                }
            }

        } else {
           Array *tmp;
            tmp = other;
            other = result;
            result = tmp;
            if (this->GetSize() >= other->GetSize()) {
                for (int i = 0; i < other->GetSize(); ++i) {
                    result->operator[](i) = other->operator[](i) + this->operator[](i);
                    if (result->operator[](i) >= 10) {
                        result->operator[](i) -= 10;
                        if (result->operator[](i + 1) == '\0') {
                            result->Size++;
                            result->operator[](i + 2) = '\0';
                        }
                        result->operator[](i + 2) += 1;
                    }
                }

            }

        }
}

    friend std::ostream &operator<<(std::ostream &out,Array &other) {
        for (int i = other.Size; i >0 ; --i) {
            cout<<other[i];
        }

        return out;
    }
   friend  std::istream &operator>>(std::istream &in, Array &other)
    {
        cout<<"Введите размер числа \n";
        cin>>other.Size;
        cout<<"Введите число\n";
        for (int i = other.Size; i >0 ; --i) {
            cin>>other[i];
        }
        return in;
    }

};
class Octal : public Array
{
    unsigned char *arr;
    int Size;
    int GetSize() const
    {
        return Size;
    }
public:

    void  Plus( Array *other,Array * result) {
        Array res(*this);
        if (res.GetSize() >= other->GetSize()) {
            for (int i = 0; i < other->GetSize(); ++i) {
                res[i] += other->operator[](i);
                if (res[i] >= 8) {
                    res[i] -= 8;
                    if (res[i + 1] == '\0') {
                        res.Size++;
                        res[i + 2] = '\0';
                    }
                    res[i + 1] += 1;
                }
            }

        } else {
            Array tmp(*this);
            tmp=*other;
            *other=res;
            res=tmp;
            for (int i = 0; i < other->GetSize(); ++i) {
                res[i] += other->operator[](i);
                if (res[i] >= 8) {
                    res[i] -= 8;
                    if (res[i + 1] == '\0') {
                        Size++;
                        res[i + 2] = '\0';
                    }
                    res[i + 1] += 1;
                }
            }
        }
        *result=res;
    }

    Octal& operator-(Octal&other)
    {
        Octal res(*this);
        if (res>other)
        {
            for (int i = 0; i <other.GetSize() ; ++i) {
                if (other.operator[](i)>res[i])
                {
                    int j=i+1;
                    while (res[j]==0){
                        res[j]=7;
                    }
                    res[i]=res[i]+8-other.operator[](i);
                } else
                {
                    res[i]-=other.operator[](i);
                }

            }
        } else
        {
            throw "Мы не можем вычитать из значение которое меньше другого";
        }
        return res;
    }
    Octal& operator*(Octal &other)
    {

        Octal res(*this);

        for (int j = 0; j <res.GetSize() ; ++j) {
            res[j]=0;
        }
        for (int j = 0; j <other.GetSize() ; ++j){
            for (int i = 0; i < this->GetSize(); ++i) {

                res[i+j] += this->operator[](i) * other.operator[](j) % 8;
                if (( res[i +j+ 1]=='\0')&&(this->operator[](i) * other.operator[](j) / 8>0))
                {
                    res[i +j+ 2]='\0';
                    res.Size++;
                    res[i +j+ 1]=0;
                }
                res[i +j+ 1] += (this->operator[](i) * other.operator[](j));//нужно чтобы век по умол был 0
                //нужнв проверка на последний эл-т
            }
        }
        return res;

    }
    Octal operator/( Octal& other)
    {
        Octal *result;
        int m = 1;
        int c = 0;
        for (int i = 0; i < this->Size; i++)
        {
            c += m * (this->operator[](i) - '0');
            m *= 10;
        }
        int k = 0;
        m = 1;
        for (int i = 0; i < other.GetSize(); i++)
        {
            k += m * (other.operator[](i) - '0');
            m *= 8;
        }
        int sum = c / k;
        int sum1 = sum;
        int r = 0;
        while (sum != 0)
        {
            sum /= 8;
            r++;
        }
        result->Size = r;
        for (int i = 0; i < r; i++)
        {
            result->operator[](i) = (sum1 % 8) + '0';
            sum1 /= 8;
        }
        return *result;
    }

};
class Decimal : public Array {
    unsigned char *arr;
    int Size;
public:

    Decimal& operator-(Decimal &other)
    {
        Decimal res(*this);

        if (res>other)
        {
            for (int i = 0; i <other.GetSize() ; ++i) {
                if (other.operator[](i)>res[i])
                {
                    int j=i+1;
                    while (res[j]==0){
                        res[j]=9;
                    }
                    res[i]=res[i]+10-other.operator[](i);
                } else
                {
                    res[i]-=other.operator[](i);
                }

            }
        } else
        {
           throw "Мы не можем вычитать из значение которое меньше другого";
        }
       return res;
    }
    void  Plus( Array *other,Array * result) {
        Array res(*this);
        if (res.GetSize() >= other->GetSize()) {
            for (int i = 0; i < other->GetSize(); ++i) {
                res[i] += other->operator[](i);
                if (res[i] >= 10) {
                    res[i] -= 10;
                    if (res[i + 1] == '\0') {
                        res.Size++;
                        res[i + 2] = '\0';
                    }
                    res[i + 1] += 1;
                }
            }

        } else {
            Array tmp(*this);
            tmp=*other;
            *other=res;
            res=tmp;
            for (int i = 0; i < other->GetSize(); ++i) {
                res[i] += other->operator[](i);
                if (res[i] >= 10) {
                    res[i] -= 10;
                    if (res[i + 1] == '\0') {
                        Size++;
                        res[i + 2] = '\0';
                    }
                    res[i + 1] += 1;
                }
            }
        }
        *result=res;
    }
    Decimal& operator*(Decimal &other)
    {
        Decimal res(*this);
        for (int j = 0; j <res.GetSize(); ++j) {
            res[j]=0;
        }
        for (int j = 0; j <other.GetSize(); ++j){
            for (int i = 0; i < this->GetSize(); ++i) {

                res[i+j] += this->operator[](i) * other.operator[](j)% 10;
                if (( res[i +j+ 1]=='\0')&&(this->operator[](i) * other.operator[](j) / 10>0))
                {
                    res[i +j+ 2]='\0';
                    res.Size++;
                    res[i +j+ 1]=0;
                }
                res[i +j+ 1] +=this->operator[](i) * other.operator[](j) / 10;//нужно чтобы век по умол был 0
                //нужнв проверка на последний эл-т
            }
        }
        return res;
    }
    Decimal operator/( Decimal& other)
    {
        Decimal result;
        int m = 1;
        int c = 0;
        for (int i = 0; i < this->Size; i++)
        {
            c += m * (this->operator[](i) - '0');
            m *= 10;
        }
        int k = 0;
        m = 1;
        for (int i = 0; i < other.GetSize(); i++)
        {
            k += m * (other.operator[](i) - '0');
            m *= 10;
        }
        int sum = c / k;
        int sum1 = sum;
        int r = 0;
        while (sum != 0)
        {
            sum /= 10;
            r++;
        }
        result.Size = r;
        for (int i = 0; i < r; i++)
        {
            result.operator[](i) = (sum1 % 10) + '0';
            sum1 /= 10;
        }
        return result;
    }

};


