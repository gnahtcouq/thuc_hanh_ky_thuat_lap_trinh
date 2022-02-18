#pragma warning(disable: 4996)
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
#define MAX 100

struct BangDia {
  char maDia[5];
  char nhanDia[30];
  char theLoai[15];
  int giaTien;
};

struct DanhSach {
  int soLuong;
  BangDia data[MAX];
};

void nhap_MotBangDia(BangDia& bd);
void xuat_MotBangDia(BangDia bd);
void nhap_DanhSachBangDia(DanhSach& ds);
void xuat_DanhSachBangDia(DanhSach ds);
void themBangDiaVaoDauDanhSach(DanhSach& ds);
bool suaThongTinKhiBietMaDia(DanhSach& ds, char* ma);
int tinhTongSoTienTrongDanhSachBangDia(DanhSach ds);
void xoaMotBangDiaDauTien(DanhSach& ds);
void sapXepBangDiaGiamDanTheoGiaTien(DanhSach& ds);
void demSoLuongDiaTheoTheLoai(DanhSach ds);
void hienThiMenu();

int main() {
  hienThiMenu();
  system("pause");
  return 0;
}

void nhap_MotBangDia(BangDia& bd) {
  cout << "\nNhap ma dia: ";
  cin.getline(bd.maDia, 5);
  cout << "Nhap nhan dia: ";
  cin.getline(bd.nhanDia, 30);
  cout << "Nhap the loai: ";
  cin.getline(bd.theLoai, 15);
  cout << "Nhap gia tien: ";
  cin >> bd.giaTien;
  cout << endl;
}

void xuat_MotBangDia(BangDia bd) {
  cout << setw(7) << left << bd.maDia << "\t";
  cout << setw(30) << left << bd.nhanDia << "\t";
  cout << setw(15) << left << bd.theLoai << "\t";
  cout << setw(15) << left << bd.giaTien << "\t" << endl;
}

void nhap_DanhSachBangDia(DanhSach& ds) {
  cout << "\nNhap so luong bang dia: ";
  cin >> ds.soLuong;
  cout << "\t\tNHAP THONG TIN TUNG BANG DIA";
  for (int i = 0; i < ds.soLuong; i++) {
    cout << "\n\tBang Dia " << i + 1;
    cin.ignore();
    nhap_MotBangDia(ds.data[i]);
  }
}

void xuat_DanhSachBangDia(DanhSach ds) {
  cout << "\n\tTHONG TIN CAC BANG DIA" << endl;
  cout << setw(7) << left << "Ma Dia" << "\t";
  cout << setw(30) << left << "Nhan Dia" << "\t";
  cout << setw(15) << left << "The Loai" << "\t";
  cout << setw(15) << left << "Gia Tien" << "\t" << endl;
  for (int i = 0; i < ds.soLuong; i++)
    xuat_MotBangDia(ds.data[i]);
}

void themBangDiaVaoDauDanhSach(DanhSach& ds) {
  BangDia bd;
  cin.ignore();
  nhap_MotBangDia(bd);
  for (int i = ds.soLuong - 1; i >= 0; i--)
    ds.data[i + 1] = ds.data[i];
  ds.data[0] = bd;
  ds.soLuong++;
  cout << "\nDanh sach bang dia sau khi them la: ";
  xuat_DanhSachBangDia(ds);
}

bool suaThongTinKhiBietMaDia(DanhSach& ds, char* ma) {
  for (int i = 0; i < ds.soLuong; i++)
    if (strcmp(ds.data[i].maDia, ma) == 0) {
      cout << "Nhap nhan dia moi: ";
      cin.getline(ds.data[i].nhanDia, 30);
      return true;
    }
  return false;
}

int tinhTongSoTienTrongDanhSachBangDia(DanhSach ds) {
  int tong = 0;
  for (int i = 0; i < ds.soLuong; i++)
    tong += ds.data[i].giaTien;
  return tong;
}

void xoaMotBangDiaDauTien(DanhSach& ds) {
  for (int i = 1; i <= ds.soLuong; i++)
    ds.data[i - 1] = ds.data[i];
  ds.soLuong--;
}

