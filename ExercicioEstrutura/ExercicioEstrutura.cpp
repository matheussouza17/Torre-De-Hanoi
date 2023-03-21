#include <string>
#include <iostream>
#include <cmath>
#include <locale.h>;
using namespace std;

int tam=21;
int* torreA = new int[tam];
int* torreB = new int[tam];
int* torreC = new int[tam];
int topA = -1;
int topB = -1;
int topC = -1;

//Preencher torres de inicio
void preencheTorres() {

    for (int i = 0, j=tam; i <tam; i++,j--) *(torreA + i) = j;
   
    for (int i = 0; i < tam; i++) {
        torreB[i] = 0;
        torreC[i] = 0;
    }

}

//PUSH e POP
int PUSH_POP(char origem,char destino) {
    if (origem == 'A') {
        if (destino == 'B') {
            topB++;
            torreB[topB] = torreA[topA];
            torreA[topA] = 0;
            topA--;
            
        }
        else {
            topC++;
            torreC[topC] = torreA[topA];
            torreA[topA] = 0;
            topA--;
            
        }
    }
    else if (origem == 'B') {
        if (destino == 'A') {
            topA++;
            torreA[topA] = torreB[topB];
            torreB[topB] = 0;
            topB--;
            
        }
        else {
            topC++;
            torreC[topC] = torreB[topB];
            torreB[topB] = 0;
            topB--;
            
        }
    }
    else {
        if (destino == 'B') {
            topB++;
            torreB[topB] = torreC[topC];
            torreC[topC] = 0;
            topC--;
            
        }
        else {
            topA++;
            torreA[topA] = torreC[topC];
            torreC[topC] = 0;
            topC--;
            
        }
    }

    return 0;
}//PUSH e POP

//Validações das torres
void trocaTorres(char origem, char destino) { //Validações
    setlocale(LC_ALL, "pt_BR.utf8");
    if (origem == 'A'&&topA!=-1) {
        if (destino == 'B') {
            if (torreA[topA] < torreB[topB]||topB==-1) {
                PUSH_POP(origem, destino);
            }
            else {
                cout << "ATENCAO, VALOR DE ORIGEM TEM QUE SER MENOR QUE DESTINO!" << endl;
            }
       }
        else if (destino == 'C') {
            if (torreA[topA] < torreC[topC] || topC == -1) {
                PUSH_POP(origem, destino);
            }
            else {
                cout << "ATENCAO, VALOR DE ORIGEM TEM QUE SER MENOR QUE DESTINO!" << endl;
            }
        }
        else {
            cout << "DIGITE VALOR DE DESTINO VALIDO!" << endl;
        }
    }
    else if (origem == 'B' && topB != -1) {
        if (destino == 'A') {
            if (torreB[topB] < torreA[topA] || topA == -1) {
                PUSH_POP(origem, destino);
            }
            else {
                cout << "ATENCAO, VALOR DE ORIGEM TEM QUE SER MENOR QUE DESTINO!" <<endl;
            }
        }
        else if(destino=='C') {
            if (torreB[topB] < torreC[topC] || topC == -1) {
                PUSH_POP(origem, destino);
            }
            else {
                cout << "ATENCAO, VALOR DE ORIGEM TEM QUE SER MENOR QUE DESTINO!" << endl;
            }
        }
        else {
            cout << "DIGITE VALOR DE DESTINO VALIDO!" << endl;
        }
            
    }
    else if (origem == 'C' && topC != -1) {
        if (destino == 'B') {
            if (torreC[topC] < torreB[topB] || topB == -1) {
                PUSH_POP(origem, destino);
            }
            else {
                cout << "ATENCAO, VALOR DE ORIGEM TEM QUE SER MENOR QUE DESTINO!" << endl;
            }
        }
        else if (destino == 'A') {
            if (torreC[topC] < torreA[topA] || topA == -1) {
                PUSH_POP(origem, destino);
            }
            else {
                cout << "ATENCAO, VALOR DE ORIGEM TEM QUE SER MENOR QUE DESTINO!" << endl;
            }
        }
    else {
        cout << "DIGITE VALOR DE DESTINO VALIDO!" << endl;
    }
    }
    else {
        cout << "DIGITE UM VALOR DE ORIGEM VALIDO! " << endl;
    }
}//Validações

//Verifica se concluiu a Torre
bool verificaEnd() {
    if (topC == tam-1) return true;
    return false;
}

//Imprime torres
void printTorres() {
    
    cout << "TORRES: \n";
    for (int i = tam-1; i >=0; i--) {
        cout <<endl<<"  "<< torreA[i] << "\t";
        cout << "  " << torreB[i] << "\t";
        cout << "  " << torreC[i] << "\t\n";
    }
    printf("TORRE A\tTORRE B\tTORRE C\n\n");
}

int main() {
    int cont = 0;
    setlocale(LC_ALL, "pt_BR.utf8");
    cout << "\tBem vindo(a)!\n";
    while (tam < 3 || tam>20) {
        cout << "Digite tamanho das torres(3 - 20): \n";
        cin >> tam;
    }    
    topA = tam-1;
    preencheTorres();
    bool isEnd=false;
    bool sair=false;
    printTorres();
    while (isEnd == false && sair==false) {
        char origem='A', destino='B';
        printf("Digite a torre de origem:\n");
        cin >> origem;

        printf("Digite a torre de destino: \nOu digite 'S' para sair\n");
        cin >> destino;

        if (toupper(destino) == 'S')
            sair = true;
        else {
            system ("cls");
            origem = toupper(origem);
            destino = toupper(destino);
            trocaTorres(origem, destino);
            isEnd = verificaEnd();
            printTorres();
        }
        cont++;
    }
    if (isEnd == true)cout << "\tVOCE GANHOU em "<<cont<<" jogadas\n\tPARABENS!\n";
    cout << "Developed by Matheus Henrique Souza\n\n";
    delete torreA;
    delete torreB;
    delete torreC;
    return 0;
}