#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
int main() {
    setlocale(LC_ALL, "Ru");
    int size;
    cout << "������� ������ �������: ";
    cin >> size;

    vector<int> myVector(size);
    srand(time(0));

    cout << "���������� ������� ���������� �������:" << endl;
    for (int i = 0; i < size; i++) {
        myVector[i] = rand();
        cout << myVector[i] << " ";
    }
    cout << endl;

    cout << "������ � �������� �������:" << endl;
    for (int i = size - 1; i >= 0; i--) {
        cout << myVector[i] << " ";
    }
    cout << endl;

    return 0;
}