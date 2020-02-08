#include "stdafx.h"
#include <iostream>
using namespace std;
struct tree{
	int data;
	tree *left;
	tree *right;
};


tree *arama(tree *r, int deger)
{
	if (r != NULL) // �ncelikle a�a�ta eleman olup olmad��� kontrol edildi.
	{
		if (r->data == deger) // k�k aran�lan deger ise sonuc bulundu
		{
			cout << "Aranilan deger mevcut " << endl << endl;
			system("pause");
			return r;
		}
		else // aran�lan eleman k�k de�il ise...
		{
			if (r->data < deger) // Aran�lan eleman k�kten b�y�k ise sa� dallarda arama yap�ld�.
				arama(r->right, deger);
			else
				arama(r->left, deger); // Aran�lan eleman k�kten k���k ise sol dallarda arama yap�ld�.
		}
	}
		return NULL; // A�a�ta eleman yok ise hi� bir i�lem yap�lmad�.
}
tree *ekle(tree *r, int deger) 
{
	if (r == NULL) // E�er a�a� bo� ise yeni a�a� olu�turuldu.
	{
		r = new tree();
		r->data = deger;
		r->left = NULL;
		r->right = NULL;
	}

	else{ // A�a� dolu ise girilen deger k�kten b�y�k veya k���k olma durumuna g�re eklemek i�in kontrol ettik 
		if (r->data <= deger) //k�kten b�y�k veya e�it ise sa� dala y�nlendirip recursive fonksiyon kullanarak ekleme yapt�k.
			r->right = ekle(r->right, deger);
		else // k�kten k���k ise sol dala y�nlendirip recursive fonksiyon kullanarak ekleme yapt�k.
			r->left = ekle(r->left, deger);
	}
	return r;
}

tree *inorder(tree *r) // K�k ortada LNR ( Left - Node - Right ) k���kten b�y��e s�ralad�. B�y�kten k����e s�ralamak isterseniz RNL olarak kullan�n�z.
{
	
	if (r != NULL)
	{
		inorder(r->left);
		cout << r->data<<" ";
		inorder(r->right);
		return r;
	}
	else
		return NULL;
}

tree *preorder(tree *r) // K�k ba�ta NLR ( Node - Left - Right )
{
	if (r != NULL)
	{
		cout << r->data<<" ";
		preorder(r->left);
		preorder(r->right);
		return r;
	}
	else
		return NULL;
}

tree *postorder(tree *r) // K�k sonda LRN ( Left - Right - Node )
{
	if (r != NULL)
	{
		postorder(r->left);
		postorder(r->right);
		cout << r->data<<" ";
		return r;
	}
	else
		return NULL;
}

tree *max(tree *r) // Olu�turdu�umuz a�ac�n en sa��ndaki eleman� bulduk. En sa�daki eleman max de�ere e�it.
{
	if (r != NULL)
	{
		tree *yrd;
		yrd = r;
		while (yrd->right != NULL)
			yrd = yrd->right;

		cout << "Max deger: " << yrd->data<<endl;
		return yrd;
	}

	else
	{
		cout << "Agac bos! " << endl;
		system("pause");
		return NULL;
	}
}

tree *min(tree *r) // Olu�turdu�umuz a�ac�n en solundaki eleman� bulduk. En solundaki eleman min de�ere e�it.
{
	if (r != NULL)
	{
		tree *yrd;
		yrd = r;
		while (yrd->left != NULL)
			yrd = yrd->left;
		cout << "Min deger: " << yrd->data << endl;
		return yrd;
	}

	else
	{
		cout << "Agac bos!" << endl;
		system("pause");
		return NULL;
	}
}

tree *sil(tree *r, int silinecek)
{
	if (r == NULL)
		return NULL;
	if (r->data== silinecek)
	{
		if (r->left == NULL&&r->right == NULL) 
			return NULL;

		if (r->left == NULL)
		{
			r->data = min(r->right)->data;
			r->right = sil(r->right, r->data);
			return r;
		}
		if (r->right == NULL)
		{
			r->data = max(r->left)->data;
			r->left = sil(r->left, r->data);
			return r;
		}
	}
	if (r->data < silinecek || r->data == silinecek
	 )
	{
		r->right = sil(r->right, silinecek);
		return r;
	}
	r->left = sil(r->left, silinecek);
	return r;
}

int nodeSay(tree *r)
{
	if (r != NULL)
		return nodeSay(r->left) + 1 + nodeSay(r->right);
	else
	{
		return NULL;
	}
		
}
int main()
{
	tree *root;
	root = new tree();
	root = NULL;
	root = ekle(root, 5);
	root = ekle(root, 1);
	root = ekle(root, -1);
	root = ekle(root, -2);
	root = ekle(root, -3);
	root = ekle(root, 1);
	root = ekle(root, 4);
	root = ekle(root, 7);
	root = ekle(root, 6);
	root = ekle(root, 45);
	root = ekle(root, -8);
	root = ekle(root, 25);

	int deger,silinecek;
	cout << "aranilacak deger gir:";
	cin >> deger;
	arama(root, deger);
	cout<<"Agactaki elemanlar: ";
	inorder(root);
	cout << endl;
	cout<<"Silinecek degeri giriniz:";
	cin>>silinecek;
	root = sil(root, silinecek);
	system("pause");
	cout << "\n# INORDER #" << endl;
	cout << "-----------" << endl;
	inorder(root);
	cout << endl;	
	system("pause");
	cout << endl;
	cout << "# PREORDER #" << endl;
	cout << "------------" << endl;
	preorder(root);
	cout << endl;
	system("pause");
	cout << endl;
	cout << "# POSTORDER #" << endl;
	cout << "-------------" << endl;
	postorder(root);
	cout << endl;
	system("pause");
	cout << endl;
	max(root);
	system("pause");
	cout << endl;
	min(root);
	system("pause");
	cout << endl;
	cout<<"Node sayisi: "<<nodeSay(root)<<endl;
	system("pause");
}

// Code writer : Hasan BA�KURT
