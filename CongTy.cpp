#include "cau1.h"

CongTy::~CongTy(){
    for (NhanVien* nv : danhSach){
        delete nv; 
    }
}

void CongTy::nhapDanhSach(){
    int soLuong;
    cout << "Nhap so luong nhan vien can them: ";
    cin >> soLuong;
    for(int i = 0; i < soLuong; ++i){
        int loai;
        cout << "\nChon loai nhan vien (1 - NV San Xuat, 2 - NV Van Phong): ";
        cin >> loai;
        NhanVien* nv = nullptr;
        if(loai == 1){
            nv = new NhanVienSanXuat();
        }else if(loai == 2){
            nv = new NhanVienVanPhong();
        }else{
            cout << "Loai khong hop le, bo qua!" << endl;
            continue;
        }
        nv->nhap();
        danhSach.push_back(nv);
    }
}

void CongTy::tinhLuongDanhSach(){
    for(NhanVien* nv : danhSach){
        nv->tinhLuong();
    }
}

void CongTy::xuatDanhSach(){
    cout << "\nDANH SACH NHAN VIEN:" << endl;
    for (NhanVien* nv : danhSach){
        nv->xuat();
    }
}

void CongTy::tinhTongLuong(){
    double tong = 0;
    for(NhanVien* nv : danhSach){
        tong += nv->getLuong();
    }
    cout << "\nTong luong cong ty phai tra: " << (long)tong << " VND" << endl;
}

void CongTy::timNVSX_LuongThapNhat(){
    NhanVien* nvMin = nullptr;
    double minLuong = numeric_limits<double>::max();
    for(NhanVien* nv : danhSach){
        NhanVienSanXuat* nvsx = dynamic_cast<NhanVienSanXuat*>(nv);
        if(nvsx != nullptr) {
            if (nvsx->getLuong() < minLuong){
                minLuong = nvsx->getLuong();
                nvMin = nvsx;
            }
        }
    }
    if(nvMin != nullptr){
        cout << "\nNhan vien san xuat co luong thap nhat la: \n";
        nvMin->xuat();
    }else{
        cout << "\nKhong co nhan vien san xuat nao trong danh sach!" << endl;
    }
}

void CongTy::timNVVP_TuoiCaoNhat(){
    NhanVien* nvMaxTuoi = nullptr;
    int maxTuoi = -1;
    int namHienTai = 2026; 
    for(NhanVien* nv : danhSach){
        NhanVienVanPhong* nvvp = dynamic_cast<NhanVienVanPhong*>(nv);
        if(nvvp != nullptr){
            int tuoi = namHienTai - nvvp->getNamSinh();
            if(tuoi > maxTuoi){
                maxTuoi = tuoi;
                nvMaxTuoi = nvvp;
            }
        }
    }
    if(nvMaxTuoi != nullptr){
        cout << "\nNhan vien van phong cao tuoi nhat la (" << maxTuoi << " tuoi): \n";
        nvMaxTuoi->xuat();
    }else{
        cout << "\nKhong co nhan vien van phong nao trong danh sach!" << endl;
    }
}
