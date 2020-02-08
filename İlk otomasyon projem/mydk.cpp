#include <iostream>
#include <cstring> // string iþlemler
#include <fstream> //dosya iþlemleri
#include<locale.h> //türkçe karakter kullanmak için
#include <conio.h> // dosya ad deðiþikliði
#include <iomanip> // setw kullanmak için
#include <stdio.h>
using namespace std;
void pduzenle(int sayi);
void uduzenle(int sayi);

class personel1{
	private:
		string pkimlik,pno;
		string pad,psoyad;
		
		public:
			void setpkimlik(string pk)
			{
				pkimlik=pk;
			}
			string getpkimlik()
			{
				return pkimlik;
			}
			
			void setpno(string pn)
			{
				pno=pn;
			}
			string getpno()
			{
				return pno;
			}
			
			void setpad(string pa)
			{
				pad=pa;
			}
			string getpad()
			{
				return pad;
			}
			
			void setpsoyad(string ps)
			{
				psoyad=ps;
			}
			string getpsoyad()
			{
				return psoyad;
			}
		
	
	void pekle()
{
	system("CLS");
	cout<<"*** PERSONEL KAYIT FORMU ***"<<endl;
	cout<<"============================"<<endl<<endl;
	string kimlik,no;
	int k,n;
	string ad,soyad;
	ofstream yaz;
	yaz.open("personel.txt",ios::app);
	fflush(stdin);
	cout<<"2 haneli personel no giriniz:";
	getline(cin,no);
	n=no.length();
	while(n!=2)
	{
		fflush(stdin);
		cout<<"Lutfen 2 haneli giriniz:";
		getline(cin,no);
		n=no.length();
	}
	fflush(stdin);
	cout<<"Personel adini giriniz:";
	getline(cin,ad);
	fflush(stdin);
	cout<<"Personel soyadi giriniz:";
	getline(cin,soyad);
	fflush(stdin);
	cout<<"Personel kimligi giriniz:";
	getline(cin,kimlik);
	k=kimlik.length();
	while(k!=11)
	{
		fflush(stdin); // Tab boþluðuna da kabul ediyor !
		cout<<"Lutfen kimlik bilgisini 11 haneli giriniz:";
		getline(cin,kimlik);
		k=kimlik.length();
	}
	
	setpkimlik(kimlik);
	setpno(no);
	setpad(ad);
	setpsoyad(soyad);
	
	yaz<<endl<<getpno()<<" -)"<<setw(4)<<"        "<<getpad()<<setw(9)<<"  "<<getpsoyad()<<setw(10)<<" "<<getpkimlik()<<setw(11);
	yaz.close();
	
	cout<<endl<<"[ *** Yeni Personel Eklendi. *** ]"<<endl;
}

//=====================================================================================================================

void plistele()
{
	system("CLS");
	cout<<"*** PERSONEL BÝLGÝLERÝ ***"<<endl;
	cout<<"=========================="<<endl<<endl;
	cout<<"-P. NO -     - AD -       - SOYAD -        - KÝMLÝK -"<<endl,
	cout<<"========     ======       =========        =========="<<endl;
	string okunan;
	ifstream poku;
	poku.open("personel.txt",ios::in);
	while(!poku.eof())
	{
		getline(poku,okunan);
		cout<<okunan<<endl;
	}
	
}

//=====================================================================================================================

void parama()
{
		system("CLS");
		cout<<"*** PERSONEL ARAMA EKRANI ***"<<endl;
		cout<<"============================="<<endl<<endl;
	int x,a,sa;
	sa=0;
	string okunan;
	ifstream oku("personel.txt",ios::in);
	cout<<"Aramak istediðiniz personel no giriniz:";
	cin>>x;
	
    while(!oku.eof())
	{
	oku>>a; //satýrýn ilk kelimesindeki sayiyi int a degerine atadik.
	getline(oku,okunan);
	if(a==x)
	{ 
	cout<<endl;
	cout<<"-P. NO -     - AD -       - SOYAD -        - KÝMLÝK -"<<endl,
	cout<<"========     ======       =========        ==========";
	sa++;
	cout<<endl<<a<<okunan<<endl;
}
	}
	
	if(sa<1)
	cout<<endl<<"X X X  Kayýtlý Kullanýcý Bulunamadý !  X X X"<<endl;
	oku.close();		

	}

}; 

