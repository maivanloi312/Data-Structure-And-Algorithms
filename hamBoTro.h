#pragma once
#include "hamKhoiTao.h"


//mon hoc
int kiemTraTonTaiMonHoc(string a, DS_MON_HOC ds_mh)
{
	for (int i=0;i<ds_mh.soMH;i++)
	{
		if(ds_mh.dsmh[i]->maMH==a)
		{
			return i;
		}
	}
	return -1;
}
int kiemTraDoDaiMaMonHoc(string a)
{
	int dem=0;
	for(int i=0;i<a.size();i++)
	{
		dem++;
	}
	if (dem>15)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
//lop hoc
int kiemTraTonTaiLopHoc(string c, DS_LOP_HOC ds_lh)
{
	for (int i=0;i<ds_lh.soLH;i++)
	{
		if(ds_lh.dslh[i]->maLH==c)
		{
			return i;
		}
	}
	return -1;
}
//sinh vien
sinhVien *kiemTraTonTaiSinhVien(string s,DS_LOP_HOC ds_lh)
{
	for (int i=0;i<ds_lh.soLH;i++)
	{
		sinhVien *p=ds_lh.dslh[i]->danhSachSinhVien.pHead;
		while(p!=NULL)
		{
			if(p->maSV==s)
			{
				return p;
			}
			p=p->next;
		}
	}
	return NULL;
}
sinhVien *createNodeStudent(SINH_VIEN &sv)
{
	SINH_VIEN *temp= new SINH_VIEN; 
	temp->next=NULL;
	temp->maSV=sv.maSV;
	temp->hoSV=sv.hoSV;
	temp->tenSV=sv.tenSV;
	temp->gioiTinh=sv.gioiTinh;
	temp->matKhau=sv.matKhau;
	return temp;
}
void addFirstNodeStudent(SINH_VIEN *&pHead,SINH_VIEN &sv)
{
	pHead=createNodeStudent(sv);
}
void addLastNodeStudent(SINH_VIEN *&pHead,SINH_VIEN &sv)
{
	SINH_VIEN *p=pHead;
	while (p->next!=NULL)
	{
		p=p->next;
	}
	p->next=createNodeStudent(sv);
}

void themSinhVien(SINH_VIEN *&pHead,SINH_VIEN &sv)
{
	if (pHead==NULL)
	{
		addFirstNodeStudent(pHead,sv);
	}
	else
	{
		addLastNodeStudent(pHead,sv);
	}
}
void xuatSinhVien(SINH_VIEN *&pHead)
{
	SINH_VIEN *p=pHead;
	while(p!=NULL)
	{
		cout<<"Ma sinh vien: "<<p->maSV<<endl;
		cout<<"Ho sinh vien: "<<p->hoSV<<endl;
		cout<<"Ten sinh vien: "<<p->tenSV<<endl;
		cout<<"Gioi tinh: "<<p->gioiTinh<<endl;
		cout<<"Mat khau tai khoan sinh vien: "<<p->matKhau<<endl;
		p=p->next;
	}
}
//cau hoi thi
bool kiemTraTrungID(CAU_HOI t,int a)
{
	if (t!=NULL)
	{
		if (t->ID==a)
		{
			return 1;
		}
		else if (t->ID>a)
		{
			kiemTraTrungID(t->left,a);
		}
		else
		{
			kiemTraTrungID(t->right,a);
		}
	}
	else
	{
		return 0;
	}
}
int taoID(CAU_HOI t)
{
	int a;
	do
	{
		a=rand()%10000;
	} while (kiemTraTrungID(t,a));
	return a;
}
cauHoi *createNodeQuestion()
{
	cauHoi *temp=new cauHoi;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
cauHoi *themNode(CAU_HOI &t, cauHoi *p)
{
	if (t==NULL)
	{
		t=p;
	}
	else
	{
		if (p->ID<t->ID)
		{
			themNode(t->left,p);
		}
		else
		{
			themNode(t->right,p);
		}
	}
}
// chi tiet thi
chiTietThi *kiemTraTonTaiDeThi(string s,CHI_TIET_THI *&pHead)
{
	CHI_TIET_THI *p=pHead;
	while (p!=NULL)
	{
		if(p->maMH==s)
		{
			return p;
		}
		p=p->next;
	}
	return NULL;
}
CHI_TIET_THI *createNodeExam()
{
	CHI_TIET_THI *temp= new CHI_TIET_THI; 
	temp->next=NULL;
	return temp;
}
void addFirstNodeExam(CHI_TIET_THI *&pHead,CHI_TIET_THI *p)
{
	pHead=p;
}
void addLastNodeExam(CHI_TIET_THI *&pHead,CHI_TIET_THI *p)
{
	CHI_TIET_THI *temp=pHead;
	while (temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=p;
}
void themChiTietThi(CHI_TIET_THI *&pHead,CHI_TIET_THI *p)
{
	if (pHead==NULL)
	{
		addFirstNodeExam(pHead,p);
	}
	else
	{
		addLastNodeExam(pHead,p);
	}
}
//void duyetCay(CAU_HOI t,CHI_TIET_THI *&p)
//{
//	if (t!=NULL)
//	{
//		duyetCay(t->left,p);
//		if(t->maMH==p->maMH && p->danhSachDeThi.soDT<=p->soCauThi)
//		{
//			DE_THI *temp=new DE_THI;
//			cout<<p->danhSachDeThi.soDT<<". "<<t->noiDung<<endl;
//			cout<<t->A<<endl;
//			cout<<t->B<<endl;
//			cout<<t->C<<endl;
//			cout<<t->D<<endl;
//			temp->boDe.noiDung=t->noiDung;
//			temp->boDe.A=t->A;
//			temp->boDe.B=t->B;
//			temp->boDe.C=t->C;
//			temp->boDe.D=t->D;
//			temp->boDe.dapAn=t->dapAn;
//			cin>>temp->traLoi;
//			p->danhSachDeThi.dsdt[p->danhSachDeThi.soDT]=temp;
//			p->danhSachDeThi.soDT++;
//		}
//		duyetCay(t->right,p);
//	}
//}
void tinhDiem(CHI_TIET_THI *&pHead)
{
	for (int i=1;i<=pHead->soCauThi;i++)
	{
		if (pHead->danhSachDeThi.dsdt[i]->traLoi==pHead->danhSachDeThi.dsdt[i]->boDe.dapAn)
		{
			pHead->soCauDung++;
		}
	}
	pHead->diem=(float)10/pHead->soCauThi*pHead->soCauDung;
}
void kiemTraSoLuongCauHoi(CAU_HOI t, int &n, string a)
{
	if (t!=NULL)
	{
		kiemTraSoLuongCauHoi(t->left,n,a);
		if(t->maMH==a)
		{
			n++;		
		}
		kiemTraSoLuongCauHoi(t->right,n,a);
	}
}
//=================================
bool stop = 1;
char inToA(int k) {
	switch (k)
	{
	case 0:return '0';
	case 1:return '1';
	case 2:return '2';
	case 3:return '3';
	case 4:return '4';
	case 5:return '5';
	case 6:return '6';
	case 7:return '7';
	case 8:return '8';
	case 9:return '9';
	default:
		break;
	}
}

void insertarray(char *h, Hour *j) {
	int bait = 0;
	bait = j->second;
	h[7] = inToA(bait % 10);
	h[6] = inToA(bait /= 10);

	bait = j->minute;
	h[4] = inToA(bait % 10);
	h[3] = inToA(bait /= 10);

	bait = j->hour;
	h[1] = inToA(bait % 10);
	h[0] = inToA(bait /= 10);

}

bool changetime(Hour *h) {
	if (h->second > 0) --h->second;
	else if (h->minute > 0) {
		h->second = 59;
		--h->minute;
	}
	else if (h->hour > 0)
	{
		--h->hour;
		h->minute = 59;
		h->second = 59;
	}
	else return 0;
	return 1;
}

////dung de in ra mot chuoi thay the ham cout
void WriteBlockChar(char * Arraych,
	int row, int col,
	int x, int y,
	int color)
{
	CHAR_INFO *charater = new CHAR_INFO[row*col];
	for (int i = 0; i < row*col; i++) {
		charater[i].Attributes = color;
		charater[i].Char.AsciiChar = Arraych[i];
	}
	COORD sizebuff = { col,row };
	COORD pos = { 0,0 };
	SMALL_RECT earea = { x,y,x + col - 1,y + row - 1 };
	WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), charater, sizebuff, pos, &earea);
	delete[] charater;
}
////
//void printClock() {
//		Hour h = { 1,1,1 };
//		char a[8] = { '0','0',':','0','0',':','0','0'};
//		while (stop)
//		{
//			if (!changetime(&h)) stop = 0;
//			insertarray(a, &h);
//			WriteBlockChar(a, 1, 8, 70, 3,0x004|0x060);
//			Sleep(970);
//		}
//		return;
//}
void printClock(int tgian){
	Hour h;
	if(tgian < 60)
	{
		h = { 0,tgian,0};
	}
	else if (tgian == 60)
	{
		h = { 1,0,0};
	}
	else
	{
		int g = tgian/60;
		int p = tgian%60;
		h = { g,p,0};
	}
	char a[8] = { '0','0',':','0','0',':','0','0'};
	while (stop)
		{
			if (!changetime(&h)) stop = 0;
			insertarray(a, &h);
			WriteBlockChar(a, 1, 8, 195, 3,0x004|0x060);
			Sleep(970);
		}
	return;
}
void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void close(DWORD evt) {
	if (evt == CTRL_CLOSE_EVENT) stop = 0;
}
