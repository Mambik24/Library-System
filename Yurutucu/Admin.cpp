//Alper
//Yoruk
//200757023
//Bilgisayar M�hendisli�i (��)
//BIM-104-50-50
//2021 Bahar D�nemi
//Proje 2
//G�l�ah T�M�KL� �ZYER

#include "Admin.h"
#include "Kitap.h"
#include "Kullanici.h"
#include "Uye.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


Uye uye;
Kitap newKitap;
int adminKitapIndex; //
int adminUyeIndex;

Kitap Admin::AdminKitapEkle(int globalKtpIndex) //Kitap eklemeyi sa�layan fonksiyon globalKitapIndex'ini parametre al�r
{

	string ktpName, ktpAuthor; //Kitab�n ad� ve yazar�n�n bilgisini tutan de�i�kenler
	cout << "Kitap adi: ";
	cin >> ktpName; //Kitap ad� bilgisi al
	cout << "Yazar adi: ";
	cin >> ktpAuthor; //Yazar bilgisi al
	cout << "Kitap Eklendi";
	cout << endl;


	newKitap.SetKitapAdi(ktpName); //ktpName de�i�kenine girilen kitap ad� atan�r
	newKitap.SetYazar(ktpAuthor); //ktpAuthor de�i�kenine girilen yazar atan�r
	newKitap.SetIsOnHold(false); //Kitab�n unhold durumda oldu�u bilgisi atan�r
	newKitap.SetKitapID(globalKtpIndex); //globalKtpIndex parametresi kullan�larak kitap id'si atan�r
	newKitap.SetAlanKisiID(99); //Kitab� k�t�phaneye g�nderir

	return newKitap; //Eklenen kitab� return ile geri d�nd�r�r
}

Kitap* Admin::AdminKitapSil(int globalKtpIndex, Kitap editKtp[100]) //Kitap silinmesini sa�layan fonksiyon globalKitapIndex ve editKtp'yi parametre al�r
{
	int adminKitapIndex; //Silinmek istenen kitab�n id'sini tutan de�i�ken
	cout << "Silmek istediginiz kitabin ID'sini giriniz: ";
	cin >> adminKitapIndex; //Silinmek istenen kitab�n bilgisini alan de�i�ken
	for (int i = adminKitapIndex; i <= globalKtpIndex; i++) //Girilen adminKitapIndex de�erinden sonras� i�in �al��an for d�ng�s�
	{
		editKtp[i].SetKitapAdi(editKtp[i + 1].GetKitapAdi()); //i. indisin kitap ad� silinir ve i yerine (i+1). de�erin kitap ad� atan�r
		editKtp[i].SetKitapID(editKtp[i + 1].GetKitapID()); //i. indisin kitap id'si silinir ve i yerine (i+1). de�erin kitap id'si atan�r
		editKtp[i].SetYazar(editKtp[i + 1].GetYazar()); //i. indisin yazar� silinir ve i yerine (i+1). de�erin yazar� atan�r
		editKtp[i].SetIsOnHold(editKtp[i + 1].GetIsOnHold()); //i. indisin kitab�n unhold durumu silinir ve i yerine (i+1). de�erin kitab�n unhold durumu atan�r
		editKtp[i].SetAlanKisiID(editKtp[i + 1].GetAlanKisiID());
	}
	cout << adminKitapIndex << " ID numarali kitap silindi. " << endl;
	return editKtp; //Silinen kitap return ile geri d�nd�r�l�r
}


void Admin::AdminKitaplariListele(int globalKtpIndex, Kitap ktpTmp[]) //Kitaplar�n listelenmesini sa�layan fonksiyon globalKitapIndex ve ktpTmp'yi parametre al�r
{
	string adminKtpIsOnHold; //Kitab�n al�n�p al�nmad��� bilgisini tutan de�i�ken
	cout << "ID" << setw(10) << "Kitap Adi" << setw(15) << "Yazar" << setw(15) << "Statu" << endl;
	for (int i = 0; i < globalKtpIndex; i++)
	{
		if (ktpTmp[i].GetIsOnHold()) //i. indisdeki kitab�n durumuna bakar
		{
			adminKtpIsOnHold = "Hold"; //E�er i. indisdeki kitap al�nm��sa "Hold" yazd�r
		}

		else
		{
			adminKtpIsOnHold = "Unhold"; //E�er i. indisteki kitap al�nmam��sa "Unhold" yazd�r
		}
		cout << i << setw(10) << ktpTmp[i].GetKitapAdi() << setw(15) << ktpTmp[i].GetYazar() << setw(15) << adminKtpIsOnHold << endl; //Ekrana kitap bilgilerini yazd�r

	}
}

