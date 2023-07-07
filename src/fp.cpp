#include <iostream>
#include <stack>
using namespace std;

const int MAX_STACK_SIZE = 100;
struct Book
{
    string judul;
    string penulis;
    string kategori;
    string dipinjamOleh;
    int isbn;
    int tahun;
};

struct Member
{
    string username;
    string password;
    bool admin;
};

Member anggota[100];
stack<Book> bukuStack; // Menggunakan stack STL

void defaultAdmin(string username, string password, bool admin);
void login();
void createAccountMember();
void createAccountAdmin();
void loginScreen();
void dasboardMember();
void dasboardAdmin();
void daftarBuku();
void pinjamBuku();
void kembalikanBuku();
void informasiAkun();
void statistikBuku();
void managementBuku();
void urutISBN();
void urutKategori();
void jumlahBukuTersedia();
void daftarBukuDipinjam();
void tambahBuku();
void hapusBuku();
void sortingBuku();

// fungsi untuk mengisi data default admin pada array anggota index ke 0
// parameter: username, password, admin
void defaultAdmin(string username, string password, bool admin)
{
    anggota[0].username = username;
    anggota[0].password = password;
    anggota[0].admin = admin;
}

void login()
{
    system("cls");
    string username, password;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;
    for (int i = 0; i < 100; i++)
    {
        if (username == anggota[i].username && password == anggota[i].password)
        {
            if (anggota[i].admin == true)
            {
                dasboardAdmin();
            }
            else
            {
                dasboardMember();
            }
        }
    }
    cout << "Username atau password salah" << endl;
    loginScreen();
}

// fungsi untuk membuat akun member baru pada array anggota
void createAccountMember()
{
    system("cls");

    // deklarasi variabel username dan password
    string username, password;

    // input username
    cout << "Masukkan username: ";
    cin >> username;

    // perulangan untuk mengecek apakah username sudah terdaftar atau belum
    for (int i = 0; i < 100; i++)
    {
        if (username == anggota[i].username)
        {
            cout << "Username sudah terdaftar" << endl;
            break;
        }
    }

    // input password
    cout << "Masukkan password: ";
    cin >> password;

    // perulangan untuk mengecek apakah array anggota index ke i kosong atau tidak
    // perulangan untuk menimpan data username dan password pada array anggota
    for (int i = 0; i < 100; i++)
    {
        if (anggota[i].username == "")
        {
            // menyimpan data username dan password pada array anggota
            anggota[i].username = username;
            anggota[i].password = password;
            anggota[i].admin = false;
            cout << "Akun berhasil dibuat" << endl;
            dasboardMember();
            break;
        }
    }
}

// fungsi untuk membuat akun admin baru pada array anggota
void createAccountAdmin()
{
    system("cls");

    // deklarasi variabel username dan password
    string username, password;

    // input username
    cout << "Masukkan username: ";
    cin >> username;

    // perulangan untuk mengecek apakah username sudah terdaftar atau belum
    for (int i = 0; i < 100; i++)
    {
        if (username == anggota[i].username)
        {
            cout << "Username sudah terdaftar" << endl;
            createAccountAdmin();
        }
    }

    // input password
    cout << "Masukkan password: ";
    cin >> password;

    // perulangan untuk menimpan data username dan password pada array anggota
    // perulangan untuk mengecek apakah array anggota index ke i kosong atau tidak
    for (int i = 0; i < 100; i++)
    {
        if (anggota[i].username == "")
        {
            // menyimpan data username dan password pada array anggota
            anggota[i].username = username;
            anggota[i].password = password;
            anggota[i].admin = true;
            cout << "Akun berhasil dibuat" << endl;
            dasboardAdmin();
            break;
        }
    }
}

void loginScreen()
{
    system("cls");
    int pilihan;
    cout << "1. Masuk" << endl;
    cout << "2. Daftar" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();
    switch (pilihan)
    {
        {
        case 1:
            login();
            break;
        case 2:
            createAccountMember();
            break;
        default:
            break;
        }
    }
}

// fungsi untuk menampilkan dasboard member setelah login
void dasboardMember()
{
    system("cls");
    int pilihan;
    cout << "Selamat Datang " << endl;
    cout << "1. Daftar Buku" << endl;
    cout << "2. Pinjam Buku" << endl;
    cout << "3. Kembalikan Buku" << endl;
    cout << "4. Informasi Akun" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();
    switch (pilihan)
    {
        {
        case 1:
            daftarBuku();
            break;
        case 2:
            pinjamBuku();
            break;
        case 3:
            kembalikanBuku();
            break;
        case 4:
            informasiAkun();
            break;
        case 5:
            loginScreen();
            break;
        default:
            cout << "Pilihan tidak tersedia" << endl;
            break;
        }
    }
}

