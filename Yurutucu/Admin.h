//Alper
//Yoruk
//200757023
//Bilgisayar M�hendisli�i (��)
//BIM-104-50-50
//2021 Bahar D�nemi
//Proje 2
//G�l�ah T�M�KL� �ZYER

#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include "Kullanici.h"
#include "Kitap.h"
#include "Uye.h"

using namespace std;

class Admin : public Kullanici
{
public:
	Kitap AdminKitapEkle(int); //Kitap eklemeyi sa�layan fonksiyon
	Kitap* AdminKitapSil(int, Kitap[]); //Kitap silinmesini sa�layan fonksiyon
	void AdminKitaplariListele(int, Kitap[]); //Kitaplar�n listelenmesini sa�layan fonksiyon
	Uye AdminUyeEkle(int, Uye[]); //�ye eklenmesini sa�layan fonksiyon
	Uye* AdminUyeSil(int, Uye[]); //�ye silinmesini sa�layan fonksiyon
	void AdminUyeleriListele(int, Uye[]); //�yelerin listelenmesini sa�layan fonksiyon
};
#endif // Admin_H