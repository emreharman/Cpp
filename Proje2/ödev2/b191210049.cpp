/****************************************************************************
**
**				ÖÐRENCÝ ADI........: EMRE HARMAN
**				ÖÐRENCÝ NUMARASI...: B191210049
**				DERS GRUBU.........: 1B
****************************************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;

void matrisGoster(int, int[][26]);
void menu();

int main() {
	srand(time(0));
	int matris[26][26];//[25][25] yapinca menu4'te hata aldim.O yuzden 26 tanimladim.
	int geciciSatir[25];
	int geciciSutun[25];
	int geciciTek[25];
	int geciciCift[25];
	int boyut=0;
	char menuSecim;
	int satir = 0;
	int sutun = 0;
	int matrisToplam = 0;

	//Matrisin boyutunun 5-25 arasi girilmesini sagliyoruz. 
	do {
		cout << "Matris Boyutu : ";
		cin >> boyut;
		if (boyut < 5 || boyut>25) {
			cout << "Matrisin boyutu 25'ten buyuk, 5'ten kucuk olamaz." << endl;
			continue;
		}
		else {
			break;
		}

	} while (1);

	//Girilen boyut dogrultusunda matrise 1-9 arasi random deger atiyoruz.
	for (int i = 0; i < boyut; i++) {
		for (int j = 0; j < boyut; j++) {
			matris[i][j] = 1+rand() % 9;
		}
	}
	matrisGoster(boyut, matris);
	menu();
	//Menuden gecerli islem secilmesini sagliyoruz.
	do {
		cout << "Seciminiz : ";
		cin >> menuSecim;
		if (menuSecim != '1' && menuSecim != '2' && menuSecim != '3' && menuSecim != '4') {
			cout << "Gecersiz secim yaptiniz!" << endl;
		}
		else{
			break;
		}
	} while (1);
	
	switch (menuSecim) {
	case '1':
		//Matrisin boyutlari arasinda satir ve sutun degeri aliyoruz.
		do {
			cout << "Satir Sutun : ";
			cin >> satir >> sutun;
			
			if (satir > boyut || sutun > boyut) {
				cout << "Satir ve sutun matrisin boyutundan buyuk olamaz!" << endl;
				matrisGoster(boyut,matris);
				menu();
			}
			
			else {
				//Secilen satir ve sutunu gecici satir ve sutuna atiyoruz.
				for (int j = 0; j < boyut; j++) {
						geciciSatir[j] = matris[satir-1][j];
						geciciSutun[j] = matris[j][sutun - 1];
				}
				//satir ve sutunlarin yerlerini degistiriyoruz.
				for (int j = 0; j < boyut; j++) {
						
						matris[j][sutun - 1] = geciciSatir[j];
						matris[satir - 1][j] = geciciSutun[j];						
				}
				//Kesisim noktalarini topluyoruz.
				matris[satir - 1][sutun - 1] = geciciSatir[satir - 1] + geciciSutun[sutun - 1];
				matrisGoster(boyut, matris);
				break;
			}
		} while (1);
		break;
	case '2':
		do {
			cout << "Satir : ";
			cin >> satir;
			if (satir > boyut) {
				cout << "Satir degeri matrisin boyutundan buyuk olamaz!" << endl;
				matrisGoster(boyut, matris);
				menu();
			}
			else {
				int tek = 0;
				int cift = 0;
				//secilen satirdaki tek sayilari gecici bir diziye,cift sayilari baska bir gecici diziye atiyoruz.
				for (int i = 0; i < boyut; i++) {
					if (matris[satir - 1][i] % 2 == 1) {
						geciciTek[tek] = matris[satir - 1][i];
						tek++;
					}
					else {
						geciciCift[cift] = matris[satir - 1][i];
						cift++;
					}
				}
				//Tek sayilari matristeki ilgili satirin basina atiyoruz.
				for (int i = 0; i < tek; i++) {
					matris[satir - 1][i] = geciciTek[i];
				}
				//Cift sayilari matriste tek sayilardan itibaren satirin sonuna atiyoruz.
				for (int i = 0; i < cift; i++) {
					matris[satir - 1][tek+i] = geciciCift[i];
				}
				matrisGoster(boyut, matris);
				break;
			}
		} while (1);
		break;
	case '3':
		do {
			cout << "Sutun : ";
			cin >> sutun;
			if (satir > boyut) {
				cout << "Sutun degeri matrisin boyutundan buyuk olamaz!" << endl;
				matrisGoster(boyut, matris);
				menu();
			}
			else {
				//Secilen sutunu gecici bir diziye atiyoruz.
				for (int i = 0; i < boyut; i++) {
					geciciSutun[i] = matris[i][sutun - 1];
				}
				int satirSayac = 0;
				//Gecici dizideki degerleri sondan itibaren matrisin ilgili sutununa atiyoruz.
				for (int j = boyut - 1; j >= 0; j--) {
					matris[satirSayac][sutun - 1] = geciciSutun[j];
					satirSayac++;
				}
			}
			matrisGoster(boyut, matris);
			break;
		} while (1);
		break;
	case '4':
		//Matrisin icerisindeki degerleri topluyoruz.
		for (int i = 0; i < boyut; i++) {
			for (int j = 0; j < boyut; j++) {
				matrisToplam += matris[i][j];
			}
		}
		//Matrisin ilk elemanina kendisini cikararak toplam degerini atiyoruz.
		matris[0][0] = matrisToplam-matris[0][0];
		//Bir sonraki degeri toplamdan cikararak ilgili matris elemanina atiyoruz.
		for (int i = 0; i < boyut; i++) {
			for (int j = 0; j < boyut; j++) {
				matris[i][j+1] = matris[i][j] - matris[i][j + 1];
				matrisToplam = matris[i][j];
			}
			//satirin sonundaki toplam degerini alt satirin ilk degerine kendisini cikararak atiyoruz.
			matris[i+1][0] = matrisToplam - matris[i+1][0];
		}
		matrisGoster(boyut, matris);
		break;
	default:
		break;
	}
	system("pause");
	return 0;
}
void matrisGoster(int boyut, int matris[][26]) {
	cout << right << setw(3) << " ";
	for (int j = 0; j < boyut; j++) {
		cout << right << setw(5) << j + 1;
	}
	cout << endl;

	cout << right << setw(3) << " ";
	for (int j = 0; j < boyut * 5; j++) {
		cout << "_";
	}
	cout << endl << endl;
	for (int i = 0; i < boyut; i++) {
		cout << endl;
		cout << i + 1 << " |";
		for (int j = 0; j < boyut; j++) {
			cout << right << setw(5) << matris[i][j];
		}
		cout << endl << endl;
	}
}
void menu() {
	cout << "1.Sutun Satir Degistir\n2.Tekleri Basa Al (Satir)\n3.Ters Cevir (Sutun)\n4.Toplamlari Yazdir\n";
}