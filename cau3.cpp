#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;
class SinhVien{
protected:
    string mssv;
    string hoTen;
    string diaChi;
    int tongSoTinChi;
    double diemTrungBinh;

public:
    SinhVien() : tongSoTinChi(0), diemTrungBinh(0) {}
    virtual ~SinhVien() {}
    /*
    Input: Nhan tu ban phim
    Output: Khong co
    Huong giai thuat: Yeu cau nguoi dung nhap cac thong tin co ban chung cua moi sinh vien nhu MSSV, ho ten, dia chi, so tin chi va diem trung binh.
    */
    virtual void nhap(){
        cin.ignore();
        cout << "Nhap MSSV: ";
        getline(cin, mssv);
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
        cout << "Nhap tong so tin chi: ";
        cin >> tongSoTinChi;
        cout << "Nhap diem trung binh: ";
        cin >> diemTrungBinh;
    }
    /*
    Input: Khong co
    Output: In ra man hinh
    Huong giai thuat: In cac thong tin chung cua sinh vien ra console.
    */
    virtual void xuat(){
        cout << "MSSV: " << mssv 
             << " | Ho ten: " << hoTen 
             << " | Dia chi: " << diaChi 
             << " | Tin chi: " << tongSoTinChi 
             << " | DTB: " << diemTrungBinh;
    }
    /*
    Input: Khong co
    Output: Kieu bool (true neu du dieu kien, false neu khong)
    Huong giai thuat: Ham thuan ao de cac lop con (He Cao dang/Dai hoc) tu dinh nghia lai tieu chi xet tot nghiep rieng.
    */
    virtual bool xetTotNghiep() = 0;
    // Cac ham getter ho tro truy xuat du lieu tu ben ngoai
    double getDiemTrungBinh(){ return diemTrungBinh;}
};
class SinhVienCaoDang : public SinhVien{
private:
    double diemThiTotNghiep;
public:
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Goi ham nhap() cua lop cha de lay thong tin chung, sau do nhap rieng diem thi tot nghiep.
    */
    void nhap() override{
        cout << "\nNhap thong tin Sinh Vien CAO DANG:" << endl;
        SinhVien::nhap();
        cout << "Nhap diem thi tot nghiep: ";
        cin >> diemThiTotNghiep;
    }
    /*
    Input: Khong co
    Output: Kieu bool
    Huong giai thuat: Kiem tra dieu kien: tongSoTinChi >= 120, diemTrungBinh >= 5, va diemThiTotNghiep >= 5. Neu thoa man tat ca thi tra ve true, nguoc la false.
    */
    bool xetTotNghiep() override{
        if(tongSoTinChi >= 120 && diemTrungBinh >= 5 && diemThiTotNghiep >= 5){
            return true;
        }
        return false;
    }
    void xuat() override{
        cout << "[CAO DANG] ";
        SinhVien::xuat();
        cout << " | Diem thi TN: " << diemThiTotNghiep 
             << " | Ket qua: " << (xetTotNghiep() ? "Do Tot Nghiep" : "Khong Tot Nghiep") << endl;
    }
};

class SinhVienDaiHoc : public SinhVien{
private:
    string tenLuanVan;
    double diemLuanVan;
public:
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Goi ham nhap() cua lop cha, xoa bo nho dem va nhap them ten luan van cung diem luan van.
    */
    void nhap() override{
        cout << "\nNhap thong tin Sinh Vien DAI HOC:" << endl;
        SinhVien::nhap();
        cin.ignore();
        cout << "Nhap ten luan van: ";
        getline(cin, tenLuanVan);
        cout << "Nhap diem luan van: ";
        cin >> diemLuanVan;
    }
    /*
    Input: Khong co
    Output: Kieu bool
    Huong giai thuat: Kiem tra dieu kien: tongSoTinChi >= 170, diemTrungBinh >= 5, va diemLuanVan >= 5. Tra ve true neu dat, nguoc lai false.
    */
    bool xetTotNghiep() override{
        if(tongSoTinChi >= 170 && diemTrungBinh >= 5 && diemLuanVan >= 5){
            return true;
        }
        return false;
    }
    void xuat() override{
        cout << "[DAI HOC]  ";
        SinhVien::xuat();
        cout << " | Luan van: " << tenLuanVan << " - Diem: " << diemLuanVan 
             << " | Ket qua: " << (xetTotNghiep() ? "Do Tot Nghiep" : "Khong Tot Nghiep") << endl;
    }
};

