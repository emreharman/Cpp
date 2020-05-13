/****************************************************************************
**
**				ÖÐRENCÝ ADI........: EMRE HARMAN
**				ÖÐRENCÝ NUMARASI...: B191210049
**				DERS GRUBU.........: 1B
****************************************************************************/

#include<iostream>
#include<fstream>
#include<Windows.h>
#include<string>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Ogrenci {
private:
	string isim;
	string soyisim;
	int numara;
public:
	void setIsim(string ad) {//Dosya yonetiminden set ederken
		isim = ad;
	}
	const string getIsim() {
		return isim;
	}
	void setSoyisim(string soyad) {//Dosya yonetiminden set ederken
		soyisim = soyad;
	}
	const string getSoyisim() {
		return soyisim;
	}
	void setNumara() {//Yeni ogrenci olustururken
		numara = 100 + rand() % 101;
	}
	void setNumara(int a) {//Okul kurucu sýnýfý icin
		numara = a;
	}
	const int getNumara() {
		return numara;
	}
};

class Sinif:public Ogrenci {
private:
	string sinifIsmi;
	int sinifSayisi;
	Ogrenci ogr[100];
	int ogrenciSayisi;
public:
	Sinif() {
		ogrenciSayisi = 0;
	}
	void setSinifIsmi() {//Yeni sinif olustururken
		setSinifSayisi();
		string sayi = to_string(sinifSayisi);
		char harf = 'A' + (rand() % ('A' - 'Z' + 1));
		sinifIsmi = sayi + harf;
	}
	void setSinifIsmi(string ad) {//Okul kurucu sýnýfý için
		sinifIsmi = ad;
	}
	const string getSinifIsmi() {
		return sinifIsmi;
	}
	int sonSinifSayisi() {//Yeni sinif ismi olustururken
		ifstream oku("kayitlar.txt");
		int sinifSayisi = 0;
		string sinifAd[100];
		int ogrSayi;
		string gecici[100];
		int i = 0;
		while (!oku.eof()) {
			oku >> sinifAd[sinifSayisi];
			if (sinifAd[sinifSayisi] == "\0") {
				return sinifSayisi;
			}
			else {
				sinifSayisi++;
				oku >> ogrSayi;
				for (int j = 0; j < ogrSayi; j++) {
					oku >> gecici[j] >> gecici[j + 1] >> gecici[j + 2];
				}
			}
		}
		return sinifSayisi;
	}

	void setSinifSayisi() {//Yeni sinif ismi olustururken
		sinifSayisi = sonSinifSayisi() + 1;
	}
	void setOgrenciSayisi(int x) {//Okul kurucu sýnýfý için
		ogrenciSayisi = x;
	}
	const int getOgrenciSayisi() {
		return ogrenciSayisi;
	}
	void ogrenciEkle(Ogrenci o, int i) {

		ogr[i] = o;
		ogrenciSayisi++;
	}
	void ogrenciSil(int ogrSirasi) {
		for (int i = 0; i < getOgrenciSayisi(); i++) {
			if (i == ogrSirasi) {
				ogr[ogrSirasi].setIsim("\0");
				ogr[ogrSirasi].setSoyisim("\0");
				ogr[ogrSirasi].setNumara(NULL);
				ogr[99] = ogr[ogrSirasi];
			}
		}
		for (int j = ogrSirasi; j < getOgrenciSayisi(); j++) {
			ogr[j] = ogr[j + 1];
		}
	}
	const Ogrenci getOgrenci(int i) {
		return ogr[i];
	}
};

