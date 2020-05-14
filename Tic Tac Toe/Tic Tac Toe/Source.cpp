#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

void goster(char matris[3][3]) {
	cout << right << setw(3) << " ";
	for (int j = 0; j < 3; j++) {
		cout << right << setw(4) << j + 1;
	}
	cout << endl;

	cout << right << setw(3) << " ";
	for (int j = 0; j < 12; j++) {
		cout << "_";
	}
	cout << endl ;
	for (int i = 0; i < 3; i++) {
		cout << endl;
		cout << i + 1 << " |";
		for (int j = 0; j < 3; j++) {
			cout << right << setw(4) << matris[i][j];
		}
		cout << endl << endl;
	}
}

int main() {

	
	string isim1;
	string isim2;
	int o1SecimSatir;
	int o1SecimSutun;
	int o2SecimSatir;
	int o2SecimSutun;
	char secim;

	cout << "Oyuncu1 isim : ";
	cin >> isim1;
	cout << "Oyuncu2 isim : ";
	cin >> isim2;

	do {
		char matris[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };
		
		for (int i = 0; i < 5; i++) {
			system("cls");
			goster(matris);
			
			do {
				cout << isim1 << " sirasi..." << endl;
				cout << "Satir ve Sutunu Girin : ";
				cin >> o1SecimSatir >> o1SecimSutun;
				if (matris[o1SecimSatir - 1][o1SecimSutun - 1] != ' ') {
					cout << "Daha Once Girdiginiz Hucreye Deger Giremezsiniz !" << endl;
					continue;
				}
				else {
					break;
				}
			} while (1);
			matris[o1SecimSatir - 1][o1SecimSutun - 1] = 'x';
			//oyuncu1
			if (matris[0][0] == 'x' & matris[0][1] == 'x' & matris[0][2] == 'x') {
				cout << isim1 << " Kazandi..." << endl;
				goster(matris);
				break;
			}
			if (matris[1][0] == 'x' && matris[1][1] == 'x' && matris[1][2] == 'x') {
				cout << isim1 << " Kazandi..." << endl;
				goster(matris);
				break;
			}
			if (matris[2][0] == 'x' && matris[2][1] == 'x' && matris[2][2] == 'x') {
				cout << isim1 << " Kazandi..." << endl;
				goster(matris);
				break;
			}
			if (matris[0][0] == 'x' && matris[1][1] == 'x' && matris[2][2] == 'x') {
				cout << isim1 << " Kazandi..." << endl;
				goster(matris);
				break;
			}
			if (matris[0][2] == 'x' && matris[1][1] == 'x' && matris[2][0] == 'x') {
				cout << isim1 << " Kazandi..." << endl;
				goster(matris);
				break;
			}
			if (matris[0][0] == 'x' && matris[1][0] == 'x' && matris[2][0] == 'x') {
				cout << isim1 << " Kazandi..." << endl;
				goster(matris);
				break;
			}
			if (matris[0][1] == 'x' && matris[1][1] == 'x' && matris[2][1] == 'x') {
				cout << isim1 << " Kazandi..." << endl;
				goster(matris);
				break;
			}
			if (matris[0][3] == 'x' && matris[1][3] == 'x' && matris[2][3] == 'x') {
				cout << isim1 << " Kazandi..." << endl;
				goster(matris);
				break;
			}
			if (i == 4) {
				cout << "Berabere Bitti..." << endl;
				goster(matris);
				break;
			}
			

			goster(matris);
			
			do {
				cout << isim2 << " sirasi..." << endl;
				cout << "Satir ve Sutunu Girin : ";
				cin >> o2SecimSatir >> o2SecimSutun;
				if (matris[o2SecimSatir - 1][o2SecimSutun - 1] != ' ') {
					cout << "Daha Once Girdiginiz Hucreye Deger Giremezsiniz !" << endl;
					continue;
				}
				else {
					break;
				}
			} while (1);
			matris[o2SecimSatir - 1][o2SecimSutun - 1] = 'o';
			
			
			//oyuncu2
			if (matris[0][0] == 'o' && matris[0][1] == 'o' && matris[0][2] == 'o') {
				cout << isim2 << " Kazandi..." << endl;
				goster(matris);
				break;
			}
			if (matris[1][0] == 'o' && matris[1][1] == 'o' && matris[1][2] == 'o') {
				cout << isim2 << " Kazandi..." << endl;
				goster(matris);
				break;
			}
			if (matris[2][0] == 'o' && matris[2][1] == 'o' && matris[2][2] == 'o') {
				cout << isim2 << " Kazandi..." << endl;
				goster(matris);
				break;
			}
			if (matris[0][0] == 'o' && matris[1][1] == 'o' && matris[2][2] == 'o') {
				cout << isim2 << " Kazandi..." << endl;
				goster(matris);
				break;
			}
			if (matris[0][2] == 'o' && matris[1][1] == 'o' && matris[2][0] == 'o') {
				cout << isim2 << " Kazandi..." << endl;
				goster(matris);
				break;
			}
			if (matris[0][0] == 'o' && matris[1][0] == 'o' && matris[2][0] == 'o') {
				cout << isim2 << " Kazandi..." << endl;
				goster(matris);
				break;
			}
			if (matris[0][1] == 'o' && matris[1][1] == 'o' && matris[2][1] == 'o') {
				cout << isim2 << " Kazandi..." << endl;
				goster(matris);
				break;
			}
			if (matris[0][3] == 'o' && matris[1][3] == 'o' && matris[2][3] == 'o') {
				cout << isim2 << " Kazandi..." << endl;
				goster(matris);
				break;
			}
		}
		cout << "Cikis icin 'c', devam icin herhangi bir tus... " << endl;
		cin >> secim;
		if (secim == 'c' || secim == 'C') {
			cout << "Gule Gule..." << endl;
			return 0;
		}
		else {
			continue;
		}

	} while (1);
	system("pause");
	return 0;
}