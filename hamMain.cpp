#include "hamDieuKhien.h"

int main(){
	clrscr();
	fullscreen();
	srand(time(0));
	DS_MON_HOC ds_mh;
	DS_LOP_HOC ds_lh;
	DS_CAU_HOI ds_ch;
	bool kt=true;
	docFileMonHoc(ds_mh);
	docFileLopHoc(ds_lh);
	docFileSinhVienTheoLop(ds_lh);
	docFileCauHoi(ds_ch);
	docFileDeThiTheoLop(ds_lh);
	ChuongTrinhChinh(ds_lh, ds_mh, ds_ch);
	return 0;
}
	
