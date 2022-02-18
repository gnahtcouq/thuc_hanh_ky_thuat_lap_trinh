#include <iostream>
using namespace std;

#define MAX 100

struct NhanVien {
  int ma;
  char ten[30];
  int tuoi;
  char chucVu[30];
  float heSoLuong;
};
typedef struct NhanVien NHANVIEN;

struct DanhSachNhanVien {
  NHANVIEN ds[100];
  int soLuong;
};
typedef struct DanhSachNhanVien DANHSACHNHANVIEN;

void nhapNhanVien(NHANVIEN &nv) {
  cout << "Nhap ma nhan vien: ";
  cin >> nv.ma;
  cin.ignore();
  cout << "Nhap ten nhan vien: ";
  cin.getline(nv.ten, 30);
  cout << "Nhap tuoi: ";
  cin >> nv.tuoi;
  cin.ignore();
  cout << "Nhap chuc vu: ";
  cin.getline(nv.chucVu, 30);
  cout << "Nhap he so luong: ";
  cin >> nv.heSoLuong;
  cout << endl;
  cin.ignore();
}

void xuatNhanVien(NHANVIEN nv) {
  cout << nv.ma << "\t" << nv.ten << "\t" << nv.tuoi << "\t" << nv.chucVu << "\t" << nv.heSoLuong << endl;
}

void nhapDanhSachNhanVien(DANHSACHNHANVIEN &dsnv) {
  do {
    cout << "\nNhap so luong nhan vien: ";
    cin >> dsnv.soLuong;
  } while (dsnv.soLuong <= 0 || dsnv.soLuong > MAX);
  cin.ignore();
  for (int i = 0; i < dsnv.soLuong; i++) {
    nhapNhanVien(dsnv.ds[i]);
  }
}

void xuatDanhSachNhanVien(DANHSACHNHANVIEN dsnv) {
  for (int i = 0; i < dsnv.soLuong; i++) {
    xuatNhanVien(dsnv.ds[i]);
  }
}

bool ghiDanhSachNhanVien(DANHSACHNHANVIEN dsnv, char *tenFile) {
  FILE *f;
  f = fopen(tenFile, "wb");
  if (f == NULL)
    return false;
  fwrite(&dsnv.soLuong, sizeof(int), 1, f);
  fwrite(&dsnv.ds, sizeof(NHANVIEN), dsnv.soLuong, f);
  fclose(f);
  return true;
}

bool docDanhSachNhanVien(DANHSACHNHANVIEN &dsnv, char *tenFile) {
  FILE *f;
  f = fopen(tenFile, "rb");
  if (f == NULL)
    return false;
  fread(&dsnv.soLuong, sizeof(int), 1, f);
  fread(&dsnv.ds, sizeof(NHANVIEN), dsnv.soLuong, f);
  fclose(f);
  return true;
}

int tinhTongLuongCuaCongTy(DANHSACHNHANVIEN dsnv, float luongCB) {
  float tongLuong = 0;
  for (int i = 0; i <= dsnv.soLuong; i++) {
    tongLuong += dsnv.ds[i].heSoLuong * luongCB;
  }
  return tongLuong;
}

bool timNhanVienTheoMa(DANHSACHNHANVIEN dsnv, int x) {
  for (int i = 0; i <= dsnv.soLuong; i++) {
    if (x == dsnv.ds[i].ma) {
      xuatNhanVien(dsnv.ds[i]);
      return true;
    }
  }
  return false;
}

int timLuongCaoNhatCuaCongTy(DANHSACHNHANVIEN dsnv, float luongCB) {
  float max = 0;
  for (int i = 0; i <= dsnv.soLuong; i++) {
    if (dsnv.ds[i].heSoLuong > max)
      max = dsnv.ds[i].heSoLuong;
  }
  float result = 0;
  result += max * luongCB;
  return result;
}

void timNhanVienLuongCaoNhatDauTien(DANHSACHNHANVIEN dsnv) {
  float max = 0;
  int dem = 0;
  for (int i = 0; i <= dsnv.soLuong; i++) {
    if (dsnv.ds[i].heSoLuong > max) {
      max = dsnv.ds[i].heSoLuong;
      dem++;
    }
  }
  xuatNhanVien(dsnv.ds[dem - 1]);
}

void timNhanVienLuongCaoNhat(DANHSACHNHANVIEN dsnv) {
  float max = 0;
  for (int i = 0; i <= dsnv.soLuong; i++) {
    if (dsnv.ds[i].heSoLuong > max) {
      max = dsnv.ds[i].heSoLuong;
    }
  }
  for (int i = 0; i <= dsnv.soLuong; i++) {
    if (dsnv.ds[i].heSoLuong == max)
      xuatNhanVien(dsnv.ds[i]);
  }
}

int main() {
  NHANVIEN nv;
  DANHSACHNHANVIEN ds;

  // nhapDanhSachNhanVien(ds);
  // if (ghiDanhSachNhanVien(ds, "danhsachnhanvien.dat"))
  //   cout << "\nGhi file thanh cong" << endl;
  // else
  //   cout << "\nGhi file khong duoc";
  // xuatDanhSachNhanVien(ds);

  if (docDanhSachNhanVien(ds, "danhsachnhanvien.dat")) {
    cout << "\nDoc file thanh cong";
    cout << "\nDanh sach nhan vien vua doc duoc la: " << endl;
    xuatDanhSachNhanVien(ds);
    int luongCB;
    cout << "\nNhap muc luong co ban: ";
    cin >> luongCB;
    cout << "Tong Luong cua cong ty la: " << tinhTongLuongCuaCongTy(ds, luongCB);
    int x;
    cout << "\nNhap ma nhan vien can tim: ";
    cin >> x;
    if (!timNhanVienTheoMa(ds, x))
      cout << "Khong tim thay";
    cout << "\nLuong cao nhat cua cong ty la: " << timLuongCaoNhatCuaCongTy(ds, luongCB);
    cout << "\nNhan vien co luong cao nhat dau tien: " << endl;
    timNhanVienLuongCaoNhatDauTien(ds);
    cout << "\nDanh sach nhan vien co luong cao nhat: " << endl;
    timNhanVienLuongCaoNhat(ds);
  }
  else
    cout << "\nDoc file khong duoc";

  cout << endl;
  system("pause");
  return 0;
}