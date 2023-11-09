#include <iostream>

using namespace std;

void find(string text, string keyword)
{
    size_t pos = text.find(keyword);
    if (pos != string::npos)
    {
        cout << "Kata \"" << keyword << "\" ditemukan pada posisi " << static_cast<int>(pos) << endl;
    }
    else
    {
        cout << "Kata \"" << keyword << "\" tidak ditemukan" << endl;
    }
}

int main()
{
    string text = "Dennis MacAlistair Ritchie (9 September 1941 - 12 Oktober 2011) adalah seorang ilmuwan komputer yang dikenal atas sumbangsihnya membuat bahasa pemrograman C dan berbagai sistem operasi seperti Multics dan Unix. Ritchie menerima penghargaan Turing Award pada tahun 1983 dan National Medal of Technology 1998 pada 21 April 1999. Ia menjabat sebagai kepala Departemen Riset Perangkat lunak Sistem di Lucent Technologies saat pensiun pada tahun 2007. Ritchie dikenal sebagai pembuat bahasa pemrograman C, pengembang utama sistem operasi, dan sebagai salah satu dari penulis (bersama Brian Kernighan) buku Kamus Bahasa C, The C Programming Language. Penemuan bahasa C dan pengembangan Unix menjadikan Ritchie dan Ken Thompson sebagai pionir utama dunia komputasi modern. Bahasa C hingga kini masih digunakan secara luas dalam program aplikasi, sistem operasi, pengembangan sistem benam, dan pengaruhnya dalam bahasa pemrograman modern lain. Sedangkan Unix juga telah memberikan pengaruh besar, membangun konsep dan prinsip dalam dunia komputasi masa kini";
    string keyword;

    cout << "Masukkan keyword: ";
    cin >> keyword;

    find(text, keyword);

    return 0;
}
