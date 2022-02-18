// #pragma warning(disable: 4996)
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
#define MAX 100

// Cau 1
void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
int demSoLuongPhanTuKeNhauMaCa2DeuChan(int a[], int n);

// Cau 2
void nhapMaTran(float arr[][MAX], int dong, int cot);
void xuatMaTran(float arr[][MAX], int dong, int cot);
void lietKeCacDongToanAm(float arr[][MAX], int dong, int cot);

// Cau 3
void xoaMotKyTu(char* s, int vitrixoa);
void chuanHoaChuoi(char* s);

// Cau 4
struct Ngay {
  int ngay;
  int thang;
  int nam;
};

struct ThuCung {
  char maThu[10];
  char loaiThu[50];
  Ngay ngaySinh;
  int gia;
};

struct DanhSach {
  ThuCung data[MAX];
  int soLuong;
};

void nhapMotThuCung(ThuCung& tc);
void xuatMotThuCung(ThuCung tc);
void xuatNgaySinh(Ngay date);
void nhapDanhSachThuCung(DanhSach& ds);
void xuatDanhSachThuCung(DanhSach ds);
void xuatDanhSachThuCungGiaCao(DanhSach ds);
void demSoLuongThuCungTheoLoaiThu(DanhSach ds);
void sapXepTheoNgaySinh(DanhSach& ds);

void hienThiMenu();

int main() {
  hienThiMenu();
  system("pause");
  return 0;
}

// Cau 1
void nhapMang(int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << "a[" << i << "]= ";
    cin >> a[i];
  }
}
void xuatMang(int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}

int demSoLuongPhanTuKeNhauMaCa2DeuChan(int a[], int n) {
  if (n == 1) // Xac dinh diem dung
    return 0;
  if (a[n - 1] % 2 == 0) // Neu phan tu o truoc va o sau deu chia het cho 2 thi goi lai de quy de tang so lan dem len 1
    if (a[n - 2] % 2 == 0)
      return 1 + demSoLuongPhanTuKeNhauMaCa2DeuChan(a, n - 1);
  return demSoLuongPhanTuKeNhauMaCa2DeuChan(a, n - 1);
}

// Cau 2
void nhapMaTran(float arr[][MAX], int dong, int cot) {
  for (int i = 0; i < dong; i++) {
    for (int j = 0; j < cot; j++) {
      cout << "arr[" << i << "][" << j << "] = ";
      cin >> arr[i][j];
    }
  }
}

