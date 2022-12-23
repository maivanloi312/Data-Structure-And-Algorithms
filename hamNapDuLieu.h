#pragma once
#include "hamGhiDuLieu.h"

//nap du lieu mon hoc
void docFileMonHoc(DS_MON_HOC &ds_mh)
{
	ifstream fileInput;
	fileInput.open("Data/danhSachMonHoc.txt",ios::in);
	while (!fileInput.eof())
	{
		ds_mh.dsmh[ds_mh.soMH]=new MON_HOC;
		getline(fileInput,ds_mh.dsmh[ds_mh.soMH]->maMH,'|');
		getline(fileInput,ds_mh.dsmh[ds_mh.soMH]->tenMH,'\n');
		ds_mh.soMH++;
	}
	ds_mh.soMH--;
	fileInput.close();
}
//nap du lieu lop hoc
void docFileMotLopHoc(ifstream &fileInput,DS_LOP_HOC &ds_lh)
{
	ds_lh.dslh[ds_lh.soLH]=new LOP_HOC;
	getline(fileInput,ds_lh.dslh[ds_lh.soLH]->maLH,'|');
	getline(fileInput,ds_lh.dslh[ds_lh.soLH]->tenLH,'\n');
	ds_lh.soLH++;
}
void docFileLopHoc(DS_LOP_HOC &ds_lh)
{
	ifstream fileInput;
	fileInput.open("Data/danhSachLopHoc.txt",ios::in);
	while (!fileInput.eof())
	{
		docFileMotLopHoc(fileInput,ds_lh);
	}
	ds_lh.soLH--;
	fileInput.close();
}
//nap du lieu sinh vien
void docFileMotSinhVien(ifstream &fileInput,SINH_VIEN &sv)
{
	getline(fileInput,sv.maSV,'|');
	getline(fileInput,sv.hoSV,'|');	
	getline(fileInput,sv.tenSV,'|');
	getline(fileInput,sv.gioiTinh,'|');
	getline(fileInput,sv.matKhau,'\n');
}
void docFileSinhVienTheoLop(DS_LOP_HOC &ds_lh)
{
	ifstream fileInput;
	fileInput.open("Data/danhSachSinhVien.txt",ios::in);
	for (int i=0;i<ds_lh.soLH;i++)
	{
		getline(fileInput,ds_lh.dslh[i]->maLH,'\n');
		fileInput>>ds_lh.dslh[i]->danhSachSinhVien.soSV;
		fileInput.ignore();
		for(int j=0;j<ds_lh.dslh[i]->danhSachSinhVien.soSV;j++)
		{
			SINH_VIEN sv;
			docFileMotSinhVien(fileInput,sv);
			themSinhVien(ds_lh.dslh[i]->danhSachSinhVien.pHead,sv);
		}
	}
	fileInput.close();
}
//nap du lieu cau hoi thi
void docFileCauHoi(DS_CAU_HOI &ds_ch)
{
	ifstream fileInput;
	fileInput.open("Data/danhSachCauHoi.txt",ios::in);
	while (!fileInput.eof())
	{
		cauHoi *ch=createNodeQuestion();
		ch->ID=taoID(ds_ch.dsch);
		getline(fileInput,ch->maMH,'|');
		getline(fileInput,ch->noiDung,'|');
		getline(fileInput,ch->A,'|');
		getline(fileInput,ch->B,'|');
		getline(fileInput,ch->C,'|');
		getline(fileInput,ch->D,'|');
		fileInput>>ch->dapAn;
		fileInput.ignore();
		themNode(ds_ch.dsch,ch);
		ds_ch.soCH++;
	}
	fileInput.close();
}
//nap du lieu cau hoi da thi theo mon hoc
void docFileDeThiTheoMonHoc(CHI_TIET_THI *&pHead,ifstream &fileInput)
{
	CHI_TIET_THI *p=createNodeExam();
	getline(fileInput,p->maMH,'|');
	fileInput>>p->diem;
	fileInput.ignore();
	fileInput>>p->soCauThi;
	fileInput.ignore();
	fileInput>>p->soCauDung;
	fileInput.ignore();
	for (int i=1;i<=p->soCauThi;i++)
	{
		p->danhSachDeThi.dsdt[i]=new DE_THI;
		getline(fileInput,p->danhSachDeThi.dsdt[i]->boDe.noiDung,'|');
		getline(fileInput,p->danhSachDeThi.dsdt[i]->boDe.A,'|');
		getline(fileInput,p->danhSachDeThi.dsdt[i]->boDe.B,'|');
		getline(fileInput,p->danhSachDeThi.dsdt[i]->boDe.C,'|');
		getline(fileInput,p->danhSachDeThi.dsdt[i]->boDe.D,'|');
		fileInput>>p->danhSachDeThi.dsdt[i]->boDe.dapAn;
		fileInput.ignore();
		fileInput>>p->danhSachDeThi.dsdt[i]->traLoi;
		fileInput.ignore();
		p->danhSachDeThi.soDT++;
	}
	p->danhSachDeThi.soDT--;
	themChiTietThi(pHead,p);
}
//nap du lieu cau hoi da thi theo sinh vien
void docFileDeThiTheoSinhVien(SINH_VIEN *&pHead,ifstream &fileInput)
{
	getline(fileInput,pHead->maSV,'|');
	fileInput>>pHead->danhSachChiTietThi.soCTT;
	fileInput.ignore();
	for(int i=0;i<pHead->danhSachChiTietThi.soCTT;i++)
	{
		docFileDeThiTheoMonHoc(pHead->danhSachChiTietThi.pHead,fileInput);
	}
}
//nap du lieu cau hoi da thi theo lop hoc
void docFileDeThiTheoLop(DS_LOP_HOC &ds_lh)
{
	ifstream fileInput;
	fileInput.open("Data/danhSachChiTietCauHoiThi.txt",ios::in);
	for (int i=0;i<ds_lh.soLH;i++)
	{
		getline(fileInput,ds_lh.dslh[i]->maLH,'\n');
		fileInput>>ds_lh.dslh[i]->danhSachSinhVien.soSV;
		fileInput.ignore();
		SINH_VIEN *p=ds_lh.dslh[i]->danhSachSinhVien.pHead;
		while (p!=NULL)
		{
			docFileDeThiTheoSinhVien(p,fileInput);
			p=p->next;
		}
	}
	fileInput.close();
}
