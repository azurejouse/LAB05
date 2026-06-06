#ifndef CAU1_H
#define CAU1_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

struct NgaySinh{
    int ngay, thang, nam;
};

class NhanVien{
protected:
    string hoTen;
    NgaySinh ngaySinh;
    double luong;
public:
    NhanVien() : luong(0) {}
    virtual ~NhanVien() {}
    virtual void nhap();
    virtual void xuat();
    virtual double tinhLuong() = 0;
    int getNamSinh() { return ngaySinh.nam; }
    double getLuong() { return luong; }
};

class NhanVienSanXuat : public NhanVien{
private:
    double luongCanBan;
    int soSanPham;
public:
    void nhap() override;
    double tinhLuong() override;
    void xuat() override;
};

class NhanVienVanPhong : public NhanVien{
private:
    int soNgayLamViec;
public:
    void nhap() override;
    double tinhLuong() override;
    void xuat() override;
};

class CongTy{
private:
    vector<NhanVien*> danhSach;
public:
    ~CongTy();
    void nhapDanhSach();
    void tinhLuongDanhSach();
    void xuatDanhSach();
    void tinhTongLuong();
    void timNVSX_LuongThapNhat();
    void timNVVP_TuoiCaoNhat();
};

#endif
