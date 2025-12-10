#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class HinhHocPhang
{
public:
    virtual float dienTich() = 0;
    virtual float chuVi() = 0;
    virtual ~HinhHocPhang() {};
};

class HinhChuNhat : public HinhHocPhang
{
private:
    float dai, rong;

public:
    friend istream &operator>>(istream &is, HinhChuNhat &h)
    {
        string line;
        getline(is, line);

        int pos = line.find(':');
        string nums = line.substr(pos + 1);

        stringstream ss(nums);
        char comma;
        ss >> h.dai >> comma >> h.rong;

        return is;
    }

    float dienTich() override
    {
        return dai * rong;
    }

    float chuVi() override
    {
        return 2 * (dai + rong);
    }
};

const float pi = 3.1415926535898;

class HinhTron : public HinhHocPhang
{
private:
    float r;

public:
    friend istream &operator>>(istream &is, HinhTron &h)
    {
        string line;
        getline(is, line);

        int pos = line.find(':');
        string nums = line.substr(pos + 1);

        stringstream ss(nums);
        ss >> h.r;

        return is;
    }

    float dienTich() override
    {
        return pi * r * r;
    }

    float chuVi() override
    {
        return 2 * pi * r;
    }
};

class HinhTamGiac : public HinhHocPhang
{
private:
    float a, b, c;

public:
    friend istream &operator>>(istream &is, HinhTamGiac &h)
    {
        string line;
        getline(is, line);

        int pos = line.find(':');
        string nums = line.substr(pos + 1);

        stringstream ss(nums);
        char comma;
        ss >> h.a >> comma >> h.b >> comma >> h.c;

        return is;
    }

    float chuVi() override
    {
        return a + b + c;
    }

    float dienTich() override
    {
        float p = chuVi() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

class HinhThangVuong : public HinhHocPhang
{
private:
    float dayLon, dayBe, cao;

public:
    friend istream &operator>>(istream &is, HinhThangVuong &h)
    {
        string line;
        getline(is, line);

        int pos = line.find(':');
        string nums = line.substr(pos + 1);

        stringstream ss(nums);
        char comma;
        ss >> h.dayLon >> comma >> h.dayBe >> comma >> h.cao;

        return is;
    }

    float dienTich() override
    {
        return (dayLon + dayBe) * cao / 2;
    }

    float chuVi() override
    {
        float canhBen = sqrt((dayLon - dayBe) * (dayLon - dayBe) + cao * cao);
        return dayLon + dayBe + cao + canhBen;
    }
};

class QuanLyHinhHocPhang
{
private:
    vector<HinhHocPhang *> _hhp;

public:
    friend istream &operator>>(istream &is, QuanLyHinhHocPhang &q)
    {
        string line;

        while (getline(is, line))
        {
            if (line == "")
                continue;

            string type = line.substr(0, line.find(':'));

            if (type == "hcn")
            {
                HinhChuNhat *x = new HinhChuNhat();
                stringstream ss(line);
                ss >> *x;
                q._hhp.push_back(x);
            }
            else if (type == "htr")
            {
                HinhTron *x = new HinhTron();
                stringstream ss(line);
                ss >> *x;
                q._hhp.push_back(x);
            }
            else if (type == "htg")
            {
                HinhTamGiac *x = new HinhTamGiac();
                stringstream ss(line);
                ss >> *x;
                q._hhp.push_back(x);
            }
            else if (type == "hthv")
            {
                HinhThangVuong *x = new HinhThangVuong();
                stringstream ss(line);
                ss >> *x;
                q._hhp.push_back(x);
            }
        }

        return is;
    }

    friend ostream &operator<<(ostream &os, const QuanLyHinhHocPhang &q)
    {
        float dt, cv;

        int soHinhChuNhat = 0;
        int soHinhTron = 0;
        int soHinhTamGiac = 0;
        int soHinhThangVuong = 0;

        float dtHCN = 0, cvHCN = 0;
        float dtHT = 0, cvHT = 0;
        float dtHTG = 0, cvHTG = 0;
        float dtHTV = 0, cvHTV = 0;

        for (auto x : q._hhp)
        {
            if (dynamic_cast<HinhChuNhat *>(x))
            {
                soHinhChuNhat++;
                dtHCN += x->dienTich();
                cvHCN += x->chuVi();
            }
            else if (dynamic_cast<HinhTron *>(x))
            {
                soHinhTron++;
                dtHT += x->dienTich();
                cvHT += x->chuVi();
            }
            else if (dynamic_cast<HinhTamGiac *>(x))
            {
                soHinhTamGiac++;
                dtHTG += x->dienTich();
                cvHTG += x->chuVi();
            }
            else if (dynamic_cast<HinhThangVuong *>(x))
            {
                soHinhThangVuong++;
                dtHTV += x->dienTich();
                cvHTV += x->chuVi();
            }
            else
            {
                cout << "Hinh khong hop le \n";
            }
        }

        os << "So hinh chu nhat: " << soHinhChuNhat << endl;
        os << "Dien tich cac hinh chu nhat: " << dtHCN << endl;
        os << "Chu vi cac hinh chu nhat: " << cvHCN << endl;

        os << "So hinh tron: " << soHinhChuNhat << endl;
        os << "Dien tich cac hinh tron: " << dtHT << endl;
        os << "Chu vi cac hinh tron: " << cvHT << endl;

        os << "So hinh tam giac: " << soHinhChuNhat << endl;
        os << "Dien tich cac hinh tam giac: " << dtHTG << endl;
        os << "Chu vi cac hinh tam giac: " << cvHTG << endl;

        os << "So hinh thang vuong: " << soHinhChuNhat << endl;
        os << "Dien tich cac hinh thang vuong: " << dtHTV << endl;
        os << "Chu vi cac hinh thang vuong: " << cvHTV << endl;

        return os;
    }
};

int main()
{
    ifstream fin("hhp.txt");
    QuanLyHinhHocPhang q;
    fin >> q;

    ofstream fout("out.txt");
    fout << q;

    return 0;
}
