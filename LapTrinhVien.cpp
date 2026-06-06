#include "cau4.h"

void LapTrinhVien::nhap(){
    cout << "\nNhap thong tin LAP TRINH VIEN:" << endl;
    NhanVien::nhap();
    cout << "Nhap so gio overtime: ";
    cin >> soGioOvertime;
}

double LapTrinhVien::tinhLuong(){
    luongHangThang = luongCoBan + (soGioOvertime * 200000.0);
    return luongHangThang;
}

void LapTrinhVien::xuat(){
    cout << "[LTV] ";
    NhanVien::xuat();
    cout << " | Gio OT: " << soGioOvertime << endl;
}
