//Alper
//Yoruk
//200757023
//Bilgisayar M�hendisli�i (��)
//BIM-104-50-50
//2021 Bahar D�nemi
//Proje 2
//G�l�ah T�M�KL� �ZYER

#include "Kullanici.h"
#include "Uye.h"
#include "Kitap.h"
#include <iostream>
#include <iomanip>


using namespace std;


void Uye::UyeKitapAra(Kitap ktpTmp[100]) //Kitap aramas�n�n yap�ld��� fonksiyon ktpTmp'yi parametre al�r
{
	string uyeKtpIsOnHold, newKtpName, newKtpAuthor; //Kitab�n al�n�p al�nmad���n�, ad�n� ve yazar�n�n bilgisini tutan de�i�ken
	cout << "Eger Kitap Adini veya Yazarini Girmek Istemiyorsaniz \"*\"\'i tuslayiniz" << endl;
	cout << "Kitap Adi Girin: ";
	cin >> newKtpName; //Kitap ad� bilgisi al
	cout << "Yazar Adi Giriniz: ";
	cin >> newKtpAuthor; //Yazar bilgisi al
	bool isKitapBulundu = false;

	if (newKtpAuthor == "*") //E�er �ye yazar girmek istemezse �al��acak if blo�u
	{

		for (int i = 0; i < 100; i++)
		{
			if (ktpTmp[i].GetIsOnHold()) //i. indisdeki kitab�n durumuna bakar
			{
				uyeKtpIsOnHold = "Hold"; //E�er i. indisdeki kitap al�nm��sa "Hold" yazd�r
			}

			else
			{
				uyeKtpIsOnHold = "Unhold"; //E�er i. indisteki kitap al�nmam��sa "Unhold" yazd�r
			}

			if (ktpTmp[i].GetKitapAdi() == newKtpName) //E�er newKtpName ile GetKitapAdi fonksiyonunun i. indisinin kitap adlar� uyu�uyorsa �al��acak if blo�u
			{
				if (isKitapBulundu == false)
				{
					cout << "Aradiginiz kitap/kitaplar bulundu. Kitap bilgileri: " << endl;
					isKitapBulundu = true;
				}
				cout << ktpTmp[i].GetKitapID() << setw(10) << ktpTmp[i].GetYazar() << setw(15) << ktpTmp[i].GetKitapAdi() << setw(15) << uyeKtpIsOnHold << endl;
			}
		}
	}

	else if (newKtpName == "*") //E�er �ye kitap ad� girmek istemezse �al��acak if blo�u
	{
		for (int i = 0; i < 100; i++)
		{
			if (ktpTmp[i].GetIsOnHold()) //i. indisdeki kitab�n durumuna bakar
			{
				uyeKtpIsOnHold = "Hold"; //E�er i. indisdeki kitap al�nm��sa "Hold" yazd�r
			}
			else
			{
				uyeKtpIsOnHold = "Unhold"; //E�er i. indisteki kitap al�nmam��sa "Unhold" yazd�r
			}
			if (ktpTmp[i].GetYazar() == newKtpAuthor) //E�er newKtpAuthor ile GetYazar fonksiyonunun i. indisinin yazar uyu�uyorsa �al��acak if blo�u
			{
				if (isKitapBulundu == false)
				{
					cout << "Aradiginiz kitap/kitaplar bulundu. Kitap bilgileri: " << endl;
					isKitapBulundu = true;
				}
				cout << ktpTmp[i].GetKitapID() << setw(10) << ktpTmp[i].GetYazar() << setw(15) << ktpTmp[i].GetKitapAdi() << setw(15) << uyeKtpIsOnHold << endl;
			}
		}
	}

	else
	{
		for (int i = 0; i < 100; i++)
		{
			if (ktpTmp[i].GetIsOnHold()) //i. indisdeki kitab�n durumuna bakar
			{
				uyeKtpIsOnHold = "Hold"; //E�er i. indisdeki kitap al�nm��sa "Hold" yazd�r
			}
			else
			{
				uyeKtpIsOnHold = "Unhold"; //E�er i. indisteki kitap al�nmam��sa "Unhold" yazd�r
			}

			if (ktpTmp[i].GetKitapAdi() == newKtpName) //E�er newKtpName ile GetKitapAdi fonksiyonunun i. indisinin kitap adlar� uyu�uyorsa �al��acak if blo�u
			{
				if (ktpTmp[i].GetYazar() == newKtpAuthor) //E�er newKtpAuthor ile GetYazar fonksiyonunun i. indisinin yazar uyu�uyorsa �al��acak if blo�u
				{
					if (isKitapBulundu == false)
					{
						cout << "Aradiginiz kitap/kitaplar bulundu. Kitap bilgileri: " << endl;
						isKitapBulundu = true;
					}
					cout << ktpTmp[i].GetKitapID() << setw(10) << ktpTmp[i].GetYazar() << setw(15) << ktpTmp[i].GetKitapAdi() << setw(15) << uyeKtpIsOnHold << endl;
				}

			}
		}
	}
}


