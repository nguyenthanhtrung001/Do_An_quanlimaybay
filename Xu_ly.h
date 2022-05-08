﻿#ifndef Xu_ly
#define Xy_ly
#include "cau_truc_du_lieu.h"
#include "mylib.h"
#include<cmath>

HANDLE wHnd;
HANDLE rHnd;

ds_may_bay dsmb;
PTR_chuyenbay phead_dscb=NULL;
NODE_hanhkhach root_hk=NULL;

//=============================================== MAY BAY ========================================================
void in_DS_MB(ds_may_bay ds);
int search_ma_may_bay(ds_may_bay& dsmb, int x, int y);
int search_ma_may_bay(ds_may_bay& dsmb, char temp_so_hieu[]);
int vetify_may_bay(char temp_mamb[]);
bool vetify_may_bay_boolean(char temp_mamb[]);
void delete_may_bay(ds_may_bay& dsmb);
void edit_maybay(ds_may_bay& dsmb);
void free_memory(ds_ve& danh_sach_ve);
//=========================================== CHUYEN BAY =========================================================
void insert_node_cb(PTR_chuyenbay& phead_cb, node_cb* p);
bool is_the_same_time_30(date_time dt1, date_time dt2);
bool check_12h_chuyen_bay(PTR_chuyenbay& phead_dscb, char temp_so_hieu[], date_time dt);
bool check_12h_chuyen_bay_version_2(PTR_chuyenbay& phead_dscb, PTR_chuyenbay& edit_node, char temp_so_hieu[], date_time dt);
void add_new_ch_bay(PTR_chuyenbay& phead_dscb, ds_may_bay dsmb);
void free_memory(ds_ve& danh_sach_ve);
void update_statement(PTR_chuyenbay& phead_dscb);
void edit_chuyen_bay(PTR_chuyenbay& phead_dscb);
void del_chuyen_bay(PTR_chuyenbay& phead_dscb, ds_may_bay& dsmb);
void sort_chuyen_bay_by_time(PTR_chuyenbay& phead_dscb);
void in_DS_chuyen_bay(PTR_chuyenbay& phead_dscb);
void sort_danh_sach_ve(ds_ve& dsv);
bool check_empty_ve(ds_ve& danh_sach_ve, int pos);
void order_ve(PTR_chuyenbay& dscb, PTR_chuyenbay cb, ds_ve& danh_sach_ve);
void remove_ve(ds_ve& danh_sach_ve);
void in_HK_thuoc_chuyen_bay(chuyen_bay cb);
void in_DSCB_Day_place(PTR_chuyenbay& phead_dscb);
void print_empty_ve(ds_ve& danh_sach_ve, char temp_macb[]);
void print_so_luot_thuc_hien(ds_may_bay& dsmb);
//============================================== HANH KHACH ============================================================
NODE_hanhkhach search_hk(char temp_cmnd[], NODE_hanhkhach& root);
hanh_khach create_data(char temp_cmnd[]);
void insert_node_hk(NODE_hanhkhach& root, hanh_khach& data_hk);
NODE_hanhkhach updateTreeAvl(NODE_hanhkhach& t);
NODE_hanhkhach search_hk(char temp_cmnd[], NODE_hanhkhach& root);



//=============================================== HAM BO TRO ========================================================

bool thong_bao_DSMB_0(ds_may_bay ds)
{
	if (ds.n == 0)
	{
		MessageBox(NULL, L"Danh sach may bay trong!", L"THONG BAO", MB_ICONHAND | MB_OK);
		while (kbhit()) getch();
		return true;
	}
	else return false;
}

bool thong_bao_DSCB_0(PTR_chuyenbay  dscb)
{
	if (dscb==NULL)
	{
		MessageBox(NULL, L"Danh sach chuyen bay trong!", L"THONG BAO", MB_ICONHAND | MB_OK);
		while (kbhit()) getch();
		return true;
	}
	return false;
}

bool thong_bao_DSHK_0(NODE_hanhkhach  hk)
{
	if (hk == NULL)
	{
		MessageBox(NULL, L"Chua co hanh khach nao!", L"THONG BAO", MB_ICONHAND | MB_OK);
		while (kbhit()) getch();
		return true;
	}
	return false;
}

//Ham xoa thanh cong cu 
void Xoa_chucnang(int x, int n, string s) {
	gotoxy(x, 1);
	SetBGColor(7);
	cout << " " << s << " ";
	SetBGColor(15);
	for (int i = 2; i <= n; i++) {
		gotoxy(x, i);
		cout << "                               ";
	}
}
void resizeConsole(int width, int height)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	SMALL_RECT windowSize = { 0, 0, width, height };
	COORD bufferSize = { width, height };
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
}
//ham tat con tro chuot Console
void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
void Chuyenmau(int x, int y, int ma_BG, int ma_Kitu, string s) {
	gotoxy(x, y);
	SetBGColor(ma_BG);
	SetColor(ma_Kitu);
	cout << s;
	SetBGColor(15);
	SetColor(0);
	gotoxy(x, y);
}

void Chuyenmau_do( string s) {
	
	
	SetBGColor(15);
	SetColor(4);
	cout << s;	
	SetColor(1);
	
}
void Chuyenmau_xanh(string s) {


	SetBGColor(15);
	SetColor(66);
	cout << s;
	SetColor(1);

}


void Ve_congcu(int x, string s) {
	SetBGColor(1); SetColor(0);
	gotoxy(x, 1);
	cout << char(186);
	Chuyenmau(x + 1, 1, 1, 15, s);
	SetBGColor(1); SetColor(0);
	gotoxy(x + 30, 1); cout << char(186);
	gotoxy(x, 2);
	cout << char(200);  for (int v = 1; v <= 29; v++) cout << char(205);    cout << char(188);
}
void ve_thanhcongcu() {
	gotoxy(0, 1);
	SetBGColor(15);
	SetColor(0);
	for (int i = 1; i <= 3; i++) {
		cout << char(186);
		for (int j = 1; j <= 148; j++) {
			if (i == 1) {
				if (j == 4 || j == 40 || j == 78 || j == 114) {
					SetColor(0);
					SetBGColor(7);
					if (j == 4)cout << "      QUAN LY MAY BAY          ";
					if (j == 40)cout << "      QUAN LY CHUYEN BAY       ";
					if (j == 78)cout << "         DAT / HUY VE          ";
					if (j == 114)cout << "       THONG KE DU LIEU        ";
					j = j + 30;
				}
				else {
					SetBGColor(15);
					cout << " ";
				}
			}
			else {
				SetBGColor(15);
				cout << " ";
			}
		}
		if (i != 3) {
			SetBGColor(15);
			cout << char(186);
			cout << endl;
		}
	}
}
// Ham ve Giao dien man hinh chinh
void Giaodien_main() {
	//ve duong thang tren 
	SetBGColor(15);
	SetColor(0);
	cout << char(201);
	for (int i = 1; i <= 148; i++) cout << char(205);
	cout << char(187);
	cout << endl;
	//ve man hinh trung tam 
	for (int i = 1; i <= 42; i++) {
		cout << char(186);
		for (int j = 1; j <= 148; j++) {
			if (i == 1) {
				ve_thanhcongcu();
				j = 148;
				i = 3;
			}
			else {
				cout << " ";
			}

		}
		SetColor(0);
		SetBGColor(15);
		cout << char(186);
		cout << endl;
	}
	//ve duong thang duoi
	cout << char(200);
	for (int i = 1; i <= 148; i++) cout << char(205);
	cout << char(188);
	cout << endl;
}
int DisplayConfirmSaveAsMessageBox()
{
	
	int msgboxID = MessageBox(
		NULL,
		L"So hieu May bay da ton tai, nhap lai !",
		L"Confirm Save As",
		MB_ICONEXCLAMATION | MB_OK
	);


	//int msgboxID = MessageBox(NULL, L"So hieu May bay da ton tai, nhap lai !", L"Confirm Save As", MB_ICONEXCLAMATION | MB_OK);
	return msgboxID;
}
int DisplayConfirmSaveAsMessageBox_so_cho()
{
	int msgboxID = MessageBox(
		NULL,
		L"So cho phai nhieu hon hoac bang 20 va nho hon hoac bang 300 !\n\t( 20 <= So cho <= 300 )",
		L"Confirm Save As",
		MB_ICONEXCLAMATION | MB_OK
	);



	return msgboxID;
}
void mau_ban_dau()
{
	SetColor(15);
	SetBGColor(64);
}
int Nhanphim() {
    int c = _getch();

    if (c == 224) {
        c = _getch();
        return c;
    }
    else return c;
}
void Ve_bang(int x, int y, int n, int m, int dem) {// vẽ tại x y, n đường kẻ ngang , m kẻ dọc
	int ngang = (m - 1) * 20 + 5, doc = n * 3;// 30 chiều dài ô,5 là khoảng cách giữa các cột

	SetColor(64);

	int tempx = x, tempy = y;
	int i = 1;
	while (i <= n) {
		if (i == 1) {
			SetBGColor(15);

			gotoxy(x, y); cout << char(218);
			for (int j = 1; j <= ngang - 2; j++) cout << char(196);
			cout << char(191);
			SetBGColor(0);

			gotoxy(x, ++y);
			for (int j = 1; j <= ngang; j++) {
				if (j == 1 || j == ngang || j == 5 || (j - 5) % 20 == 0) cout << char(179);
				else { SetBGColor(1); cout << " "; SetBGColor(15); }
			}

			gotoxy(x, ++y);
			cout << char(179); //dọc
			for (int j = 1; j <= ngang - 2; j++) cout << char(196);// ngang
			cout << char(179);// kẻ dọc
		}
		else if (i == n) {
			gotoxy(x, ++y);
			for (int j = 1; j <= ngang; j++) {
				if (j == 1 || j == ngang || j == 5 || (j - 5) % 20 == 0) cout << char(179);
				else cout << " ";
			}
			gotoxy(x, ++y);
			cout << char(192);
			for (int j = 1; j <= ngang - 2; j++) cout << char(196); cout << char(217);
		}
		else {
			gotoxy(x, ++y);
			for (int j = 1; j <= ngang; j++) {
				if (j == 1 || j == ngang || j == 5 || (j - 5) % 20 == 0) cout << char(179);
				else cout << " ";
			}
			gotoxy(x, ++y);
			cout << char(179);
			for (int j = 1; j <= ngang - 2; j++) cout << char(196);
			cout << char(179);
		}
		i++;
	}
	for (int i = 1; i <= n - 1; i++) {

		gotoxy(tempx + 1, i * 2 + tempy + 1); cout << dem++;
	}

}
void Xoa_khunhap() {
	gotoxy(0, 5);
	SetBGColor(15);
	SetColor(0);
	for (int i = 5; i <= 41; i++)
	{

		for (int j = 1; j <= 148; j++)
		{
			cout << " ";
		}
		cout << endl;
	}

}
void Nhan_chu(char t[], int x, int y, int dem, int& ktra) {
	fflush(stdin);
	int d = 0, ch, tempx = x, dem_cach = 0;
	gotoxy(x, y);
	cout << t;
	d = strlen(t);// chiều dài chuỗi kí tự
	x = x + strlen(t);
	while (1) {
		while (kbhit()) {
			// cho phep nhap ki tu
			if (ktra == 2) {
				ch = _getch();
				if (ch == 224) {
					ktra = _getch();
					if (ktra == 77 || ktra == 80)
						return;
					else (ktra = 2);
				}
				if (ch >= 65 && ch <= 90) {
					if (d < dem) {
						dem_cach = 0;
						cout << char(ch);
						t[d] = char(ch);
						d++;
						x++;
					}
				}
				if (ch >= 97 && ch <= 122) {
					if (d < dem) {
						dem_cach = 0;
						cout << char(ch);
						t[d] = char(ch);
						d++;
						x++;
					}
				}
				if (ch == 32) {
					if (d < dem) {
						if (dem_cach == 0 && d != 0) {
							dem_cach = 1;
							cout << char(ch);
							t[d] = char(ch);
							d++;
							x++;
						}
					}
				}
				if (ch == 8) {
					dem_cach = 0;
					if (d > 0) t[d - 1] = '\0';
					if (x > tempx) {
						d--;
						x--;
					}
					gotoxy(x, y); cout << " ";
					gotoxy(x, y);
				}
				if (ch == 13) {
					if (t[d - 1] == ' ') {
						t[d - 1] = '\0';
					}
					return;
				}
				
			}
			// cho phep nhap ki tu va so
			if (ktra == 1) {
				ch = 0;
				ch = _getch();
				if (ch == 224) {
					ktra = _getch();
					if (ktra == 77 || ktra == 80)
						return;
					else ktra = 1;
				}
				if (ch >= 65 && ch <= 90) {
					if (d < dem) {
						dem_cach = 0;
						cout << char(ch);
						t[d] = char(ch);
						d++;
						x++;
					}
				}
				if (ch >= 97 && ch <= 122) {
					if (d < dem) {
						dem_cach = 0;
						cout << char(ch);
						t[d] = char(ch);
						d++;
						x++;
					}
				}
				if (ch >= 48 && ch <= 57) {
					if (d < dem) {
						dem_cach = 0;
						cout << char(ch);
						t[d] = char(ch);
						d++;
						x++;
					}
				}
				if (ch == 32)// phim pacse
				{
					if (d < dem) {
						if (dem_cach == 0 && d != 0) {
							dem_cach = 1;
							cout << char(ch);
							t[d] = char(ch);
							d++;
							x++;
						}
					}
				}
				if (ch == 8) // phism backspace
				{
					dem_cach = 0;
					if (d > 0) t[d - 1] = '\0';
					if (x > tempx) {
						d--;
						x--;
					}
					gotoxy(x, y); cout << " ";
					gotoxy(x, y);
				}
				if (ch == 13)// phim enter
				{
					if (t[d - 1] == ' ') {
						t[d - 1] = '\0';
					}
					return;
				}
				
				
			}
			//cho phep nhap so
			if (ktra == 3) {
				ch = _getch();
				if (ch == 224) {
					ch = 0;
					ktra = _getch();
					if (ktra == 77 || ktra == 80)
						return;
					else ktra = 3;
				}
				if (ch >= 48 && ch <= 57) {
					if (d < dem) {
						cout << char(ch);
						t[d] = char(ch);
						d++;
						x++;
					}
				}
				if (ch == 8) {
					if (d > 0) t[d - 1] = '\0';
					if (x > tempx) {
						d--;
						x--;
					}
					gotoxy(x, y); cout << " ";
					gotoxy(x, y);
				}
				if (ch == 13) {
					if (t[d - 1] == ' ') {
						t[d - 1] = '\0';
					}
					return;
				}
				
			}
		}
	}

}
void Nhan_so(int& tempso, int x, int y, int dem, int& ktra) {
	int d = 0, ch = 0, cd = 0, tempx = x, t = tempso;
	while (tempso > 0) {
		tempso /= 10;
		cd++;
	}
	tempso = t;
	gotoxy(x, y);
	if (tempso != 0) cout << tempso;
	x += cd;
	d = cd;
	while (1) {
		while (kbhit()) {
			ch = 0;
			ch = getch();
			if (ch == 224) {
				ktra = getch();
				if (ktra == 77 || ktra==80 )
				{
					return;
					
				}
				
			}
			if (ch >= 48 && ch <= 57) {
				if (d < dem) {
					cout << ch - 48;
					tempso = tempso * 10 + ch - 48;
					d++;
					x++;
				}
			}
			if (ch == 8) {
				tempso = tempso / 10;
				if (x > tempx) {
					d--;
					x--;
				}
				gotoxy(x, y); cout << " ";
				gotoxy(x, y);
			}
			if (ch == 13) return;
		}
	}
}
void Nhan_chu2(char t[], int x, int y, int dem,ds_may_bay &dsmb, int& ktra) {
	
	
	
	fflush(stdin);
	int d = 0, ch, tempx = x, tempy = y, dem_cach = 0;
	char temp_t[16] = "";
	gotoxy(x, y);
	cout << t;
	d = strlen(t);//0
	x = x + strlen(t);
	while (1) {
		//1.kiểm tra và xuất ra gợi ý cho số hiệu máy bay từ ds máy bay
		if (ktra == 1 && strcmp(t, temp_t) != 0) {//chiều dài hợp lệ
			
			ShowConsoleCursor(false);// tắt
			int dgy = 0, d1 = 0;
			strupr(t);// chuyển chữ hoa
			strcpy(temp_t, t);// copy

			SetBGColor(3);
			SetColor(1);
			gotoxy(tempx, y + 1); cout << "                                       ";
			gotoxy(tempx, y + 2); cout << "                                       ";
			gotoxy(tempx, y + 3); cout << "                                       ";
			gotoxy(tempx, y + 4); cout << "                                       ";
			gotoxy(tempx, y + 5); cout << "                                       ";
			gotoxy(2, 2);
			
		
			for (int i = dsmb.n - 1; i >= 0; i--) {
				if (dgy == 5) {
					break;
				}
				char temp_so_hieu[16] = "";
			//	if (dsmb.data[i]->active == 0) { continue; }
				
				
				strcpy(temp_so_hieu, dsmb.data[i]->so_hieu_may_bay);
				
				d1 = 0;
				for (int j = 0; j < d; j++) {
					if (t[j] == temp_so_hieu[j])
					{
						
						d1++;
					}
				}
				if (d1 == d) {
					dgy++;
					gotoxy(tempx, y + dgy);
					cout << dsmb.data[i]->so_hieu_may_bay;
				}
			}
			if (dgy == 0) 
			{
				SetColor(1);
				gotoxy(tempx, y + 1); cout << "                                       ";
				gotoxy(tempx, y + 2); cout << "                                       ";
				gotoxy(tempx, y + 3); cout << "                                       ";
				gotoxy(tempx, y + 4); cout << "                                       ";
				gotoxy(tempx, y + 5); cout << "                                       ";
				gotoxy(tempx + 8, y + 2);
				cout << "KHONG TIM THAY DU LIEU";
			}
		
			SetBGColor(11);
			SetColor(0);
		}
		//chuyến bay 
		//4.còn vé và hết vé   // 3.còn vé    //2.tất cả 4 trạng thái

		if ((ktra == 2 || ktra == 3 || ktra == 4) && strlen(t) != 0 && strcmp(t, temp_t) != 0) {
			ShowConsoleCursor(false);
			node_cb* ptr = new node_cb;
			ptr = phead_dscb;
			int dgy = 0, d1 = 0;
			strupr(t);
			strcpy(temp_t, t);
			SetBGColor(3);
			SetColor(1);
			gotoxy(tempx - 1, y + 1); cout << "                                     ";
			gotoxy(tempx - 1, y + 2); cout << "                                     ";
			gotoxy(tempx - 1, y + 3); cout << "                                     ";
			gotoxy(tempx - 1, y + 4); cout << "                                     ";
			gotoxy(tempx - 1, y + 5); cout << "                                     ";
			while (ptr != NULL) {
				if (dgy == 5) {
					break;
				}
				char temp_macb[16] = "";
				strcpy(temp_macb, ptr->data.macb);
				d1 = 0;
				for (int j = 0; j < d; j++) {
					if (t[j] == temp_macb[j]) d1++;
				}
				if (d1 == d) {
					if (ktra == 4 && (ptr->data.trang_thai == 1 || ptr->data.trang_thai == 2)) {
						dgy++;
						gotoxy(tempx, y + dgy);
						cout << temp_macb;
					}
					if (ktra == 3 && ptr->data.trang_thai == 1) {
						dgy++;
						gotoxy(tempx, y + dgy);
						cout << temp_macb;
					}
					if (ktra == 2) {
						dgy++;
						gotoxy(tempx, y + dgy);
						cout << temp_macb;
					}
				}
				ptr = ptr->pnext;
			}
			if (dgy == 0) {
				SetColor(1);
				gotoxy(tempx - 1, y + 1); cout << "                                     ";
				gotoxy(tempx - 1, y + 2); cout << "                                     ";
				gotoxy(tempx - 1, y + 3); cout << "                                     ";
				gotoxy(tempx - 1, y + 4); cout << "                                     ";
				gotoxy(tempx - 1, y + 5); cout << "                                     ";
				gotoxy(tempx + 6, y + 2);
				cout << "KHONG TIM THAY DU LIEU";
			}
			SetBGColor(11);
			SetColor(0);
		}

		while (kbhit()) {
			gotoxy(x, y);
			ShowConsoleCursor(true);
			ch = 0;
			ch = getch();
			if (ch == 224) {
				ch = getch();
				ch = 0;
			}
			if (ch >= 65 && ch <= 90) {
				if (d < dem) {
					dem_cach = 0;
					cout << char(ch);
					t[d] = char(ch);
					d++;
					x++;
				}
			}
			if (ch >= 97 && ch <= 122) {
				if (d < dem) {
					dem_cach = 0;
					cout << char(ch);
					t[d] = char(ch);
					d++;
					x++;
				}
			}
			if (ch >= 48 && ch <= 57) {
				if (d < dem) {
					dem_cach = 0;
					cout << char(ch);
					t[d] = char(ch);
					d++;
					x++;
				}
			}
			if (ch == 32) {
				if (d < dem) {
					if (dem_cach == 0 && d != 0) {
						dem_cach = 1;
						cout << char(ch);
						t[d] = char(ch);
						d++;
						x++;
					}
				}
			}
			if (ch == 8) {
				dem_cach = 0;
				
				if (d > 0) t[d - 1] = '\0';
				if (x > tempx) {
					d--;
					x--;
				}
				

				gotoxy(x, y); cout << " ";
				gotoxy(x, y);
			}
			if (ch == 13) {
				if (t[d - 1] == ' ') {
					t[d - 1] = '\0';
				}
				return;
			}
		}

	}
}
void ve_hcnrong(int x, int y, int n, int m)
{
	gotoxy(x, y);
	cout << char(218);
	for (int i = 1; i <= n - 2; i++) {
		cout << char(196);
	}
	cout << char(191); gotoxy(x, ++y);
	int j = 1;
	while (j <= m - 2) {
		cout << char(179);
		for (int i = 1; i <= n - 2; i++) {
			cout << " ";
		}
		cout << char(179); gotoxy(x, ++y);
		j++;
	}
	cout << char(192);
	for (int i = 1; i <= n - 2; i++) {
		cout << char(196);
	}
	cout << char(217);
}
void Loading(int x, int y) {
	Xoa_khunhap();
	//	gotoxy(x+25,y+7); cout<<"LOADING...";
	gotoxy(x + 25, y + 7); cout << "THONG BAO";
	ve_hcnrong(x + 10, y + 8, 40, 3);
	SetBGColor(10);
	SetColor(15);
	gotoxy(x + 11, y + 9);
	int j = 1;
	//	while (j!=39){
	//		    while(kbhit()) getch();
	//			cout<<" ";
	//			if (j>30 && j<=35) Sleep(50);
	//			else Sleep(20);
	//			j++;
	//		}
	for (; j <= 38; j++) {
		cout << " ";
	}
	Sleep(400);
}
//Ham viet hoa chu cai dau va sau khoang trang
void Viet_hoa(char t[]) {
	strlwr(t);
	t[0] = toupper(t[0]);
	for (int i = 1; i <= strlen(t); i++) {
		if (t[i] == ' ') {
			t[i + 1] = toupper(t[i + 1]);
		}
	}
}

