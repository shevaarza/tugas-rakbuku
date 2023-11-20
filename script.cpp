#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <set> 


using namespace std;

class Book {
public:
    string judul;
    string isi;
    double harga;

    // Konstruktor untuk inisialisasi objek Book
    Book(string t, string a, double h) : judul(t), isi(a), harga(h) {}

    // Metode untuk menampilkan informasi buku
    void displayInfo() const {
        cout << "judul: " << judul << "\nisi: " << isi << "\nharga: $" << harga << endl;
    }
};
class PinManager {
private:
    const int defaultPin = 132006; // PIN default

public:
    bool verifyPin(int enteredPin) const {
        return defaultPin == enteredPin;
    }
};

class Bookshelf {
private:
    vector<Book> books;

public:
    // Metode untuk menambahkan buku ke dalam rak buku
    void addBook(const Book& book) {
        books.push_back(book);
        cout << endl;
        cout << "Book added successfully.\n";
        
    }

    // Metode untuk menampilkan semua buku di rak buku
    void displayBooks() const {
        if (books.empty()) {
            cout << "MAAF TIDAK ADA BUKU DI RAK ANDA.\n";
            cout << endl;
        } else {
            cout << "Ini adalah rak buku Anda Saat ini  :\n";
            cout << "--------------------------------------------------------------------------------------------\n";
            cout << "| No. |          Judul                 |          Pengarang             |      Harga     |\n";
            cout << "--------------------------------------------------------------------------------------------\n";

            int number = 1;
            for (const Book& book : books) {
                cout << "| " << setw(3) << number++ << " | " << setw(18) << book.judul << setw(15) <<  " | " << setw(18) 
                << book.isi << setw(15) << " | " << setw(14) << fixed << setprecision(2) << book.harga << " |\n";
            }

            cout << "--------------------------------------------------------------------------------------------\n";
        }
    }

    // Metode untuk mencari buku berdasarkan judul
     void searchBook(const string& judul) const {
        cout << "Ini adalah Judul Buku yang dapat saya temukan : " << judul << ":\n";
        cout << "--------------------------------------------------------------------------------------------\n";
        cout << "| No. |          Judul                 |          Pengarang             |      Harga     |\n";
        cout << "--------------------------------------------------------------------------------------------\n";

        int number = 1;
        for (const Book& book : books) {
            if (book.judul == judul) {
                cout << "| " << setw(3) << number++ << " | " << setw(18) << book.judul << setw(15) <<  " | " << setw(18) 
                << book.isi << setw(15) << " | " << setw(14) << fixed << setprecision(2) << book.harga << " |\n";
            }
        }

        cout << "--------------------------------------------------------------------------------------------\n";
    }


     void searchAuthor(const string& isi) const {
        cout << "Ini adalah beberapa buku dengan penulis yang anda cari " << isi << ":\n";
        cout << "--------------------------------------------------------------------------------------------\n";
        cout << "| No. |          Judul                 |          Pengarang             |      Harga     |\n";
        cout << "--------------------------------------------------------------------------------------------\n";

        int number = 1;
        for (const Book& book : books) {
            if (book.isi == isi) {
                cout << "| " << setw(3) << number++ << " | " << setw(18) << book.judul << setw(15) <<  " | " << setw(18)
                 << book.isi << setw(15) << " | " << setw(14) << fixed << setprecision(2) << book.harga << " |\n";
            }
        }

        cout << "--------------------------------------------------------------------------------------------\n";
    }

    // Metode untuk menghapus buku dari rak berdasarkan judul
    void removeBook(const string& judul) {
        auto it = remove_if(books.begin(), books.end(), [judul](const Book& book) {
            return book.judul == judul;
        });

        if (it != books.end()) {
            books.erase(it, books.end());
            cout << "Book removed successfully(mantap).\n";
            cout << endl;
        } else {
            cout << "Buku ini tidak di temukan di rak buku anda.\n";
            cout << endl;
        }
    }

