#include <iostream>
#include <string>
using namespace std;

// Struct untuk menyimpan informasi tentang paket perjalanan
struct datatrip
{
    string nama;
    string deskripsi;
    int harga;
};

// Struct untuk menyimpan informasi tentang jenis perjalanan
struct jenistrip
{
    string nama;
    datatrip paket[3]; // Array untuk menyimpan tiga paket perjalanan
} jenisTrip[100];

// Struct untuk menyimpan informasi tentang tanggal
struct tanggal
{
    int hari;
    int bulan;
    int tahun;
};

// Struct untuk menyimpan data pembeli
struct pembeli
{
    string nama;
    string paketTrip;
    int jumlahOrang;
    tanggal tgl;
    int harga;
    int uangDibayar;
    int kembalian;
};

struct LogNode
{
    string action;
    LogNode *next;
};

LogNode *logHead = nullptr;

// Array untuk menyimpan tanggal yang telah diatur
tanggal tidakTersediaTanggal[10];
int jumlahTanggal = 0;

// Array untuk menyimpan riwayat pembeli
pembeli riwayatPembeli[100];
int jumlahPembeli = 0;

void declareTrip()
{
    jenisTrip[0].nama = "Malang Trip";
    jenisTrip[0].paket[0] = {"Paket 1 Hari", "Makan 2x, Gunung Batok, Widodaren Hill, Sunrise Bromo", 275000};
    jenisTrip[0].paket[1] = {"Paket 2 Hari", "Makan 5x, Gunung Batok, Widodaren Hill, Sunrise Bromo, Pura Luhur, Kawah Bromo", 550000};
    jenisTrip[0].paket[2] = {"Paket 3 Hari", "Makan 8x, Gunung Batok, Widodaren Hill, Sunrise Bromo, Pura Luhur, Kawah Bromo, Pasir Berbisik, Padang Savanah", 750000};
    jenisTrip[1].nama = "Jakarta Trip";
    jenisTrip[1].paket[0] = {"Paket 1 Hari", "Makan 2x, Dufan, Jakarta Aquarium, TMII", 225000};
    jenisTrip[1].paket[1] = {"Paket 2 Hari", "Makan 5x, Dufan, Jakarta Aquarium, TMII, Playtopia Gandaria, Museum Macan", 400000};
    jenisTrip[1].paket[2] = {"Paket 3 Hari", "Makan 8x, Dufan, Jakarta Aquarium, TMII, Playtopia Gandaria, Museum Macan, Kep. Seribu, Playtopia PIK", 575000};
    jenisTrip[2].nama = "Bandung Trip";
    jenisTrip[2].paket[0] = {"Paket 1 Hari,", "Makan 2x, Lembang Park, Jl Braga, Rainbow Slide", 215000};
    jenisTrip[2].paket[1] = {"Paket 2 Hari,", "Makan 5x, Lembang Park, Jl Braga, Rainbow Slide, Forest Walk, Hutan Pinus", 350000};
    jenisTrip[2].paket[2] = {"Paket 3 Hari,", "Makan 8x, Lembang Park, Jl Braga, Rainbow Slide, Forest Walk, Hutan Pinus, Kaawah Rengginas, The Lodge Maribaya", 485000};
}

void tampilkanMenu()
{

    cout << "\n\nSelamat Datang di Layanan Pemesanan Trip\n";

    cout << "=============================================\n";

    cout << "1. Pesan Trip\n";

    cout << "2. Ubah Data Pesanan\n";

    cout << "3. Data Trip\n";

    cout << "4. Daftar Pesanan\n";

    cout << "5. Log sistem\n";

    cout << "\n0. Keluar\n";

    cout << "Pilih opsi (1/2/3/4/5/0): ";
}

void tampilkanDataTrip()
{

    cout << "\n\nPilih Paket Perjalanan:\n";

    cout << "=============================================\n";

    cout << "1. Tambah Data Trip\n";

    cout << "2. Ubah Data Trip\n";

    cout << "3. Hapus Data Trip\n";

    cout << "\n0. Kembali\n";

    cout << "Pilih opsi (1/2/3/0): ";
}

