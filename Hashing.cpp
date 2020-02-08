#include "stdafx.h"
#include "iostream"
using namespace std; 

char alfabe[] = { "abcdefghijklmnopqrstuvxwyzABCDEFGHIJKLMNOPQRSTUVXWYZ0123456789" };

void hashle(char *data) {
	int idizi[5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 62; j++)
		{
			if (data[i] == alfabe[j])
				idizi[i] = j;

		}
		char encode[33];
		int indis;
		int tmp = 7;
		for (int i = 0; i < 32; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				indis = (idizi[j] * 81 + tmp) % 62;
				encode[i] = alfabe[indis];
				i++;
			}
			tmp = tmp + 7;
			i--;
		}
		encode[32] = '!';
		cout << encode;
	}
}
int main()
{
	char data[5];
	cout << "kelime:";
	cin >> data;
	hashle(data);  
	system("pause");
}

// Code writer: Hasan BAÞKURT
