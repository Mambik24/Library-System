//Alper
//Yoruk
//200757023
//Bilgisayar M�hendisli�i (��)
//BIM-104-50-50
//2021 Bahar D�nemi
//Proje 2
//G�l�ah T�M�KL� �ZYER

#include <iostream>
#include "Kitap.h"

using namespace std;

void Kitap::SetKitapAdi(string bookName) //Kitap ad�n� de�i�tir
{
    kitapAdi = bookName;
}
string Kitap::GetKitapAdi() //Kitap ad� bilgisini getir
{
    return kitapAdi;
}
void Kitap::SetKitapID(int bookID) //Kitap id'sini de�i�tir
{
    kitapID = bookID;
}
int Kitap::GetKitapID() //Kitap id'si bilgisini getir
{
    return kitapID;
}
void Kitap::SetYazar(string author) //Yazar ad�n� de�i�tir
{
    yazar = author;
}
string Kitap::GetYazar() //Yazar ad� bilgisini getir
{
    return yazar;
}
void Kitap::SetAlanKisiID(int alanID) //Kitab� alan ki�inin id'sini de�i�tir
{
    alanKisiID = alanID;
}
int Kitap::GetAlanKisiID() //Kitab� alan ki�inin id'si bilgisini getir
{
    return alanKisiID;
}
void Kitap::SetOnHoldID(int alanKisiID) //Kitaba sahip olan ki�inin id'sini de�i�tir
{
    onHoldID = alanKisiID;
}
int Kitap::GetOnHoldID() //Kitaba sahip olan ki�inin id bilgisini getir
{
    return onHoldID;
}
void Kitap::SetIsOnHold(bool sahipli) //Kitab�n al�n�p al�nmad���n� de�i�tir
{
    isOnHold = sahipli;
}
bool Kitap::GetIsOnHold() //Kitab�n al�n�p al�nmad��� bilgisini getir
{
    return isOnHold;
}