class DosyaYonetimi;
class Okul {
private:
	Sinif sinif[100];
	int sinifSayi;
	int oSayi[100];
	char solUstKose = 201;
	char duz = 205;
	char sagUstKose = 187;
	char solAltKose = 200;
	char sagAltKose = 188;
	char dikey = 186;
public:
	Okul() {
		string sAd[100];
		string oAd[100];
		string oSoyad[100];
		int oNum[100];
		int i = 0;
		int j ;
		ifstream oku("kayitlar.txt");
		while (oku >> sAd[i] >> oSayi[i]) {
			sinif[i].setSinifIsmi(sAd[i]);
			for (j=0; j < oSayi[i]; j++) {
				oku >> oAd[j] >> oSoyad[j] >> oNum[j];
				Ogrenci ogr;
				ogr.setIsim(oAd[j]);
				ogr.setSoyisim(oSoyad[j]);
				ogr.setNumara(oNum[j]);
				sinif[i].ogrenciEkle(ogr, j);
			}
			sinifEkle(i, sinif[i]);
			sinif[i].setOgrenciSayisi(j);
			i++;
		}
		setSinifSayi(i);
	}
	void setSinifSayi(int x) {
		sinifSayi = x;
	}
	void setOkulunSinifininOgrenciSayisi(int sinifNumarasi,int ogrSayisi) {
		sinif[sinifNumarasi].setOgrenciSayisi(ogrSayisi);
	}
	void okulGoster() {
		int x = 0;
		int j;
		int k;
		for (k = 0; k < getSinifSayi(); k++) {
			sinifCiz(sinif[k].getSinifIsmi(), x, 1);
			for (j = 0; j < sinif[k].getOgrenciSayisi(); j++) {
				ogrenciCiz(sinif[k].getOgrenci(j), x+2, 5 + j*5);
			}
			x += 18;
		}
		gotoxy(0, ogrSayiSirala() * 5+4);
	}
	void sinifCiz(string sinifAd, int x1, int y1) {
		int sinifGenislik = 15;
		int sinifYukseklik = 1;
		int x = x1;
		int y = y1;
		gotoxy(x, y - 1);
		ustYazdir(sinifGenislik);
		for (int i = 0; i < sinifYukseklik; i++) {//sag kenar
			gotoxy(x + sinifGenislik + 1, y);
			cout << dikey << endl;
			y++;
		}

		for (int j = 0; j < sinifYukseklik; j++) {//sol kenar
			gotoxy(x, y - sinifYukseklik);
			cout << dikey << endl;
		}
		gotoxy(x, y);
		altYazdir(sinifGenislik);
		gotoxy(x + sinifGenislik / 2, y - 1);
		cout << sinifAd;
		gotoxy(x, y + 1);
	}
	void ogrenciCiz(Ogrenci ogr, int x1, int y1) {
		int ogrenciGenislik = 10;
		int ogrenciYukseklik = 3;
		int x = x1;
		int y = y1;
		gotoxy(x, y - 1);
		ustYazdir(ogrenciGenislik);
		for (int i = 0; i < ogrenciYukseklik; i++) {//sag kenar
			gotoxy(x + ogrenciGenislik + 1, y);
			cout << dikey << endl;
			y++;
		}

		for (int j = 0; j < ogrenciYukseklik; j++) {//sol kenar
			gotoxy(x, y - ogrenciYukseklik + j);
			cout << dikey << endl;
		}
		gotoxy(x, y);
		altYazdir(ogrenciGenislik);
		gotoxy(x + 1, y - ogrenciYukseklik);
		cout << setw(ogrenciGenislik) << right << ogr.getIsim();
		gotoxy(x + 1, y - ogrenciYukseklik + 1); 
		cout << setw(ogrenciGenislik) << right << ogr.getSoyisim();
		gotoxy(x + 1, y - ogrenciYukseklik + 2); 
		cout << setw(ogrenciGenislik) << right << ogr.getNumara();
		gotoxy(x + 1, y - ogrenciYukseklik + 5); 
	}
	void ustYazdir(int elemanSayisi) {
		cout << solUstKose;
		for (int i = 0; i < elemanSayisi; i++) {
			cout << duz;
		}
		cout << sagUstKose;
	}
	void altYazdir(int elemanSayisi) {
		cout << solAltKose;
		for (int i = 0; i < elemanSayisi; i++) {
			cout << duz;
		}
		cout << sagAltKose;
	}
	int ogrSayiSirala() {
		int buyuk = 0;
		int temp;
		for (int i = 0; i < 5; i++) {
			for (int j = 1; j < 10; j++) {
				if (oSayi[i] < oSayi[j]) {
					temp = oSayi[i];
					oSayi[i] = oSayi[j];
					oSayi[j] = temp;
				}
			}
		}
		buyuk = oSayi[0];
		return buyuk;
	}
	int getSinifSayi() {
		return sinifSayi;
	}
	void okulKaydet() {
		ofstream kayit("kayitlar1.txt");
		for (int i = 0; i < getSinifSayi(); i++) {
			kayit << getSinif(i).getSinifIsmi() << endl;
			kayit << getSinif(i).getOgrenciSayisi() << endl;
			for (int j = 0; j < getSinif(i).getOgrenciSayisi(); j++) {
				Ogrenci ogr = getSinif(i).getOgrenci(j);
				kayit << ogr.getIsim() << " " << ogr.getSoyisim() << " " << ogr.getNumara() << endl;
			}
		}
		kayit.close();
		remove("kayitlar.txt");
		rename("kayitlar1.txt", "kayitlar.txt");
	}
	Sinif getSinif(int i) {
		return sinif[i];
	}
	void sinifEkle(int i, Sinif s) {
		sinif[i] = s;
		sinifSayi++;
	}
	void okulunSinifinaOgrenciEkle(Ogrenci ogr, int hangiSinif, int ogrenci) {
		sinif[hangiSinif].ogrenciEkle(ogr, ogrenci);
	}
	void okulunSinifindanOgrenciSil(int sinifNumarasi, int ogrSirasi) {
		sinif[sinifNumarasi].ogrenciSil(ogrSirasi);
	}
	void sinifSil(int sinifNumarasi) {
		sinif[sinifNumarasi].setSinifIsmi("\0");
		int k = sinif[sinifNumarasi].getOgrenciSayisi();
		for (int i = 0; i < k; i++) {
			sinif[sinifNumarasi].ogrenciSil(i);
			k--;
		}
		for (int j = sinifNumarasi; j < getSinifSayi(); j++) {
			sinif[j] = sinif[j + 1];
		}
		setSinifSayi(getSinifSayi() - 1);
	}

};
class DosyaYonetimi {
private:

public:
	string isimOku() {
		srand(time(0));
		string Isim[5000];
		int i = 0;
		int boyut = 0;
		ifstream oku("isimler.txt");
		while (!oku.eof()) {
			oku >> Isim[i];
			++i;
			++boyut;
		}
		oku.close();
		return Isim[rand() % 4946];
	}
	string soyisimOku() {
		srand(time(0));
		string Soyisim[300];
		int i = 0;
		int boyut = 0;
		ifstream oku("soyisimler.txt");
		while (!oku.eof()) {
			oku >> Soyisim[i];
			++i;
			++boyut;
		}
		oku.close();
		return Soyisim[rand() % 279];
	}
	void dosyayaOgrenciKaydet(Ogrenci o) {
		Ogrenci ogr;
		ogr = o;
		ofstream kayit("kayitlar.txt", ios::app);
		kayit << ogr.getIsim() << " " << ogr.getSoyisim() << " " << ogr.getNumara() << endl;
		kayit.close();
	}
	void dosyayaSinifKaydet(Sinif s) {
		ofstream kayit("kayitlar.txt", ios::app);
		kayit << s.getSinifIsmi() << endl;
		kayit << s.getOgrenciSayisi() << endl;
		kayit.close();
	}
	void dosyayaOkulKaydet(Okul o) {
		o.getSinifSayi();
		int sayi = o.getSinifSayi();
		ofstream kayit("kayitlar1.txt", ios::app);
		for (int i = 0; i < sayi; i++) {
			Sinif s;
			s = o.getSinif(i);
			kayit << s.getSinifIsmi() << endl;
			kayit << sayi << endl;
			for (int j = 0; j < sayi; j++) {
				Ogrenci ogr;
				ogr = s.getOgrenci(j);
				kayit << ogr.getIsim() << " " << ogr.getSoyisim() << " " << ogr.getNumara() << endl;
			}
		}
		kayit.close();
		remove("kayitlar.txt");
		rename("kayitlar1.txt", "kayitlar.txt");
	}
	

};