void xuatMaTran(float arr[][MAX], int dong, int cot) {
  for (int i = 0; i < dong; i++) {
    for (int j = 0; j < cot; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void lietKeCacDongToanAm(float arr[][MAX], int dong, int cot) {
  int flag;
  for (int i = 0; i < dong; i++) {
    flag = 1;
    for (int j = 0; j < cot; j++) { // Xet qua cac cot trong dong, neu > 0 thi cho flag == 0 va break
      if (arr[i][j] > 0) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) // Neu flag van == 1 thi xuat ra dong do
      cout << "\nDong " << i + 1 << " toan am";
  }
}

// Cau 3
// Luc dau viet ham xoa mot ky tu trong chuoi
void xoaMotKyTu(char* s, int vitrixoa) {
  int length = strlen(s);
  for (int i = vitrixoa + 1; i < length; i++) {
    s[i - 1] = s[i];
  }
  s[length - 1] = '\0';
}

void chuanHoaChuoi(char* s) {
  int length = strlen(s);
  // Chay tu dau den cuoi gap 2 khoang trang lien tiep thi xoa di 1
  for (int i = 0; i < length; i++) {
    if (s[i] == ' ' && s[i + 1] == ' ') {
      xoaMotKyTu(s, i);
      i--; // Xoa xong thi i-- xuong
      length--; // Phai giam length lai
    }
  }
  if (s[0] == ' ') {
    xoaMotKyTu(s, 0);
    length--;
  }
  if (s[length - 1] == ' ') {
    xoaMotKyTu(s, length - 1);
    length--;
  }
}

// Cau 4
void nhapMotThuCung(ThuCung& tc) {
  fflush(stdin);
  cout << "\nNhap Ma thu: ";
  cin.getline(tc.maThu, 10);
  cout << "Nhap Loai thu: ";
  cin.getline(tc.loaiThu, 50);
  cout << "Nhap ngay sinh: ";
  cout << "\n\t+ Ngay: ";
  cin >> tc.ngaySinh.ngay;

  do {
    cout << "\t+ Thang: ";
    cin >> tc.ngaySinh.thang;
    if (tc.ngaySinh.thang <= 0 || tc.ngaySinh.thang > 12)
      cout << "\nNhap sai. Hay nhap lai" << endl;
  } while (tc.ngaySinh.thang <= 0 || tc.ngaySinh.thang > 12);

  cout << "\t+ Nam: ";
  cin >> tc.ngaySinh.nam;
  cout << "Nhap gia: ";
  cin >> tc.gia;
  cout << endl;
}

void xuatMotThuCung(ThuCung tc) {
  cout << "\nMa Thu: " << tc.maThu;
  cout << "\nLoai Thu: " << tc.loaiThu;
  cout << "\nNgay Sinh: " << tc.ngaySinh.ngay << "/" << tc.ngaySinh.thang << "/" << tc.ngaySinh.nam;
  cout << "\nGia: " << tc.gia;
  cout << "\n---" << endl;
}

// Cau 4a
void nhapDanhSachThuCung(DanhSach& ds) {
  cout << "\n\nNhap so luong Thu Cung: ";
  cin >> ds.soLuong;
  cout << "\t\tNHAP THONG TIN TUNG THU CUNG";
  for (int i = 0; i < ds.soLuong; i++) {
    cout << "\n\tThu Cung " << i + 1;
    nhapMotThuCung(ds.data[i]);
  }
}

// Cau 4b
void xuatDanhSachThuCung(DanhSach ds) {
  cout << "\nDANH SACH CAC THU CUNG" << endl;
  for (int i = 0; i < ds.soLuong; i++) {
    xuatMotThuCung(ds.data[i]);
  }
}

// Cau 4c
void xuatDanhSachThuCungGiaCao(DanhSach ds) {
  // Tim gia cao nhat
  int max = 0;
  for (int i = 0; i < ds.soLuong; i++) {
    if (ds.data[i].gia > max)
      max = ds.data[i].gia;
  }
  // Duyet lai tat ca danh sach, gia nao = gia cao nhat thi xuat thong tin ra
  for (int i = 0; i < ds.soLuong; i++) {
    if (ds.data[i].gia == max)
      xuatMotThuCung(ds.data[i]);
  }
}

// Cau 4d
void demSoLuongThuCungTheoLoaiThu(DanhSach ds) {
  char a[100][100];
  int x = 1;
  strcpy(a[0], ds.data[0].loaiThu);
  for (int i = 0; i < ds.soLuong; i++)
    for (int j = 0; j < x; j++)
      if (strcmp(ds.data[i].loaiThu, a[j]) != 0) {
        strcpy(a[x], ds.data[i].loaiThu);
        x++;
      }
  for (int j = 0; j < x; j++) {
    int dem = 0;
    for (int i = 0; i < ds.soLuong; i++)
      if (strcmp(ds.data[i].loaiThu, a[j]) == 0)
        dem++;
    cout << "Loai thu " << a[j] << " co " << dem << " con" << endl;
  }
}

// Cau 4e
void sapXepTheoNgaySinh(DanhSach& ds) {
  for (int i = 0; i < ds.soLuong; i++) {
    for (int j = i + 1; j < ds.soLuong; j++) {
      if (ds.data[i].ngaySinh.nam < ds.data[j].ngaySinh.nam) {
        ThuCung tam = ds.data[i];
        ds.data[i] = ds.data[j];
        ds.data[j] = tam;
      }
      if (ds.data[i].ngaySinh.nam == ds.data[j].ngaySinh.nam) {
        if (ds.data[i].ngaySinh.thang < ds.data[j].ngaySinh.thang) {
          ThuCung tam = ds.data[i];
          ds.data[i] = ds.data[j];
          ds.data[j] = tam;
        }
        if (ds.data[i].ngaySinh.thang == ds.data[j].ngaySinh.thang) {
          if (ds.data[i].ngaySinh.ngay < ds.data[j].ngaySinh.ngay) {
            ThuCung tam = ds.data[i];
            ds.data[i] = ds.data[j];
            ds.data[j] = tam;
          }
        }
      }
    }
  }
}

void hienThiMenu() {
  DanhSach ds;
  int dem;
  int chon = 0;
  do {
    cout << "\n0 - Thoat chuong trinh";
    cout << "\n1 - Xac dinh so luong cac phan tu ke nhau ma ca hai deu chan";
    cout << "\n2 - Liet ke cac dong toan am trong ma tran cac so thuc";
    cout << "\n3 - Chuan hoa chuoi";
    cout << "\n4 - a. Nhap danh sach cac thu cung";
    cout << "\n5 - b. Xuat danh sach cac thu cung";
    cout << "\n6 - c. Liet ke danh sach cac thu cung co gia cao nhat";
    cout << "\n7 - d. Thong ke so luong thu cung theo loai thu";
    cout << "\n8 - e. Sap xep cac phan tu trong mang giam dan theo ngay sinh";
    cout << "\nVui long chon: ";
    cin >> chon;
    switch (chon) {
    case 0:
      break;
    case 1:
      int a[MAX];
      int n;
      do {
        cout << "\nNhap so luong phan tu cua mang: ";
        cin >> n;
        if (n<0 || n>MAX)
          cout << "\nBan nhap khong dung. Xin hay nhap lai";
      } while (n<0 || n>MAX);
      nhapMang(a, n);
      xuatMang(a, n);
      // Cau 1
      dem = demSoLuongPhanTuKeNhauMaCa2DeuChan(a, n);
      cout << "\nSo luong cac phan tu ke nhau ma ca 2 deu chan = " << dem << endl;
      break;
    case 2:
      // Cau 2
      float arr[MAX][MAX];
      int dong, cot;
      cout << "\nNhap so dong: ";
      cin >> dong;
      cout << "Nhap so cot: ";
      cin >> cot;
      nhapMaTran(arr, dong, cot);
      xuatMaTran(arr, dong, cot);
      lietKeCacDongToanAm(arr, dong, cot);
      break;
    case 3:
      // Cau 3
      char str[100];
      cin.ignore();
      cout << "\nNhap chuoi can chuan hoa: ";
      cin.getline(str, 100);
      cout << "\nChuoi ban dau = " << str;
      chuanHoaChuoi(str);
      cout << "\nChuoi sau khi chuan hoa: " << str << endl;
      break;
    case 4:
      // Cau 4a
      nhapDanhSachThuCung(ds);
      break;
    case 5:
      // Cau 4b
      xuatDanhSachThuCung(ds);
      break;
    case 6:
      // Cau 4c
      cout << "\nDanh sach thu cung gia cao nhat: ";
      xuatDanhSachThuCungGiaCao(ds);
      break;
    case 7:
      // Cau 4d
      demSoLuongThuCungTheoLoaiThu(ds);
      break;
    case 8:
      // Cau 4e
      cout << "\nSap xep danh sach giam dan theo ngay sinh: ";
      sapXepTheoNgaySinh(ds);
      break;
    default:
      cout << "\nBan chon sai, vui long chon lai!";
      break;
    }
  } while (chon != 0);
}