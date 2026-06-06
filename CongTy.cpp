#include "cau4.h"

CongTy::~CongTy(){
    for(NhanVien* nv : danhSach){
        delete nv;
    }
}

void CongTy::nhapDanhSach(){
    int n;
    cout << "Nhap so luong nhan vien cong ty: ";
    cin >> n;
    for(int i=0; i<n; ++i){
        int loai;
        cout << "\nChon loai NV (1 - Lap Trinh Vien, 2 - Kiem Chung Vien): ";
        cin >> loai;

        NhanVien* nv = nullptr;
        if(loai == 1){
            nv = new LapTrinhVien();
        }
        else if(loai == 2){
            nv = new KiemChungVien();
        }
        else{
            cout << "Loai nhan vien khong hop le!" << endl;
            continue;
        }
        nv->nhap();
        nv->tinhLuong();
        danhSach.push_back(nv);
    }
}

void CongTy::xuatDanhSach(){
    cout << "\nDANH SACH NHAN VIEN CONG TY:" << endl;
    for(NhanVien* nv : danhSach){
        nv->xuat();
    }
}

void CongTy::luongThapHonTrungBinh(){
    if(danhSach.empty()) return;
    double tongLuong = 0;
    for(NhanVien* nv : danhSach){
        tongLuong += nv->getLuong();
    }
    double trungBinh = tongLuong / danhSach.size();
    cout << "\nNV CO LUONG THAP HON TRUNG BINH (" << (long long)trungBinh << " VND):" << endl;
    bool coNV = false;
    for(NhanVien* nv : danhSach){
        if(nv->getLuong() < trungBinh){
            nv->xuat();
            coNV = true;
        }
    }
    if(!coNV){
        cout << "Khong co ai co luong thap hon trung binh." << endl;
    }
}

void CongTy::inNhanVienLuongCaoNhat(){
    NhanVien* nvMax = nullptr;
    double maxLuong = -1;
    for(NhanVien* nv : danhSach){
        if(nv->getLuong() > maxLuong){
            maxLuong = nv->getLuong();
            nvMax = nv;
        }
    }
    if(nvMax != nullptr){
        cout << "\n[TOP 1] Nhan vien co luong CAO nhat cong ty la:" << endl;
        nvMax->xuat();
    }
}

void CongTy::inNhanVienLuongThapNhat(){
    NhanVien* nvMin = nullptr;
    double minLuong = numeric_limits<double>::max();
    for(NhanVien* nv : danhSach){
        if(nv->getLuong() < minLuong){
            minLuong = nv->getLuong();
            nvMin = nv;
        }
    }
    if(nvMin != nullptr){
        cout << "\n[BOTTOM 1] Nhan vien co luong THAP nhat cong ty la:" << endl;
        nvMin->xuat();
    }
}

void CongTy::inLapTrinhVienLuongCaoNhat(){
    NhanVien* nvMax = nullptr;
    double maxLuong = -1;
    for(NhanVien* nv : danhSach){
        if(dynamic_cast<LapTrinhVien*>(nv)){
            if(nv->getLuong() > maxLuong){
                maxLuong = nv->getLuong();
                nvMax = nv;
            }
        }
    }
    if(nvMax != nullptr){
        cout << "\nLap trinh vien co luong CAO nhat la:" << endl;
        nvMax->xuat();
    }else{
        cout << "\nKhong co lap trinh vien nao trong cong ty." << endl;
    }
}

void CongTy::inKiemChungVienLuongThapNhat(){
    NhanVien* nvMin = nullptr;
    double minLuong = numeric_limits<double>::max();
    for(NhanVien* nv : danhSach){
        if(dynamic_cast<KiemChungVien*>(nv)){
            if(nv->getLuong() < minLuong){
                minLuong = nv->getLuong();
                nvMin = nv;
            }
        }
    }
    if(nvMin != nullptr){
        cout << "\nKiem chung vien co luong THAP nhat la:" << endl;
        nvMin->xuat();
    }else{
        cout << "\nKhong co kiem chung vien nao trong cong ty." << endl;
    }
}
