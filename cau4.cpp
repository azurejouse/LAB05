#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;
class NhanVien{
protected:
    string maNV;
    string hoTen;
    int tuoi;
    string sdt;
    string email;
    double luongCoBan;
    double luongHangThang;
public:
    NhanVien() : tuoi(0), luongCoBan(0), luongHangThang(0) {}
    virtual ~NhanVien() {}
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Yeu cau nguoi dung nhap cac thuoc tinh chung ma moi nhan vien deu co: Ma NV, Ho ten, Tuoi, SDT, Email, Luong co ban.
    */
    virtual void nhap(){
        cin.ignore();
        cout << "Nhap Ma NV: ";
        getline(cin, maNV);
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cin.ignore();
        cout << "Nhap SDT: ";
        getline(cin, sdt);
        cout << "Nhap Email: ";
        getline(cin, email);
        cout << "Nhap luong co ban: ";
        cin >> luongCoBan;
    }
    /*
    Input: Khong co
    Output: In ra man hinh
    Huong giai thuat: In cac thong tin co ban cua nhan vien cung voi luong hang thang.
    */
    virtual void xuat(){
        cout << "Ma: " << maNV 
             << " | Ten: " << hoTen 
             << " | Tuoi: " << tuoi 
             << " | SDT: " << sdt 
             << " | Email: " << email 
             << " | LCB: " << (long long)luongCoBan
             << " | Luong thuc nhan: " << (long long)luongHangThang;
    }
    /*
    Input: Khong co
    Output: Kieu double (Tien luong)
    Huong giai thuat: Ham thuan ao, buoc cac lop con phai ghi de cong thuc tinh luong rieng.
    */
    virtual double tinhLuong() = 0;
    // Getter ho tro lay gia tri luong
    double getLuong(){ return luongHangThang;}
};

class LapTrinhVien : public NhanVien{
private:
    int soGioOvertime;
public:
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Goi ham nhap() cha de lay thong tin chung, sau do nhap rieng so gio lam them.
    */
    void nhap() override{
        cout << "\nNhap thong tin LAP TRINH VIEN:" << endl;
        NhanVien::nhap();
        cout << "Nhap so gio overtime: ";
        cin >> soGioOvertime;
    }

