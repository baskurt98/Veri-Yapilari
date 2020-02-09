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
	if (r != NULL) // oncelikle agacta eleman olup olmadýgý kontrol edildi.
	{
		if (r->data == deger) // root aranilan deger ise sonuc bulundu
		{
			cout << "Aranilan deger mevcut " << endl << endl;
			system("pause");
			return r;
		}
		else // aranilan eleman root degil ise...
		{
			if (r->data < deger) // Aranilan eleman roottan buyuk ise sag dallarda arama yapildi.
				arama(r->right, deger);
			else
				arama(r->left, deger); // Aranilan eleman roottan kucuk ise sol dallarda arama yapildi.
		}
	}
		return NULL; // Agacta eleman yok ise hic bir islem yapilmadi.
}
tree *ekle(tree *r, int deger) 
{
	if (r == NULL) // Eger agac bos ise yeni agag olusturuldu.
	{
		r = new tree();
		r->data = deger;
		r->left = NULL;
		r->right = NULL;
	}

	else{ // Agac dolu ise girilen deger roottan buyuk veya kucuk olma durumuna gore eklemek icin kontrol ettik 
		if (r->data <= deger) //Roottan buyuk veya esit ise sag dala yonlendirip recursive fonksiyon kullanarak ekleme yaptik.
			r->right = ekle(r->right, deger);
		else // Roottan kucuk ise sol dala yonlendirip recursive fonksiyon kullanarak ekleme yaptik.
			r->left = ekle(r->left, deger);
	}
	return r;
}

tree *inorder(tree *r) // Root ortada LNR ( Left - Node - Right ) kucukten buyuge siraladi. Buyukten kucuge siralamak isterseniz RNL olarak kullaniniz.
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

tree *preorder(tree *r) // Root basta NLR ( Node - Left - Right )
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

tree *postorder(tree *r) // Root sonda LRN ( Left - Right - Node )
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

tree *max(tree *r) // Olusturdugumuz agacin en sagindaki elemani bulduk. En sagdaki eleman max degere esit.
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

tree *min(tree *r) // Olusturdugumuz agacin en solundaki elemani bulduk. En solundaki eleman min degere esit.
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

// Code writer : Hasan BASKURT
