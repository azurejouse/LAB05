    #ifndef CAU3_H
#define CAU3_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

class SinhVien{
protected:
    string mssv;
    string hoTen;
    string diaChi;
    int tongSoTinChi;
    double diemTrungBinh;

public:
    SinhVien() : tongSoTinChi(0), diemTrungBinh(0) {}
    virtual ~SinhVien() {}
    virtual void nhap();
    virtual void xuat();
    virtual bool xetTotNghiep() = 0;
    double getDiemTrungBinh(){ return diemTrungBinh;}
};

class SinhVienCaoDang : public SinhVien{
private:
    double diemThiTotNghiep;
public:
    void nhap() override;
    bool xetTotNghiep() override;
    void xuat() override;
};

class SinhVienDaiHoc : public SinhVien{
private:
    string tenLuanVan;
    double diemLuanVan;
public:
    void nhap() override;
    bool xetTotNghiep() override;
    void xuat() override;
};

class QuanLySinhVien{
private:
    vector<SinhVien*> danhSach;
public:
    ~QuanLySinhVien();
    void nhapDanhSach();
    void xuatDanhSach();
    void xuatDuDieuKienTN();
    void xuatKhongDuDieuKienTN();
    void timDaiHocMaxGPA();
    void timCaoDangMaxGPA();
    void thongKeKhongDuTotNghiep();
};

#endif