void Uye::UyeKitapOduncAl(int userId, Uye tmpUye[100], Kitap ktpTmp[100]) //Kitap �d�n� al�nmas�n�n yap�ld��� fonksiyon userId, tmpUye ve ktpTmp'yi parametre al�r
{

	string uyeKtpIsOnHold; //Kitab�n al�n�p al�nmad��� bilgisini tutan de�i�ken
	int newKtpID;  //Kitab�n id bilgisini tutan de�i�ken

	cout << "Kitap ID: ";
	cin >> newKtpID; //Kitap id'si bilgisi al



	if (tmpUye[userId].GetUyeTipi() == "Ogrenci") //�ye tipi "Ogrenci" tipindeyse �al��acak if blo�u
	{
		cout << tmpUye[userId].GetUyeTipi() << endl;
		cout << "Ogrenci uye kitap almaya calisiyor" << endl;
		int tempAlinanKitapSayisi = tmpUye[userId].GetAlinanKitapSayisi(); //Hangi �yenin ne kadar kitaba sahip oldu�u bilgisini tutan de�i�ken

		if (ktpTmp[newKtpID].GetAlanKisiID() != 99)
		{
			cout << "Kitap baska bir uye tarafindan alinmis" << endl;
		}

		else
		{
			if (tempAlinanKitapSayisi < 5)
			{
				ktpTmp[newKtpID].SetAlanKisiID(userId); //userId parametre al�narak hangi �yenin kitap ald��� bilgisine eri�ilir
				tempAlinanKitapSayisi++; //�yenin ald��� kitaplar�n say�s� artt�r�l�r
				tmpUye[userId].SetAlinanKitapSayisi(tempAlinanKitapSayisi); //�d�n� al�nmak istenilen kitap SetAlinanKitapSayisi fonksiyonu tempAlinanKitapSayisi kullan�larak �yenin ka� kitab� oldu�u bilgisine eri�ilir
			}
			else
			{
				cout << "Daha fazla kitap alamazsiniz!" << endl; //Maksimum kitap say�s�na geldi�inde ekrana yaz�l�r
			}

		}
	}

	else if (tmpUye[userId].GetUyeTipi() == "Personel") //�ye tipi "Personel" tipindeyse �al��acak if blo�u
	{
		cout << "Personel uye kitap almaya calisiyor" << endl;
		if (ktpTmp[newKtpID].GetAlanKisiID() != 99)
		{
			cout << "Kitap baska bir uye tarafindan alinmis" << endl;
		}

		else
		{
			int tempAlinanKitapSayisi = tmpUye[userId].GetAlinanKitapSayisi(); //Hangi �yenin ne kadar kitaba sahip oldu�u bilgisini tutan de�i�ken
			if (tempAlinanKitapSayisi < 3)
			{
				ktpTmp[newKtpID].SetAlanKisiID(userId); //userId parametre al�narak hangi �yenin kitap ald��� bilgisine eri�ilir
				tempAlinanKitapSayisi++; //�yenin ald��� kitaplar�n say�s� artt�r�l�r
				tmpUye[userId].SetAlinanKitapSayisi(tempAlinanKitapSayisi); //�d�n� al�nmak istenilen kitap SetAlinanKitapSayisi fonksiyonu tempAlinanKitapSayisi kullan�larak �yenin ka� kitab� oldu�u bilgisine eri�ilir
				cout << tempAlinanKitapSayisi << endl;
			}
			else
			{
				cout << "Daha fazla kitap alamazsiniz!" << endl; //Maksimum kitap say�s�na geldi�inde ekrana yaz�l�r
			}

		}
	}

	else if (tmpUye[userId].GetUyeTipi() == "OgretimElemani") //�ye tipi "OgretimElemani" tipindeyse �al��acak if blo�u
	{
		cout << "OgrenciElemani uye kitap almaya calisiyor" << endl;
		if (ktpTmp[newKtpID].GetAlanKisiID() != 99)
		{
			cout << "Kitap baska bir uye tarafindan alinmis" << endl;
		}

		else
		{
			int tempAlinanKitapSayisi = tmpUye[userId].GetAlinanKitapSayisi(); //Hangi �yenin ne kadar kitaba sahip oldu�u bilgisini tutan de�i�ken
			if (tempAlinanKitapSayisi < 10)
			{
				ktpTmp[newKtpID].SetAlanKisiID(userId); //userId parametre al�narak hangi �yenin kitap ald��� bilgisine eri�ilir
				tempAlinanKitapSayisi++; //�yenin ald��� kitaplar�n say�s� artt�r�l�r
				tmpUye[userId].SetAlinanKitapSayisi(tempAlinanKitapSayisi); //�d�n� al�nmak istenilen kitap SetAlinanKitapSayisi fonksiyonu tempAlinanKitapSayisi kullan�larak �yenin ka� kitab� oldu�u bilgisine eri�ilir
			}

			else
			{
				cout << "Daha fazla kitap alamazsiniz!" << endl; //Maksimum kitap say�s�na geldi�inde ekrana yaz�l�r
			}
		}
	}
}

