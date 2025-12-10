#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class HinhHocPhang {
public:
    virtual float dienTich() = 0;
    virtual float chuVi() = 0;
    virtual ~HinhHocPhang() {}
};

class HinhChuNhat : public HinhHocPhang {
private:
    float dai, rong;
public:
    friend istream& operator>>(istream& is, HinhChuNhat& h) {
        string line; 
        getline(is, line);

        int pos = line.find(':');
        string nums = line.substr(pos + 1);

        stringstream ss(nums);
        char comma;
        ss >> h.dai >> comma >> h.rong;

        return is;
    }

    float dienTich() override { 
        return dai * rong; 
    }

    float chuVi() override { 
        return 2 * (dai + rong); 
    }
};

class HinhTron : public HinhHocPhang {
private:
    float r;
public:
    friend istream& operator>>(istream& is, HinhTron& h) {
        string line; 
        getline(is, line);

        int pos = line.find(':');
        string nums = line.substr(pos + 1);

        stringstream ss(nums);
        ss >> h.r;

        return is;
    }

    float dienTich() override { 
        return M_PI * r * r; 
    }

    float chuVi() override { 
        return 2 * M_PI * r; 
    }
};

class HinhTamGiac : public HinhHocPhang {
private:
    float a, b, c;
public:
    friend istream& operator>>(istream& is, HinhTamGiac& h) {
        string line; 
        getline(is, line);

        int pos = line.find(':');
        string nums = line.substr(pos + 1);

        stringstream ss(nums);
        char comma;
        ss >> h.a >> comma >> h.b >> comma >> h.c;

        return is;
    }

    float chuVi() override { 
        return a + b + c; 
    }

    float dienTich() override {
        float p = chuVi() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

class HinhThangVuong : public HinhHocPhang {
private:
    float dayLon, dayBe, cao;
public:
    friend istream& operator>>(istream& is, HinhThangVuong& h) {
        string line; 
        getline(is, line);

        int pos = line.find(':');
        string nums = line.substr(pos + 1);

        stringstream ss(nums);
        char comma;
        ss >> h.dayLon >> comma >> h.dayBe >> comma >> h.cao;

        return is;
    }

    float dienTich() override { 
        return (dayLon + dayBe)*cao/2; 
    }

    float chuVi() override {
        float canhBen = sqrt((dayLon - dayBe)*(dayLon - dayBe) + cao * cao);
        return dayLon + dayBe + cao + canhBen;
    }
};

class QuanLyHinhHocPhang {
private:
    vector<HinhChuNhat*> hcn;
    vector<HinhTron*> htr;
    vector<HinhTamGiac*> htg;
    vector<HinhThangVuong*> htv;

public:
    friend istream& operator>>(istream& is, QuanLyHinhHocPhang& q) {
        string line;

        while (getline(is, line)) {
            if (line == "") continue; 

            string type = line.substr(0, line.find(':'));

            if (type == "hcn") {
                HinhChuNhat* x = new HinhChuNhat();
                stringstream ss(line);
                ss >> *x;
                q.hcn.push_back(x);
            }
            else if (type == "htr") {
                HinhTron* x = new HinhTron();
                stringstream ss(line);
                ss >> *x;
                q.htr.push_back(x);
            }
            else if (type == "htg") {
                HinhTamGiac* x = new HinhTamGiac();
                stringstream ss(line);
                ss >> *x;
                q.htg.push_back(x);
            }
            else if (type == "hthv") {
                HinhThangVuong* x = new HinhThangVuong();
                stringstream ss(line);
                ss >> *x;
                q.htv.push_back(x);
            }
        }

        return is;
    }

    friend ostream& operator<<(ostream& os, const QuanLyHinhHocPhang& q) {
        float dt, cv;

        os << "So luong hinh chu nhat: " << q.hcn.size() << "\n";
        dt = cv = 0;
        for (auto x : q.hcn) { dt += x->dienTich(); cv += x->chuVi(); }
        os << "Tong dien tich HCN: " << dt << "\n";
        os << "Tong chu vi HCN: " << cv << "\n";

        os << "So luong hinh tron: " << q.htr.size() << "\n";
        dt = cv = 0;
        for (auto x : q.htr) { dt += x->dienTich(); cv += x->chuVi(); }
        os << "Tong dien tich HT: " << dt << "\n";
        os << "Tong chu vi HT: " << cv << "\n";

        os << "So luong hinh tam giac: " << q.htg.size() << "\n";
        dt = cv = 0;
        for (auto x : q.htg) { dt += x->dienTich(); cv += x->chuVi(); }
        os << "Tong dien tich HTG: " << dt << "\n";
        os << "Tong chu vi HTG: " << cv << "\n";

        os << "So luong hinh thang vuong: " << q.htv.size() << "\n";
        dt = cv = 0;
        for (auto x : q.htv) { dt += x->dienTich(); cv += x->chuVi(); }
        os << "Tong dien tich HTV: " << dt << "\n";
        os << "Tong chu vi HTV: " << cv << "\n";

        return os;
    }
};

int main() {
    ifstream fin("hhp.txt");
    QuanLyHinhHocPhang q;
    fin >> q;

    ofstream fout("out.txt");
    fout << q;

    return 0;
}
