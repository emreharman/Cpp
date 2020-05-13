/****************************************************************************
**																		   	
**				ÖÐRENCÝ ADI.......: Emre Harman							   	
**				ÖÐRENCÝ NUMARASI..: b191210049							   
**				DERS GRUBU........: B1									   	
****************************************************************************/
#include<iostream>
#include<Windows.h>
#include<iomanip>

using namespace std;

int main() {
	int satir = 0;
	int sutun = 0;
	int bosluk1 = 0;
	int bosluk2 = 0;
	
	do {
		//satir sayisi 5-15 arasinda olana kadar satir sayisi giriliyor.
		do {
			cout << "Satir Sayisi...: ";
			cin >> satir;
			if (satir < 5 || satir > 15) {
				cout << "Satir numarasi hatali... Tekrar deneyin..." << endl;
				continue;
			}
			else {
				break;
			}
		} while (1);

		//sutun sayisi 5-40 arasinda olana kadar sutun sayisi giriliyor.
		do {
			cout << "Sutun Sayisi...: ";
			cin >> sutun;
			if (sutun < 5 || sutun > 40) {
				cout << "Sutun numarasi hatali... Tekrar deneyin..." << endl;
				continue;
			}
			else {
				break;
			}
		} while (1);
		
		//sutun sayisi satir sayisinin 2 kati degilse donguye bastan basliyor
		//2 katiysa donguden cikiyor.
		if (sutun / 2 != satir) {
			cout << "Sutun sayisi satir sayisinin iki kati olmalidir... Tekrar deneyin..." << endl;
			continue;
		}
		else {
			break;
		}
	} while (1);
	
	bosluk1 = (sutun / 2)-2;
	bosluk2 = 3;
	
	//satir sayisi kadar seklin ust kismina islem yapiyoruz.
	for (int i = 0; i < satir; i++) {
		//seklin ilk ve son satirina sutun sayisi kadar '*' koyuyoruz.
		if (i == 0 || i == satir - 1) {
			for (int j = 0; j < sutun; j++) {
				cout << "*";
			}
		}
		//ilk ve son satir disindaki satirlara kenardaki '*'lari ve seklin ortasindaki 
		//ucgen seklindeki '*'lari koyuyoruz.
		else {
			cout << "*" << setw(bosluk1) << "*" << setw(bosluk2) <<  "*" << setw(bosluk1)  << "*";
			bosluk1--;
			bosluk2 += 2;	
		}
		Sleep(100);
		cout << endl;
	}

	bosluk1 = 1;
	bosluk2 = sutun - 3;

	//seklin ust kisminda yaptigimiz islemleri tersten uygulayarak alt kisimdaki sekli ciziyoruz.
	for (int i = 0; i < satir; i++) {
		if (i == 0 || i == satir - 1) {
			for (int j = 0; j < sutun; j++) {
				cout << "*";
			}
		}
		else {
			cout << "*" << setw(bosluk1) << "*" << setw(bosluk2) << "*" << setw(bosluk1) << "*";
			bosluk1++;
			bosluk2 -= 2;
		}
		Sleep(100);
		cout << endl;
	}
	system("pause");
	return 0;
}
