#include "cau3.h"

void SinhVienCaoDang::nhap(){
    cout << "\nNhap thong tin Sinh Vien CAO DANG:" << endl;
    SinhVien::nhap();
    cout << "Nhap diem thi tot nghiep: ";
    cin >> diemThiTotNghiep;
}

bool SinhVienCaoDang::xetTotNghiep(){
    if(tongSoTinChi >= 120 && diemTrungBinh >= 5 && diemThiTotNghiep >= 5){
        return true;
    }
    return false;
}

void SinhVienCaoDang::xuat(){
    cout << "[CAO DANG] ";
    SinhVien::xuat();
    cout << " | Diem thi TN: " << diemThiTotNghiep 
         << " | Ket qua: " << (xetTotNghiep() ? "Do Tot Nghiep" : "Khong Tot Nghiep") << endl;
}
