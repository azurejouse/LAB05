#include "cau6.h"

double KhachHangC::tinhTien(){
    double giaTri = soLuongHang * donGiaHang;
    double giaTriSauKM = giaTri * 0.5;
    double thueVAT = giaTriSauKM * 0.1;
    soTienPhaiTra = giaTriSauKM + thueVAT;
    return soTienPhaiTra;
}
