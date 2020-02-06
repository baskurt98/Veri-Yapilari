#include "stdafx.h"
#include "iostream"
using namespace std;
char anahtar[6][6];  //alfabe global tanýmlandý
char sifre[60]; //girilen kelime bu diziye atýldý
void alfabe() // matris olarak kullanacaðýmýz alfabe oluþturuldu
{
	int k = 65;
	for (int i = 1; i < 6; i++)
	{
		for (int j = 1; j < 6; j++)
		{
			if (k != 74){ // 'j' ile 'i' 5*5 lik matris için ayný satýr ve sütuna atandý 
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
	// harfleri ascii tablosunu kullanarak çektim.
}

void kodla(char kelime[20], int size) // gelen kelimeyi koda çevirdik. kelimeyi ve kelimenin boyutunu parametre olarak aldýk.
{
	int d = 0;
	for (int x = 0; x < size; x++)
	{
		if (kelime[x]>90)
			kelime[x] -= 32; // eger girilen karakter kücük harf ise onu ascii tablodaki degerinden 32 eksilterek buyuk harf yaptýk. Matris alfabede kullanmak icin.
		if (kelime[x] == 74)
			kelime[x] = 73;
		for (int i = 1; i < 6; i++)
		{
			for (int j = 1; j < 6; j++)

			{

				if (anahtar[i][j] == kelime[x]) // Tablodaki degeri bulduk
				{ //sifre adýnda olusturdugum char dizisine olusturulan kodu atadýk.
					sifre[d] = i + 48; //satýr degeri
					sifre[d + 1] = anahtar[j][i]; // satýr ve sutun degerlerinin yerini degiþtirip yeni deger olusturduk.
					sifre[d + 2] = j + 48; // sutun degeri
					d += 3;
					//son olarak bunlarý birlestirip kodlarý olusturduk
				}
			}
		}
	}
	cout << endl;
}

void desifre()
{
	for (int x = 0; x < strlen(sifre); x++) // sifrenin boyutu kadar deger döndürdük
	{

		for (int i = 1; i < 6; i++)
		{
			for (int j = 1; j < 6; j++)
			{

				if (anahtar[i][j] == sifre[x])
				{
					if (anahtar[j][i] == 73) //i ve j ayný satýrve sutunda olduðu icin ekrana ikisinide yazýcak
						cout << " "<<anahtar[j][i] << "/j ";
					else
					cout << " "<<anahtar[j][i]<<" "; //rakamlar tabloda olmadýðý icin sadece kodtaki harfleri buldu

				}// bulunan harflerin satýr ve sütunun yer degistip matris alfabeki karsiliðini bulup kodu cozduk.
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