#include "cau3.h"

void SinhVien::nhap(){
    cin.ignore();
    cout << "Nhap MSSV: ";
    getline(cin, mssv);
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);
    cout << "Nhap tong so tin chi: ";
    cin >> tongSoTinChi;
    cout << "Nhap diem trung binh: ";
    cin >> diemTrungBinh;
}

void SinhVien::xuat(){
    cout << "MSSV: " << mssv 
         << " | Ho ten: " << hoTen 
         << " | Dia chi: " << diaChi 
         << " | Tin chi: " << tongSoTinChi 
         << " | DTB: " << diemTrungBinh;
}