//**********************************************************************************************************************

class personel2{
	
	int yaz(int a)
	{
		return a;
	}
	
	string yaz(string b)
	{
		return b;
	}
	
	protected:
		int x,a;
	public:
		
		int psilme()
		{
	system("CLS");
	int sayac=0,sa=0;
	string okunan;
	ifstream oku("personel.txt",ios::in);
	ofstream yaz2;
	yaz2.open("personelyedek.txt",ios::out);
	
	cout<<"*** PERSONEL KAYIT SÝLME ***"<<endl;
	cout<<"============================"<<endl<<endl;
	cout<<"Silinecek satýr no giriniz:";
	cin>>x;
	
    while(!oku.eof())
	{
	oku>>a; //satýrýn ilk kelimesindeki sayiyi int a degerine atadik.
	getline(oku,okunan);
	if(a==x)
	{
		sayac=sayac-1;
		sa++;
	}
	if(a!=x)
	yaz2<<a<<okunan<<endl;
	sayac++;
	
	}
	
	if(sa>0)
	cout<<endl<<"*** Silme iþlemi baþarýlý bir þekilde gerçekleþtirildi. ***"<<endl;
	
	if(sa<1)
	cout<<endl<<"X X X  Silmek istediðiniz kullanýcý zaten kayýtlý deðil !  X X X"<<endl;
	
		yaz2.close();
		oku.close();		
		remove("personel.txt");
		rename("personelyedek.txt","personel.txt");
		return sayac;
		}
		
//=====================================================================================================================
		
		int pguncelleme()
		{
	system("CLS");
	cout<<"*** PERSONEL GÜNCELLEME ***"<<endl;
	cout<<"==========================="<<endl<<endl;
	int sayac=0,sa=0,k,n;
	string okunan,yad,yno,ysoyad,ykimlik;
	ifstream oku("personel.txt",ios::in);
	ofstream yaz2;
	yaz2.open("personelyedek.txt",ios::out);
	
	cout<<"Güncellemek istediðiniz satýr no giriniz:";
	cin>>x;
	fflush(stdin);
	cout<<"2 haneli yeni personel no giriniz:";
	getline(cin,yno);
	n=yno.length();
	while(n!=2)
	{
		fflush(stdin);
		cout<<"Lutfen 2 haneli giriniz:";
		getline(cin,yno);
		n=yno.length();
	}
	fflush(stdin);
	cout<<"Yeni personel adini giriniz:";
	getline(cin,yad);
	fflush(stdin);
	cout<<"Yeni personel soyadi giriniz:";
	getline(cin,ysoyad);
	fflush(stdin);
	cout<<"Yeni personel kimligi giriniz:";
	getline(cin,ykimlik);
	k=ykimlik.length();
	while(k!=11)
	{
		fflush(stdin);
		cout<<"Lutfen kimlik bilgisini 11 haneli giriniz:";
		getline(cin,ykimlik);
		k=ykimlik.length();
	}
	
    while(!oku.eof())
	{
	oku>>a; //satýrýn ilk kelimesindeki sayiyi int a degerine atadik.
	getline(oku,okunan);
	if(a==yaz(x))
	{
		yaz2<<yaz(yno)<<" -)"<<setw(4)<<"        "<<yaz(yad)<<setw(9)<<"  "<<yaz(ysoyad)<<setw(10)<<"  "<<yaz(ykimlik)<<endl;
		sa++;
	}
	if(a!=yaz(x))
	yaz2<<a<<okunan<<endl;
	sayac++;
	
	}
	
	if(sa>0)
	cout<<endl<<"*** Güncelleme iþlemi baþarýlý bir þekilde gerçekleþtirildi. ***"<<endl;
	
	if(sa<1)
	cout<<endl<<"X X X  Güncellemek istediðiniz kullanýcý kayýtlý deðil !  X X X"<<endl;
	
		yaz2.close();
		oku.close();		
		remove("personel.txt");
		rename("personelyedek.txt","personel.txt");
		return sayac;
		}
	
};

