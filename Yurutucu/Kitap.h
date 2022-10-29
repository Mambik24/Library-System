//Alper
//Yoruk
//200757023
//Bilgisayar M�hendisli�i (��)
//BIM-104-50-50
//2021 Bahar D�nemi
//Proje 2
//G�l�ah T�M�KL� �ZYER

#ifndef KITAP_H
#define KITAP_H

#include <iostream>
#include <string>

using namespace std;

class Kitap
{
public:
    void SetKitapAdi(string); //Kitap ad�n� de�i�tir
    string GetKitapAdi(); //Kitap ad� bilgisini getir

    void SetKitapID(int); //Kitap id'sini de�i�tir
    int GetKitapID(); //Kitap id'si bilgisini getir

    void SetYazar(string); //Yazar ad�n� de�i�tir
    string GetYazar(); //Yazar ad� bilgisini getir

    void SetAlanKisiID(int); //Kitab� alan ki�inin id'sini de�i�tir
    int GetAlanKisiID(); //Kitab� alan ki�inin id bilgisini getir

    void SetOnHoldID(int); //Kitaba sahip olan ki�inin id'sini de�i�tir
    int GetOnHoldID(); //Kitaba sahip olan ki�inin id bilgisini getir

    void SetIsOnHold(bool); //Kitab�n al�n�p al�nmad���n� de�i�tir
    bool GetIsOnHold(); //Kitab�n al�n�p al�nmad��� bilgisini getir

private:
    string kitapAdi;
    int kitapID;
    string yazar;
    int onHoldID;
    bool isOnHold;
    int alanKisiID;
};
#endif // Kitap_H
