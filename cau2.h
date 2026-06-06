#ifndef CAU2_H
#define CAU2_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

struct NgayGiaoDich{
    int ngay, thang, nam;
};

class GiaoDich{
protected:
    string maGiaoDich;
    NgayGiaoDich ngayGD;
    double donGia;
    double dienTich;
    double thanhTien;
public:
    GiaoDich() : donGia(0), dienTich(0), thanhTien(0) {}
    virtual ~GiaoDich() {}
    virtual void nhap();
    virtual void xuat();
    virtual double tinhThanhTien() = 0;
    int getThang(){ return ngayGD.thang;}
    int getNam(){ return ngayGD.nam; }
    double getThanhTien(){ return thanhTien;}
};

class GiaoDichDat : public GiaoDich{
private:
    char loaiDat;
public:
    void nhap() override;
    double tinhThanhTien() override;
    void xuat() override;
};

class GiaoDichNhaPho : public GiaoDich{
private:
    int loaiNha;
    string diaChi;
public:
    void nhap() override;
    double tinhThanhTien() override;
    void xuat() override;
};

class GiaoDichChungCu : public GiaoDich{
private:
    string maCan;
    int tang;
public:
    void nhap() override;
    double tinhThanhTien() override;
    void xuat() override;
};

class QuanLyGiaoDich{
private:
    vector<GiaoDich*> danhSach;
public:
    ~QuanLyGiaoDich();
    void nhapDanhSach();
    void tinhTongSoLuongTungLoai();
    void tinhTrungBinhThanhTienChungCu();
    void timNhaPhoGiaTriCaoNhat();
    void xuatGiaoDichThang12Nam2024();
};

#endif
