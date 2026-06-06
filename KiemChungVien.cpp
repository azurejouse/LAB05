#include "cau4.h"

void KiemChungVien::nhap(){
    cout << "\nNhap thong tin KIEM CHUNG VIEN:" << endl;
    NhanVien::nhap();
    cout << "Nhap so loi phat hien: ";
    cin >> soLoiPhatHien;
}

double KiemChungVien::tinhLuong(){
    luongHangThang = luongCoBan + (soLoiPhatHien * 50000.0);
    return luongHangThang;
}

void KiemChungVien::xuat(){
    cout << "[KCV] ";
    NhanVien::xuat();
    cout << " | So loi: " << soLoiPhatHien << endl;
}
