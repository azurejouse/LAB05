#include "cau2.h"

QuanLyGiaoDich::~QuanLyGiaoDich(){
    for(GiaoDich* gd : danhSach){
        delete gd;
    }
}

void QuanLyGiaoDich::nhapDanhSach(){
    int n;
    cout << "Nhap so luong giao dich: ";
    cin >> n;
    for(int i = 0; i < n; ++i){
        int loai;
        cout << "\nChon loai GD (1 - Dat, 2 - Nha Pho, 3 - Chung Cu): ";
        cin >> loai;

        GiaoDich* gd = nullptr;
        if(loai == 1){
            gd = new GiaoDichDat();
        }else if(loai == 2){
            gd = new GiaoDichNhaPho();
        }else if(loai == 3){
            gd = new GiaoDichChungCu();
        }else{
            cout << "Loai GD khong hop le!" << endl;
            continue;
        }
        gd->nhap();
        gd->tinhThanhTien();
        danhSach.push_back(gd);
    }
}

void QuanLyGiaoDich::tinhTongSoLuongTungLoai(){
    int demDat = 0, demNhaPho = 0, demChungCu = 0;
    for(GiaoDich* gd : danhSach){
        if(dynamic_cast<GiaoDichDat*>(gd)){
            demDat++;
        }else if(dynamic_cast<GiaoDichNhaPho*>(gd)){
            demNhaPho++;
        }
        else if(dynamic_cast<GiaoDichChungCu*>(gd)){
            demChungCu++;
        }
    }
    cout << "\nTong so luong Giao Dich Dat: " << demDat;
    cout << "\nTong so luong Giao Dich Nha Pho: " << demNhaPho;
    cout << "\nTong so luong Giao Dich Chung Cu: " << demChungCu << endl;
}

void QuanLyGiaoDich::tinhTrungBinhThanhTienChungCu(){
    double tongTien = 0;
    int dem = 0;
    for(GiaoDich* gd : danhSach){
        if(dynamic_cast<GiaoDichChungCu*>(gd)){
            tongTien += gd->getThanhTien();
            dem++;
        }
    }
    if(dem > 0){
        cout << "\nTrung binh thanh tien cua GD Chung Cu: " << (long long)(tongTien / dem) << " VND" << endl;
    }else{
        cout << "\nKhong co GD Chung Cu nao de tinh trung binh." << endl;
    }
}

void QuanLyGiaoDich::timNhaPhoGiaTriCaoNhat(){
    GiaoDich* maxGD = nullptr;
    double maxTien = -1;
    for(GiaoDich* gd : danhSach){
        if(dynamic_cast<GiaoDichNhaPho*>(gd)){
            if(gd->getThanhTien() > maxTien){
                maxTien = gd->getThanhTien();
                maxGD = gd;
            }
        }
    }
    if(maxGD != nullptr){
        cout << "\nGiao Dich Nha Pho co gia tri cao nhat la:" << endl;
        maxGD->xuat();
    }else{
        cout << "\nKhong co GD Nha Pho nao trong danh sach!" << endl;
    }
}

void QuanLyGiaoDich::xuatGiaoDichThang12Nam2024(){
    cout << "\nDanh sach Giao Dich Thang 12 Nam 2024:" << endl;
    bool coGiaoDich = false;
    for(GiaoDich* gd : danhSach){
        if(gd->getThang() == 12 && gd->getNam() == 2024){
            gd->xuat();
            coGiaoDich = true;
        }
    }
    if(!coGiaoDich){
        cout << "Khong co giao dich nao trong thoi gian nay." << endl;
    }
}
