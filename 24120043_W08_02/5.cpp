#include <iostream>
#include <vector>
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
protected:
    float _dtXQ, _theTich;

public:
    friend ostream &operator<<(ostream &, const HinhHoc3Chieu &);
    virtual ~HinhHoc3Chieu() {};
};

ostream &operator<<(ostream &os, const HinhHoc3Chieu &hh3c)
{
    os << "[Sxq = " << hh3c._dtXQ << ", V = " << hh3c._theTich << "]";
    return os;
}

class HinhCau : public HinhHoc3Chieu
{
private:
    float _banKinh;

public:
    HinhCau(const float &);
    friend ostream &operator<<(ostream &, const HinhCau &);
};

HinhCau::HinhCau(const float &f) : _banKinh(f)
{
    _dtXQ = 4 * 3.14 * f * f;
    _theTich = 4 / 3 * 3.14 * f * f * f;
}

ostream &operator<<(ostream &os, const HinhCau &hc)
{
    os << "Hinh Cau ";
    os << (HinhHoc3Chieu)hc;

    return os;
}

class HinhLapPhuong : public HinhHoc3Chieu
{
private:
    float _canh;

public:
    HinhLapPhuong(const float &);
    friend ostream &operator<<(ostream &, const HinhLapPhuong &);
};

HinhLapPhuong::HinhLapPhuong(const float &f) : _canh(f)
{
    _dtXQ = 4 * f * f;
    _theTich = f * f * f;
}

ostream &operator<<(ostream &os, const HinhLapPhuong &hlp)
{
    os << "Hinh Lap Phuong ";
    os << (HinhHoc3Chieu)hlp;

    return os;
}

class HinhHop : public HinhHoc3Chieu
{
private:
    float _c1, _c2, _c3;

public:
    HinhHop(const float &, const float &, const float &);
    friend ostream &operator<<(ostream &, const HinhHop &);
};

HinhHop::HinhHop(const float &f1, const float &f2, const float &f3) : _c1(f1), _c2(f2), _c3(f3)
{
    _dtXQ = 4 * f1 * f2;
    _theTich = f1 * f2 * f3;
}

ostream &operator<<(ostream &os, const HinhHop &hh)
{
    os << "Hinh Hop ";
    os << (HinhHoc3Chieu)hh;

    return os;
}

class HinhTru : public HinhHoc3Chieu
{
private:
    float _bk, _cao;

public:
    HinhTru(const float &, const float &);
    friend ostream &operator<<(ostream &, const HinhTru &);
};

HinhTru::HinhTru(const float &bk, const float &c) : _bk(bk), _cao(c)
{
    _dtXQ = 2 * c * 3.14 * bk;
    _theTich = bk * bk * 3.14 * c;
}

ostream &operator<<(ostream &os, const HinhTru &ht)
{
    os << "Hinh Tru ";
    os << (HinhHoc3Chieu)ht;

    return os;
}

class HinhNon : public HinhHoc3Chieu
{
private:
    float _bk, _c;

public:
    HinhNon(const float &f1, const float &f2);
    friend ostream &operator<<(ostream &, const HinhNon &);
};

HinhNon::HinhNon(const float &f1, const float &f2) : _bk(f1), _c(f2)
{
    _dtXQ = 3.14 * _bk * sqrt(_bk * _bk + _c * _c);
    _theTich = 1 / 3 * 3.14 * _bk * _bk * _c;
}

ostream &operator<<(ostream &os, const HinhNon &hn)
{
    os << "Hinh Non ";
    os << (HinhHoc3Chieu)hn;

    return os;
}

int main()
{
    vector<Hinh *> dsHinh;
    dsHinh.push_back(new HinhTron(3.5));
    dsHinh.push_back(new HinhTamGiacDeu(8.5));
    dsHinh.push_back(new HinhChuNhat(3.7, 1.9));
    dsHinh.push_back(new HinhVuong(4.1));
    dsHinh.push_back(new HinhCau(13.5));
}