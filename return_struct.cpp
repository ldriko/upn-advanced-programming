#include <iostream>

using namespace std;

struct Mahasiswa
{
    long long npm;
    string name;
    int birthYear;
};

Mahasiswa buildMahasiswa(long long npm, string name, int birthYear)
{
    Mahasiswa mhs;

    mhs.npm = npm;
    mhs.name = name;
    mhs.birthYear = birthYear;

    return mhs;
}

void printMahasiswa(Mahasiswa mhs)
{
    cout << "NPM: " << mhs.npm << endl;
    cout << "Name: " << mhs.name << endl;
    cout << "Age: " << 2023 - mhs.birthYear << endl;
}

int main()
{
    Mahasiswa mhs = buildMahasiswa(22081010158, "Heaven Aldrico", 2003);

    printMahasiswa(mhs);

    return 0;
}