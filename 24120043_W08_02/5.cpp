#include <iostream>
#include <cmath>

using namespace std;

class Hinh
{
public:
    virtual ~Hinh() {};
};

class HinhHocPhang : public Hinh
{
protected:
    float _chuVi, _dienTich;

public:
    friend ostream &operator<<(ostream &, const HinhHocPhang &);
    virtual ~HinhHocPhang() {};
};

ostream &operator<<(ostream &os, const HinhHocPhang &hhp)
{
    os << "[P = " << hhp._chuVi << ", S = " << hhp._dienTich << "]";
    return os;
}

class HinhTron : public HinhHocPhang
{
private:
    int _banKinh;

public:
    HinhTron(const float &);
    friend ostream &operator<<(ostream &, const HinhTron &);
};

HinhTron::HinhTron(const float &bk) : _banKinh(bk)
{
    _chuVi = 2 * bk * 3.14;
    _dienTich = 3.14 * bk * bk;
}

ostream &operator<<(ostream &os, const HinhTron &ht)
{
    os << "Hinh Tron ";
    os << (HinhHocPhang)ht;

    return os;
}

class HinhTamGiacDeu : public HinhHocPhang
{
private:
    float _canh;

public:
    HinhTamGiacDeu(const float &);
    friend ostream &operator<<(ostream &, const HinhTamGiacDeu &);
};

HinhTamGiacDeu::HinhTamGiacDeu(const float &f) : _canh(f)
{
    _chuVi = 3 * f;
    _dienTich = sqrt(3) / 2 * f * f;
}

ostream &operator<<(ostream &os, const HinhTamGiacDeu &htgd)
{
    os << "Hinh Tam Giac Deu ";
    os << (HinhHocPhang)htgd;

    return os;
}

class HinhChuNhat : public HinhHocPhang
{
private:
    float _cdai, _crong;

public:
    HinhChuNhat(const float &, const float &);
    friend ostream &operator<<(ostream &, const HinhChuNhat &);
};

HinhChuNhat::HinhChuNhat(const float &f1, const float &f2) : _cdai(f1), _crong(f2)
{
    _chuVi = (f1 + f2) * 2;
    _dienTich = f1 * f2;
}

ostream &operator<<(ostream &os, const HinhChuNhat &hcn)
{
    os << "Hinh Chu Nhat ";
    os << (HinhChuNhat)hcn;

    return os;
}

class HinhHoc3Chieu : public Hinh
{

public:
    virtual ~HinhHoc3Chieu() {};
};