int so_luong_tt_1_2(PTR_chuyenbay  dscb)
{
	if (dscb == NULL) return 0;
	int cnt = 0;
	PTR_chuyenbay p = dscb;
	while (p != NULL)
	{
		if (p->data.trang_thai != 0 && p->data.trang_thai != 3)
		{
			cnt++;
		}
		p = p->pnext;
	}
	return cnt;
	
}







//=============================================== ND MAY BAY ========================================================

int	vetify_may_bay(char temp_mamb[]) {//  số lượng chuyến bay 1-2 của 1 số hiệu hiệu máy bay
	node_cb* ptr = new node_cb;
	ptr = phead_dscb;
	int count = 0;
	while (ptr != NULL) {
		if (ptr->data.danh_sach_ve.n == ptr->data.danh_sach_ve.limit && ptr->data.trang_thai != 0) {
			ptr->data.trang_thai = 2;
		}

		if (check_depart_time(ptr->data.depart_time) == false && ptr->data.trang_thai != 0) {
			ptr->data.trang_thai = 3;
		}
		if (strcmp(ptr->data.so_hieu_may_bay, temp_mamb) == 0 && ptr->data.trang_thai != 3 && ptr->data.trang_thai != 0) {
			count++;
		}
		ptr = ptr->pnext;
	}
	return count;
}
bool vetify_may_bay_boolean(char temp_mamb[]) {
	node_cb* ptr = new node_cb;// duyệt chuyến bay tìm số hiệu máy bay
	ptr = phead_dscb;
	while (ptr != NULL) {
		if (strcmp(ptr->data.so_hieu_may_bay, temp_mamb) == 0) {
			return false;
		}
		ptr = ptr->pnext;
	}
	return true;
}
//Ham tim chuyen bay
PTR_chuyenbay search_node(PTR_chuyenbay& phead_cb, char temp_macb[]) {
	node_cb* ptr = phead_cb;
	while (ptr != NULL) {
		if (strcmp(ptr->data.macb, temp_macb) == 0) {
			return ptr;
		}
		ptr = ptr->pnext;
	}
	return NULL;
}
//Ham tim may bay co ma may bay  
int search_ma_may_bay(ds_may_bay& dsmb, char temp_so_hieu[]) {
	for (int i = 0; i < dsmb.n; i++) {
		if (strcmp(dsmb.data[i]->so_hieu_may_bay, temp_so_hieu) == 0) {
			return i;
		}
	}
	return -1;
}
//Ham tim may bay khong can ma may bay  
int search_ma_may_bay(ds_may_bay& dsmb, int x, int y) {
	
	int ktra = 1;
	char temp_so_hieu[16] = "";
	gotoxy(x + 6, y + 5); cout << "So Hieu MB :                                        ";
	do {
		
		Nhan_chu2(temp_so_hieu, x + 19, y + 5, 15,dsmb, ktra); //hàm bất kí tự chữ và số có gợi ý
	} while (strlen(temp_so_hieu) == 0);
	strupr(temp_so_hieu);
	
	for (int i = 0; i < dsmb.n; i++) {
		if (strcmp(dsmb.data[i]->so_hieu_may_bay, temp_so_hieu) == 0) {
			return i;
		}
	}
	return -1;
}
void in_DS_MB(ds_may_bay ds)
{
	if (ds.n == 0) return;
	int x = 4, y = 8, n = 16, j = 3, dem = 1, pageht = 0, page = 0, cd = 0;

    Ve_bang(x, y, n, 4, dem);

	SetBGColor(1);
	SetColor(15);

	gotoxy(x + 1, y + 1); cout << "STT";
	gotoxy(x + 9, y + 1); cout << "So Hieu MB";
	gotoxy(x + 29, y + 1); cout << "Loai May bay";
	gotoxy(x + 51, y + 1); cout << "So Cho";
	//SetBGColor(15);
	SetColor(64);
	SetBGColor(15);

	//SetBGColor(15);



	for (int i = 0; i < ds.n && i < 15; i++)
	{


		gotoxy(x + 6, y + j); cout << ds.data[i]->so_hieu_may_bay;
		gotoxy(x + 26, y + j); cout << ds.data[i]->loai_may_bay;
		gotoxy(x + 46, y + j); cout << ds.data[i]->socho;
		j += 2;


	}

	page = ds.n / 15;
	if (page == 0) page = 1;
	if ((ds.n - (page * 15)) > 0) page++;
	pageht = 1;
	gotoxy(x + 30, y + 33); cout << pageht << "/" << page;
	int np = 0;
	while (1) {
		np = Nhanphim(); int k = 0;
		if (np == 27 || np == 13) break;
		if (np == 77 && pageht < page) {// sang phaỉ
			pageht++;
			k = 1;
		}
		if (np == 75 && pageht > 1) {// sang trái
			pageht--;
			k = 1;
		}
		if (k == 1) {

			dem = pageht * 15 - 14;
			Ve_bang(x, y, n, 4, dem);
			SetBGColor(1);
			SetColor(15);
			gotoxy(x + 1, y + 1); cout << "STT";
			gotoxy(x + 12, y + 1); cout << "So hieu MB";
			gotoxy(x + 29, y + 1); cout << "Loai May Bay";
			gotoxy(x + 48, y + 1); cout << "So Cho";
			SetBGColor(15);
			SetColor(64);

			j = 3;
			for (int i = dem - 1; i < ds.n && i < pageht * 15; i++)
			{

				gotoxy(x + 6, y + j); cout << ds.data[i]->so_hieu_may_bay;
				gotoxy(x + 26, y + j); cout << ds.data[i]->loai_may_bay;
				gotoxy(x + 46, y + j); cout << ds.data[i]->socho;
				j += 2;


			}

			gotoxy(x + 30, y + 33); cout << pageht << "/" << page;
		}
		
	}
	ShowConsoleCursor(false);
	





}
//Ham them may bay vao danh sach
void add_new_MB(ds_may_bay& dsmb) {
	
	int x = 42, y = 12, ktra;
	char temp_so_hieu[16] = "";
	char temp_loai_may_bay[41] = "";
	int temp_socho = 0;
	ShowConsoleCursor(true);
	ve_hcnrong(x, y, 64, 19);
	ve_hcnrong(x + 5, y + 5, 54, 3);
	ve_hcnrong(x + 5, y + 9, 54, 3);
	ve_hcnrong(x + 5, y + 13, 54, 3);
	SetBGColor(14);
	SetColor(32);
	gotoxy(x + 7, y + 2); cout << " [NHAP DU LIEU MAY BAY BAN MUON THEM VAO DANH SACH] ";
	SetBGColor(11);
	SetColor(0);
	gotoxy(x + 6, y + 6); cout << "So Hieu MB :                                        ";
	gotoxy(x + 6, y + 10); cout << "Loai MB    :                                        ";
	gotoxy(x + 6, y + 14); cout << "So cho     :                                        ";
	fflush(stdin);

	do {
		do {
			ktra = 1;
			Nhan_chu(temp_so_hieu, x + 19, y + 6, 15, ktra);
		} while (strlen(temp_so_hieu) == 0);
		strupr(temp_so_hieu);
		if (search_ma_may_bay(dsmb, temp_so_hieu) != -1) {
			DisplayConfirmSaveAsMessageBox();
			while (kbhit()) getch();
		}
	} while (search_ma_may_bay(dsmb, temp_so_hieu) != -1);


	do {
		ktra = 1;
		Nhan_chu(temp_loai_may_bay, x + 19, y + 10, 40, ktra);
	} while (strlen(temp_loai_may_bay) == 0);


	strupr(temp_loai_may_bay);

	do {
		gotoxy(x + 19, y + 14); cout << "   ";
		ktra = 0;
		temp_socho = 20;
		Nhan_so(temp_socho, x + 19, y + 14, 3, ktra);
		if (temp_socho < 20 || temp_socho > 300) {
			DisplayConfirmSaveAsMessageBox_so_cho();

			while (kbhit()) getchar();
		}
	} while (temp_socho == 0 || temp_socho < 20 || temp_socho > 300);

	may_bay* mb = new may_bay;


	strcpy(mb->so_hieu_may_bay, temp_so_hieu);
	strcpy(mb->loai_may_bay, temp_loai_may_bay);
	mb->socho = temp_socho;
	dsmb.data[dsmb.n] = mb;
	dsmb.n++;

	ShowConsoleCursor(false);
	//mau_ban_dau();
	Xoa_khunhap();
	

}
void edit_maybay(ds_may_bay& dsmb) {
	if (thong_bao_DSMB_0(dsmb)) return;
	in_DS_MB(dsmb);
	int x = 42 + 30, y = 12, ktra;
	ve_hcnrong(x, y, 64, 10);//vẽ hình chữ nhật rỗng vị trí x y chiều dài 64 chiều rộng 10
	ve_hcnrong(x + 5, y + 4, 54, 3);
	SetBGColor(14);
	gotoxy(x + 10, y + 2); cout << " [NHHAP VAO SO HIEU MAY BAY BAN MUON HIEU CHINH] ";
	ShowConsoleCursor(true);
	SetBGColor(11);
	int result = search_ma_may_bay(dsmb, x, y);// tìm kiếm máy bay



	if (result == -1) {
		int msgboxID = MessageBox(NULL, L"MAY BAY KHONG TON TAI !", L"Confirm Save As", MB_ICONEXCLAMATION | MB_OK);
		while (kbhit()) getchar();
		ShowConsoleCursor(false);
		Xoa_khunhap();
	}



	else {
		SetBGColor(15);
		ve_hcnrong(x, y, 64, 18);
		ve_hcnrong(x + 5, y + 5, 54, 3);
		ve_hcnrong(x + 5, y + 9, 54, 3);
		ve_hcnrong(x + 5, y + 14, 54, 3);
		SetBGColor(14);
		gotoxy(x + 10, y + 2); cout << "[NHHAP VAO DU LIEU MAY BAY BAN MUON HIEU CHINH]";
		SetBGColor(11);
		SetColor(0);
		char temp_so_hieu[15] = "";
		char temp_loai_may_bay[40] = "";
		int temp_socho = dsmb.data[result]->socho;
		strcpy(temp_loai_may_bay, dsmb.data[result]->loai_may_bay);
		gotoxy(x + 6, y + 6); cout << "So Hieu MB :                                        ";
		gotoxy(x + 6, y + 10); cout << "Loai MB    :                                        ";
		gotoxy(x + 6, y + 15); cout << "So cho     :                                        ";
		gotoxy(x + 19, y + 6); cout << dsmb.data[result]->so_hieu_may_bay;
		gotoxy(x + 19, y + 10); cout << dsmb.data[result]->loai_may_bay;
		gotoxy(x + 19, y + 15); cout << dsmb.data[result]->socho;
		fflush(stdin);

		bool check = false;// kiem tra co trong chuyen bay hay kh

		if (vetify_may_bay_boolean(dsmb.data[result]->so_hieu_may_bay) == true)
		{
			do {
				ktra = 1;// nhap chu va so
				Nhan_chu(temp_loai_may_bay, x + 19, y + 10, 40, ktra);
			} while (strlen(temp_loai_may_bay) == 0);
			strupr(temp_loai_may_bay);
			check = true;

		}


		do {
			temp_socho = dsmb.data[result]->socho;
			ktra = 0;
			gotoxy(x + 19, y + 15); cout << "    ";
			temp_socho = dsmb.data[result]->socho;
			Nhan_so(temp_socho, x + 19, y + 15, 4, ktra);
			if (temp_socho < dsmb.data[result]->socho && check == false)
			{
				int msgboxID = MessageBox(NULL, L"May bay da duoc dua vao danh sach chuyen bay \n\t \"So cho\" >=  ban dau", L"THONG BAO", MB_ICONHAND | MB_OK);
				while (kbhit()) getchar();
			}

		} while (temp_socho == 0 || temp_socho < 20 || temp_socho < dsmb.data[result]->socho && check == false || temp_socho >300);



		strcpy(dsmb.data[result]->loai_may_bay, temp_loai_may_bay);
		dsmb.data[result]->socho = temp_socho;
		ShowConsoleCursor(false);
		Loading(x, y);
		gotoxy(x + 11, y + 9); cout << "        CHINH SUA THANH CONG !";
		Sleep(500);
		Xoa_khunhap();
	}
}
void delete_may_bay(ds_may_bay& dsmb) {
	if (thong_bao_DSMB_0(dsmb)) return;
	in_DS_MB(dsmb);
	int x = 42+30, y = 12;
	ve_hcnrong(x, y, 64, 18);
	ve_hcnrong(x + 5, y + 4, 54, 3);
	SetBGColor(14);
	gotoxy(x + 12, y + 2); cout << " [NHAP VAO SO HIEU MAY BAY BAN MUON XOA] ";
	SetBGColor(11);
	ShowConsoleCursor(true);
	int result = search_ma_may_bay(dsmb, x, y);
	if (result == -1) {
		MessageBox(NULL, L"MAY BAY KHONG TON TAI !!", L"THONG BAO", MB_ICONWARNING | MB_OK);
		while (kbhit()) getch();
		ShowConsoleCursor(false);
		Xoa_khunhap();
		return;
	}
	int times = vetify_may_bay(dsmb.data[result]->so_hieu_may_bay);    // tra ve sl trang thai 1-2
	if (times == 0) {

		for (int i = result; i < dsmb.n - 1; i++) {
			*dsmb.data[i] = *dsmb.data[i + 1];
		}
		dsmb.n--;
		
		ShowConsoleCursor(false);
		
		Xoa_khunhap();
		Loading(x, y);
		gotoxy(x + 11, y + 9); cout << "           XOA THANH CONG !";
		Sleep(500);
		Xoa_khunhap();
		return;

	}
	else if (times != 0) {
		ShowConsoleCursor(false);
		MessageBox(NULL, L"Khong the xoa vi May bay nay con chuyen bay phai thuc hien!", L"THONG BAO", MB_ICONHAND | MB_OK);
		while (kbhit()) getch();
		Xoa_khunhap();
		return;
	}

}

