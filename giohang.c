#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum LuaChon{
    TAO_GIO_HANG=1,
    CHON_HANG=2,
    XEM_CHI_TIET_GIO_HANG=3,
    LOAI_BO_MOT_MAT_HANG=4,
    GHI_TOAN_BO_GIO_HANG_VAO_TEP_TIN_NHI_PHAN=5,
    THOAT=6
}; 
struct Sanpham{	
    char tensp[30]; 
	int gia;
 	int soluong;
};

struct {
 	char tenkhachhang[30];
 	char diachi[50];
 	int sosanpham;
 	Sanpham sp[30]; 
}Giohang;


void taoGiohang(){
	printf("Nhap ten khach hang: ");
	fflush(stdin);
	gets(Giohang.tenkhachhang);
	printf("Nhap dia chi khach hang: ");
	fflush(stdin);
	gets(Giohang.diachi);
	Giohang.sosanpham=0;	
}
int chonHang(){
	int GH;
	int i=0;
    while(GH!=0){ 
	printf("Ten san pham: ");
	fflush(stdin);
	gets(Giohang.sp[i].tensp);
	printf("Nhap gia: ");
	scanf("%d",&Giohang.sp[i].gia);
	printf("Nhap so luong: ");
	scanf("%d",&Giohang.sp[i].soluong);
	Giohang.sosanpham++;i++;
	printf("\n Khach Hang co muon tiep tuc chon hang khong?");
	printf("\n Nhap 1 neu 'Co' va Nhap 0 neu 'Khong': ");
	scanf("%d", &GH);
}
}
void xuatBill(){
 	int i,j;
	struct Sanpham Doi;
    printf("Ten khach hang: ");
	puts(Giohang.tenkhachhang);
	printf("Dia chi: ");
	puts(Giohang.diachi);
	printf("\n %-10s %-30s %-10s %-10s\n","STT","Ten San Pham","Gia","So Luong");
	for( i=0;i<Giohang.sosanpham-2;i++){
			for(j=i+1;j<Giohang.sosanpham-1;j++){
				if(strcmp(Giohang.sp[i].tensp,Giohang.sp[j].tensp)>0){
				Doi=Giohang.sp[i];
				Giohang.sp[i]=Giohang.sp[j];
				Giohang.sp[j]=Doi;
            }       
        }          
    }   
	for(i=0;i<Giohang.sosanpham;i++){
	printf("%-10d %-30s %-10d %-10d\n",i+1,Giohang.sp[i].tensp,Giohang.sp[i].gia,Giohang.sp[i].soluong);			
    }
}
void loaibomathang(){
	int n,i;
	do{
	printf("\nNhap vi tri san pham can loai bo: ");
	scanf("%d",&n);
	if(n<1 || n>Giohang.sosanpham) 
	printf("\nVi tri san phan khong hop le. Xin nhap lai vi tri! ");
	}while(n<1 || n>Giohang.sosanpham);
	for( i=n-1;i<Giohang.sosanpham;i++)
		Giohang.sp[i]=Giohang.sp[i+1];
	    Giohang.sosanpham=Giohang.sosanpham-1;
}
void ghiFile(){
	FILE *fp;
	int i;
	fp = fopen("D:\\test\\cart.dat","wb");
	fprintf(fp,"%-10s %-30s %-10s %-10s	\n","STT","Ten san pham","Gia","So luong");
	for( i=0;i<Giohang.sosanpham;i++){
		fprintf(fp,"%-10d %-30s %-10d %-10d	\n",i+1,Giohang.sp[i].tensp,Giohang.sp[i].gia,Giohang.sp[i].soluong);
	}
	fclose(fp);
}
void docFile(){
	FILE *fp;
	int i;
	fp=fopen("D:\\test\\cart.dat","r");
	fscanf(fp,"\n %-10s    %-10s    %-10s    %-10s \n","STT","Ten San Pham","Gia","So Luong");
	for(i=0;i<Giohang.sosanpham;i++){
	fscanf(fp,"%-10d    %-10s      %-10d     %-10d \n",i+1,&Giohang.sp[i].tensp,&Giohang.sp[i].gia,&Giohang.sp[i].soluong);			
    }
    fclose(fp);
}
void luuFile(){
	ghiFile();
	docFile();
}


void Menu(){
    int luaChon;
    do{
        printf("        -----------*    MENU    *------------            \n");
        printf("               1. Tao gio hang                               \n");
        printf("               2. Chon hang                                    \n");
        printf("               3. Xem chi tiet gio hang                        \n");
        printf("               4. Loai bo mot mat hang                         \n"); 
		printf("               5. Luu toan bo noi dung vao tep                  \n");
        printf("               6. Thoat chuong trinh                           \n");
      	printf("------------------------------------------------------------------\n");
        printf(" Lua chon cua ban 1->6:");
scanf("%d",&luaChon);
switch(luaChon){
	case TAO_GIO_HANG:{
        taoGiohang(); 
        break;
    }
	case CHON_HANG:{
        chonHang(); 
        break;
    }
	case XEM_CHI_TIET_GIO_HANG:{
        xuatBill();
        break;
    }
	case LOAI_BO_MOT_MAT_HANG:{
        loaibomathang(); 
        break;
    }
	case GHI_TOAN_BO_GIO_HANG_VAO_TEP_TIN_NHI_PHAN:{
        luuFile(); 
        break;
    }
	default: break;
}
}while(luaChon!=6);
}
int main(){
 	Menu();

return 0;
}
