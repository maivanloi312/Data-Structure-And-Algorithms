#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define BACKSPACE 8
#define SPACE 32
#define ESC 27
#define F1 59

#define doc (char)179
#define ngang (char)196
#define traitren (char)218
#define phaitren (char)191
#define traiduoi (char)192
#define phaiduoi (char)217
#define docphai (char)195
#define doctrai (char)180
#define ngangxuong (char)194
#define nganglen (char)193
#define giua (char)197

using namespace std;


void gotoxy(short x,short y)
{
        HANDLE hConsoleOutput;
        COORD Cursor_an_Pos = { x,y};
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}  

int wherex( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}

int wherey( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}
void clreol( ) {
COORD coord;
DWORD written;
CONSOLE_SCREEN_BUFFER_INFO info;
GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
coord.X = info.dwCursorPosition.X;
coord.Y = info.dwCursorPosition.Y;
FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
  info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
gotoxy (info.dwCursorPosition.X , info.dwCursorPosition.Y );
}

void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void clrscr() {
	system("cls");
}
void ShowCur(bool CursorVisibility){
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;
    
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = CursorVisibility;
    
    SetConsoleCursorInfo(handle, &ConCurInf);
}
char InHoa(char a){
	char b;
	if(a>96 && a<123){
		b=a-32;
		return b;
	}else if(a>64 && a<94) return a;
}
string XoaCuoi(string &str){
	str.erase(str.length() -1, 1);
	return str;
}
void BackSpace(){
	gotoxy(wherex()-1, wherey());
	cout << " ";
	gotoxy(wherex()-1, wherey());
}
int DoiSo(string text){
	if (text.length() == 0) return -1;
	int so = 0;
	for (int i = 0; i < text.length(); i++){
		so = so*10 + (int)(text[i] - 48);
	}
	return so;
}
void VeDuongThangNgang(int chieudai){
	for(int i=0; i<chieudai; i++)
		cout << ngang;
}
void VeDuongThangDoc(int chieucao){
	for(int i=0; i<chieucao; i++){
		gotoxy(wherex(),wherey()+1);
		cout << doc;
	}
}
void VeKhung(int rong, int dai){
	for (int i = 0; i < rong; i++){
		for (int j = 0; j < dai; j++){
			if (i == 0){
				if (j == 0) cout << traitren;
				else if (j == dai-1) cout << phaitren;
				else cout << ngang;
			}
			else if (i == rong-1){
				if (j == 0) cout << traiduoi;
				else if (j == dai-1) cout << phaiduoi;
				else cout << ngang;
			}else{
				if (j == 0 || j == dai-1) cout << doc;
				else cout << " ";
			}
		}
		gotoxy(wherex()-dai,wherey()+1);
	}
}
void XoaKhung(int rong, int dai){
	for (int i = 0; i < rong; i++){
		for (int j = 0; j < dai; j++)
			cout << " ";
		gotoxy(wherex()-dai,wherey()+1);
	}
}
void VeNut(string text){
	VeKhung(3,text.size()+2);
	gotoxy(wherex()+1, wherey()-2);
	cout << text;
}
void VeNutMauChu(int mauchu, string text){
	VeKhung(3,text.size()+2);
	gotoxy(wherex()+1, wherey()-2);
	SetColor(mauchu);
	cout << text;
	SetColor(7);
}

void VeKhungNhapMonThi(){
	SetColor(10);
	gotoxy(75, 14);
	cout << "VUI LONG NHAP DAY DU THONG TIN BEN DUOI DE VAO THI!";
	SetColor(11);
	gotoxy(70,15);
	VeKhung(14, 60);
	SetColor(13);
	gotoxy(95, 16);
	VeKhung(3, 30);
	SetColor(7);
	gotoxy(75,17);
	cout << "NHAP MA MON THI:";
	gotoxy(75, 20);
	cout << "NHAP SO CAU HOI THI:";
	gotoxy(95,19);
	VeKhung(3, 15);
	gotoxy(75,23);
	cout << "NHAP SO PHUT THI:";
	gotoxy(95,  22);
	VeKhung(3, 15);
	gotoxy(96, 25);
	VeNut("XAC NHAN");
	gotoxy(96, 17);
	ShowCur(1);
}
void VeKhungDN(){
	SetColor(11);
	gotoxy(70,21);
	VeKhung(12,60);
	SetColor(7);
	gotoxy(73,23);
	cout << "TEN TAI KHOAN: ";
	SetColor(13);
	gotoxy(87, 22);
	VeKhung(3,40);
	SetColor(7);
	gotoxy(73,26);
	cout << "MAT KHAU: ";
	gotoxy(87, 25);
	VeKhung(3,40);
	gotoxy(95,29);
	VeNut("DANG NHAP");
}
char LayPhim(bool &phimchucnang){
	char s = getch();
	if(s==0 || s==-32){
		s = getch();
		phimchucnang = true;
		return s;
	}else{
		phimchucnang = false;
		return s;
	}
}