//=============================================== ND CHUYEN BAY ========================================================


bool check_12h_chuyen_bay(PTR_chuyenbay& phead_dscb, char temp_so_hieu[], date_time dt) {


	node_cb* ptr = phead_dscb;



	while (ptr != NULL) {
		if (strcmp(ptr->data.so_hieu_may_bay, temp_so_hieu) == 0 && ptr->data.trang_thai != 0) {
			// ngay-thang-nam// chênh lệch nhau 1 ngày
			if (ptr->data.depart_time.day == dt.day && ptr->data.depart_time.mon == dt.mon
				&& ptr->data.depart_time.year == dt.year) {

				if (ptr->data.depart_time.hour != dt.hour) {
					int time = abs((ptr->data.depart_time.hour * 60 + ptr->data.depart_time.min)
						- (dt.hour * 60 + dt.min));
					if (time < 720) {
						return false;
					}
				}

				else if (ptr->data.depart_time.hour == dt.hour) return false;
			}
			// tháng-năm--chênh lệch ngày
			else if (abs(ptr->data.depart_time.day - dt.day) == 1 && ptr->data.depart_time.mon == dt.mon
				&& ptr->data.depart_time.year == dt.year) {

				//cach nhau 1 ngay, cb truoc ptr->data
				if (ptr->data.depart_time.day > dt.day) {
					int time = (ptr->data.depart_time.hour * 60 + ptr->data.depart_time.min)
						+ (1440 - (dt.hour * 60 + dt.min));
					if (time < 720) return false;
				}

				//cach nhau 1 ngay, cb sau ptr->data
				else if (dt.day > ptr->data.depart_time.day) {
					int time = (1440 - (ptr->data.depart_time.hour * 60 + ptr->data.depart_time.min))
						+ (dt.hour * 60 + dt.min);
					if (time < 720) return false;
				}
			}
			// năm-chênh lệch tháng->1 ngày ( chuyển tieps ngày tháng)
			else if (ptr->data.depart_time.year == dt.year && abs(ptr->data.depart_time.mon - dt.mon) == 1) {

				if ((ptr->data.depart_time.day == day[ptr->data.depart_time.mon] && dt.day == 1) || (dt.day == day[dt.mon] && ptr->data.depart_time.day == 1)) {
					if (ptr->data.depart_time.mon > dt.mon) {
						if ((ptr->data.depart_time.hour * 60 + ptr->data.depart_time.min) + (1440 - (dt.hour * 60 + dt.min)) < 720) {
							return false;
						}
					}
					else {
						if ((dt.hour * 60 + dt.min) + (1440 - (ptr->data.depart_time.hour * 60 + ptr->data.depart_time.min)) < 720) {
							return false;
						}
					}
				}
			}
			// chênh lệch năm-> chyển đổi tháng-> chênh lệch 1 ngày
			else if (abs(ptr->data.depart_time.year - dt.year) == 1) {
				if (ptr->data.depart_time.day == 31 && ptr->data.depart_time.mon == 12 && dt.day == 1 && dt.mon == 1) {
					if ((1440 - (ptr->data.depart_time.hour * 60 + ptr->data.depart_time.min) + (dt.hour * 60 + dt.min)) < 1880) {
						return false;
					}
				}
				else if (ptr->data.depart_time.day == 1 && ptr->data.depart_time.mon == 1 && dt.day == 31 && dt.mon == 12) {
					if (((1440 - (dt.hour * 60 + dt.min) + ptr->data.depart_time.hour * 60 + ptr->data.depart_time.min)) < 720) {
						return false;
					}
				}

			}

		}
		ptr = ptr->pnext;

	}
	return true;
}
void Ve_khunhap_chbay(int x, int y) {
	SetBGColor(15);
	SetColor(0);
	ve_hcnrong(x, y, 71, 25);
	ve_hcnrong(x + 5, y + 4, 61, 3);
	ve_hcnrong(x + 5, y + 9, 61, 3);
	ve_hcnrong(x + 5, y + 14, 61, 3);
	ve_hcnrong(x + 24, y + 18, 22, 3);
	ve_hcnrong(x + 5, y + 21, 10, 3); ve_hcnrong(x + 15, y + 21, 6, 3); ve_hcnrong(x + 22, y + 21, 6, 3); gotoxy(x + 21, y + 22); cout << ":";
	ve_hcnrong(x + 30, y + 21, 16, 3); ve_hcnrong(x + 46, y + 21, 6, 3); ve_hcnrong(x + 53, y + 21, 6, 3); ve_hcnrong(x + 60, y + 21, 8, 3);
	gotoxy(x + 52, y + 22); cout << "\\"; gotoxy(x + 59, y + 22); cout << "\\";
	SetBGColor(14);
	gotoxy(x + 20, y + 2); cout << " [NHHAP DU LIEU CHUYEN BAY MOI] ";
	gotoxy(x + 25, y + 19); cout << "[Ngay gio khoi hanh]";
	SetBGColor(11);
	gotoxy(x + 6, y + 5); cout << "Ma chuyen bay     :                                        ";
	gotoxy(x + 6, y + 10); cout << "So hieu MB        :                                        ";
	gotoxy(x + 6, y + 15); cout << "San bay den       :                                        ";
	gotoxy(x + 6, y + 22); cout << "Gio:Phut"; gotoxy(x + 16, y + 22); cout << "    "; gotoxy(x + 23, y + 22); cout << "    ";
	gotoxy(x + 31, y + 22); cout << "Ngay\\thang\\nam"; gotoxy(x + 47, y + 22); cout << "    "; gotoxy(x + 54, y + 22); cout << "    "; gotoxy(x + 61, y + 22); cout << "      ";
}
void free_memory(ds_ve& danh_sach_ve) {
	for (int i = danh_sach_ve.n; i < danh_sach_ve.limit; i++) {
		delete danh_sach_ve.so_ghe[i];
		danh_sach_ve.so_ghe[i] = NULL;
	}
}
void update_statement(PTR_chuyenbay& phead_dscb) {

	node_cb* ptr = new node_cb;
	ptr = phead_dscb;

	while (ptr != NULL) {

		if (ptr->data.danh_sach_ve.n < ptr->data.danh_sach_ve.limit && ptr->data.trang_thai != 0 && ptr->data.trang_thai != 3) {
			ptr->data.trang_thai = 1;
		}
		if (ptr->data.danh_sach_ve.n == ptr->data.danh_sach_ve.limit && ptr->data.trang_thai != 0) {
			ptr->data.trang_thai = 2;
		}

		if (check_depart_time(ptr->data.depart_time) == false && ptr->data.trang_thai != 0 && ptr->data.trang_thai != 3) {
			ptr->data.trang_thai = 3;
			free_memory(phead_dscb->data.danh_sach_ve);
		}

		ptr = ptr->pnext;
	}
}
void sort_chuyen_bay_by_time(PTR_chuyenbay& phead_dscb) {// hien tai- qua khu- tang dan
	PTR_chuyenbay ptr1 = phead_dscb;
	while (ptr1 != NULL) {
		PTR_chuyenbay ptr2 = ptr1->pnext;
		while (ptr2 != NULL) {
			if (check_depart_time(ptr1->data.depart_time) == true
				&& check_depart_time(ptr2->data.depart_time) == true) {
				if (is_nearer(ptr2->data.depart_time, ptr1->data.depart_time)) {
					chuyen_bay temp_chuyen_bay = ptr1->data;
					ptr1->data = ptr2->data;
					ptr2->data = temp_chuyen_bay;
				}
			}
			else if ((ptr1->data.trang_thai == 3 || check_depart_time(ptr1->data.depart_time) == false) && check_depart_time(ptr2->data.depart_time) == true) {
				chuyen_bay temp_chuyen_bay = ptr1->data;
				ptr1->data = ptr2->data;
				ptr2->data = temp_chuyen_bay;
			}

			else if (check_depart_time(ptr1->data.depart_time) == false
				&& check_depart_time(ptr2->data.depart_time) == false) {
				if (is_nearer2(ptr2->data.depart_time, ptr1->data.depart_time)) {
					chuyen_bay temp_chuyen_bay = ptr1->data;
					ptr1->data = ptr2->data;
					ptr2->data = temp_chuyen_bay;
				}

			}
			ptr2 = ptr2->pnext;
		}
		ptr1 = ptr1->pnext;
	}
}
void in_DS_chuyen_bay(PTR_chuyenbay& phead_dscb) {
	node_cb* ptr = new node_cb;
	ptr = phead_dscb;
	int x = 4, y = 8, n = 16, j = 3, dem = 1, pageht = 0, page = 0, cd = 0;
	ve_hcnrong(x + 112, y, 25, 11);
	Ve_bang(x, y, n, 6, dem);
	SetBGColor(1);
	SetColor(15);
	gotoxy(x + 113, y + 1); cout << "       TRANG THAI      ";
	gotoxy(x + 1, y + 1); cout << "STT";
	gotoxy(x + 12, y + 1); cout << "Ma CB";
	gotoxy(x + 29, y + 1); cout << "So hieu MB";
	gotoxy(x + 48, y + 1); cout << "San bay den";
	gotoxy(x + 67, y + 1); cout << "Ngay khoi hanh";
	gotoxy(x + 87, y + 1); cout << "Trang thai";

	SetBGColor(10);
	SetColor(0);
	gotoxy(x + 113, y + 3); cout << "  1 : CON VE           ";
	gotoxy(x + 113, y + 7); cout << "  3 : HOAN TAT         ";
	SetBGColor(4);
	SetColor(15);
	gotoxy(x + 113, y + 9); cout << "  0 : HUY CHUYEN       ";
	gotoxy(x + 113, y + 5); cout << "  2 : HET VE           ";
	SetBGColor(15);
	SetColor(0);
	update_statement(phead_dscb);//cap nhat trang thai
	sort_chuyen_bay_by_time(phead_dscb);
	while (ptr != NULL) {
		cd++;
		if (cd <= 15) {
			gotoxy(x + 6, y + j); cout << ptr->data.macb; gotoxy(x + 26, y + j); cout << ptr->data.so_hieu_may_bay; gotoxy(x + 46, y + j); cout << ptr->data.san_bay_den;
			gotoxy(x + 66, y + j); cout << ptr->data.depart_time.hour << ":" << ptr->data.depart_time.min << "  " << ptr->data.depart_time.day << "/"
				<< ptr->data.depart_time.mon << "/" << ptr->data.depart_time.year;
			gotoxy(x + 92, y + j); cout << ptr->data.trang_thai;
			j += 2;
		}
		ptr = ptr->pnext;
	}
	page = cd / 15;
	if (page == 0) page = 1;
	if ((cd - (page * 15)) > 0) page++;
	pageht = 1;
	gotoxy(x + 43, y + 33); cout << pageht << "/" << page;
	int np = 0;
	while (1) {
		np = Nhanphim(); int k = 0;
		if (np == 27 || np == 13) break;
		if (np == 77 && pageht < page) {
			pageht++;
			k = 1;
		}
		if (np == 75 && pageht > 1) {
			pageht--;
			k = 1;
		}
		if (k == 1) {
			cd = 0;
			dem = pageht * 15 - 14;
			Ve_bang(x, y, n, 6, dem);
			SetBGColor(1);
			SetColor(15);
			gotoxy(x + 1, y + 1); cout << "STT";
			gotoxy(x + 12, y + 1); cout << "Ma CB";
			gotoxy(x + 29, y + 1); cout << "So hieu MB";
			gotoxy(x + 48, y + 1); cout << "San bay den";
			gotoxy(x + 67, y + 1); cout << "Ngay khoi hanh";
			gotoxy(x + 87, y + 1); cout << "Trang thai";

			SetBGColor(15);
			SetColor(0);
			j = 3;
			ptr = phead_dscb;
			while (ptr != NULL) {
				cd++;
				if (cd <= pageht * 15 && cd >= dem) {
					gotoxy(x + 6, y + j); cout << ptr->data.macb; gotoxy(x + 26, y + j); cout << ptr->data.so_hieu_may_bay; gotoxy(x + 46, y + j); cout << ptr->data.san_bay_den;
					gotoxy(x + 66, y + j); cout << ptr->data.depart_time.hour << ":" << ptr->data.depart_time.min << "  " << ptr->data.depart_time.day << "/"
						<< ptr->data.depart_time.mon << "/" << ptr->data.depart_time.year;
					gotoxy(x + 92, y + j); cout << ptr->data.trang_thai;
					j += 2;
				}
				ptr = ptr->pnext;
			}
			gotoxy(x + 43, y + 33); cout << pageht << "/" << page;
		}
	}
	Xoa_khunhap();
}
void in_ten_chuyen_bay(PTR_chuyenbay phead_dscb) {
	if (phead_dscb == NULL) return;
	sort_chuyen_bay_by_time(phead_dscb);
	node_cb* ptr = new node_cb;
	ptr = phead_dscb;
	int x = 4, y = 8, n = 16, j = 3, dem = 1, pageht = 0, page = 0, cd = 0;
	
	Ve_bang(x, y, n, 3, dem);
	SetBGColor(1);
	SetColor(15);
	
	gotoxy(x + 1, y + 1); cout << "STT";
	gotoxy(x + 12, y + 1); cout << "Ma CB";
	gotoxy(x + 29, y + 1); cout << "  Thoi gian ";
	

	
	SetBGColor(15);
	SetColor(0);
	
	while (ptr != NULL) {
		cd++;
		if (cd <= 15 && ptr->data.trang_thai != 0) {
			

				gotoxy(x + 6, y + j); cout << ptr->data.macb;
				gotoxy(x + 26, y + j);  cout << ptr->data.depart_time.hour << ":" << ptr->data.depart_time.min << "  " << ptr->data.depart_time.day << "/"
					<< ptr->data.depart_time.mon << "/" << ptr->data.depart_time.year;
			
			
			
			
			j += 2;
		}
		ptr = ptr->pnext;
	}
	page = cd / 15;
	if (page == 0) page = 1;
	if ((cd - (page * 15)) > 0) page++;
	pageht = 1;
	gotoxy(x + 23, y + 33); cout << pageht << "/" << page; ShowConsoleCursor(false);
	int np = 0;
	while (1) {
		np = Nhanphim(); int k = 0;
		if (np == 27 || np == 13) break;
		if (np == 77 && pageht < page) {
			pageht++;
			k = 1;
		}
		if (np == 75 && pageht > 1) {
			pageht--;
			k = 1;
		}
		if (k == 1) {
			cd = 0;
			dem = pageht * 15 - 14;
			Ve_bang(x, y, n, 6, dem);
			SetBGColor(1);
			SetColor(15);
			gotoxy(x + 1, y + 1); cout << "STT";
			gotoxy(x + 12, y + 1); cout << "Ma CB";
			gotoxy(x + 29, y + 1); cout << "  Thoi gian ";
			

			SetBGColor(15);
			SetColor(0);
			j = 3;
			ptr = phead_dscb;
			while (ptr != NULL) {
				cd++;
				if (cd <= pageht * 15 && cd >= dem && ptr->data.trang_thai != 0) {

					gotoxy(x + 6, y + j); cout << ptr->data.macb;
					gotoxy(x + 26, y + j);  cout << ptr->data.depart_time.hour << ":" << ptr->data.depart_time.min << "  " << ptr->data.depart_time.day << "/"
						<< ptr->data.depart_time.mon << "/" << ptr->data.depart_time.year;
					
					j += 2;
				}
				ptr = ptr->pnext;
			}
			gotoxy(x + 23, y + 33); cout << pageht << "/" << page;
		}
	}
	ShowConsoleCursor(false);
	
}
void in_ten_chuyen_bay_all(PTR_chuyenbay phead_dscb) {
	if (phead_dscb == NULL) return;
	sort_chuyen_bay_by_time(phead_dscb);
	node_cb* ptr = new node_cb;
	ptr = phead_dscb;
	int x = 4, y = 8, n = 16, j = 3, dem = 1, pageht = 0, page = 0, cd = 0;

	Ve_bang(x, y, n, 4, dem);
	SetBGColor(1);
	SetColor(15);

	gotoxy(x + 1, y + 1); cout << "STT";
	gotoxy(x + 12, y + 1); cout << "Ma CB";
	gotoxy(x + 29, y + 1); cout << "  Thoi gian ";
	gotoxy(x + 48, y + 1); cout << "Trang thai";



	SetBGColor(15);
	SetColor(0);

	while (ptr != NULL) {
		cd++;
		if (cd <= 15 ) {


			gotoxy(x + 6, y + j); cout << ptr->data.macb;
			gotoxy(x + 26, y + j);  cout << ptr->data.depart_time.hour << ":" << ptr->data.depart_time.min << "  " << ptr->data.depart_time.day << "/"
				<< ptr->data.depart_time.mon << "/" << ptr->data.depart_time.year;

            gotoxy(x + 46+7, y + j); cout << ptr->data.trang_thai;

			j += 2;
		}
		ptr = ptr->pnext;
	}
	page = cd / 15;
	if (page == 0) page = 1;
	if ((cd - (page * 15)) > 0) page++;
	pageht = 1;
	gotoxy(x + 33, y + 33); cout << pageht << "/" << page; ShowConsoleCursor(false);
	int np = 0;
	while (1) {
		np = Nhanphim(); int k = 0;
		if (np == 27 || np == 13) break;
		if (np == 77 && pageht < page) {
			pageht++;
			k = 1;
		}
		if (np == 75 && pageht > 1) {
			pageht--;
			k = 1;
		}
		if (k == 1) {
			cd = 0;
			dem = pageht * 15 - 14;
			Ve_bang(x, y, n, 6, dem);
			SetBGColor(1);
			SetColor(15);
			gotoxy(x + 1, y + 1); cout << "STT";
			gotoxy(x + 12, y + 1); cout << "Ma CB";
			gotoxy(x + 29, y + 1); cout << "  Thoi gian ";
			gotoxy(x + 48, y + 1); cout << "Trang thai";


			SetBGColor(15);
			SetColor(0);
			j = 3;
			ptr = phead_dscb;
			while (ptr != NULL) {
				cd++;
				if (cd <= pageht * 15 && cd >= dem && ptr->data.trang_thai != 0) {

					gotoxy(x + 6, y + j); cout << ptr->data.macb;
					gotoxy(x + 26, y + j);  cout << ptr->data.depart_time.hour << ":" << ptr->data.depart_time.min << "  " << ptr->data.depart_time.day << "/"
						<< ptr->data.depart_time.mon << "/" << ptr->data.depart_time.year;
					gotoxy(x + 46+7, y + j); cout << ptr->data.trang_thai;

					j += 2;
				}
				ptr = ptr->pnext;
			}
			gotoxy(x + 33, y + 33); cout << pageht << "/" << page;
		}
	}
	ShowConsoleCursor(false);

}

