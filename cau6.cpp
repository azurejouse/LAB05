#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
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
    
    virtual void nhap(){
        // Bỏ '>> ws', chỉ dùng getline thuần túy để đọc trọn vẹn dòng tên
        getline(cin, tenKhachHang);
        cin >> soLuongHang >> donGiaHang;
        cin.ignore(); // Xóa dấu xuống dòng còn sót lại sau khi nhập số
    }

    virtual void xuat(){
        cout << tenKhachHang << "\n";
        cout << (long long)soTienPhaiTra << "\n";
    }

    virtual double tinhTien() = 0;
    double getSoTienPhaiTra(){ return soTienPhaiTra; }
};

class KhachHangA : public KhachHang{
public:
    double tinhTien() override{
        double giaTri = soLuongHang * donGiaHang;
        double thueVAT = giaTri * 0.1;
        soTienPhaiTra = giaTri + thueVAT;
        return soTienPhaiTra;
    }
};

class KhachHangB : public KhachHang{
private:
    int soNamThanThiet;
public:
    void nhap() override{
        // Gọi hàm nhập của cha để lấy tên, số lượng, đơn giá
        KhachHang::nhap();
        cin >> soNamThanThiet;
        cin.ignore(); // Xóa dấu xuống dòng sau khi nhập số năm thân thiết
    }

    double tinhTien() override{
        double phanTramKM = soNamThanThiet * 0.05;
        if(phanTramKM > 0.5){
            phanTramKM = 0.5;
        }
        double giaTri = soLuongHang * donGiaHang;
        double giaTriSauKM = giaTri * (1.0 - phanTramKM);
        double thueVAT = giaTriSauKM * 0.1;
        
        soTienPhaiTra = giaTriSauKM + thueVAT;
        return soTienPhaiTra;
    }
};

class KhachHangC : public KhachHang{
public:
    double tinhTien() override{
        double giaTri = soLuongHang * donGiaHang;
        double giaTriSauKM = giaTri * 0.5;
        double thueVAT = giaTriSauKM * 0.1;
        soTienPhaiTra = giaTriSauKM + thueVAT;
        return soTienPhaiTra;
    }
};

class CongTyXYZ{
private:
    int x, y, z;
    vector<KhachHang*> danhSach;
public:
    CongTyXYZ() : x(0), y(0), z(0) {}
    ~CongTyXYZ(){
        for(KhachHang* kh : danhSach){
            delete kh;
        }
    }
    
    void xuLyData(){
        if (!(cin >> x >> y >> z)) return;
        cin.ignore(); // Xóa dấu xuống dòng ngay sau khi đọc bộ ba số x y z

        // Nhap x khach hang loai A
        for(int i = 0; i < x; ++i){
            KhachHangA* a = new KhachHangA();
            a->nhap();
            a->tinhTien();
            danhSach.push_back(a);
        }
        // Nhap y khach hang loai B
        for(int i = 0; i < y; ++i){
            KhachHangB* b = new KhachHangB();
            b->nhap();
            b->tinhTien();
            danhSach.push_back(b);
        }
        // Nhap z khach hang loai C
        for(int i = 0; i < z; ++i){
            KhachHangC* c = new KhachHangC();
            c->nhap();
            c->tinhTien();
            danhSach.push_back(c);
        }
        
        // In dòng đầu tiên chứa x y z đúng định dạng ảnh mẫu
        cout << x << " " << y << " " << z << "\n";
        
        double tongTienCongTyThuDuoc = 0;
        for(KhachHang* kh : danhSach){
            kh->xuat();
            tongTienCongTyThuDuoc += kh->getSoTienPhaiTra();
        }
        
        // In tổng tiền thu được ở dòng cuối cùng
        cout << (long long)tongTienCongTyThuDuoc << "\n";
    }
};

int main(){
    
    CongTyXYZ congTy;
    congTy.xuLyData();
    return 0;
}