#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct sp_st 
{	char tensp[30]; 
	int gia;
 	int soluong;
};
struct 
{ 	char tenkhachhang[30];
 	char diachi[50];
 	int sosanpham;
 	struct sp_st dssp[30]; 
}giohang_st;
void taogiohang()
{	printf("Nhap Ten Khach Hang: ");
	fflush(stdin);
	gets(giohang_st.tenkhachhang);
	printf("Nhap Dia Chi: ");
	fflush(stdin);
	gets(giohang_st.diachi);
	giohang_st.sosanpham=0;	
}
int chonhang()
{	int GH;
	int i=0;
while(GH!=0)	
{ 
	printf("Ten San Pham: ");
	fflush(stdin);
	gets(giohang_st.dssp[i].tensp);
	printf("Nhap Gia: ");
	scanf("%d",&giohang_st.dssp[i].gia);
	printf("Nhap So Luong: ");
	scanf("%d",&giohang_st.dssp[i].soluong);
	giohang_st.sosanpham++;
	i++;
	printf("\n Khach Hang co muon tiep tuc chon hang Khong: ");
	printf("\n Nhap 1 neu Co va Nhap 0 neu Khong : ");
	scanf("%d", &GH);
}
}
void xemchitiet()
{ 	int i,j;
	struct sp_st Doi;
	printf("\n %-10s    %-10s    %-10s    %-10s \n","STT","Ten San Pham","Gia","So Luong");
	for( i=0;i<giohang_st.sosanpham-2;i++)
	{
			for(j=i+1;j<giohang_st.sosanpham-1;j++)
		{
				if(strcmp(giohang_st.dssp[i].tensp,giohang_st.dssp[j].tensp)>0)
				{
				Doi=giohang_st.dssp[i];
				giohang_st.dssp[i]=giohang_st.dssp[j];
				giohang_st.dssp[j]=Doi;
}}}
	for(i=0;i<giohang_st.sosanpham;i++)
{
	printf("%-10d    %-10s      %-10d     %-10d \n",i+1,giohang_st.dssp[i].tensp,giohang_st.dssp[i].gia,giohang_st.dssp[i].soluong);			
}}
void loaibomathang(){
	int n,i;
	do
	{
	printf("\nNhap vi tri san pham can loai bo: ");
	scanf("%d",&n);
	if(n<1 || n>giohang_st.sosanpham) printf("\nVi tri san phan khong hop le. Xin nhap lai vi tri! ");
	}while(n<1 || n>giohang_st.sosanpham);
	for( i=n-1;i<giohang_st.sosanpham;i++)
		giohang_st.dssp[i]=giohang_st.dssp[i+1];
	giohang_st.sosanpham=giohang_st.sosanpham-1;
}
void luu(){
	FILE *fp;
	int i;
	fp = fopen("E://Users//KHANHLY//Desktop//vart","rb+");
	fprintf(fp,"%-10s   %-10s   %-10s   %-10s	\n","STT","Ten san pham","Gia","So luong");
	for( i=0;i<giohang_st.sosanpham;i++)
		fprintf(fp,"%-10d   %-10s   %-10d   %-10d	\n",i+1,giohang_st.dssp[i].tensp,giohang_st.dssp[i].gia,giohang_st.dssp[i].soluong);
	fclose(fp);
}
void Menu()
{  int a;
do{
        printf("\n\n********************************************************************\n");
        printf("**       CHUONG TRINH BAN HANG CO BAN                          **\n");
        printf("**        1. Tao gio hang                                         **\n");
        printf("**        2.  Chon hang                                           **\n");
        printf("**        3. Xem chi tiet gio hang                                **\n");
        printf("**        4. Loai bo mot mat hang                                 **\n"); 
		printf("**        5.Ghi toan bo noi dung vao tep nhi phan cart.dat        **\n");
        printf("**        6. Thoat                                                **\n");
      	printf("********************************************************************\n");

	 	printf("          Lua chon 1->6:");
scanf("%d",&a);
switch(a){
	case 1: {taogiohang(); break;}
	case 2:	{chonhang(); break;}
	case 3: {xemchitiet(); break;}
	case 4: {loaibomathang(); break;}
	case 5:	{luu(); break;}
	default: break;
}
}while(a!=6);
}
int main()
{ 	Menu();

return 0;
}