void insert_node_cb(PTR_chuyenbay& phead_cb, node_cb* p) {
	if (phead_cb == NULL) {
		phead_cb = p;
		return;
	}
	else {
		PTR_chuyenbay ptr = phead_cb;
		while (ptr->pnext != NULL) ptr = ptr->pnext;
		ptr->pnext = p;
		return;
	}
}
// ham lap chuyen bay moi
void add_new_ch_bay(PTR_chuyenbay& phead_dscb, ds_may_bay dsmb) {
	in_DS_MB(dsmb);
	
	int x = 42+30, y = 12, ktra;
	if (dsmb.n == 0) {
		int tb=MessageBox(NULL, L"Can khoi tao danh sach may bay truoc!", L"THONG BAO", MB_ICONWARNING | MB_OK);
		while (kbhit()) getch();
		return;
	}
	Ve_khunhap_chbay(x, y);
	//================================================================================//

	int result = 0;//kiem tra so_hieu_may_bay co ton tai hay khong.
	char temp_so_hieu[16] = "";
	char temp_san_bay[21] = "";

	//tao ngay gio khoi hanh: 
	int temp_hour = 0;
	int temp_min = 0;
	int temp_day = 0;
	int temp_mon = 0;
	int temp_year = 0;


	ds_ve temp_ds_ve; //danh sach ve cua chuyen bay.

	ShowConsoleCursor(true);
	char temp_ma_cb[16] = "";
	fflush(stdin);

	do {
		gotoxy(x + 6, y + 5); cout << "Ma chuyen bay     :                                        ";
		do {
			ktra = 1;
			Nhan_chu(temp_ma_cb, x + 26, y + 5, 15, ktra);
		} while (strlen(temp_ma_cb) == 0);
		strupr(temp_ma_cb);

		if (search_node(phead_dscb, temp_ma_cb) != NULL) {
			int tb=MessageBox(NULL, L"Ma chuyen bay da ton tai\n nhap lai", L"THONG BAO", MB_ICONWARNING | MB_OK);
			while (kbhit()) getch();
		}
	} while (search_node(phead_dscb, temp_ma_cb) != NULL);

	do {
		Ve_khunhap_chbay(x, y);
		gotoxy(x + 26, y + 5); cout << temp_ma_cb;
		do {
			memset(temp_so_hieu, '\0', sizeof(temp_so_hieu));
			gotoxy(x + 26, y + 10); cout << temp_so_hieu;
			ktra = 1;
			Nhan_chu2(temp_so_hieu, x + 26, y + 10, 15,dsmb, ktra);
		} while (strlen(temp_so_hieu) == 0);
		strupr(temp_so_hieu);
		result = search_ma_may_bay(dsmb, temp_so_hieu);
		if (result < 0) {
			int temp = MessageBox(NULL, L"So hieu May bay khong ton tai\n Ban co muon nhap lai khong?", L"THONG BAO", MB_ICONWARNING | MB_OKCANCEL);
			while (kbhit()) getch();
			if (temp == IDCANCEL) {
				ShowConsoleCursor(false);
				Xoa_khunhap();
				return;
			}
		}
		
	} while (result < 0);
	Ve_khunhap_chbay(x, y);
	gotoxy(x + 26, y + 5); cout << temp_ma_cb;
	gotoxy(x + 26, y + 10); cout << temp_so_hieu;
	fflush(stdin);
	do {
		ktra = 2;
		Nhan_chu(temp_san_bay, x + 26, y + 15, 20, ktra);
	} while (strlen(temp_san_bay) == 0);
	Viet_hoa(temp_san_bay);

	date_time depart;
	bool stop_check_time = false;

	gotoxy(x + 17, y + 22);// đánh đấu vị trí
	cout << "00";
	gotoxy(x + 24, y + 22);
	cout << "00";
	do {
		bool exit = true;
		//	cout<<"nhap vao gio/phut khoi hanh ";
		do {
			gotoxy(x + 17, y + 22);
			cout << "  ";
			temp_hour = 0, ktra = 0;
			Nhan_so(temp_hour, x + 17, y + 22, 2, ktra);
			if (temp_hour == 24 || temp_hour == 0) {
				temp_hour = 0;
				gotoxy(x + 17, y + 22);
				cout << "00";
			}
		} while (temp_hour > 24 || temp_hour < 0);
		do {
			gotoxy(x + 24, y + 22);
			cout << "  ";
			temp_min = 0, ktra = 0;
			Nhan_so(temp_min, x + 24, y + 22, 2, ktra);
			if (temp_min == 60 || temp_min == 0) {
				if (temp_min == 60) {
					temp_hour++;
					temp_hour %= 24;
					gotoxy(x + 17, y + 22);
					cout << "  ";
					gotoxy(x + 17, y + 22);
					if (temp_hour > 0)cout << temp_hour;
					else cout << "00";
				}
				temp_min = 0;
				gotoxy(x + 24, y + 22);
				cout << "00";
			}
		} while (temp_min > 60);
		//	cout<<"nhap vao ngay/thang/nam ";
		do {
			gotoxy(x + 48, y + 22);
			cout << "  ";
			temp_day = 0, ktra = 0;
			Nhan_so(temp_day, x + 48, y + 22, 2, ktra);
		} while (temp_day == 0 || temp_day > 31);
		do {
			gotoxy(x + 55, y + 22);
			cout << "  ";
			temp_mon = 0, ktra = 0;
			Nhan_so(temp_mon, x + 55, y + 22, 2, ktra);
		} while (temp_mon == 0 || temp_mon > 12);
		do {
			temp_year = 202, ktra = 0;
			Nhan_so(temp_year, x + 62, y + 22, 4, ktra);
		} while (temp_year == 0 || temp_year < 2020);

		depart.hour = temp_hour;
		depart.min = temp_min;
		depart.day = temp_day;
		depart.mon = temp_mon;
		depart.year = temp_year;

		if (check_depart_time(depart) == false) {
			MessageBox(NULL, L"Vui long kiem tra lai thoi gian khoi hanh !", L"THONG BAO", MB_ICONWARNING | MB_OK);
			while (kbhit()) getchar();
			exit = false;
		}

		if (check_12h_chuyen_bay(phead_dscb, temp_so_hieu, depart) == false) {
			MessageBox(NULL, L"Trong 2 gio, mot may bay khong the thuc hien 2 chuyen bay khac nhau!\n\tNhap lai!",L"THONG BAO", MB_ICONWARNING | MB_OK);
			while (kbhit()) getchar();
			exit = false;
		}

		if (exit == true) {
			stop_check_time = true;
		}

	} while (stop_check_time == false);

	ShowConsoleCursor(false);
	Loading(x, y);

	chuyen_bay data;// gan truc tiep se bi sai!
	strcpy(data.macb, temp_ma_cb);
	strcpy(data.so_hieu_may_bay, temp_so_hieu);
	strcpy(data.san_bay_den, temp_san_bay);
	data.depart_time = depart;
	data.trang_thai = 1;


	//khoi tao node_cb moi: 
	node_cb* p = new node_cb;


	//khoi tao danh sach ve cua may bay 
	initialize_ve(temp_ds_ve, dsmb.data[result]->socho, 0);
	data.danh_sach_ve = temp_ds_ve;

	//cong them so luot thuc hien chuyen bay.
	dsmb.data[result]->so_luot_thuc_hien++;
	
	


	p->data = data;
	p->pnext = NULL;
	insert_node_cb(phead_dscb, p);

	gotoxy(x + 11, y + 9); cout << "        	THEM THANH CONG !";
	Sleep(500);
	Xoa_khunhap();

}
//ham xoa chuyen bay
void del_chuyen_bay(PTR_chuyenbay& phead_dscb, ds_may_bay& dsmb) {
	if (so_luong_tt_1_2(phead_dscb) == 0)
	{
		MessageBox(NULL, L"Khong the HUY\nVi danh sach chi con cac chuyen bay da bi HUY hoac DANG BAY !", L"THONG BAO", MB_ICONHAND | MB_OK);
		while (kbhit()) getch();
		return;

	}
	in_ten_chuyen_bay(phead_dscb);
	int x = 42+15, y = 12, ktra;
	if (phead_dscb == NULL) {
		MessageBox(NULL, L"danh sach chuyen bay trong!", L"THONG BAO", MB_ICONHAND | MB_OK);
		while (kbhit()) getch();
		return;
	}
	else {
		ve_hcnrong(x, y, 66, 18);
		ve_hcnrong(x + 5, y + 4, 54, 3);
		SetBGColor(14);
		gotoxy(x + 15, y + 2); cout << "[NHHAP VAO MA CHUYEN BAY BAN MUON HUY]";
		SetBGColor(11);
		gotoxy(x + 6, y + 5); cout << "Ma chuyen bay :                                     ";
		ShowConsoleCursor(true);
		char del_ma[16] = "";
		ktra = 0;
		do {
			ktra = 4;
			Nhan_chu2(del_ma, x + 22, y + 5, 15, dsmb, ktra);
		} while (strlen(del_ma) == 0);
		strupr(del_ma);

		PTR_chuyenbay ptr = phead_dscb;
		while (ptr != NULL) {
			if (strcmp(del_ma, ptr->data.macb) == 0) {
				if (ptr->data.trang_thai == 0) {
					ShowConsoleCursor(false);
					MessageBox(NULL, L"Chuyen bay da bi huy tu truoc!", L"THONG BAO", MB_ICONWARNING | MB_OK);
					while (kbhit()) getch();
					Xoa_khunhap();
					return;
				}
				else if (ptr->data.trang_thai == 3) {
					ShowConsoleCursor(false);
					MessageBox(NULL, L"Chuyen bay da hoan tat \nKhong the huy!", L"THONG BAO", MB_ICONWARNING | MB_OK);
					while (kbhit()) getch();
					Xoa_khunhap();
					return;
				}
				else if (ptr->data.trang_thai != 0) {
					ShowConsoleCursor(false);
					Loading(x, y);
					ptr->data.trang_thai = 0;
					gotoxy(x + 11, y + 9); cout << "          HUY THANH CONG !";
					int result = search_ma_may_bay(dsmb, ptr->data.so_hieu_may_bay);
					dsmb.data[result]->so_luot_thuc_hien--;
					free_memory(ptr->data.danh_sach_ve);
					Sleep(500);
					Xoa_khunhap();
					return;
				}

			}
			ptr = ptr->pnext;
		}
		MessageBox(NULL, L"Ma chuyen bay khong ton tai!", L"THONG BAO", MB_ICONHAND | MB_OK);
		while (kbhit()) getch();
		ShowConsoleCursor(false);
		Xoa_khunhap();
		return;
	}
}
bool check_12h_chuyen_bay_version_2(PTR_chuyenbay& phead_dscb, PTR_chuyenbay& edit_node, char temp_so_hieu[], date_time dt) {


	node_cb* ptr = phead_dscb;



	while (ptr != NULL) {
		if (strcmp(ptr->data.so_hieu_may_bay, temp_so_hieu) == 0 && ptr->data.trang_thai != 0 && ptr != edit_node) {
			if (ptr->data.depart_time.day == dt.day && ptr->data.depart_time.mon == dt.mon
				&& ptr->data.depart_time.year == dt.year) {

				if (ptr->data.depart_time.hour != dt.hour) {
					int time = abs((ptr->data.depart_time.hour * 60 + ptr->data.depart_time.min)
						- (dt.hour * 60 + dt.min));
					if (time < 720) {
						return false;
					}
				}

				else if (ptr->data.depart_time.hour == dt.hour) return false;
			}

			else if (abs(ptr->data.depart_time.day - dt.day) == 1 && ptr->data.depart_time.mon == dt.mon
				&& ptr->data.depart_time.year == dt.year) {

				//cach nhau 1 ngay, cb truoc ptr->data
				if (ptr->data.depart_time.day > dt.day) {
					int time = (ptr->data.depart_time.hour * 60 + ptr->data.depart_time.min)
						+ (1440 - (dt.hour * 60 + dt.min));
					if (time < 720) return false;
				}

				//cach nhau 1 ngay, cb sau ptr->data
				else if (dt.day > ptr->data.depart_time.day) {
					int time = (1440 - (ptr->data.depart_time.hour * 60 + ptr->data.depart_time.min))
						+ (dt.hour * 60 + dt.min);
					if (time < 720) return false;
				}
			}
			else if (ptr->data.depart_time.year == dt.year && abs(ptr->data.depart_time.mon - dt.mon) == 1) {

				if ((ptr->data.depart_time.day == day[ptr->data.depart_time.mon] && dt.day == 1) || (dt.day == day[dt.mon] && ptr->data.depart_time.day == 1)) {
					if (ptr->data.depart_time.mon > dt.mon) {
						if ((ptr->data.depart_time.hour * 60 + ptr->data.depart_time.min) + (1440 - (dt.hour * 60 + dt.min)) < 720) {
							return false;
						}
					}
					else {
						if ((dt.hour * 60 + dt.min) + (1440 - (ptr->data.depart_time.hour * 60 + ptr->data.depart_time.min)) < 720) {
							return false;
						}
					}
				}
			}
			else if (abs(ptr->data.depart_time.year - dt.year) == 1) {
				if (ptr->data.depart_time.day == 31 && ptr->data.depart_time.mon == 12 && dt.day == 1 && dt.mon == 1) {
					if ((dt.hour * 60 + dt.min) + (1440 - (ptr->data.depart_time.hour * 60 + ptr->data.depart_time.min)) < 720) {
						return false;
					}
				}
				else if (ptr->data.depart_time.day == 1 && ptr->data.depart_time.mon == 1 && dt.day == 31 && dt.mon == 12) {
					if ((ptr->data.depart_time.hour * 60 + ptr->data.depart_time.min) + (1440 - (dt.hour * 60 + dt.min)) < 720) {
						return false;
					}
				}

			}

		}
		ptr = ptr->pnext;

	}
	return true;
}
//ham hieu chinh ngay gio cua chuyen bay
void edit_chuyen_bay(PTR_chuyenbay& phead_dscb) {

	
	if (so_luong_tt_1_2(phead_dscb) == 0)
	{
		MessageBox(NULL, L"Khong the hieu chinh\nVi danh sach chi con cac chuyen bay da bi HUY hoac DANG BAY !", L"THONG BAO", MB_ICONHAND | MB_OK);
		while (kbhit()) getch();
		return;

	}
nhap_lai:
	in_ten_chuyen_bay(phead_dscb);
	int x = 42+30, y = 12, ktra;
	if (phead_dscb == NULL) {
		MessageBox(NULL, L"Danh sach chuyen bay trong!", L"THONG BAO", MB_ICONHAND | MB_OK);
		while (kbhit()) getch();
		return;
	}
	
	ve_hcnrong(x, y, 66, 18);
	ve_hcnrong(x + 5, y + 4, 54, 3);
	SetBGColor(14);
	gotoxy(x + 1, y + 2); cout << "[NHAP VAO MA CHUYEN BAY BAN MUON HIEU CHINH NGAY GIO KHOI HANH]";
	SetBGColor(11);
	gotoxy(x + 6, y + 5); cout << "Ma chuyen bay :                                     ";
	ShowConsoleCursor(true);
	char temp_ma[15] = "";
	do {
		ktra = 4;
		Nhan_chu2(temp_ma, x + 22, y + 5, 15, dsmb, ktra);
	} while (strlen(temp_ma) == 0);
	strupr(temp_ma);
	node_cb* edit_node = phead_dscb;

	SetBGColor(15);
	while (edit_node != NULL) {
		if (strcmp(edit_node->data.macb, temp_ma) == 0) {
			break;
		}
		else edit_node = edit_node->pnext;
	}

	if (edit_node == NULL) {
		MessageBox(NULL, L"Ma chuyen bay khong ton tai!", L"THONG BAO", MB_ICONHAND | MB_OK);
		while (kbhit()) getch();
		ShowConsoleCursor(false);
		Xoa_khunhap();
		return;
	}
	else if (edit_node->data.trang_thai == 3) {
		MessageBox(NULL, L"Chuyen bay nay da thuc hien thanh cong!\n\tKhong the hieu chinh!", L"THONG BAO", MB_ICONWARNING | MB_OK);
		while (kbhit()) getch();
		ShowConsoleCursor(false);
		Xoa_khunhap();
		return;
	}
	else if (edit_node->data.trang_thai == 0) {
		MessageBox(NULL, L"Chuyen bay nay da bi huy!\nKhong the hieu chinh!", L"THONG BAO", MB_ICONWARNING | MB_OK);
		while (kbhit()) getch();
		ShowConsoleCursor(false);
		Xoa_khunhap();
		return;
	}
	
	else {

		if (edit_node->data.danh_sach_ve.n != 0)
		{
			PTR_chuyenbay p = phead_dscb;
			while (p != NULL) {

				if (p != edit_node && p->data.trang_thai != 0 && p->data.trang_thai != 3) {
					for (int i = 0; i < edit_node->data.danh_sach_ve.n; i++) {
						for (int j = 0; j < p->data.danh_sach_ve.n; j++) {

							if (strcmp(edit_node->data.danh_sach_ve.so_ghe[i]->cmnd, p->data.danh_sach_ve.so_ghe[j]->cmnd) == 0) {
								MessageBox(NULL, L"Chuyen bay co Hanh Khach thuoc chuyen bay khac\nKhong the hieu chinh!", L"THONG BAO", MB_ICONHAND | MB_OK);
								while (kbhit()) getch();
								Xoa_khunhap();
								goto nhap_lai;
							}
						}
					}
				}
				p = p->pnext;
			}

		}

		ve_hcnrong(x, y, 66, 18);
		ve_hcnrong(x + 5, y + 7, 10, 3); ve_hcnrong(x + 15, y + 7, 6, 3); ve_hcnrong(x + 22, y + 7, 6, 3); gotoxy(x + 21, y + 8); cout << ":";
		ve_hcnrong(x + 5, y + 13, 16, 3); ve_hcnrong(x + 21, y + 13, 6, 3); ve_hcnrong(x + 28, y + 13, 6, 3); ve_hcnrong(x + 35, y + 13, 8, 3);
		gotoxy(x + 27, y + 14); cout << "\\"; gotoxy(x + 34, y + 14); cout << "\\";
		SetBGColor(14);
		gotoxy(x + 5, y + 2); cout << "[NHAP VAO THOI GIAN KHOI HANH MA BAN MUON THAY DOI]";
		SetBGColor(11);
		gotoxy(x + 6, y + 8); cout << "Gio:Phut"; gotoxy(x + 16, y + 8); cout << "    "; gotoxy(x + 23, y + 8); cout << "    ";
		gotoxy(x + 6, y + 14); cout << "Ngay\\thang\\nam"; gotoxy(x + 22, y + 14); cout << "    "; gotoxy(x + 29, y + 14); cout << "    "; gotoxy(x + 36, y + 14); cout << "      ";

		int temp_hour = edit_node->data.depart_time.hour,
			temp_min = edit_node->data.depart_time.min,
			temp_day = edit_node->data.depart_time.day,
			temp_mon = edit_node->data.depart_time.mon,
			temp_year = edit_node->data.depart_time.year;

		gotoxy(x + 17, y + 8); cout << temp_hour;
		gotoxy(x + 24, y + 8); cout << temp_min;
		gotoxy(x + 23, y + 14); cout << temp_day;
		gotoxy(x + 30, y + 14); cout << temp_mon;
		gotoxy(x + 37, y + 14); cout << temp_year;
		while (true) {
			//			cout<<"Moi ban nhap vao gio/phut ";
			do {
				gotoxy(x + 17, y + 8); cout << "  ";
				temp_hour = edit_node->data.depart_time.hour;
				ktra = 0;
				Nhan_so(temp_hour, x + 17, y + 8, 2, ktra);
				if (temp_hour == 24 || temp_hour == 0) {
					temp_hour = 0;
					gotoxy(x + 17, y + 8);
					cout << "00";
				}
			} while (temp_hour > 24 || temp_hour < 0);

			do {
				gotoxy(x + 24, y + 8); cout << "  ";
				temp_min = edit_node->data.depart_time.min;
				ktra = 0;
				Nhan_so(temp_min, x + 24, y + 8, 2, ktra);
				if (temp_min == 60 || temp_min == 0) {
					if (temp_min == 60) {
						temp_hour++;
						temp_hour %= 24;
						gotoxy(x + 17, y + 8);
						cout << "  ";
						gotoxy(x + 17, y + 8);
						if (temp_hour > 0)cout << temp_hour;
						else cout << "00";
					}
					temp_min = 0;
					gotoxy(x + 24, y + 8);
					cout << "00";
				}
			} while (temp_min > 60);
			//			nhap ngay/thang/nam 		
			do {
				gotoxy(x + 23, y + 14); cout << "  ";
				temp_day = edit_node->data.depart_time.day;
				ktra = 0;
				Nhan_so(temp_day, x + 23, y + 14, 2, ktra);
			} while (temp_day == 0 || temp_day > 31);
			do {
				gotoxy(x + 30, y + 14); cout << "  ";
				temp_mon = edit_node->data.depart_time.mon;
				ktra = 0;
				Nhan_so(temp_mon, x + 30, y + 14, 2, ktra);
			} while (temp_mon == 0 || temp_mon > 12);
			do {
				gotoxy(x + 37, y + 14); cout << "    ";
				temp_year = edit_node->data.depart_time.year;
				ktra = 0;
				Nhan_so(temp_year, x + 37, y + 14, 4, ktra);
			} while (temp_year == 0 || temp_year < 2020);

			date_time temp_depart;
			temp_depart.hour = temp_hour;
			temp_depart.min = temp_min;
			temp_depart.day = temp_day;
			temp_depart.mon = temp_mon;
			temp_depart.year = temp_year;
			if (check_depart_time(temp_depart) == false) {
				MessageBox(NULL, L"Thoi gian nhap vao khong hop le!\nVui long nhap lai!", L"THONG BAO", MB_ICONWARNING | MB_OK);
				while (kbhit()) getch();
			}
			else if (check_12h_chuyen_bay_version_2(phead_dscb, edit_node, edit_node->data.so_hieu_may_bay, temp_depart) == false) {
				MessageBox(NULL, L"Mot may bay khong the thuc hien 2 chuyen bay cach nhau duoi 12 gio!\nVui long nhap lai!", L"THONG BAO", MB_ICONWARNING | MB_OK);
				while (kbhit()) getch();
			}
			else {
				ShowConsoleCursor(false);
				Loading(x, y);
				gotoxy(x + 11, y + 9); cout << "         CAP NHAT THANH CONG !";
				edit_node->data.depart_time = temp_depart;
				Sleep(500);
				Xoa_khunhap();
				return;
			}
		}
	}

}

