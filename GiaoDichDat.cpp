#include "cau2.h"

void GiaoDichDat::nhap(){
    cout << "\nNhap thong tin Giao Dich DAT:" << endl;
    GiaoDich::nhap();
    cout << "Nhap loai dat (A, B, C): ";
    cin >> loaiDat;
}

double GiaoDichDat::tinhThanhTien(){
    if(loaiDat == 'A' || loaiDat == 'a'){
        thanhTien = dienTich * donGia * 1.5;
    }
    else{
        thanhTien = dienTich * donGia;
    }
    return thanhTien;
}

void GiaoDichDat::xuat(){
    cout << "[GD DAT] ";
    GiaoDich::xuat();
    cout << " | Loai dat: " << loaiDat << endl;
}
