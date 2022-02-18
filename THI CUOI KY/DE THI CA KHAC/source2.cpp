#include <iostream>
#include <string.h>
using namespace std;
#define MAX 50

struct Ngay {
  int ngay, thang, nam;
};
typedef struct Ngay NGAY;

struct ThuCung {
  char maThu[10];
  char loaiThu[50];
  NGAY ngaySinh;
  int gia;
};
typedef struct ThuCung THUCUNG;

struct DanhSach {
  int soLuong;
  THUCUNG data[MAX];
};
typedef struct DanhSach DANHSACH;

void nhap_ThuCung(THUCUNG &a);
void xuat_ThuCung(THUCUNG a);
void nhap_DSTC(DANHSACH &dstc);
void xuat_DSTC(DANHSACH dstc);
int timGiaMax(DANHSACH dstc);
void xuat_DSTC_GiaMax(DANHSACH dstc);
void sapXep_TheoNgaySinh(DANHSACH &dstc);

int main() {
  DANHSACH dstc;
  nhap_DSTC(dstc);
  cout << "\nDanh sach thu cung da nhap" << endl;
  xuat_DSTC(dstc);
  cout << "\nDanh sach thu cung gia cao" << endl;
  xuat_DSTC_GiaMax(dstc);
  cout << "\nSap xep danh sach thu cung giam dan theo ngay sinh" << endl;
  sapXep_TheoNgaySinh(dstc);
  xuat_DSTC(dstc);

  system("pause");
  return 0;
}

void nhap_ThuCung(THUCUNG &a) {
  cin.ignore();
  cout << "\nNhap ma thu cung: ";
  cin.getline(a.maThu, 10);
  cout << "Nhap loai thu cung: ";
  cin.getline(a.loaiThu, 50);
  cout << "Nhap ngay sinh: ";
  cin >> a.ngaySinh.ngay;
  cout << "Nhap thang sinh: ";
  cin >> a.ngaySinh.thang;
  cout << "Nhap nam sinh: ";
  cin >> a.ngaySinh.nam;
  cout << "Nhap gia: ";
  cin >> a.gia;
  cout << endl;
}

void xuat_ThuCung(THUCUNG a) {
  cout << "Ma thu: " << a.maThu << endl;
  cout << "Loai thu: " << a.loaiThu << endl;
  cout << "Ngay sinh: " << a.ngaySinh.ngay << "-" << a.ngaySinh.thang << "-" << a.ngaySinh.nam << endl;
  cout << "Gia: " << a.gia << endl;
  cout << endl;
}

void nhap_DSTC(DANHSACH &dstc) {
  cout << "\nNhap so luong: ";
  cin >> dstc.soLuong;
  for (int i = 0; i < dstc.soLuong; ++i)
    nhap_ThuCung(dstc.data[i]);
}

void xuat_DSTC(DANHSACH dstc) {
  for (int i = 0; i < dstc.soLuong; ++i)
    xuat_ThuCung(dstc.data[i]);
}

int tim_GiaMax(DANHSACH dstc) {
  int max = 0;
  for (int i = 0; i < dstc.soLuong; ++i)
    if (dstc.data[i].gia > max)
      max = dstc.data[i].gia;
  return max;
}

void xuat_DSTC_GiaMax(DANHSACH dstc) {
  int max = tim_GiaMax(dstc);
  for (int i = 0; i < dstc.soLuong; ++i)
    if (dstc.data[i].gia == max)
      xuat_ThuCung(dstc.data[i]);
}

void sapXep_TheoNgaySinh(DANHSACH &dstc) {
  for (int i = 0; i < dstc.soLuong; ++i)
    for (int j = i + 1; j < dstc.soLuong; ++j) {
      if (dstc.data[i].ngaySinh.nam < dstc.data[j].ngaySinh.nam)
        swap(dstc.data[i], dstc.data[j]);
      if (dstc.data[i].ngaySinh.nam == dstc.data[j].ngaySinh.nam) {
        if (dstc.data[i].ngaySinh.thang < dstc.data[j].ngaySinh.thang)
          swap(dstc.data[i], dstc.data[j]);
        if (dstc.data[i].ngaySinh.thang == dstc.data[j].ngaySinh.thang)
          if (dstc.data[i].ngaySinh.ngay < dstc.data[j].ngaySinh.ngay)
            swap(dstc.data[i], dstc.data[j]);
      }
    }
}