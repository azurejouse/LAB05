#include "cau2.h"

void GiaoDichNhaPho::nhap(){
    cout << "\nNhap thong tin Giao Dich NHA PHO:" << endl;
    GiaoDich::nhap();
    cout << "Chon loai nha (1 - Cao cap, 2 - Thuong): ";
    cin >> loaiNha;
    cin.ignore();
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);
}

double GiaoDichNhaPho::tinhThanhTien(){
    if(loaiNha == 1){
        thanhTien = dienTich * donGia;
    }else{
        thanhTien = dienTich * donGia * 0.9;
    }
    return thanhTien;
}

void GiaoDichNhaPho::xuat(){
    cout << "[GD NHA PHO] ";
    GiaoDich::xuat();
    cout << " | Loai: " << (loaiNha == 1 ? "Cao cap" : "Thuong") << " | Dia chi: " << diaChi << endl;
}
