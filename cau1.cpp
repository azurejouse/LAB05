#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;
struct NgaySinh{
    int ngay, thang, nam;
};
class NhanVien{
protected:
    string hoTen;
    NgaySinh ngaySinh;
    double luong;
public:
    NhanVien() : luong(0) {}
    virtual ~NhanVien() {}
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Yeu cau nguoi dung nhap chuoi hoTen va 3 so nguyen cho ngay, thang, nam sinh.
    */
    virtual void nhap(){
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap ngay sinh (d/m/y): ";
        cin >> ngaySinh.ngay >> ngaySinh.thang >> ngaySinh.nam;
    }
    /*
    Input: Khong co
    Output: In ket qua ra man hinh
    Huong giai thuat: In cac thuoc tinh hoTen, ngaySinh va luong ra console.
    */
    virtual void xuat() {
        cout << "Ho ten: " << hoTen 
             << " | Ngay sinh: " << ngaySinh.ngay << "/" << ngaySinh.thang << "/" << ngaySinh.nam 
             << " | Luong: " << (long)luong << " VND";
    }

    /*
    Input: Khong co
    Output: Kieu double (Tien luong)
    Huong giai thuat: Day la ham thuan ao (= 0), chi dinh nghia de bat buoc cac lop con phai tu trien khai cong thuc tinh luong rieng.
    */
    virtual double tinhLuong() = 0;
    /*
    Input: Khong co
    Output: So nguyen (nam sinh) hoac so thuc (luong)
    Huong giai thuat: Tra ve gia tri cua cac thuoc tinh tuong ung de cac lop khac co the truy cap.
    */
    int getNamSinh() { return ngaySinh.nam; }
    double getLuong() { return luong; }
};
class NhanVienSanXuat : public NhanVien{
private:
    double luongCanBan;
    int soSanPham;
public:
    /*
    Input: Khong co (Nhan tu ban phim)
    Output: Khong co
    Huong giai thuat: Goi ham nhap() cua lop cha de lay thong tin chung. Sau do nhap them thuoc tinh rieng: luongCanBan va soSanPham.
    */
    void nhap() override{
        cout << "\nNhap thong tin Nhan Vien San Xuat:" << endl;
        NhanVien::nhap();
        cout << "Nhap luong can ban: ";
        cin >> luongCanBan;
        cout << "Nhap so san pham: ";
        cin >> soSanPham;
    }
    /*
    Input: Khong co
    Output: Kieu double (Tien luong cua NVSX)
    Huong giai thuat: Luong = luongCanBan + (soSanPham * 5000). Gan vao thuoc tinh 'luong' cua lop cha va tra ve gia tri do.
    */
    double tinhLuong() override{
        luong = luongCanBan + (soSanPham * 5000.0);
        return luong;
    }
    /*
    Input: Khong co
    Output: Khong co (In ra man hinh)
    Huong giai thuat: In tag [NV San Xuat], goi ham xuat() cua lop cha, sau do in them so san pham.
    */
    void xuat() override{
        cout << "[NV San Xuat] ";
        NhanVien::xuat();
        cout << " | So SP: " << soSanPham << endl;
    }
};
class NhanVienVanPhong : public NhanVien{
private:
    int soNgayLamViec;
public:
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Goi ham nhap() cua lop cha de lay thong tin chung. Sau do nhap them thuoc tinh rieng: soNgayLamViec.
    */
    void nhap() override{
        cout << "\nNhap thong tin Nhan Vien Van Phong:" << endl;
        NhanVien::nhap();
        cout << "Nhap so ngay lam viec: ";
        cin >> soNgayLamViec;
    }
    /*
    Input: Khong co
    Output: Kieu double (Tien luong cua NVVP)
    Huong giai thuat: Luong = soNgayLamViec * 100000. Gan vao thuoc tinh 'luong' cua lop cha va tra ve gia tri do.
    */
    double tinhLuong() override{
        luong = soNgayLamViec * 100000.0;
        return luong;
    }
    /*
    Input: Khong co
    Output: In ra man hinh
    Huong giai thuat: In tag [NV Van Phong], goi ham xuat() cua lop cha, sau do in them so ngay lam viec.
    */
    void xuat() override{
        cout << "[NV Van Phong] ";
        NhanVien::xuat();
        cout << " | So ngay lam: " << soNgayLamViec << endl;
    }
};
class CongTy{
private:
    vector<NhanVien*> danhSach;
public:
    ~CongTy(){
        for (NhanVien* nv : danhSach){
            delete nv; 
        }
    }
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Hoi so luong NV. Dung vong lap de hoi nguoi dung chon loai NV. 
    Khoi tao con tro NhanVien* tro vao doi tuong tuong ung, goi nv->nhap(), them vao vector danhSach.
    */
    void nhapDanhSach(){
        int soLuong;
        cout << "Nhap so luong nhan vien can them: ";
        cin >> soLuong;
        for(int i = 0; i < soLuong; ++i){
            int loai;
            cout << "\nChon loai nhan vien (1 - NV San Xuat, 2 - NV Van Phong): ";
            cin >> loai;
            NhanVien* nv = nullptr;
            if(loai == 1){
                nv = new NhanVienSanXuat();
            }else if(loai == 2){
                nv = new NhanVienVanPhong();
            }else{
                cout << "Loai khong hop le, bo qua!" << endl;
                continue;
            }
            nv->nhap();
            danhSach.push_back(nv);
        }
    }
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Duyet qua tat ca phan tu con tro trong vector danhSach, goi nv->tinhLuong(). 
    Nho co co che Da hinh, chuong trinh tu xac dinh do la NVSX hay NVVP de goi dung ham.
    */
    void tinhLuongDanhSach(){
        for(NhanVien* nv : danhSach){
            nv->tinhLuong();
        }
    }
    /*
    Input: Khong co
    Output: In ra man hinh
    Huong giai thuat: Duyet vector va goi phuong thuc xuat() cho tung nhan vien.
    */
    void xuatDanhSach(){
        cout << "\nDANH SACH NHAN VIEN:" << endl;
        for (NhanVien* nv : danhSach){
            nv->xuat();
        }
    }
    /*
    Input: Khong co
    Output: In ket qua tong luong
    Huong giai thuat: Khoi tao tong = 0. Duyet danh sach, cong don nv->getLuong() vao tong.
    */
    void tinhTongLuong(){
        double tong = 0;
        for(NhanVien* nv : danhSach){
            tong += nv->getLuong();
        }
        cout << "\nTong luong cong ty phai tra: " << (long)tong << " VND" << endl;
    }
    /*
    Input: Khong co
    Output: In thong tin NV tim duoc hoac thong bao khong co
    Huong giai thuat: 
    1. Khoi tao minLuong = Gia tri double lon nhat co the, nvMin = nullptr.
    2. Duyet danhSach. Dung 'dynamic_cast<NhanVienSanXuat*>' de xac dinh phan tu hien tai co phai NVSX khong.
    3. Neu dung, so sanh luong de cap nhat minLuong va nvMin.
    4. Cuoi cung kiem tra nvMin de in ket qua.
    */
    void timNVSX_LuongThapNhat(){
        NhanVien* nvMin = nullptr;
        double minLuong = numeric_limits<double>::max();
        for(NhanVien* nv : danhSach){
            NhanVienSanXuat* nvsx = dynamic_cast<NhanVienSanXuat*>(nv);
            if(nvsx != nullptr) {
                if (nvsx->getLuong() < minLuong){
                    minLuong = nvsx->getLuong();
                    nvMin = nvsx;
                }
            }
        }
        if(nvMin != nullptr){
            cout << "\nNhan vien san xuat co luong thap nhat la: \n";
            nvMin->xuat();
        }else{
            cout << "\nKhong co nhan vien san xuat nao trong danh sach!" << endl;
        }
    }
    /*
    Input: Khong co
    Output: In thong tin NV tim duoc
    Huong giai thuat:
    1. Khoi tao maxTuoi = -1, nvMaxTuoi = nullptr. Lay nam hien tai = 2026.
    2. Duyet danhSach. Dung 'dynamic_cast<NhanVienVanPhong*>' de xac dinh NVVP.
    3. Tinh tuoi = nam hien tai - nv->getNamSinh(). 
    4. Neu tuoi > maxTuoi thi cap nhat maxTuoi va nvMaxTuoi. In ket qua.
    */
    void timNVVP_TuoiCaoNhat(){
        NhanVien* nvMaxTuoi = nullptr;
        int maxTuoi = -1;
        int namHienTai = 2026; 
        for(NhanVien* nv : danhSach){
            NhanVienVanPhong* nvvp = dynamic_cast<NhanVienVanPhong*>(nv);
            if(nvvp != nullptr){
                int tuoi = namHienTai - nvvp->getNamSinh();
                if(tuoi > maxTuoi){
                    maxTuoi = tuoi;
                    nvMaxTuoi = nvvp;
                }
            }
        }
        if(nvMaxTuoi != nullptr){
            cout << "\nNhan vien van phong cao tuoi nhat la (" << maxTuoi << " tuoi): \n";
            nvMaxTuoi->xuat();
        }else{
            cout << "\nKhong co nhan vien van phong nao trong danh sach!" << endl;
        }
    }
};
int main(){
    CongTy ct;
    ct.nhapDanhSach();
    ct.tinhLuongDanhSach(); 
    ct.xuatDanhSach();
    ct.tinhTongLuong();
    ct.timNVSX_LuongThapNhat();
    ct.timNVVP_TuoiCaoNhat();
    return 0;
}