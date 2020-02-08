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

node *s�rala(node *r, int deger)  // Ba�a , araya ve sona eklemek i�in olu�turdu�um fonksiyonlar� burada kulland�m.
{
	if (r == NULL || r->data >= deger) // E�er root bo� ise ekle,root' un datas� girilen degerden b�y�k veya e�it ise ba�a ekle �al��acak.
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
			if (yrd->data >= deger) // Yard�mc�n� datas� girilen degerden b�y�k veya e�it ise araya ekle �al��acak.
			{
				r = arayaekle(r, deger, yrd->data);
				return r;
			}

			yrd = yrd->next;

			if (yrd == NULL) // E�er son eleman gelmi�sek ve bu s�rece kadar deger araya veya ba�a yerle�memi� ise en sona eklenicek.
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

	for (int i = 0; i < listedegeri; i++) // Her ad�mda random de�er olu�turup bunu s�ralama fonksiyona atad�k ve bu s�re�te neler oldu�u g�zlemlemek i�in ekrana yazd�rd�k.
	{
		deger = rand() % 9 + 1;
		root = s�rala(root, deger);
		gezin(root);
		cout<<"		"<<i+1<<". Eklenen deger :"<< deger<<"		"<<endl;
		
		}
	cout << endl<<"Olusan liste"<<endl<<"------------"<<endl;
	gezin(root);
	cout << endl;
	system("pause");
	return 0;
}

//Code Writer: Hasan BA�KURT