int dapatPanjangJenisTrip()
{
    int y = 0;
    for (int i = 0; i < sizeof(jenisTrip) / sizeof(jenisTrip[0]); i++)
    {
        if (jenisTrip[i].nama != "")
        {
            y++;
        }
    }
    return y;
}

void tampilkanJenisTrip()
{

    cout << "\n\nPilih Jenis Trip:\n";

    cout << "=============================================\n";
    for (int i = 0; i < dapatPanjangJenisTrip(); i++)
    {

        cout << i + 1 << ". " << jenisTrip[i].nama << endl;
    }

    cout << "\n0. Kembali\n";

    cout << "Pilih opsi (";
    for (int y = 0; y < dapatPanjangJenisTrip(); y++)
    {

        cout << y + 1 << "/";
    }

    cout << "0) : ";
}

void tampilkanPaketTrip(int index)
{

    cout << "\n\nPilih Paket Perjalanan:\n";

    cout << "=============================================\n";
    for (int i = 0; i < 3; i++)
    {

        cout << jenisTrip[index].paket[i].nama << ": " << jenisTrip[index].paket[i].deskripsi <<

            endl;
    }

    cout << "=============================================\n";
    for (int i = 0; i < 3; i++)
    {

        cout << i + 1 << ". " << jenisTrip[index].paket[i].nama << " RP." << jenisTrip[index].paket[i].harga <<

            endl;
    }

    cout << "\nPilih opsi (1/2/3/0): ";
}

void tampilkanNamaBulan()
{

    cout << "\n\nPilih Bulan Perjalanan:\n";

    cout << "=============================================\n";

    cout << "1. Januari\n";

    cout << "2. Februari\n";

    cout << "3. Maret\n";

    cout << "4. April\n";

    cout << "5. Mei\n";

    cout << "6. Juni\n";

    cout << "7. Juli\n";

    cout << "8. Agustus\n";

    cout << "9. September\n";

    cout << "10. Oktober\n";

    cout << "11. November\n";

    cout << "12. Desember\n";

    cout << "\n0. Kembali\n";

    cout << "Pilih opsi (1/2/3/4/5/6/7/8/9/10/11/12/0): ";
}

bool cekKetersediaan(tanggal t)
{
    for (int i = 0; i < jumlahTanggal; i++)
    {
        if (tidakTersediaTanggal[i].hari == t.hari && tidakTersediaTanggal[i].bulan == t.bulan && tidakTersediaTanggal[i].tahun == t.tahun)
        {
            return false;
        }
    }
    return true;
}

int dapatIndexTersediaan()
{
    int y = 0;
    for (int i = 0; i < (sizeof(tidakTersediaTanggal) / sizeof(tidakTersediaTanggal[0])); i++)
    {
        if (tidakTersediaTanggal[i].hari == 0)
        {
            return y - 1;
        }
        y++;
    }
    return 0;
}

void tambahkanTanggal(int hari, int bulan, int tahun)
{
    tidakTersediaTanggal[jumlahTanggal].hari = hari;
    tidakTersediaTanggal[jumlahTanggal].bulan = bulan;
    tidakTersediaTanggal[jumlahTanggal].tahun = tahun;
    jumlahTanggal++;
}

void prosesPembayaran(pembeli &p)
{
    while (true)
    {

        cout << "\n\nTotal harga: " << p.harga << endl;

        cout << "Masukkan uang yang dibayar: ";

        cin >> p.uangDibayar;
        p.kembalian = p.uangDibayar - p.harga;
        if (p.kembalian < 0)
        {

            cout << "\nUang yang dibayar kurang atau input salah.\n";
            p.uangDibayar = 0;
        }
        else
        {
            cout << "Pembayaran berhasil. Kembalian: " << p.kembalian << endl;
            return;
        }
    }
}

