//Alper
//Yoruk
//200757023
//Bilgisayar M�hendisli�i (��)
//BIM-104-50-50
//2021 Bahar D�nemi
//Proje 2
//G�l�ah T�M�KL� �ZYER

#include <iostream>
#include <iomanip>
#include "Admin.h"
#include "Uye.h"
#include "Kitap.h"
#include "Kullanici.h"

using namespace std;

void GirisEkranMenusu(int, int, Kitap[], Uye[]); //Admin Giri�i, �ye Giri�i ve C�k�� gibi se�eneklerin oldu�u ilk giri� men�s�
bool IsAdminGiris(); //Admin giri�inin do�rulu�unu kontrol eden bool fonksiyonu
bool UyeGiris(Uye[100]); //�ye giri�inin do�rulu�unu kontrol eden bool fonksiyonu


int main()
{
    int ktpIndex = 0; //Ba�lang��taki kitap say�s�
    int uyeIndex = 0; //Ba�lang��taki �ye say�s�
    Kitap kitap[100]; //K�t�phanedeki maksimum olu�abilecek kitap say�s�
    Uye uye[100]; //K�t�phanedeki maksimum olu�abilecek �ye say�s�
    Admin admin; //Admin ile ilgili baz� i�lemlerin yap�labilmesi i�in olu�turulan de�i�ken

    admin.SetHesapAdi("admin"); //Adminin giri�teki hesap ad�
    admin.SetSifre("1234"); // Adminin giri�teki �ifresi
    GirisEkranMenusu(ktpIndex, uyeIndex, kitap, uye); 

    return 0;
}

