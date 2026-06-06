#include "cau1.h"

void NhanVienVanPhong::nhap(){
    cout << "\nNhap thong tin Nhan Vien Van Phong:" << endl;
    NhanVien::nhap();
    cout << "Nhap so ngay lam viec: ";
    cin >> soNgayLamViec;
}

double NhanVienVanPhong::tinhLuong(){
    luong = soNgayLamViec * 100000.0;
    return luong;
}

void NhanVienVanPhong::xuat(){
    cout << "[NV Van Phong] ";
    NhanVien::xuat();
    cout << " | So ngay lam: " << soNgayLamViec << endl;
}
