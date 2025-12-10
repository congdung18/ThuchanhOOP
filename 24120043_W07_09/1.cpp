#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class NhanVien
{
protected:
    string _hoTen, _diaChi;
};

class NhanVienThuKy : public NhanVien
{
private:
    string _ccnn;
    int _baoCao;

public:
    friend istream &operator>>(istream &, NhanVienThuKy &);
    friend ostream &operator<<(ostream &, const NhanVienThuKy &);
};

istream &operator>>(istream &is, NhanVienThuKy &nvtk)
{
    cout << "Nhap ho va ten: ";
    is >> nvtk._hoTen;
    cout << "Nhap dia chi: ";
    is >> nvtk._diaChi;
    cout << "Nhap loai chung chi ngoai ngu: ";
    is >> nvtk._ccnn;
    cout << "Nhap so bao cao da hoan thanh: ";
    is >> nvtk._baoCao;

    return is;
}

ostream &operator<<(ostream &os, const NhanVienThuKy &nvtk)
{
    os << nvtk._hoTen << " " << nvtk._diaChi << " " << nvtk._ccnn << " " << nvtk._baoCao << endl;

    return os;
}

class NhanVienKyThuat : public NhanVien
{
private:
    string _ccn;
    int _sangKien;

public:
    friend istream &operator>>(istream &, NhanVienKyThuat &);
    friend ostream &operator<<(ostream &, const NhanVienKyThuat &);
};

istream &operator>>(istream &is, NhanVienKyThuat &nvkt)
{
    cout << "Nhap ho va ten: ";
    is >> nvkt._hoTen;
    cout << "Nhap dia chi: ";
    is >> nvkt._diaChi;
    cout << "Nhap loai chung chi nganh: ";
    is >> nvkt._ccn;
    cout << "Nhap so luong sang kien trong nam: ";
    is >> nvkt._sangKien;

    return is;
}

ostream &operator<<(ostream &os, const NhanVienKyThuat &nvkt)
{
    os << nvkt._hoTen << " " << nvkt._diaChi << " " << nvkt._ccn << " " << nvkt._sangKien << endl;

    return os;
}

class CongTy
{
private:
    vector<NhanVienThuKy *> _nvtk;
    vector<NhanVienKyThuat *> _nvkt;

public:
    friend istream &operator>>(istream &, CongTy &);
    friend ostream &operator<<(ostream &, const CongTy &);

    ~CongTy();
};

istream &operator>>(istream &is, CongTy &ct)
{
    int size = 0, total = 0;
    cout << "Nhap so nhan vien thu ky trong cong ty: ";
    is >> size;
    total += size;
    cout << "Nhap so nhan vien ky thuat trong cong ty: ";
    is >> size;
    total += size;
    while (total--)
    {
        cout << "Nhap 1 neu la nhan vien thu ky, 2 neu la nhan vien ky thuat: ";
        int option = 0;
        is >> option;
        if (option == 1)
        {
            NhanVienThuKy *nvtk = new NhanVienThuKy;
            is >> *nvtk;
            ct._nvtk.push_back(nvtk);
        }
        else if (option == 2)
        {
            NhanVienKyThuat *nvkt = new NhanVienKyThuat;
            is >> *nvkt;
            ct._nvkt.push_back(nvkt);
        }
        else
        {
            cout << "So khong hop le." << endl;
        }
    }

    return is;
}

ostream &operator<<(ostream &os, const CongTy &ct)
{
    cout << "Cac nhan vien thu ky: " << endl;
    for (int i = 0; i < ct._nvtk.size(); i++)
    {
        cout << i + 1 << ": " << *ct._nvtk[i];
    }

    cout << "Cac nhan vien ky thuat: " << endl;
    for (int i = 0; i < ct._nvkt.size(); i++)
    {
        cout << i + 1 << ": " << *ct._nvkt[i];
    }

    return os;
}

CongTy::~CongTy()
{
    for (int i = 0; i < _nvtk.size(); i++)
    {
        delete _nvtk[i];
    }

    for (int i = 0; i < _nvkt.size(); i++)
    {
        delete _nvkt[i];
    }
}

int main()
{
    CongTy ct;
    cin >> ct;
    cout << ct;

    return 0;
}