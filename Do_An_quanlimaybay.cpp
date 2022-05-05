//#include "mylib.h"
//#include "my_time.h"
//#include "cau_truc_du_lieu.h"
//#include <iomanip>
//
//
//
//#include "io.h"
//using namespace std;
//
//
//void xuat_mb(may_bay& mb)
//{
//	cout << setw(20) << left << mb.so_hieu_may_bay << setw(20) << left << mb.loai_may_bay << setw(20) << left << mb.socho << setw(20) << left << mb.active<< endl;
//}
//void xuat_ds_mb(ds_may_bay ds)
//{
//	cout << endl;
//	cout << setw(20) << left << "SO HIEU MAY BAY" << setw(20) << left << "LOAI" << setw(20) << left << "SO CHO" << setw(20) << left << "ACTICE" << endl;
//
//	for (int i = 0; i < ds.n; i++)
//	{
//		//cout << "i=" << i << ":";
//		xuat_mb(*ds.data[i]);
//	}
//	cout << "\n------------------------------------------------------------------------------------------\n";
//}
//
//
//
//
//
//
////void print_empty_ve(ds_ve& danh_sach_ve, char temp_macb[]) {
////	int x = 53, y = 8; int n = 16, j = 3, dem = 1, np = 0, cd = 0, page = 0, pageht = 0;
////	ve_hcnrong(x - 41, y, 34, 3);
////	ve_hcnrong(x - 41, y + 4, 34, 3);
////	ve_hcnrong(x - 41, y + 8, 34, 3);
////	Ve_bang(x, y, n, 2, dem);
////	dem = 16;
////	Ve_bang(x + 48, y, n, 2, dem);
////	SetBGColor(11);
////	gotoxy(x - 40, y + 1); cout << "Ma chuyen bay:                  ";
////	gotoxy(x - 25, y + 1); cout << temp_macb;
////	SetBGColor(1);
////	SetColor(15);
////	gotoxy(x + 1, y + 1); cout << "STT"; gotoxy(x + 7, y + 1); cout << "STT VE CON TRONG";
////	gotoxy(x + 49, y + 1); cout << "STT"; gotoxy(x + 55, y + 1); cout << "STT VE CON TRONG";
////	SetBGColor(15);
////	SetColor(0);
////	for (int i = 0; i < danh_sach_ve.limit; i++) {
////		if (check_empty(danh_sach_ve, i + 1)) {
////			cd++;
////			if (cd == 16) j = 3;
////			if (cd <= 15) {
////				gotoxy(x + 10, y + j); cout << i + 1;
////				j += 2;
////			}
////			if (cd > 15 && cd <= 30) {
////				gotoxy(x + 58, y + j); cout << i + 1;
////				j += 2;
////			}
////		}
////	}
////	SetBGColor(2);
////	gotoxy(x - 40, y + 5); cout << "Tong so ve   :                  ";
////	gotoxy(x - 25, y + 5); cout << danh_sach_ve.limit;
////	SetBGColor(10);
////	gotoxy(x - 40, y + 9); cout << "Ve con trong :                  ";
////	gotoxy(x - 25, y + 9); cout << (danh_sach_ve.limit - danh_sach_ve.n);
////	SetBGColor(15);
////	SetColor(0);
////	page = cd / 30;
////	if ((cd - (page * 30)) > 0) page++;
////	pageht = 1;
////	
////	gotoxy(x + 35, y + 33); cout << pageht <<"/" << page;
////	
////	dem = 1; int dem2 = 0, k = 0;
////	while (1) {
////		np = Nhanphim();
////		k = 0;
////		if (np == 27 || np == 13) break;
////		if (np == 77 && pageht < page) {
////			pageht++;
////			dem = pageht * 15 - 14;
////			pageht++;
////			dem2 = pageht * 15 - 14;
////			k = 1;
////			pageht--;
////		}
////		if (np == 75 && pageht > 2) {
////			pageht--;
////			dem2 = pageht * 15 - 14;
////			pageht--;
////			dem = pageht * 15 - 14;
////			pageht++;
////			
////			k = 1;
////			
////
////		}
////		if (k == 1) {
////			cd = 0, j = 3;
////			Ve_bang(x, y, n, 2, dem);
////			Ve_bang(x + 48, y, n, 2, dem2);
////			SetBGColor(1);
////			SetColor(15);
////			gotoxy(x + 1, y + 1); cout << "STT"; gotoxy(x + 7, y + 1); cout << "STT VE CON TRONG";
////			gotoxy(x + 49, y + 1); cout << "STT"; gotoxy(x + 55, y + 1); cout << "STT VE CON TRONG";
////			SetBGColor(15);
////			SetColor(0);
////
////			for (int i = 0; i < danh_sach_ve.limit; i++) {
////				if (check_empty(danh_sach_ve, i + 1)) {
////					cd++;
////					if (cd == dem2) j = 3;
////					if (cd <= dem + 14 && cd >= dem) {
////						gotoxy(x + 10, y + j); cout << i + 1;
////						j += 2;
////					}
////					if (cd >= dem2 && cd <= dem2 + 14) {
////						gotoxy(x + 58, y + j); cout << i + 1;
////						j += 2;
////					}
////				}
////			}
////			gotoxy(x + 30, y + 33); cout << pageht << "-/" << page;
////		}
////	}
////	Xoa_khunhap();
////}
//void menu(ds_may_bay ds)
//{
//	
//
//	while (1)
//	{
//		gotoxy(5, 2);
//		cout << "\t\t\t\t0.luu" << endl;
//		cout << "\t\t\t\t1.them" << endl;
//		cout << "\t\t\t\t2.in" << endl;
//		cout << "\t\t\t\t3.edit" << endl;
//		cout << "\t\t\t\t4.lap chuyen bay" << endl;
//		cout << "\t\t\t\t5.in ds may bay" << endl;
//		cout << "\t\t\t\t6.in ds chuyen bay" << endl;
//		cout << "\t\t\t\t7.xoa may bay" << endl;
//		cout << "\t\t\t\t8.huy chuyen bay" << endl;
//		cout << "\t\t\t\t9.in ds hanh khach 1 chuyen bay" << endl;
//		cout << "\t\t\t\t10.dat ve" << endl;
//		cout << "\t\t\t\t11.tao lao" << endl;
//		cout << "\t\t\t\t11.ds ve trong" << endl;
//		
//		
//
//
//		
//		int n;
//		
//		gotoxy(5, 5);
//		cout << "\nchon:";
//		cin >> n;
//		system("cls");
//		switch (n)
//		{
//
//		case 0:
//		{
//			string f = "maybay";
//			string f1 = "chuyen bay 1";
//			string f2 = "chuyen bay 2";
//			/*Save_file_may_bay(ds,(char *)f.c_str());
//			Save_file_chuyen_bay(phead_dscb, (char*)"f1", (char*)"f2");*/
//			Open_file_may_bay(ds, (char*)f.c_str());
//			
//			Open_file_chuyen_bay(phead_dscb, (char*)"f1", (char*)"f2");
//			
//			break;
//		}
//
//		case 1:
//		{
//			
//			add_new_MB(ds);
//			break;
//		}
//		case 2:
//		{
//			
//			xuat_ds_mb(ds);
//			break;
//
//		}
//		case 3:
//		{
//			edit_maybay1(ds);
//			break;
//
//		}
//
//
//		case 4:
//		{
//			
//			add_new_ch_bay(phead_dscb,ds);
//			cout << "so luo thuc hien";
//			cout << ds.data[0]->so_luot_thuc_hien;
//			break;
//
//		}
//		case 5:
//		{
//			in_DS_MB(ds);
//			Xoa_khunhap();
//			break;
//		}
//		case 6:
//		{
//			traverse_chuyen_bay(phead_dscb);
//			Xoa_khunhap();
//			break;
//		}
//		case 7:
//		{
//			delete_may_bay(ds);
//			break;
//			
//
//		}
//		case 8:
//		{
//			del_chuyen_bay(phead_dscb, ds);
//			break;
//
//		}
//		case 9:
//		{
//			int ktra = 0; char temp_macb[15] = "";
//			PTR_chuyenbay check = NULL;
//			do {
//				ve_hcnrong(42, 15, 65, 3);
//				gotoxy(44, 16);
//				SetBGColor(11);
//				cout << "Nhap vao Ma chuyen bay :                                     ";
//				ShowConsoleCursor(true);
//				fflush(stdin);
//				do {
//					ktra = 2;
//					Nhan_chu2(temp_macb, 69, 16, 15,ds, ktra);
//				} while (strlen(temp_macb) == 0);
//				strupr(temp_macb);
//				SetBGColor(15);
//				ShowConsoleCursor(false);
//				check = search_node(phead_dscb, temp_macb);
//				if (check != NULL) {
//					Xoa_khunhap();
//					print_by_macb(check->data);
//				}
//				else {
//					int result = MessageBox(NULL, L"Ma chuyen bay khong ton tai\n Ban co muon nhap lai", L"THONG BAO", MB_ICONWARNING | MB_OKCANCEL);
//					while (kbhit()) getch();
//					if (result == IDCANCEL) {
//						Xoa_khunhap();
//						break;
//					}
//				}
//			} while (check == NULL);
//			break;
//
//		}
//
//		case 10:
//		{
//			PTR_chuyenbay check = NULL;
//			int ktra = 0;
//			char temp_macb[15];
//			update_statement(phead_dscb);
//			do {
//				memset(temp_macb, '\0', sizeof(temp_macb));
//				Xoa_khunhap();
//				ve_hcnrong(42, 15, 65, 3);
//				gotoxy(44, 16);
//				SetBGColor(11);
//				cout << "Nhap vao Ma chuyen bay :                                     ";
//				ShowConsoleCursor(true);
//				fflush(stdin);
//				do {
//					ktra = 3;
//					Nhan_chu2(temp_macb, 69, 16, 15,ds, ktra);
//				} while (strlen(temp_macb) == 0);
//				strupr(temp_macb);
//				SetBGColor(15);
//				ShowConsoleCursor(false);
//				check = search_node(phead_dscb, temp_macb);
//
//				if (check != NULL && check->data.trang_thai == 1) {
//					order_ve(phead_dscb, check, check->data.danh_sach_ve);
//
//					break;
//				}
//				else if (check == NULL) {
//					int result = MessageBox(NULL, L"Ma chuyen bay khong ton tai\n Ban co muon nhap lai", L"THONG BAO", MB_ICONWARNING | MB_OKCANCEL);
//					while (kbhit()) getch();
//					if (result == IDCANCEL) {
//						Xoa_khunhap();
//						break;
//					}
//				}
//				else if (check->data.trang_thai == 3) {
//					int result = MessageBox(NULL, L"Chuyen bay nay da thuc hien!\n Ban co muon nhap lai", L"THONG BAO", MB_ICONWARNING | MB_OKCANCEL);
//					while (kbhit()) getch();
//					if (result == IDCANCEL) {
//						Xoa_khunhap();
//						break;
//					}
//				}
//				else if (check->data.trang_thai == 0) {
//					int result = MessageBox(NULL, L"Chuyen bay nay da bi huy!\n Ban co muon nhap lai", L"THONG BAO", MB_ICONWARNING | MB_OKCANCEL);
//					while (kbhit()) getch();
//					if (result == IDCANCEL) {
//						Xoa_khunhap();
//						break;
//					}
//				}
//				else if (check->data.trang_thai == 2) {
//					int result = MessageBox(NULL, L"Chuyen bay nay da het ve!\n Ban co muon nhap lai", L"THONG BAO", MB_ICONWARNING | MB_OKCANCEL);
//					while (kbhit()) getch();
//					if (result == IDCANCEL) {
//						Xoa_khunhap();
//						break;
//					}
//				}
//			} while (true);
//
//			break;
//
//		}
//
//		case 11:
//		{
//			int ktra = 0; char temp_macb[15] = "";
//			PTR_chuyenbay check = NULL;
//			do {
//				ve_hcnrong(42, 15, 65, 3);
//				gotoxy(44, 16);
//				SetBGColor(11);
//				cout << "Nhap vao Ma chuyen bay :                                     ";
//				ShowConsoleCursor(true);
//				fflush(stdin);
//				do {
//					ktra = 2;
//					Nhan_chu2(temp_macb, 69, 16, 15,ds, ktra);
//				} while (strlen(temp_macb) == 0);
//				strupr(temp_macb);
//				SetBGColor(15);
//				ShowConsoleCursor(false);
//				check = search_node(phead_dscb, temp_macb);
//				if (check != NULL) {
//					Xoa_khunhap();
//					print_empty_ve(check->data.danh_sach_ve, temp_macb);
//				}
//				else {
//					int result = MessageBox(NULL, L"Ma chuyen bay khong ton tai\n Ban co muon nhap lai", L"THONG BAO", MB_ICONWARNING | MB_OKCANCEL);
//					while (kbhit()) getch();
//					if (result == IDCANCEL) {
//						Xoa_khunhap();
//						break;
//					}
//				}
//			} while (check == NULL);
//
//		}
//		case 12:
//		{
//
//			int ktra = 0; char temp_macb[15] = "";
//			PTR_chuyenbay check = NULL;
//			do {
//				ve_hcnrong(42, 15, 65, 3);
//				gotoxy(44, 16);
//				SetBGColor(11);
//				cout << "Nhap vao Ma chuyen bay :                                     ";
//				ShowConsoleCursor(true);
//				fflush(stdin);
//				do {
//					ktra = 2;
//					Nhan_chu2(temp_macb, 69, 16, 15,ds, ktra);
//				} while (strlen(temp_macb) == 0);
//				strupr(temp_macb);
//				SetBGColor(15);
//				ShowConsoleCursor(false);
//				check = search_node(phead_dscb, temp_macb);
//				if (check != NULL) {
//					Xoa_khunhap();
//					print_empty_ve(check->data.danh_sach_ve, temp_macb);
//				}
//				else {
//					int result = MessageBox(NULL, L"Ma chuyen bay khong ton tai\n Ban co muon nhap lai", L"THONG BAO", MB_ICONWARNING | MB_OKCANCEL);
//					while (kbhit()) getch();
//					if (result == IDCANCEL) {
//						Xoa_khunhap();
//						break;
//					}
//				}
//			} while (check == NULL);
//
//		}
//		default:
//			break;
//		}
//	}
//}
//
//
//
//
//
//
//
//
//
//
//
////
//
//int main()
//{
//	
//	menu(dsmb);
//	
//	/*char temp_t[16] = "";
//	cout << strlen(temp_t);*/
//	
//	/*for (int i = 0; i < 100; i++)
//	{
//		cout << (char)218; 
//	}
//	*/
//	/*SetBGColor(29);
//	char c[10];
//	gotoxy(5, 1); cout << "Nhap cmnd: ";
//	cin.getline(c, 3);
//	hanh_khach hk = create_data(c);
//	NODE_hanhkhach root = create_node(hk);
//	
//	for (int i = 0; i < 6; i++)
//	{
//		
//		gotoxy(5, 1); cout << "Nhap cmnd: ";
//		cin.getline(c, 3);
//		hk = create_data(c);
//		insert_node_hk(root, hk);
//	}
//	cout << treeLevel(root)<< endl;
//	NLR(root);
//	*/
//
//	
//	return 0;
//}
#include "menu.h"
int main() {
	
	
	
	Chon_chucnang();
	deleteTree(root_hk);
	delete_dsmb(dsmb);
	delete_dscb(phead_dscb);
	

	return 0;
}
