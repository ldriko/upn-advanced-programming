#include <iostream>

using namespace std;

struct Employee
{
    int number;
    string name;
    int birthYear;
    unsigned long hourlySalary;
};

int showMenu()
{
    int menu;

    cout << "Menu: " << endl;
    cout << "1. Tampilkan data semua pegawai" << endl;
    cout << "2. Tampilkan data pegawai berdasarkan usia diatas" << endl;
    cout << "3. Tampilkan data pegawai berdasarkan usia dibawah" << endl;
    cout << "4. Ubah data pegawai" << endl;
    cout << "5. Hapus data pegawai" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilih menu: ";
    cin >> menu;
    cout << endl;

    return menu;
}

void setEmployee(Employee *employee, int i)
{
    cout << i + 1 << ". Nomor: ";
    cin >> employee->number;

    cout << "   Nama: ";
    cin.ignore();
    getline(cin >> ws, employee->name);

    cout << "   Tahun lahir: ";
    cin >> employee->birthYear;

    cout << "   Gaji/jam: ";
    cin >> employee->hourlySalary;
}

void showEmployees(Employee employees[], int count)
{
    cout << "Data semua pegawai: " << endl;

    for (int i = 0; i < count; i++)
    {
        int age = 2023 - employees[i].birthYear;
        int monthlySalary = employees[i].hourlySalary * 8 * 5;

        cout << i + 1 << ". No: " << employees[i].number << endl;
        cout << "   Nama: " << employees[i].name << endl;
        cout << "   Usia: " << age << endl;
        cout << "   Gaji/bulan: " << monthlySalary << endl;
        cout << endl;
    }
}

void showEmployeesByAge(Employee employees[], int count, bool over)
{
    int ageFilter;
    string desc = over ? "diatas" : "dibawah";
    cout << "Data pegawai berdasarkan umur " << desc << ": ";
    cin >> ageFilter;

    for (int i = 0; i < count; i++)
    {
        int age = 2023 - employees[i].birthYear;

        if (over && age <= ageFilter)
            continue;
        else if (!over && age >= ageFilter)
            continue;

        int monthlySalary = employees[i].hourlySalary * 8 * 5;

        cout << i + 1 << ". No: " << employees[i].number << endl;
        cout << "   Nama: " << employees[i].name << endl;
        cout << "   Usia: " << age << endl;
        cout << "   Gaji/bulan: " << monthlySalary << endl;
        cout << endl;
    }
}

void updateEmployee(Employee employee[])
{
    cout << "Data semua pegawai";
}

int main()
{
    int count;

    cout << "Masukkan jumlah pegawai: ";
    cin >> count;
    cout << endl;

    Employee employees[count];

    for (int i = 0; i < count; i++)
    {
        setEmployee(&employees[i], i);
        cout << endl;
    }

    bool isRunning = true;

    while (isRunning)
    {
        int menu = showMenu();

        if (menu == 1)
            showEmployees(employees, count);
        else if (menu == 2)
            showEmployeesByAge(employees, count, true);
        else if (menu == 3)
            showEmployeesByAge(employees, count, false);
        else if (menu == 4)
        {
            int number;

            cout << "Masukkan nomor pegawai yang ingin diubah: ";
            cin >> number;
        }
        else if (menu == 6)
            isRunning = false;
        else
            cout << "Menu tidak tersedia!" << endl;
    }

    return 0;
}