void tampilkanDaftarPesanan(int tahun, int bulan)
{

    cout << "Daftar Pesanan untuk " << bulan << "/" << tahun << ":\n";
    for (int i = 0; i < jumlahPembeli; i++)
    {
        if (riwayatPembeli[i].tgl.tahun == tahun && riwayatPembeli[i].tgl.bulan == bulan)
        {

            cout << "Nama: " << riwayatPembeli[i].nama
                 << "\nPaket: " << riwayatPembeli[i].paketTrip
                 << "\nTanggal: " << riwayatPembeli[i].tgl.hari << "/"
                 << riwayatPembeli[i].tgl.bulan << "/"
                 << riwayatPembeli[i].tgl.tahun
                 << "\nJumlah Orang: " << riwayatPembeli[i].jumlahOrang
                 << "\nTotal Harga: " << riwayatPembeli[i].harga << endl;
        }
    }
}

void pushLog(string action)
{
    LogNode *newNode = new LogNode;
    newNode->action = action;
    newNode->next = logHead;
    logHead = newNode;
}

void printLogs()
{
    LogNode *temp = logHead;

    cout << "Log Sistem:\n";
    while (temp != nullptr)
    {

        cout << temp->action << endl;
        temp = temp->next;
    }
}

void tampilkanStruk(pembeli p)
{

    cout << "\n\nStruk Pembelian:\n";

    cout << "=============================================\n";

    cout << "Atas nama : " << p.nama <<

        endl;

    cout << "Jenis Trip: " << p.paketTrip <<

        endl;

    for (int i = 0; i < 3; i++)
    {
        if (jenisTrip[i].nama == p.paketTrip)
        {

            cout << "Paket yang dipilih: " << jenisTrip[i].paket[p.jumlahOrang - 1].nama <<

                endl;

            cout << "Isi Paket: " << jenisTrip[i].paket[p.jumlahOrang - 1].deskripsi <<

                endl;
            break;
        }
    }

    cout << "Jumlah orang: " << p.jumlahOrang <<

        endl;

    cout << "Tanggal : " << p.tgl.hari << "/" << p.tgl.bulan << "/" << p.tgl.tahun <<

        endl;

    cout << "Total harga: " << p.harga <<

        endl;
    cout << "Bayar : " << p.uangDibayar <<

        endl;
    cout << "Kembalian : " << p.kembalian << endl;
}

void editPesanan()
{
    string nama;

    cout << "Masukkan nama pembeli yang ingin diedit: ";

    cin.ignore();
    getline(

        cin, nama);

    for (int i = 0; i < jumlahPembeli; i++)
    {
        if (riwayatPembeli[i].nama == nama)
        {
        labelEditPesanan:
            cout << "Mengedit pesanan untuk " << nama << endl;

            cout << "Masukkan nama baru: ";
            getline(

                cin, riwayatPembeli[i].nama);

            cout << "Masukkan jumlah orang baru: ";

            cin >> riwayatPembeli[i].jumlahOrang;

            while (true)
            {
                tampilkanNamaBulan();

                cin >> riwayatPembeli[i].tgl.bulan;
                if (riwayatPembeli[i].tgl.bulan == 0)
                {
                    goto labelEditPesanan;
                }
                else if (riwayatPembeli[i].tgl.bulan >= 1 && riwayatPembeli[i].tgl.bulan <= 12)
                {
                    break;
                }
                cout << "Pilihan tidak valid.\n";
            }

            cout << "Masukkan tanggal baru: ";

            cin >> riwayatPembeli[i].tgl.hari;

            cout << "Masukkan tahun baru: ";

            cin >> riwayatPembeli[i].tgl.tahun;

            riwayatPembeli[i].harga *= riwayatPembeli[i].jumlahOrang;

            cout << "Data berhasil diupdate.\n";
            pushLog("Ubah pesanan: " + riwayatPembeli[i].nama);

            return;
        }
    }

    cout << "Data tidak ditemukan.\n";
}

