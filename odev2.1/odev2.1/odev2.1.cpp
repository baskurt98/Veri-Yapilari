#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

struct node{
	int data;
	node *next;
};

void gezin(node *r)
{
	while (r != NULL)
	{
		cout << r->data << " ";
		r = r->next;
	}
}

node *ekle(node *r, int x)
{
	if (r == NULL)
	{
		r = new node;
		r->data = x;
		r->next = NULL;
	}

	else{
		node *yrd;
		yrd = r;
		while (yrd->next != NULL)
			yrd = yrd->next;

		yrd->next = new node;
		yrd->next->data = x;
		yrd->next->next = NULL;
		yrd = NULL;
		delete yrd;

	}

	return r;
}

node *basaekle(node *r, int x)
{
	if (r == NULL)
	{
		node *r;
		r = new node;
		r->data = x;
	}

	else{
		node *yrd;
		yrd = new node;
		yrd->data = x;
		yrd->next = r;
		r = yrd;
		yrd = NULL;
		delete yrd;
	}
	return r;
}

node *arayaekle(node *r, int x, int hangiara)
{
	node *yrd;
	yrd = r;
	if (r->data == hangiara)
		basaekle(r, x);

	else{
		while (yrd->next->data != hangiara)
			yrd = yrd->next;

		node *temp;
		temp = new node;
		temp->data = x;
		temp->next = yrd->next;
		yrd->next = temp;
		yrd = NULL;
		temp = NULL;
		delete yrd, temp;

	}

	return r;
}

node *sýrala(node *r, int deger)  // Basa , araya ve sona eklemek icin olusturdugum fonksiyonlari burada kullandim.
{
	if (r == NULL || r->data >= deger) // Eger root bos ise ekle,root' un datasi girilen degerden buyuk veya esit ise basa ekle calýsacak.
	{
		if (r == NULL)
			r = ekle(r, deger);

		else
			r = basaekle(r, deger);
	}

	else{

		node *yrd;
		yrd = r;

		while (yrd != NULL)
		{
			if (yrd->data >= deger) // Yardimcinin datasi girilen degerden buyuk veya esit ise araya ekle calýsacak.
			{
				r = arayaekle(r, deger, yrd->data);
				return r;
			}

			yrd = yrd->next;

			if (yrd == NULL) // Eger son elemana gelmissek ve bu surece kadar deger araya veya basa yerlesmemis ise en sona eklenicek.
			{
				r = ekle(r, deger);
				return r;
			}

		}
	}

	return r;
}


int main()
{
	node *root;
	root = NULL;
	srand(time(NULL));
	int listedegeri,deger;
	cout << "Kac elamanli bir liste istersin ?\n Gir:";
	cin >> listedegeri;

	for (int i = 0; i < listedegeri; i++) // Her adimda random deger olusturup bunu siralama fonksiyona atadik ve bu surecte neler oldugu gozlemlemek icin ekrana yazdirdik.
	{
		deger = rand() % 9 + 1;
		root = sýrala(root, deger);
		gezin(root);
		cout<<"		"<<i+1<<". Eklenen deger :"<< deger<<"		"<<endl;
		
		}
	cout << endl<<"Olusan liste"<<endl<<"------------"<<endl;
	gezin(root);
	cout << endl;
	system("pause");
	return 0;
}

//Code Writer: Hasan BASKURT