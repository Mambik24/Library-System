//Alper
//Yoruk
//200757023
//Bilgisayar M�hendisli�i (��)
//BIM-104-50-50
//2021 Bahar D�nemi
//Proje 2
//G�l�ah T�M�KL� �ZYER

#ifndef KULLANICI_H
#define KULLANICI_H  

#include <iostream>
#include <string>

using namespace std;

class Kullanici
{
public:

    void SetHesapAdi(string); //Kullan�c� hesap ad�n� de�i�tir
    string GetHesapAdi(); //Kullan�c� hesap ad� bilgisini getir

    void SetId(int); //Kullan�c� id'sini de�i�tir
    int GetId(); //Kullan�c� id bilgisini getir

    void SetSifre(string); //Kullan�c� sifresini de�i�tir
    string GetSifre(); //Kullan�c� �ifre bilgisini getir

    void SetAdSoyad(string); //Kullan�c� ad soyad�n� de�i�tir
    string GetAdSoyad(); //Kullan�c� ad soyad bilgisini getir

    void SetAlinanKitapSayisi(int); //Kullan�c�n�n alabildi�i kitap say�s�n� de�i�tir
    int GetAlinanKitapSayisi(); //Kullan�c�n�n alabildi�i kitap say�s� bilgisini getir

    void SetUyeTipi(string); //Kullan�c�n�n �ye tipini de�i�tir
    string GetUyeTipi(); //Kullan�c�n�n �ye tipi bilgisini getir

    void SetUyeKitapSayisi(int); //�yenin elinde bulunan kitap say�s�n� de�i�tir
    int GetUyeKitapSayisi(); //�yenin elinde bulunan kitap say�s� bilgisini getir

private:
    int alinanKitapSayisi;
    string hesapAdi;
    int id;
    string sifre;
    string uyeTipi;
    string adSoyad;

};
#endif //Kullanici_H