//**********************************************************************************************************************

class personel : public personel1 , public personel2{ //Çoklu kalýtým !
	public:
		personel();
		~personel();
	
};
personel::personel() 	//yapici
 	{ 
	cout<<endl<<"		*** MAÐAZA OTOMASYONUNA HOÞGELDÝNÝZ ***"<<endl;
	cout<<"		======================================="<<endl<<endl<<endl;
	}
	
	personel::~personel()	//yikici
	{
	 cout<<endl<<endl<<"*** ÝYÝ GÜNLER DÝLERÝZ :) ***";
	}
	
	
	//**********************************************************************************************************************
	//**********************************************************************************************************************
	//**********************************************************************************************************************
	
class urun{
	public:
	void uekle()
{
	system("CLS");
	cout<<"*** ÜRÜN EKLEME ***"<<endl;
	cout<<"==================="<<endl<<endl;
	string no;
	int n,adet;
	string ad;
	ofstream yaz;
	yaz.open("urun.txt",ios::app);
	fflush(stdin);
	cout<<"2 haneli ürün no giriniz:";
	getline(cin,no);
	n=no.length();
	while(n!=2)
	{
		fflush(stdin);
		cout<<"Lutfen 2 haneli giriniz:";
		getline(cin,no);
		n=no.length();
	}
	cout<<"Ürün adýný giriniz:";
	cin>>ad;
	cout<<"Ürün adedini giriniz:";
	cin>>adet;
	yaz<<endl<<no<<" -)"<<setw(4)<<"       "<<ad<<setw(13)<<"  [ "<<adet<<" ]";
	yaz.close();
	cout<<endl<<"[ *** Yeni Ürün Maðazamýza Eklendi. *** ]"<<endl;
	
}

//----------------------------------------------------------------

void uarama()
{
    system("CLS");
	cout<<"*** ÜRÜN ARAMA EKRANI ***"<<endl;
	cout<<"============================="<<endl<<endl;
	int x,a,sa;
	sa=0;
	string okunan;
	ifstream oku("urun.txt",ios::in);
	cout<<"Aramak istediðiniz ürün no giriniz:";
	cin>>x;
	
    while(!oku.eof())
	{
	oku>>a; //satýrýn ilk kelimesindeki sayiyi int a degerine atadik.
	getline(oku,okunan);
	if(a==x)
	{ 
	cout<<endl;
	cout<<"-U. NO -    - AD -        - U.ADET -"<<endl;
	cout<<"========    ======        ==========";
	sa++;
	cout<<endl<<a<<okunan<<endl;
}
	}
	
	if(sa<1)
	cout<<endl<<"X X X  Kayýtlý Kullanýcý Bulunamadý !  X X X"<<endl;
	oku.close();		

	}



int usil()
{
	system("CLS");
	int x,a,sayac=0,sa=0;
	string okunan;
	ifstream oku("urun.txt",ios::in);
	ofstream yaz2;
	yaz2.open("urunyedek.txt",ios::out);
	
	cout<<"*** ÜRÜN KAYIT SÝLME ***"<<endl;
	cout<<"========================"<<endl<<endl;
	cout<<"Silinecek ürün no giriniz:";
	cin>>x;
	
    while(!oku.eof())
	{
	oku>>a; //satýrýn ilk kelimesindeki sayiyi int a degerine atadik.
	getline(oku,okunan);
	if(a==x)
	{
		sayac=sayac-1;
		sa++;
	}
	if(a!=x)
	yaz2<<a<<okunan<<endl;
	sayac++;
	}
	
	if(sa>0)
	cout<<endl<<"*** Silme iþlemi baþarýlý bir þekilde gerçekleþtirildi. ***"<<endl;
	
	if(sa<1)
	cout<<endl<<"X X X  Silmek istediðiniz kullanýcý zaten kayýtlý deðil !  X X X"<<endl;
	
		yaz2.close();
		oku.close();		
		remove("urun.txt");
		rename("urunyedek.txt","urun.txt");
		return sayac;
}

//----------------------------------------------------------------

