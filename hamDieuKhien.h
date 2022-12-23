#pragma once
#include "hamNapDuLieu.h"
#include "thuviencuatoi.h"

void NhapMonThi(DS_MON_HOC ds_mh, DS_CAU_HOI ds_ch, string &mamt, int &socau, int &sophut, bool &check){
	if(ds_mh.soMH == 0){
		return;
	}
	VeKhungNhapMonThi();
	string cau, phut;
	check = false;
	char k;
	bool checkPhim;
	while((k=LayPhim(checkPhim))!=ESC){
		if(wherey()==17){
			if(((k > 96 && k<123) || (k>64 && k<91)) && checkPhim==false && mamt.length()<15){
				cout << InHoa(k);
				mamt+=InHoa(k);
			}else if((k>47 && k<58) && checkPhim==false && mamt.length()<15){
				cout << k;
				mamt+=k;
			}else if(k==BACKSPACE && mamt.length()>0){
				XoaCuoi(mamt);
				BackSpace();
			}else if(k==DOWN && checkPhim==true){
				gotoxy(95, 16);
				VeKhung(3, 30);
				gotoxy(96, 17);
				cout << mamt;
				SetColor(13);
				gotoxy(95,19);
				VeKhung(3, 15);
				SetColor(7);
				gotoxy(96, 20);
				cout << cau;
			}
		}else if(wherey()==20){
			if((k>47 && k<58) && checkPhim==false && cau.length()<2){
				cout << k;
				cau+=k;
				socau=DoiSo(cau);
			}else if(k==BACKSPACE && cau.length()>0){
				XoaCuoi(cau);
				BackSpace();
				socau=DoiSo(cau);
			}else if(k==DOWN && checkPhim==true){
				gotoxy(95,19);
				VeKhung(3, 15);
				gotoxy(96, 20);
				cout << cau;
				SetColor(13);
				gotoxy(95,  22);
				VeKhung(3, 15);
				SetColor(7);
				gotoxy(96, 23);
				cout << phut;
			}else if(k==UP && checkPhim==true){
				gotoxy(95,19);
				VeKhung(3, 15);
				gotoxy(96, 20);
				cout << cau;
				SetColor(13);
				gotoxy(95, 16);
				VeKhung(3, 30);
				SetColor(7);
				gotoxy(96, 17);
				cout << mamt;
			}
		}else if(wherey()==23){
			if((k>47 && k<58) && checkPhim==false && phut.length()<2){
				cout << k;
				phut+=k;
				sophut=DoiSo(phut);
			}else if(k==BACKSPACE && phut.length()>0){
				XoaCuoi(phut);
				BackSpace();
				sophut=DoiSo(phut);
			}else if(k==DOWN && checkPhim==true){
				gotoxy(95,  22);
				VeKhung(3, 15);
				gotoxy(96, 23);
				cout << phut;
				SetColor(13);
				gotoxy(96, 25);
				VeNut("XAC NHAN");
				SetColor(7);
				ShowCur(0);
			}else if(k==UP && checkPhim==true){
				gotoxy(95,  22);
				VeKhung(3, 15);
				gotoxy(96, 23);
				cout << phut;
				SetColor(13);
				gotoxy(95,19);
				VeKhung(3, 15);
				SetColor(7);
				gotoxy(96, 20);
				cout << cau;
			}
		}else if(wherey()==26){
			if(k==UP && checkPhim==true){
				gotoxy(96, 25);
				VeNut("XAC NHAN");
				SetColor(13);
				gotoxy(95,  22);
				VeKhung(3, 15);
				SetColor(7);
				gotoxy(96, 23);
				cout << phut;
				ShowCur(1);
			}else if(k==ENTER){
				if(mamt.length() == 0 || cau.length() == 0 || phut.length() == 0){
					gotoxy(96, 25);
					VeNut("XAC NHAN");
					BaoLoi(83, 18, "Vui long dien day du thong tin!");
					VeKhungNhapMonThi();
					gotoxy(96, 23);
					cout << phut;
					gotoxy(96, 20);
					cout << cau;
					gotoxy(96, 17);
					cout << mamt;
				}else if(socau==0 || sophut==0){
					gotoxy(96, 25);
					VeNut("XAC NHAN");
					BaoLoi(77,18, "Vui long nhap so cau va so phut lon hon 0!");
					VeKhungNhapMonThi();
					gotoxy(96, 23);
					cout << phut;
					gotoxy(96, 20);
					cout << cau;
					gotoxy(96, 17);
					cout << mamt;
				}else{
					gotoxy(96, 25);
					VeNut("XAC NHAN");
					int i=kiemTraTonTaiMonHoc(mamt,ds_mh);
					int n=0;
					kiemTraSoLuongCauHoi(ds_ch.dsch,n,mamt);
					if(i==-1){
						BaoLoi(83, 18, "Ma mon hoc khong ton tai!");
						VeKhungNhapMonThi();
						gotoxy(96, 23);
						cout << phut;
						gotoxy(96, 20);
						cout << cau;
						gotoxy(96, 17);
						cout << mamt;
					}else if(socau>n){
						BaoLoi(72,18,"So luong cau hoi trong ngan hang khong du de thi!");
						VeKhungNhapMonThi();
						gotoxy(96, 23);
						cout << phut;
						gotoxy(96, 20);
						cout << cau;
						gotoxy(96, 17);
						cout << mamt;
					}else{
						check=true;
						gotoxy(70,14);
						XoaKhung(15, 60);
						return;
					}
				}
			}
		}
	}
}

void duyetCay(CAU_HOI t,CHI_TIET_THI *&p)
{
	if (t!=NULL)
	{
		duyetCay(t->left,p);
		if(t->maMH==p->maMH && p->danhSachDeThi.soDT<=p->soCauThi)
		{
			DE_THI *temp=new DE_THI;
			temp->boDe.noiDung=t->noiDung;
			temp->boDe.A=t->A;
			temp->boDe.B=t->B;
			temp->boDe.C=t->C;
			temp->boDe.D=t->D;
			temp->boDe.dapAn=t->dapAn;
			temp->traLoi='0';
			p->danhSachDeThi.dsdt[p->danhSachDeThi.soDT]=temp;
			p->danhSachDeThi.soDT++;
		}
		duyetCay(t->right,p);
	}
}
CHI_TIET_THI *LayDeThi(CAU_HOI t,CHI_TIET_THI *&p){
	duyetCay(t,p);
	return p;
}

