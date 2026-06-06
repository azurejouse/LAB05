#ifndef CAU6_H
#define CAU6_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class KhachHang{
protected:
    string tenKhachHang;
    double soLuongHang;
    double donGiaHang;
    double soTienPhaiTra;
public:
    KhachHang() : soLuongHang(0), donGiaHang(0), soTienPhaiTra(0) {}
    virtual ~KhachHang() {}
    virtual void nhap();
    virtual void xuat();
    virtual double tinhTien() = 0;
    double getSoTienPhaiTra(){ return soTienPhaiTra; }
};

class KhachHangA : public KhachHang{
public:
    double tinhTien() override;
};

class KhachHangB : public KhachHang{
private:
    int soNamThanThiet;
public:
    void nhap() override;
    double tinhTien() override;
};

class KhachHangC : public KhachHang{
public:
    double tinhTien() override;
};

class CongTyXYZ{
private:
    int x, y, z;
    vector<KhachHang*> danhSach;
public:
    CongTyXYZ() : x(0), y(0), z(0) {}
    ~CongTyXYZ();
    void xuLyData();
};

#endif
