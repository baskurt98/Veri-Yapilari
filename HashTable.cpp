#include "stdafx.h"
#include "iostream"
using namespace std;

int data[10];

int h(int x)
{
	return x % 10;
}

int kontrol(int deger)
{
	int sayac = 0;
	int indis = h(deger);
	while (data[indis] != deger && data[indis] > 0)
	{
		indis++;
		if (indis > 9)
		{
			indis = 0;
			sayac++;
		}
		if (sayac == 2)
			break;
	}

	if (sayac != 2 )
		return indis;
	else
		return -2;
}

void ekle(int k)
{
	int indis = kontrol(k);
	
	if (indis != -2)
		data[indis] = k;
	else
		cout << endl << "Bos alan yok." << endl;
		
}

void sil(int x)
{
	int indis = kontrol(x);
	if (data[indis] == x)
		data[indis] = -1;
	else
		cout << "aranan eleman bulunamadi" << endl;
}

void gezin()
{
	for (int i = 0; i < 10; i++)
		cout << data[i] << " ";
}

int main()
{
	for (int i = 0; i < 10; i++)
		data[i] = NULL;
	for (int i = 7; i < 21; i+=2)
		ekle(i + 3);
	gezin();
	system("pause");
	ekle(48);
	ekle(28);
	gezin();
	system("pause");
	sil(28);
	gezin();
	system("pause");
	ekle(64);
	ekle(4);
	gezin();
	system("pause");	
	ekle(17); // Dizi de bos alan kalmadigi icin uyari verdi ve ekleme yapmadi.
	system("pause");
	sil(28); // dizi de eleman olmayinca uyari verdi
	gezin();
	system("pause");
	return 0;
}

// Code writer: Hasan BASKURT
