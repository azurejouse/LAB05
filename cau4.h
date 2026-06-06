#ifndef CAU4_H
#define CAU4_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

class NhanVien{
protected:
    string maNV;
    string hoTen;
    int tuoi;
    string sdt;
    string email;
    double luongCoBan;
    double luongHangThang;
public:
    NhanVien() : tuoi(0), luongCoBan(0), luongHangThang(0) {}
    virtual ~NhanVien() {}
    virtual void nhap();
    virtual void xuat();
    virtual double tinhLuong() = 0;
    double getLuong(){ return luongHangThang;}
};

class LapTrinhVien : public NhanVien{
private:
    int soGioOvertime;
public:
    void nhap() override;
    double tinhLuong() override;
    void xuat() override;
};

class KiemChungVien : public NhanVien{
private:
    int soLoiPhatHien;
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
    void xuatDanhSach();
    void luongThapHonTrungBinh();
    void inNhanVienLuongCaoNhat();
    void inNhanVienLuongThapNhat();
    void inLapTrinhVienLuongCaoNhat();
    void inKiemChungVienLuongThapNhat();
};

#endif