void ThiThu(DS_MON_HOC ds_mh,DS_CAU_HOI ds_ch){
	string mamonThi;
	int socauThi, tgThi;
	bool l;
	NhapMonThi(ds_mh,ds_ch,mamonThi,socauThi,tgThi,l);
	if(l==false) return;
	SetColor(8);
	gotoxy(3,42);
	cout << "LEFT: Cau truoc    RIGHT: Cau sau";
	gotoxy(3,40);
	cout << "F1: Nop bai";
	gotoxy(188,3);
	cout << "TIME:";
	SetColor(7);
	thread clock;
	clock = thread(printClock, tgThi);
	CHI_TIET_THI *p=createNodeExam();
	p->maMH=mamonThi;
	p->soCauThi=socauThi;
	p->phut=tgThi;
	p=LayDeThi(ds_ch.dsch,p);
	string tenmonThi;
	for (int i=0;i<ds_mh.soMH;i++){
		if(ds_mh.dsmh[i]->maMH==mamonThi){
			tenmonThi=ds_mh.dsmh[i]->tenMH;
			break;
		}
	}
	SetColor(10);
	gotoxy(50, 6);
	cout << "BAI THI MON " << tenmonThi;
	SetColor(7);
	int i=1;
	gotoxy(43,7);
	while(i<=socauThi){
		if(i<34){
			if(i<10){
				gotoxy(wherex()+2, 7);
				cout << i <<".?";
			}else{
				gotoxy(wherex()+1, 7);
				cout << i <<".?";
			}
			if(i==33)
				gotoxy(43,9);
		}else if(i<67){
			gotoxy(wherex()+1, 9);
			cout << i <<".?";
			if(i==66)
				gotoxy(43,11);
		}else{
			gotoxy(wherex()+1, 11);
			cout << i <<".?";
		}
		i++;
	}
	
	int cau=1;
	DE_THI *temp=new DE_THI;
	trolai:
	VeKhungThi();
	temp=p->danhSachDeThi.dsdt[cau];
	gotoxy(55,13);
	cout << "Cau " << cau << ":";
	HienThi(61,190,16,temp->boDe.noiDung);
	HienThi(61,190,22,temp->boDe.A);
	HienThi(61,190,27,temp->boDe.B);
	HienThi(61,190,32,temp->boDe.C);
	HienThi(61,190,37,temp->boDe.D);
	if(temp->traLoi == 'A'){
		gotoxy(60,41);
		VeNutMauChu(3, " A ");
		SetColor(13);
		gotoxy(60,21);
		VeKhung(4,133);
		SetColor(7);
		HienThi(61,190,22,temp->boDe.A);
		ShowCur(0);
	}else if(temp->traLoi == 'B'){
		gotoxy(70,41);
		VeNutMauChu(3," B ");
		SetColor(13);
		gotoxy(60,26);
		VeKhung(4,133);
		SetColor(7);
		HienThi(61,190,27,temp->boDe.B);	
		ShowCur(0);
	}else if(temp->traLoi == 'C'){
		gotoxy(80,41);
		VeNutMauChu(3," C ");
		SetColor(13);
		gotoxy(60,31);
		VeKhung(4,133);
		SetColor(7);
		HienThi(61,190,32,temp->boDe.C);
		ShowCur(0);
	}else if(temp->traLoi == 'D'){
		gotoxy(90,41);
		VeNutMauChu(3," D ");
		SetColor(13);
		gotoxy(60,36);
		VeKhung(4,133);
		SetColor(7);
		HienThi(61,190,37,temp->boDe.D);
		ShowCur(0);
	}else{
		SetColor(13);
		gotoxy(60,21);
		VeKhung(4,133);
		SetColor(7);
		HienThi(61,190,22,temp->boDe.A);
		ShowCur(0);
	}
	char k;
	bool checkPhim;
	while(stop){
		k=LayPhim(checkPhim);
		if(stop==0){
			break;
		}else if(wherey()==22 || wherey()==23){
			if(k==DOWN && checkPhim==true){
				gotoxy(60,21);
				VeKhung(4,133);
				HienThi(61,190,22,temp->boDe.A);
				SetColor(13);
				gotoxy(60,26);
				VeKhung(4,133);
				SetColor(7);
				HienThi(61,190,27,temp->boDe.B);
				ShowCur(0);
			}else if(k==ENTER){
				if(temp->traLoi == 'B'){
					gotoxy(70,41);
					VeNut(" B ");
					gotoxy(60,41);
					VeNutMauChu(3, " A ");
					SetColor(7);
					temp->traLoi='A';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,22,temp->boDe.A);	
					ShowCur(0);
				}else if(temp->traLoi == 'C'){
					gotoxy(80,41);
					VeNut(" C ");
					gotoxy(60,41);
					VeNutMauChu(3, " A ");
					SetColor(7);
					temp->traLoi='A';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,22,temp->boDe.A);
					ShowCur(0);
				}else if(temp->traLoi == 'D'){
					gotoxy(90,41);
					VeNut(" D ");
					gotoxy(60,41);
					VeNutMauChu(3, " A ");
					SetColor(7);
					temp->traLoi='A';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,22,temp->boDe.A);
					ShowCur(0);
				}else{
					gotoxy(60,41);
					VeNutMauChu(3, " A ");
					SetColor(7);
					temp->traLoi='A';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,22,temp->boDe.A);
					ShowCur(0);
				}
				if(cau<34){
					SetColor(3);
					gotoxy(42+5*cau, 7);
					cout << "A";
					SetColor(7);
					gotoxy(0,22);
				}else if(cau<67){
					SetColor(3);
					gotoxy(42+5*(cau-33), 9);
					cout << "A";
					SetColor(7);
					gotoxy(0,22);
				}else{
					SetColor(3);
					gotoxy(42+5*(cau-66), 11);
					cout << "A";
					SetColor(7);
					gotoxy(0,22);
				}
			}else if(k==RIGHT && checkPhim==true){
				if(cau<socauThi){
					cau++;
					goto trolai;	
				}
			}else if(k==LEFT && checkPhim==true){
				if(cau>1){
					cau--;
					goto trolai;
				}
			}else if(k==F1 && checkPhim==true){
				if(Hoi(105,23,"Ban co chac chan muon nop bai khong?")==false){
					goto trolai;
				}else{
					gotoxy(44,5);
					XoaKhung(46, 162);
					break;
				}
			}
		}else if(wherey()==27 || wherey()==28){
			if(k==DOWN && checkPhim==true){
				gotoxy(60,26);
				VeKhung(4,133);
				HienThi(61,190,27,temp->boDe.B);
				SetColor(13);
				gotoxy(60,31);
				VeKhung(4,133);
				SetColor(7);
				HienThi(61,190,32,temp->boDe.C);
				ShowCur(0);
			}else if(k==UP && checkPhim==true){
				gotoxy(60,26);
				VeKhung(4,133);
				HienThi(61,190,27,temp->boDe.B);
				SetColor(13);
				gotoxy(60,21);
				VeKhung(4,133);
				SetColor(7);
				HienThi(61,190,22,temp->boDe.A);;
				ShowCur(0);
			}else if(k==ENTER){
				if(temp->traLoi == 'A'){
					gotoxy(60,41);
					VeNut(" A ");
					gotoxy(70,41);
					VeNutMauChu(3, " B ");
					SetColor(7);
					temp->traLoi='B';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,27,temp->boDe.B);
					ShowCur(0);
				}else if(temp->traLoi == 'C'){
					gotoxy(80,41);
					VeNut(" C ");
					gotoxy(70,41);
					VeNutMauChu(3, " B ");
					SetColor(7);
					temp->traLoi='B';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,27,temp->boDe.B);
					ShowCur(0);
				}else if(temp->traLoi == 'D'){
					gotoxy(90,41);
					VeNut(" D ");
					gotoxy(70,41);
					VeNutMauChu(3, " B ");
					SetColor(7);
					temp->traLoi='B';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,27,temp->boDe.B);
					ShowCur(0); 
				}else{
					gotoxy(70,41);
					VeNutMauChu(3, " B ");
					SetColor(7);
					temp->traLoi='B';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,27,temp->boDe.B);
					ShowCur(0);
				}
				if(cau<34){
					SetColor(3);
					gotoxy(42+5*cau, 7);
					cout << "B";
					SetColor(7);
					gotoxy(0,27);
				}else if(cau<67){
					SetColor(3);
					gotoxy(42+5*(cau-33), 9);
					cout << "B";
					SetColor(7);
					gotoxy(0,27);
				}else{
					SetColor(3);
					gotoxy(42+5*(cau-66), 11);
					cout << "B";
					SetColor(7);
					gotoxy(0,27);
				}
			}else if(k==RIGHT && checkPhim==true){
				if(cau<socauThi){
					cau++;
					goto trolai;
				}
			}else if(k==LEFT && checkPhim==true){
				if(cau>1){
					cau--;
					goto trolai;
				}
			}else if(k==F1 && checkPhim==true){
				if(Hoi(105,23,"Ban co chac chan muon nop bai khong?")==false){
					goto trolai;
				}else{
					gotoxy(44,5);
					XoaKhung(46, 162);
					break;
				}
			}
		}else if(wherey()==32 || wherey()==33){
			if(k==DOWN && checkPhim==true){
				gotoxy(60,31);
				VeKhung(4,133);
				HienThi(61,190,32,temp->boDe.C);
				SetColor(13);
				gotoxy(60,36);
				VeKhung(4,133);
				SetColor(7);
				HienThi(61,190,37,temp->boDe.D);
				ShowCur(0);
			}else if(k==UP && checkPhim==true){
				gotoxy(60,31);
				VeKhung(4,133);
				HienThi(61,190,32,temp->boDe.C);
				SetColor(13);
				gotoxy(60,26);
				VeKhung(4,133);
				SetColor(7);
				HienThi(61,190,27,temp->boDe.B);
				ShowCur(0);
			}else if(k==ENTER){
				if(temp->traLoi == 'A'){
					gotoxy(60,41);
					VeNut(" A ");
					gotoxy(80,41);
					VeNutMauChu(3, " C ");
					temp->traLoi='C';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,32,temp->boDe.C);
					ShowCur(0);
				}else if(temp->traLoi == 'B'){
					gotoxy(70,41);
					VeNut(" B ");
					gotoxy(80,41);
					VeNutMauChu(3, " C ");
					temp->traLoi='C';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,32,temp->boDe.C);
					ShowCur(0);
				}else if(temp->traLoi == 'D'){
					gotoxy(90,41);
					VeNut(" D ");
					gotoxy(80,41);
					VeNutMauChu(3, " C ");
					temp->traLoi='C';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,32,temp->boDe.C);
					ShowCur(0);
				}else{
					gotoxy(80,41);
					VeNutMauChu(3, " C ");
					temp->traLoi='C';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,32,temp->boDe.C);
					ShowCur(0);
				}
				if(cau<34){
					SetColor(3);
					gotoxy(42+5*cau, 7);
					cout << "C";
					SetColor(7);
					gotoxy(0,32);
				}else if(cau<67){
					SetColor(3);
					gotoxy(42+5*(cau-33), 9);
					cout << "C";
					SetColor(7);
					gotoxy(0,32);
				}else{
					SetColor(3);
					gotoxy(42+5*(cau-66), 11);
					cout << "C";
					SetColor(7);
					gotoxy(0,32);
				}
			}else if(k==RIGHT && checkPhim==true){
				if(cau<socauThi){
					cau++;
					goto trolai;	
				}	
			}else if(k==LEFT && checkPhim==true){
				if(cau>1){
					cau--;
					goto trolai;
				}
			}else if(k==F1 && checkPhim==true){
				if(Hoi(105,23,"Ban co chac chan muon nop bai khong?")==false){
					goto trolai;
				}else{
					gotoxy(44,5);
					XoaKhung(46, 162);
					break;
				}
			}
		}else if(wherey()==37 || wherey()==38){
			if(k==UP && checkPhim){
				gotoxy(60,36);
				VeKhung(4,133);
				HienThi(61,190,37,temp->boDe.D);
				SetColor(13);
				gotoxy(60,31);
				VeKhung(4,133);
				SetColor(7);
				HienThi(61,190,32,temp->boDe.C);
				ShowCur(0);
			}else if(k==ENTER){
				if(temp->traLoi == 'A'){
					gotoxy(60,41);
					VeNut(" A ");
					gotoxy(90,41);
					VeNutMauChu(3, " D ");
					temp->traLoi='D';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,37,temp->boDe.D);
					ShowCur(0);
				}else if(temp->traLoi == 'B'){
					gotoxy(70,41);
					VeNut(" B ");
					gotoxy(90,41);
					VeNutMauChu(3, " D ");
					temp->traLoi='D';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,37,temp->boDe.D);
					ShowCur(0);
				}else if(temp->traLoi == 'C'){
					gotoxy(80,41);
					VeNut(" C ");
					gotoxy(90,41);
					VeNutMauChu(3, " D ");
					temp->traLoi='D';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,37,temp->boDe.D);
					ShowCur(0);
				}else{
					gotoxy(90,41);
					VeNutMauChu(3, " D ");
					temp->traLoi='D';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,37,temp->boDe.D);
					ShowCur(0);
				}
				if(cau<34){
					SetColor(3);
					gotoxy(42+5*cau, 7);
					cout << "D";
					SetColor(7);
					gotoxy(0,37);
				}else if(cau<67){
					SetColor(3);
					gotoxy(42+5*(cau-33), 9);
					cout << "D";
					SetColor(7);
					gotoxy(0,37);
				}else{
					SetColor(3);
					gotoxy(42+5*(cau-66), 11);
					cout << "D";
					SetColor(7);
					gotoxy(0,37);
				}
			}else if(k==RIGHT && checkPhim==true){
				if(cau<socauThi){
					cau++;
					goto trolai;	
				}		
			}else if(k==LEFT && checkPhim==true){
				if(cau>1){
					cau--;
					goto trolai;
				}
			}else if(k==F1 && checkPhim==true){
				if(Hoi(105,23,"Ban co chac chan muon nop bai khong?")==false){
					goto trolai;
				}else{
					gotoxy(44,5);
					XoaKhung(46, 162);
					break;
				}
			}
		}
	}
	if(stop==0){
		clock.join();
		gotoxy(188,3);
		cout << "                  ";
		ThongBao(105,23,"Ban da het gio lam bai!");
		gotoxy(44,5);
		XoaKhung(46, 162);
		tinhDiem(p);
		VeKhungBaoDiem();
		gotoxy(92,21);
		cout << p->soCauDung << "/"<< p->soCauThi;
		gotoxy(93,23);
		cout<< roundf(p->diem*10)/10;
		getch();
		gotoxy(3,42);
		cout << "                                    ";
		gotoxy(3, 43);
		cout <<"              ";
	}else{
		stop=0;
		clock.join();
		gotoxy(188,3);
		cout << "                  ";
		tinhDiem(p);
		VeKhungBaoDiem();
		gotoxy(92,21);
		cout << p->soCauDung << "/"<< p->soCauThi;
		gotoxy(93,23);
		cout<< roundf(p->diem*10)/10;
		getch();
		gotoxy(3,42);
		cout << "                                    ";
		gotoxy(3, 43);
		cout <<"              ";
	}
	stop=1;
}
void Thi(SINH_VIEN *&pHead, DS_MON_HOC ds_mh,DS_CAU_HOI ds_ch,DS_LOP_HOC &ds_lh){
	nhaplai:
	string mamonThi;
	int socauThi, tgThi;
	SetColor(8);
	gotoxy(55, 35);
	cout <<"Huong dan:	 ESC: Thoat   	UP: Len		DOWN: Xuong		ENTER: Chon";
	SetColor(7);
	bool l;
	NhapMonThi(ds_mh,ds_ch,mamonThi,socauThi,tgThi,l);
	if(l==false) return;
	chiTietThi *t=kiemTraTonTaiDeThi(mamonThi,pHead->danhSachChiTietThi.pHead);
	if (t!=NULL){
		BaoLoi(87, 18, "Ban da thi mon nay!");
		goto nhaplai;
	}
	thread clock;
	clock = thread(printClock, tgThi);
	CHI_TIET_THI *p=createNodeExam();
	p->maMH=mamonThi;
	p->soCauThi=socauThi;
	p->phut =tgThi;
	p=LayDeThi(ds_ch.dsch,p);
	string tenmonThi;
	for (int i=0;i<ds_mh.soMH;i++){
		if(ds_mh.dsmh[i]->maMH==mamonThi){
			tenmonThi=ds_mh.dsmh[i]->tenMH;
			break;
		}
	}
	
	gotoxy(94,0);
	cout << "PHAN MEM THI TRAC NGHIEM";
	SetBGColor(0);
	gotoxy(98,1);
	cout << "===== &&& =====";
	gotoxy(0,2);
	VeKhung(50, 210);
	for(int i=3; i<=50; i++){
		gotoxy(43,i);
		cout << doc;
	}
	gotoxy(1,38);
	VeDuongThangNgang(42);
	SetColor(2);
	gotoxy(3,39);
	cout << "HUONG DAN:";
	SetColor(8);
	gotoxy(3,40);
	cout << "F1: Nop bai";
	gotoxy(3,41);
	cout << "LEFT: Cau truoc      RIGHT: Cau sau";
	gotoxy(3,42);
	cout << "UP: Len              DOWN: Xuong";
	gotoxy(3,43);
	cout << "ENTER: Chon";
	gotoxy(188,3);
	cout << "TIME:";
	SetColor(10);
	gotoxy(2,3);
	cout << "BAI THI MON: " << tenmonThi;
	gotoxy(2,4);
	cout << "MA MON: " << mamonThi;
	gotoxy(2,5);
	cout << "SO CAU:  " << socauThi << "  (cau)";
	gotoxy(2,6);
	cout << "THOI GIAN:  " << tgThi << "  (phut)";
	gotoxy(50, 6);
	cout << "Cau tra loi cua ban:";
	SetColor(7);
	int i=1;
	gotoxy(43,7);
	while(i<=socauThi){
		if(i<34){
			if(i<10){
				gotoxy(wherex()+2, 7);
				cout << i <<".?";
			}else{
				gotoxy(wherex()+1, 7);
				cout << i <<".?";
			}
			if(i==33)
				gotoxy(43,9);
		}else if(i<67){
			gotoxy(wherex()+1, 9);
			cout << i <<".?";
			if(i==66)
				gotoxy(43,11);
		}else{
			gotoxy(wherex()+1, 11);
			cout << i <<".?";
		}
		i++;
	}
	int cau=1;
	DE_THI *temp=new DE_THI;
	trolai:
	VeKhungThi();
	temp=p->danhSachDeThi.dsdt[cau];
	gotoxy(55,13);
	cout << "Cau " << cau << ":";
	HienThi(61,190,16,temp->boDe.noiDung);
	HienThi(61,190,22,temp->boDe.A);
	HienThi(61,190,27,temp->boDe.B);
	HienThi(61,190,32,temp->boDe.C);
	HienThi(61,190,37,temp->boDe.D);
	if(temp->traLoi == 'A'){
		gotoxy(60,41);
		VeNutMauChu(3, " A ");
		SetColor(13);
		gotoxy(60,21);
		VeKhung(4,133);
		SetColor(7);
		HienThi(61,190,22,temp->boDe.A);
		ShowCur(0);
	}else if(temp->traLoi == 'B'){
		gotoxy(70,41);
		VeNutMauChu(3," B ");
		SetColor(13);
		gotoxy(60,26);
		VeKhung(4,133);
		SetColor(7);
		HienThi(61,190,27,temp->boDe.B);	
		ShowCur(0);
	}else if(temp->traLoi == 'C'){
		gotoxy(80,41);
		VeNutMauChu(3," C ");
		SetColor(13);
		gotoxy(60,31);
		VeKhung(4,133);
		SetColor(7);
		HienThi(61,190,32,temp->boDe.C);
		ShowCur(0);
	}else if(temp->traLoi == 'D'){
		gotoxy(90,41);
		VeNutMauChu(3," D ");
		SetColor(13);
		gotoxy(60,36);
		VeKhung(4,133);
		SetColor(7);
		HienThi(61,190,37,temp->boDe.D);
		ShowCur(0);
	}else{
		SetColor(13);
		gotoxy(60,21);
		VeKhung(4,133);
		SetColor(7);
		HienThi(61,190,22,temp->boDe.A);
		ShowCur(0);
	}
	char k;
	bool checkPhim;
	while(stop){
		k=LayPhim(checkPhim);
		if(stop==0){
			break;
		}else if(wherey()==22 || wherey()==23){
			if(k==DOWN && checkPhim==true){
				gotoxy(60,21);
				VeKhung(4,133);
				HienThi(61,190,22,temp->boDe.A);
				SetColor(13);
				gotoxy(60,26);
				VeKhung(4,133);
				SetColor(7);
				HienThi(61,190,27,temp->boDe.B);
				ShowCur(0);
			}else if(k==ENTER){
				if(temp->traLoi == 'B'){
					gotoxy(70,41);
					VeNut(" B ");
					gotoxy(60,41);
					VeNutMauChu(3, " A ");
					SetColor(7);
					temp->traLoi='A';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,22,temp->boDe.A);	
					ShowCur(0);
				}else if(temp->traLoi == 'C'){
					gotoxy(80,41);
					VeNut(" C ");
					gotoxy(60,41);
					VeNutMauChu(3, " A ");
					SetColor(7);
					temp->traLoi='A';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,22,temp->boDe.A);
					ShowCur(0);
				}else if(temp->traLoi == 'D'){
					gotoxy(90,41);
					VeNut(" D ");
					gotoxy(60,41);
					VeNutMauChu(3, " A ");
					SetColor(7);
					temp->traLoi='A';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,22,temp->boDe.A);
					ShowCur(0);
				}else{
					gotoxy(60,41);
					VeNutMauChu(3, " A ");
					SetColor(7);
					temp->traLoi='A';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,22,temp->boDe.A);
					ShowCur(0);
				}
				if(cau<34){
					SetColor(3);
					gotoxy(42+5*cau, 7);
					cout << "A";
					SetColor(7);
					gotoxy(0,22);
				}else if(cau<67){
					SetColor(3);
					gotoxy(42+5*(cau-33), 9);
					cout << "A";
					SetColor(7);
					gotoxy(0,22);
				}else{
					SetColor(3);
					gotoxy(42+5*(cau-66), 11);
					cout << "A";
					SetColor(7);
					gotoxy(0,22);
				}
			}else if(k==RIGHT && checkPhim==true){
				if(cau<socauThi){
					cau++;
					goto trolai;	
				}
			}else if(k==LEFT && checkPhim==true){
				if(cau>1){
					cau--;
					goto trolai;
				}
			}else if(k==F1 && checkPhim==true){
				if(Hoi(105,23,"Ban co chac chan muon nop bai khong?")==false){
					goto trolai;
				}else{
					gotoxy(44,5);
					XoaKhung(46, 162);
					break;
				}
			}
		}else if(wherey()==27 || wherey()==28){
			if(k==DOWN && checkPhim==true){
				gotoxy(60,26);
				VeKhung(4,133);
				HienThi(61,190,27,temp->boDe.B);
				SetColor(13);
				gotoxy(60,31);
				VeKhung(4,133);
				SetColor(7);
				HienThi(61,190,32,temp->boDe.C);
				ShowCur(0);
			}else if(k==UP && checkPhim==true){
				gotoxy(60,26);
				VeKhung(4,133);
				HienThi(61,190,27,temp->boDe.B);
				SetColor(13);
				gotoxy(60,21);
				VeKhung(4,133);
				SetColor(7);
				HienThi(61,190,22,temp->boDe.A);;
				ShowCur(0);
			}else if(k==ENTER){
				if(temp->traLoi == 'A'){
					gotoxy(60,41);
					VeNut(" A ");
					gotoxy(70,41);
					VeNutMauChu(3, " B ");
					SetColor(7);
					temp->traLoi='B';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,27,temp->boDe.B);
					ShowCur(0);
				}else if(temp->traLoi == 'C'){
					gotoxy(80,41);
					VeNut(" C ");
					gotoxy(70,41);
					VeNutMauChu(3, " B ");
					SetColor(7);
					temp->traLoi='B';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,27,temp->boDe.B);
					ShowCur(0);
				}else if(temp->traLoi == 'D'){
					gotoxy(90,41);
					VeNut(" D ");
					gotoxy(70,41);
					VeNutMauChu(3, " B ");
					SetColor(7);
					temp->traLoi='B';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,27,temp->boDe.B);
					ShowCur(0);
				}else{
					gotoxy(70,41);
					VeNutMauChu(3, " B ");
					SetColor(7);
					temp->traLoi='B';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,27,temp->boDe.B);
					ShowCur(0);
				}
				if(cau<34){
					SetColor(3);
					gotoxy(42+5*cau, 7);
					cout << "B";
					SetColor(7);
					gotoxy(0,27);
				}else if(cau<67){
					SetColor(3);
					gotoxy(42+5*(cau-33), 9);
					cout << "B";
					SetColor(7);
					gotoxy(0,27);
				}else{
					SetColor(3);
					gotoxy(42+5*(cau-66), 11);
					cout << "B";
					SetColor(7);
					gotoxy(0,27);
				}
			}else if(k==RIGHT && checkPhim==true){
				if(cau<socauThi){
					cau++;
					goto trolai;
				}
			}else if(k==LEFT && checkPhim==true){
				if(cau>1){
					cau--;
					goto trolai;
				}
			}else if(k==F1 && checkPhim==true){
				if(Hoi(105,23,"Ban co chac chan muon nop bai khong?")==false){
					goto trolai;
				}else{
					gotoxy(44,5);
					XoaKhung(46, 162);
					break;
				}
			}
		}else if(wherey()==32 || wherey()==33){
			if(k==DOWN && checkPhim==true){
				gotoxy(60,31);
				VeKhung(4,133);
				HienThi(61,190,32,temp->boDe.C);
				SetColor(13);
				gotoxy(60,36);
				VeKhung(4,133);
				SetColor(7);
				HienThi(61,190,37,temp->boDe.D);
				ShowCur(0);
			}else if(k==UP && checkPhim==true){
				gotoxy(60,31);
				VeKhung(4,133);
				HienThi(61,190,32,temp->boDe.C);
				SetColor(13);
				gotoxy(60,26);
				VeKhung(4,133);
				SetColor(7);
				HienThi(61,190,27,temp->boDe.B);
				ShowCur(0);
			}else if(k==ENTER){
				if(temp->traLoi == 'A'){
					gotoxy(60,41);
					VeNut(" A ");
					gotoxy(80,41);
					VeNutMauChu(3, " C ");
					temp->traLoi='C';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,32,temp->boDe.C);
					ShowCur(0);
				}else if(temp->traLoi == 'B'){
					gotoxy(70,41);
					VeNut(" B ");
					gotoxy(80,41);
					VeNutMauChu(3, " C ");
					temp->traLoi='C';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,32,temp->boDe.C);
					ShowCur(0);
				}else if(temp->traLoi == 'D'){
					gotoxy(90,41);
					VeNut(" D ");
					gotoxy(80,41);
					VeNutMauChu(3, " C ");
					temp->traLoi='C';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,32,temp->boDe.C);
					ShowCur(0);
				}else{
					gotoxy(80,41);
					VeNutMauChu(3, " C ");
					temp->traLoi='C';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,32,temp->boDe.C);
					ShowCur(0);
				}
				if(cau<34){
					SetColor(3);
					gotoxy(42+5*cau, 7);
					cout << "C";
					SetColor(7);
					gotoxy(0,32);
				}else if(cau<67){
					SetColor(3);
					gotoxy(42+5*(cau-33), 9);
					cout << "C";
					SetColor(7);
					gotoxy(0,32);
				}else{
					SetColor(3);
					gotoxy(42+5*(cau-66), 11);
					cout << "C";
					SetColor(7);
					gotoxy(0,32);
				}
			}else if(k==RIGHT && checkPhim==true){
				if(cau<socauThi){
					cau++;
					goto trolai;	
				}	
			}else if(k==LEFT && checkPhim==true){
				if(cau>1){
					cau--;
					goto trolai;
				}
			}else if(k==F1 && checkPhim==true){
				if(Hoi(105,23,"Ban co chac chan muon nop bai khong?")==false){
					goto trolai;
				}else{
					gotoxy(44,5);
					XoaKhung(46, 162);
					break;
				}
			}
		}else if(wherey()==37 || wherey()==38){
			if(k==UP && checkPhim){
				gotoxy(60,36);
				VeKhung(4,133);
				HienThi(61,190,37,temp->boDe.D);
				SetColor(13);
				gotoxy(60,31);
				VeKhung(4,133);
				SetColor(7);
				HienThi(61,190,32,temp->boDe.C);
				ShowCur(0);
			}else if(k==ENTER){
				if(temp->traLoi == 'A'){
					gotoxy(60,41);
					VeNut(" A ");
					gotoxy(90,41);
					VeNutMauChu(3, " D ");
					temp->traLoi='D';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,37,temp->boDe.D);
					ShowCur(0);
				}else if(temp->traLoi == 'B'){
					gotoxy(70,41);
					VeNut(" B ");
					gotoxy(90,41);
					VeNutMauChu(3, " D ");
					temp->traLoi='D';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,37,temp->boDe.D);
					ShowCur(0);
				}else if(temp->traLoi == 'C'){
					gotoxy(80,41);
					VeNut(" C ");
					gotoxy(90,41);
					VeNutMauChu(3, " D ");
					temp->traLoi='D';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,37,temp->boDe.D);
					ShowCur(0);
				}else{
					gotoxy(90,41);
					VeNutMauChu(3, " D ");
					temp->traLoi='D';
					p->danhSachDeThi.dsdt[cau]=temp;
					HienThi(61,190,37,temp->boDe.D);
					ShowCur(0);
				}
				if(cau<34){
					SetColor(3);
					gotoxy(42+5*cau, 7);
					cout << "D";
					SetColor(7);
					gotoxy(0,37);
				}else if(cau<67){
					SetColor(3);
					gotoxy(42+5*(cau-33), 9);
					cout << "D";
					SetColor(7);
					gotoxy(0,37);
				}else{
					SetColor(3);
					gotoxy(42+5*(cau-66), 11);
					cout << "D";
					SetColor(7);
					gotoxy(0,37);
				}
			}else if(k==RIGHT && checkPhim==true){
				if(cau<socauThi){
					cau++;
					goto trolai;	
				}		
			}else if(k==LEFT && checkPhim==true){
				if(cau>1){
					cau--;
					goto trolai;
				}
			}else if(k==F1 && checkPhim==true){
				if(Hoi(105,23,"Ban co chac chan muon nop bai khong?")==false){
					goto trolai;
				}else{
					gotoxy(44,5);
					XoaKhung(46, 162);
					break;
				}
			}
		}
	}
	if(stop==0){
		clock.join();
		gotoxy(188,3);
		cout << "                  ";
		ThongBao(105,23,"Ban da het gio lam bai!");
		gotoxy(44,5);
		XoaKhung(46, 162);
		tinhDiem(p);
		themChiTietThi(pHead->danhSachChiTietThi.pHead,p);
		pHead->danhSachChiTietThi.soCTT++;
		themFileDeThiTheoLop(ds_lh);
		VeKhungBaoDiem();
		gotoxy(92,21);
		cout << p->soCauDung << "/"<< p->soCauThi;
		gotoxy(93,23);
		cout<< roundf(p->diem*10)/10;
		getch();
	}else{
		stop=0;
		clock.join();
		gotoxy(188,3);
		cout << "                  ";
		tinhDiem(p);
		themChiTietThi(pHead->danhSachChiTietThi.pHead,p);
		pHead->danhSachChiTietThi.soCTT++;
		themFileDeThiTheoLop(ds_lh);
		VeKhungBaoDiem();
		gotoxy(92,21);
		cout << p->soCauDung << "/"<< p->soCauThi;
		gotoxy(93,23);
		cout<< roundf(p->diem*10)/10;
		getch();
	}
	stop=1;
}
sinhVien *DangNhap(DS_LOP_HOC ds_lh, bool &check){
	ShowCur(0);
	clrscr();
	SetColor(8);
	gotoxy(182,0);
	cout << "HUYNH TUAN KIET - N19DCCN079";
	gotoxy(182,1);
	cout << "MAI VAN LOI - N19DCCN102";
	SetColor(9);
	gotoxy(36,5);
	cout << "__ __ __ __   _      _   _       __ __ __ __   _ __ _        _         _ _       __      _      __ __   _      _   _   __ __   __         __";
	gotoxy(35,6);
	cout << "|_ __   __ _| | |    | | | |     |_ __   __ _| |  __  |      | |       | __|     |  |    | |    | __  | | |    | | | | |  _ _| |  |       |  |";
	gotoxy(35,7);
	cout << "     | |      | |    | | | |          | |      | |__| |     | | |     | |        | | |   | |   | |  |_| | |    | | | | | |     | | |     | | |";
	gotoxy(35,8);
	cout << "     | |      | |____| | | |          | |      |  _ __|    | | | |   | |         | || |  | |  | |       | |____| | | | | |__   | || |   | || |";
	gotoxy(35,9);
	cout << "     | |      |  ____| | | |          | |      | | |      | |___| | | |          | | | | | | | |   _ _  |  ____| | | | |  __|  | | | | | | | |";
	gotoxy(35,10);  
	cout << "     | |      | |    | | | |          | |      | || |    | |_ _ _| | | |         | |  | || |  | | |_  | | |    | | | | | |     | |  | | |  | |";
	gotoxy(35,11);
	cout << "     | |      | |    | | | |          | |      | | | |  | |       | | | |__      | |   | | |   | |__| | | |    | | | | | |_ _  | |   |_|   | |";
	gotoxy(35,12);
	cout << "     |_|      |_|    |_| |_|          |_|      |_|  |_| |_|       |_|  |_ _|     |_|    |__|    |__ __| |_|    |_| |_| |__ __| |_|         |_|";
	SetColor(10);
	gotoxy(90,20);
	cout << "VUI LONG DANG NHAP:";
	VeKhungDN();
	SetColor(2);
	gotoxy(40, 35);
	cout <<"Huong dan:";
	gotoxy(3, 39);
	cout << "*Luu y:";
	SetColor(7);
	gotoxy(55, 35);
	cout <<"ESC: THOAT			UP: LEN			DOWN: XUONG			ENTER: CHON";
	gotoxy(11, 39);
	cout << "- Ten tai khoan gom cac chu cai in hoa va cac so tu 1 den 9 co do dai khong qua 20 ki tu";
	gotoxy(11, 40);
	cout << "- Mat khau gom chu cai va cac so tu 1 den 9 khong qua 15 ki tu";
	gotoxy(88,23);
	check=false;
	char s;
	bool checkPhim;
	string taiKhoan, matKhau;
	ShowCur(1);
	while((s=LayPhim(checkPhim))!=ESC){
		if(wherey() == 23){
			if(((s>96 && s<123) || (s>64 && s<91)) && checkPhim==false && taiKhoan.length()<20){
				cout << InHoa(s);
				taiKhoan+=InHoa(s);
			}else if(s>47 && s<58 && checkPhim==false && taiKhoan.length()<20){
				cout << s;
				taiKhoan+=s;
			}else if(s==BACKSPACE && taiKhoan.length()>0){
				XoaCuoi(taiKhoan);
				BackSpace();
			}else if(s == DOWN && checkPhim==true){
				gotoxy(87,22);
				VeKhung(3,40);
				gotoxy(88,23);
				cout << taiKhoan;
				SetColor(13);
				gotoxy(87,25);
				VeKhung(3,40);
				SetColor(7);
				gotoxy(88,26);
				for(int i=0; i<matKhau.length(); i++)
					cout << "*";
			}
		}else if(wherey() == 26){
			if(((s > 96 && s<123) || (s>64 && s<91) || (s>47 && s<58)) && checkPhim==false && matKhau.length()<15){
				cout << "*";
				matKhau+=s;
			}else if(s==BACKSPACE && matKhau.length()>0){
				XoaCuoi(matKhau);
				BackSpace();
			}else if(s == DOWN && checkPhim==true){
				gotoxy(87, 25);
				VeKhung(3,40);
				gotoxy(88,26);
				for(int i=0; i<matKhau.length(); i++)
					cout << "*";
				SetColor(13);
				gotoxy(95,29);
				VeNut("DANG NHAP");
				SetColor(7);
				ShowCur(0);	
			}else if(s == UP && checkPhim==true){
				SetColor(7);
				gotoxy(87, 25);
				VeKhung(3,40);
				gotoxy(88,26);
				for(int i=0; i<matKhau.length(); i++)
					cout << "*";
				SetColor(13);
				gotoxy(87,22);
				VeKhung(3,40);
				SetColor(7);
				gotoxy(88,23);
				cout << taiKhoan;
			}
		}else if(wherey() == 30){
			if(s == UP && checkPhim==true){
				SetColor(7);
				gotoxy(95,29);
				VeNut("DANG NHAP");
				SetColor(13);
				gotoxy(87, 25);
				VeKhung(3,40);
				SetColor(7);
				gotoxy(88,26);
				for(int i=0; i<matKhau.length(); i++)
					cout << "*";
				ShowCur(1);
			}else if(s==ENTER){
				if(taiKhoan.length() == 0 || matKhau.length() == 0){
					gotoxy(95,29);
					VeNut("DANG NHAP");
					BaoLoi(83, 23, "Vui long dien day du thong tin!");
					VeKhungDN();
					gotoxy(88, 26);
					for(int i=0; i< matKhau.length(); i++){
						cout << "*";
					}
					gotoxy(88,23);
					cout << taiKhoan;
					ShowCur(1);
				}else if(taiKhoan == "GV" && matKhau == "GV"){
					gotoxy(95,29);
					VeNut("DANG NHAP");
					ThongBao(87,24,"Dang Nhap Thanh Cong!");
					check=true;
					return NULL;
				}else{
					bool checkTK=false;
					for (int i=0;i<ds_lh.soLH;i++){
						sinhVien *p=ds_lh.dslh[i]->danhSachSinhVien.pHead;
						while(p!=NULL){
							if((p->maSV==taiKhoan) && (p->matKhau==matKhau)){
								gotoxy(95,29);
								VeNut("DANG NHAP");
								ThongBao(87,24,"Dang Nhap Thanh Cong!");
								checkTK=true;
								check=true;
								return p;
							}
							p=p->next;
						}
					}
					if (checkTK==false){
						gotoxy(95,29);
						VeNut("DANG NHAP");
						BaoLoi(77,23,"Tai khoan hoac mat khau khong chinh xac!");
						VeKhungDN();
						gotoxy(88, 26);
						for(int i=0; i< matKhau.length(); i++){
							cout << "*";
						}
						gotoxy(88,23);
						cout << taiKhoan;
						ShowCur(1);
					}
				}
			}
		}
	}
	gotoxy(0,40);
}

