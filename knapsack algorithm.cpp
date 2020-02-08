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
	if (elemansayisi == 0 || kapasite == 0) // canta bos veya esya kalmamýþ ise deger döndürmeyecek
		return 0;
	if (kilo[elemansayisi - 1] > kapasite) // eger esyanýn kilosu kalan kapasiteden buyuk ise diger esyayý kontrol edicek
		return knapSack(kapasite, kilo, deger, elemansayisi - 1);
	else 
		return max(deger[elemansayisi - 1] + knapSack(kapasite - kilo[elemansayisi - 1], kilo, deger, elemansayisi - 1),
		knapSack(kapasite, kilo, deger, elemansayisi - 1)); // Bulduðu  en verimli degeri max fonksiyonundan çekip o degeri döndürücek
}
int main()
{
	int deger[] = { 25, 50, 10, 70, 20, 40, 100 }; // esyalarýn degeri tanýmlandý 
	int kilo[] = { 3,8,4,6,7,5,9 };// eþyalarýn kilosu degerlendi
	int kapasite = 25; // çanta degeri
	int ElemanSayisi = sizeof(deger) / sizeof(deger[0]); // dizinin boyutu ve dizinin bir elemanýnýn boyutunu alýp dizide kaç eleman olduðunu öðrendik
	cout<<" Kg   deger"<<endl;
	cout<<" --   -----"<<endl;
	for(int i=0; i<7; i++)
	cout<<" "<<kilo[i]<<"     "<<deger[i]<<endl;
	cout <<"\nEn degerli doldurma: "<< knapSack(kapasite, kilo, deger, ElemanSayisi)<<endl;
	system("pause");
	return 0;
}

// Code writer : Hasan BAÞKURT

