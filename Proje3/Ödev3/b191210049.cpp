/****************************************************************************
**
**				ÖÐRENCÝ ADI.........: Emre Harman
**				ÖÐRENCÝ NUMARASI....: b191210049
**				DERS GRUBU..........: 1B
****************************************************************************/

#include<iostream>
#include<Windows.h>
#include<cstdlib>
#include<ctime>

using namespace std;

struct sahne {
	int  genislik;
	int  yukseklik;	
	char karakter;
};
struct LSekli {
	int  x;
	int  y;
	int  boyut;
	char LKarakter;
};
//Fonksiyon Bildirimleri: 
void kursoruGizle();
void gotoxy(int, int);
sahne sahneOlustur();
void sahneCiz(sahne);
LSekli lSekliOlustur();
void lSekliCiz(LSekli);
LSekli lSekliAsagiGotur(LSekli);

int main() {
	system("color 0F");
	kursoruGizle();
	sahne s;
	LSekli L;
	while (true) {
		srand(time(0));
		system("cls");
		s = sahneOlustur();
		L = lSekliOlustur();
		sahneCiz(s);
		lSekliCiz(L);
		int sayac = 0;
		//L seklini taban degene kadar her seferinde bir asagi aliyor.
		while (sayac<s.yukseklik-3-(L.boyut)) {
			system("cls");
			sahneCiz(s);
			lSekliCiz(L);
			L=lSekliAsagiGotur(L);
			sayac++;
			Sleep(100);
		}
	}
	system("pause");
	return 0;
}
void kursoruGizle() {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
sahne sahneOlustur() {
	srand(time(0));
	sahne sahne;
	char karakterDiziS[5] = { '*','#','$','+','@' };
	sahne.genislik = (rand() % 3 + 3) * 10;
	sahne.yukseklik = (rand() % 11) + 20;
	sahne.karakter = karakterDiziS[rand() % 5];
	return sahne;
}
void sahneCiz(sahne s) {
	//Sahnenin ust kenarini ciziyor.
	for (int i = 0; i < s.genislik; i++) {
		cout << s.karakter;
	}
	//Sahnenin sag kenarini ciziyor.
	for (int i = 0; i < s.yukseklik; i++) {
		gotoxy(s.genislik - 1, i);
		cout << s.karakter;
	}
	//Sahnenin alt kenarini ciziyor.
	for (int i = s.genislik - 1; i >= 0; i--) {
		gotoxy(i, s.yukseklik - 1);
		cout << s.karakter;
	}
	//Sahnenin sol kenarini ciziyor.
	for (int i = s.yukseklik - 1; i >= 0; i--) {
		gotoxy(0, i);
		cout << s.karakter;
	}
}

LSekli lSekliOlustur() {
	srand(time(0));
	LSekli L;
	char karakterDiziL[5] = { '#','*','+','$','@' };
	L.x = (rand() % 21) + 5;
	L.y = 3;
	L.boyut = (rand() % 6) + 2;
	L.LKarakter = karakterDiziL[rand() % 5];
	return L;
}
void lSekliCiz(LSekli L) {
	gotoxy(L.x, L.y);
	if (L.boyut % 2 != 0) {//Boyut tek oldugunda
		int bosluk = (L.boyut / 2 + 1) - 2;
		for (int i = 0; i < L.boyut + 1; i++) {//satirlar
			if (i == 0) {//ilk satir
				gotoxy(L.x, L.y + i);
				for (int j = 0; j < L.boyut / 2 + 1; j++) {
					cout << L.LKarakter;
				}
			}
			else if (i > 0 && i < (L.boyut + 1) / 2 - 1) {//L'nin ust tarafi
				gotoxy(L.x, L.y + i);
				cout << L.LKarakter;
				for (int j = 0; j < bosluk; j++) {
					cout << " ";
				}
				cout << L.LKarakter;
			}
			else if (i == (L.boyut + 1) / 2 - 1) {//L'nin ortasi
				gotoxy(L.x, L.y + i);
				cout << L.LKarakter;
				for (int j = 0; j < bosluk; j++) {
					cout << " ";
				}
				cout << L.LKarakter;
				for (int j = 0; j < L.boyut - bosluk - 2; j++) {
					cout << L.LKarakter;
				}
			}
			else if (i == L.boyut) {//son satir
				gotoxy(L.x, L.y + i);
				for (int j = 0; j < L.boyut; j++) {
					cout << L.LKarakter;
				}
			}
			else {//L'nin alt kismi
				gotoxy(L.x, L.y + i);
				cout << L.LKarakter;
				for (int j = 0; j < L.boyut - 2; j++) {
					cout << " ";
				}
				cout << L.LKarakter;
			}
		}
	}
	else {//Boyut cift oldugunda
		int bosluk = (L.boyut / 2) - 2;
		for (int i = 0; i < L.boyut + 1; i++) {//Ilk satir
			if (i == 0) {
				gotoxy(L.x, L.y + i);
				for (int j = 0; j < L.boyut / 2; j++) {
					cout << L.LKarakter;
				}
			}
			else if (i > 0 && i < L.boyut / 2) {//L'nin ust kismi
				gotoxy(L.x, L.y + i); cout << L.LKarakter;
				for (int j = 0; j < bosluk; j++) {
					cout << " ";
				}
				cout << L.LKarakter;
			}
			else if (i == L.boyut / 2) {//L'nin ortasi
				if (L.boyut == 2) {//Boyut 2 oldugunda bosluk degiskeninde hata aldim.O yuzden kodunu ayri yazdim.
					gotoxy(L.x, L.y + i);
					for (int j = 0; j < 2; j++) {
						cout << L.LKarakter;
					}
				}
				else {
					gotoxy(L.x, L.y + i);
					cout << L.LKarakter;
					for (int j = 0; j < bosluk; j++) {
						cout << " ";
					}
					cout << L.LKarakter;
					for (int j = 0; j < L.boyut / 2; j++) {
						cout << L.LKarakter;
					}
				}
			}
			else if (i == L.boyut) {//L'nin alt satiri.
				gotoxy(L.x, L.y + i);
				for (int j = 0; j < L.boyut; j++) {
					cout << L.LKarakter;
				}
			}
			else {//L'nin alt kismi.
				gotoxy(L.x, L.y + i);
				cout << L.LKarakter;
				for (int j = 0; j < L.boyut - 2; j++) {
					cout << " ";
				}
				cout << L.LKarakter;
			}
		}
	}
}
LSekli lSekliAsagiGotur(LSekli Le) {
	Le.y++;
	return Le;
}
