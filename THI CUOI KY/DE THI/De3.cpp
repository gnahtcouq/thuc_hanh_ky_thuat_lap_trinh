#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
#define MAX 100

struct MonHoc {
  char maMH[5];
  char tenMH[15];
  int soTC;
  char giaoVien[30];
};

struct DanhSach {
  int soLuong;
  MonHoc data[MAX];
};

void nhap_MotMonHoc(MonHoc &mh);
void xuat_MotMonHoc(MonHoc mh);
void nhap_DanhSachMonHoc(DanhSach &ds);
void xuat_DanhSachMonHoc(DanhSach ds);
void themMonHocVaoDauDanhSach(DanhSach& ds);
bool suaThongTinKhiBietMaMocHoc(DanhSach& ds, char* ma);
bool timKiemThongTinMonHoc(DanhSach ds, char *str);
void xoaMotMonHoc(DanhSach &ds, int vitri);
bool xoaMotMonHocTaiViTriBatKy(DanhSach &ds, char *str);
void sapXepMonHocGiamDanTheoTinChi(DanhSach &ds);
void xuatThongTinGiaoVienPhuTrachMonHocNao(DanhSach ds);
void hienThiMenu();

int main() {
  hienThiMenu();
  system("pause");
  return 0;
}

void nhap_MotMonHoc(MonHoc &mh) {
  cout << "\nNhap ma MH: ";
  cin.getline(mh.maMH, 5);
  cout << "Nhap ten MH: ";
  cin.getline(mh.tenMH, 15);
  cout << "Nhap ten giao vien: ";
  cin.getline(mh.giaoVien, 30);
  cout << "Nhap so TC: ";
  cin >> mh.soTC;
  cout << endl;
}

void xuat_MotMonHoc(MonHoc mh) {
  cout << setw(5) << left << mh.maMH << "\t";
  cout << setw(15) << left << mh.tenMH << "\t";
  cout << setw(5) << left << mh.soTC << "\t";
  cout << setw(30) << left << mh.giaoVien << "\t" << endl;
}

void nhap_DanhSachMonHoc(DanhSach &ds) {
  cout << "\nNhap so luong mon hoc: ";
  cin >> ds.soLuong;
  cout << "\t\tNHAP THONG TIN TUNG MON HOC";
  for (int i = 0; i < ds.soLuong; i++) {
    cout << "\n\tMon Hoc " << i + 1;
    cin.ignore();
    nhap_MotMonHoc(ds.data[i]);
  }
}

void xuat_DanhSachMonHoc(DanhSach ds) {
  cout << "\n\tTHONG TIN CAC MON HOC" << endl;
  cout << setw(5) << left << "Ma MH" << "\t";
  cout << setw(15) << left << "Ten MH" << "\t";
  cout << setw(5) << left << "So TC" << "\t";
  cout << setw(30) << left << "Giao Vien" << "\t" << endl;
  for (int i = 0; i < ds.soLuong; i++)
    xuat_MotMonHoc(ds.data[i]);
}

void themMonHocVaoDauDanhSach(DanhSach& ds) {
  MonHoc mh;
  cin.ignore();
  nhap_MotMonHoc(mh);
  for (int i = ds.soLuong - 1; i >= 0; i--)
    ds.data[i + 1] = ds.data[i];
  ds.data[0] = mh;
  ds.soLuong++;
  cout << "\nDanh sach mon hoc sau khi them la: ";
  xuat_DanhSachMonHoc(ds);
}

bool suaThongTinKhiBietMaMocHoc(DanhSach& ds, char* ma) {
  for (int i = 0; i < ds.soLuong; i++)
    if (strcmp(ds.data[i].maMH, ma) == 0) {
      cout << "Nhap so TC moi: ";
      cin >> ds.data[i].soTC;
      return true;
    }
  return false;
}

bool timKiemThongTinMonHoc(DanhSach ds, char *str) {
  cout << setw(5) << left << "Ma MH" << "\t";
  cout << setw(15) << left << "Ten MH" << "\t";
  cout << setw(5) << left << "So TC" << "\t";
  cout << setw(30) << left << "Giao Vien" << "\t" << endl;
  for (int i = 0; i < ds.soLuong; i++)
    if (strcmp(ds.data[i].maMH, str) == 0) {
      xuat_MotMonHoc(ds.data[i]);
      return true;
    }
  return false;
}