	void ulistele()
		{
	system("CLS");
	cout<<"*** ÜRÜN LÝSTESÝ ***"<<endl;
	cout<<"===================="<<endl<<endl;
	cout<<"-U. NO -    - AD -        - U.ADET -"<<endl,
	cout<<"========    ======        =========="<<endl;
	string okunan;
	ifstream uoku;
	uoku.open("urun.txt",ios::in);
	while(!uoku.eof())
	{
		getline(uoku,okunan);
		cout<<okunan<<endl;
	}
		}

//----------------------------------------------------------------

int uguncelleme()
{
	system("CLS");
	cout<<"*** ÜRÜN GÜNCELLEME ***"<<endl;
	cout<<"======================="<<endl<<endl;
	
	int x,a,sayac=0,sa=0,adet,n;
	string okunan,no,ad;
	ifstream oku("urun.txt",ios::in);
	ofstream yaz2;
	yaz2.open("urunyedek.txt",ios::out);
	
	
	cout<<"Güncellenecek ürün no giriniz:";
	cin>>x;
	fflush(stdin);
	cout<<"2 haneli yeni ürün no giriniz:";
	getline(cin,no);
	n=no.length();
	while(n!=2)
	{
		fflush(stdin);
		cout<<"Lutfen 2 haneli giriniz:";
		getline(cin,no);
		n=no.length();
	}
	fflush(stdin);
	cout<<"Ürün adýný giriniz:";
	getline(cin,ad);
	cout<<"Ürün adedini giriniz:";
	cin>>adet;
	
    while(!oku.eof())
	{
	oku>>a; //satýrýn ilk kelimesindeki sayiyi int a degerine atadik.
	getline(oku,okunan);
	if(a==x)
	{
		yaz2<<no<<" -)"<<setw(4)<<"       "<<ad<<setw(13)<<"  [ "<<adet<<" ]"<<endl;
		sa++;
	}
	if(a!=x)
	yaz2<<a<<okunan<<endl;
	sayac++;
	}
	
	if(sa>0)
	cout<<endl<<"*** Güncelleme iþlemi baþarýlý bir þekilde gerçekleþtirildi. ***"<<endl;
	
	if(sa<1)
	cout<<endl<<"X X X Güncellemek istediðiniz kullanýcý zaten kayýtlý deðil !  X X X"<<endl;
	
		yaz2.close();
		oku.close();		
		remove("urun.txt");
		rename("urunyedek.txt","urun.txt");
		return sayac;
}
};


	//**********************************************************************************************************************
	//**********************************************************************************************************************
	//**********************************************************************************************************************
	
class stok{
	public:
		
		int yaz(int a)
		{
			return a;
		}
		
		string yaz(string b)
		{
			return b;
		}
		
		int sislem()
		{
			system("CLS");
	cout<<"*** STOK GÜNCELLEME ***"<<endl;
	cout<<"==================="<<endl<<endl;
	
	int x,a,sayac=0,sa=0,adet,n;
	string okunan,ad;
	ifstream oku("urun.txt",ios::in);
	ofstream yaz2;
	yaz2.open("urunyedek.txt",ios::out);
	
	cout<<"Güncellenecek ürün no giriniz:";
	cin>>x;
	
	fflush(stdin);
	cout<<"Ürün adýný giriniz:";
	getline(cin,ad);
	
	cout<<"Ürün adedini giriniz:";
	cin>>adet;
	
    while(!oku.eof())
	{
	oku>>a; //satýrýn ilk kelimesindeki sayiyi int a degerine atadik.
	getline(oku,okunan);
	if(a==x)
	{
		yaz2<<a<<" -)"<<setw(4)<<"       "<<yaz(ad)<<setw(13)<<"  [ "<<yaz(adet)<<" ]"<<endl;
		sa++;
	}
	if(a!=x)
	yaz2<<a<<okunan<<endl;
	sayac++;
	}
	
	if(sa>0)
	cout<<endl<<"*** Güncelleme iþlemi baþarýlý bir þekilde gerçekleþtirildi. ***"<<endl;
	
	if(sa<1)
	cout<<endl<<"X X X Güncellemek istediðiniz kullanýcý kayýtlý deðil !  X X X"<<endl;
	
		yaz2.close();
		oku.close();		
		remove("urun.txt");
		rename("urunyedek.txt","urun.txt");
		return sayac;

		}

//----------------------------------------------------------------
		
	
};