void GirisEkranMenusu(int ktpIndex, int uyeIndex, Kitap ktp[100], Uye uy[100]) //Admin Men�s�, �ye Men�s� ve C�k�� gibi se�eneklerin oldu�u ilk giri� men�s�
{
    int secim1 = 0; //Ana Men� i�indeki se�imlerin bilgisini tutan secim1 de�i�keni ve ba�lang��taki standart de�eri.
    int tempKitapIndex = ktpIndex; //Ba�lang��taki kitap say�s� ileride i�lem yap�l�rken kolayl�k olsun diye ge�ici bir kitap say�s� de�i�keni olan tempKitapIndex'e atan�r. 
    int tempUyeIndex = uyeIndex; //Ba�lang��taki �ye say�s� ileride i�lem yap�l�rken kolayl�k olsun diye ge�ici bir �ye say�s� de�i�keni olan tempUyeIndex'e atan�r.
    bool cikis = false; //GirisEkranMenusu fonksiyonunun s�rekli devam etmesi i�in olu�turulan cikis ad�ndaki bool fonksiyonu ve ona atanan ilk deger
    int tempUserID = 0; //Uyelerin ba�lang��taki ID say�s�
    while (cikis == false) 
    {
        cout << endl;
        cout << "                   ANA MENU" << endl;
        cout << "1 Admin Girisi" << endl;
        cout << "2 Uye Girisi" << endl;
        cout << "3 Cikis" << endl;
        cout << "           Seciminizi Giriniz: ";
        cin >> secim1; //Ana Men�de se�im bilgisinin al�nmas�
        cout << endl;
        bool control1 = false; //Admin Giri�i se�ildi�i taktirde s�rekli devam etmesi i�in olu�turulan control1 ad�ndaki bool fonksiyonu ve ona atanan ilk deger
        bool control2 = false; //�ye Giri�i se�ildi�i taktirde s�rekli devam etmesi i�in olu�turulan control2 ad�ndaki bool fonksiyonu ve ona atanan ilk deger
        switch (secim1) //se�im1'e ba�l� switch yap�s�
        {
        case 1: //Admin Giri�i
        {
            bool isAdmin = IsAdminGiris(); //Admin giri�inin do�rulu�unu kontrol eden bool fonksiyonunun sonucu isAdmin ad�ndaki de�i�kene atan�r
            control1 = true; //Alttaki while d�ng�s�n�n �al��mas� i�in control1'e true de�eri atan�r
            while (control1)
            {
                if (isAdmin) //Do�ru ise if blo�unu �al��t�r
                {
                    Admin adminGiris; //Admin Men�s�ndeki i�lemlerin yap�labilmesi i�in olu�turulan de�i�ken
                    int secim2; //Admin Men�s� i�indeki se�imlerin bilgisini tutan secim2 de�i�keni ve ba�lang��taki standart de�eri.
                    cout << endl;
                    cout << "       ADMIN MENUSU" << endl;
                    cout << "1 Kitap Ekle" << endl;
                    cout << "2 Kitap Sil" << endl;
                    cout << "3 Kitaplari Listele" << endl;
                    cout << "4 Uye Ekle" << endl;
                    cout << "5 Uyeleri Listele" << endl;
                    cout << "6 Uyeleri Sil" << endl;
                    cout << "7 Cikis" << endl;
                    cout << "           Seciminizi Giriniz: ";
                    cin >> secim2; //Admin Men�s�nde se�im bilgisinin al�nmas�
                    cout << endl;
                    switch (secim2) //secim2'ye ba�l� switch yap�s�
                    {
                    case 1: //Kitap Ekle
                        ktp[tempKitapIndex] = adminGiris.AdminKitapEkle(tempKitapIndex); //ktp dizisinin ge�ici de�i�ken olarak se�ilmi� tempKitapIndex de�i�ken de�erine, AdminKitapEkle fonksiyonunun tempKitapIndex parametresi atan�r 
                        tempKitapIndex++; //Kitap indexleri artarak s�radaki kitab�n indexi eklemeye haz�r hale getirilir
                        break;
                    case 2: //Kitap Sil
                        ktp = adminGiris.AdminKitapSil(tempKitapIndex, ktp); //ktp dizisine AdminKitapSil fonkisyonunun tempKitapIndex ve ktp'si parametre al�narak kitab�n silinmi� hali atan�r
                        tempKitapIndex--; //Kitap indexleri azalarak s�radaki kitab�n indexi silinmeye haz�r hale getirilir
                        break;
                    case 3: //Kitaplar� Listele
                        adminGiris.AdminKitaplariListele(tempKitapIndex, ktp); //AdminKitaplariListele fonksiyonunun tempKitapIndex ve ktp'yi parametre almas� sonucu ekrana kitaplar�n listesi yaz�l�r
                        break;
                    case 4: //�ye Ekle
                        uy[tempUyeIndex] = adminGiris.AdminUyeEkle(tempUyeIndex, uy); //uy dizisinin ge�ici de�i�ken olarak se�ilmi� tempUyeIndex de�i�ken de�erine, AdminUyeEkle fonksiyonunu tempUyeIndex ve uy parametresi atan�r
                        tempUyeIndex++;
                        break;

                    case 5: //�yeleri Listele
                        adminGiris.AdminUyeleriListele(tempUyeIndex, uy); //AdminUyeleriListele fonksiyonunun tempUyeIndex ve uy'u parametre almas� sonucu ekrana kitaplar�n listesi yaz�l�r
                        break;
                        break;

                    case 6: //�ye Sil
                        uy = adminGiris.AdminUyeSil(tempUyeIndex, uy); ///uy dizisine AdminUyeSil fonkisyonunun tempUyeIndex ve uy'u parametre al�narak kitab�n silinmi� hali atan�r
                        tempUyeIndex--;
                        break;

                    case 7: //C�k��
                        control1 = false; //while d�ng�s�n�n bitmesi i�in control1'e false atan�r
                        break;

                    default: //Yanl�� tu�lama
                        cout << "Yanlis giris yaptiniz.";
                        break;
                    }
                }

                else
                {
                    isAdmin = IsAdminGiris(); //Admin giri�inde yanl��l�k oldu�unda �al���r
                    secim1 = 1; //Admin gir�inin tekrarlanmas� i�in secim1'e 1 atan�r
                }
            }
            break;
        }

        case 2: //Uye Giri�i
        {
            bool control2 = true; //Alttaki while d�ng�s�n�n �al��mas� i�in control1'e true de�eri atan�r
            bool giris = false; //�ye giri�i i�in olu�turulan giris de�i�keninin ba�lang��taki de�eri
            while (control2)
            {
                string username, usernameAttempt, password, passwordAttempt; //�yenin kullan�c� ad�n� ve �ifresini kontrol edecek de�i�kenler ve olu�turulan kullan�c� ad� ve �ifresini bulunduran de�i�kenler
                while (giris == false)
                {
                    cout << "Uye Kullanici Adi: ";
                    cin >> usernameAttempt; //�yeden kullan�c� ad� bilgisi al�n�r
                    for (int i = 0; i < 100; i++) //Var olan t�m kullan�c�larda test edilir
                    {
                        if (usernameAttempt == uy[i].GetHesapAdi()) //i. �yenin hesap ad� do�rulu�u
                        {
                            cout << "Sifre: ";
                            cin >> passwordAttempt; //�yeden �ifre bilgisi al�n�r
                            if (passwordAttempt == uy[i].GetSifre()) //i. �yenin �ifre do�rulu�u
                            {
                                cout << "Sifre kabul edildi" << endl;
                                username = usernameAttempt; //Hangi kullan�c� ad�na sahip �yenin �ifresinin kabul edildi�i bilgisi username de�i�kenine atan�r
                                tempUserID = i; //Hangi ID'ye sahip �yenin �ifresinin kabul edildi�i tempUserID de�i�kenine atan�r
                                giris = true; //�ye giri�i i�in olu�turulan giris'e true atan�r
                                break;
                            }
                            else
                            {
                                cout << "Hatali sifre."; 
                                cout << endl;
                            }
                        }
                    }
                }
                if (giris) //Do�ru ise if blo�unu �al��t�r
                {
                    Uye uyeGiris; //Uye Men�s�ndeki i�lemlerin yap�labilmesi i�in olu�turulan de�i�ken
                    
                                            
                    // uyeGiris.SetAdSoyad(uy[tempUserID].GetAdSoyad());
                    // uyeGiris.SetHesapAdi(uy[tempUserID].GetHesapAdi());
                    // uyeGiris.SetId(uy[tempUserID].GetId());
                    // uyeGiris.SetUyeKitapSayisi(uy[tempUserID].GetUyeKitapSayisi());
                    // uyeGiris.SetUyeTipi(uy[tempUserID].GetUyeTipi());
                    // uyeGiris.SetAlinanKitapSayisi(uy[tempUserID].GetAlinanKitapSayisi());

                    int secim3; //�ye Men�s� i�indeki se�imlerin bilgisini tutan secim3 de�i�keni ve ba�lang��taki standart de�eri
                    cout << endl;
                    cout << "       UYE MENUSU" << endl;
                    cout << "1 Kitap Ara" << endl;
                    cout << "2 Kitap Odunc Al" << endl;
                    cout << "3 Kitap Iade Et" << endl;
                    cout << "4 Kitaplari Listele" << endl;
                    cout << "5 Uyelik Islemleri" << endl;
                    cout << "6 Cikis" << endl;
                    cout << "           Seciminizi Giriniz: ";
                    cin >> secim3; //�ye Men�s�nde se�im bilgisinin al�nmas�
                    cout << endl;
                    switch (secim3) //secim3'e ba�l� switch yap�s�
                    {
                    case 1: //Kitap Ara
                        uyeGiris.UyeKitapAra(ktp); //UyeKitapAra fonksiyonunun ktp'yi parametre almas� sonucu istenilen kitap aran�r
                        break;

                    case 2: //Kitap Odunc Al
                        uyeGiris.UyeKitapOduncAl(tempUserID, uy, ktp); //UyeKitaplariOduncAl fonksiyonunun tempUserID, uy ve ktp'yi parametre almas� sonucu istenilen kitap �d�n� al�n�r
                        break;

                    case 3: //Kitap Iade Et
                        uyeGiris.UyeKitapIadeEt(tempUserID, uy, ktp); //UyeKitapIadeEt fonksiyonunun tempUserID, uy ve ktp'yi parametre almas� sonucu istenilen kitap iade edilir
                        break;

                    case 4: //Kitaplari Listele
                        uyeGiris.UyeKitaplariListele(tempKitapIndex, ktp); //UyeKitaplariListele fonksiyonunun tempKitapIndex ve ktp'yi parametre almas� sonucu ekrana kitaplar�n listesi yaz�l�r
                        break;

                    case 5: //Uyelik Islemleri
                        uyeGiris.UyeUyelikIslemleri(tempUserID, uy); //UyeUyelik�slemleri fonksiyonunun tempUserID ve uy'u parametre almas� sonucu kullan�c� �ifresini istedi�i ba�ka bir �ifre ile de�i�tirebilir
                        break;

                    case 6: //C�k��
                        control2 = false; //while d�ng�s�n�n bitmesi i�in control2'ye false atan�r
                        break;

                    default: //Yanl�� tu�lama
                        cout << "Yanlis giris yaptiniz.";
                        break;
                    }
                }
            }
            break;
        }

        case 3: //C�k��
        {
            cikis = true; //while d�ng�s�n�n bitmesi i�in cikis'a false atan�r
            break;
        }

        default: //Yanl�� tu�lama
            cout << "Yanlis giris yaptiniz.";
            break;
        }
    }
}

