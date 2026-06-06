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
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Yeu cau nguoi dung nhap cac thuoc tinh chung cua moi loai giao dich bao gom: ma giao dich, ngay thang nam, don gia va dien tich.
    */
    virtual void nhap(){
        cin.ignore();
        cout << "Nhap ma giao dich: ";
        getline(cin, maGiaoDich);
        cout << "Nhap ngay giao dich (d/m/y): ";
        cin >> ngayGD.ngay >> ngayGD.thang >> ngayGD.nam;
        cout << "Nhap don gia: ";
        cin >> donGia;
        cout << "Nhap dien tich: ";
        cin >> dienTich;
    }
    /*
    Phuong thuc: xuat()
    Input: Khong co
    Output: Khong co (In ra man hinh)
    Huong giai thuat: In cac thong tin chung cua giao dich.
    */
    virtual void xuat() {
        cout << "Ma GD: " << maGiaoDich 
             << " | Ngay: " << ngayGD.ngay << "/" << ngayGD.thang << "/" << ngayGD.nam
             << " | Don gia: " << (long long)donGia
             << " | Dien tich: " << dienTich
             << " | Thanh tien: " << (long long)tinhThanhTien();
    }
    /*
    Input: Khong co
    Output: Kieu double (Tien giao dich)
    Huong giai thuat: Ham thuan ao, bat buoc cac lop con ghi de de the hien cong thuc tinh rieng biet.
    */
    virtual double tinhThanhTien() = 0;
    // Cac ham getter de ho tro truy xuat du lieu
    int getThang(){ return ngayGD.thang;}
    int getNam(){ return ngayGD.nam; }
    double getThanhTien(){ return thanhTien;}
};
class GiaoDichDat : public GiaoDich{
private:
    char loaiDat;

public:
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Goi ham nhap() cua lop cha de nhap thong tin chung. Sau do yeu cau nhap them loai dat (A/B/C).
    */
    void nhap() override{
        cout << "\nNhap thong tin Giao Dich DAT:" << endl;
        GiaoDich::nhap();
        cout << "Nhap loai dat (A, B, C): ";
        cin >> loaiDat;
    }

    /*
    Input: Khong co
    Output: Kieu double (Thanh tien cua giao dich dat)
    Huong giai thuat: Kiem tra loaiDat. Neu la 'A' thi thanhTien = dienTich * donGia * 1.5. Neu la 'B' hoac 'C' thi thanhTien = dienTich * donGia. Gan vao thuoc tinh cha va tra ve.
    */
    double tinhThanhTien() override{
        if(loaiDat == 'A' || loaiDat == 'a'){
            thanhTien = dienTich * donGia * 1.5;
        }
        else{
            thanhTien = dienTich * donGia;
        }
        return thanhTien;
    }

    void xuat() override{
        cout << "[GD DAT] ";
        GiaoDich::xuat();
        cout << " | Loai dat: " << loaiDat << endl;
    }
};
class GiaoDichNhaPho : public GiaoDich{
private:
    int loaiNha; // 1: Cao cap, 2: Thuong
    string diaChi;
public:
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Goi ham nhap cha. Nhap them dia chi va chon loai nha (1 hoac 2).
    */
    void nhap() override{
        cout << "\nNhap thong tin Giao Dich NHA PHO:" << endl;
        GiaoDich::nhap();
        cout << "Chon loai nha (1 - Cao cap, 2 - Thuong): ";
        cin >> loaiNha;
        cin.ignore();
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
    }
    /*
    Input: Khong co
    Output: Kieu double
    Huong giai thuat: Neu loaiNha la 1 (Cao cap) thi giu nguyen dienTich * donGia. Neu loaiNha la 2 (Thuong) thi nhan them 0.9 (90%).
    */
    double tinhThanhTien() override{
        if(loaiNha == 1){
            thanhTien = dienTich * donGia;
        }else{
            thanhTien = dienTich * donGia * 0.9;
        }
        return thanhTien;
    }

