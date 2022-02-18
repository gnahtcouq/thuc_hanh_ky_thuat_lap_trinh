#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 100;

void nhapChuoi(char* s);
char* daoChuoi(char* s);
char* chenChuoi(char* s, char* sub, int pos);
void hoanVi(char& x, char& y);

int main() {
  char s[MAX];
  char* t;
  cout << "\nNhap chuoi: ";
  nhapChuoi(s);
  cout << "\nChuoi vua nhap: " << s << " ";
  t = daoChuoi(s);
  cout << "\n\nChuoi dao nguoc: " << t << " ";
  char s1[MAX], sub[MAX];
  int pos;
  cout << "\nNhap chuoi chinh: ";
  nhapChuoi(s1);
  cout << "\nNhap chuoi can chen: ";
  nhapChuoi(sub);
  cout << "\nNhap vi tri can chen: ";
  cin >> pos;
  t = chenChuoi(s1, sub, pos);
  cout << "\nChuoi da chen: " << t;

  cout << endl;
  return 0;
}

void nhapChuoi(char* s) {
  cin.getline(s, MAX + 1);
}

void hoanVi(char& x, char& y) {
  char temp = x;
  x = y;
  y = temp;
}

char* daoChuoi(char* s) {
  char* t = new char[MAX + 1];
  strcpy(t, s); // Sao chep noi dung tu bien s sang bien t
  int i = 0;
  int j = strlen(t) - 1; // Tinh do dai chuoi
  while (i < j) {
    hoanVi(t[i], t[j]);
    i++;
    j--;
  }
  return t;
}

char* chenChuoi(char* s, char* sub, int pos) {
  char* t;
  if (pos < 0)
    pos = 0;
  if (pos > strlen(s))
    pos = strlen(s);
  t = new char[strlen(s + pos) + 1];
  strcpy(t, s + pos);
  s[pos] = '\0';
  strcat(s, sub);
  strcat(s, t);
  return s;
}
