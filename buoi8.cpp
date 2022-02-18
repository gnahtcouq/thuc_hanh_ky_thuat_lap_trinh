#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100

struct NhanVien {
  char maNhanVien[10];
  char hoTen[50];
  float luongCanBan;
  float heSoLuong;
};

struct CongTy {
  int soNhanVien;
  NhanVien danhSach[MAX];
};


void nhapNhanVien(NhanVien& nhanVien);
void xuatNhanVien(NhanVien nv);
void nhapCongTy(CongTy& cTy);
void xuatCongTy(CongTy cTy);
bool themNhanVien(CongTy& cTy);
void xoaMotNhanVien(CongTy& cTy, int pos);
void xoaNhanVienBangMa(CongTy& cTy);
void sapXepNhanVienTheoMa(CongTy& cTy);
void sapXepNhanVienTheoHeSoLuong(CongTy& cTy);
void lietKeNhanVienCoHeSoLuongLonHon3(CongTy cTy);
void hienThiMenu();

int main() {
  hienThiMenu();
  system("pause");
  return 0;
}

void nhapNhanVien(NhanVien& nhanVien) {
  cin.ignore();
  cout << "Ma nhan vien: ";
  cin.getline(nhanVien.maNhanVien, 10);
  cout << "Ho ten: ";
  cin.getline(nhanVien.hoTen, 50);
  cout << "Luong can ban: ";
  cin >> nhanVien.luongCanBan;
  cout << "He so luong: ";
  cin >> nhanVien.heSoLuong;
}

void xuatNhanVien(NhanVien nv) {
  cout << "\nMa nhan vien: " << nv.maNhanVien;
  cout << "\nHo ten: " << nv.hoTen;
  cout << "\nLuong can ban: " << nv.luongCanBan;
  cout << "\nHe so luong: " << nv.heSoLuong;
  cout << "\n-------------------";
}

void nhapCongTy(CongTy& cTy) {
  cout << "\nNhap so luong nhan vien: ";
  cin >> cTy.soNhanVien;
  cout << "Nhap danh sach nhan vien: " << endl;
  for (int i = 0; i < cTy.soNhanVien; i++) {
    cout << "\nNhap nhan vien thu " << i + 1 << endl;
    nhapNhanVien(cTy.danhSach[i]);
  }
}

void xuatCongTy(CongTy cTy) {
  cout << "\nSo luong nhan vien: " << cTy.soNhanVien << endl;
  cout << "Danh sach nhan vien: " << endl;
  for (int i = 0; i < cTy.soNhanVien; i++) {
    xuatNhanVien(cTy.danhSach[i]);
  }
}

bool themNhanVien(CongTy& cTy) {
  NhanVien nhanVien;
  if (cTy.soNhanVien == MAX)
    return false;
  nhapNhanVien(nhanVien);
  cTy.danhSach[cTy.soNhanVien++] = nhanVien;
  return true;
}

void xoaMotNhanVien(CongTy& cTy, int pos) {
  if (pos < 0 || pos > cTy.soNhanVien)
    cout << "\nNhap sai. Hay Nhap Lai";
  else {
    for (int i = pos + 1; i <= cTy.soNhanVien; i++)
      cTy.danhSach[i - 1] = cTy.danhSach[i];
    cTy.soNhanVien--;
  }
}

void xoaNhanVienBangMa(CongTy& cTy) {
  char str[30];
  cin.ignore();
  cout << "Nhap ma nhan vien can xoa: ";
  cin.getline(str, 10);
  for (int i = 0; i < cTy.soNhanVien; i++) {
    if (strcmp(cTy.danhSach[i].maNhanVien, str) == 0) {
      xoaMotNhanVien(cTy, i);
      i--;
    }
  }
}

void sapXepNhanVienTheoMa(CongTy& cTy) {
  for (int i = 0; i < cTy.soNhanVien; i++) {
    for (int j = i + 1; j < cTy.soNhanVien; j++) {
      if (strcmp(cTy.danhSach[i].maNhanVien, cTy.danhSach[j].maNhanVien) > 0) {
        NhanVien tam = cTy.danhSach[i];
        cTy.danhSach[i] = cTy.danhSach[j];
        cTy.danhSach[j] = tam;
      }
    }
  }
}

void sapXepNhanVienTheoHeSoLuong(CongTy& cTy) {
  for (int i = 0; i < cTy.soNhanVien; i++) {
    for (int j = i + 1; j < cTy.soNhanVien; j++) {
      if (cTy.danhSach[i].heSoLuong > cTy.danhSach[j].heSoLuong) {
        NhanVien tam = cTy.danhSach[i];
        cTy.danhSach[i] = cTy.danhSach[j];
        cTy.danhSach[j] = tam;
      }
    }
  }
}

void lietKeNhanVienCoHeSoLuongLonHon3(CongTy cTy) {
  for (int i = 0; i < cTy.soNhanVien; i++) {
    if (cTy.danhSach[i].heSoLuong > 3)
      xuatNhanVien(cTy.danhSach[i]);
  }
}

void hienThiMenu() {
  NhanVien nhanVien;
  CongTy cTy;
  int chon = 0;
  do {
    cout << "\n0 - Thoat chuong trinh";
    cout << "\n1 - Nhap danh sach nhan vien";
    cout << "\n2 - Xuat danh sach nhan vien";
    cout << "\n3 - Them nhan vien";
    cout << "\n4 - Xoa nhan vien";
    cout << "\n5 - Sap xep danh sach nhan vien theo ma";
    cout << "\n6 - Sap xep danh sach nhan vien theo he so luong";
    cout << "\n7 - Liet ke nhan vien co he so luong > 3";
    cout << "\nVui long chon: ";
    cin >> chon;
    switch (chon) {
    case 0:
      break;
    case 1:
      nhapCongTy(cTy);
      break;
    case 2:
      xuatCongTy(cTy);
      break;
    case 3:
      if (themNhanVien(cTy) == true)
        cout << "Them thanh cong";
      break;
    case 4:
      xoaNhanVienBangMa(cTy);
      break;
    case 5:
      sapXepNhanVienTheoMa(cTy);
      break;
    case 6:
      sapXepNhanVienTheoHeSoLuong(cTy);
      break;
    case 7:
      cout << "\nCac nhan vien co he so luong > 3 la";
      lietKeNhanVienCoHeSoLuongLonHon3(cTy);
      break;
    default:
      cout << "\nBan chon sai, vui long chon lai!";
      break;
    }
  } while (chon != 0);
}