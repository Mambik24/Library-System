//Alper
//Yoruk
//200757023
//Bilgisayar M�hendisli�i (��)
//BIM-104-50-50
//2021 Bahar D�nemi
//Proje 2
//G�l�ah T�M�KL� �ZYER

#ifndef UYE_H
#define UYE_H

#include <iostream>
#include <string>
#include "Kullanici.h"
#include "Kitap.h"

using namespace std;

class Uye :public Kullanici
{
public:
	void UyeKitapAra(Kitap[]); //Kitap aramas�n�n yap�ld��� fonksiyon
	void UyeKitapOduncAl(int, Uye[], Kitap[]); //Kitap �d�n� al�nmas�n�n yap�ld��� fonksiyon
	void UyeKitapIadeEt(int, Uye[], Kitap[]); //Kitap siliminin yap�ld��� fonksiyon
	void UyeKitaplariListele(int, Kitap[]); //Kitaplar�n listelenmesini sa�layan fonksiyon
	void UyeUyelikIslemleri(int, Uye[]); //�yeerin �ifrelerini de�i�tirebilmesini sa�layan fonksiyon
	// void SetUyeTipi(string);
	// string GetUyeTipi();

};
#endif // Uye_H