//=============================================== ND HANH KHACH ========================================================

//tao hanh khach
hanh_khach create_data(char temp_cmnd[]) {


	char temp_ten[11] = "";
	char temp_ho[31] = "";
	bool temp_phai;
	int x = 42, y = 12, ktra;
	ve_hcnrong(x, y, 70, 18);
	ve_hcnrong(x + 5, y + 4, 36, 3);
	ve_hcnrong(x + 5, y + 7, 28, 3);
	ve_hcnrong(x + 5, y + 10, 41, 3);
	ve_hcnrong(x + 23, y + 13, 5, 3); ve_hcnrong(x + 30, y + 13, 5, 3);
	SetBGColor(14);
	gotoxy(x + 24, y + 2); cout << "[ NHHAP DU LIEU KHACH HANG ]";
	gotoxy(x + 12, y + 14); cout << "Gioi tinh :";
	SetBGColor(15);
	gotoxy(x + 24, y + 14); cout << "Nam";  gotoxy(x + 31, y + 14); cout << "Nu";
	SetBGColor(11);
	gotoxy(x + 6, y + 5); cout << "Ho :                              ";
	gotoxy(x + 6, y + 8); cout << "Ten :                     ";
	gotoxy(x + 6, y + 11); cout << " CMND         :                        ";
	gotoxy(x + 22, y + 11); cout << temp_cmnd;
	ShowConsoleCursor(true);
	do {
		ktra = 2;
		Nhan_chu(temp_ho, x + 11, y + 5, 30, ktra);
	} while (strlen(temp_ho) == 0);
	Viet_hoa(temp_ho);

	do {
		ktra = 2;
		Nhan_chu(temp_ten, x + 12, y + 8, 10, ktra);
	} while (strlen(temp_ten) == 0);
	Viet_hoa(temp_ten);

	ShowConsoleCursor(false);
	SetBGColor(11);
	gotoxy(x + 24, y + 14); cout << "Nam";
	int np, tempx = 66;
	while (1) {
		np = Nhanphim();
		switch (tempx) {
		case 66: {
			if (np == 77 || np == 75) {
				tempx = 73;
				SetBGColor(15);
				gotoxy(x + 24, y + 14); cout << "Nam";
				SetBGColor(11);
				gotoxy(x + 31, y + 14); cout << "Nu";
			}
			break;
		}
		case 73: {
			if (np == 77 || np == 75) {
				tempx = 66;
				SetBGColor(11);
				gotoxy(x + 24, y + 14); cout << "Nam";
				SetBGColor(15);
				gotoxy(x + 31, y + 14); cout << "Nu";
			}
			break;
		}
		}
		if (np == 13) {
			break;
		}
	};
	if (tempx == 66) temp_phai = 0;
	if (tempx == 73) temp_phai = 1;
	hanh_khach data_hk;
	strcpy(data_hk.cmnd, temp_cmnd);
	strcpy(data_hk.ho, temp_ho);
	strcpy(data_hk.ten, temp_ten);
	data_hk.phai = temp_phai;

	return data_hk;
	Xoa_khunhap();
}
//khoi tao node hanh khach
node_hk* create_node(hanh_khach& data_hk) {
	node_hk* new_node = new node_hk;
	new_node->data = data_hk;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}
int treeLevel(NODE_hanhkhach& t) {// tinh do cao cua cay
	if (t == NULL) return -1;
	return 1 + max(treeLevel(t->left), treeLevel(t->right));
}
bool checkAvl(NODE_hanhkhach t) {// kiem tra cay can bang hay chua
	if (t == NULL) 	return true;
	if (abs(treeLevel(t->left) - treeLevel(t->right)) > 1) return false;
	return checkAvl(t->left) && checkAvl(t->right);
}
NODE_hanhkhach turnRight(NODE_hanhkhach& a) {
	NODE_hanhkhach b = a->left;
	NODE_hanhkhach d = b->right;
	a->left = d;
	b->right = a;
	return b;
}
NODE_hanhkhach turnLeft(NODE_hanhkhach& a) {
	NODE_hanhkhach b = a->right;
	NODE_hanhkhach c = b->left;
	a->right = c;
	b->left = a;
	return b;
}
NODE_hanhkhach updateTreeAvl(NODE_hanhkhach& t) {
	if (abs(treeLevel(t->left) - treeLevel(t->right)) > 1) {
		if (treeLevel(t->left) > treeLevel(t->right)) {
			NODE_hanhkhach p = t->left;
			if (treeLevel(p->left) >= treeLevel(p->right)) {
				t = turnRight(t);
			}
			else {
				t->left = turnLeft(t->left);
				t = turnRight(t);
			}
		}
		else {
			NODE_hanhkhach p = t->right;
			if (treeLevel(p->right) >= treeLevel(p->left)) {
				t = turnLeft(t);
			}
			else {
				t->right = turnRight(t->right);
				t = turnLeft(t);

			}
		}
	}
	if (t->left != NULL) t->left = updateTreeAvl(t->left);
	if (t->right != NULL) t->right = updateTreeAvl(t->right);
	return t;
}
//chen them node moi vao cay.
void insert_node_hk(NODE_hanhkhach& root, hanh_khach& data_hk) {

	
	if (root == NULL) {

		NODE_hanhkhach new_node = new node_hk;
		strcpy(new_node->data.cmnd, data_hk.cmnd);
		strcpy(new_node->data.ho, data_hk.ho);
		strcpy(new_node->data.ten, data_hk.ten);
		new_node->data.phai = data_hk.phai;
		new_node->left = NULL;
		new_node->right = NULL;
		root = new_node;
		return;
	}
	else {

		if (strcmp(data_hk.cmnd, root->data.cmnd) == 0)
			return;
		else if (strcmp(data_hk.cmnd, root->data.cmnd) < 0) {
			insert_node_hk(root->left, data_hk);
		}
		else {
			insert_node_hk(root->right, data_hk);
		}
	}

	root = updateTreeAvl(root);

}
void LNR(NODE_hanhkhach& root, int x, int& y, int& dem, int bd, int max) {
	if (dem > max) return;
	if (root != NULL) {
		LNR(root->left, x, y, dem, bd, max);
		if (dem <= max && dem >= bd) {
			gotoxy(x + 6, y); cout << root->data.cmnd; gotoxy(x + 18, y); cout << root->data.ho << " " << root->data.ten;
			gotoxy(x + 58, y); cout << (root->data.phai == 0 ? "Nam" : "Nu");
			y = y + 2;
		}
		dem++;
		LNR(root->right, x, y, dem, bd, max);
	}
}
//duyet theo trung tu lay chieu dai
void LNR(NODE_hanhkhach& root, int& cd) {
	if (root != NULL) {
		LNR(root->left, cd);
		cd++;
		LNR(root->right, cd);
	}
}
NODE_hanhkhach search_hk(char temp_cmnd[], NODE_hanhkhach& root) {

	
	if (root == NULL) {
		return root; //phan biet ro rang!
	}
	else if (strcmp(temp_cmnd, root->data.cmnd) < 0) {
		search_hk(temp_cmnd, root->left);
	}
	else if (strcmp(temp_cmnd, root->data.cmnd) > 0) {
		search_hk(temp_cmnd, root->right);
	}
	else {
		return root;
	}
}
void Ve_bang1(int x, int y, int n, int m, int dem) {
	int ngang = 0, doc = n * 3;
	if (m == 5) ngang = 72;
	if (m == 4) ngang = 64;
	int tempx = x, tempy = y;
	int i = 1;
	while (i <= n) {
		if (i == 1) {
			gotoxy(x, y); cout << char(218); for (int j = 1; j <= ngang - 2; j++) cout << char(196); cout << char(191);
			gotoxy(x, ++y);
			for (int j = 1; j <= ngang; j++) {
				if (m == 5) {
					if (j == 1 || j == ngang || j == 5 || j == 13 || j == 25 || j == 65) cout << char(179);
					else { SetBGColor(1); cout << " "; SetBGColor(15); }
				}
				if (m == 4) {
					if (j == 1 || j == ngang || j == 5 || j == 17 || j == 57) cout << char(179);
					else { SetBGColor(1); cout << " "; SetBGColor(15); }
				}
			}
			gotoxy(x, ++y); cout << char(179); for (int j = 1; j <= ngang - 2; j++) cout << char(196); cout << char(179);
		}
		else if (i == n) {
			gotoxy(x, ++y);
			for (int j = 1; j <= ngang; j++) {
				if (m == 5) {
					if (j == 1 || j == ngang || j == 5 || j == 13 || j == 25 || j == 65) cout << char(179);
					else cout << " ";
				}
				if (m == 4) {
					if (j == 1 || j == ngang || j == 5 || j == 17 || j == 57) cout << char(179);
					else cout << " ";
				}
			}
			gotoxy(x, ++y); cout << char(192); for (int j = 1; j <= ngang - 2; j++) cout << char(196); cout << char(217);
		}
		else {
			gotoxy(x, ++y);
			for (int j = 1; j <= ngang; j++) {
				if (m == 5) {
					if (j == 1 || j == ngang || j == 5 || j == 13 || j == 25 || j == 65) cout << char(179);
					else cout << " ";
				}
				if (m == 4) {
					if (j == 1 || j == ngang || j == 5 || j == 17 || j == 57) cout << char(179);
					else cout << " ";
				}
			}
			gotoxy(x, ++y); cout << char(179); for (int j = 1; j <= ngang - 2; j++) cout << char(196); cout << char(179);
		}
		i++;
	}
	for (int i = 1; i <= n - 1; i++) {
		gotoxy(tempx + 1, i * 2 + tempy + 1); cout << dem++;
	}
}
void in_HK_thuoc_chuyen_bay(chuyen_bay cb) {
	NODE_hanhkhach result;

	int x = 33, y = 8, n = 16, j = 3, dem = 0, np = 0, page = 0, pageht = 1, d1 = 0, cd = 0;
	Ve_bang1(x, y, n, 5, 1);
	gotoxy(x + 15, 6); cout << "DANH SACH HANH KHACH THUOC CHUYEN BAY : " << cb.macb;
	gotoxy(x + 12, 7); cout << "Ngay gio khoi hanh: " << cb.depart_time.day << "/" << cb.depart_time.mon << "/" << cb.depart_time.year << " " << cb.depart_time.hour << ":" << cb.depart_time.min
		<< "  Noi den: " << cb.san_bay_den;
	SetBGColor(1);
	SetColor(15);
	gotoxy(x + 1, y + 1); cout << "STT";
	gotoxy(x + 5, y + 1); cout << "SO GHE";
	gotoxy(x + 14, y + 1); cout << "SO CMND";
	gotoxy(x + 40, y + 1); cout << "HO TEN";
	gotoxy(x + 66, y + 1); cout << "PHAI";
	SetBGColor(15);
	SetColor(0);
	for (int i = 0; i < cb.danh_sach_ve.n; i++) {
		cd++;// dem co bao nhieu hanh khach

		//tim du lieu trong cay nhi phan
		 
		result = search_hk(cb.danh_sach_ve.so_ghe[i]->cmnd, root_hk);

		if (cd <= 15) {
			gotoxy(x + 7, y + j); cout << cb.danh_sach_ve.so_ghe[i]->stt; gotoxy(x + 14, y + j); cout << result->data.cmnd;
			gotoxy(x + 26, y + j); cout << result->data.ho << " " << result->data.ten;
			gotoxy(x + 66, y + j); cout << (result->data.phai == 0 ? "Nam" : "Nu");
			j += 2;
		}

	}
	page = cb.danh_sach_ve.n / 15;
	if ((cb.danh_sach_ve.n - (page * 15)) > 0) page++;
	if (page == 0) page = 1;
	gotoxy(x + 33, y + 33); cout << pageht << "/" << page;
	while (1) {
		np = Nhanphim();
		int k = 0;
		if (np == 27 || np == 13) break;

		if (np == 77 && pageht < page) {
			pageht++;
			k = 1;
		}
		if (np == 75 && pageht > 1) {
			pageht--;
			k = 1;
		}
		if (k == 1) {
			dem = pageht * 15 - 14;
			Ve_bang1(x, y, n, 5, dem);
			SetBGColor(1);
			SetColor(15);
			gotoxy(x + 1, y + 1); cout << "STT"; gotoxy(x + 5, y + 1); cout << "SO GHE"; gotoxy(x + 14, y + 1); cout << "SO CMND"; gotoxy(x + 40, y + 1); cout << "HO TEN"; gotoxy(x + 66, y + 1); cout << "PHAI";
			SetBGColor(15);
			SetColor(0);
			j = 3;
			for (int i = dem - 1; i <= pageht * 15 - 1; i++) {
				if (i > cd - 1) break;
				result = search_hk(cb.danh_sach_ve.so_ghe[i]->cmnd, root_hk);
				if (result != NULL) {
					gotoxy(x + 7, y + j); cout << cb.danh_sach_ve.so_ghe[i]->stt; gotoxy(x + 14, y + j); cout << result->data.cmnd; gotoxy(x + 26, y + j); cout << result->data.ho << " " << result->data.ten;
					gotoxy(x + 66, y + j); cout << (result->data.phai == 0 ? "Nam" : "Nu");
					j += 2;
				}

			}
			gotoxy(x + 33, y + 33); cout << pageht << "/" << page;
		}
	}
	Xoa_khunhap();
	return;
}


