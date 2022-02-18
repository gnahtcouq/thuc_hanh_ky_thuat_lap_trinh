#include <iostream>
using namespace std;

const int MAX = 50; //khai báo tối đa số phần tử
struct MATRAN{
    int list[MAX][MAX];
    int n; //số dòng
    int m; //số cột
};
void nhapMaTran(MATRAN &a);
void xuatMaTran(MATRAN &a);
int tinhTongChan(MATRAN a);
int demLe(MATRAN a);
int timMin(MATRAN a);
int tinhTong(MATRAN a);
void xuatTong(MATRAN a);
void timDongTongMax(MATRAN a, int b[], int &u);

int main(){
    MATRAN a;
    int b[MAX], u;
    nhapMaTran(a);
    xuatMaTran(a);

    int tong = tinhTongChan(a);
    cout << "\nCau2.1 Tong cac phan tu chan: " << tong;

    int dem = demLe(a);
    cout << "\nCau2.2 So le co trong ma tran: " << dem;

    int min = timMin(a);
    cout << "\nCau3.1 Phan tu nho nhat co trong ma tran: " << min;

    cout << "\nCau3.2";
    xuatTong(a);

    cout << endl;
    timDongTongMax(a, b, u);

    cout << endl;
    system("pause");
    return 0;
}

void nhapMaTran(MATRAN &a){
    cout << "\n Nhap so dong: ";
    cin >> a.n;
    cout << "\n Nhap so cot: ";
    cin >> a.m;
    for (int i = 0; i < a.n; i++){
        for (int j = 0; j < a.m; j++){
            cout << "a[" << i << "]" << "[" << j << "]= ";
            cin >> a.list[i][j];
        }
    }
}
void xuatMaTran(MATRAN &a){
    cout << "Mang vua nhap: ";
    for (int i = 0; i < a.n; i++){
        cout << endl;
        for (int j = 0; j < a.m; j++)
            cout << a.list[i][j] << " ";
    }
}
// Cau 2.1
int tinhTongChan(MATRAN a){
    int s = 0;
    for (int i = 0; i < a.n; i++)
        for (int j = 0; j < a.m; j++){
            if(a.list[i][j]%2==0)
            s += a.list[i][j];
        }
    return s;
}
// Cau 2.2
int demLe(MATRAN a){
    int dem = 0;
    for (int i = 0; i < a.n; i++)
        for (int j = 0; j < a.m; j++)
            if (a.list[i][j] %2 != 0)
                dem++;
    return dem;
}
// Cau 3.1
int timMin(MATRAN a){
    int min = a.list[0][0];
    for (int i = 0; i < a.n; i++)
            if(a.list[i][i] < min)
                min = a.list[i][i];
    return min;
}
// Cau 3.2
void xuatTong(MATRAN a){
    for (int i = 0; i < a.n; i++){
        int tong = 0;
        for (int j = 0; j < a.n; j++){
            tong += a.list[i][j];
        }
        cout << "\n    Dong " << i + 1 << " tong = " << tong;
    }
}
// Cau 3.3
void timDongTongMax(MATRAN a, int b[], int &u){
    u = 0;
    for (int i = 0; i < a.n; i++){
        int tong = 0;
        for (int j = 0; j < a.n; j++){
            tong += a.list[i][j];
        b[u++] = tong;
        }
    }
    for(int i=0; i < a.n; i++){
        cout << b[u] << " ";
    }
}