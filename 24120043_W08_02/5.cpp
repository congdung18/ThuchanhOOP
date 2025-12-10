#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Hinh {
public:
    virtual ~Hinh() {}
    virtual void print(ostream& os) const = 0;

    friend ostream& operator<<(ostream& os, const Hinh& h) {
        h.print(os);
        return os;
    }
};

class HinhHocPhang : public Hinh {
protected:
    float _chuVi{}, _dienTich{};

public:
    virtual ~HinhHocPhang() {}

    void print(ostream& os) const override {
        os << "[P = " << _chuVi << ", S = " << _dienTich << "]";
    }
};

class HinhTron : public HinhHocPhang {
    float _banKinh;

public:
    HinhTron(float bk) : _banKinh(bk) {
        _chuVi = 2 * 3.14 * bk;
        _dienTich = 3.14 * bk * bk;
    }

    void print(ostream& os) const override {
        os << "Hinh Tron ";
        HinhHocPhang::print(os);
    }
};

class HinhTamGiacDeu : public HinhHocPhang {
    float _canh;

public:
    HinhTamGiacDeu(float f) : _canh(f) {
        _chuVi = 3 * f;
        _dienTich = sqrt(3) / 2 * f * f;
    }

    void print(ostream& os) const override {
        os << "Hinh Tam Giac Deu ";
        HinhHocPhang::print(os);
    }
};

class HinhChuNhat : public HinhHocPhang {
    float _cdai, _crong;

public:
    HinhChuNhat(float d, float r) : _cdai(d), _crong(r) {
        _chuVi = 2 * (d + r);
        _dienTich = d * r;
    }

    void print(ostream& os) const override {
        os << "Hinh Chu Nhat ";
        HinhHocPhang::print(os);
    }
};

class HinhVuong : public HinhHocPhang {
    float _canh;

public:
    HinhVuong(float f) : _canh(f) {
        _chuVi = 4 * f;
        _dienTich = f * f;
    }

    void print(ostream& os) const override {
        os << "Hinh Vuong ";
        HinhHocPhang::print(os);
    }
};

class HinhHoc3Chieu : public Hinh {
protected:
    float _dtXQ{}, _theTich{};

public:
    virtual ~HinhHoc3Chieu() {}

    void print(ostream& os) const override {
        os << "[Sxq = " << _dtXQ << ", V = " << _theTich << "]";
    }
};

class HinhCau : public HinhHoc3Chieu {
    float _banKinh;

public:
    HinhCau(float r) : _banKinh(r) {
        _dtXQ = 4 * 3.14 * r * r;
        _theTich = (4.0f / 3.0f) * 3.14 * r * r * r;
    }

    void print(ostream& os) const override {
        os << "Hinh Cau ";
        HinhHoc3Chieu::print(os);
    }
};

class HinhLapPhuong : public HinhHoc3Chieu {
    float _canh;

public:
    HinhLapPhuong(float f) : _canh(f) {
        _dtXQ = 4 * f * f;
        _theTich = f * f * f;
    }

    void print(ostream& os) const override {
        os << "Hinh Lap Phuong ";
        HinhHoc3Chieu::print(os);
    }
};

class HinhHop : public HinhHoc3Chieu {
    float _c1, _c2, _c3;

public:
    HinhHop(float a, float b, float c) : _c1(a), _c2(b), _c3(c) {
        _dtXQ = 4 * a * b;
        _theTich = a * b * c;
    }

    void print(ostream& os) const override {
        os << "Hinh Hop ";
        HinhHoc3Chieu::print(os);
    }
};

class HinhTru : public HinhHoc3Chieu {
    float _bk, _cao;

public:
    HinhTru(float r, float h) : _bk(r), _cao(h) {
        _dtXQ = 2 * 3.14 * r * h;
        _theTich = 3.14 * r * r * h;
    }

    void print(ostream& os) const override {
        os << "Hinh Tru ";
        HinhHoc3Chieu::print(os);
    }
};

class HinhNon : public HinhHoc3Chieu {
    float _bk, _c;

public:
    HinhNon(float r, float h) : _bk(r), _c(h) {
        _dtXQ = 3.14 * r * sqrt(r * r + h * h);
        _theTich = (1.0f / 3.0f) * 3.14 * r * r * h;
    }

    void print(ostream& os) const override {
        os << "Hinh Non ";
        HinhHoc3Chieu::print(os);
    }
};

int main()
{
    vector<Hinh *> dsHinh;
    dsHinh.push_back(new HinhTron(3.5));
    dsHinh.push_back(new HinhTamGiacDeu(8.5));
    dsHinh.push_back(new HinhChuNhat(3.7, 1.9));
    dsHinh.push_back(new HinhVuong(4.1));
    dsHinh.push_back(new HinhCau(13.5));
    dsHinh.push_back(new HinhLapPhuong(2.9));
    dsHinh.push_back(new HinhHop(1.2, 3.7, 6.3));
    dsHinh.push_back(new HinhTru(6.1, 4.9));
    dsHinh.push_back(new HinhNon(8.7, 3.2));

    for (int i = 0; i < dsHinh.size(); i++){
        cout << *dsHinh[i] << endl;
    }

    cout << endl << endl;
    system("pause");
    return 0;
}