void dasboardAdmin()
{
    system("cls");
    int pilihan;
    cout << "Selamat Datang " << endl;
    cout << "1. Daftar Buku" << endl;
    cout << "2. Kelola Buku" << endl;
    cout << "3. Statistik Buku" << endl;
    cout << "4. Tambah Admin Baru" << endl;
    cout << "5. Keluar Aplikasi" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();
    switch (pilihan)
    {
        {
        case 1:
            daftarBuku();
            break;
        case 2:
            managementBuku();
            break;
        case 3:
            statistikBuku();
            break;
        case 4:
            createAccountAdmin();
            break;
        case 5:
            loginScreen();
            break;
        default:
            cout << "Pilihan tidak tersedia" << endl;
            break;
        }
    }
}

void managementBuku()
{
    system("cls");
    int pilihan;
    cout << "Kelola Buku" << endl;
    cout << "1. Tambah Buku" << endl;
    cout << "2. Hapus Buku" << endl;
    cout << "3. Kembali" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();
    switch (pilihan)
    {
        {
        case 1:
            tambahBuku();
            break;
        case 2:
            hapusBuku();
            break;
        case 3:
            dasboardAdmin();
            break;
        default:
            cout << "Pilihan tidak tersedia" << endl;
            break;
        }
    }
}

void jumlahBukuTersedia()
{
}

void daftarBukuDipinjam()
{
}
void tambahBuku()
{
    if (bukuStack.size() == MAX_STACK_SIZE)
    {
        cout << "Stack penuh. Tidak dapat menambahkan buku." << endl;
        system("pause");
        if (anggota[0].admin)
        {
            managementBuku();
        }
        else
        {
            dasboardMember();
        }
    }
    else
    {
        Book buku;
        cin.ignore(); // membersihkan newline sebelumnya
        cout << "Masukkan judul buku: ";
        getline(cin, buku.judul);

        cout << "Masukkan penulis buku: ";
        getline(cin, buku.penulis);

        cout << "Masukkan kategori buku: ";
        getline(cin, buku.kategori);

        cout << "Masukkan ISBN buku: ";
        cin >> buku.isbn;
        cin.ignore(); // membersihkan newline

        cout << "Masukkan tahun terbit buku: ";
        cin >> buku.tahun;

        bukuStack.push(buku);
        cout << "Buku berhasil ditambahkan ke dalam stack." << endl;
        system("pause");
        if (anggota[0].admin)
        {
            managementBuku();
        }
        else
        {
            dasboardMember();
        }
    }
}
void hapusBuku()
{
}
void urutKategori()
{
}
void urutISBN()
{
}

void daftarBuku()
{
    system("cls");
    cout << "Daftar Buku" << endl;

    if (bukuStack.empty())
    {
        cout << "Tidak ada buku yang tersedia." << endl;
    }
    else
    {
        stack<Book> tempStack; // Stack sementara untuk mengembalikan buku-buku ke stack asli dengan urutan semula

        while (!bukuStack.empty())
        {
            Book buku = bukuStack.top();
            bukuStack.pop();
            tempStack.push(buku);
            cout << "============================================" << endl;
            cout << "Judul: " << buku.judul << endl;
            cout << "Penulis: " << buku.penulis << endl;
            cout << "Kategori: " << buku.kategori << endl;
            cout << "ISBN: " << buku.isbn << endl;
            cout << "Tahun Terbit: " << buku.tahun << endl;
            cout << "============================================" << endl;
        }

        while (!tempStack.empty())
        {
            Book buku = tempStack.top();
            tempStack.pop();
            bukuStack.push(buku);
        }
    }
    system("pause");

    if (anggota[0].admin)
    {
        dasboardAdmin();
    }
    else
    {
        dasboardMember();
    }
}
void pinjamBuku()
{
}

void kembalikanBuku()
{
}

void informasiAkun()
{
}
void statistikBuku()
{
    system("cls");
    int pilihan;
    cout << "1. Jumlah Buku Tersedia" << endl;
    cout << "2. Daftar Buku Dipinjam" << endl;
    cout << "3. Kembali" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;
    cin.ignore();
    switch (pilihan)
    {
        {
        case 1:
            jumlahBukuTersedia();
            break;
        case 2:
            daftarBukuDipinjam();
            break;
        case 3:
            dasboardAdmin();
            break;
        default:
            cout << "Pilihan tidak tersedia" << endl;
            break;
        }
    }
}

void sortingBuku()
{
    system("cls");
    int pilMenu;
    cout << "MengurutkanDaftar Buku" << endl;
    cout << "1. Berdasarkan Kategori " << endl;
    cout << "2. Berdasarkan ISBN " << endl;
    cout << "3. Kembali " << endl;
    cout << "\nPilihan : ";
    cin >> pilMenu;
    cin.ignore();
    switch (pilMenu)
    {
    case 1:
        urutKategori();
        break;
    case 2:
        urutISBN();
        break;
    case 3:
        dasboardAdmin();
        break;
    default:
        cout << "Pilihan tidak tersedia" << endl;
        break;
    }
}

int main()
{
    defaultAdmin("admin", "admin", true);
    loginScreen();
    return 0;
}
