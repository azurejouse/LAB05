#include "cau6.h"

double KhachHangA::tinhTien(){
    double giaTri = soLuongHang * donGiaHang;
    double thueVAT = giaTri * 0.1;
    soTienPhaiTra = giaTri + thueVAT;
    return soTienPhaiTra;
}