void xoaMotMonHoc(DanhSach &ds, int vitri) {
  if (vitri < 0 || vitri > ds.soLuong)
    cout << "\nVi tri khong hop le";
  else {
    for (int i = vitri + 1; i <= ds.soLuong; i++)
      ds.data[i - 1] = ds.data[i];
    ds.soLuong--;
  }
}

bool xoaMotMonHocTaiViTriBatKy(DanhSach &ds, char *str) {
  for (int i = 0; i < ds.soLuong; i++)
    if (strcmp(ds.data[i].maMH, str) == 0) {
      xoaMotMonHoc(ds, i);
      return true;
    }
  return false;
}

void sapXepMonHocGiamDanTheoTinChi(DanhSach &ds) {
  for (int i = 0; i < ds.soLuong; i++)
    for (int j = i + 1; j < ds.soLuong; j++)
      if (ds.data[i].soTC < ds.data[j].soTC) {
        MonHoc tam = ds.data[i];
        ds.data[i] = ds.data[j];
        ds.data[j] = tam;
      }
  xuat_DanhSachMonHoc(ds);
}

void xuatThongTinGiaoVienPhuTrachMonHocNao(DanhSach ds) {
  for (int i = 0; i < ds.soLuong; i++)
    cout << "\nGiao vien " << ds.data[i].giaoVien << " phu trach mon hoc " << ds.data[i].tenMH;
}

void hienThiMenu() {
  MonHoc mh;
  DanhSach ds;
  ds.soLuong = 0;
  int chon = 0;
  do {
    cout << "\n--------------- MENU ---------------";
    cout << "\n\n0 - Thoat chuong trinh";
    cout << "\n1 - Nhap danh sach mon hoc";
    cout << "\n2 - Xuat danh sach mon hoc";
    cout << "\n3 - Them 1 mon hoc vao dau danh sach";
    cout << "\n4 - Sua thong tin tin chi cua 1 mon hoc khi biet ma mon hoc";
    cout << "\n5 - Tim thong tin mon hoc khi biet ma mon hoc";
    cout << "\n6 - Xoa 1 mon hoc tai vi tri bat ky";
    cout << "\n7 - Sap xep cac mon hoc giam dan theo so TC";
    cout << "\n8 - Cho biet moi giao vien phuc trach nhung mon hoc nao";
    cout << "\nVui long chon: ";
    cin >> chon;
    switch (chon) {
    case 0:
      break;
    case 1:
      nhap_DanhSachMonHoc(ds);
      break;
    case 2:
      if (ds.soLuong == 0)
        cout << "\n2. Danh sach rong" << endl;
      else {
        cout << "\n2. Danh sach cac mon hoc da nhap la: ";
        xuat_DanhSachMonHoc(ds);
      }
      break;
    case 3:
      cout << "\n3. Nhap thong tin mon hoc can them vao dau danh sach";
      themMonHocVaoDauDanhSach(ds);
      break;
    case 4:
      char str[5];
      cout << "\n4. Nhap ma mon hoc can sua thong tin tin chi: ";
      cin.ignore();
      cin.getline(str, 5);
      if (suaThongTinKhiBietMaMocHoc(ds, str))
        cout << "Sua thong tin tin chi cua ma mon hoc " << str << " thanh cong";
      else
        cout << "Sua khong thanh cong";
      cout << "\nDanh sach mon hoc sau khi sua thong tin la: ";
      xuat_DanhSachMonHoc(ds);
      break;
    case 5:
      char str2[5];
      cout << "\n5. Nhap ma mon hoc can xuat thong tin: ";
      cin.ignore();
      cin.getline(str2, 5);
      if (!timKiemThongTinMonHoc(ds, str2))
        cout << "\nKhong tim thay, hay thu lai" << endl;
      break;
    case 6:
      char str3[5];
      cout << "\n5. Nhap ma mon hoc can xoa: ";
      cin.ignore();
      cin.getline(str3, 30);
      if (xoaMotMonHocTaiViTriBatKy(ds, str3)) {
        cout << "Danh sach mon hoc sau khi xoa la: ";
        xuat_DanhSachMonHoc(ds);
      }
      else
        cout << "Khong tim thay, hay thu lai" << endl;
      break;
    case 7:
      cout << "\n7. Sap xep cac mon hoc giam dan theo so TC";
      sapXepMonHocGiamDanTheoTinChi(ds);
      break;
    case 8:
      cout << "\n8. Cho biet moi giao vien phuc trach nhung mon hoc: ";
      xuatThongTinGiaoVienPhuTrachMonHocNao(ds);
      break;
    default:
      cout << "\nBan chon sai, vui long chon lai!";
      break;
    }
  } while (chon != 0);
}