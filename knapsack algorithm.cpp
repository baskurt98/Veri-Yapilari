#include "stdafx.h"
#include "iostream"
using namespace std;

int max(int a, int b) // max degeri bulduk!
{
	if (a > b)
		return a;
	else
		return b;
}
int knapSack(int kapasite, int kilo[], int deger[], int elemansayisi) // bu fonksiyonda en verimli halini bulduk
{
	if (elemansayisi == 0 || kapasite == 0) // canta bos veya esya kalmam�� ise deger d�nd�rmeyecek
		return 0;
	if (kilo[elemansayisi - 1] > kapasite) // eger esyan�n kilosu kalan kapasiteden buyuk ise diger esyay� kontrol edicek
		return knapSack(kapasite, kilo, deger, elemansayisi - 1);
	else 
		return max(deger[elemansayisi - 1] + knapSack(kapasite - kilo[elemansayisi - 1], kilo, deger, elemansayisi - 1),
		knapSack(kapasite, kilo, deger, elemansayisi - 1)); // Buldu�u  en verimli degeri max fonksiyonundan �ekip o degeri d�nd�r�cek
}
int main()
{
	int deger[] = { 25, 50, 10, 70, 20, 40, 100 }; // esyalar�n degeri tan�mland� 
	int kilo[] = { 3,8,4,6,7,5,9 };// e�yalar�n kilosu degerlendi
	int kapasite = 25; // �anta degeri
	int ElemanSayisi = sizeof(deger) / sizeof(deger[0]); // dizinin boyutu ve dizinin bir eleman�n�n boyutunu al�p dizide ka� eleman oldu�unu ��rendik
	cout<<" Kg   deger"<<endl;
	cout<<" --   -----"<<endl;
	for(int i=0; i<7; i++)
	cout<<" "<<kilo[i]<<"     "<<deger[i]<<endl;
	cout <<"\nEn degerli doldurma: "<< knapSack(kapasite, kilo, deger, ElemanSayisi)<<endl;
	system("pause");
	return 0;
}

// Code writer : Hasan BA�KURT