//=============================================== ND VE ========================================================

int Thong_bao(int x, int y, string s) {
	int kc = (70 - s.length()) / 2;
	SetBGColor(15);
	ve_hcnrong(x, y + 19, 70, 8);
	ve_hcnrong(x + 5, y + 22, 5, 3);
	ve_hcnrong(x + 59, y + 22, 4, 3);
	gotoxy(x + 6, y + 23); cout << "YES"; gotoxy(x + 60, y + 23); cout << "NO";
	SetBGColor(14);
	gotoxy(x + kc, y + 20); cout << "[ " << s << " ]";
	SetBGColor(2);
	SetColor(15);
	gotoxy(x + 6, y + 23); cout << "YES";
	int kp = 0, tempx = 48;
	while (1) {
		fflush(stdin);
		kp = Nhanphim();
		if (kp == 13) break;
		switch (tempx) {
		case 48: {
			if (kp == 75 || kp == 77) {
				SetBGColor(4);
				SetColor(15);
				gotoxy(x + 60, y + 23); cout << "NO";
				SetBGColor(15);
				SetColor(0);
				gotoxy(x + 6, y + 23); cout << "YES";
				tempx = 102;
			}
			break;
		}
		case 102: {
			if (kp == 75 || kp == 77) {
				SetBGColor(2);
				SetColor(15);
				gotoxy(x + 6, y + 23); cout << "YES";
				SetBGColor(15);
				SetColor(0);
				gotoxy(x + 60, y + 23); cout << "NO";
				tempx = 48;
			}
			break;
		}
		}
	}
	if (tempx == 48) return 1;
	else return 0;
}
bool check_empty_ve(ds_ve& danh_sach_ve, int pos) {
	for (int i = 0; i < danh_sach_ve.n; i++) {
		if (danh_sach_ve.so_ghe[i]->stt == pos) {
			return false;
		}
	}
	return true;
}
void print_empty_ve(ds_ve& danh_sach_ve, char temp_macb[]) {
	int x = 53, y = 8; int n = 16, j = 3, dem = 1, np = 0, cd = 0, page = 0, pageht = 0;
	ve_hcnrong(x - 41, y, 34, 3);
	ve_hcnrong(x - 41, y + 4, 34, 3);
	ve_hcnrong(x - 41, y + 8, 34, 3);
	Ve_bang(x, y, n, 2, dem);
	dem = 16;
	Ve_bang(x + 48, y, n, 2, dem);
	SetBGColor(11);
	gotoxy(x - 40, y + 1); cout << "Ma chuyen bay:                  ";
	gotoxy(x - 25, y + 1); cout << temp_macb;
	SetBGColor(1);
	SetColor(15);
	gotoxy(x + 1, y + 1); cout << "STT"; gotoxy(x + 7, y + 1); cout << "STT VE CON TRONG";
	gotoxy(x + 49, y + 1); cout << "STT"; gotoxy(x + 55, y + 1); cout << "STT VE CON TRONG";
	SetBGColor(15);
	SetColor(0);
	for (int i = 0; i < danh_sach_ve.limit; i++) {
		if (check_empty_ve(danh_sach_ve, i + 1)) {
			cd++;
			if (cd == 16) j = 3;
			if (cd <= 15) {
				gotoxy(x + 10, y + j); cout << i + 1;
				j += 2;
			}
			if (cd > 15 && cd <= 30) {
				gotoxy(x + 58, y + j); cout << i + 1;
				j += 2;
			}
		}
	}
	SetBGColor(2);
	gotoxy(x - 40, y + 5); cout << "Tong so ve   :                  ";
	gotoxy(x - 25, y + 5); cout << danh_sach_ve.limit;
	SetBGColor(10);
	gotoxy(x - 40, y + 9); cout << "Ve con trong :                  ";
	gotoxy(x - 25, y + 9); cout << (danh_sach_ve.limit - danh_sach_ve.n);
	SetBGColor(15);
	SetColor(0);
	page = cd / 15;
	if ((cd - (page * 15)) > 0) page++;
	if (page % 2 == 1) page++;
	gotoxy(x + 35, y + 33); cout << "2/" << page;
	pageht = 2;
	dem = 1; int dem2 = 0, k = 0;
	while (1) {
		np = Nhanphim();
		k = 0;
		if (np == 27 || np == 13) break;
		if (np == 77 && pageht < page) {
			pageht++;
			dem = pageht * 15 - 14;
			pageht++;
			dem2 = pageht * 15 - 14;
			k = 1;
		}
		if (np == 75 && pageht > 2) {
			pageht -= 3;
			dem = pageht * 15 - 14;
			pageht++;
			dem2 = pageht * 15 - 14;
			k = 1;
		}
		if (k == 1) {
			cd = 0, j = 3;
			Ve_bang(x, y, n, 2, dem);
			Ve_bang(x + 48, y, n, 2, dem2);
			SetBGColor(1);
			SetColor(15);
			gotoxy(x + 1, y + 1); cout << "STT"; gotoxy(x + 7, y + 1); cout << "STT VE CON TRONG";
			gotoxy(x + 49, y + 1); cout << "STT"; gotoxy(x + 55, y + 1); cout << "STT VE CON TRONG";
			SetBGColor(15);
			SetColor(0);

			for (int i = 0; i < danh_sach_ve.limit; i++) {
				if (check_empty_ve(danh_sach_ve, i + 1)) {
					cd++;
					if (cd == dem2) j = 3;
					if (cd <= dem + 14 && cd >= dem) {
						gotoxy(x + 10, y + j); cout << i + 1;
						j += 2;
					}
					if (cd >= dem2 && cd <= dem2 + 14) {
						gotoxy(x + 58, y + j); cout << i + 1;
						j += 2;
					}
				}
			}
			gotoxy(x + 35, y + 33); cout << "              ";
			gotoxy(x + 35, y + 33); cout << pageht<< " ";
			gotoxy(x + 37, y + 33); cout << "/" << page;

		}
	}
	Xoa_khunhap();
}
// nhap chu danh cho ve
void Nhan_so2(int& tempso, int x, int y, int dem, int ktra, ds_ve& danh_sach_ve) {
	int d = 0, ch = 0, cd = 0, tempx = x, t = tempso, d1 = 0;
	while (tempso > 0) {
		tempso /= 10;
		cd++;
	}
	tempso = t;
	gotoxy(x, y);
	if (tempso != 0) cout << tempso;
	x += cd;
	d = cd;
	while (1) {// d1 biến kiểm tra có nhập dữ liệu
		if (ktra == 1 && tempso != 0 && d1 != 0) {
			d1 = 0;
			ve_hcnrong(tempx, y + 4, 32, 5);
			ShowConsoleCursor(false);
			if (tempso > danh_sach_ve.limit) {
				//Khong ton tai so ghe nay trong chuyen bay
				SetBGColor(4);
				SetColor(15);
				gotoxy(tempx + 1, y + 5); cout << "   KHONG TON TAI SO GHE NAY   ";
				gotoxy(tempx + 1, y + 6); cout << "       TRONG CHUYEN BAY       ";
				gotoxy(tempx + 1, y + 7); cout << "                              ";
				gotoxy(tempx + 8, y + 7); cout << "0 < So ghe <= " << danh_sach_ve.limit;
				SetBGColor(11);
				SetColor(0);
				gotoxy(x, y);
			}
			else if (check_empty_ve(danh_sach_ve, tempso) == true) {
				SetBGColor(10);
				SetColor(0);
				gotoxy(tempx + 1, y + 5); cout << "                              ";
				gotoxy(tempx + 1, y + 6); cout << "                              ";
				gotoxy(tempx + 1, y + 7); cout << "                              ";
				gotoxy(tempx + 8, y + 6); cout << "So ghe hop le !";
				SetBGColor(11);
				gotoxy(x, y);
			}
			else if (check_empty_ve(danh_sach_ve, tempso) == false) {
				SetBGColor(4);
				SetColor(15);
				gotoxy(tempx + 1, y + 5); cout << "                              ";
				gotoxy(tempx + 1, y + 6); cout << "                              ";
				gotoxy(tempx + 1, y + 7); cout << "                              ";
				gotoxy(tempx + 3, y + 6); cout << "Ve nay da co nguoi dat !";
				SetBGColor(11);
				SetColor(0);
				gotoxy(x, y);
			}
		}
		while (kbhit()) {
			ShowConsoleCursor(true);
			ch = 0, d1 = 1;
			ch = getch();
			if (ch == 224) {
				ch = getch();
				ch = 0;
			}
			if (ch >= 48 && ch <= 57) {
				if (d < dem) {
					cout << ch - 48;
					tempso = tempso * 10 + ch - 48;
					d++;
					x++;
				}
			}
			if (ch == 8) {
				tempso = tempso / 10;
				if (x > tempx) {
					d--;
					x--;
				}
				gotoxy(x, y); cout << " ";
				gotoxy(x, y);
			}
			if (ch == 13) return;
		}
	}
}
void sort_danh_sach_ve(ds_ve& dsv) {
	for (int i = 0; i < dsv.n - 1; i++) {
		ve* temp_ve = dsv.so_ghe[i];
		int temp_ve_index = i;
		for (int j = i + 1; j < dsv.n; j++) {
			if (temp_ve->stt > dsv.so_ghe[j]->stt) {
				temp_ve = dsv.so_ghe[j];
				temp_ve_index = j;
			}
		}

		temp_ve = dsv.so_ghe[i];
		dsv.so_ghe[i] = dsv.so_ghe[temp_ve_index];
		dsv.so_ghe[temp_ve_index] = temp_ve;
	}
}
bool is_the_same_time_30(date_time dt1, date_time dt2) {

	if (dt1.day == dt2.day) {
		if (dt1.year == dt2.year && dt1.mon == dt2.mon && dt1.hour == dt2.hour && abs(dt1.min - dt2.min) <= 30) {
			return true;
		}
	}
	else if (dt1.year == dt2.year && dt1.mon == dt2.mon && abs(dt1.day - dt2.day) == 1) {
		if (dt1.day > dt2.day) {
			if ((dt1.hour * 60 + dt1.min) + (1440 - (dt2.hour * 60 + dt2.min)) <= 30) {
				return true;
			}
		}
		else if (dt1.day < dt2.day) {
			if ((dt2.hour * 60 + dt2.min) + (1440 - (dt1.hour * 60 + dt1.min)) <= 30) {
				return true;
			}
		}
	}
	else if (dt1.year == dt2.year && abs(dt1.mon - dt2.mon) == 1) {
		if (dt1.day == day[dt1.mon] && dt2.day == 1 || dt2.day == day[dt2.mon] && dt1.day == 1) {
			if (dt1.mon > dt2.mon) {
				if ((dt1.hour * 60 + dt1.min) + (1440 - (dt2.hour * 60 + dt2.min)) <= 30) {
					return true;
				}
			}
			else {
				if ((dt2.hour * 60 + dt2.min) + (1440 - (dt1.hour * 60 + dt1.min)) <= 30) {
					return true;
				}
			}
		}
	}
	else if (abs(dt1.year - dt2.year) == 1) {
		if (dt1.day == 31 && dt1.mon == 12 && dt2.day == 1 && dt2.mon == 1) {
			if ((dt2.hour * 60 + dt2.min) + (1440 - (dt1.hour * 60 + dt1.min)) <= 30) {
				return true;
			}
		}
		else if (dt1.day == 1 && dt1.mon == 1 && dt2.day == 31 && dt2.mon == 12) {
			if ((dt1.hour * 60 + dt1.min) + (1440 - (dt2.hour * 60 + dt2.min)) <= 30) {
				return false;
			}
		}

	}
	return false;
}

