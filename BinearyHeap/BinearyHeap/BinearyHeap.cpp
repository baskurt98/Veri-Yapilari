#include "stdafx.h"
#include "iostream"
using namespace std;
const int size = 21;
int *dizi;
int indis = 1;
void insert(int x){

	int cnt = indis;
	if (cnt == size - 1)
		cout << "heap dolu";
	else  {
			dizi[cnt] = x;
			while (cnt != 1 && dizi[cnt / 2] < dizi[cnt])
			{
			swap(dizi[cnt / 2], dizi[cnt]);    cnt /= 2;
			}
		}  
	indis++;
}

void dilete(){

	int i = 1;

	int x = dizi[1];   dizi[i] = dizi[indis - 1];   
	dizi[indis--] = NULL;    
	while (dizi[i] < dizi[2 * i] || dizi[i] < dizi[(2 * i) + 1] && dizi[i * 2] != NULL)  
	{
		if (dizi[2 * i] < dizi[(2 * i) + 1]) 
		{
			swap(dizi[i], dizi[(2 * i) + 1]);   
			i = (i * 2) + 1;
		} 
		else   
		{
			swap(dizi[i], dizi[2 * i]); 
			i = i * 2;
		}
	}
}

void yazdir(){


	for (int i = 1; i < indis; i++)   
		cout << dizi[i] << " ";  system("pause");

}

void main(){

	dizi = new int[size];    insert(5);  insert(3);  insert(8);  insert(7);  insert(11);  insert(16);  insert(19);  insert(9);  insert(13);  insert(2);


	yazdir();

	dilete();  yazdir();  dilete();  yazdir();  dilete();  yazdir();  dilete();  yazdir();

	dilete();  yazdir();

	dilete();  yazdir();

	dilete();  yazdir();

	dilete();  yazdir();

	dilete();  yazdir();


}

// Code writer: Hasan BASKURT