// Fungsi Menambahkan Pesanan
void tambahPesanan()
{
    pembeli p;
    tanggal t;
    int panjangJenisTrip = dapatPanjangJenisTrip();
    int opsiJenis, opsiPaket, jumlahOrang, hari, bulan, tahun;

labelJenisTrip:
    while (true)
    {
        tampilkanJenisTrip();
        cin >> opsiJenis;
        if (opsiJenis > 0 && opsiJenis <= panjangJenisTrip)
        {
            break;
        }
        cout << "Pilihan tidak valid.\n";
    }
    p.paketTrip = jenisTrip[opsiJenis - 1].nama;
    int panjangPaketTrip = sizeof(jenisTrip) / sizeof(jenisTrip[0]);

labelPaketTrip:
    while (true)
    {
        tampilkanPaketTrip(opsiJenis - 1);

        cin >> opsiPaket;
        if (opsiJenis == 0)
        {
            goto labelJenisTrip;
        }
        else if (opsiPaket >= 1 && opsiPaket <= (sizeof(jenisTrip[opsiJenis - 1].paket) / sizeof(jenisTrip[opsiJenis - 1].paket[0])))
        {
            break;
        }

        cout << "Pilihan tidak valid.\n";
    }
    p.harga = jenisTrip[opsiJenis - 1].paket[opsiPaket - 1].harga;

    while (true)
    {

        cout << "Masukkan jumlah orang: ";

        cin >> jumlahOrang;
        if (jumlahOrang > 0)
        {
            break;
        }

        cout << "Jumlah orang tidak valid.\n";
    }
    p.jumlahOrang = jumlahOrang;
    p.harga = p.harga * jumlahOrang;

    cout << "Masukkan nama pembeli: ";

    cin.ignore();
    getline(

        cin, p.nama);

    cout << "Masukan Tahun : ";

    cin >> tahun;

    while (true)
    {
        tampilkanNamaBulan();

        cin >> bulan;
        if (bulan == 0)
        {
            goto labelPaketTrip;
        }
        if (bulan >= 1 && bulan <= 12)
        {
            break;
        }

        cout << "Pilihan tidak valid.\n";
    }

labelTanggal:
    while (true)
    {

        cout << "Masukkan tanggal: ";

        cin >> hari;

        if (hari >= 1 && hari <= 31)
        {
            break;
        }

        cout << "Tanggal tidak valid.\n";
    }
    t.hari = hari;
    t.bulan = bulan;
    t.tahun = tahun;
    p.tgl = t;

    if (cekKetersediaan(t))
    {
        prosesPembayaran(p);
        if (p.uangDibayar > 0)
        {
            riwayatPembeli[jumlahPembeli++] = p;

            cout << "Trip berhasil dipesan.\n";
        }
    }
    else
    {

        cout << "Tanggal tidak tersedia.\n";
        goto labelTanggal;
    }
    tidakTersediaTanggal[dapatIndexTersediaan()] = {hari, bulan, 2024};
    tampilkanStruk(p);
    pushLog("Menambah pesanan: " + p.nama);
}

// Fungsi Menambah Trip
void tambahTrip()
{
    int index = dapatPanjangJenisTrip();
    if (index >= 100)
    {

        cout << "Tidak dapat menambah trip baru. Batas maksimum tercapai.\n";
        return;
    }

    cout << "Masukkan nama trip: ";

    cin.ignore();
    getline(

        cin, jenisTrip[index].nama);

    for (int i = 0; i < 3; i++)
    {

        cout << "Masukkan nama paket " << i + 1 << ": ";
        getline(

            cin, jenisTrip[index].paket[i].nama);

        cout << "Masukkan deskripsi paket " << i + 1 << ": ";
        getline(

            cin, jenisTrip[index].paket[i].deskripsi);

        cout << "Masukkan harga paket " << i + 1 << ": ";

        cin >> jenisTrip[index].paket[i].harga;

        cin.ignore();
    }

    pushLog("Menambah trip: " + jenisTrip[index].nama);

    cout << "Trip baru berhasil ditambahkan.\n";
}

