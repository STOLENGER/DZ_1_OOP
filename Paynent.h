//
// Created by Egor Salkov on 11.05.2020.
//

#ifndef DZ_1_OOP_PAYNENT_H
#define DZ_1_OOP_PAYNENT_H

class Money{
    long rub;
    unsigned char cop;
    //int callClass=0;
public:
    Money()
            :rub(0)
            , cop(00)
    {}
    Money(long rub,unsigned char cop)
    {
        this->rub=rub;
        this->cop=cop;

    }
    ~Money()
    {
      //  callClass++;
    }
    int GetcallClass()  const
    {
        return GetcallClass();
    }
    Money& operator+(const Money& other)
    {
        Money res(*this);
        res.rub+=other.rub;
        res.cop+=other.cop;
        if(res.cop>=100)
        {
            res.rub++;
            res.cop-=100;
        }
        return res;
    }


    Money& operator-(const Money& other)
    {
        Money res(*this);
        res.rub-=other.rub;
        if(other.cop>res.cop)
        {
            res.rub--;
            res.cop+=100-other.cop;
        } else
        {
            res.cop-=other.cop;
        }
        return (res);
    }
    Money operator=(const Money &other)
    {
        if (this==&other)
            return *this;
        this->rub=other.rub;
        this->cop=other.cop;
        return *this;

    }
    bool operator==(const Money &other)
    {
        return (this->rub == other.rub) && (this->cop == other.cop);
    }
    bool operator!=(const Money &other)
    {
        return !((this->rub == other.rub) && (this->cop == other.cop));
    }
    bool operator>(const Money &other)
    {
        if(this->rub>other.rub)
            return true;
        else
        if(this->rub==other.rub)
        {
            return this->cop > other.cop;
        }
    }
    bool operator>=(const Money &other)
    {
        return !operator<(other);
    }
    bool operator<=(const Money &other)
    {
        return !operator>(other);
    }
    bool operator<(const Money &other)
    {
        if(this->rub<other.rub)
            return true;
        else
        if(this->rub==other.rub)
        {
            return this->cop < other.cop;
        }
    }

    Money operator*(double a)
    {
        this->rub*=a;
        int d= this->cop*a;
        this->rub+=d/100;
        this->cop+=d%100;
        return *this;
    }
    Money operator/(double a)
    {
        this->rub= this->rub/a;
        this->cop= this->cop/a;
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &out, Money &other) {
        out << other.rub <<','<<other.cop<<std::endl;
        return out;
    }
    friend  std::istream &operator>>(std::istream &in, Money &other)
    {
        in >>other.rub;
        in >>other.cop;
        return in;
    }

};


class Paymenet
{
    char firstname[20];
    char name[20];
    char otchestvo[20];
    Money salary;
    int year;
    float proc;
    Money Nalog;
    int spentday;
    int workday;
    Money NaSum;
    Money HoldSum;
public:
    Paymenet( char *firstname,char *name,char *otchestvo,Money salary,int year,float proc,int spentday,int workday)
    {
        strcpy(this->firstname,firstname);
        strcpy(this->name,name);
        strcpy(this->otchestvo,otchestvo);
        this->salary=salary;
        this->year=year;
        this->proc=proc;
        this->spentday=spentday;
        this->workday=workday;
        NaSum=salary*spentday/workday+salary*proc;
        HoldSum=NaSum-Nalog-NaSum*0.01;
        Nalog=NaSum*0.13;
    }

    int GetYear()  const
    {
        return 2020-year;
    }
    Money GetNaSum () const
    {
        return NaSum;
    }
    Money GetHoldSum()  const
    {
        return HoldSum;
    }
    Money GetNalog()  const
    {
        return Nalog ;
    }
    Money GetMoney()
    {
        return NaSum-HoldSum;
    }
    friend std::ostream &operator<<(std::ostream &out, Paymenet &other) {
        out << "firstname " <<other.firstname<<"\nname "<<other.name<<"\notchestvo "
        <<other.otchestvo<<"\nyear "<<other.GetYear()<<"\nmomey "<<other.NaSum-other.HoldSum<<std::endl;
        return out;
    }

};


#endif //DZ_1_OOP_PAYNENT_H
