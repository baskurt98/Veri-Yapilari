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
	if (elemansayisi == 0 || kapasite == 0) // canta bos veya esya kalmamis ise deger dondurmeyecek
		return 0;
	if (kilo[elemansayisi - 1] > kapasite) // eger esyanin kilosu kalan kapasiteden buyuk ise diger esyayý kontrol edicek
		return knapSack(kapasite, kilo, deger, elemansayisi - 1);
	else 
		return max(deger[elemansayisi - 1] + knapSack(kapasite - kilo[elemansayisi - 1], kilo, deger, elemansayisi - 1),
		knapSack(kapasite, kilo, deger, elemansayisi - 1)); // Buldugu  en verimli degeri max fonksiyonundan cekip o degeri dondurecek
}
int main()
{
	int deger[] = { 25, 50, 10, 70, 20, 40, 100 }; // esyalarin degeri tanimlandi.
	int kilo[] = { 3,8,4,6,7,5,9 };// esyalarin kilosu degerlendi
	int kapasite = 25; // canta degeri
	int ElemanSayisi = sizeof(deger) / sizeof(deger[0]); // dizinin boyutu ve dizinin bir elemaninin boyutunu alip dizide kac eleman oldugunu ögrendik
	cout<<" Kg   deger"<<endl;
	cout<<" --   -----"<<endl;
	for(int i=0; i<7; i++)
	cout<<" "<<kilo[i]<<"     "<<deger[i]<<endl;
	cout <<"\nEn degerli doldurma: "<< knapSack(kapasite, kilo, deger, ElemanSayisi)<<endl;
	system("pause");
	return 0;
}

// Code writer : Hasan BASKURT