void Uye::UyeKitapIadeEt(int userID, Uye tmpUye[100], Kitap ktpTmp[100]) //Kitap siliminin yap�ld��� fonksiyon userId, tmpUye ve ktpTmp'yi parametre al�r
{
	int tempKitapID, tempAlinanKitapSayisi; //Kitab�n id'sini ve �yenin ald��� kitap say�s� bilgisini tutan de�i�ken

	cout << "Iade etmek istediginiz kitabin ID'sini giriniz: ";
	cin >> tempKitapID; //Kitab�n id bilgisini al
	if (ktpTmp[tempKitapID].GetAlanKisiID() == userID) {
		cout << "Kitap iade edilmistir." << endl;

		tempAlinanKitapSayisi = tmpUye[userID].GetAlinanKitapSayisi(); //�ade edilmek istenilen kitap userID'ye ba�l� olarak kullan�lan GetAlinanKitapSayisi fonksiyonunun de�eri tempAlinanKitapSayisina atan�r
		tempAlinanKitapSayisi--; //Kitap idade edildikten sonra tempAlinanKitapSayisi azalt�l�r
		tmpUye[userID].SetAlinanKitapSayisi(tempAlinanKitapSayisi);

		ktpTmp[tempKitapID].SetAlanKisiID(99);
	}
	else {
		cout << "Baska birine ait bir kitabi iade edemezsiniz." << endl;
	}
}

void Uye::UyeKitaplariListele(int uyeKitapIndex, Kitap ktpTmp[100]) //Kitaplar�n listelenmesini sa�layan fonksiyon uyeKitapIndex ve ktpTmp'yi parametre al�r
{
	string uyeKtpIsOnHold;
	for (int i = 0; i < uyeKitapIndex; i++)
	{
		if (ktpTmp[i].GetAlanKisiID() != 99)
		{
			uyeKtpIsOnHold = "Hold"; //E�er i. indisdeki kitap al�nm��sa "Hold" yazd�r
		}
		else
		{
			uyeKtpIsOnHold = "Unhold"; //E�er i. indisteki kitap al�nmam��sa "Unhold" yazd�r
		}
		cout << ktpTmp[i].GetKitapID() << setw(10) << ktpTmp[i].GetKitapAdi() << setw(15) << ktpTmp[i].GetYazar() << setw(15) << uyeKtpIsOnHold << endl;
	}
}

void Uye::UyeUyelikIslemleri(int uyeID, Uye uyeUye[100]) //�yeerin �ifrelerini de�i�tirebilmesini sa�layan fonksiyon uyeID ve uyeUye'yi parametre al�r
{
	string tmpPassword; //�yenin �ifre bilgisini tutan de�i�ken
	cout << "Yeni Sifrenizi Giriniz: ";
	cin >> tmpPassword; //�yenin �ifre bilgisini al
	uyeUye[uyeID].SetSifre(tmpPassword); //SetSifre fonksiyonunda tmpPassword kullanarak uyeID'ye ba�l� �ifre de�i�imi ger�ekle�tirir
}