void NhapMH(DS_MON_HOC &ds_mh){
	tieptuc:
	VeKhungNhapMH();
	string mamh, tenmh;
	char k;
	bool checkPhim;
	while((k=LayPhim(checkPhim))!=ESC){
		if(wherey()==19){
			if(((k > 96 && k<123) || (k>64 && k<91)) && checkPhim==false && mamh.length()<15){
				cout << InHoa(k);
				mamh+=InHoa(k);
			}else if(k>47 && k<58 && checkPhim==false && mamh.length()<15){
				cout << k;
				mamh+=k;
			}else if(k==BACKSPACE && mamh.length()>0){
				XoaCuoi(mamh);
				BackSpace();
			}else if(k==DOWN && checkPhim==true){
				gotoxy(102, 18);
				VeKhung(3,60);
				gotoxy(103, 19);
				cout << mamh;
				SetColor(13);
				gotoxy(102,21);
				VeKhung(3,60);
				gotoxy(103,22);
				SetColor(7);
				cout << tenmh;
			}
		}else if(wherey()==22){
			if(((k > 96 && k<123) || (k>64 && k<91)) && checkPhim==false && tenmh.length()<50){
				cout << InHoa(k);
				tenmh+=InHoa(k);
			}else if(k>47 && k<58 && checkPhim==false && tenmh.length()<50){
				cout << k;
				tenmh+=k;
			}else if(k==SPACE && tenmh.length() >0 &&  tenmh.length()<50 && (tenmh[tenmh.length()-1]!=32)){
				cout << k;
				tenmh+=k;
			}else if(k==BACKSPACE && tenmh.length()>0){
				XoaCuoi(tenmh);
				BackSpace();
			}else if(k==DOWN && checkPhim==true){
				gotoxy(102,21);
				VeKhung(3,60);
				gotoxy(103,22);
				cout << tenmh;
				SetColor(13);
				gotoxy(150,24);
				VeNut(" OK ");
				SetColor(7);
				ShowCur(0);
			}else if(k==UP && checkPhim==true){
				gotoxy(102,21);
				VeKhung(3,60);
				gotoxy(103,22);
				cout << tenmh;
				SetColor(13);
				gotoxy(102, 18);
				VeKhung(3,60);
				SetColor(7);
				gotoxy(103, 19);
				cout << mamh;
			}
		}else if(wherey()==25){
			if(k==UP && checkPhim==true){
				gotoxy(150,24);
				VeNut(" OK ");
				SetColor(13);
				gotoxy(102,21);
				VeKhung(3,60);
				SetColor(7);
				gotoxy(103,22);
				cout << tenmh;
				ShowCur(1);
			}else if(k==ENTER){
				if(mamh.length() == 0 || tenmh.length() == 0){
					gotoxy(150,24);
					VeNut(" OK ");
					BaoLoi(88,17, "     Chua nhap ten mon hoc hoac ma mon hoc. Vui long nhap day du!    ");
					VeKhungNhapMH();
					gotoxy(103,22);
					cout << tenmh;
					gotoxy(103, 19);
					cout << mamh;
				}else if(kiemTraTonTaiMonHoc(mamh,ds_mh)!=-1){
					gotoxy(150,24);
					VeNut(" OK ");
					BaoLoi(96, 17, "     Ma mon hoc da ton tai. Vui long nhap lai!     ");
					VeKhungNhapMH();
					gotoxy(103,22);
					cout << tenmh;
					gotoxy(103, 19);
					cout << mamh;
				}else{
					gotoxy(150,24);
					VeNut(" OK ");
					MON_HOC *temp=new MON_HOC;
					temp->maMH = mamh;
					temp->tenMH = tenmh;
					ds_mh.dsmh[ds_mh.soMH]=temp;
					themFileMonHoc(ds_mh);
					ds_mh.soMH++;
					ThongBao(107,19,"     Them mon hoc thanh cong!     ");
					goto tieptuc;
				}
			}
		}
	}
}


