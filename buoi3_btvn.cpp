#include <iostream>
using namespace std;
const int MAX = 50;
struct DAYSO {
    float list[MAX];
    int n;
    int vitrixoa;
};

void nhapDS(DAYSO& a);
void xuatDS(DAYSO a);
void xoaPhanTuBatKy(DAYSO& a);
void xoaPhanTuMax(DAYSO& a);
void xoaPhanTuTrung(DAYSO& a);
void daoNguocDaySo(DAYSO a);

int main() {
    DAYSO d;
    nhapDS(d);
    xuatDS(d);

    xoaPhanTuMax(d);
    cout << "\n2. Day so sau khi xoa tat ca phan tu lon nhat la: ";
    xuatDS(d);

    xoaPhanTuTrung(d);
    cout << "\n3. Day so sau khi xoa tat ca phan tu trung nhau la: ";
    xuatDS(d);

    cout << "\n4. Day so sau khi dao nguoc la: ";
    daoNguocDaySo(d);

    cout << endl;
    system("pause");
    return 0;
}

// Cau 1
void nhapDS(DAYSO& a) {
    cout << "\nNhap so phan tu: ";
    cin >> a.n;
    for (int i = 0; i < a.n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a.list[i];
    }
}
void xuatDS(DAYSO a) {
    for (int i = 0; i < a.n; i++)
        cout << a.list[i] << " ";
}

// Cau 2
void xoaPhanTuBatKy(DAYSO& a, int vitrixoa) {
    for (int i = vitrixoa + 1; i < a.n; i++) {
        a.list[i - 1] = a.list[i];
    }
    a.n--;
}
void xoaPhanTuMax(DAYSO& a) {
    float max = a.list[0];
    for (int i = 0; i < a.n; i++) {
        if (a.list[i] > max)
            max = a.list[i];
    }
    for (int i = 0; i < a.n; i++) {
        if (a.list[i] == max) {
            xoaPhanTuBatKy(a, i);
            i--;
        }
    }
}

// Cau 3
void xoaPhanTuTrung(DAYSO& a) {
    for (int i = 0; i < a.n - 1; i++) {
        int j = i + 1;
        while (j < a.n)
            if (a.list[i] == a.list[j]) {
                for (int k = j; k < a.n - 1; k++)
                    a.list[k] = a.list[k + 1];
                a.n = a.n - 1;
            }
            else
                j = j + 1;
    }
}

// Cau 4
void daoNguocDaySo(DAYSO a){
    for (int i=0 ;i<a.n/2;i++){
        float tam = a.list[i];
        a.list[i] = a.list[a.n-1-i];
        a.list[a.n-1-i] = tam;
    }
    for(int i=0;i<a.n;i++){
        cout << a.list[i] << " ";
    }
}