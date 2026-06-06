#include "cau6.h"

CongTyXYZ::~CongTyXYZ(){
    for(KhachHang* kh : danhSach){
        delete kh;
    }
}

void CongTyXYZ::xuLyData(){
    cout << "Nhap so luong khach hang loai A, B, C: ";
    cin >> x >> y >> z;
    // Nhap x khach hang loai A
    if(x > 0){
        cout << "\nNhap " << x << " khach hang loai A: " << endl;
    }
    for(int i=0;i<x;++i){
        cout << "- Khach hang loai A thu " << i + 1 << ":" << endl;
        KhachHangA* a = new KhachHangA();
        a->nhap();
        a->tinhTien();
        danhSach.push_back(a);
    }
    // Nhap y khach hang loai B
    for(int i=0;i<y;++i){
        cout << "- Khach hang loai B thu " << i + 1 << ":" << endl;
        KhachHangB* b = new KhachHangB();
        b->nhap();
        b->tinhTien();
        danhSach.push_back(b);
    }
    // Nhap z khach hang loai C
    for(int i=0;i<z;++i){
        cout << "- Khach hang loai C thu " << i + 1 << ":" << endl;
        KhachHangC* c = new KhachHangC();
        c->nhap();
        c->tinhTien();
        danhSach.push_back(c);
    }
    cout << "\nKET QUA: \n";
    cout << x << " " << y << " " << z << "\n";
    double tongTienCongTyThuDuoc = 0;
    for(KhachHang* kh : danhSach){
        kh->xuat();
        tongTienCongTyThuDuoc += kh->getSoTienPhaiTra();
    }
    
    cout << (long long)tongTienCongTyThuDuoc << "\n";
}
