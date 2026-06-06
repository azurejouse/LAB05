#include "cau6.h"

void KhachHang::nhap(){
    cout << "  + Nhap ten khach hang: ";
    getline(cin >> ws, tenKhachHang);
    cout << "  + Nhap so luong va don gia: ";
    cin >> soLuongHang >> donGiaHang;
}

void KhachHang::xuat(){
    cout << tenKhachHang << "\n";
    cout << (long long)soTienPhaiTra << "\n";
}
