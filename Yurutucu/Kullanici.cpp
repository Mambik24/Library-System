//Alper
//Yoruk
//200757023
//Bilgisayar M�hendisli�i (��)
//BIM-104-50-50
//2021 Bahar D�nemi
//Proje 2
//G�l�ah T�M�KL� �ZYER

#include <iostream>
#include "Admin.h"
#include "Uye.h"
#include "Kullanici.h"

using namespace std;

bool GirisDogruMu(string username, string password, string passwordAttempt)
{
	// cout << "Uye Kullanici Adi: ";
	// cin >> username;
	// cout << "Sifre: "
	// cin >> passwordAttempt;

	return true;
}

void Kullanici::SetHesapAdi(string accountName) //Kullan�c� hesap ad�n� de�i�tir
{
	hesapAdi = accountName;
}

string Kullanici::GetHesapAdi()  //Kullan�c� hesap ad� bilgisini getir
{
	return hesapAdi;
}

void Kullanici::SetId(int kimlikNumarasi) //Kullan�c� id'sini de�i�tir
{
	id = kimlikNumarasi;
}

int Kullanici::GetId() //Kullan�c� id bilgisini getir
{
	return id;
}

void Kullanici::SetSifre(string password) //Kullan�c� sifresini de�i�tir
{
	sifre = password;
}
string Kullanici::GetSifre() //Kullan�c� �ifre bilgisini getir
{
	return sifre;
}

void Kullanici::SetAdSoyad(string nameSurname) //Kullan�c� ad soyad�n� de�i�tir
{
	adSoyad = nameSurname;
}

string Kullanici::GetAdSoyad() //Kullan�c� ad soyad bilgisini getir
{
	return adSoyad;
}

void Kullanici::SetAlinanKitapSayisi(int numberOfBooksTaken) //Kullan�c�n�n alabildi�i kitap say�s�n� de�i�tir
{
	alinanKitapSayisi = numberOfBooksTaken;
}

int Kullanici::GetAlinanKitapSayisi() //Kullan�c�n�n alabildi�i kitap say�s� bilgisini getir
{
	return alinanKitapSayisi;
}

void Kullanici::SetUyeTipi(string memberType) //Kullan�c�n�n �ye tipini de�i�tir
{
	uyeTipi = memberType;
}

string Kullanici::GetUyeTipi() //Kullan�c�n�n �ye tipi bilgisini getir

{
	return uyeTipi;
}