class QuanLySinhVien{
private:
    vector<SinhVien*> danhSach;
public:
    ~QuanLySinhVien(){
        for(SinhVien* sv : danhSach){
            delete sv;
        }
    }
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Hoi so luong SV. Dung vong lap for, chon 1 cho Cao dang hoac 2 cho Dai hoc. Khoi tao vung nho bang 'new', goi ham nhap() da hinh roi luu vao vector.
    */
    void nhapDanhSach(){
        int n;
        cout << "Nhap so luong sinh vien can them: ";
        cin >> n;
        for(int i=0;i<n;++i){
            int loai;
            cout << "\nChon he dao tao (1 - Cao dang, 2 - Dai hoc): ";
            cin >> loai;
            SinhVien* sv = nullptr;
            if(loai == 1){
                sv = new SinhVienCaoDang();
            }
            else if(loai == 2){
                sv = new SinhVienDaiHoc();
            }else{
                cout << "He dao tao khong hop le!" << endl;
                continue;
            }
            sv->nhap();
            danhSach.push_back(sv);
        }
    }
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Duyet qua toan bo danh sach va goi phuong thuc xuat() ung voi tung doi tuong con tro.
    */
    void xuatDanhSach(){
        cout << "\nDANH SACH SINH VIEN: " << endl;
        for(SinhVien* sv : danhSach){
            sv->xuat();
        }
    }
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Duyet danh sach, dung lenh if kiem tra neu sv->xetTotNghiep() == true thi goi ham xuat() cua sinh vien do.
    */
    void xuatDuDieuKienTN(){
        cout << "\nDANH SACH SINH VIEN DU DIEU KIEN TOT NGHIEP:" << endl;
        bool coSV = false;
        for(SinhVien* sv : danhSach){
            if(sv->xetTotNghiep()){
                sv->xuat();
                coSV = true;
            }
        }
        if(!coSV){
            cout << "Khong co sinh vien nao du dieu kien." << endl;
        }
    }

    /*
    Phuong thuc: xuatKhongDuDieuKienTN()
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Duyet danh sach, neu sv->xetTotNghiep() tra ve false thi hien thi thong tin sinh vien do ra man hinh.
    */
    void xuatKhongDuDieuKienTN(){
        cout << "\nDANH SACH SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP:" << endl;
        bool coSV = false;
        for(SinhVien* sv : danhSach){
            if(!sv->xetTotNghiep()){
                sv->xuat();
                coSV = true;
            }
        }
        if(!coSV){
            cout << "Tat ca sinh vien deu da tot nghiep." << endl;
        }
    }

    /*
    Phuong thuc: timDaiHocMaxGPA()
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Dung dynamic_cast de loc ra cac sinh vien Dai hoc. So sanh getDiemTrungBinh() de tim ra ban co diem cao nhat, sau do in ra.
    */
    void timDaiHocMaxGPA(){
        SinhVien* svMax = nullptr;
        double maxGPA = -1;
        for(SinhVien* sv : danhSach){
            if(dynamic_cast<SinhVienDaiHoc*>(sv)){
                if(sv->getDiemTrungBinh() > maxGPA){
                    maxGPA = sv->getDiemTrungBinh();
                    svMax = sv;
                }
            }
        }
        if(svMax != nullptr){
            cout << "\nSinh vien DAI HOC co diem trung binh cao nhat la:" << endl;
            svMax->xuat();
        }
        else{
            cout << "\nKhong co sinh vien dai hoc nao trong danh sach!" << endl;
        }
    }
    /*
    Phuong thuc: timCaoDangMaxGPA()
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Tuong tu nhu tren, dung dynamic_cast de loc cac ban he Cao dang, so sanh DTB de tim va in ra nguoi co diem cao nhat.
    */
    void timCaoDangMaxGPA(){
        SinhVien* svMax = nullptr;
        double maxGPA = -1;
        for(SinhVien* sv : danhSach){
            if(dynamic_cast<SinhVienCaoDang*>(sv)){
                if(sv->getDiemTrungBinh() > maxGPA){
                    maxGPA = sv->getDiemTrungBinh();
                    svMax = sv;
                }
            }
        }
        if(svMax != nullptr){
            cout << "\nSinh vien CAO DANG co diem trung binh cao nhat la:" << endl;
            svMax->xuat();
        }else{
            cout << "\nKhong co sinh vien cao dang nao trong danh sach!" << endl;
        }
    }
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Khoi tao demCD = 0 va demDH = 0. Duyet qua vector, neu sinh vien do truot tot nghiep (!xetTotNghiep()), kiem tra phan loai bang dynamic_cast va tang bien dem tuong ung.
    */
    void thongKeKhongDuTotNghiep(){
        int demCD = 0;
        int demDH = 0;
        for(SinhVien* sv : danhSach){
            if(!sv->xetTotNghiep()){
                if(dynamic_cast<SinhVienCaoDang*>(sv)){
                    demCD++;
                }
                else if(dynamic_cast<SinhVienDaiHoc*>(sv)){
                    demDH++;
                }
            }
        }
        cout << "\nTHONG KE SINH VIEN TRUOT TOT NGHIEP:" << endl;
        cout << "So sinh vien he Cao Dang khong du dieu kien: " << demCD << endl;
        cout << "So sinh vien he Dai Hoc khong du dieu kien: " << demDH << endl;
    }
};
int main(){
    QuanLySinhVien ql;
    ql.nhapDanhSach();
    ql.xuatDanhSach();
    ql.xuatDuDieuKienTN();
    ql.xuatKhongDuDieuKienTN();
    ql.timDaiHocMaxGPA();
    ql.timCaoDangMaxGPA();
    ql.thongKeKhongDuTotNghiep();
    return 0;
}