bool Hoi(int x, int y, string text){
	ShowCur(0);
	SetColor(3);
	gotoxy(x,y);
	VeKhung(8,text.size()+6);
	gotoxy(wherex()+3, wherey()-6);
	cout << text;
	gotoxy(wherex()-4, wherey()+2);
	VeNut(" NO ");
	gotoxy(wherex()-13, wherey()-1);
	SetColor(12);
	VeNut(" YES ");
	SetColor(7);
	char s;
	bool checkPhim;
	bool f=true;
	while((s=LayPhim(checkPhim))!=ENTER){
		if(s==RIGHT && f==true && checkPhim==true){
			gotoxy(wherex()-6, wherey()-1);
			VeNut(" YES ");
			SetColor(12);
			gotoxy(wherex()+2, wherey()-1);
			VeNut(" NO ");
			SetColor(7);
			f=false;
		}else if(s==LEFT && f==false && checkPhim==true){
			gotoxy(wherex()-5, wherey()-1);
			VeNut(" NO ");
			SetColor(12);
			gotoxy(wherex()-13, wherey()-1);
			VeNut(" YES ");
			SetColor(7);
			f=true;
		}
	}
	gotoxy(x,y);
	XoaKhung(8,text.size()+6);
	return f;
}

void BaoLoi(int x, int y, string text){
	ShowCur(0);
	SetColor(3);
	gotoxy(x,y);
	VeKhung(8,text.size()+6);
	gotoxy(wherex()+3, wherey()-6);
	cout << text;
	gotoxy(wherex()-3, wherey()+2);
	SetColor(12);
	VeNut("OK");
	SetColor(7);
	char s;
	while((s=getch()) != ENTER);
	gotoxy(x,y);
	XoaKhung(8,text.size()+6);
	SetColor(7);
}
void ThongBao(int x, int y, string text){
	ShowCur(0);
	SetColor(3);
	gotoxy(x,y);
	VeKhung(5,text.size()+6);
	gotoxy(x+3, y+2);
	cout << text;
	Sleep(2000);
	gotoxy(x,y);
	XoaKhung(5,text.size()+6);
	SetColor(7);
}
void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}



void VeNutMeNu(int rong, int dai, string text){
	VeKhung(rong, dai);
	gotoxy(wherex()+dai/2-text.size()/2, wherey()-2);
	cout << text;
}