    set<string> getAllAuthors() const {
        set<string> authors;
        for (const Book& book : books) {
            authors.insert(book.isi);
        }
        return authors;
    }


};

    class Bookremoves{
    private:
    vector<Book> remove;

    public:
    

    // Metode untuk menampilkan semua buku di rak buku
    void displayRemove() const {
        if (remove.empty()) {
            cout << "Ini adalah judul semua buku di rak saat ini :\n";
            cout << "----------------------------------------\n";
            cout << "| No. |          Judul                 |\n";
            cout << "----------------------------------------\n";

            int number = 1;
            for (const Book& book : remove) {
                cout << "| " << setw(3) << number++ << " | " << setw(18) << book.judul << setw(15) <<  " | \n";
            }

            cout << "----------------------------------------\n";
        }
    }

    };

int main() {
    const int pinBenar = 132006; // PIN yang benar
    int pin;

    // Meminta pengguna untuk memasukkan PIN
    cout << "Masukkan PIN: ";
    cin >> pin;
    cout << endl;

    // Memeriksa apakah PIN yang dimasukkan benar atau salah
    while (pin != pinBenar) {
        cout << "PIN salah. Coba lagi." << endl;
        cout << "Masukkan PIN: ";
        cin >> pin;
        cout << endl;

        // Jika pengguna memasukkan nilai selain angka, hentikan program
        if (cin.fail()) {
            cout << "Input bukan angka. Program berhenti." << endl;
            cout << endl;
            return 1;
        }
    }

    cout << "PIN benar. Akses diberikan." << endl;


    Bookshelf bookshelf;
    Bookremoves bookremove;

    int choice;
    string judul, isi;
     double harga;
    
     time_t now = time(0);
    tm* localTime = localtime(&now);  

      
    

    do {
        cout << "Waktu saat ini : " << localTime->tm_mday <<   " - " <<localTime->tm_mon + 1 << " - "  << localTime->tm_year + 1900 
        << endl;
        cout << "\nPERPUSTAKAAN RUMAH KU\n";
        cout << "1. Tambahkan buku anda\n";
        cout << "2. Melihat tampilan semua buku\n";
        cout << "3. Mencari Judul buku\n";
        cout << "4. mencari pengarang buku \n";
        cout << "5. hapus buku dari perpustakaan \n" ;
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        

        switch (choice) {
            case 1:
                cout << "Masukan judul buku anda: ";
                cin.ignore();
                getline(cin, judul);
                cout << endl;
                cout << "Pengarang atau karya cerita buku tersebut : ";
                getline(cin, isi);
                cout << endl;
                cout << "Masukkan harga buku: $";
                  cin >> harga;
                  cout << endl;
                bookshelf.addBook(Book(judul, isi,harga));
                break;
            case 2:
                bookshelf.displayBooks();
                cout << endl;
                break;
            case 3:
                cout << "ketik judul buku yang mau di cari : ";
                cin.ignore();
                getline(cin, judul);
                bookshelf.searchBook(judul);
                break;
           case 4:
                cout << "Karya buku yang tersedia :\n";
                for (const string& author : bookshelf.getAllAuthors()) {
                    cout << "-" << author << endl;
                    cout << endl;
                }
                cout << "Pilih pengarang atau karya yang ingin dicari: ";
                cin.ignore();
                getline(cin, isi);
                bookshelf.searchAuthor(isi);
                break;            
            case 5:
                cout << "Judul buku yang tersedia:\n";
                 bookshelf.displayBooks();
                cout << "Pilih buku yang mau di hapus : ";
                cout << endl;
                cin.ignore();
                getline(cin, judul);
                bookshelf.removeBook(judul);
                break;
            
            case 0:
                cout << "Selamat tinggal semoga hidupmu bahagia Selamanya !\n";
                cout << endl;
                break;
            default:
                cout << "Mantap sekali bro anda hebat.\n";
                cout << endl;
        }
    } while (choice != 0);

    return 0;
}
