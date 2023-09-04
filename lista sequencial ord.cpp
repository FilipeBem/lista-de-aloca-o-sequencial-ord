#include <iostream>
using namespace std;
void menu();
int n = 0;
const int MAX = 100;

void buscaOrdenada(int arr[], int n, int value) {
    int i = 0;
    while (i < n && arr[i] < value) {
        i++;
    }
    if (i < n && arr[i] == value) {
        cout << "O valor " << value << " foi encontrado na posição " << i << endl;
    } else {
        cout << "O valor " << value << " não foi encontrado na lista" << endl;
    }
}

void insertSorted(int arr[], int& n, int value) {
    int i = n - 1;
    while (i >= 0 && arr[i] > value) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = value;
    n++;
}

void remove(int arr[], int& n, int value) {
    int i = 0;
    while (i < n && arr[i] != value) {
        i++;
    }
    if (i < n) {
        for (int j = i; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        n--;
        cout << "O valor " << value << " foi removido da lista" << endl;
    } else {
        cout << "O valor " << value << " nao foi encontrado na lista" << endl;
    }
}

void display(int arr[], int& n ){
    if (n == 0)
       cout << "empty list";
    if (n != 0)
       cout << "List = ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int total(){
   return n;
}

void clear(){
    system("cls");
    menu();
}

int main() {
    int arr[MAX];
    int n = 0;
    int opcao, valor;
    menu();
    do {

        cout << "selecione sua opecao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o valor a ser buscado: ";
                cin >> valor;
                buscaOrdenada(arr, n, valor);
                break;
            case 2:
                cout << "Digite o valor a ser inserido: ";
                cin >> valor;
                insertSorted(arr, n, valor);
                cout << "O valor " << valor << " foi inserido na lista" << endl;
                break;
            case 3:
                cout << "Digite o valor a ser removido: ";
                cin >> valor;
                remove(arr, n, valor);
                break;
            case 4: 
                display(arr, n);
                break;  
            case 5: 
                total();
                cout << "Total = " << n << endl;
                break;    
            case 6: 
                clear();
                break;           
            case 7:
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                cout << "Opcao inválida" << endl;
                break;
        }
    } while (opcao != 7);

    return 0;
}

void menu(){
    cout << "Escolha uma opcao:" << endl;
        cout << "1 - Busca ordenada" << endl;
        cout << "2 - Inserir ordenada" << endl;
        cout << "3 - Remover" << endl;
        cout << "4 - display" << endl;
        cout << "5 - Total" << endl;
        cout << "6 - clear" << endl;
        cout << "7 - Sair" << endl; 
}