//dat ve
void order_ve(PTR_chuyenbay& dscb, PTR_chuyenbay cb, ds_ve& danh_sach_ve) {
	Xoa_khunhap();
	
	int x = 42, y = 12, ktra;
	if (danh_sach_ve.n == danh_sach_ve.limit) {
		MessageBox(NULL, L"Chuyen bay da du hanh khach! \nMoi chon chuyen bay khac!", L"THONG BAO", MB_ICONHAND | MB_OK);
		while (kbhit()) getch();
		return;
	}
	char temp_cmnd[10] = "";
	NODE_hanhkhach check;
	bool stop = true;
	hanh_khach data_hk;
//	do {
		ve_hcnrong(x, y, 64, 18);
		ve_hcnrong(x + 5, y + 4, 54, 3);
		SetBGColor(14);
		gotoxy(x + 17, y + 2); cout << "[NHAP CMND DE DAT VE MAY BAY]";
		SetBGColor(11);
		gotoxy(x + 6, y + 5); cout << "  CMND :                                            ";
		ShowConsoleCursor(true);
		do {
			ktra = 3;
			Nhan_chu(temp_cmnd, x + 14, y + 5, 9, ktra);
		} while (strlen(temp_cmnd) == 0 || strlen(temp_cmnd) < 9);
		ShowConsoleCursor(false);


		for (int i = 0; i < danh_sach_ve.n; i++) {
			if (strcmp(temp_cmnd, danh_sach_ve.so_ghe[i]->cmnd) == 0) {
				MessageBox(NULL, L"So CMND da dat ve tren chuyen bay nay!", L"THONG BAO", MB_ICONHAND | MB_OK);
				while (kbhit()) getch();
				//stop = false;
				Xoa_khunhap();
				return;
			}
			//stop = true;
		}

//	} while (stop == false);

	Xoa_khunhap();
	check = search_hk(temp_cmnd, root_hk);
	if (check == NULL) {
		data_hk = create_data(temp_cmnd);
		//stop = true;
	}
	// da co du lieu cua hanh khach nay!
	else {
		PTR_chuyenbay p = phead_dscb;
		while (p != NULL) {
			if (is_the_same_time_30(p->data.depart_time, cb->data.depart_time) == true && p != cb) {
				for (int i = 0; i < p->data.danh_sach_ve.n; i++) {
					if (strcmp(temp_cmnd, p->data.danh_sach_ve.so_ghe[i]->cmnd) == 0) {
						MessageBox(NULL, L"Hanh khach khong the dat 2 chuyen bay khoi hanh cach nhau duoi 30 phut!", L"THONG BAO", MB_ICONHAND | MB_OK);
						while (kbhit()) getch();
						Xoa_khunhap();
						return;
					}
				}
			}
			p = p->pnext;
		}
		Xoa_khunhap();
		ve_hcnrong(x, y, 70, 18);
		ve_hcnrong(x + 5, y + 4, 36, 3);
		ve_hcnrong(x + 5, y + 7, 28, 3);
		ve_hcnrong(x + 5, y + 10, 41, 3);
		ve_hcnrong(x + 23, y + 13, 5, 3); ve_hcnrong(x + 30, y + 13, 5, 3);
		SetBGColor(14);
		gotoxy(x + 26, y + 2); cout << "[ DU LIEU KHACH HANG ]";
		gotoxy(x + 12, y + 14); cout << "Gioi tinh :";
		SetBGColor(15);
		gotoxy(x + 24, y + 14); cout << "Nam";  gotoxy(x + 31, y + 14); cout << "Nu";
		SetBGColor(11);
		gotoxy(x + 6, y + 5); cout << "Ho :                              ";
		gotoxy(x + 6, y + 8); cout << "Ten :                     ";
		gotoxy(x + 6, y + 11); cout << " CMND         :                        ";
		gotoxy(x + 22, y + 11); cout << check->data.cmnd;
		gotoxy(x + 11, y + 5); cout << check->data.ho;
		gotoxy(x + 12, y + 8); cout << check->data.ten;

		if (check->data.phai == 0) {
			gotoxy(x + 24, y + 14); cout << "Nam";
		}
		if (check->data.phai == 1) {
			gotoxy(x + 31, y + 14); cout << "Nu";
		}


		if (Thong_bao(x, y, "DAT VE CHO HANH KHACH NAY ?") == 0) {
			Xoa_khunhap();
			return;
		}
	}

	while (true) {
		Xoa_khunhap();
		ve_hcnrong(x, y, 64, 18);
		ve_hcnrong(x + 5, y + 4, 54, 3);
		SetBGColor(14);
		gotoxy(x + 17, y + 2); cout << "[NHAP SO GHE DE DAT VE MAY BAY]";
		SetBGColor(11);
		gotoxy(x + 6, y + 5); cout << "  So ghe :                                          ";
		ShowConsoleCursor(true);
		int ve = 0, ID = 0;
		do {
			ktra = 1;
			Nhan_so2(ve, x + 17, y + 5, 3, ktra, danh_sach_ve);
		} while (ve == 0);
		ShowConsoleCursor(false);

		if (ve > danh_sach_ve.limit) {// sự cố chấp
			MessageBox(NULL, L"Khong ton tai so ghe nay trong chuyen bay\n Vui long nhap so ghe khac!", L"THONG BAO", MB_ICONHAND | MB_OK);
			while (kbhit()) getch();
		}

		else if (check_empty_ve(danh_sach_ve, ve)) {



			if (check == NULL) {
				insert_node_hk(root_hk, data_hk);
				danh_sach_ve.so_ghe[danh_sach_ve.n]->stt = ve;
				
				strcpy(danh_sach_ve.so_ghe[danh_sach_ve.n]->cmnd, data_hk.cmnd);
			}
			else if (check != NULL) {
				danh_sach_ve.so_ghe[danh_sach_ve.n]->stt = ve;
				strcpy(danh_sach_ve.so_ghe[danh_sach_ve.n]->cmnd, check->data.cmnd);
			}
			Loading(x, y);
			gotoxy(x + 11, y + 9); cout << "         DAT VE THANH CONG !";
			Sleep(500);
			danh_sach_ve.n++;//tang so luong hanh khach len 1 don vi.
			sort_danh_sach_ve(danh_sach_ve);
			Xoa_khunhap();
			return;
		}
		else {
			ID = MessageBox(NULL, L"Ve nay da co nguoi dat ! \nban co muon chon ve khac!", L"THONG BAO", MB_ICONQUESTION | MB_OKCANCEL);
			while (kbhit()) getch();
			if (ID == IDCANCEL) {
				Xoa_khunhap();
				return;
			}
		}
	}
}
// ham huy ve 
void remove_ve(ds_ve& danh_sach_ve) {
	Xoa_khunhap();
	char temp_cmnd[10] = "";
	int key;
	NODE_hanhkhach hanh_khach = NULL;
	int x = 42, y = 12, ktra;
	ve_hcnrong(x, y, 64, 18);
	gotoxy(x + 1, y + 2); cout << "                NHAP CMND DE HUY VE MAY BAY";
	ve_hcnrong(x + 5, y + 4, 54, 3);
	SetBGColor(11);
	gotoxy(x + 6, y + 5); cout << "  CMND :                                            ";
	gotoxy(x + 14, y + 5);
	ShowConsoleCursor(true);
	do {
		ktra = 3;
		Nhan_chu(temp_cmnd, x + 14, y + 5, 9, ktra);
	} while (strlen(temp_cmnd) == 0 || strlen(temp_cmnd) < 9);

	ShowConsoleCursor(false);
	Xoa_khunhap();
	Loading(x, y);
	Xoa_khunhap();
	for (int i = 0; i < danh_sach_ve.n; i++) {
		if (strcmp(temp_cmnd, danh_sach_ve.so_ghe[i]->cmnd) == 0) {
			ve_hcnrong(x, y, 64, 18);
			ve_hcnrong(x + 5, y + 4, 26, 3); ve_hcnrong(x + 31, y + 4, 28, 3);
			ve_hcnrong(x + 5, y + 7, 41, 3);
			ve_hcnrong(x + 5, y + 10, 41, 3);
			SetBGColor(14);
			gotoxy(x + 16, y + 2); cout << L"[DU LIEU KHACH HANG MUON HUY VE]";
			SetBGColor(11);
			gotoxy(x + 6, y + 5); cout << "Ho :                    "; gotoxy(x + 32, y + 5); cout << "Ten :                     ";
			gotoxy(x + 6, y + 8); cout << " CMND         :                        ";
			gotoxy(x + 6, y + 11); cout << "     PHAI     :                        ";

			hanh_khach = search_hk(temp_cmnd, root_hk);
			gotoxy(x + 11, y + 5); cout << hanh_khach->data.ho; gotoxy(x + 38, y + 5); cout << hanh_khach->data.ten;
			gotoxy(x + 22, y + 8); cout << hanh_khach->data.cmnd;
			string s = (hanh_khach->data.phai == 0) ? "Nam" : "Nu";
			gotoxy(x + 22, y + 11); cout << s;

			if (Thong_bao(x, y, "ban co muon xoa hanh khach nay khong?") == 1) {
				for (int j = i; j < danh_sach_ve.n - 1; j++) {
					*danh_sach_ve.so_ghe[j] = *danh_sach_ve.so_ghe[j + 1];
				}
				MessageBox(NULL, L"XOA VE THANH CONG !", L"THONG BAO", MB_ICONINFORMATION | MB_OK);
				danh_sach_ve.n--;
				while (kbhit()) getch();
				Xoa_khunhap();
				return;
			}
			else {
				MessageBox(NULL, L"XOA VE KHONG THANH CONG !", L"THONG BAO", MB_ICONINFORMATION | MB_OK);
				while (kbhit()) getch();
				Xoa_khunhap();
				return;
			}
		}
	}
	MessageBox(NULL, L"Hanh khach van chua dat ve tren chuyen bay nay!", L"THONG BAO", MB_ICONWARNING | MB_OK);
	while (kbhit()) getch();
	return;
}
// Ham gioi thieu chuc nang 

void f1_f5(int x,int y)
{
	x = x + 5;
	gotoxy(x-4, y);  cout << "CAC PHIM TRO NANG";
	gotoxy(x, y+1); Chuyenmau_do( "F1: "); cout << "Lap Chuyen Bay Moi";
	gotoxy(x, y+2); Chuyenmau_do("F2: "); cout << "Hieu Chinh Chuyen Bay ";
	gotoxy(x, y+3); Chuyenmau_do("F3: ");  cout << "Dat ve";
	gotoxy(x + 40, y+1); Chuyenmau_do("F4: ");  cout << "In DS Ve Trong";
	gotoxy(x+40, y+2);  Chuyenmau_do("F5: ");  cout << "In DS Hanh Khach 1 Chuyen Bay";
	


}