void InDSMH(int x, int y, DS_MON_HOC ds_mh){
	VeKhungInDSMH(x, y, ds_mh.soMH);
	for (int i=0;i<ds_mh.soMH;i++){
		gotoxy(x+1, y+3+i);
		cout << ds_mh.dsmh[i]->maMH;
		gotoxy(x+20, y+3+i);
		cout << ds_mh.dsmh[i]->tenMH;
	}
	ShowCur(0);
}

void XoaMonHoc(DS_MON_HOC &ds_mh){
	if (ds_mh.soMH==0){
		BaoLoi(105, 18, "Danh sach hien dang rong. Khong xoa duoc!");
	}else{
		tieptuc:
		gotoxy(50, 8);
		XoaKhung(ds_mh.soMH + 5, 77);
		InDSMH(50, 8, ds_mh);
		SetColor(10);
		gotoxy(141, 8);
		cout << "NHAP MA MON HOC CAN XOA VA AN ENTER DE TIEP TUC!";
		SetColor(13);
		gotoxy(140,9);
		VeKhung(3,50);
		SetColor(7);
		gotoxy(141,10);
		ShowCur(1);
		string mamh;
		char k;
		bool checkPhim;
		while((k=LayPhim(checkPhim))!=ESC){
			if(((k > 96 && k<123) || (k>64 && k<91)) && checkPhim==false && mamh.length()<15){
				cout << InHoa(k);
				mamh+=InHoa(k);
			}else if((k>47 && k<58) && checkPhim==false && mamh.length()<15){
				cout << k;
				mamh+=k;
			}else if(k==BACKSPACE && mamh.length()>0){
				XoaCuoi(mamh);
				BackSpace();
			}else if(k==ENTER){
				if(mamh.length() == 0){
					SetColor(7);
					gotoxy(140,9);
					VeKhung(3,50);
					BaoLoi(150, 15, "Vui long nhap day du!");
					SetColor(13);
					gotoxy(140,9);
					VeKhung(3,50);
					gotoxy(141,10);
					SetColor(7);
					cout << mamh;
					ShowCur(1);
				}else{
					int viTriXoa=kiemTraTonTaiMonHoc(mamh,ds_mh);
					if (viTriXoa==-1){
						SetColor(7);
						gotoxy(140,9);
						VeKhung(3,50);
						gotoxy(141,10);
						cout << mamh;
						BaoLoi(150, 15, "Ma mon hoc khong ton tai!");
						SetColor(13);
						gotoxy(140,9);
						VeKhung(3,50);
						SetColor(7);
						gotoxy(141,10);
						cout << mamh;
						ShowCur(1);
					}else{
						SetColor(7);
						gotoxy(140,9);
						VeKhung(3,50);
						gotoxy(141,10);
						cout << mamh;
						if(Hoi(145, 15, " Ban chan chan muon xoa mon hoc? ")==true){
							for (int i=viTriXoa;i<ds_mh.soMH-1;i++){
								ds_mh.dsmh[i]->maMH=ds_mh.dsmh[i+1]->maMH;
								ds_mh.dsmh[i]->tenMH=ds_mh.dsmh[i+1]->tenMH;
							}
							MON_HOC *temp=ds_mh.dsmh[ds_mh.soMH-1];
							ds_mh.soMH--;
							hieuChinhFileMonHoc(ds_mh);
							ThongBao(150, 15, " Xoa mon hoc thanh cong! ");
							if(ds_mh.soMH>0)
								goto tieptuc;
							else break;
							
						}else{
							SetColor(7);
							gotoxy(140,9);
							VeKhung(3,50);
							gotoxy(141,10);
							cout << mamh;
							ThongBao(150, 15, "  Xoa mon hoc that bai!  ");
							SetColor(13);
							gotoxy(140,9);
							VeKhung(3,50);
							SetColor(7);
							gotoxy(141,10);
							cout << mamh;
							ShowCur(1);
						}
					}
				}
			}
		}	
	}
}

void HieuChinhMonHoc(DS_MON_HOC &ds_mh, DS_CAU_HOI ds_ch){
	if (ds_mh.soMH==0){
		BaoLoi(100, 18, "Danh sach hien dang rong. Khong hieu chinh duoc!");
	}else{
		tieptuc:
		gotoxy(50, 8);
		XoaKhung(ds_mh.soMH + 5, 77);
		InDSMH(50, 8, ds_mh);
		VeKhungHieuChinhMH();
		string mamhCu, mamhMoi, tenmhMoi;
		char k;
		bool checkPhim;
		while((k=LayPhim(checkPhim))!=ESC){
			if(wherey()==12){
				if(((k > 96 && k<123) || (k>64 && k<91)) && checkPhim==false && mamhCu.length()<15){
					cout << InHoa(k);
					mamhCu+=InHoa(k);
				}else if((k>47 && k<58) && checkPhim==false && mamhCu.length()<15){
					cout << k;
					mamhCu+=k;
				}else if(k==BACKSPACE && mamhCu.length()>0){
					XoaCuoi(mamhCu);
					BackSpace();
				}else if(k==DOWN && checkPhim==true){
					gotoxy(143,11);
					VeKhung(3,54);
					gotoxy(144, 12);
					cout << mamhCu;
					SetColor(13);
					gotoxy(143, 16);
					VeKhung(3,54);
					SetColor(7);
					gotoxy(144,17);
					cout << mamhMoi;
				}
			}else if(wherey()==17){
				if(((k > 96 && k<123) || (k>64 && k<91)) && checkPhim==false && mamhMoi.length()<15){
					cout << InHoa(k);
					mamhMoi+=InHoa(k);
				}else if((k>47 && k<58) && checkPhim==false && mamhMoi.length()<15){
					cout << k;
					mamhMoi+=k;
				}else if(k==BACKSPACE && mamhMoi.length()>0){
					XoaCuoi(mamhMoi);
					BackSpace();
				}else if(k==DOWN && checkPhim==true){
					gotoxy(143, 16);
					VeKhung(3,54);
					gotoxy(144,17);
					cout << mamhMoi;
					SetColor(13);
					gotoxy(143, 20);
					VeKhung(3,54);
					SetColor(7);
					gotoxy(144,21);
					cout << tenmhMoi;
				}else if(k==UP && checkPhim==true){
					gotoxy(143, 16);
					VeKhung(3,54);
					gotoxy(144,17);
					cout << mamhMoi;
					SetColor(13);
					gotoxy(143,11);
					VeKhung(3,54);
					SetColor(7);
					gotoxy(144, 12);
					cout << mamhCu;
				}
			}else if(wherey()==21){
				if(((k > 96 && k<123) || (k>64 && k<91)) && checkPhim==false && tenmhMoi.length()<50){
					cout << InHoa(k);
					tenmhMoi+=InHoa(k);
				}else if((k>47 && k<58) && checkPhim==false && tenmhMoi.length()<50){
					cout << k;
					tenmhMoi+=k;
				}else if(k==SPACE && tenmhMoi.length()>0 && tenmhMoi.length()<50 && (tenmhMoi[tenmhMoi.length()-1]!=32)) {
					cout << k;
					tenmhMoi+=k;
				}else if(k==BACKSPACE && tenmhMoi.length()>0){
					XoaCuoi(tenmhMoi);
					BackSpace();
				}else if(k==DOWN && checkPhim==true){
					gotoxy(143, 20);
					VeKhung(3,54);
					gotoxy(144,21);
					cout << tenmhMoi;
					SetColor(13);
					gotoxy(185, 23);
					VeNut(" OK ");
					SetColor(7);
					ShowCur(0);
				}else if(k==UP && checkPhim==true){
					gotoxy(143, 20);
					VeKhung(3,54);
					gotoxy(144,21);
					cout << tenmhMoi;
					SetColor(13);
					gotoxy(143, 16);
					VeKhung(3,54);
					SetColor(7);
					gotoxy(144,17);
					cout << mamhMoi;
				}
			}else if(wherey()==24){
				if(k==UP && checkPhim==true){
					gotoxy(185, 23);
					VeNut(" OK ");
					SetColor(13);
					gotoxy(143, 20);
					VeKhung(3,54);
					SetColor(7);
					gotoxy(144,21);
					cout << tenmhMoi;
					ShowCur(1);
				}else if(k==ENTER){
					int n=0;
					kiemTraSoLuongCauHoi(ds_ch.dsch,n,mamhCu);
					if(mamhCu.length()==0 || mamhMoi.length()==0 || tenmhMoi.length()==0){
						gotoxy(185, 23);
						VeNut(" OK ");
						BaoLoi(150, 29, "Vui long dien day du thong tin!");
						VeKhungHieuChinhMH();
						gotoxy(144,21);
						cout << tenmhMoi;
						gotoxy(144,17);
						cout << mamhMoi;
						gotoxy(144, 12);
						cout << mamhCu;
					}else if(n!=0){
						gotoxy(185, 23);
						VeNut(" OK ");
						BaoLoi(140, 29, "Da nhap cau hoi cho mon hoc nay.Khong the hieu chinh!");
						VeKhungHieuChinhMH();
						gotoxy(144,21);
						cout << tenmhMoi;
						gotoxy(144,17);
						cout << mamhMoi;
						gotoxy(144, 12);
						cout << mamhCu;
					}else{
						int viTriHieuChinh=kiemTraTonTaiMonHoc(mamhCu,ds_mh);
						int j = kiemTraTonTaiMonHoc(mamhMoi,ds_mh);
						if (viTriHieuChinh==-1){
							gotoxy(185, 23);
							VeNut(" OK ");
							BaoLoi(155,29,"Ma mon hoc khong ton tai!");
							VeKhungHieuChinhMH();
							gotoxy(144,21);
							cout << tenmhMoi;
							gotoxy(144,17);
							cout << mamhMoi;
							gotoxy(144, 12);
							cout << mamhCu;
						}else if(j!=-1 && (mamhMoi!=mamhCu)){
							gotoxy(185, 23);
							VeNut(" OK ");
							BaoLoi(154,29,"Ma mon hoc moi bi trung!");
							VeKhungHieuChinhMH();
							gotoxy(144,21);
							cout << tenmhMoi;
							gotoxy(144,17);
							cout << mamhMoi;
							gotoxy(144, 12);
							cout << mamhCu;
						}else{
							gotoxy(185, 23);
							VeNut(" OK ");
							if(Hoi(147,29,"Ban co chac chan muon hieu chinh mon hoc?")==true){
								ds_mh.dsmh[viTriHieuChinh]->maMH=mamhMoi;
								ds_mh.dsmh[viTriHieuChinh]->tenMH=tenmhMoi;
								hieuChinhFileMonHoc(ds_mh);
								ThongBao(152,29,"Hieu chinh mon hoc thanh cong!");
								goto tieptuc;
							}else{
								ThongBao(153,29,"Hieu chinh mon hoc that bai!");
								VeKhungHieuChinhMH();
								gotoxy(144,21);
								cout << tenmhMoi;
								gotoxy(144,17);
								cout << mamhMoi;
								gotoxy(144, 12);
								cout << mamhCu;
							}
						}
					}
				}
			}
		}
	}
}

