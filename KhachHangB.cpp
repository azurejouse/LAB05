#include "cau6.h"

void KhachHangB::nhap(){
    KhachHang::nhap();
    cout << "  + Nhap so nam than thiet: ";
    cin >> soNamThanThiet;
}

double KhachHangB::tinhTien(){
    double phanTramKM = soNamThanThiet * 0.05;
    if(phanTramKM > 0.5){
        phanTramKM = 0.5;
    }
    double giaTri = soLuongHang * donGiaHang;
    double giaTriSauKM = giaTri * (1.0 - phanTramKM);
    double thueVAT = giaTriSauKM * 0.1;
    
    soTienPhaiTra = giaTriSauKM + thueVAT;
    return soTienPhaiTra;
}