//  Fungsi mengedit trip
void editTrip()
{
    int index;
    tampilkanJenisTrip();

    cin >> index;
    if (index <= 0 || index > dapatPanjangJenisTrip())
    {

        cout << "Pilihan tidak valid.\n";
        return;
    }

    index--; // Convert to 0-based index

    cout << "Mengedit trip: " << jenisTrip[index].nama << endl;

    cout << "Masukkan nama baru trip: ";

    cin.ignore();
    getline(

        cin, jenisTrip[index].nama);

    for (int i = 0; i < 3; i++)
    {

        cout << "Masukkan nama baru paket " << i + 1 << ": ";
        getline(

            cin, jenisTrip[index].paket[i].nama);

        cout << "Masukkan deskripsi baru paket " << i + 1 << ": ";
        getline(

            cin, jenisTrip[index].paket[i].deskripsi);

        cout << "Masukkan harga baru paket " << i + 1 << ": ";

        cin >> jenisTrip[index].paket[i].harga;

        cin.ignore();
    }

    pushLog("Mengedit trip: " + jenisTrip[index].nama);

    cout << "Trip berhasil diupdate.\n";
}

// Fungsi menghapus trip
void hapusTrip()
{
    int index;
    tampilkanJenisTrip();

    cin >> index;
    if (index <= 0 || index > dapatPanjangJenisTrip())
    {

        cout << "Pilihan tidak valid.\n";
        return;
    }

    index--; // Convert to 0-based index

    string deletedTripName = jenisTrip[index].nama;

    for (int i = index; i < dapatPanjangJenisTrip() - 1; i++)
    {
        jenisTrip[i] = jenisTrip[i + 1];
    }
    jenisTrip[dapatPanjangJenisTrip() - 1].nama = "";
    for (int i = 0; i < 3; i++)
    {
        jenisTrip[dapatPanjangJenisTrip() - 1].paket[i] = {"", "", 0};
    }

    pushLog("Menghapus trip: " + deletedTripName);

    cout << "Trip berhasil dihapus.\n";
}

// Fungsi Mengatur Data Trip
void aturDataTrip()
{
    int pilihan;
    while (true)
    {
        tampilkanDataTrip();

        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            tambahTrip();
            break;
        case 2:
            editTrip();
            break;
        case 3:
            hapusTrip();
            break;
        case 0:
            return;
        default:

            cout << "Pilihan tidak valid.\n";
            break;
        }
    }
}

int main()
{
    declareTrip();
    int opsiMenu;
    int tahun, bulan;

    // Contoh tanggal yang tidak tersedia
    tambahkanTanggal(15, 7, 2024);
    tambahkanTanggal(20, 8, 2024);

    while (true)
    {
        tampilkanMenu();

        cin >> opsiMenu;

        if (opsiMenu == 0)
        {

            cout << "\n========== Program berhenti. ==============\n";
            break;
        }

        switch (opsiMenu)
        {
        case 1:
            tambahPesanan();
            break;
        case 2:
            editPesanan();
            break;
        case 3:
            aturDataTrip();
            break;
        case 4:

            cout << "masukan tahun : ";

            cin >> tahun;
            tampilkanNamaBulan();

            cin >> bulan;
            tampilkanDaftarPesanan(tahun, bulan);
            break;
        case 5:
            printLogs();
            break;
        default:

            cout << "Pilihan tidak valid.\n";
            break;
        }

        cout << "Kembali ke menu utama? (y/n): ";
        char kembali;

        cin >> kembali;
        if (kembali == 'n' || kembali == 'N')
        {

            cout << "\n========== Program berhenti. ==============\n";
            break;
        }
    }
    return 0;
}
