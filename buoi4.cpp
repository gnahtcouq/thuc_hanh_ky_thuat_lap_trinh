#include <iostream>
using namespace std;

const int MAX = 50;
struct MATRAN{
    int list[MAX][MAX];
    int n;
    int m;
};

void docMaTran(MATRAN &a);
void xuatMaTran(MATRAN &a);
int tinhTong(MATRAN a);
int demAm(MATRAN a);
void xuatTong(MATRAN a);
int timMax(MATRAN a);
void timDongChuaPhanTuMax(MATRAN a);

int main(){
    MATRAN a;
    docMaTran(a);
    xuatMaTran(a);

    int tong = tinhTong(a);
    cout << "\nCau1. Tong cac phan tu la: " << tong;

    int dem = demAm(a);
    cout << "\nCau2. So phan tu am la: " << dem;

    xuatTong(a);

    timDongChuaPhanTuMax(a);

    cout << endl;
    system("pause");
    return 0;
}

void docMaTran(MATRAN &a){
    FILE *fp;
    fp = fopen("text.txt", "r");
    if (fp != NULL){
        fscanf(fp, "%d", &a.n);
        fscanf(fp, "%d", &a.m);
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < a.m; j++)
                fscanf(fp, "%d", &a.list[i][j]);
        fclose(fp);
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
// Cau 1
int tinhTong(MATRAN a){
    int s = 0;
    for (int i = 0; i < a.n; i++)
        for (int j = 0; j < a.m; j++)
            s += a.list[i][j];
    return s;
}
// Cau 2
int demAm(MATRAN a){
    int dem = 0;
    for (int i = 0; i < a.n; i++)
        for (int j = 0; j < a.m; j++)
            if (a.list[i][j] < 0)
                dem++;
    return dem;
}
// Cau 3
void xuatTong(MATRAN a){
    for (int i = 0; i < a.n; i++){
        int tong = 0;
        for (int j = 0; j < a.n; j++){
            tong += a.list[i][j];
        }
        cout << "\nCau3. Dong " << i + 1 << " tong = " << tong;
    }
}
// Cau 4
int timMax(MATRAN a){
    int max = a.list[0][0];
    for (int i = 0; i < a.n; i++){
        for (int j = 0; j < a.m; j++){
            if(a.list[i][j] > max)
                max = a.list[i][j];
        }
    }
    return max;
}
void timDongChuaPhanTuMax(MATRAN a){
    int max = timMax(a);
    cout << "\nCau4. Dong chua phan tu lon nhat la: ";
    for (int i = 0; i < a.n; i++){
        for (int j = 0; j < a.m; j++){
            if(a.list[i][j] == max){
                cout << i+1 << " ";
                break;
            }
        }
    }
}