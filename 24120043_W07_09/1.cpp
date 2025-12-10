#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector> 

using namespace std; 

class NhanVien{ 
    protected: 
    string _hoTen, _diaChi; 

    public: 
    friend istream &operator>>(istream&, NhanVien&); 
    friend ostream &operator<<(ostream&, const NhanVien&); 
}; 

istream &operator>>(istream& is, NhanVien& nv){ 
    // streampos start = is.tellg();

    string line; 
    getline(is, line); 

    int posOpen = line.find('(');
    int posClose = line.find(')');
    int posColon = line.find(':');

    nv._hoTen = line.substr(posColon + 2, posOpen - posColon - 3); 
    nv._diaChi = line.substr(posOpen + 1, posClose - posOpen - 1);

    // is.seekg(start);

    return is; 
} 

ostream &operator<<(ostream& os, const NhanVien& nv){ 
    os << nv._hoTen << " (" << nv._diaChi << ")"; return os; 
} 

class NhanVienThuKy: public NhanVien{ 
    private: 
    string _ccnn; 
    int _baoCao; 

    public: 
    friend istream &operator>>(istream&, NhanVienThuKy&);
    friend ostream &operator<<(ostream&, const NhanVienThuKy&);
    int layBaoCao();
};

int NhanVienThuKy::layBaoCao(){
    return _baoCao;
}

istream &operator>>(istream& is, NhanVienThuKy& nv){
    // streampos start = is.tellg();

    string line; 
    getline(is, line);

    int pos1 = line.find('['); 
    int pos2 = line.find(']');
    nv._ccnn = line.substr(pos1 + 1, pos2 - pos1 - 1); 

    int pos3 = line.find('<');
    int pos4 = line.find('>'); 
    nv._baoCao = stoi(line.substr(pos3 + 1, pos4 - pos3 - 1));

    // is.seekg(start);

    return is; 
} 

ostream &operator<<(ostream& os, const NhanVienThuKy& nv){ 
    os << (NhanVien&)nv << " | CCNN: " << nv._ccnn << " | Bao cao: " << nv._baoCao; 
    return os; 
} 

class NhanVienKyThuat : public NhanVien{ 
    private: 
    string _ccn; 
    int _sangKien; 
    
    public: 
    friend istream &operator>>(istream&, NhanVienKyThuat&); 
    friend ostream &operator<<(ostream&, const NhanVienKyThuat&);
    int laySangKien();
};

int NhanVienKyThuat::laySangKien(){
    return _sangKien;
}

istream &operator>>(istream& is, NhanVienKyThuat& nv){
    // streampos start = is.tellg();

    string line; 
    getline(is, line);

    int pos1 = line.find('['); 
    int pos2 = line.find(']'); 
    nv._ccn = line.substr(pos1 + 1, pos2 - pos1 - 1);

    int pos3 = line.find('<'); 
    int pos4 = line.find('>'); 
    nv._sangKien = stoi(line.substr(pos3 + 1, pos4 - pos3 - 1));

    // is.seekg(start);

    return is; 
} 

ostream &operator<<(ostream& os, const NhanVienKyThuat& nv){ 
    os << (NhanVien&)nv << " | CCN: " << nv._ccn << " | Sang kien: " << nv._sangKien; 
    return os; 
} 

class CongTy{ 
    private: 
    vector<NhanVienThuKy*> _nvtk; 
    vector<NhanVienKyThuat*> _nvkt; 
    
    public: 
    friend istream &operator>>(istream&, CongTy&); 
    friend ostream &operator<<(ostream&, const CongTy&);
    void nhanVienXuanSac();
    ~CongTy(); 
}; 

istream &operator>>(istream &is, CongTy &ct){ 
    streampos start = is.tellg();

    string line; 
    while (getline(is, line)){ 
        if (line.empty()){ 
            continue;
        } 
        
        int pos = line.find(':'); 
        if (pos == string::npos){ 
            continue; 
        } 
        
        string loai = line.substr(0, pos); 
        if (loai == "nvtk"){ 
            auto *nv = new NhanVienThuKy;

            is.seekg(start); 
            is >> (NhanVien&)(*nv); 
            is.seekg(start); 
            is >> *nv;

            ct._nvtk.push_back(nv); 
        } else if (loai == "nvkt"){ 
            auto *nv = new NhanVienKyThuat;

            is.seekg(start); 
            is >> (NhanVien&)(*nv); 
            is.seekg(start); 
            is >> *nv;

            ct._nvkt.push_back(nv); 
        } else{ 
            cout << "Invalid syntax\n"; 
        } 
        
        start = is.tellg(); 
    }
    
    return is; 
} 

ostream &operator<<(ostream& os, const CongTy& ct){ 
    os << "--- Danh sach nhan vien thu ky ---\n"; 
    for (int i = 0; i < ct._nvtk.size(); i++){        
        os << i + 1 << ": " << *ct._nvtk[i] << "\n"; 
    }
    
    os << "\n--- Danh sach nhan vien ky thuat ---\n"; 
    for (int i = 0; i < ct._nvkt.size(); i++){
        os << i + 1 << ": " << *ct._nvkt[i] << "\n";
    } 

    return os; 
} 

void CongTy::nhanVienXuanSac(){
    cout << "\n --- Danh sach nhan vien xuat sac --- \n";

    for (int i = 0; i < _nvtk.size(); i++){
        if (_nvtk[i]->layBaoCao() >= 12){
            cout << *_nvtk[i] << endl;
        }
    }

    for (int i = 0; i < _nvkt.size(); i++){
        if (_nvkt[i]->laySangKien() >= 6){
            cout << *_nvkt[i] << endl;
        }
    }
}

CongTy::~CongTy(){ 
    for (auto p : _nvtk) delete p;
    for (auto p : _nvkt) delete p;
} 

int main(){ 
    ifstream fin("input.txt"); 
    CongTy ct; 
    fin >> ct;

    ofstream fout("output.txt");
    fout << ct;

    ct.nhanVienXuanSac();
    
    return 0; 
}