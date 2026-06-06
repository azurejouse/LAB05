#include "cau4.h"

void NhanVien::nhap(){
    cin.ignore();
    cout << "Nhap Ma NV: ";
    getline(cin, maNV);
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap tuoi: ";
    cin >> tuoi;
    cin.ignore();
    cout << "Nhap SDT: ";
    getline(cin, sdt);
    cout << "Nhap Email: ";
    getline(cin, email);
    cout << "Nhap luong co ban: ";
    cin >> luongCoBan;
}

void NhanVien::xuat(){
    cout << "Ma: " << maNV 
         << " | Ten: " << hoTen 
         << " | Tuoi: " << tuoi 
         << " | SDT: " << sdt 
         << " | Email: " << email 
         << " | LCB: " << (long long)luongCoBan
         << " | Luong thuc nhan: " << (long long)luongHangThang;
}
