#include "cau1.h"

void NhanVienSanXuat::nhap(){
    cout << "\nNhap thong tin Nhan Vien San Xuat:" << endl;
    NhanVien::nhap();
    cout << "Nhap luong can ban: ";
    cin >> luongCanBan;
    cout << "Nhap so san pham: ";
    cin >> soSanPham;
}

double NhanVienSanXuat::tinhLuong(){
    luong = luongCanBan + (soSanPham * 5000.0);
    return luong;
}

void NhanVienSanXuat::xuat(){
    cout << "[NV San Xuat] ";
    NhanVien::xuat();
    cout << " | So SP: " << soSanPham << endl;
}
