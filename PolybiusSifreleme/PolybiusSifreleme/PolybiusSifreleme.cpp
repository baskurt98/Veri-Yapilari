#include "stdafx.h"
#include "iostream"
using namespace std;
char anahtar[6][6];  //alfabe global tan�mland�
char sifre[60]; //girilen kelime bu diziye at�ld�
void alfabe() // matris olarak kullanaca��m�z alfabe olu�turuldu
{
	int k = 65;
	for (int i = 1; i < 6; i++)
	{
		for (int j = 1; j < 6; j++)
		{
			if (k != 74){ // 'j' ile 'i' 5*5 lik matris i�in ayn� sat�r ve s�tuna atand� 
				anahtar[i][j] = k;
				if (k == 73)
					cout << anahtar[i][j] << "/J" << "  ";
				else
					cout << " " << anahtar[i][j] << "  ";
			}

			else
			{
				k += 1;
				anahtar[i][j] = k;
				cout << anahtar[i][j] << " ";
			}
			k++;
		}
		cout << endl << endl;
	}
	// harfleri ascii tablosunu kullanarak �ektim.
}

void kodla(char kelime[20], int size) // gelen kelimeyi koda �evirdik. kelimeyi ve kelimenin boyutunu parametre olarak ald�k.
{
	int d = 0;
	for (int x = 0; x < size; x++)
	{
		if (kelime[x]>90)
			kelime[x] -= 32; // eger girilen karakter k�c�k harf ise onu ascii tablodaki degerinden 32 eksilterek buyuk harf yapt�k. Matris alfabede kullanmak icin.
		if (kelime[x] == 74)
			kelime[x] = 73;
		for (int i = 1; i < 6; i++)
		{
			for (int j = 1; j < 6; j++)

			{

				if (anahtar[i][j] == kelime[x]) // Tablodaki degeri bulduk
				{ //sifre ad�nda olusturdugum char dizisine olusturulan kodu atad�k.
					sifre[d] = i + 48; //sat�r degeri
					sifre[d + 1] = anahtar[j][i]; // sat�r ve sutun degerlerinin yerini degi�tirip yeni deger olusturduk.
					sifre[d + 2] = j + 48; // sutun degeri
					d += 3;
					//son olarak bunlar� birlestirip kodlar� olusturduk
				}
			}
		}
	}
	cout << endl;
}

void desifre()
{
	for (int x = 0; x < strlen(sifre); x++) // sifrenin boyutu kadar deger d�nd�rd�k
	{

		for (int i = 1; i < 6; i++)
		{
			for (int j = 1; j < 6; j++)
			{

				if (anahtar[i][j] == sifre[x])
				{
					if (anahtar[j][i] == 73) //i ve j ayn� sat�rve sutunda oldu�u icin ekrana ikisinide yaz�cak
						cout << " "<<anahtar[j][i] << "/j ";
					else
					cout << " "<<anahtar[j][i]<<" "; //rakamlar tabloda olmad��� icin sadece kodtaki harfleri buldu

				}// bulunan harflerin sat�r ve s�tunun yer degistip matris alfabeki karsili�ini bulup kodu cozduk.
			}
		}
	}
}
int main()
{
	alfabe(); // matris alfabe olusturuldu.
	int size;
	char kelime[20];
	cout << endl << "kelime giriniz:";
	cin >> kelime;
	size = strlen(kelime);
	kodla(kelime, size);
	cout << "kod: " << sifre << endl << endl;
	cout << "Desifre: "; 
	desifre(); // kod cozuldu
	cout << endl << endl;
	system("pause");



}