Uye Admin::AdminUyeEkle(int globalUyeIndex, Uye uy[100]) //�ye eklenmesini sa�layan fonksiyon globalUyeIndex ve uy'u parametre al�r
{
	Uye uye;
	bool tempHesapAdiKontrol = true; //Hesap ad�n�n daha �nce var olup olmad���n� kontrol eden bool fonksiyonu
	string uyeName, uyeAccountName, uyeMemberType, uyePassword; //�yenin ad�n�, kullan�c� ad�n�, �ye tipini ve �ifresini tutan de�i�kenler
	int uyeID; //�yenin id bilgisii tutan de�i�ken
	cout << "Lutfen adinizi bosluk olmadan giriniz!" << endl;
	cout << "ad-soyad: ";
	cin >> uyeName; //�yenin ad�n�n bilgisi al�n�r
	cout << "Hesap Adi: ";
	cin >> uyeAccountName; //�yenin kullan�c� ad� bilgisi al�n�r
	if (globalUyeIndex != 0)
	{
		while (tempHesapAdiKontrol)
		{
			for (int i = 0; i < globalUyeIndex; i++) //T�m �yelerin kullan�c� adlar�n�n konutrol� i�in i. indisten parametre olarak al�nan globalUyeIndex'ine kadar giden for d�ng�s�
			{
				if (uyeAccountName == uy[i].GetHesapAdi())  //Girilen kullan�c� ad� i. indisteki kullan�c� ad� ile e�le�iyorsa �al��acak if blo�u
				{
					cout << "Girmis oldugunuz hesap adi baska bir kullanici tarafindan kullanilmaktadir. Lutfen yeni bir hesap adi deneyiniz." << endl;
					cout << "Hesap Adi: ";
					cin >> uyeAccountName; //�yenin yeni kullan�c� ad� bilgisi al�n�r
					i = -1; //Girilen yeni kullan�c� ad�n�n daha �ncesinde olup olmad��� kontrol edilir
				}
				else
				{
					tempHesapAdiKontrol = false; //E�er girilen kullan�c� ad� bilgisi daha �nce sistemde yoksa tempHesapAdiKontrol'e ba�l� while d�ng�s�n�n durmas� i�in tempHesapAdiKontrol'e false atan�r
				}
			}
		}
	}
	cout << "Uye Tipi: ";
	cin >> uyeMemberType; //�yenin �ye tipi bilgisi al�n�r

	uyePassword = "temp"; //�yelerin standart ba�lang�� �ifreleri "temp" olarak atan�r

	uye.SetAdSoyad(uyeName); //uyeName de�i�kenine girilen ad soyad atan�r
	uye.SetHesapAdi(uyeAccountName); //uyeAccoundName de�i�kenine girilen hesap ad� atan�r
	uye.SetUyeTipi(uyeMemberType); //uyeMemberType de�i�kenine girilen �ye tipi atan�r
	uye.SetSifre(uyePassword); //uyePassword de�i�kenine standart ba�langi� de�eri olan "temp" atan�r
	uye.SetId(globalUyeIndex);
	uye.SetAlinanKitapSayisi(0);

	return uye; //Eklenen �ye return ile geri d�nd�r�l�r
}

Uye* Admin::AdminUyeSil(int globalUyeIndex, Uye editUye[100]) //�ye silinmesini sa�layan fonksiyon globalUyeIndex ve editUye'yi parametre al�r
{

	string tempUserName; //Silinmek istenen �yenin kullan�c� ad�n� tutan de�i�ken
	int tempUserID; //Silinmek istenen �yenin kullan�c�n�n id'sini tutan de�i�ken
	cout << "Silmek istediginiz uyenin kullanici adini giriniz: ";
	cin >> tempUserName; //Silinmek istenen �yenin kullan�c� ad�n�n bilgisini alan de�i�en
	for (int i = 0; i < 100; i++)
	{
		if (tempUserName == editUye[i].GetHesapAdi()) //E�er GetHesapAdi de�i�keninin i. de�eri tempUserName de�i�kenine e�itse �al��acak if blo�u
		{
			tempUserID = editUye[i].GetId(); //GetId fonksiyonunun i. indisi tempUserID de�i�kenine atan�r ve bu sayede �ye silme i�lemi ger�ekle�ir
		}
	}
	for (int j = tempUserID; j <= globalUyeIndex; j++)
	{
		editUye[j].SetAdSoyad(editUye[j + 1].GetAdSoyad()); //j. indisin ad soyad� silinir ve j yerine (j+1). de�erin ad soyad� atan�r.
		editUye[j].SetHesapAdi(editUye[j + 1].GetHesapAdi()); //j. indisin hesap ad� silinir ve j yerine (j+1). de�erin hesap ad� atan�r.
		editUye[j].SetId(editUye[j + 1].GetId()); //j. indisin id'si silinir ve j yerine (j+1). de�erin id'si atan�r.
		editUye[j].SetSifre(editUye[j + 1].GetSifre()); //j. indisin �ifresi silinir ve j yerine (j+1). de�erin �ifresi atan�r.
		editUye[j].SetUyeTipi(editUye[j + 1].GetUyeTipi()); //j. indisin �ye tipi silinir ve j yerine (j+1). de�erin �ye tipi atan�r.
	}

	return editUye; //Silinen �ye return ile geri d�nd�r�l�r

}

void Admin::AdminUyeleriListele(int globalUyeIndex, Uye uyeTmp[]) //�yelerin listelenmesini sa�layan fonksiyon globalUyeIndex ve uyeTmp'yi parametre al�r
{
	cout << "ID" << setw(10) << "Uye Adi" << setw(15) << "Uye Tipi" << setw(15) << "Hesap Adi" << endl;
	for (int i = 0; i < globalUyeIndex; i++)
	{
		cout << i << setw(10) << uyeTmp[i].GetAdSoyad() << setw(15) << uyeTmp[i].GetUyeTipi() << setw(15) << uyeTmp[i].GetHesapAdi() << endl; //Ekrana �ye bilgilerini yazd�r
	}

}