    void xuat() override{
        cout << "[GD NHA PHO] ";
        GiaoDich::xuat();
        cout << " | Loai: " << (loaiNha == 1 ? "Cao cap" : "Thuong") << " | Dia chi: " << diaChi << endl;
    }
};

class GiaoDichChungCu : public GiaoDich{
private:
    string maCan;
    int tang;
public:
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Goi ham nhap cha. Nhap them ma can ho va vi tri tang.
    */
    void nhap() override{
        cout << "\nNhap thong tin Giao Dich CHUNG CU:" << endl;
        GiaoDich::nhap();
        cin.ignore();
        cout << "Nhap ma can ho: ";
        getline(cin, maCan);
        cout << "Nhap vi tri tang: ";
        cin >> tang;
    }
    /*
    Input: Khong co
    Output: Kieu double
    Huong giai thuat: 
    - Tang == 1: he so 2.0
    - Tang >= 15: he so 1.2
    - Con lai: he so 1.0
    Thanh tien = dienTich * donGia * he_so.
    */
    double tinhThanhTien() override{
        if(tang == 1){
            thanhTien = dienTich * donGia * 2.0;
        }else if(tang >= 15){
            thanhTien = dienTich * donGia * 1.2;
        }else{
            thanhTien = dienTich * donGia;
        }
        return thanhTien;
    }

    void xuat() override{
        cout << "[GD CHUNG CU] ";
        GiaoDich::xuat();
        cout << " | Ma can: " << maCan << " | Tang: " << tang << endl;
    }
};
class QuanLyGiaoDich{
private:
    vector<GiaoDich*> danhSach;
public:
    ~QuanLyGiaoDich(){
        for(GiaoDich* gd : danhSach){
            delete gd;
        }
    }
    /*
    Input: Khong co
    Output: Khong co
    Huong giai thuat: Hoi so luong giao dich. Vong lap nhap tung loai (1-Dat, 2-Nha Pho, 3-Chung Cu). Tao doi tuong dong tuong ung bang toan tu new, goi nhap() da hinh, va dua vao vector.
    */
    void nhapDanhSach(){
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
            gd->tinhThanhTien(); // Tinh tien ngay khi nhap xong de luu du lieu
            danhSach.push_back(gd);
        }
    }
    /*
    Input: Khong co
    Output: Khong co (In ket qua ra man hinh)
    Huong giai thuat: Khoi tao 3 bien dem = 0. Duyet danh sach, dung dynamic_cast tung loai de kiem tra giao dich thuoc class nao, sau do tang bien dem tuong ung.
    */
    void tinhTongSoLuongTungLoai(){
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
    /*
    Input: Khong co
    Output: Khong co (In ra man hinh)
    Huong giai thuat: Dung dynamic_cast tim cac giao dich chung cu. Cong don tong tien va dem so luong. Neu so luong > 0 thi in ket qua tong / so luong.
    */
    void tinhTrungBinhThanhTienChungCu(){
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
    /*
    Input: Khong co
    Output: In ra man hinh
    Huong giai thuat: Dung dynamic_cast xac dinh Nha Pho. So sanh getThanhTien() voi bien maxTien hien tai de tim doi tuong Nha Pho co maxTien lon nhat. Goi xuat() de hien thi.
    */
    void timNhaPhoGiaTriCaoNhat(){
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
    /*
    Input: Khong co
    Output: In ra man hinh
    Huong giai thuat: Duyet danh sach, kiem tra dieu kien getThang() == 12 va getNam() == 2024. Neu thoa man, goi ham xuat() cua doi tuong.
    */
    void xuatGiaoDichThang12Nam2024(){
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
};
int main(){
    QuanLyGiaoDich ql;
    ql.nhapDanhSach();
    ql.tinhTongSoLuongTungLoai();
    ql.tinhTrungBinhThanhTienChungCu();
    ql.timNhaPhoGiaTriCaoNhat();
    ql.xuatGiaoDichThang12Nam2024();
    return 0;
}