int main()
{
	setlocale(LC_ALL, "Turkish"); 
	
	personel p;
	urun u;
	stok s;
	int kontrol;
	do{
	int secim,tercih,pkayit,ukayit;
	cout<<" #  PERSONEL MENÜ  #  	  	  #  ÜRÜN MENÜ  #	     #  STOK MENÜ  #"<<endl;
	cout<<" ====================	   	 ================	     ================"<<endl;
	cout<<" 1-) Personel Ekleme	   	 6-) Ürün Ekleme	     11-) Stok Güncelleme"<<endl;
	cout<<" 2-) Personel Listeleme   	 7-) Ürün Arama"<<endl;
	cout<<" 3-) Personel Arama	   	 8-) Ürün Silme"<<endl;    
	cout<<" 4-) Personel Silme	   	 9-) Ürün Listeleme"<<endl;
	cout<<" 5-) Personel Güncelleme	 10-) Ürün Güncelleme"<<endl;
	cout<<endl<<"Seçiminizi giriniz: ";
	cin>>secim;
	
	while(secim<1 || secim>11)
	{
		cout<<"Lütfen 1 ile 11 arasýnda bir deðer giriniz:";
		cin>>secim; 
	}
	
	switch(secim)
	{
		case 1: p.pekle(); break;
	
		case 2: p.plistele(); break; 
		
		case 3: p.parama(); break;
		
		case 4: 
		pkayit=p.psilme();
		pduzenle(pkayit);
		 break; 
		
		case 5: 
		pkayit=p.pguncelleme();
		pduzenle(pkayit);
		 break;
		
		case 6: u.uekle(); break;
		
		case 7: u.uarama(); break;
		
		case 8: 
		ukayit=u.usil();
		uduzenle(ukayit);
		 break; 
		 
		case 9: u.ulistele();	 break;
		
		case 10: 
		ukayit=u.uguncelleme();
		uduzenle(ukayit);
		 break; 
		
		case 11: 
		ukayit=s.sislem();
		uduzenle(ukayit);
		 break;
		
	}
	
	
	cout<<"\nTekrar iþlem yapmak ister misiniz ? \n(1-Evet , 2-Hayýr)\nTercih:";
	cin>>tercih;
	
	while(tercih<1 || tercih>2)
	{
		cout<<"\nLutfen 1 veya 2 degerini giriniz:";
		cin>>tercih;
	}
	if(tercih==1){
	kontrol=true;
	system("CLS");
}
	else
	kontrol=false;
   }while(kontrol);

	return 0;
}

//============================================================
void pduzenle(int sayi)
{
	string kayit;
	int sayac=0;
	ifstream oku("personel.txt",ios::in);
	ofstream yaz2("personelyedek.txt",ios::out);

	while(!oku.eof())
	{
	if(sayac!=sayi-1){
    getline(oku,kayit);
	yaz2<<kayit<<endl;
}
	if(sayac==sayi-1){
    getline(oku,kayit);
	yaz2<<kayit;
}
	sayac++;
	if(sayac==sayi)
	break;
	}
	
		yaz2.close();
		oku.close();		
		remove("personel.txt");
		rename("personelyedek.txt","personel.txt");
}

//============================================================
void uduzenle(int sayi)
{
	string kayit;
	int sayac=0;
	ifstream oku("urun.txt",ios::in);
	ofstream yaz2("urunyedek.txt",ios::out);

	while(!oku.eof())
	{
	if(sayac!=sayi-1){
    getline(oku,kayit);
	yaz2<<kayit<<endl;
}
	if(sayac==sayi-1){
    getline(oku,kayit);
	yaz2<<kayit;
}
	sayac++;
	if(sayac==sayi)
	break;
	}
	
		yaz2.close();
		oku.close();		
		remove("urun.txt");
		rename("urunyedek.txt","urun.txt");
}
