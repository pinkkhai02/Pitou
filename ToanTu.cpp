#include<stdio.h>

void Nhap(int &a, int &b);
void Nhaptoantu(char k);
void xuatTong(int a, int b);
int tinhTong( int a, int b);
void xuatHieu(int a, int b);
int tinhHieu( int a, int b);
void xuatTich(int a, int b);
int tinhTich (int a, int b);

int main(){
    int a,b;
    char k;
    Nhap(a,b);
    printf("Nhap toan tu:");
    scanf("%c",&k);
   // Nhaptoantu(k);
    switch (k)
    {
    case '+':{
        printf("%d + %d = %d",a,b,tinhTong(a,b));
        break;
    }
    case '-':{
        printf("%d - %d = %d",a,b,tinhHieu(a,b));
        break;
    }
    case '*':{
        printf("%d * %d = %d",a,b,tinhTich(a,b));
        break;
    }        
        
    
    
    }

    
    }
/*void Nhaptoantu(char k){
    printf("Moi nhap toan tu:");
    scanf("%c",&k);
}*/

void Nhap(int &a, int &b){
    printf("Nhap so a va b :");
    scanf("%d%d",&a,&b );
}

void xuatTong(int a, int b){
    int tong = tinhTong(a,b);
    printf("Tong:%d",tong);
}

int tinhTong(int a, int b){
    return a+b;
}

void xuatHieu(int a, int b){
    int hieu = tinhHieu(a,b);
    printf("Hieu:%d",tinhHieu);
}

int tinhHieu(int a, int b){
    return a-b;
}

void xuatTich(int a, int b){
    int tich = tinhTich(a,b);
    printf("Tich:%d",tinhTich);
}

int tinhTich(int a, int b){
    return a*b;
}
