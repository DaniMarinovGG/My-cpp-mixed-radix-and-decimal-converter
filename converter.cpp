#include <iostream>
using namespace std;

int main() {
    cout << "Enter number of array dimensions: ";
    int n;
    do {
        cin >> n;
        if (n <= 0){
            cout << "Enter a natural number!: ";
        }
    } while (n <= 0);

    int base[n];
    cout << "Enter the dimenstions (with space pls natural numbers bigger than 1): ";

    for (int i = 0; i < n; i++){
        do {
            cin >> base[i];
            if (base[i] < 2){
                cout << "Are you blind??? read the instruction!!!: ";
            }
        } while (base[i] < 2);
    }

    int choice;

    do {
        cout << "Select what to do: " << endl;
        cout << "1. [...] -> index" << endl;
        cout << "2. index -> [...]" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;
        if (choice == 1){
            int digit[n];
            cout << "Enter " << n << " non-negative integers: ";
            for (int i = 0; i < n; i++){
                do {
                    cin >> digit[i];
                    if (digit[i] >= base[i]){
                        cout << "Please be so kind to enter a non-negative integer smaller than " << base[i] << ": ";
                    }
                } while (digit[i] >= base[i]);
            }
            // most important!!!
            int index = 0, weight = 1;
            for (int i = 0; i < n; i++){
                index += digit[i] * weight;
                weight *= base[i];
            }
            cout << "Index is: " << index << endl << "\n";
        }
        if (choice == 2){
            int index;
            int max_index = 1;
            for (int i = 0; i < n; i++){
                max_index *= base[i];
            }
            do {
                cout << "Enter a non-negative integer smaller than " << max_index << ": ";
                cin >> index;
                if (index >= max_index){
                    cout << "Please follow the instruction!!!" << endl;
                }
            } while (index >= max_index);
            // most important!!!
            int digit[n];
            for (int i = 0; i < n; i++){
                digit[i] = index % base[i];
                index /= base[i];
            }
            // print the array...
            cout << "[";
            for (int i = 0; i < n; i++) {
                if (i != n-1){
                    cout << digit[i] << ",";
                } else {
                    cout << digit[i];
                }
            }
            cout << "]" << endl << "\n";
        }
        if (choice == 3){
            cout << "You exited successfully!" << endl;
            break;
        }
        if (choice != 1 && choice != 2 && choice != 3) {
            cout << "Invalid number!!!" << endl;
        }
    } while (choice != 3);
}