void NhapLopHoc(DS_LOP_HOC &ds_lh){
	tieptuc:
	gotoxy(85,30);
	cout << "Luu y: - Ma lop chi gom cac chu cai in hoa va khong qua 15 ki tu";
	gotoxy(92,31);
	cout << "- Ten lop gom cac chu cai in hoa va khoang trang co do dai khong qua 50 ki tu";
	VeKhungNhapLop();
	char k;
	bool checkP;
	string malop, tenlop;
	while((k=LayPhim(checkP))!=ESC){
		if(wherey()==(19)){
			if(((k > 96 && k<123) || (k>64 && k<91)) && checkP==false && malop.length()<15){
				cout << InHoa(k);
				malop+=InHoa(k);
			}else if(k>47 && k<58 && checkP==false && malop.length()<15){
				cout << k;
				malop+=k;
			}else if(k==BACKSPACE && malop.length()>0){
				XoaCuoi(malop);
				BackSpace();
			}else if(k==DOWN && checkP==true){
				gotoxy(102, 18);
				VeKhung(3,60);
				gotoxy(103, 19);
				cout << malop;
				SetColor(13);
				gotoxy(102,21);
				VeKhung(3,60);
				gotoxy(103,22);
				SetColor(7);
				cout << tenlop;
			}
		}else if(wherey()==22){
			if(((k > 96 && k<123) || (k>64 && k<91)) && checkP==false && tenlop.length()<50){
				cout << InHoa(k);
				tenlop+=InHoa(k);
			}else if((k>47 && k<58) && checkP==false && tenlop.length()<50){
				cout << k;
				tenlop+=k;
			}else if(k==32 && tenlop.length()>0 && tenlop.length()<50 && (tenlop[tenlop.length()-1]!=32)){
				cout << k;
				tenlop+=k;
			}else if(k==BACKSPACE && tenlop.length()>0){
				XoaCuoi(tenlop);
				BackSpace();
			}else if(k==DOWN && checkP==true){
				gotoxy(102,21);
				VeKhung(3,60);
				gotoxy(103,22);
				cout << tenlop;
				SetColor(13);
				gotoxy(122,24);
				VeNut("  OK  ");
				SetColor(7);
				ShowCur(0);
			}else if(k==UP && checkP==true){
				gotoxy(102,21);
				VeKhung(3,60);
				gotoxy(103,22);
				cout << tenlop;
				SetColor(13);
				gotoxy(102, 18);
				VeKhung(3,60);
				SetColor(7);
				gotoxy(103, 19);
				cout << malop;
			}
		}else if(wherey()==25){
			if(k==UP && checkP==true){
				gotoxy(122,24);
				VeNut("  OK  ");
				SetColor(13);
				gotoxy(102,21);
				VeKhung(3,60);
				SetColor(7);
				gotoxy(103,22);
				cout << tenlop;
				ShowCur(1);
			}else if(k==ENTER){
				LOP_HOC *temp=new LOP_HOC;
				temp->maLH=malop;
				temp->tenLH=tenlop;
				if(malop.length() == 0 || tenlop.length() == 0){
					gotoxy(122,24);
					VeNut("  OK  ");
					BaoLoi(93,17, "     Chua nhap ten lop hoac ma lop. Vui long nhap day du!    ");
					VeKhungNhapLop();
					gotoxy(103,22);
					cout << tenlop;
					gotoxy(103, 19);
					cout << malop;
				}else if(kiemTraTonTaiLopHoc(temp->maLH,ds_lh)!=-1){
					gotoxy(122,24);
					VeNut("  OK  ");
					BaoLoi(95,17,"     Ma lop hoc da ton tai. Vui long nhap lai!     ");
					VeKhungNhapLop();
					gotoxy(103,22);
					cout << tenlop;
					gotoxy(103, 19);
					cout << malop;
				}else{
					gotoxy(122,24);
					VeNut("  OK  ");
					ds_lh.dslh[ds_lh.soLH]=temp;
					themFileLopHoc(ds_lh);
					ds_lh.soLH++;
					ThongBao(103,19,"        Them lop hoc thanh cong       ");
					goto tieptuc;
				}
			}
		}
	}
	gotoxy(85,30);
	cout << "                                                                        ";
	gotoxy(92,31);
	cout << "                                                                                  ";
}

void InDSLopHoc(int x, int y, DS_LOP_HOC ds_lh){
	VeKhungInDSLop(x, y, ds_lh.soLH);
	for (int i=0;i<ds_lh.soLH;i++)
	{
		gotoxy(x+1, y+3+i);
		cout << ds_lh.dslh[i]->maLH;
		gotoxy(x+20, y+3+i);
		cout << ds_lh.dslh[i]->tenLH;
		gotoxy(x+75, y+3+i);
		cout << ds_lh.dslh[i]->danhSachSinhVien.soSV;
	}
	ShowCur(0);
}

void NhapSV(DS_LOP_HOC &ds_lh){
	nhaplai:
	InDSLopHoc(85, 15, ds_lh);	
	VeKhungNhapMaLop();
	string malop;
	int i;
	char k;
	bool checkPhim;
	while((k=LayPhim(checkPhim))){
		if(((k > 96 && k<123) || (k>64 && k<91)) && checkPhim==false && malop.length()<15){
			cout << InHoa(k);
			malop+= InHoa(k);
		}else if((k>47 && k<58) && checkPhim==false && malop.length()<15){
			cout << k;
			malop+=k;
		}else if(k==BACKSPACE && malop.length()>0){
				XoaCuoi(malop);
				BackSpace();
		}else if(k==ENTER){
			i = kiemTraTonTaiLopHoc(malop,ds_lh);
			if(malop.length() == 0){
				gotoxy(100,9);
				VeKhung(3,50);
				gotoxy(101,10);
				cout << malop;
				BaoLoi(103,20, "          Vui long nhap ma lop!          ");
				InDSLopHoc(85, 15, ds_lh);	
				VeKhungNhapMaLop();
				gotoxy(101,10);
				cout << malop;
			}else if(i==-1){
				gotoxy(100,9);
				VeKhung(3,50);
				gotoxy(101,10);
				cout << malop;
				BaoLoi(105,20,"     Ma lop hoc khong ton tai!     ");
				InDSLopHoc(85, 15, ds_lh);	
				VeKhungNhapMaLop();
				gotoxy(101,10);
				cout << malop;
			}else{
				gotoxy(85,15);
				XoaKhung(ds_lh.soLH +5, 83);
				break;
			}
		}else if(k==ESC)
			return ;
	}
	tieptuc:
	VeKhungNhapSV();
	string masv, ho, ten,phai, pass;
	while((k=LayPhim(checkPhim))!=ESC){
		if(wherey()==18){
			if(((k > 96 && k<123) || (k>64 && k<91)) && checkPhim==false && masv.length()<15){
				cout << InHoa(k);
				masv+= InHoa(k);
			}else if((k>47 && k<58) && checkPhim==false && masv.length()<15){
				cout << k;
				masv+=k;
			}else if(k==BACKSPACE && masv.length()>0){
				XoaCuoi(masv);
				BackSpace();
			}else if(k==DOWN && checkPhim==true){
				gotoxy(102,17);
				VeKhung(3,60);
				gotoxy(103,18);
				cout << masv;
				SetColor(13);
				gotoxy(102,20);
				VeKhung(3,60);
				SetColor(7);
				gotoxy(103,21);
				cout << ho;
			}
		}else if(wherey()==21){
			if(((k > 96 && k<123) || (k>64 && k<91)) && checkPhim==false && ho.length()<15){
				cout << InHoa(k);
				ho+= InHoa(k);
			}else if(k==BACKSPACE && ho.length()>0){
				XoaCuoi(ho);
				BackSpace();
			}else if(k==DOWN && checkPhim==true){
				gotoxy(102,20);
				VeKhung(3,60);
				gotoxy(103,21);
				cout << ho;
				SetColor(13);
				gotoxy(102,23);
				VeKhung(3,60);
				SetColor(7);
				gotoxy(103,24);
				cout << ten;
			}else if(k==UP && checkPhim==true){
				gotoxy(102,20);
				VeKhung(3,60);
				gotoxy(103,21);
				cout << ho;
				SetColor(13);
				gotoxy(102,17);
				VeKhung(3,60);
				SetColor(7);
				gotoxy(103,18);
				cout << masv;
			}
		}else if(wherey()==24){
			if(((k > 96 && k<123) || (k>64 && k<91)) && checkPhim==false && ten.length()<30){
				cout << InHoa(k);
				ten+= InHoa(k);
			}else if(k==BACKSPACE && ten.length()>0){
				XoaCuoi(ten);
				BackSpace();
			}else if(k==32 && ten.length() >0 &&  ten.length()<30 && (ten[ten.length()-1]!=32)){
				cout << k;
				ten+=k;
			}else if(k==DOWN && checkPhim==true){
				if(phai=="NAM" || phai.length()==0){
					gotoxy(102,23);
					VeKhung(3,60);
					gotoxy(103,24);
					cout << ten;
					SetColor(13);
					gotoxy(102,26);
					VeNutMauChu(3, "NAM");
					phai="NAM";
					SetColor(7);
					ShowCur(0);
				}else if(phai=="NU"){
					gotoxy(102,23);
					VeKhung(3,60);
					gotoxy(103,24);
					cout << ten;
					SetColor(13);
					gotoxy(112,26);
					VeNutMauChu(3,"NU");
					SetColor(7);
					ShowCur(0);
				}
			}else if(k==UP && checkPhim==true){
				gotoxy(102,23);
				VeKhung(3,60);
				gotoxy(103,24);
				cout << ten;
				SetColor(13);
				gotoxy(102,20);
				VeKhung(3,60);
				SetColor(7);
				gotoxy(103,21);
				cout << ho;
			}
		}else if(wherey()==27){
			if(k==RIGHT && checkPhim==true && phai=="NAM"){
				gotoxy(102,26);
				VeNut("NAM");
				SetColor(13);
				gotoxy(112,26);
				VeNutMauChu(3,"NU");
				SetColor(7);
				phai="NU";
			}else if(k==LEFT && checkPhim==true && phai=="NU"){
				gotoxy(112,26);
				VeNut("NU");
				SetColor(13);
				gotoxy(102,26);
				VeNutMauChu(3,"NAM");
				phai="NAM";
			}else if(k==DOWN && checkPhim==true){
				if(phai=="NAM"){
					gotoxy(102,26);
					VeNutMauChu(3,"NAM");
					SetColor(13);
					gotoxy(102,29);
					VeKhung(3,60);
					SetColor(7);
					gotoxy(103,30);
					cout << pass;
					ShowCur(1);
				}else if(phai=="NU"){
					gotoxy(112,26);
					VeNutMauChu(3,"NU");
					SetColor(13);
					gotoxy(102,29);
					VeKhung(3,60);
					SetColor(7);
					gotoxy(103,30);
					cout << pass;
					ShowCur(1);
				}
			}else if(k==UP && checkPhim==true){
				if(phai=="NAM"){
					gotoxy(102,26);
					VeNutMauChu(3,"NAM");
					SetColor(13);
					gotoxy(102,23);
					VeKhung(3,60);
					SetColor(7);
					gotoxy(103,24);
					cout << ten;
					ShowCur(1);
				}else if(phai=="NU"){
					gotoxy(112,26);
					VeNutMauChu(3,"NU");
					SetColor(13);
					gotoxy(102,23);
					VeKhung(3,60);
					SetColor(7);
					gotoxy(103,24);
					cout << ten;
					ShowCur(1);
				}
			}
		}else if(wherey()==30){
			if(((k > 96 && k<123) || (k>64 && k<91)) && checkPhim==false && pass.length()<15){
				cout << k;
				pass += k;
			}else if((k>47 && k<58) && checkPhim==false && pass.length()<15){
				cout << k;
				pass+=k;
			}else if(k==BACKSPACE && pass.length()>0){
				XoaCuoi(pass);
				BackSpace();
			}else if(k==DOWN && checkPhim==true){
				gotoxy(102,29);
				VeKhung(3,60);
				gotoxy(103,30);
				cout << pass;
				SetColor(13);
				ShowCur(0);
				gotoxy(150,32);
				VeNut(" OK ");
				SetColor(7);
			}else if(k==UP && checkPhim==true){
				if(phai=="NAM"){
					gotoxy(102,29);
					VeKhung(3,60);
					gotoxy(103,30);
					cout << pass;
					SetColor(13);
					gotoxy(102,26);
					VeNutMauChu(3,"NAM");
					SetColor(7);
					ShowCur(0);
				}else if(phai=="NU"){
					gotoxy(102,29);
					VeKhung(3,60);
					gotoxy(103,30);
					cout << pass;
					SetColor(13);
					gotoxy(112,26);
					VeNutMauChu(3,"NU");
					SetColor(7);
					ShowCur(0);
				}
			}
		}else if(wherey()==33){
			if(k==UP && checkPhim==true){
				gotoxy(150,32);
				VeNut(" OK ");
				SetColor(13);
				gotoxy(102,29);
				VeKhung(3,60);
				SetColor(7);
				gotoxy(103,30);
				cout << pass;
				ShowCur(1);
			}else if(k==ENTER){
				if(masv.length() == 0 || ho.length() == 0 || ten.length() == 0 || phai.length() == 0 || pass.length() == 0){
					gotoxy(150,32);
					VeNut(" OK ");
					BaoLoi(103,20, "     Vui long dien day du thong tin!     ");
					VeKhungNhapSV();
					gotoxy(103,30);
					cout << pass;
					if(phai=="NAM"){
						gotoxy(102,26);
						VeNutMauChu(3,"NAM");
					}else if(phai=="NU"){
						gotoxy(112,26);
						VeNutMauChu(3,"NU");
					}
					gotoxy(103,24);
					cout << ten;
					gotoxy(103,21);
					cout << ho;
					gotoxy(103,18);
					cout << masv;
				}else{
					gotoxy(150,32);
					VeNut(" OK ");
					SINH_VIEN sv;
					sv.maSV = masv;
					sv.hoSV = ho;
					sv.tenSV = ten;
					sv.gioiTinh = phai;
					sv.matKhau = pass;
					themSinhVien(ds_lh.dslh[i]->danhSachSinhVien.pHead,sv);	
					ds_lh.dslh[i]->danhSachSinhVien.soSV++;
					themFileSinhVienTheoLop(ds_lh);
					themFileDeThiTheoLop(ds_lh);
					ThongBao(105,20, "     Them sinh vien thanh cong!     ");
					goto tieptuc;
				} 
			}
		}
	}
	gotoxy(85,14);
	XoaKhung(22,80);
	goto nhaplai;
}


