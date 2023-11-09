#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct Mahasiswa
{
    string npm;
    string name;
    string study;
    string gpa;
};

void showTitle()
{
    system("cls");

    cout << "Manajemen Mahasiswa"
         << endl
         << endl;
}

void showMahasiswa(Mahasiswa data[], int n)
{
    cout << setw(15) << left << "NPM";
    cout << setw(15) << left << "Nama";
    cout << setw(20) << left << "Jurusan";
    cout << setw(3) << left << "IPK";
    cout << endl;
    cout << "------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << setw(15) << left << data[i].npm;
        cout << setw(15) << left << data[i].name;
        cout << setw(20) << left << data[i].study;
        cout << setw(15) << left << data[i].gpa;
        cout << endl;
    }
}

void insertMahasiswa(Mahasiswa data[], int n)
{
    for (int i = 0; i < n; i++)
    {
        showTitle();

        if (i > 0)
        {
            showMahasiswa(data, i);
            cout << endl;
        }

        cout << "Masukkan mahasiswa ke-" << i + 1 << endl;
        cout << "NPM: ";
        cin >> data[i].npm;
        cout << "Nama: ";
        cin >> data[i].name;
        cout << "Jurusan: ";
        cin >> data[i].study;
        cout << "IPK: ";
        cin >> data[i].gpa;
    }
}

char showMenu(Mahasiswa data[], int i)
{
    showTitle();
    showMahasiswa(data, i);

    cout << endl;

    char menu;

    cout << "Menu:" << endl;
    cout << "1. Urutkan data" << endl;
    cout << "2. Acak data" << endl;
    cout << "q. Keluar" << endl;
    cout << endl;
    cout << "Pilih menu: ";
    cin >> menu;

    return menu;
}

void swapMahasiswa(Mahasiswa *a, Mahasiswa *b)
{
    Mahasiswa temp = *a;
    *a = *b;
    *b = temp;
}

string getAttributeValue(Mahasiswa mahasiswa, int attribute)
{
    if (attribute == 1)
        return mahasiswa.npm;
    else if (attribute == 2)
        return mahasiswa.name;
    else if (attribute == 3)
        return mahasiswa.study;
    else if (attribute == 4)
        return mahasiswa.gpa;
    else
        return "";
}

void wait()
{
    cout << "Tekan enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void bubbleSortMahasiswa(Mahasiswa data[], int n, int attribute, bool asc = true)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            string first = getAttributeValue(data[j], attribute);
            string second = getAttributeValue(data[j + 1], attribute);

            if (asc && first.compare(second) > 0)
            {
                swapMahasiswa(&data[j], &data[j + 1]);
                swapped = true;
            }
            else if (!asc && first.compare(second) < 0)
            {
                swapMahasiswa(&data[j], &data[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

void selectionSortMahasiswa(Mahasiswa data[], int n, int attribute, bool asc = true)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            string first = getAttributeValue(data[j], attribute);
            string second = getAttributeValue(data[min], attribute);

            if (asc && first.compare(second) < 0)
                min = j;
            else if (!asc && first.compare(second) > 0)
                min = j;
        }

        if (min != i)
            swapMahasiswa(&data[i], &data[min]);
    }
}

void sortMahasiswa(Mahasiswa data[], int n)
{
    showTitle();
    showMahasiswa(data, n);

    cout << endl;

    char attribute;

    cout << "Urutkan mahasiswa berdasarkan:" << endl;
    cout << "1. NPM" << endl;
    cout << "2. Nama" << endl;
    cout << "3. Jurusan" << endl;
    cout << "4. IPK" << endl;
    cout << "q. Kembali" << endl;
    cout << endl;
    cout << "Pilih atribut: ";
    cin >> attribute;

    if (attribute == 'q')
        return;

    showTitle();
    showMahasiswa(data, n);

    cout << endl;

    char method;

    cout << "Metode pengurutan:" << endl;
    cout << "1. Bubble sort" << endl;
    cout << "2. Selection sort" << endl;
    cout << "q. Kembali" << endl;
    cout << endl;
    cout << "Pilih metode: ";
    cin >> method;

    if (method == 'q')
        return;

    showTitle();
    showMahasiswa(data, n);

    cout << endl;

    char order;

    cout << "Urutan pengurutan:" << endl;
    cout << "1. Ascending" << endl;
    cout << "2. Descending" << endl;
    cout << "q. Kembali" << endl;
    cout << endl;
    cout << "Pilih urutan: ";
    cin >> order;

    if (order == 'q')
        return;

    bubbleSortMahasiswa(data, n, attribute - '0', order == '1' ? true : false);
}

void shuffleMahasiswa(Mahasiswa data[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int random = rand() % n;

        Mahasiswa temp = data[i];
        data[i] = data[random];
        data[random] = temp;
    }
}

int main()
{
    showTitle();

    int n;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    Mahasiswa data[4];

    insertMahasiswa(data, n);

    char menu;

    while (menu != 'q')
    {
        menu = showMenu(data, n);

        if (menu == '1')
            sortMahasiswa(data, n);
        else if (menu == '2')
            shuffleMahasiswa(data, n);
        else if (menu == 'q')
            system("cls");
        else
        {
            cout << "Menu tidak tersedia" << endl;
            wait();
        }
    }
}