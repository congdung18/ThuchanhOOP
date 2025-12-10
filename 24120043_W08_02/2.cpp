#include <iostream>
#include <cmath>

using namespace std;

class HinhHocPhang
{
public:
    HinhHocPhang() {}

    virtual float TinhDienTich();
};

float HinhHocPhang::TinhDienTich()
{
    return 0;
}

class HinhChuNhat : public HinhHocPhang
{
private:
    float chieuDai, chieuRong;

public:
    HinhChuNhat();
    HinhChuNhat(const float &cd, const float &cr);

    float TinhDienTich() override;
};

HinhChuNhat::HinhChuNhat()
{
    chieuDai = chieuRong = 0;
}

HinhChuNhat::HinhChuNhat(const float &cd, const float &cr)
{
    chieuDai = (cd == 0) ? 1 : abs(cd);
    chieuRong = (cr == 0) ? 1 : abs(cr);
}

float HinhChuNhat::TinhDienTich()
{
    return chieuDai * chieuRong;
}

#define PI 3.14159
class HinhTron : public HinhHocPhang
{
private:
    float banKinh;

public:
    HinhTron();
    HinhTron(const float &ht);

    float TinhDienTich() override;
};

HinhTron::HinhTron()
{
    banKinh = 0;
}

HinhTron::HinhTron(const float &bk)
{
    banKinh = (bk == 0) ? 1 : abs(bk);
}

float HinhTron::TinhDienTich()
{
    return PI * banKinh * banKinh;
}

int main()
{
    HinhHocPhang *hhp = new HinhHocPhang;
    HinhChuNhat *hcn = new HinhChuNhat(34, 56.8);
    HinhTron *ht = new HinhTron(73.9);
    cout << hhp->TinhDienTich() << "\t" << hcn->TinhDienTich() << "\t" << ht->TinhDienTich();
    cout << endl;
    delete hhp;
    hhp = hcn;
    cout << hhp->TinhDienTich() << endl;
    cout << endl
         << endl;
    delete hcn;
    delete ht;

    cout << endl
         << endl;
    system("pause");
    return 0;
}