void ve_gioithieu(int n, int m)
{
	//SetColor(57);
	SetColor(1);
	int x = 6, y = 23;
	gotoxy(x, y);
	cout << char(201);
	for (int i = 1; i <= n - 2; i++) {
		cout << char(205);
	}
	cout << char(187); gotoxy(x, ++y);
	int j = 1;
	while (j <= m - 2) {
		cout << char(186);
		for (int i = 1; i <= n - 2; i++) {
			
			cout << " ";
			
			
		}
		cout << char(186); gotoxy(x, ++y);
		j++;
	}
	cout << char(200);
	for (int i = 1; i <= n - 2; i++) {
		cout << char(205);
	}
	cout << char(188);
	gotoxy(68, 24); cout << "GIOI THIEU";
	gotoxy(7, 25); cout << " Chuc nang: ";
	
	
	
	gotoxy(7, 38); cout << " Huong dan:";
	gotoxy(7, 39); cout << "          Nhan Phim"; Chuyenmau_do(" Up / Down"); cout<< " (len / xuong) de lua chon cac chuc nang khac";
	gotoxy(7, 41); cout << "          Nhan Phim"; Chuyenmau_do(" Left / Right");cout<< " (trai / phai) de lua chon cac thanh chuc nang khac";
	gotoxy(10, 42); cout << "Esc : Thoat";
	
	//	gotoxy(50,42);cout<<"F2: Luu";
	SetBGColor(15);
	SetColor(0);
}
void xoa_gt(int t) {
	if (t == 1) {
		for (int i = 23; i <= 42; i++) {
			gotoxy(6, i);
			for (int j = 1; j <= 138; j++) cout << " ";
		}
	}
	if (t == 0) {
		for (int i = 26; i <= 37; i++) {
			gotoxy(7, i);
			for (int j = 1; j <= 136; j++) cout << " ";
		}
	}
}
void gioi_thieu(int i) {
	xoa_gt(0);
	SetColor(1);
	if (i == 1) {
		gotoxy(7, 26);  Chuyenmau_do("           THEM MAY BAY MOI ");
		gotoxy(7, 27); cout << "    (bao gom cac thong tin nhu: so hieu may bay, loai may bay , so cho) ";
		gotoxy(7, 28); Chuyenmau_do(" *Luu y :"); cout << (" - So Hieu May Bay la"); Chuyenmau_do(" DUY NHAT"); cout<< " (khong trung)";
		gotoxy(7, 30); cout << " Danh sach may bay hien co : "; Chuyenmau_do("["); cout << dsmb.n; Chuyenmau_do("]");
		f1_f5(7, 33);
	}
	if (i == 2) {
		gotoxy(7, 26); Chuyenmau_do("            XOA MAY BAY  ");
		gotoxy(7, 27); cout << "     (ban can so hieu may bay hien dang co trong danh sach may bay de xoa) ";
		gotoxy(7, 28); Chuyenmau_do(" *Luu y :"); cout << "  - Xoa duoc khi MB "; Chuyenmau_do("chua lap chuyen bay"); cout << " hoac chuyen bay o trang thai"; Chuyenmau_do("\"HUY\"");cout<<" hoac "; Chuyenmau_do("\"HOAN TAT\"");
		gotoxy(7, 30); cout << " Danh sach may bay hien co : "; Chuyenmau_do("["); cout << dsmb.n; Chuyenmau_do("]");
		f1_f5(7, 33);
	}
	if (i == 3) {
		gotoxy(7, 26); Chuyenmau_do("            HIEU CHINH MAY BAY ");
		gotoxy(7, 27); cout << "     (ban can so hieu may bay hien dang co trong danh sach may bay de hieu chinh) ";
		gotoxy(7, 28); Chuyenmau_do(" *Luu y :"); cout << "  -Neu MB chua Lap Chuyen Bay (Thay doi duoc "; Chuyenmau_do("\"Loai MB\""); cout << " va"; Chuyenmau_do(" \"So Cho\""); cout << ")";
		gotoxy(7, 29); cout << "        -Neu MB da Lap Chuyen Bay (Thay doi duoc"; Chuyenmau_do("  \"So Cho\""); cout << " theo chieu tang"; Chuyenmau_do(" (>= So Cho ban dau)"); cout << ")";
		gotoxy(7, 30); cout << " Danh sach may bay hien co : "; Chuyenmau_do("["); cout << dsmb.n; Chuyenmau_do("]");
		f1_f5(7, 33);
	}
	if (i == 4) {
		gotoxy(7, 26); Chuyenmau_do("           LAP CHUYEN BAY MOI ");
		gotoxy(7, 27); cout << "     (bao gom cac thong tin nhu: Ma chuyen bay, so hieu may bay,  Ngay gio khoi hanh, san bay den , *trang thai) ";
		gotoxy(7, 28); cout << " *trang thai bao gom : 0: huy chuyen, 1: con ve, 2: het ve, 3: hoan tat ";
		gotoxy(7, 30); Chuyenmau_do(" *Luu y :");  cout << (" - Ma May Bay la"); Chuyenmau_do(" DUY NHAT"); cout << " (khong trung)";
		gotoxy(7, 31);  cout << "        - Neu chuyen bay moi duoc lap tu 1 may bay thi"; Chuyenmau_do(" cac Chuyen Bay cach nhau >= 12h");
		
		f1_f5(7, 33);
	}
	if (i == 41) {
		gotoxy(7, 26); Chuyenmau_do("           IN DANH SACH CAC CHUYEN BAY ");
		gotoxy(7, 27); cout << "     (bao gom cac thong tin nhu: Ma chuyen bay, so hieu may bay,  Ngay gio khoi hanh, san bay den , *trang thai) ";
		gotoxy(7, 28); cout << " *trang thai bao gom : 0: huy chuyen, 1: con ve, 2: het ve, 3: hoan tat ";
		gotoxy(7, 30); Chuyenmau_do(" *Luu y :"); 
		f1_f5(7, 33);
		
	}
	if (i == 5) {
		gotoxy(7, 26); Chuyenmau_do("            HIEU CHINH NGAY GIO MOT CHUYEN BAY ");
		gotoxy(7, 27); cout << "     (ban can ma chuyen bay va so hieu may bay hien dang co trong danh sach may ba de hieu chinh) ";
		gotoxy(7, 29); Chuyenmau_do(" *Luu y :"); cout << "  - Chi hieu chinh duoc khi chuyen bay o trang thai "; Chuyenmau_do(" \"(1) con ve\" "); cout << "hoac"; Chuyenmau_do(" \"(2) het ve\"");
		f1_f5(7, 33);
	}
	if (i == 6) {
		gotoxy(7, 26); Chuyenmau_do("            HUY CHUYEN BAY ");
		gotoxy(7, 27); cout << "     (ban can ma chuyen bay hien dang co trong danh sach chuyen bay de huy) ";
		gotoxy(7, 29); Chuyenmau_do(" *Luu y :"); cout << "  - Huy khi MAY BAY o trang thai"; Chuyenmau_do(" \"(1) con ve\" "); cout << "hoac"; Chuyenmau_do(" \"(2) het ve\"");
		f1_f5(7, 33);
	}
	if (i == 7) {
		gotoxy(7, 26); Chuyenmau_do("             DAT VE TREN 1 CHUYEN BAY");
		gotoxy(7, 27); cout << "		(Ban can co so cmnd de dang ky)";
		gotoxy(7, 29); Chuyenmau_do(" *Luu y :"); cout << "  - Tren 1 chuyen bay,"; Chuyenmau_do(" moi hanh khach chi duoc mua 1 ve.");
		int y = 26;
		gotoxy(96, y); cout << "        Mo phong so do cho ngoi";
		gotoxy(96, y + 1); cout << " -----------------------------------";
		gotoxy(96, y + 2); cout << char(186) << " | 1 || 2 || 3 |...| 8 || 9 ||10 | " << char(186);
		gotoxy(96, y + 3); cout << char(176) << " |11 ||12 ||13 |...|18 ||19 ||20 | " << char(176);
		gotoxy(96, y + 4); cout << char(186) << " |21 ||22 ||23 |...|28 ||29 ||30 | " << char(186);
		gotoxy(96, y + 5); cout << char(176) << " |31 ||32 ||33 |...|38 ||39 ||40 | " << char(176);
		gotoxy(96, y + 6); cout << char(186) << " |41 ||42 ||43 |...|48 ||49 ||50 | " << char(186);
		gotoxy(96, y + 7); cout << char(176) << " |51 ||52 ||53 |...|58 ||59 ||60 | " << char(176);
		gotoxy(96, y + 8); cout << char(186) << "                 .                 " << char(186);
		gotoxy(96, y + 9); cout << char(176) << "                 .                 " << char(176);
		gotoxy(96, y + 10); cout << char(186) << " |281||282||283|...|288||289||290| " << char(186);
		gotoxy(96, y + 11); cout << char(176) << " |291||292||293|...|298||299||300| " << char(176);
		f1_f5(7, 33);
	}
	
	if (i == 8) {
		gotoxy(7, 26); Chuyenmau_do("             HUY VE DA DAT");
		gotoxy(7, 27); cout << "       (Ban can co so cmnd de huy ve)";
		gotoxy(7, 29); Chuyenmau_do(" *Luu y :"); 
		f1_f5(7, 33);
	}
	if (i == 9) {
		gotoxy(7, 26); Chuyenmau_do("             IN DANH SACH HANH KHACH THUOC 1 CHUYEN BAY");
		gotoxy(7, 27); cout << " (Bao gom cac thong tin nhu: STT, So ve, So cmnd, Ho ten, Phai)";
		gotoxy(7, 29); Chuyenmau_do(" *Luu y :");
		f1_f5(7, 33);
	}
	if (i == 91) {
		gotoxy(7, 26); Chuyenmau_do("             IN DU LIEU TAT CA HANH KHACH ");
		gotoxy(7, 27); cout << "     (Bao gom cac thong tin nhu: So cmnd, Ho ten, Phai)";
		gotoxy(7, 29); Chuyenmau_do(" *Luu y :"); 
		f1_f5(7, 33);
	}
	if (i == 10) {
		gotoxy(7, 26); Chuyenmau_do("            IN DANH SACH CAC CHUYEN BAY KHOI HANH TRONG NGAY dd/mm/yyyy DEN NOI XXXX   ");
		gotoxy(7, 27); cout << " (Danh sach cho biet cu the so luong cac ve con trong va gio khoi hanh)";
		gotoxy(7, 29); Chuyenmau_do(" *Luu y :"); 
		f1_f5(7, 33);
	}
	if (i == 11) {
		gotoxy(7, 26); Chuyenmau_do("            IN DANH SACH CAC VE CON TRONG CUA MOT CHUYEN BAY");
		gotoxy(7, 27); cout << " (Danh sach cho biet cu the so luong cac ve con trong cua chuyen bay X)";
		gotoxy(7, 29); Chuyenmau_do(" *Luu y :"); 
		f1_f5(7, 33);
	}
	if (i == 12) {
		gotoxy(7, 26); Chuyenmau_do("             THONG KE SO LUOT THUC HIEN CHUYEN BAY CUA CAC MAY BAY");
		gotoxy(7, 27); cout << " (Danh sach cho biet cu the so luot thuc hien cua cac chuyen bay)";
		gotoxy(7, 29); Chuyenmau_do(" *Luu y :"); 
		f1_f5(7, 33);
	}
	SetColor(0);
	ShowConsoleCursor(false);
}
//in danh sach chuc nang
void In_chucnang(int x, int n, string s[]) {
	if (x == 4 || x == 78)
	{
		for (int i = 0; i < n; i++) {
			ve_hcnrong(x, 3 * i + 3, 31, 3);
			Chuyenmau(x + 1, 3 * i + 4, 11, 0, s[i]);
		}
	}
	if (x == 40) {
		for (int i = 0; i < n; i++) {
			if (i == 1) {
				ve_hcnrong(x, 3 * i + 3, 31, 4);
				Chuyenmau(x + 1, 3 * i + 4, 11, 0, s[i]);
				i++;
				Chuyenmau(x + 1, 3 * (i - 1) + 5, 11, 0, s[i]);
			}
			else if (i == 3 || i == 4) {
				ve_hcnrong(x, 3 * (i - 1) + 4, 31, 3);
				Chuyenmau(x + 1, 3 * (i - 1) + 5, 11, 0, s[i]);
			}
			else {
				ve_hcnrong(x, i + 3, 31, 3);
				Chuyenmau(x + 1, i + 4, 11, 0, s[i]);
			}
		}
	}
	if (x == 114) {
		for (int i = 0; i < n; i++) {
			if (i == 1 || i == 3 || i == 5) {
				ve_hcnrong(x, 2 * i + 4, 31, 4);
				Chuyenmau(x + 1, 2 * i + 5, 11, 0, s[i]);
				i++;
				Chuyenmau(x + 1, 2 * (i - 1) + 6, 11, 0, s[i]);
			}
			else if (i == 7) {
				ve_hcnrong(x, 2 * i + 4, 31, 3);
				Chuyenmau(x + 1, 2 * i + 5, 11, 0, s[i]);
			}
			else if (i == 0) {
				ve_hcnrong(x, i + 3, 31, 3);
				Chuyenmau(x + 1, i + 4, 11, 0, s[i]);
			}
		}
	}
}
void in_DSCB_Day_place(PTR_chuyenbay& phead_dscb) {
	if (phead_dscb == NULL) {
		MessageBox(NULL, L"Chua co chuyen bay nao !", L"THONG BAO", MB_ICONWARNING | MB_OK);
		while (kbhit()) getch();
		return;
	}
	int x = 42, y = 12, ktra = 0;
	ve_hcnrong(x, y, 64, 18);
	gotoxy(x + 1, y + 2); cout << "            THONG TIN THOI GIAN KHOI HANH VA DIA DIEM";
	ve_hcnrong(x + 5, y + 4, 20, 3);
	ve_hcnrong(x + 25, y + 4, 6, 3); gotoxy(x + 31, y + 5); cout << "\\";
	ve_hcnrong(x + 32, y + 4, 6, 3); gotoxy(x + 38, y + 5); cout << "\\";
	ve_hcnrong(x + 39, y + 4, 8, 3);
	ve_hcnrong(x + 5, y + 10, 54, 3);
	SetBGColor(11);
	gotoxy(x + 26, y + 5); cout << "    "; gotoxy(x + 33, y + 5); cout << "    "; gotoxy(x + 40, y + 5); cout << "      ";
	gotoxy(x + 6, y + 5); cout << " Ngay\\thang\\nam : ";
	gotoxy(x + 6, y + 11); cout << " Nhap vao noi den  :                                ";

	ShowConsoleCursor(true);
	int temp_day = 0, temp_mon = 0, temp_year = 0;
	while (1) {
		do {
			gotoxy(x + 27, y + 5);
			cout << "  ";
			temp_day = 0, ktra = 0;
			Nhan_so(temp_day, x + 27, y + 5, 2, ktra);
		} while (temp_day == 0 || temp_day > 31);

		do {
			gotoxy(x + 34, y + 5);
			cout << "  ";
			temp_mon = 0, ktra = 0;
			Nhan_so(temp_mon, x + 34, y + 5, 2, ktra);
		} while (temp_mon == 0 || temp_mon > 12);

		do {
			temp_year = 2020, ktra = 0;
			Nhan_so(temp_year, x + 41, y + 5, 4, ktra);
		} while (temp_year == 0 || temp_year < 2020);

		date_time check;
		check.day = temp_day;
		check.mon = temp_mon;
		check.year = temp_year;
		if (days_of_mon(check) == false) {
			int kq = MessageBox(NULL, L"Thoi gian bi sai!\nban co muon nhap lai", L"THONG BAO", MB_ICONWARNING | MB_OKCANCEL);
			while (kbhit()) getch();
			if (kq == IDCANCEL) {
				ShowConsoleCursor(false);
				Xoa_khunhap();
				return;
			}
		}
		else break;
	}


	char temp_san_bay_den[20] = "";
	fflush(stdin);
	do {
		int ktra = 2;
		Nhan_chu(temp_san_bay_den, x + 27, y + 11, 20, ktra);
	} while (strlen(temp_san_bay_den) == 0);
	Viet_hoa(temp_san_bay_den);

	ShowConsoleCursor(false);
	Xoa_khunhap();
	PTR_chuyenbay ptr = phead_dscb;

	x = 37, y = 8;
	int n = 16, j = 3, np = 0, cd = 0, page = 0, pageht = 0, dem = 1, d = 0;
	Ve_bang(x, y, n, 5, dem);
	SetBGColor(1);
	SetColor(15);
	gotoxy(x + 1, y + 1); cout << "STT"; gotoxy(x + 12, y + 1); cout << "MA CB";
	gotoxy(x + 29, y + 1); cout << "SO HIEU MB"; gotoxy(x + 52, y + 1); cout << "GIO"; gotoxy(x + 70, y + 1); cout << "CON TRONG";
	SetBGColor(15);
	SetColor(0);
	while (ptr != NULL) {
		if (ptr->data.depart_time.day == temp_day && ptr->data.depart_time.mon == temp_mon && ptr->data.depart_time.year == temp_year
			&& (strcmp(ptr->data.san_bay_den, temp_san_bay_den) == 0)) {
			cd++;
			gotoxy(x + 10, y + j); cout << ptr->data.macb; gotoxy(x + 30, y + j); cout << ptr->data.so_hieu_may_bay; gotoxy(x + 50, y + j);
			cout << ptr->data.depart_time.hour << " : " << ptr->data.depart_time.min;
			gotoxy(x + 73, y + j); cout << (ptr->data.danh_sach_ve.limit - ptr->data.danh_sach_ve.n);
			j += 2;
		}
		ptr = ptr->pnext;
	}
	page = cd / 15;
	if ((cd - (page * 15)) > 0) page++;
	if (page == 0) page = 1;
	pageht = 1;
	gotoxy(x + 43, y + 33); cout << pageht << "/" << page;
	while (1) {
		np = Nhanphim();
		int k = 0;
		if (np == 27 || np == 13) break;
		if (np == 77 && pageht < page) {
			pageht++;
			k = 1;
		}
		if (np == 75 && pageht > 1) {
			pageht--;
			k = 1;
		}
		if (k == 1) {
			dem = pageht * 15 - 14;
			Ve_bang(x, y, n, 5, dem);
			SetBGColor(1);
			SetColor(15);
			gotoxy(x + 1, y + 1); cout << "STT"; gotoxy(x + 12, y + 1); cout << "MA CB"; gotoxy(x + 29, y + 1); cout << "SO HIEU MB"; gotoxy(x + 52, y + 1); cout << "GIO"; gotoxy(x + 70, y + 1); cout << "CON TRONG";
			SetBGColor(15);
			SetColor(0);
			d = 0;
			while (ptr != NULL) {
				if (ptr->data.depart_time.day == temp_day && ptr->data.depart_time.mon == temp_mon && ptr->data.depart_time.year == temp_year
					&& (strcmp(ptr->data.san_bay_den, temp_san_bay_den) == 0)) {
					d++;
					if (d >= dem && d <= pageht * 15) {
						gotoxy(x + 10, y + j); cout << ptr->data.macb; gotoxy(x + 30, y + j); cout << ptr->data.so_hieu_may_bay; gotoxy(x + 50, y + j); cout << ptr->data.depart_time.hour << " : " << ptr->data.depart_time.min;
						gotoxy(x + 73, y + j); cout << (ptr->data.danh_sach_ve.limit - ptr->data.danh_sach_ve.n);
						j += 2;
					}
				}
				ptr = ptr->pnext;
			}
			gotoxy(x + 43, y + 33); cout << pageht << "/" << page;
		}

	}
	Xoa_khunhap();
	return;
}
//In so lan thuc hien cua chuyen bay 
void print_so_luot_thuc_hien(ds_may_bay& dsmb)
{
	if (thong_bao_DSMB_0(dsmb)) return;
	for (int i = 0; i < dsmb.n; i++) {

		int temp_index = i;
		for (int j = i + 1; j < dsmb.n; j++) {
			if (dsmb.data[temp_index]->so_luot_thuc_hien < dsmb.data[j]->so_luot_thuc_hien) {
				temp_index = j;
			}
		}
		may_bay* temp_mb = dsmb.data[i];
		dsmb.data[i] = dsmb.data[temp_index];
		dsmb.data[temp_index] = temp_mb;
	}
	int x = 12, y = 8; int n1 = 16, j = 3, dem = 1, np = 0, page = 0, pageht = 0;
	ve_hcnrong(x + 98, y, 25, 8);
	Ve_bang(x, y, n1, 5, dem);
	SetBGColor(1);
	SetColor(15);
	gotoxy(x + 99, y + 1); cout << "       TRANG THAI      ";
	gotoxy(x + 1, y + 1); cout << "STT";
	gotoxy(x + 8, y + 1); cout << "SO HIEU MAY BAY";
	gotoxy(x + 26, y + 1); cout << "SO LUOT THUC HIEN";
	gotoxy(x + 48, y + 1); cout << "TRANG THAI";
	gotoxy(x + 68, y + 1); cout << "SO LUONG GHE";
	SetBGColor(10);
	SetColor(0);
	gotoxy(x + 99, y + 3); cout << "  1 : HOAT DONG        ";
	SetBGColor(4);
	SetColor(15);
	gotoxy(x + 99, y + 5); cout << "  0 : KHONG HOAT DONG  ";
	SetBGColor(15);
	SetColor(0);
	for (int i = 0; i < 15; i++) {
		if (i >= dsmb.n) break;
		gotoxy(x + 9, y + j); cout << dsmb.data[i]->so_hieu_may_bay;
		gotoxy(x + 30, y + j); cout << dsmb.data[i]->so_luot_thuc_hien;
		gotoxy(x + 51, y + j); cout << (dsmb.data[i]->active == true ? "1" : "0");
		gotoxy(x + 68, y + j); cout << dsmb.data[i]->socho;
		j += 2;
	}
	page = dsmb.n / 15;
	if ((dsmb.n - (page * 15)) > 0) page++;
	if (page == 0) page = 1;
	pageht = 1;
	gotoxy(x + 35, y + 33); cout << pageht << "/" << page;
	ShowConsoleCursor(false);
	while (1) {
		np = Nhanphim();
		int k = 0;
		if (np == 27 || np == 13) break;
		if (np == 77 && pageht < page) {
			pageht++;
			dem = pageht * 15 - 14;
			k = 1;
		}
		if (np == 75 && pageht > 1) {
			pageht--;
			dem = pageht * 15 - 14;
			k = 1;
		}
		if (k == 1) {

			Ve_bang(x, y, n1, 5, dem);
			SetBGColor(1);
			SetColor(15);
			gotoxy(x + 1, y + 1); cout << "STT"; gotoxy(x + 8, y + 1); cout << "SO HIEU MAY BAY"; gotoxy(x + 26, y + 1); cout << "SO LUOT THUC HIEN";
			gotoxy(x + 48, y + 1); cout << "TRANG THAI"; gotoxy(x + 68, y + 1); cout << "SO LUONG GHE";
			SetBGColor(15);
			SetColor(0);
			j = 3;

			for (int i = dem - 1; i < pageht * 15; i++) {
				if (i >= dsmb.n) break;
				gotoxy(x + 9, y + j); cout << dsmb.data[i]->so_hieu_may_bay; gotoxy(x + 30, y + j); cout << dsmb.data[i]->so_luot_thuc_hien;
				gotoxy(x + 51, y + j); cout << (dsmb.data[i]->active == true ? "1" : "0"); gotoxy(x + 68, y + j); cout << dsmb.data[i]->socho;
				j += 2;
			}
			gotoxy(x + 35, y + 33); cout << pageht << "/" << page;
		}
	}
	ShowConsoleCursor(false);
	Xoa_khunhap();
}
void In_tatca_hk() {
	int x = 45, y = 8, tempy = 11, n = 16, dem = 1, np = 0, page = 0, pageht = 1, bd = 1, cd = 0;
	LNR(root_hk, cd);
	Ve_bang1(x, y, n, 4, 1);
	SetBGColor(1);
	SetColor(15);
	gotoxy(x + 1, y + 1); cout << "STT"; gotoxy(x + 6, y + 1); cout << "SO CMND"; gotoxy(x + 28, y + 1); cout << "HO VA TEN"; gotoxy(x + 58, y + 1); cout << "PHAI";
	SetBGColor(15);
	SetColor(0);
	LNR(root_hk, x, tempy, dem, 1, 15);
	page = cd / 15;
	if (cd - (page * 15) > 0) page++;
	if (page == 0) page = 1;
	gotoxy(x + 28, y + 33); cout << pageht << "/" << page;
	ShowConsoleCursor(false);
	while (1) {
		np = Nhanphim();
		int k = 0;
		if (np == 13 || np == 27)break;
		if (np == 77 && pageht < page) {
			pageht++;
			k = 1;
		}
		if (np == 75 && pageht > 1) {
			pageht--;
			k = 1;
		}
		if (k == 1) {
			bd = pageht * 15 - 14;
			Ve_bang1(x, y, n, 4, bd);
			SetBGColor(1);
			SetColor(15);
			gotoxy(x + 1, y + 1); cout << "STT"; gotoxy(x + 6, y + 1); cout << "SO CMND"; gotoxy(x + 28, y + 1); cout << "HO VA TEN"; gotoxy(x + 58, y + 1); cout << "PHAI";
			SetBGColor(15);
			SetColor(0);
			tempy = 11, dem = 1;
			LNR(root_hk, x, tempy, dem, bd, pageht * 15);
			gotoxy(x + 28, y + 33); cout << pageht << "/" << page;
		}
	}
	ShowConsoleCursor(false);
	Xoa_khunhap();
}

// giai phong bo nho
void deleteTree(NODE_hanhkhach& root) {
	if (root == NULL) {
		return;
	}
	if (root->left) {
		deleteTree(root->left);
	}
	if (root->right) {
		deleteTree(root->right);
	}

	delete root;
	root = NULL;
}
void delete_dsmb(ds_may_bay& dsmb) {
	for (int i = 0; i < dsmb.n; i++) {
		delete dsmb.data[i];
	}
}
void delete_dscb(PTR_chuyenbay& phead_cb) {
	PTR_chuyenbay ptr =NULL;
	
	while (phead_dscb != NULL) {
		ptr = phead_dscb;
		phead_cb = ptr->pnext;// phead_cb=phead_cb->next ;
		delete ptr;
		
	}
}


#endif