void sapXepBangDiaGiamDanTheoGiaTien(DanhSach& ds) {
  for (int i = 0; i < ds.soLuong; i++)
    for (int j = i + 1; j < ds.soLuong; j++)
      if (ds.data[i].giaTien < ds.data[j].giaTien) {
        BangDia tam = ds.data[i];
        ds.data[i] = ds.data[j];
        ds.data[j] = tam;
      }
  xuat_DanhSachBangDia(ds);
}

void demSoLuongDiaTheoTheLoai(DanhSach ds) {
  char a[100][100];
  strcpy(a[0], ds.data[0].theLoai);
  int x = 1;
  for (int i = 1; i < ds.soLuong; i++) {
    int dem = 0;
    for (int j = 0; j < x; j++)
      if (strcmp(ds.data[i].theLoai, a[j]) == 0)
        dem++;
    if (dem == 0) {
      strcpy(a[x], ds.data[i].theLoai);
      x++;
    }
  }
  for (int j = 0; j < x; j++) {
    int dem = 0;
    for (int i = 0; i < ds.soLuong; i++)
      if (strcmp(ds.data[i].theLoai, a[j]) == 0)
        dem++;
    cout << "\n\tThe loai " << a[j] << " co " << dem << " dia";
  }
}

void hienThiMenu() {
  BangDia bd;
  DanhSach ds;
  ds.soLuong = 0;
  int chon = 0;
  do {
    cout << "\n--------------- MENU ---------------";
    cout << "\n\n0 - Thoat chuong trinh";
    cout << "\n1 - Nhap danh sach bang dia";
    cout << "\n2 - Xuat danh sach bang dia";
    cout << "\n3 - Them 1 bang dia vao dau danh sach";
    cout << "\n4 - Sua thong tin nhan dia cua 1 bang dia khi biet ma bang dia";
    cout << "\n5 - Tinh tong so tien trong danh sach bang dia";
    cout << "\n6 - Xoa 1 bang dia dau tien";
    cout << "\n7 - Sap xep cac bang dia giam dan theo gia tien";
    cout << "\n8 - Dem so luong dia cua moi the loai";
    cout << "\nVui long chon: ";
    cin >> chon;
    switch (chon) {
    case 0:
      break;
    case 1:
      nhap_DanhSachBangDia(ds);
      break;
    case 2:
      if (ds.soLuong == 0)
        cout << "\n2. Danh sach rong" << endl;
      else {
        cout << "\n2. Danh sach cac bang dia da nhap la: ";
        xuat_DanhSachBangDia(ds);
      }
      break;
    case 3:
      cout << "\n3. Nhap thong tin bang dia can them vao dau danh sach";
      themBangDiaVaoDauDanhSach(ds);
      break;
    case 4:
      char str[5];
      cout << "\n4. Nhap ma dia can sua thong tin nhan dia: ";
      cin.ignore();
      cin.getline(str, 5);
      if (suaThongTinKhiBietMaDia(ds, str))
        cout << "Sua thong tin nhan dia cua ma dia " << str << " thanh cong";
      else
        cout << "Sua khong thanh cong";
      cout << "\nDanh sach bang dia sau khi sua thong tin la: ";
      xuat_DanhSachBangDia(ds);
      break;
    case 5:
      cout << "\n5. Tong so tien trong danh sach bang dia = " << tinhTongSoTienTrongDanhSachBangDia(ds) << endl;
      break;
    case 6:
      cout << "\n6. Xoa 1 bang dia o vi tri dau tien: ";
      xoaMotBangDiaDauTien(ds);
      cout << "\nDanh sach sau khi xoa: ";
      xuat_DanhSachBangDia(ds);
      break;
    case 7:
      cout << "\n7. Sap xep cac bang dia giam dan theo gia tien";
      sapXepBangDiaGiamDanTheoGiaTien(ds);
      break;
    case 8:
      cout << "\n8. Dem so luong dia theo the loai: ";
      demSoLuongDiaTheoTheLoai(ds);
      break;
    default:
      cout << "\nBan chon sai, vui long chon lai!";
      break;
    }
  } while (chon != 0);
}