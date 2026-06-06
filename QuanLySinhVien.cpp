#include "cau3.h"

QuanLySinhVien::~QuanLySinhVien(){
    for(SinhVien* sv : danhSach){
        delete sv;
    }
}

void QuanLySinhVien::nhapDanhSach(){
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

void QuanLySinhVien::xuatDanhSach(){
    cout << "\nDANH SACH SINH VIEN: " << endl;
    for(SinhVien* sv : danhSach){
        sv->xuat();
    }
}

void QuanLySinhVien::xuatDuDieuKienTN(){
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

void QuanLySinhVien::xuatKhongDuDieuKienTN(){
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

void QuanLySinhVien::timDaiHocMaxGPA(){
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

void QuanLySinhVien::timCaoDangMaxGPA(){
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

void QuanLySinhVien::thongKeKhongDuTotNghiep(){
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
