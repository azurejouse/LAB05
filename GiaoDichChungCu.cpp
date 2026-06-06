#include "cau2.h"

void GiaoDichChungCu::nhap(){
    cout << "\nNhap thong tin Giao Dich CHUNG CU:" << endl;
    GiaoDich::nhap();
    cin.ignore();
    cout << "Nhap ma can ho: ";
    getline(cin, maCan);
    cout << "Nhap vi tri tang: ";
    cin >> tang;
}

double GiaoDichChungCu::tinhThanhTien(){
    if(tang == 1){
        thanhTien = dienTich * donGia * 2.0;
    }else if(tang >= 15){
        thanhTien = dienTich * donGia * 1.2;
    }else{
        thanhTien = dienTich * donGia;
    }
    return thanhTien;
}

void GiaoDichChungCu::xuat(){
    cout << "[GD CHUNG CU] ";
    GiaoDich::xuat();
    cout << " | Ma can: " << maCan << " | Tang: " << tang << endl;
}
