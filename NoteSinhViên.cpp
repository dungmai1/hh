#include"iostream"
#include"string"
#include"stdlib.h"
using namespace std;

struct SinhVien {
	int mssv;
	string name;
	string diachi;
	string ngaysinh;
	string lop;
};
typedef struct SinhVien sinhvien;
struct node {
	sinhvien *data;
	struct  node* link;
};
typedef struct node Node;
struct list {
	Node* pHead;
	Node* pTail;
};
typedef struct list List;
void KhoiTaoList(List &l) {
	l.pHead = l.pTail = NULL;
}
void Input_ThongTin(sinhvien *sv) {
	cin.ignore();
	cout << "Nhap Ten sinh vien: \n";
	fflush(stdin);
	getline(cin,sv->name);
	cout << "Nhap Ma so sinh vien : ";
	cin >> sv->mssv;	
	cin.ignore();
	cout << "Nhap dia chi sinh vien :\n";
	getline(cin,sv->diachi);
	fflush(stdin);
	cout << "Nhap ngay sinh cua sinh vien:\n";
	getline(cin, sv->ngaysinh);
	fflush(stdin);
	cout << "Nhap lop cua sinh vien : ";
	getline(cin, sv->lop);
}
Node *KhoiTaoNode() {
	sinhvien* sv = new sinhvien;
	Input_ThongTin(sv);
	Node* p = new Node;
	if (p == NULL) {
		cout << "full ram ko th? tao thêm\n";
		return 0;
	}
	p->data = sv;
	p->link = NULL;
	return p;
}
void ThemVaoDauMotSinhVien(List &l, Node *p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail= p;
	}
	else {
		p->link = l.pHead;
		l.pHead = p;
	}
}
void Show(List l) {
	for (Node* k = l.pHead; k != NULL; k = k->link) {
		cout << "MSSV : " << k->data->mssv<<endl;
		cout << "Ten  : " << k->data->name << endl;
		cout << "Dia Chi  : " << k->data->diachi << endl;
		cout << "Ngay Sinh : " << k->data->ngaysinh << endl;
		cout << "Lop : " << k->data->lop << endl;
		cout << "==============================SV================\n";
	}
}
void showNode(Node *k) {
	cout << "==============================SV================\n";
	cout << "MSSV : " << k->data->mssv << endl;
	cout << "Ten  : " << k->data->name << endl;
	cout << "Dia Chi  : " << k->data->diachi << endl;
	cout << "Ngay Sinh : " << k->data->ngaysinh << endl;
	cout << "Lop : " << k->data->lop << endl;
}
void XoaSV(List& l) {
	string Xoa;
	cin.ignore();
	cout << "Nhap Ma So SV hoac Ten SV Can Xoa : \n";
	fflush(stdin);
	getline(cin, Xoa);
	Node* g = new Node;
	if (Xoa.compare(l.pHead->data->name) == 0 && l.pHead->link ==NULL) {
		l.pHead = NULL;
	}
	else{
		for (Node* k = l.pHead; k != NULL; k = k->link) {
			if (Xoa.compare(k->data->name) == 0) {
				g->link = k->link;
				k = g;
			}
			g = k;
		}
}
}

void ChucNang(List &l) {
	int n;
	cout << "======Danh Sach Chuc Nang=========\n";
	cout << "1 => Nhap 1 sinh vien moi .\n";
	cout << "2 => In danh sach sinh vien .\n ";
	cout << "3 => Xoa sinh vien khoi danh sach\n";
	cout << "0 = >Thoat chuong trinh\n";
	while (1){
		cout << "Nhap chuc nang ban  chon : ";
		cin >> n;
		if (n == 1) {
			cout << "Moi Ban nhap thong tin 1 sinh vien : \n";
			Node* p = KhoiTaoNode();
			ThemVaoDauMotSinhVien(l, p);
		}		
		if (n == 2) {
			cout << "Danh Sach Sinh Vien : \n";
			Show(l);
		}
		if (n == 3) {
			XoaSV(l);
		}
		if (n == 0) {
			break;
		}
	}
}

int main() {
	List l;
	KhoiTaoList(l);
	ChucNang(l);
	system("pause");
	return 0;
}
