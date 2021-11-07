//Mai Danh Dung
//6151071038
#include<iostream>
#include<string>
using namespace std;
class mh{
	protected:
		string tmh;
		int sl;
		float dg;		
};
class hd:public mh{
	private:
		string thd;
		string dsmh;
		int slmh;
	public:
		void nhap();
		void in();
		float tongt(float *t, int n);
		float tien();
		void timkiem();
};
void hd::nhap(){
	cin.ignore();
	cout<<"Nhap ten hoa don: ";
	getline(cin,thd);
	fflush(stdin);
	cout<<"Nhap thong tin mat hang: ";
	getline(cin,tmh);
	cout<<"Nhap so luong mua: ";
	cin>>sl;
	cout<<"Gia cua mat hang la: ";
	cin>>dg;
	fflush(stdin);
	cout<<"Danh sach mat hang: ";
	getline(cin,dsmh);
	cout<<"So luong mat hang: ";
	cin>>slmh;
}
void hd::in(){
	cout<<thd;
	cout<<"\t\t"<<tmh;
	cout<<"\t\t"<<sl;
	cout<<"\t\t"<<dg;
	cout<<"\t\t"<<dsmh;
	cout<<"\t\t\t"<<slmh<<endl;
}
float hd::tien(){
	return (sl*dg);
}
//void hd::timkiem(){
//    for(i=0;i<n;++i){
//       if(strcmp(a[i].thd,)==0){
//       }
//    }
//}
int main(){
	hd a[2];
	hd b;
	int n,x;
	cout<<"Ban muon nhap bao nhieu hoa don: ";
	cin>>n;
	for(int i=0; i<n;i++){
		cout<<"Thong tin hoa don "<<i+1<<" la"<<endl;
		a[i].nhap();
	}
	cout<<"======= Thong tin ban da nhap la =======";
	cout<<"\nTen hoa don\tTen mat hang\tSo luong\tDon gia\t\tDanh sach mat hang\tSo luong mat hang"<<endl;
	for(int i=0; i<n;i++){
		a[i].in();
	}
	for(int i=0; i<n;i++){
		cout<<"So tien hoa don "<<i+1<<" la: "<<endl;
		a[i].tien();
	}
	return 0;
}
	


