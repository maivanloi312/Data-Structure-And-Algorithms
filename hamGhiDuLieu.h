#pragma once
#include "hamBoTro.h"

//ghi du lieu mon hoc
void themFileMonHoc(DS_MON_HOC &ds_mh)
{
	ofstream fileOutput;
	fileOutput.open("Data/danhSachMonHoc.txt",ios::out | ios::app);
	fileOutput<<ds_mh.dsmh[ds_mh.soMH]->maMH<<"|"<<ds_mh.dsmh[ds_mh.soMH]->tenMH<<endl;
	fileOutput.close();
}
void hieuChinhFileMonHoc(DS_MON_HOC &ds_mh)
{
	ofstream fileOutput;
	fileOutput.open("Data/danhSachMonHoc.txt",ios::out);
	for (int i=0;i<ds_mh.soMH;i++)
	{
		fileOutput<<ds_mh.dsmh[i]->maMH<<"|"<<ds_mh.dsmh[i]->tenMH<<endl;
	}
	fileOutput.close();
}
//ghi du lieu lop hoc
void themFileLopHoc(DS_LOP_HOC &ds_lh)
{
	ofstream fileOutput;
	fileOutput.open("Data/danhSachLopHoc.txt",ios::out | ios::app);
	fileOutput<<ds_lh.dslh[ds_lh.soLH]->maLH<<"|"<<ds_lh.dslh[ds_lh.soLH]->tenLH<<endl;
	fileOutput.close();
}
// ghi du lieu sinh vien theo lop
void themFileSinhVienTheoLop(DS_LOP_HOC &ds_lh)
{
	ofstream fileOutput;
	fileOutput.open("Data/danhSachSinhVien.txt",ios::out);
	for (int i=0;i<ds_lh.soLH;i++)
	{	
		fileOutput<<ds_lh.dslh[i]->maLH<<endl;
		fileOutput<<ds_lh.dslh[i]->danhSachSinhVien.soSV<<endl;
		SINH_VIEN *p=ds_lh.dslh[i]->danhSachSinhVien.pHead;
		for(int j=0;j<ds_lh.dslh[i]->danhSachSinhVien.soSV;j++)
		{
			fileOutput<<p->maSV<<"|"<<p->hoSV<<"|"<<p->tenSV<<"|"<<p->gioiTinh<<"|"<<p->matKhau<<endl;
			p=p->next;
		}
	}
	fileOutput.close();
}
// ghi du lieu cau hoi thi
cauHoi *ghiFileCauHoi(CAU_HOI &t, cauHoi *p,ofstream &fileOutput)
{
	if (t==NULL)
	{
		fileOutput<<endl<<p->maMH<<"|"<<p->noiDung<<"|"<<p->A<<"|"<<p->B<<"|"<<p->C<<"|"<<p->D<<"|"<<p->dapAn;
	}
	else
	{
		if (p->ID<t->ID)
		{
			ghiFileCauHoi(t->left,p,fileOutput);
		}
		else
		{
			ghiFileCauHoi(t->right,p,fileOutput);
		}
	}
}
void themFileCauHoi(DS_CAU_HOI &ds_ch,cauHoi *p)
{
	ofstream fileOutput;
	fileOutput.open("Data/danhSachCauHoi.txt",ios::out | ios::app);
	ghiFileCauHoi(ds_ch.dsch,p,fileOutput);
	fileOutput.close();
}
// ghi du lieu cau hoi da thi theo mon hoc
void themFileDeThiTheoMonHoc(CHI_TIET_THI *&pHead,ofstream &fileOutput)
{
	fileOutput<<pHead->maMH<<"|"<<roundf(pHead->diem*10)/10<<"|"<<pHead->soCauThi<<"|"<<pHead->soCauDung<<endl;
	for (int i=1;i<=pHead->soCauThi;i++)
	{
		fileOutput<<pHead->danhSachDeThi.dsdt[i]->boDe.noiDung<<"|";
		fileOutput<<pHead->danhSachDeThi.dsdt[i]->boDe.A<<"|";
		fileOutput<<pHead->danhSachDeThi.dsdt[i]->boDe.B<<"|";
		fileOutput<<pHead->danhSachDeThi.dsdt[i]->boDe.C<<"|";
		fileOutput<<pHead->danhSachDeThi.dsdt[i]->boDe.D<<"|";
		fileOutput<<pHead->danhSachDeThi.dsdt[i]->boDe.dapAn<<"|";
		fileOutput<<pHead->danhSachDeThi.dsdt[i]->traLoi<<endl;
	}
}
// ghi du lieu cau hoi da thi theo sinh vien
void themFileDeThiTheoSinhVien(SINH_VIEN *&pHead,ofstream &fileOutput)
{
	fileOutput<<pHead->maSV<<"|"<<pHead->danhSachChiTietThi.soCTT<<endl;
	CHI_TIET_THI *p=pHead->danhSachChiTietThi.pHead;
	while (p!=NULL)
	{
		themFileDeThiTheoMonHoc(p,fileOutput);
		p=p->next;
	}
}
// ghi du lieu cau hoi da thi theo lop hoc
void themFileDeThiTheoLop(DS_LOP_HOC &ds_lh)
{
	ofstream fileOutput;
	fileOutput.open("Data/danhSachChiTietCauHoiThi.txt",ios::out);
	for (int i=0;i<ds_lh.soLH;i++)
	{	
		fileOutput<<ds_lh.dslh[i]->maLH<<endl;
		fileOutput<<ds_lh.dslh[i]->danhSachSinhVien.soSV<<endl;
		SINH_VIEN *p=ds_lh.dslh[i]->danhSachSinhVien.pHead;
		while (p!=NULL)
		{
			themFileDeThiTheoSinhVien(p,fileOutput);
			p=p->next;
		}
	}
	fileOutput.close();
}
