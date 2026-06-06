#include "cau2.h"

void GiaoDich::nhap(){
    cin.ignore();
    cout << "Nhap ma giao dich: ";
    getline(cin, maGiaoDich);
    cout << "Nhap ngay giao dich (d/m/y): ";
    cin >> ngayGD.ngay >> ngayGD.thang >> ngayGD.nam;
    cout << "Nhap don gia: ";
    cin >> donGia;
    cout << "Nhap dien tich: ";
    cin >> dienTich;
}

void GiaoDich::xuat() {
    cout << "Ma GD: " << maGiaoDich 
         << " | Ngay: " << ngayGD.ngay << "/" << ngayGD.thang << "/" << ngayGD.nam
         << " | Don gia: " << (long long)donGia
         << " | Dien tich: " << dienTich
         << " | Thanh tien: " << (long long)tinhThanhTien();
}