void NhapCauHoi(DS_CAU_HOI &ds_ch, DS_MON_HOC ds_mh){
	tieptuc:
	VeKhungNhapCauHoi();
	string mamh, noidungch, daa, dab, dac, dad;
	char kq='A';
	char k;
	bool checkPhim;
	while((k=LayPhim(checkPhim))!=ESC){
		if(wherey()==11){
			if(((k > 96 && k<123) || (k>64 && k<91)) && checkPhim==false && mamh.length()<15){
				cout << InHoa(k);
				mamh += InHoa(k);
			}else if((k>47 && k<58) && checkPhim==false && mamh.length()<15){
				cout << k;
				mamh+=k;
			}else if(k==BACKSPACE && mamh.length()>0){
				XoaCuoi(mamh);
				BackSpace();
			}else if(k==DOWN && checkPhim==true){
				gotoxy(70,10);
				VeKhung(3,60);
				gotoxy(71,11);
				cout << mamh;
				SetColor(13);
				gotoxy(60,15);
				VeKhung(5,133);
				SetColor(7);
				HienThi(61,190,16,noidungch);
			}
		}else if(wherey()==16 || wherey()==17 || wherey()==18){
			if(((k > 96 && k<123) || (k>64 && k<91) || (k>47 && k<58)) && checkPhim==false && noidungch.length()<350){
				noidungch+=k;
				HienThi(61,190,16,noidungch);
			}else if(k==BACKSPACE && noidungch.length() >0){
				if(wherex()==61){
					XoaCuoi(noidungch);
					HienThi(61,190,16,noidungch);
				}else{
					XoaCuoi(noidungch);
					BackSpace();
				}
			}else if(k==SPACE && noidungch.length() >0 && noidungch.length() < 350 && (noidungch[noidungch.length()-1]!=32)){
				noidungch+=k;
				HienThi(61,190,16,noidungch);
			}else if(k==DOWN && checkPhim==true){
				gotoxy(60,15);
				VeKhung(5,133);
				HienThi(61,190,16,noidungch);
				SetColor(13);
				gotoxy(60,21);
				VeKhung(4,133);
				SetColor(7);
				HienThi(61,190,22,daa);
		    }else if(k==UP && checkPhim==true){
				gotoxy(60,15);
				VeKhung(5,133);
				HienThi(61,190,16,noidungch);
				SetColor(13);
				gotoxy(70,10);
				VeKhung(3,60);
				SetColor(7);
				gotoxy(71,11);
				cout << mamh;
			}
		}else if(wherey()==22 || wherey()==23){
			if(((k > 96 && k<123) || (k>64 && k<91) || (k>47 && k<58)) && checkPhim==false && daa.length()<240){
				daa+=k;
				HienThi(61,190,22,daa);
			}else if(k==BACKSPACE && daa.length() >0){
				if(wherex()==61){
					XoaCuoi(daa);
					HienThi(61,190,22,daa);
				}else{
					XoaCuoi(daa);
					BackSpace();
				}
			}else if(k==SPACE && daa.length() >0 && daa.length() < 240 && (daa[daa.length()-1]!=32)){
				daa+=k;
				HienThi(61,190,22,daa);
			}else if(k==DOWN && checkPhim==true){
				gotoxy(60,21);
				VeKhung(4,133);
				HienThi(61,190,22,daa);
				SetColor(13);
				gotoxy(60,26);
				VeKhung(4,133);
				SetColor(7);
				HienThi(61,190,27,dab);
		    }else if(k==UP && checkPhim==true){
				gotoxy(60,21);
				VeKhung(4,133);
				HienThi(61,190,22,daa);
				SetColor(13);
				gotoxy(60,15);
				VeKhung(5,133);
				SetColor(7);
				HienThi(61,190,16,noidungch);
			}
		}else if(wherey()==27 || wherey()==28){
			if(((k > 96 && k<123) || (k>64 && k<91) || (k>47 && k<58)) && checkPhim==false && dab.length()<240){
				dab+=k;
				HienThi(61,190,27,dab);
			}else if(k==BACKSPACE && dab.length() >0){
				if(wherex()==61){
					XoaCuoi(dab);
					HienThi(61,190,27,dab);
				}else{
					XoaCuoi(dab);
					BackSpace();
				}
			}else if(k==SPACE && dab.length() >0 && dab.length() < 240 && (dab[dab.length()-1]!=32)){
				dab+=k;
				HienThi(61,190,27,dab);
			}else if(k==DOWN && checkPhim==true){
				gotoxy(60,26);
				VeKhung(4,133);
				HienThi(61,190,27,dab);
				SetColor(13);
				gotoxy(60,31);
				VeKhung(4,133);
				SetColor(7);
				HienThi(61,190,32,dac);
		    }else if(k==UP && checkPhim==true){
				gotoxy(60,26);
				VeKhung(4,133);
				HienThi(61,190,27,dab);
				SetColor(13);
				gotoxy(60,21);
				VeKhung(4,133);
				SetColor(7);
				HienThi(61,190,22,daa);
			}
		}else if(wherey()==32 || wherey()==33){
			if(((k > 96 && k<123) || (k>64 && k<91) || (k>47 && k<58)) && checkPhim==false && dac.length()<240){
				dac+=k;
				HienThi(61,190,32,dac);
			}else if(k==BACKSPACE && dac.length() >0){
				if(wherex()==61){
					XoaCuoi(dac);
					HienThi(61,190,32,dac);
				}else{
					XoaCuoi(dac);
					BackSpace();
				}
			}else if(k==SPACE && dac.length() >0 && dac.length() < 240 && (dac[dac.length()-1]!=32)){
				dac+=k;
				HienThi(61,190,32,dac);
			}else if(k==DOWN && checkPhim==true){
				gotoxy(60,31);
				VeKhung(4,133);
				HienThi(61,190,32,dac);
				SetColor(13);
				gotoxy(60,36);
				VeKhung(4,133);
				SetColor(7);
				HienThi(61,190,37,dad);
		    }else if(k==UP && checkPhim==true){
				gotoxy(60,31);
				VeKhung(4,133);
				HienThi(61,190,32,dac);
				SetColor(13);
				gotoxy(60,26);
				VeKhung(4,133);
				SetColor(7);
				HienThi(61,190,27,dab);
			}
		}else if(wherey()==37 || wherey()==38){
			if(((k > 96 && k<123) || (k>64 && k<91) || (k>47 && k<58)) && checkPhim==false && dad.length()<240){
				dad+=k;
				HienThi(61,190,37,dad);
			}else if(k==BACKSPACE && dad.length() >0){
				if(wherex()==61){
					XoaCuoi(dad);
					HienThi(61,190,37,dad);
				}else{
					XoaCuoi(dad);
					BackSpace();
				}
			}else if(k==SPACE && dad.length() >0 && dad.length() < 240 && (dad[dad.length()-1]!=32)){
				dad+=k;
				HienThi(61,190,37,dad);
			}else if(k==DOWN && checkPhim==true){
				if(kq=='A'){
					gotoxy(60,36);
					VeKhung(4,133);
					HienThi(61,190,37,dad);
					SetColor(13);
					gotoxy(60,41);
					VeNutMauChu(3," A ");
					SetColor(7);
					ShowCur(0);
				}else if(kq=='B'){
					gotoxy(60,36);
					VeKhung(4,133);
					HienThi(61,190,37,dad);
					SetColor(13);
					gotoxy(70,41);
					VeNutMauChu(3," B ");
					SetColor(7);
					ShowCur(0);
				}else if(kq=='C'){
					gotoxy(60,36);
					VeKhung(4,133);
					HienThi(61,190,37,dad);
					SetColor(13);
					gotoxy(80,41);
					VeNutMauChu(3," C ");
					SetColor(7);
					ShowCur(0);
				}else if(kq=='D'){
					gotoxy(60,36);
					VeKhung(4,133);
					HienThi(61,190,37,dad);
					SetColor(13);
					gotoxy(90,41);
					VeNutMauChu(3," D ");
					SetColor(7);
					ShowCur(0);
				}
		    }else if(k==UP && checkPhim==true){
				gotoxy(60,36);
				VeKhung(4,133);
				HienThi(61,190,37,dad);
				SetColor(13);
				gotoxy(60,31);
				VeKhung(4,133);
				SetColor(7);
				HienThi(61,190,32,dac);
			}
		}else if(wherey()==42){
			if(k==RIGHT && checkPhim==true){
				if(kq=='A'){
					gotoxy(60,41);
					VeNut(" A ");
					SetColor(13);
					gotoxy(70,41);
					VeNutMauChu(3," B ");
					kq='B';
					SetColor(7);
				}else if(kq=='B'){
					gotoxy(70,41);
					VeNut(" B ");
					SetColor(13);
					gotoxy(80,41);
					VeNutMauChu(3," C ");
					kq='C';
					SetColor(7);
				}else if(kq=='C'){
					gotoxy(80,41);
					VeNut(" C ");
					SetColor(13);
					gotoxy(90,41);
					VeNutMauChu(3," D ");
					kq='D';
					SetColor(7);
				}
			}else if(k==LEFT && checkPhim==true){
				if(kq=='D'){
					gotoxy(90,41);
					VeNut(" D ");
					SetColor(13);
					gotoxy(80,41);
					VeNutMauChu(3," C ");
					kq='C';
					SetColor(7);
				}else if(kq=='C'){
					gotoxy(80,41);
					VeNut(" C ");
					SetColor(13);
					gotoxy(70,41);
					VeNutMauChu(3," B ");
					kq='B';
					SetColor(7);
				}else if(kq=='B'){
					gotoxy(70,41);
					VeNut(" B ");
					SetColor(13);
					gotoxy(60,41);
					VeNutMauChu(3," A ");
					kq='A';
					SetColor(7);
				}
			}else if(k==DOWN && checkPhim==true){
				if(kq=='A'){
					gotoxy(60,41);
					VeNutMauChu(3," A ");
					SetColor(13);
					gotoxy(180,42);
					VeNut("  OK  ");
					SetColor(7);
				}else if(kq=='B'){
					gotoxy(70,41);
					VeNutMauChu(3," B ");
					SetColor(13);
					gotoxy(180,42);
					VeNut("  OK  ");
					SetColor(7);
				}else if(kq=='C'){
					gotoxy(80,41);
					VeNutMauChu(3," C ");
					SetColor(13);
					gotoxy(180,42);
					VeNut("  OK  ");
					SetColor(7);
				}else if(kq=='D'){
					gotoxy(90,41);
					VeNutMauChu(3," D ");
					SetColor(13);
					gotoxy(180,42);
					VeNut("  OK  ");
					SetColor(7);
				}
			}else if(k==UP && checkPhim==true){
				if(kq=='A'){
					gotoxy(60,41);
					VeNutMauChu(3," A ");
					SetColor(13);
					gotoxy(60,36);
					VeKhung(4,133);
					SetColor(7);
					HienThi(61,190,37,dad);
					ShowCur(1);
				}else if(kq=='B'){
					gotoxy(70,41);
					VeNutMauChu(3," B ");
					SetColor(13);
					gotoxy(60,36);
					VeKhung(4,133);
					SetColor(7);
					HienThi(61,190,37,dad);
					ShowCur(1);
				}else if(kq=='C'){
					gotoxy(80,41);
					VeNutMauChu(3," C ");
					SetColor(13);
					gotoxy(60,36);
					VeKhung(4,133);
					SetColor(7);
					HienThi(61,190,37,dad);
					ShowCur(1);
				}else if(kq=='D'){
					gotoxy(90,41);
					VeNutMauChu(3," D ");
					SetColor(13);
					gotoxy(60,36);
					VeKhung(4,133);
					SetColor(7);
					HienThi(61,190,37,dad);
					ShowCur(1);
				}
			}
		}else if(wherey()==43){
			if(k==UP && checkPhim==true){
				if(kq=='A'){
					gotoxy(180,42);
					VeNut("  OK  ");
					SetColor(13);
					gotoxy(60,41);
					VeNutMauChu(3," A ");
					SetColor(7);
				}else if(kq=='B'){
					gotoxy(180,42);
					VeNut("  OK  ");
					SetColor(13);
					gotoxy(70,41);
					VeNutMauChu(3," B ");
					SetColor(7);
				}else if(kq=='C'){
					gotoxy(180,42);
					VeNut("  OK  ");
					SetColor(13);
					gotoxy(80,41);
					VeNutMauChu(3," C ");
					SetColor(7);
				}else if(kq=='D'){
					gotoxy(180,42);
					VeNut("  OK  ");
					SetColor(13);
					gotoxy(90,41);
					VeNutMauChu(3," D ");
					SetColor(7);
				}
			}else if(k==ENTER){
				if(mamh.length() ==0 || noidungch.length() ==0 || daa.length() ==0 || dab.length() ==0 || dac.length() ==0 || dad.length() ==0){
					gotoxy(180,42);
					VeNut("  OK  ");
					BaoLoi(105, 21, "     Vui long nhap day du du lieu!     ");
					VeKhungNhapCauHoi();
					if(kq=='A'){
						gotoxy(60,41);
						VeNutMauChu(3," A ");
						SetColor(7);
					}else if(kq=='B'){
						gotoxy(70,41);
						VeNutMauChu(3," B ");
						SetColor(7);
					}else if(kq=='C'){
						gotoxy(80,41);
						VeNutMauChu(3," C ");
						SetColor(7);
					}else if(kq=='D'){
						gotoxy(90,41);
						VeNutMauChu(3," D ");
						SetColor(7);
					}
					HienThi(61,190,37,dad);
					HienThi(61,190,32,dac);
					HienThi(61,190,27,dab);
					HienThi(61,190,22,daa);
					HienThi(61,190,16,noidungch);
					SetColor(13);
					gotoxy(70,10);
					VeKhung(3,60);
					SetColor(7);
					gotoxy(71,11);
					cout << mamh;
				}else if(kiemTraTonTaiMonHoc(mamh,ds_mh)==-1){
					gotoxy(180,42);
					VeNut("  OK  ");
					BaoLoi(105, 21, "       Ma mon hoc khong ton tai!       ");
					VeKhungNhapCauHoi();
					if(kq=='A'){
						gotoxy(60,41);
						VeNutMauChu(3," A ");
						SetColor(7);
					}else if(kq=='B'){
						gotoxy(70,41);
						VeNutMauChu(3," B ");
						SetColor(7);
					}else if(kq=='C'){
						gotoxy(80,41);
						VeNutMauChu(3," C ");
						SetColor(7);
					}else if(kq=='D'){
						gotoxy(90,41);
						VeNutMauChu(3," D ");
						SetColor(7);
					}
					HienThi(61,190,37,dad);
					HienThi(61,190,32,dac);
					HienThi(61,190,27,dab);
					HienThi(61,190,22,daa);
					HienThi(61,190,16,noidungch);
					SetColor(13);
					gotoxy(70,10);
					VeKhung(3,60);
					SetColor(7);
					gotoxy(71,11);
					cout << mamh;
				}else{
					gotoxy(180,42);
					VeNut("  OK  ");
					cauHoi *p=createNodeQuestion();
					p->ID=taoID(ds_ch.dsch);
					p->maMH=mamh;
					p->noiDung=noidungch;
					p->A=daa;
					p->B=dab;
					p->C=dac;
					p->D=dad;
					p->dapAn=kq;
					themNode(ds_ch.dsch,p);
					ds_ch.soCH++;
					themFileCauHoi(ds_ch,p);
					ThongBao(105, 24, "      Them cau hoi thanh cong!      ");
					goto tieptuc;
				}
			}
		}
	}
}
void InDSDiem(DS_LOP_HOC ds_lh, DS_MON_HOC ds_mh, int x, int y){
	NhapDLXuatDiemThi();
	string malop, mamh;
	int r;
	char k;
	bool checkPhim;
	while((k=LayPhim(checkPhim))!=ESC){
		if(wherey()==17){
			if(((k>96 && k<123) || (k>64 && k<91)) && checkPhim==false && malop.length()<15){
				cout << InHoa(k);
				malop+=InHoa(k);
			}else if(k>47 && k<58 && checkPhim==false && malop.length()<15){
				cout << k;
				malop+=k;
			}else if(k==BACKSPACE && malop.length()>0){
				XoaCuoi(malop);
				BackSpace();
			}else if(k == DOWN && checkPhim==true){
				gotoxy(100, 16);
				VeKhung(3,30);
				gotoxy(101,17);
				cout << malop;
				SetColor(13);
				gotoxy(100,20);
				VeKhung(3,60);
				SetColor(7);
				gotoxy(101,21);
				cout << mamh;
			}
		}else if(wherey()==21){
			if(((k>96 && k<123) || (k>64 && k<91)) && checkPhim==false && mamh.length()<15){
				cout << InHoa(k);
				mamh+=InHoa(k);
			}else if(k>47 && k<58 && checkPhim==false && mamh.length()<15){
				cout << k;
				mamh+=k;
			}else if(k==BACKSPACE && mamh.length()>0){
				XoaCuoi(mamh);
				BackSpace();
			}else if(k == DOWN && checkPhim==true){
				gotoxy(100,20);
				VeKhung(3,60);
				gotoxy(101,21);
				cout << mamh;
				SetColor(13);
				gotoxy(123,24);
				VeNut(" OK ");
				SetColor(7);
				ShowCur(0);
			}else if(k == UP && checkPhim==true){
				gotoxy(100,20);
				VeKhung(3,60);
				gotoxy(101,21);
				cout << mamh;
				SetColor(13);
				gotoxy(100, 16);
				VeKhung(3,30);
				SetColor(7);
				gotoxy(101,17);
				cout << malop;
			}
		}else if(wherey()==25){
			if(k==UP && checkPhim==true){
				gotoxy(123,24);
				VeNut(" OK ");
				SetColor(13);
				gotoxy(100,20);
				VeKhung(3,60);
				SetColor(7);
				gotoxy(101,21);
				cout << mamh;
				ShowCur(1);
			}else if(k==ENTER){
				gotoxy(123,24);
				VeNut(" OK ");
				int i=kiemTraTonTaiLopHoc(malop,ds_lh);
				int z=kiemTraTonTaiMonHoc(mamh,ds_mh);
				if(mamh.length() == 0 || malop.length() == 0){
					BaoLoi(112,17, "Vui long nhap day du!");
					NhapDLXuatDiemThi();
					gotoxy(101,21);
					cout << mamh;
					gotoxy(101,17);
					cout << malop;
					ShowCur(1);
				}else if(i==-1){
					BaoLoi(110,17, "Ma lop hoc khong ton tai!");
					NhapDLXuatDiemThi();
					gotoxy(101,21);
					cout << mamh;
					gotoxy(101,17);
					cout << malop;
					ShowCur(1);
				}else if(z==-1){
					BaoLoi(107,17, "Ma mon hoc hoc khong ton tai!");
					NhapDLXuatDiemThi();
					gotoxy(101,21);
					cout << mamh;
					gotoxy(101,17);
					cout << malop;
					ShowCur(1);
				}else{
					gotoxy(85,14);
					XoaKhung(14,80);
					int h = 0;
					SINH_VIEN *p=ds_lh.dslh[i]->danhSachSinhVien.pHead;
					VeKhungXuatDiemThi(x,y,ds_lh.dslh[i]->danhSachSinhVien.soSV);
					r=ds_lh.dslh[i]->danhSachSinhVien.soSV;
					gotoxy(x+55, y-1);
					cout << "(" << mamh << ")";
					while (p!=NULL){
						gotoxy(x+1,y+h+3);
						cout << p->maSV;
						gotoxy(x+21,y+h+3);
						cout << p->hoSV;
						gotoxy(x+41,y+h+3);
						cout << p->tenSV;
						gotoxy(x+71,y+h+3);
						cout << p->gioiTinh;
						chiTietThi *temp=kiemTraTonTaiDeThi(mamh,p->danhSachChiTietThi.pHead);
						if(temp==NULL){
							gotoxy(x+86, y+h+3);
							cout<<"Chua thi";
						}else{
							gotoxy(x+86, y+h+3);
							cout<<(float)temp->diem;
						}
						p=p->next;
						h++;
					}
					gotoxy(0,0);	
				}	
			}
		}
	}
	gotoxy(x, y-1);
	XoaKhung(r+5,100);
}
void InDSCauHoi(DS_LOP_HOC ds_lh, DS_MON_HOC ds_mh){
	VeKhungNhapDLInCH();
	string masv, mamh;
	char k;
	bool checkPhim;
	while((k=LayPhim(checkPhim))!=ESC){
		if(wherey()==17){
			if(((k>96 && k<123) || (k>64 && k<91)) && checkPhim==false && masv.length()<15){
				cout << InHoa(k);
				masv+=InHoa(k);
			}else if(k>47 && k<58 && checkPhim==false && masv.length()<15){
				cout << k;
				masv+=k;
			}else if(k==BACKSPACE && masv.length()>0){
				XoaCuoi(masv);
				BackSpace();
			}else if(k == DOWN && checkPhim==true){
				gotoxy(100, 16);
				VeKhung(3,30);
				gotoxy(101,17);
				cout << masv;
				SetColor(13);
				gotoxy(100,20);
				VeKhung(3,60);
				SetColor(7);
				gotoxy(101,21);
				cout << mamh;
			}
		}else if(wherey()==21){
			if(((k>96 && k<123) || (k>64 && k<91)) && checkPhim==false && mamh.length()<15){
				cout << InHoa(k);
				mamh+=InHoa(k);
			}else if(k>47 && k<58 && checkPhim==false && mamh.length()<15){
				cout << k;
				mamh+=k;
			}else if(k==BACKSPACE && mamh.length()>0){
				XoaCuoi(mamh);
				BackSpace();
			}else if(k == DOWN && checkPhim==true){
				gotoxy(100,20);
				VeKhung(3,60);
				gotoxy(101,21);
				cout << mamh;
				SetColor(13);
				gotoxy(123,24);
				VeNut(" OK ");
				SetColor(7);
				ShowCur(0);
			}else if(k == UP && checkPhim==true){
				gotoxy(100,20);
				VeKhung(3,60);
				gotoxy(101,21);
				cout << mamh;
				SetColor(13);
				gotoxy(100, 16);
				VeKhung(3,30);
				SetColor(7);
				gotoxy(101,17);
				cout << masv;
			}
		}else if(wherey()==25){
			if(k==UP && checkPhim==true){
				gotoxy(123,24);
				VeNut(" OK ");
				SetColor(13);
				gotoxy(100,20);
				VeKhung(3,60);
				SetColor(7);
				gotoxy(101,21);
				cout << mamh;
				ShowCur(1);
			}else if(k==ENTER){
				gotoxy(123,24);
				VeNut(" OK ");
				sinhVien *tam=kiemTraTonTaiSinhVien(masv,ds_lh);
				if(masv.length() ==0 || mamh.length() == 0){
					BaoLoi(112, 110, "Vui long nhap day du!");
					VeKhungNhapDLInCH();
					gotoxy(101,21);
					cout << mamh;
					gotoxy(101,17);
					cout << masv;
					ShowCur(1);
				}else if (tam==NULL){
					BaoLoi(110, 17, "Ma sinh vien khong ton tai!");
					VeKhungNhapDLInCH();
					gotoxy(101,21);
					cout << mamh;
					gotoxy(101,17);
					cout << masv;
					ShowCur(1);
				}else{
					int z=kiemTraTonTaiMonHoc(mamh,ds_mh);
					chiTietThi *temp=kiemTraTonTaiDeThi(mamh,tam->danhSachChiTietThi.pHead);
					if(z==-1){
						BaoLoi(110,17,"Ma mon hoc khong ton tai!");
						VeKhungNhapDLInCH();
						gotoxy(101,21);
						cout << mamh;
						gotoxy(101,17);
						cout << masv;
						ShowCur(1);
					}else if(temp==NULL){
						BaoLoi(110,17,"Sinh vien chua thi mon nay!");
						VeKhungNhapDLInCH();
						gotoxy(101,21);
						cout << mamh;
						gotoxy(101,17);
						cout << masv;
						ShowCur(1);
					}else{
						gotoxy(50,9);
						cout << "MA SV: " << masv;
						gotoxy(50,10);
						cout << "MA MH: " << temp->maMH;
						gotoxy(50,11);
						cout << "SO CAU THI: " << temp->soCauThi;
						char s;
						bool checkP;
						int i = 1;
						VeKhungInCH();
						gotoxy(55,13);
						cout << "Cau: " << i;
						HienThi(61,190,16,temp->danhSachDeThi.dsdt[i]->boDe.noiDung);
						HienThi(61,190,22,temp->danhSachDeThi.dsdt[i]->boDe.A);
						HienThi(61,190,27,temp->danhSachDeThi.dsdt[i]->boDe.B);
						HienThi(61,190,32,temp->danhSachDeThi.dsdt[i]->boDe.C);
						HienThi(61,190,37,temp->danhSachDeThi.dsdt[i]->boDe.D);
						gotoxy(75,40);
						cout << temp->danhSachDeThi.dsdt[i]->boDe.dapAn;
						gotoxy(80,42);
						cout << temp->danhSachDeThi.dsdt[i]->traLoi;
						ShowCur(0);
						while((s=LayPhim(checkP))!=ESC){
							if(s==RIGHT && checkP==true && i<temp->soCauThi){
								i++;
								gotoxy(55,13);
								cout << "Cau: " << i;
								HienThi(61,190,16,temp->danhSachDeThi.dsdt[i]->boDe.noiDung);
								HienThi(61,190,22,temp->danhSachDeThi.dsdt[i]->boDe.A);
								HienThi(61,190,27,temp->danhSachDeThi.dsdt[i]->boDe.B);
								HienThi(61,190,32,temp->danhSachDeThi.dsdt[i]->boDe.C);
								HienThi(61,190,37,temp->danhSachDeThi.dsdt[i]->boDe.D);
								gotoxy(75,40);
								cout << temp->danhSachDeThi.dsdt[i]->boDe.dapAn;
								gotoxy(80,42);
								cout << temp->danhSachDeThi.dsdt[i]->traLoi;
								ShowCur(0);
							}else if(s==LEFT && checkP==true && i>1){
								i--;
								gotoxy(55,13);
								cout << "Cau: " << i;
								HienThi(61,190,16,temp->danhSachDeThi.dsdt[i]->boDe.noiDung);
								HienThi(61,190,22,temp->danhSachDeThi.dsdt[i]->boDe.A);
								HienThi(61,190,27,temp->danhSachDeThi.dsdt[i]->boDe.B);
								HienThi(61,190,32,temp->danhSachDeThi.dsdt[i]->boDe.C);
								HienThi(61,190,37,temp->danhSachDeThi.dsdt[i]->boDe.D);
								gotoxy(75,40);
								cout << temp->danhSachDeThi.dsdt[i]->boDe.dapAn;
								gotoxy(80,42);
								cout << temp->danhSachDeThi.dsdt[i]->traLoi;
								ShowCur(0);
							}
						}
						break;
					}
				}
			}
		}
	}
}
void MeNuGV(DS_LOP_HOC &ds_lh, DS_MON_HOC &ds_mh, DS_CAU_HOI &ds_ch){
//	SetBGColor(1);
	clrscr;
	ShowCur(0);
	gotoxy(94,0);
	cout << "PHAN MEM THI TRAC NGHIEM";
	SetBGColor(0);
	gotoxy(98,1);
	cout << "===== &&& =====";
	gotoxy(0,2);
	VeKhung(50, 210);
	for(int i=3; i<=50; i++){
		gotoxy(43,i);
		cout << doc;
	}
	gotoxy(1,38);
	VeDuongThangNgang(42);
	SetColor(2);
	gotoxy(3,39);
	cout << "HUONG DAN:";
	SetColor(8); 
	gotoxy(3,40);
	cout << "ESC: Thoat         ENTER: chon";
	gotoxy(3,41);
	cout << "UP: Len            DOWN: Xuong";
	SetColor(4);
	gotoxy(15,4);
	cout << "MENU GIANG VIEN:";
	gotoxy(123,4);
	cout << "XU LI: ";
	SetColor(7);
	gotoxy(2,9);
	VeNutMeNu(3,40,"IN DANH SACH LOP");
	gotoxy(2,12);
	VeNutMeNu(3,40,"NHAP SINH VIEN CUA LOP");
	gotoxy(2,15);
	VeNutMeNu(3,40,"NHAP MON HOC");
	gotoxy(2,18);
	VeNutMeNu(3,40,"NHAP CAU HOI THI");
	gotoxy(2,21);
	VeNutMeNu(3,40,"THI THU");
	gotoxy(2,24);
	VeNutMeNu(3,40,"IN CAU HOI DA THI 1MH/ 1SV");
	gotoxy(2,27);
	VeNutMeNu(3,40,"IN BANG DIEM 1 LOP");
	gotoxy(2,30);
	VeNutMeNu(3,40,"XOA MON HOC");
	gotoxy(2,33);
	VeNutMeNu(3,40,"HIEU CHINH MON HOC");
	SetColor(13);
	gotoxy(2,6);
	VeNutMeNu(3,40,"NHAP LOP");
	SetColor(7);
	char s;
	bool checkPhim;
	while((s=LayPhim(checkPhim))!=ESC){
		if(wherey()==7){
			if(s==DOWN && checkPhim==true){
				gotoxy(2,6);
				VeNutMeNu(3,40,"NHAP LOP");	
				SetColor(13);
				gotoxy(2,9);
				VeNutMeNu(3,40,"IN DANH SACH LOP");
				SetColor(7);
			}else if(s==UP && checkPhim==true){
				gotoxy(2,6);
				VeNutMeNu(3,40,"NHAP LOP");
				SetColor(13);
				gotoxy(2,33);
				VeNutMeNu(3,40,"HIEU CHINH MON HOC");
				SetColor(7);
			}else if(s==ENTER){
				gotoxy(2,6);
				VeNutMeNu(3,40,"NHAP LOP");
				NhapLopHoc(ds_lh);
				gotoxy(85,15);
				XoaKhung(13,80);
				SetColor(13);
				gotoxy(2,6);
				VeNutMeNu(3,40,"NHAP LOP");
				ShowCur(0);
				SetColor(7);
			}
		}else if(wherey()==10){
			if(s==DOWN && checkPhim==true){
				gotoxy(2,9);
				VeNutMeNu(3,40,"IN DANH SACH LOP");
				SetColor(13);
				gotoxy(2,12);
				VeNutMeNu(3,40,"NHAP SINH VIEN CUA LOP");
				SetColor(7);
			}else if(s==UP && checkPhim==true){
				gotoxy(2,9);
				VeNutMeNu(3,40,"IN DANH SACH LOP");
				SetColor(13);
				gotoxy(2,6);
				VeNutMeNu(3,40,"NHAP LOP");
				SetColor(7);
			}else if(s==ENTER){
				gotoxy(2,9);
				VeNutMeNu(3,40,"IN DANH SACH LOP");
				InDSLopHoc(90, 9, ds_lh);
				char k;
				bool checkPhim;
				while((k=LayPhim(checkPhim))!=ESC);
				gotoxy(90,8);
				XoaKhung(ds_lh.soLH+5, 83);
				SetColor(13);
				gotoxy(2,9);
				VeNutMeNu(3,40,"IN DANH SACH LOP");
				SetColor(7);
			}
		}else if(wherey()==13){
			if(s==DOWN && checkPhim==true){
				gotoxy(2,12);
				VeNutMeNu(3,40,"NHAP SINH VIEN CUA LOP");
				SetColor(13);
				gotoxy(2,15);
				VeNutMeNu(3,40,"NHAP MON HOC");
				SetColor(7);
			}else if(s==UP && checkPhim==true){
				gotoxy(2,12);
				VeNutMeNu(3,40,"NHAP SINH VIEN CUA LOP");
				SetColor(13);
				gotoxy(2,9);
				VeNutMeNu(3,40,"IN DANH SACH LOP");
				SetColor(7);
			}else if(s==ENTER){
				gotoxy(2,12);
				VeNutMeNu(3,40,"NHAP SINH VIEN CUA LOP");
				NhapSV(ds_lh);
				gotoxy(95,8);
				XoaKhung(30,80);
				gotoxy(85,15);
				XoaKhung(ds_lh.soLH +5, 75);
				SetColor(13);
				gotoxy(2,12);
				VeNutMeNu(3,40,"NHAP SINH VIEN CUA LOP");
				ShowCur(0);
				SetColor(7);
			}
		}else if(wherey()==16){
			if(s==DOWN && checkPhim==true){
				gotoxy(2,15);
				VeNutMeNu(3,40,"NHAP MON HOC");
				SetColor(13);
				gotoxy(2,18);
				VeNutMeNu(3,40,"NHAP CAU HOI THI");
				SetColor(7);
			}else if(s==UP && checkPhim==true){
				gotoxy(2,15);
				VeNutMeNu(3,40,"NHAP MON HOC");
				SetColor(13);
				gotoxy(2,12);
				VeNutMeNu(3,40,"NHAP SINH VIEN CUA LOP");
				SetColor(7);
			}else if(s==ENTER){
				gotoxy(2,15);
				VeNutMeNu(3,40,"NHAP MON HOC");
				NhapMH(ds_mh);
				gotoxy(85,15);
				XoaKhung(13,80);
				SetColor(13);
				gotoxy(2,15);
				VeNutMeNu(3,40,"NHAP MON HOC");
				ShowCur(0);
				SetColor(7);
			}
		}else if(wherey()==19){
			if(s==DOWN && checkPhim==true){
				gotoxy(2,18);
				VeNutMeNu(3,40,"NHAP CAU HOI THI");
				SetColor(13);
				gotoxy(2,21);
				VeNutMeNu(3,40,"THI THU");
				SetColor(7);
			}else if(s==UP && checkPhim==true){
				gotoxy(2,18);
				VeNutMeNu(3,40,"NHAP CAU HOI THI");
				SetColor(13);
				gotoxy(2,15);
				VeNutMeNu(3,40,"NHAP MON HOC");
				SetColor(7);
			}else if(s==ENTER){
				gotoxy(2,18);
				VeNutMeNu(3,40,"NHAP CAU HOI THI");
				NhapCauHoi(ds_ch,ds_mh);
				gotoxy(50, 7);
				XoaKhung(40,153);
				SetColor(13);
				gotoxy(2,18);
				VeNutMeNu(3,40,"NHAP CAU HOI THI");
				ShowCur(0);
				SetColor(7);
			}
		}else if(wherey()==22){
			if(s==DOWN && checkPhim==true){
				gotoxy(2,21);
				VeNutMeNu(3,40,"THI THU");
				SetColor(13);
				gotoxy(2,24);
				VeNutMeNu(3,40,"IN CAU HOI DA THI 1MH/ 1SV");
				SetColor(7);
			}else if(s==UP && checkPhim==true){
				gotoxy(2,21);
				VeNutMeNu(3,40,"THI THU");
				SetColor(13);
				gotoxy(2,18);
				VeNutMeNu(3,40,"NHAP CAU HOI THI");
				SetColor(7);
			}else if(s==ENTER){
				gotoxy(2,21);
				VeNutMeNu(3,40,"THI THU");
				ThiThu(ds_mh, ds_ch);
				gotoxy(70,14);
				XoaKhung(15, 60);
				SetColor(8); 
				gotoxy(3,40);
				cout << "ESC: Thoat         ENTER: chon  ";
				gotoxy(3,41);
				cout << "UP: Len            DOWN: Xuong  ";
				SetColor(13);
				gotoxy(2,21);
				VeNutMeNu(3,40,"THI THU");
				ShowCur(0);
				SetColor(7);
			}
		}else if(wherey()==25){
			if(s==DOWN && checkPhim==true){
				gotoxy(2,24);
				VeNutMeNu(3,40,"IN CAU HOI DA THI 1MH/ 1SV");
				SetColor(13);
				gotoxy(2,27);
				VeNutMeNu(3,40,"IN BANG DIEM 1 LOP");
				SetColor(7);
			}else if(s==UP && checkPhim==true){
				gotoxy(2,24);
				VeNutMeNu(3,40,"IN CAU HOI DA THI 1MH/ 1SV");
				SetColor(13);
				gotoxy(2,21);
				VeNutMeNu(3,40,"THI THU");
				SetColor(7);
			}else if(s==ENTER){
				gotoxy(2,24);
				VeNutMeNu(3,40,"IN CAU HOI DA THI 1MH/ 1SV");
				InDSCauHoi(ds_lh,ds_mh);
				gotoxy(50, 7);
				XoaKhung(40,153);
				SetColor(13);
				gotoxy(2,24);
				VeNutMeNu(3,40,"IN CAU HOI DA THI 1MH/ 1SV");
				ShowCur(0);
				SetColor(7);
			}
		}else if(wherey()==28){
			if(s==DOWN && checkPhim==true){
				gotoxy(2,27);
				VeNutMeNu(3,40,"IN BANG DIEM 1 LOP");
				SetColor(13);
				gotoxy(2,30);
				VeNutMeNu(3,40,"XOA MON HOC");
				SetColor(7);
			}else if(s==UP && checkPhim==true){
				gotoxy(2,27);
				VeNutMeNu(3,40,"IN BANG DIEM 1 LOP");
				SetColor(13);
				gotoxy(2,24);
				VeNutMeNu(3,40,"IN CAU HOI DA THI 1MH/ 1SV");
				SetColor(7);
			}else if(s==ENTER){
				gotoxy(2,27);
				VeNutMeNu(3,40,"IN BANG DIEM 1 LOP");
				InDSDiem(ds_lh, ds_mh, 80,10);
				SetColor(13);
				gotoxy(2,27);
				VeNutMeNu(3,40,"IN BANG DIEM 1 LOP");
				ShowCur(0);
				SetColor(7);
			}
		}else if(wherey()==31){
			if(s==DOWN && checkPhim==true){
				gotoxy(2,30);
				VeNutMeNu(3,40,"XOA MON HOC");
				SetColor(13);
				gotoxy(2,33);
				VeNutMeNu(3,40,"HIEU CHINH MON HOC");
				SetColor(7);
			}else if(s==UP && checkPhim==true){
				gotoxy(2,30);
				VeNutMeNu(3,40,"XOA MON HOC");
				SetColor(13);
				gotoxy(2,27);
				VeNutMeNu(3,40,"IN BANG DIEM 1 LOP");
				SetColor(7);
			}else if(s==ENTER){
				gotoxy(2,30);
				VeNutMeNu(3,40,"XOA MON HOC");
				XoaMonHoc(ds_mh);
				gotoxy(50, 7);
				XoaKhung(ds_mh.soMH + 5, 83);
				gotoxy(140,8);
				XoaKhung(5,60);
				SetColor(13);
				gotoxy(2,30);
				VeNutMeNu(3,40,"XOA MON HOC");
				ShowCur(0);
				SetColor(7);
			}
		}else if(wherey()==34){
			if(s==DOWN && checkPhim==true){
				gotoxy(2,33);
				VeNutMeNu(3,40,"HIEU CHINH MON HOC");
				SetColor(13);
				gotoxy(2,6);
				VeNutMeNu(3,40,"NHAP LOP");
				SetColor(7);
			}else if(s==UP && checkPhim==true){
				gotoxy(2,33);
				VeNutMeNu(3,40,"HIEU CHINH MON HOC");
				SetColor(13);
				gotoxy(2,30);
				VeNutMeNu(3,40,"XOA MON HOC");
				SetColor(7);
			}else if(s==ENTER){
				gotoxy(2,33);
				VeNutMeNu(3,40,"HIEU CHINH MON HOC");
				HieuChinhMonHoc(ds_mh,ds_ch);
				gotoxy(50, 7);
				XoaKhung(ds_mh.soMH + 5, 83);
				gotoxy(140, 8);
				XoaKhung(19, 60);
				SetColor(13);
				gotoxy(2,33);
				VeNutMeNu(3,40,"HIEU CHINH MON HOC");
				SetColor(7);
				ShowCur(0);
			}
		}
	}
}
void ChuongTrinhChinh(DS_LOP_HOC &ds_lh, DS_MON_HOC &ds_mh, DS_CAU_HOI &ds_ch){
	dangnhap: 
	bool check;
	sinhVien *temp=DangNhap(ds_lh, check);
	if(check==false){
		return;
	}else if(temp==NULL){
		MeNuGV(ds_lh,ds_mh,ds_ch);
		goto dangnhap;
	}else{
		clrscr();
		SetColor(8);
		gotoxy(182,0);
		cout << "HUYNH TUAN KIET - N19DCCN079";
		gotoxy(182,1);
		cout << "MAI VAN LOI - N19DCCN102";
		SetColor(7);
		Thi(temp,ds_mh,ds_ch,ds_lh);
		goto dangnhap;
	}
}