void VeKhungNhapLop(){
	SetColor(11);
	gotoxy(85,15);
	VeKhung(13,80);
	SetColor(10);
	gotoxy(121, 16);
	cout << "NHAP LOP";
	SetColor(7);
	gotoxy(88, 19);
	cout << "NHAP MA LOP:";
	gotoxy(88, 22);
	cout << "NHAP TEN LOP:";
	gotoxy(102,21);
	VeKhung(3,60);
	gotoxy(122,24);
	VeNut("  OK  ");
	SetColor(13);
	gotoxy(102, 18);
	VeKhung(3,60);
	SetColor(7);
	gotoxy(103,19);
	ShowCur(1);
}
void VeKhungInDSLop(int x, int y, int solop){
	gotoxy(x, y);
	for (int i = 0; i < solop+4; i++){
		for (int j = 0; j < 83; j++){
			if (i == 0){
				if (j == 0) cout << traitren;
				else if(j == 19) cout << ngangxuong;
				else if (j == 74) cout << ngangxuong;
				else if(j==82) cout << phaitren;
				else cout << ngang;
			}else if(i == 2){
				if(j == 0) cout << docphai;
				else if(j == 82) cout << doctrai;
				else if(j==19 || j==74) cout << giua;
				else cout << ngang;
			}else if (i == solop+3){
				if (j == 0) cout << traiduoi;
				else if(j == 19 || j == 74) cout << nganglen;
				else if (j == 82) cout << phaiduoi;
				else cout << ngang;
			}else{
				if (j == 0 || j == 74 || j==19 || j==82) cout << doc;
				else cout << " ";
			}
		}
		gotoxy(wherex()-83,wherey()+1);
	}
	SetColor(10);
	gotoxy(wherex()+7, wherey()-solop-3);
	cout << "MA LOP";
	gotoxy(wherex()+30, wherey());
	cout << "TEN LOP";
	gotoxy(wherex()+27, wherey());
	cout <<"SL";
	gotoxy(x+32, y-1);
	cout << "DANH SACH LOP";
	SetColor(7);
}
void VeKhungInDSMH(int x , int y, int somh){
	gotoxy(x, y);
	for (int i = 0; i < somh+4; i++){
		for (int j = 0; j < 75; j++){
			if (i == 0){
				if (j == 0) cout << traitren;
				else if(j == 19) cout << ngangxuong;
				else if (j == 74) cout << phaitren;
				else cout << ngang;
			}else if(i == 2){
				if(j == 0) cout << docphai;
				else if(j == 74) cout << doctrai;
				else if(j==19) cout << giua;
				else cout << ngang;
			}else if (i == somh+3){
				if (j == 0) cout << traiduoi;
				else if(j == 19) cout << nganglen;
				else if (j == 74) cout << phaiduoi;
				else cout << ngang;
			}else{
				if (j == 0 || j == 74 || j==19) cout << doc;
				else cout << " ";
			}
		}
		gotoxy(wherex()-75,wherey()+1);
	}
	SetColor(10);
	gotoxy(wherex()+7, wherey()-somh-3);
	cout << "MA  MH";
	gotoxy(wherex()+30, wherey());
	cout << "TEN  MH";
	gotoxy(x+30, y-1);
	cout << "DANH SACH MON HOC";
	SetColor(7);	
}
void VeKhungHieuChinhMH(){
	SetColor(11);
	gotoxy(140, 8);
	VeKhung(19, 60);
	SetColor(10);
	gotoxy(160, 9);
	cout << " HIEU CHINH MON HOC";
	SetColor(7);
	gotoxy(141,10);
	cout << "Ma MH can hieu chinh:";
	SetColor(13);
	gotoxy(143,11);
	VeKhung(3,54);
	SetColor(7);
	gotoxy(141,14);
	cout << "Hieu chinh thanh:";
	gotoxy(142,15);
	cout << "- Ma MH:";
	gotoxy(143, 16);
	VeKhung(3,54);
	gotoxy(142,19);
	cout << "- Ten MH:";
	gotoxy(143, 20);
	VeKhung(3,54);
	gotoxy(185, 23);
	VeNut(" OK ");
	gotoxy(144,12);
	ShowCur(1);
}
void VeKhungNhapMaLop(){
	SetColor(10);
	gotoxy(97, 8);
	cout << "NHAP MA LOP CAN THEM SINH VIEN VA AN ENTER DE TIEP TUC !";
	SetColor(13);
	gotoxy(100,9);
	VeKhung(3,50);
	SetColor(7);
	gotoxy(101,10);
	ShowCur(1);
}
void VeKhungNhapSV(){
	SetColor(11);
	gotoxy(85,14);
	VeKhung(22,80);
	SetColor(10);
	gotoxy(119, 15);
	cout << "NHAP SINH VIEN";
	SetColor(7);
	gotoxy(88,18);
	cout << "NHAP MA SV:";
	SetColor(13);
	gotoxy(102,17);
	VeKhung(3,60);
	SetColor(7);
	gotoxy(88,21);
	cout << "HO:";
	gotoxy(102,20);
	VeKhung(3,60);
	gotoxy(88,24);
	cout << "TEN:";
	gotoxy(102,23);
	VeKhung(3,60);
	gotoxy(88,27);
	cout << "GIOI TINH:";
	gotoxy(102,26);
	VeNut("NAM");
	gotoxy(112,26);
	VeNut("NU");
	gotoxy(88,30);
	cout<< "NHAP PASSWORD:";
	gotoxy(102,29);
	VeKhung(3,60);
	gotoxy(150,32);
	VeNut(" OK ");
	gotoxy(103,18);
	ShowCur(1);
}
void VeKhungNhapMH(){
	SetColor(11);
	gotoxy(85,15);
	VeKhung(13,80);
	SetColor(10);
	gotoxy(120, 16);
	cout << "NHAP MON HOC";
	SetColor(13);
	gotoxy(102, 18);
	VeKhung(3,60);
	SetColor(7);
	gotoxy(88, 19);
	cout << "NHAP MA MH:";
	gotoxy(88, 22);
	cout << "NHAP TEN MH:";
	gotoxy(102,21);
	VeKhung(3,60);
	gotoxy(150,24);
	VeNut(" OK ");
	gotoxy(103,19);
	ShowCur(1);
}
void VeKhungNhapCauHoi(){
	SetColor(11);
	gotoxy(50, 7);
	VeKhung(40,153);
	SetColor(10);
	gotoxy(120,8);
	cout << "NHAP CAU HOI";
	SetColor(7);
	gotoxy(55,11);
	cout << "NHAP MA MH:";
	SetColor(13);
	gotoxy(70,10);
	VeKhung(3,60);
	SetColor(7);
	gotoxy(55,14);
	cout << "NHAP NOI DUNG CAU HOI:";
	gotoxy(60,15);
	VeKhung(5,133);
	gotoxy(55,20);
	cout << "NHAP DAP AN A:";
	gotoxy(60,21);
	VeKhung(4,133);
	gotoxy(55,25);
	cout << "NHAP DAP AN B:";
	gotoxy(60,26);
	VeKhung(4,133);
	gotoxy(55,30);
	cout << "NHAP DAP AN C:";
	gotoxy(60,31);
	VeKhung(4,133);
	gotoxy(55,35);
	cout << "NHAP DAP AN D:";
	gotoxy(60,36);
	VeKhung(4,133);
	gotoxy(55,40);
	cout << "DAP AN DUNG LA:";
	gotoxy(60,41);
	VeNut(" A ");
	gotoxy(70,41);
	VeNut(" B ");
	gotoxy(80,41);
	VeNut(" C ");
	gotoxy(90,41);
	VeNut(" D ");
	gotoxy(180,42);
	VeNut("  OK  ");
	gotoxy(71,11);
	ShowCur(1);
}
void VeKhungNhapDLInCH(){
	SetColor(11);
	gotoxy(85,15);
	VeKhung(13,80);
	SetColor(10);
	gotoxy(107, 14);
	cout << "NHAP MA SV VA MA MH DE IN DS CAU HOI";
	gotoxy(87, 17);
	cout << "NHAP MA SV:";
	gotoxy(87,21);
	cout << "NHAP MA MH:";
	SetColor(13);
	gotoxy(100, 16);
	VeKhung(3,30);
	SetColor(7);
	gotoxy(100,20);
	VeKhung(3,60);
	gotoxy(123,24);
	VeNut(" OK ");
	gotoxy(101,17);
	ShowCur(1);
}
void VeKhungInCH(){
	ShowCur(0);
	SetColor(11);
	gotoxy(50, 12);
	VeKhung(33,153);
	SetColor(7);
	gotoxy(55,14);
	cout << "NOI DUNG CAU HOI:";
	gotoxy(60,15);
	VeKhung(5,133);
	gotoxy(55,20);
	cout << "DAP AN A:";
	gotoxy(60,21);
	VeKhung(4,133);
	gotoxy(55,25);
	cout << "DAP AN B:";
	gotoxy(60,26);
	VeKhung(4,133);
	gotoxy(55,30);
	cout << "DAP AN C:";
	gotoxy(60,31);
	VeKhung(4,133);
	gotoxy(55,35);
	cout << "DAP AN D:";
	gotoxy(60,36);
	VeKhung(4,133);
	gotoxy(55,40);
	cout << "DAP AN DUNG LA:";
	gotoxy(55, 42);
	cout << "DAP AN DA CHON LA:";
}
void NhapDLXuatDiemThi(){
	SetColor(11);
	gotoxy(85,15);
	VeKhung(13,80);
	SetColor(10);
	gotoxy(107, 14);
	cout << "NHAP MA LOP VA MA MH DE IN DS DIEM!";
	gotoxy(87, 17);
	cout << "NHAP MA LOP:";
	gotoxy(87,21);
	cout << "NHAP MA MH:";
	SetColor(13);
	gotoxy(100, 16);
	VeKhung(3,30);
	SetColor(7);
	gotoxy(100,20);
	VeKhung(3,60);
	gotoxy(123,24);
	VeNut(" OK ");
	gotoxy(101,17);
	ShowCur(1);
}
void VeKhungXuatDiemThi(int x, int y, int sosv){
	gotoxy(x, y);
	for (int i = 0; i < sosv+4; i++){
		for (int j = 0; j < 100; j++){
			if (i == 0){
				if (j == 0) cout << traitren;
				else if(j == 19 || j == 39 || j== 69 || j==84) cout << ngangxuong;
				else if (j == 99) cout << phaitren;
				else cout << ngang;
			}else if(i == 2){
				if(j == 0) cout << docphai;
				else if(j == 99) cout << doctrai;
				else if(j==19 || j==39 || j==69 || j==84) cout << giua;
				else cout << ngang;
			}else if (i == sosv+3){
				if (j == 0) cout << traiduoi;
				else if(j == 19 || j==39 || j==69 || j==84) cout << nganglen;
				else if (j == 99) cout << phaiduoi;
				else cout << ngang;
			}else{
				if (j == 0 || j == 19 || j==39 || j == 69 || j==84 || j==99) cout << doc;
				else cout << " ";
			}
		}
		gotoxy(wherex()-100,wherey()+1);
	}
	SetColor(10);
	gotoxy(wherex()+7, wherey()-sosv-3);
	cout << "MA  SV";
	gotoxy(wherex()+15, wherey());
	cout << "HO";
	gotoxy(wherex()+23, wherey());
	cout << "TEN";
	gotoxy(wherex()+19, wherey());
	cout << "PHAI";
	gotoxy(wherex()+9, wherey());
	cout << "DIEM THI";
	gotoxy(x+35, y-1);
	cout << "DANH SACH DIEM THI";
	SetColor(7);
}
void VeKhungThi(){
	ShowCur(0);
	SetColor(11);
	gotoxy(50, 12);
	VeKhung(33,153);
	SetColor(7);
	gotoxy(55,14);
	cout << "NOI DUNG CAU HOI:";
	gotoxy(60,15);
	VeKhung(5,133);
	gotoxy(55,20);
	cout << "DAP AN A:";
	gotoxy(60,21);
	VeKhung(4,133);
	gotoxy(55,25);
	cout << "DAP AN B:";
	gotoxy(60,26);
	VeKhung(4,133);
	gotoxy(55,30);
	cout << "DAP AN C:";
	gotoxy(60,31);
	VeKhung(4,133);
	gotoxy(55,35);
	cout << "DAP AN D:";
	gotoxy(60,36);
	VeKhung(4,133);
	gotoxy(55,40);
	cout << "DAP AN BAN CHON LA:";
	gotoxy(60,41);
	VeNut(" A ");
	gotoxy(70,41);
	VeNut(" B ");
	gotoxy(80,41);
	VeNut(" C ");
	gotoxy(90,41);
	VeNut(" D ");
}
void VeKhungBaoDiem(){
	SetColor(11);
	gotoxy(70,15);
	VeKhung(14, 60);
	SetColor(3);
	gotoxy(81, 17);
	cout << "Chuc mung ban da hoan thanh bai thi!!";
	SetColor(7);
	gotoxy(75,21);
	cout << "Ban da lam dung        cau.";
	gotoxy(75,23);
	cout << "Diem cua ban la:";
	SetColor(4);
	gotoxy(88, 26);
	cout << "An phim bat ki de thoat!";
	SetColor(7);
	ShowCur(0);
}
void HienThi(int x1, int x2, int y, string text){
	ShowCur(0);
	int h = y;
	gotoxy(x1, h);
	for(int i=0; i<text.length(); i++){
		if(wherex() == x2+1 && text[i]!=32){
			string temp;
			for(int j=i; text[j]!=32; j--){
				temp+=text[j];
				gotoxy(wherex()-1,h);
				cout << " ";
				gotoxy(wherex()-1,h);
			}
			gotoxy(x1,++h);
			for(int z=temp.length()-1; z>=0; z--){
				cout << temp[z];
			}
		}else if(wherex()==x2+1 && text[i]==32){
			cout << text[i];
			gotoxy(x1, ++h);
		}else if(wherex()<=x2){
			cout << text[i];
		}
	}	
	ShowCur(1);
}