bool IsAdminGiris()
{
    bool giris = false; //Admin giri�i i�in olu�turulan giris de�i�keninin ba�lang��taki de�eri
    string username, password;  //Adminin kullan�c� ad�n� ve �ifresini kontrol edecek de�i�kenler
    cout << "Admin Kullanici Adi: ";
    cin >> username; //Admin kullan�c� ad� bilgisi al�n�r
    if (username == "admin")
    {
        cout << "Sifre: ";
        cin >> password; //Admin �ifre bilgisi al�n�r
        if (password == "1234")
        {
            cout << "          Sifre kabul edildi." << endl;
            giris = true; //Admin giri�i i�in olu�turulan giris'e true atan�r
        }
        else
        {
            cout << "Yanlis sifre girdiniz" << endl;
            giris = false; //Admin giri�i i�in olu�turulan giris yanl�� �ifre girildi�i i�in false �eklinde kal�r.
        }
    }
    else
    {
        cout << "Yanlis kullanici adi girdiniz" << endl;
        giris = false; //Admin giri�i i�in olu�turulan giris yanl�� kullan�c� ad� girildi�i i�in false �eklinde kal�r.
    }
    return giris; //giris de�i�keni Admin Girisinde kullan�lmak �zere return ile geri d�nd�r�l�r
}