    /*
    Phuong thuc: tinhLuong()
    Input: Khong co
    Output: Kieu double
    Huong giai thuat: Luong = luongCoBan + soGioOvertime * 200000. Gan vao luongHangThang va tra ve.
    */
    double tinhLuong() override{
        luongHangThang = luongCoBan + (soGioOvertime * 200000.0);
        return luongHangThang;
    }
    void xuat() override{
        cout << "[LTV] ";
        NhanVien::xuat();
        cout << " | Gio OT: " << soGioOvertime << endl;
    }
};
class KiemChungVien : public NhanVien{
private:
    int soLoiPhatHien;
public:
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Goi ham nhap() cha de lay thong tin chung, sau do nhap rieng so loi phat hien.
    */
    void nhap() override{
        cout << "\nNhap thong tin KIEM CHUNG VIEN:" << endl;
        NhanVien::nhap();
        cout << "Nhap so loi phat hien: ";
        cin >> soLoiPhatHien;
    }
    /*
    Input: Khong co
    Output: Kieu double
    Huong giai thuat: Luong = luongCoBan + soLoi * 50000. Gan vao luongHangThang va tra ve.
    */
    double tinhLuong() override{
        luongHangThang = luongCoBan + (soLoiPhatHien * 50000.0);
        return luongHangThang;
    }
    void xuat() override{
        cout << "[KCV] ";
        NhanVien::xuat();
        cout << " | So loi: " << soLoiPhatHien << endl;
    }
};
class CongTy{
private:
    vector<NhanVien*> danhSach;
public:
    ~CongTy(){
        for(NhanVien* nv : danhSach){
            delete nv;
        }
    }
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Hoi so luong nv. Dung vong lap for cho nguoi dung chon kieu, khoi tao bang toan tu new, nhap va tinh tien luong luon roi dua vao mang.
    */
    void nhapDanhSach(){
        int n;
        cout << "Nhap so luong nhan vien cong ty: ";
        cin >> n;
        for(int i=0; i<n; ++i){
            int loai;
            cout << "\nChon loai NV (1 - Lap Trinh Vien, 2 - Kiem Chung Vien): ";
            cin >> loai;

            NhanVien* nv = nullptr;
            if(loai == 1){
                nv = new LapTrinhVien();
            }
            else if(loai == 2){
                nv = new KiemChungVien();
            }
            else{
                cout << "Loai nhan vien khong hop le!" << endl;
                continue;
            }
            nv->nhap();
            nv->tinhLuong();
            danhSach.push_back(nv);
        }
    }

    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Duyet qua toan bo vector danhSach, goi ham xuat() de in thong tin.
    */
    void xuatDanhSach(){
        cout << "\nDANH SACH NHAN VIEN CONG TY:" << endl;
        for(NhanVien* nv : danhSach){
            nv->xuat();
        }
    }
    /*
    Input: Khong co
    Output: In danh sach nhan vien ra man hinh
    Huong giai thuat: Tinh tong luong tat ca nhan vien. Chia cho size() de lay trung binh. Duyet danh sach lan nua de in ra ai co luong < trung binh.
    */
    void luongThapHonTrungBinh(){
        if(danhSach.empty()) return;
        double tongLuong = 0;
        for(NhanVien* nv : danhSach){
            tongLuong += nv->getLuong();
        }
        double trungBinh = tongLuong / danhSach.size();
        cout << "\nNV CO LUONG THAP HON TRUNG BINH (" << (long long)trungBinh << " VND):" << endl;
        bool coNV = false;
        for(NhanVien* nv : danhSach){
            if(nv->getLuong() < trungBinh){
                nv->xuat();
                coNV = true;
            }
        }
        if(!coNV){
            cout << "Khong co ai co luong thap hon trung binh." << endl;
        }
    }
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Gan maxLuong la -1. Duyet mang de tim luong lon nhat va gan doi tuong tuong ung, sau do goi xuat().
    */
    void inNhanVienLuongCaoNhat(){
        NhanVien* nvMax = nullptr;
        double maxLuong = -1;
        for(NhanVien* nv : danhSach){
            if(nv->getLuong() > maxLuong){
                maxLuong = nv->getLuong();
                nvMax = nv;
            }
        }
        if(nvMax != nullptr){
            cout << "\n[TOP 1] Nhan vien co luong CAO nhat cong ty la:" << endl;
            nvMax->xuat();
        }
    }

    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Gan minLuong la gia tri double lon nhat co the (dung numeric). Duyet mang de tim luong nho nhat roi goi xuat().
    */
    void inNhanVienLuongThapNhat(){
        NhanVien* nvMin = nullptr;
        double minLuong = numeric_limits<double>::max();
        for(NhanVien* nv : danhSach){
            if(nv->getLuong() < minLuong){
                minLuong = nv->getLuong();
                nvMin = nv;
            }
        }
        if(nvMin != nullptr){
            cout << "\n[BOTTOM 1] Nhan vien co luong THAP nhat cong ty la:" << endl;
            nvMin->xuat();
        }
    }
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Dung dynamic_cast<LapTrinhVien*> loc loai nhan vien LTV. Kiem tra luong de tim max roi in ra man hinh.
    */
    void inLapTrinhVienLuongCaoNhat(){
        NhanVien* nvMax = nullptr;
        double maxLuong = -1;
        for(NhanVien* nv : danhSach){
            if(dynamic_cast<LapTrinhVien*>(nv)){
                if(nv->getLuong() > maxLuong){
                    maxLuong = nv->getLuong();
                    nvMax = nv;
                }
            }
        }
        if(nvMax != nullptr){
            cout << "\nLap trinh vien co luong CAO nhat la:" << endl;
            nvMax->xuat();
        }else{
            cout << "\nKhong co lap trinh vien nao trong cong ty." << endl;
        }
    }
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Dung dynamic_cast<KiemChungVien*> loc loai nhan vien KCV. Kiem tra luong de tim min roi in ra man hinh.
    */
    void inKiemChungVienLuongThapNhat(){
        NhanVien* nvMin = nullptr;
        double minLuong = numeric_limits<double>::max();
        for(NhanVien* nv : danhSach){
            if(dynamic_cast<KiemChungVien*>(nv)){
                if(nv->getLuong() < minLuong){
                    minLuong = nv->getLuong();
                    nvMin = nv;
                }
            }
        }
        if(nvMin != nullptr){
            cout << "\nKiem chung vien co luong THAP nhat la:" << endl;
            nvMin->xuat();
        }else{
            cout << "\nKhong co kiem chung vien nao trong cong ty." << endl;
        }
    }
};
int main(){
    CongTy hoanCau;
    hoanCau.nhapDanhSach();
    hoanCau.xuatDanhSach();
    hoanCau.luongThapHonTrungBinh();
    hoanCau.inNhanVienLuongCaoNhat();
    hoanCau.inNhanVienLuongThapNhat();
    hoanCau.inLapTrinhVienLuongCaoNhat();
    hoanCau.inKiemChungVienLuongThapNhat();
    return 0;
}
