#include "cau1.h"

void NhanVien::nhap(){
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap ngay sinh (d/m/y): ";
    cin >> ngaySinh.ngay >> ngaySinh.thang >> ngaySinh.nam;
}

void NhanVien::xuat() {
    cout << "Ho ten: " << hoTen 
         << " | Ngay sinh: " << ngaySinh.ngay << "/" << ngaySinh.thang << "/" << ngaySinh.nam 
         << " | Luong: " << (long)luong << " VND";
}
