#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
#define MAX 100

struct TrangPhuc {
  char maSP[5];
  char tenSP[30];
  char boSuuTap[15];
  int donGia;
};

struct DanhSach {
  int soLuong;
  TrangPhuc data[MAX];
};

void nhap_MotTrangPhuc(TrangPhuc &tp);
void xuat_MotTrangPhuc(TrangPhuc tp);
void nhap_DSTP(DanhSach &ds);
void xuat_DSTP(DanhSach ds);
void themTrangPhuc(DanhSach &ds);
bool timKiemThongTinTrangPhuc(DanhSach ds, char *str);
void xoaTrangPhucTaiViTri(DanhSach &ds, int vitri);
bool xoaTenTrangPhuc(DanhSach &ds, char *str);
void demSoLuongTrangPhucTheoBoSuuTap(DanhSach ds);
void sapXepTrangPhucTheoDonGia(DanhSach &ds);
void hienThiMenu();

int main() {
  hienThiMenu();
  system("pause");
  return 0;
}

void nhap_MotTrangPhuc(TrangPhuc &tp) {
  fflush(stdin);
  cout << "\nNhap ma trang phuc: ";
  cin.getline(tp.maSP, 5);
  cout << "Nhap ten trang phuc: ";
  cin.getline(tp.tenSP, 30);
  cout << "Nhap ten bo suu tap: ";
  cin.getline(tp.boSuuTap, 15);
  cout << "Nhap don gia: ";
  cin >> tp.donGia;
  cout << endl;
}

void xuat_MotTrangPhuc(TrangPhuc tp) {
  cout << setw(5) << left << tp.maSP << "\t";
  cout << setw(30) << left << tp.tenSP << "\t";
  cout << setw(15) << left << tp.boSuuTap << "\t";
  cout << setw(15) << left << tp.donGia << "\t" << endl;
}

void nhap_DSTP(DanhSach &ds) {
  cout << "\nNhap so luong trang phuc: ";
  cin >> ds.soLuong;
  cout << "\t\tNHAP THONG TIN TUNG TRANG PHUC";
  for (int i = 0; i < ds.soLuong; i++) {
    cout << "\n\tTrang Phuc " << i + 1;
    nhap_MotTrangPhuc(ds.data[i]);
  }
}

void xuat_DSTP(DanhSach ds) {
  cout << "\n\n\tTHONG TIN CAC TRANG PHUC" << endl;
  cout << setw(5) << left << "Ma TP" << "\t";
  cout << setw(30) << left << "Ten TP" << "\t";
  cout << setw(15) << left << "Bo Suu Tap" << "\t";
  cout << setw(15) << left << "Don Gia" << "\t" << endl;
  for (int i = 0; i < ds.soLuong; i++)
    xuat_MotTrangPhuc(ds.data[i]);
}

void themTrangPhuc(DanhSach &ds) {
  int vitrithem = 0;
  TrangPhuc tp;
  nhap_MotTrangPhuc(tp);
  for (int i = ds.soLuong - 1; i >= vitrithem; i--)
    ds.data[i + 1] = ds.data[i];
  ds.data[vitrithem] = tp;
  ds.soLuong++;
  cout << "\nDanh sach trang phuc sau khi them la: ";
  xuat_DSTP(ds);
}


bool timKiemThongTinTrangPhuc(DanhSach ds, char *str) {
  cout << setw(5) << left << "Ma TP" << "\t";
  cout << setw(30) << left << "Ten TP" << "\t";
  cout << setw(15) << left << "Bo Suu Tap" << "\t";
  cout << setw(15) << left << "Don Gia" << "\t" << endl;
  for (int i = 0; i < ds.soLuong; i++)
    if (strcmp(ds.data[i].maSP, str) == 0) {
      xuat_MotTrangPhuc(ds.data[i]);
      return true;
    }
  return false;
}

