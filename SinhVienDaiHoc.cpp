#include "cau3.h"

void SinhVienDaiHoc::nhap(){
    cout << "\nNhap thong tin Sinh Vien DAI HOC:" << endl;
    SinhVien::nhap();
    cin.ignore();
    cout << "Nhap ten luan van: ";
    getline(cin, tenLuanVan);
    cout << "Nhap diem luan van: ";
    cin >> diemLuanVan;
}

bool SinhVienDaiHoc::xetTotNghiep(){
    if(tongSoTinChi >= 170 && diemTrungBinh >= 5 && diemLuanVan >= 5){
        return true;
    }
    return false;
}

void SinhVienDaiHoc::xuat(){
    cout << "[DAI HOC]  ";
    SinhVien::xuat();
    cout << " | Luan van: " << tenLuanVan << " - Diem: " << diemLuanVan 
         << " | Ket qua: " << (xetTotNghiep() ? "Do Tot Nghiep" : "Khong Tot Nghiep") << endl;
}