class Program {
private:
	char secim;
public:
	void menu() {
		cout << "1.Ogrenci Ekle" << endl;
		cout << "2.Sinif Ekle" << endl;
		cout << "3.Ogrenci Degistir" << endl;
		cout << "4.Ogrenci Sil" << endl;
		cout << "5.Sinif Sil" << endl;
		cout << "6.Cikis" << endl;
	}
	void calistir() {
		fstream dosya("kayitlar.txt",ios::app);
		dosya.close();
		while (secim != '6') {
			system("cls");
			Okul okul;
			DosyaYonetimi dy;
			okul.okulGoster();
			menu();
			cin >> secim;
			if (secim == '1') {
				string sinifAd;
				cout << "Sinif Adi : ";
				cin >> sinifAd;
				Ogrenci ogr;
				ogr.setIsim(dy.isimOku());
				ogr.setSoyisim(dy.soyisimOku());
				ogr.setNumara();
				cout << ogr.getIsim() << endl;
				cout << ogr.getSoyisim() << endl;
				cout << ogr.getNumara() << endl;
				Sleep(200);
				//Sinif s;
				for (int i = 0; i < okul.getSinifSayi(); i++) {
					if (sinifAd == okul.getSinif(i).getSinifIsmi()) {
						okul.okulunSinifinaOgrenciEkle(ogr, i, okul.getSinif(i).getOgrenciSayisi());
					}
				}
				okul.okulKaydet();
			}
			else if (secim == '2') {
				Sinif s;
				s.setSinifIsmi();
				okul.sinifEkle(okul.getSinifSayi(), s);
				okul.okulKaydet();
			}
			else if (secim == '3') {
				Ogrenci o;
				int no;
				cout << "Ogrenci Numarasi : ";
				cin >> no;
				for (int i = 0; i < okul.getSinifSayi(); i++) {
					for (int j = 0; j < okul.getSinif(i).getOgrenciSayisi(); j++) {
						 o = okul.getSinif(i).getOgrenci(j);
						if (no == o.getNumara()) {
							o.setIsim(dy.isimOku());
							o.setSoyisim(dy.soyisimOku());
							o.setNumara();
							cout << o.getIsim()<<endl;
							cout << o.getSoyisim() << endl;
							cout << o.getNumara() << endl;
							Sleep(200);
							okul.okulunSinifinaOgrenciEkle(o, i, j);
							okul.setOkulunSinifininOgrenciSayisi(i, okul.getSinif(i).getOgrenciSayisi() - 1);
						}
					}
				}
				okul.okulKaydet();
			}
			else if (secim == '4') {
				Ogrenci ogr;
				int no;
				cout << "Ogrenci Numarasi : ";
				cin >> no;
				for (int i = 0; i < okul.getSinifSayi(); i++) {
					for (int j = 0; j < okul.getSinif(i).getOgrenciSayisi(); j++) {
						ogr = okul.getSinif(i).getOgrenci(j);
						if (no == ogr.getNumara()) {
							okul.okulunSinifindanOgrenciSil(i, j);
							okul.setOkulunSinifininOgrenciSayisi(i, okul.getSinif(i).getOgrenciSayisi() - 1);
							break;
						}
					}
				}
				okul.okulKaydet();
			}
			else if (secim == '5') {
				string sinifAd;
				cout << "Sinif Ismi : ";
				cin >> sinifAd;
				for (int i = 0; i < okul.getSinifSayi(); i++) {
					if (sinifAd == okul.getSinif(i).getSinifIsmi()) {
						okul.sinifSil(i);
						break;
					}
				}
				okul.okulKaydet();
			}
			else if (secim == '6') {
				exit(0);
			}
			else {
				cout << "Hatali Secim!" << endl;
				Sleep(200);
			}
		}
	}
};
int main() {
	Program prog;
	prog.calistir();
	system("pause");
	return 0;
}