void xoaTrangPhucTaiViTri(DanhSach &ds, int vitri) {
  if (vitri < 0 || vitri > ds.soLuong)
    cout << "\nVi tri khong hop le";
  else {
    for (int i = vitri + 1; i <= ds.soLuong; i++)
      ds.data[i - 1] = ds.data[i];
    ds.soLuong--;
  }
}

bool xoaTenTrangPhuc(DanhSach &ds, char *str) {
  for (int i = 0; i < ds.soLuong; i++)
    if (strcmp(ds.data[i].tenSP, str) == 0) {
      xoaTrangPhucTaiViTri(ds, i);
      return true;
    }
  return false;
}

void demSoLuongTrangPhucTheoBoSuuTap(DanhSach ds) {
  char a[100][100];
  strcpy(a[0], ds.data[0].boSuuTap);
  int x = 1;
  for (int i = 1; i < ds.soLuong; i++) {
    int dem = 0;
    for (int j = 0; j < x; j++)
      if (strcmp(ds.data[i].boSuuTap, a[j]) == 0)
        dem++;
    if (dem == 0) {
      strcpy(a[x], ds.data[i].boSuuTap);
      x++;
    }
  }
  for (int j = 0; j < x; j++) {
    int dem = 0;
    for (int i = 0; i < ds.soLuong; i++)
      if (strcmp(ds.data[i].boSuuTap, a[j]) == 0)
        dem++;
    cout << "\n\tBo suu tap " << a[j] << " co " << dem << " trang phuc";
  }
}

void sapXepTrangPhucTheoDonGia(DanhSach &ds) {
  for (int i = 0; i < ds.soLuong; i++)
    for (int j = i + 1; j < ds.soLuong; j++)
      if (ds.data[i].donGia > ds.data[j].donGia) {
        TrangPhuc tam = ds.data[i];
        ds.data[i] = ds.data[j];
        ds.data[j] = tam;
      }
  xuat_DSTP(ds);
}

void hienThiMenu() {
  TrangPhuc tp;
  DanhSach ds;
  int chon = 0;
  do {
    cout << "\n\n0 - Thoat chuong trinh";
    cout << "\n1 - Nhap danh sach trang phuc";
    cout << "\n2 - Xuat danh sach trang phuc";
    cout << "\n3 - Them trang phuc";
    cout << "\n4 - Tim thong tin trang phuc";
    cout << "\n5 - Xoa trang phuc";
    cout << "\n6 - Dem so luong trang phuc trong bo suu tap";
    cout << "\n7 - Sap xep danh sach tang dan theo don gia";
    cout << "\nVui long chon: ";
    cin >> chon;
    switch (chon) {
    case 0:
      break;
    case 1:
      nhap_DSTP(ds);
      break;
    case 2:
      xuat_DSTP(ds);
      break;
    case 3:
      cout << "\n3. Nhap thong tin trang phuc can them";
      themTrangPhuc(ds);
      break;
    case 4:
      char str[5];
      cout << "\n4. Nhap ma trang phuc can xuat thong tin: ";
      cin.ignore();
      cin.getline(str, 5);
      if (!timKiemThongTinTrangPhuc(ds, str))
        cout << "\nKhong tim thay, hay thu lai" << endl;
      break;
    case 5:
      char str2[30];
      cout << "\n5. Nhap ten trang phuc can xoa: ";
      cin.ignore();
      cin.getline(str2, 30);
      if (xoaTenTrangPhuc(ds, str2)) {
        cout << "Danh sach trang phuc sau khi xoa la: ";
        xuat_DSTP(ds);
      }
      else
        cout << "Khong tim thay, hay thu lai" << endl;
      break;
    case 6:
      cout << "\n6. So luong trang phuc theo bo suu tap la: ";
      demSoLuongTrangPhucTheoBoSuuTap(ds);
      break;
    case 7:
      cout << "\n7. Sap xep trang phuc tang dan theo don gia";
      cout << "\nDanh sach sau khi sap xep";
      sapXepTrangPhucTheoDonGia(ds);
      break;
    default:
      cout << "\nBan chon sai, vui long chon lai!";
      break;
    }
  } while (chon != 0);
}