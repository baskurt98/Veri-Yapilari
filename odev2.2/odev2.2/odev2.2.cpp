#include "stdafx.h"
#include <iostream>
#include <string> // string islemler
#include <fstream> //dosya islemleri
#include<locale.h> //turkce karakter kullanmak icin
#include <stdio.h>
using namespace std;

struct node {
	string data;
	node *next;
	node *prev;
};

void dhyaz(node *r) //program kapatilirken en son yapilan islemler guncel haliyle dosyaya aktarmak icin kullandim.
{
	ofstream yaz("iller.txt");
	node *yrd;
	yrd = r;
	if (r == NULL)
	{
		return;
	}
	while (yrd->next != r)
	{
		yaz << yrd->data << endl;
		yrd = yrd->next;
	}
	yaz << yrd->data << endl;
	yaz.close();
}


node *ekle(node *r, string x) {
	if (r == NULL)
	{
		r = new node;
		r->data = x;
		r->next = r;
		r->prev = r;
	}
	else {
		r->prev->next = new node;
		r->prev->next->data = x;
		r->prev->next->next = r;
		r->prev->next->prev = r->prev;
		r->prev = r->prev->next;
	}
	dhyaz(r);
	return r;
}
node *dlistele(node *r) // Program acildiðinda dosyada olanlari listeye aktarma islemi icin olusturdum.
{
	string okunan;
	ifstream oku;
	oku.open("iller.txt", ios::in);
	if (oku)
	while (!oku.eof())
	{
		getline(oku, okunan);
		if (okunan.length()>0)
			r = ekle(r, okunan);
	}
	return r;
}

node *arama(node *r, string ne)
{
	if (r == NULL)
		return NULL;
	else
	{
		node *yrd;
		yrd = r;

		while (yrd->data != ne && yrd->next != r)
			yrd = yrd->next;

		if (yrd->data == ne)
			return yrd;

		else
			return NULL;

	}

}

node *ilArama(node *r, string ne) // il ararken ekrana cikti almak icin ayri bir arama fonksiyonu olusturdum.
{
	if (r == NULL)
	{
		cout << "Liste bos" << endl;
		return NULL;
	}
	else
	{
		node *yrd;
		yrd = r;

		while (yrd->data != ne && yrd->next != r)
			yrd = yrd->next;

		if (yrd->data == ne)
		{
			cout << "Aranýlan il bulundu: " << ne << endl;
			return yrd;
		}
		else{
			cout << "Aranýlan il bulunamadý!" << endl;
			return r;
		}
	}

}

node *sil(node *r, string hangisi)
{
	if (r == NULL)
		cout << "Liste bos !";

	else
	{
		node *yrd;
		yrd = arama(r, hangisi);

		if (yrd == NULL)
			cout << "Silinecek eleman bulunamadý";

		else
		{
			if (yrd == r)
			{
				if (yrd->next == r)
				{
					delete yrd;
					cout << "Silme iþlemi baþarýlý"<<endl;
					return NULL;
				}
				
			
			}
			r = yrd->next;
			yrd->prev->next = yrd->next;
			yrd->next->prev = yrd->prev;
			yrd->next = NULL;
			yrd->prev = NULL;
			delete yrd;
			cout << "Silme iþlemi baþarýlý.";
		}
	}
	dhyaz(r);
	return r;
}

void gezin(node *r)
{
	if (r == NULL)
		cout << "Liste boþ"<<endl;
	else {
		node *yrd;
		yrd = r;
		while (yrd->next != r)
		{
			cout << yrd->data << " " << endl;
			yrd = yrd->next;
		}
		cout << yrd->data << " ";

	}
}
int main()
{
	setlocale(LC_ALL, "Turkish"); //Console 'da turkce karakter kullanimi ile daha iyi gorunum saglamak icin kullandim.
	node *root;
	root = NULL;
	root = dlistele(root); // dosyadakileri listeye aktardim ve liste uzerinde islem yapacagim.
	node *yrd;
	char m;
	string ilSil, ilEkle, aranan;
	int kontrol = true;
	do{
		char islem;
		cout << "1-) Ýller arasý gezinti \n2-)Ýl ekleme\n3-)Ýl silme\n4-)Ýl arama\n5-)Listele\n6-)Çýkýþ\n";
		cout << "Yapacaðýnýz iþlemi giriniz:";
		cin >> islem;
		while (islem<49 || islem>54)
		{
			cout << "Lütfen 1 ile 6 arasýnda bir deger giriniz:";
			cin >> islem;
		}
		switch (islem)
		{
		case 49:
			system("CLS");
			if (root == NULL){
				cout << "Liste boþ";
				system("pause");
			}
			else{
				cout << "Bulunduðunuz Ýl\n===============" << endl;
				yrd = root;
				cout << yrd->data << endl;
				m = 'i';
				while (m == 'i' || m == 'I' || m == 'g' || m == 'G') {
					cout << endl << "# Ýleri 'i' , Geri 'g' \n(Gezintiden çýkmak için herhangi bir tuþa basmanýz yeterliir.) \nGezme iþlemini giriniz: ";
					cin >> m;
					cout << endl;
					if (m == 'i' || m == 'Ý')
					{
						yrd = yrd->next;
					}
					else
					{
						yrd = yrd->prev;
					}
					system("CLS");
					cout << "Bulunduðunuz Ýl\n===============" << endl;
					cout << yrd->data << endl;
				}
			}
			system("CLS");
			yrd = root;
			break;

		case 50:
			system("CLS");
			cout << "Eklemek istediðiniz ili yazýnýz:";
			cin >> ilEkle;
			root = ekle(root, ilEkle);
			cout << endl << "Ekleme iþlemi baþarýlý." << endl;
			system("pause");
			system("CLS");
			break;
		case 51:
			system("CLS");
			cout << "Silmek istediðiniz ili yazýnýz:";
			cin >> ilSil;
			root = sil(root, ilSil);
			system("pause");
			system("CLS");
			break;



		case 52:
			system("CLS");
			cout << "Aramak istediðiniz ili yazýnýz:";
			cin >> aranan;
			root = ilArama(root, aranan);
			system("pause");
			system("CLS");
			break;

		case 53:
			system("CLS");
			cout << "Bulunan Ýller" << endl;
			cout << "=============" << endl;
			gezin(root);
			cout << endl;
			system("pause");
			system("CLS");
			break;

		case 54:
			kontrol = false;
			break;

		}

	} while (kontrol == true);


	system("pause");
	dhyaz(root); //liste uzerinde islemler bitti artik dosyam en guncel halinde.
	return 0;
}

// Code writer: Hasan BASKURT