#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <thread>
#define MAX 100

using namespace std;

//danh sach cau hoi (cay nhi phan)
struct cauHoi
{
	int ID;
	string maMH,noiDung,A,B,C,D;
	char dapAn;
	cauHoi *left;
	cauHoi *right;
};
typedef struct cauHoi *CAU_HOI;
struct dscauHoi
{
	CAU_HOI dsch=NULL;
	int soCH=0;
};
typedef struct dscauHoi DS_CAU_HOI;
//bo de thi (mang con tro)
struct deThi
{
	cauHoi boDe;
	char traLoi;
};
typedef struct deThi DE_THI;
struct dsdeThi
{
	DE_THI *dsdt[MAX];
	int soDT=1;
};
typedef struct dsdeThi DS_DE_THI;
// danh sach de thi (danh sach lien ket don)
struct chiTietThi
{
	int soCauThi,gio,phut,giay,soCauDung;
	string maMH;
	float diem;
	DS_DE_THI danhSachDeThi;
	chiTietThi *next;
};
typedef struct chiTietThi CHI_TIET_THI;
struct dschiTietThi
{
	CHI_TIET_THI *pHead=NULL;
	int soCTT=0;
};
typedef struct dschiTietThi DS_CHI_TIET_THI;
//danh sach mon hoc (danh sach tuyen tinh)
struct monHoc
{
	string maMH;
	string tenMH;
};
typedef struct monHoc MON_HOC;
struct dsmonHoc
{
	MON_HOC *dsmh[MAX];
	int soMH=0;
};
typedef struct dsmonHoc DS_MON_HOC;
//danh sach sinh vien (danh sach lien ket don)
struct sinhVien
{
	string maSV;
	string hoSV;
	string tenSV;
	string gioiTinh;
	string matKhau;
	DS_CHI_TIET_THI danhSachChiTietThi;
	sinhVien *next;
};
typedef struct sinhVien SINH_VIEN;
struct dssinhVien
{
	SINH_VIEN *pHead=NULL;
	int soSV=0;
};
typedef struct dssinhVien DS_SINH_VIEN;
//danh sach lop hoc (mang con tro)
struct lopHoc
{
	string maLH;
	string tenLH;
	DS_SINH_VIEN danhSachSinhVien;
};
typedef struct lopHoc LOP_HOC;
struct dslopHoc
{
	LOP_HOC *dslh[MAX];
	int soLH=0;
};
typedef struct dslopHoc DS_LOP_HOC;
//thoi gian
struct Hour{
	int hour;
	int minute;
	int second;
};
