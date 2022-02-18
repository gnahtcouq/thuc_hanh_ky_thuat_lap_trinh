#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int MAX = 50;
struct maTran {
  int list[MAX][MAX];
  int n;
};
void docMaTran(maTran& a);
void xuatMaTran(maTran a);
int tinhTongAm(maTran a);
void timMaxTungCot(maTran a);
bool kiemTraDonVi(maTran a);
int demLeDuongCheoPhu(maTran a);
void xuatTamGiacDuoi(maTran a);
bool kiemTraTamGiacDuoiPhaiDuong(maTran a);
void nhan_MaTranVuong(maTran& a, int& x);

int main() {
  maTran a;
  maTran b;
  maTran c;
  docMaTran(a);
  docMaTran(b);
  cout << "\nCau 1. Ma tran vuong da nhap: " << endl;
  xuatMaTran(a);

  int tong = tinhTongAm(a);
  cout << "\nCau 2. Tong cac phan tu am co trong ma tran la: " << tong;

  timMaxTungCot(a);

  if (kiemTraDonVi(a) == true)
    cout << "\nCau 4. Ma tran nay la ma tran don vi";
  else
    cout << "\nCau 4. Khong phai ma tran don vi";

  int dem = demLeDuongCheoPhu(a);
  cout << "\nCau 5. So gia tri le tren duong cheo phu la: " << dem;

  xuatTamGiacDuoi(a);

  if (kiemTraTamGiacDuoiPhaiDuong(a) == true)
    cout << "\nCau 7. Tam giac duoi ben phai tat ca la so duong";
  else
    cout << "\nCau 7. Tam giac duoi ben phai co so am";

  int x;
  cout << "\nCau 8. Nhan ma tran vuong voi x";
  nhan_MaTranVuong(a, x);
  xuatMaTran(a);

  cout << endl;
  system("pause");
  return 0;
}

void docMaTran(maTran& a) {
  FILE* f;
  f = fopen("a.txt", "r");
  if (f == NULL) {
    cout << "Loi mo file";
    exit(1);
  }
  fscanf(f, "%d", &a.n);
  for (int i = 0; i < a.n; i++)
    for (int j = 0; j < a.n; j++)
      fscanf(f, "%d", &a.list[i][j]);
  fclose(f);
}
void xuatMaTran(maTran a) {
  for (int i = 0; i < a.n; i++) {
    for (int j = 0; j < a.n; j++)
      cout << a.list[i][j] << "\t";
    cout << endl;
  }
}

// Cau 2
int tinhTongAm(maTran a) {
  int s = 0;
  for (int i = 0; i < a.n; i++)
    for (int j = 0; j < a.n; j++)
      if (a.list[i][j] < 0)
        s += a.list[i][j];
  return s;
}

// Cau 3
void timMaxTungCot(maTran a) {
  int max;
  max = a.list[0][0];
  int j = 0;
  while (j < a.n) {
    max = a.list[0][j];
    for (int i = 0; i < a.n; i++) {
      if (a.list[i][j] > max) {
        max = a.list[i][j];
      }
    }
    cout << "\nCau 3. Max cot " << j + 1 << " la " << max;
    j++;
  }
}

// Cau 4
bool kiemTraDonVi(maTran a) {
  for (int i = 0; i < a.n; i++) {
    for (int j = 0; j < a.n; j++) {
      if (i == j) {
        if (a.list[i][j] != 1)
          return false;
      }
      else if (a.list[i][j] != 0)
        return false;
    }
  }
  return true;
}

// Cau 5
int demLeDuongCheoPhu(maTran a) {
  int dem = 0;
  for (int i = 0; i < a.n; i++)
    for (int j = 0; j < a.n; j++) {
      if (i + j == a.n - 1) {
        if (a.list[i][j] % 2 != 0) {
          dem++;
        }
      }
    }
  return dem;
}

// Cau 6
void xuatTamGiacDuoi(maTran a) {
  cout << "\nCau 6. In tam giac duoi phai: " << endl;
  for (int i = 0; i < a.n; i++) {
    for (int j = 0; j < a.n; j++)
      if (j >= a.n - i - 1)
        cout << a.list[i][j] << "\t";
      else
        cout << "\t";
    cout << endl;
  }
}

// Cau 7
bool kiemTraTamGiacDuoiPhaiDuong(maTran a) {
  for (int i = 1; i < a.n; i++) {
    for (int j = a.n - i; j < a.n; j++) {
      if (a.list[i][j] < 0)
        return false;
    }
  }
  return true;
}

// Cau 8
void nhan_MaTranVuong(maTran& a, int& x) {
  cout << "\nNhap x = ";
  cin >> x;
  for (int i = 0; i < a.n; i++)
    for (int j = 0; j < a.n; j++)
      a.list[i][j] *= x;
}