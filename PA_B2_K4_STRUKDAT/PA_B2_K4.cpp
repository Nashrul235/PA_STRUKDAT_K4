#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

struct alatPendakian { // metode linked list  alat pendakian seperti id,nama,harga,update, dan acc alat
    int idAlat;
    string nama;
    int harga;
    bool isUpdated;  
    bool isAcc;  
    alatPendakian* next;
};

void enqueue(alatPendakian*& head, alatPendakian*& tail, string idAlat, string namaAlat, string harga); //metode queue berbasis linked list ( queue untuk menambah dan menghapus )
void tampilkanAlat(alatPendakian*& head); //metode linkedlist
void tampilkanHistori(alatPendakian*& historyHead);// metode linkedlist mencetak elemen stack  
void tambahAlatQueue(alatPendakian*& queueHead, alatPendakian*& queueTail, string idAlat, string namaAlat, string harga); //metode queue berbasi linkedlist
void tambahAlatHistory(alatPendakian*& history, string idAlat, string namaAlat, string harga);//metode stack berbasis linkedlist (stack tambah)


void menuAdmin(alatPendakian*& queueHead, alatPendakian*& queueTail, alatPendakian*& historyHead); // metode queue berbasis linked list pada aadmin


void menuManajer(alatPendakian*& queueHead, alatPendakian*& queueTail, alatPendakian*& historyHead); // metode queue berbasis linkedl list pada manajer
void menuPilih(alatPendakian*& queueHead, alatPendakian*& queueTail, alatPendakian*& historyHead);

void push(alatPendakian*& head, int idAlat, string namaAlat, int harga) { //metode stack mengurutkan alat pendakian
    alatPendakian* newAlat = new alatPendakian();
    newAlat->idAlat = idAlat;
    newAlat->nama = namaAlat;
    newAlat->harga = harga;
    newAlat->next = head;
    head = newAlat;
}
void pop(alatPendakian*& head) {
    if (head == nullptr) {
        cout << "Stack kosong, tidak ada yang bisa di-pop!" << endl;
        return;
    }
    alatPendakian* temp = head;
    head = head->next; 
    delete temp; 
    cout << "Alat pendakian paling atas telah dihapus" << endl;
}

void tambahAlatQueue(alatPendakian*& queueHead, alatPendakian*& queueTail, int idAlat, string namaAlat, int harga, bool isUpdated = false) { // metode queue menambahkan alat
    alatPendakian* alatBaru = new alatPendakian();
    alatBaru->idAlat = idAlat;
    alatBaru->nama = namaAlat;
    alatBaru->harga = harga;
    alatBaru->isUpdated = isUpdated;
    alatBaru->next = nullptr;

    if (queueHead == nullptr) {
        queueHead = alatBaru;
        queueTail = alatBaru;
    } else {
        queueTail->next = alatBaru;
        queueTail = alatBaru;
    }

    cout << "Alat " << alatBaru->nama << " telah ditambahkan ke dalam antrean untuk ACC Manajer." << endl;
}




void enqueue(alatPendakian*& head, alatPendakian*& tail, int idAlat, string namaAlat, int harga) { // Metode Queue Menambahkan alat ke antrean 
    alatPendakian* tambahAlat = new alatPendakian();
    tambahAlat->nama = namaAlat;
    tambahAlat->harga = harga;
    tambahAlat->idAlat = idAlat;
    tambahAlat->next = nullptr;

    if (head == nullptr) {
        head = tambahAlat;
        tail = tambahAlat; 
    } else {
        tail->next = tambahAlat;
        tail = tambahAlat; 
    }
}


void tampilkanAlat(alatPendakian*& head) { // Mentode linkedlist Menampilkan alat
    if (head == nullptr) {
        cout << "Antrian kosong!" << endl;
        return;
    }
    alatPendakian* temp = head;
    while (temp != nullptr) {
        cout << "Id alat: " << temp->idAlat << endl;
        cout << "Nama alat: " << temp->nama << endl;
        cout << "Harga (Rp): " << temp->harga << endl;
        cout << endl;
        temp = temp->next;
    }
}



void tampilkanHistori(alatPendakian*& historyHead) { // metode linkedlist menampilkan histori alat yang sudah di-ACC
    if (historyHead == nullptr) {
        cout << "Histori kosong!" << endl;
        return;
    }
    alatPendakian* temp = historyHead;
    while (temp != nullptr) {
        cout << "Id alat: " << temp->idAlat << endl;
        cout << "Nama alat: " << temp->nama << endl;
        cout << "Harga (Rp): " << temp->harga << endl;
        cout << endl;
        temp = temp->next;
    }
}




void tambahAlatHistory(alatPendakian*& history, int idAlat, string namaAlat, int harga) { //    Metode Stack Menambahkan alat ke histori
    push(history, idAlat, namaAlat, harga);
}

void deleteAlatFromHistori(alatPendakian*& historyHead) { // metode Linked List mengahapus history.
  
    if (historyHead == nullptr) {
        cout << "Histori kosong! Tidak ada alat yang bisa dihapus." << endl;
        return;  
    } 
    alatPendakian* alatDihapus = historyHead;
    historyHead = historyHead->next;  
    delete alatDihapus;  

    cout << "Alat terbaru di histori telah dihapus." << endl;
}

void alatbarueacc(alatPendakian*& queueHead, alatPendakian*& historyHead) { //metode queue menambah alat baru acc
    if (queueHead == nullptr) {
        cout << "Tidak ada alat yang perlu di-ACC!" << endl;
        return;
    }

    alatPendakian* temp = queueHead;
    alatPendakian* prev = nullptr;
    bool alatDitemukan = false;

    cout << "\n===== tambah Alat yang di-ACC =====\n";
    while (temp != nullptr) {
        cout << "ID Alat: " << temp->idAlat << endl;
        cout << "Nama Alat: " << temp->nama << endl;
        cout << "Harga (Rp): " << temp->harga << endl;
        cout << (temp->isUpdated ? "Status: Update\n" : "Status: Baru\n") << endl;
        alatDitemukan = true;

        cout << "Apakah Anda ingin ACC alat ini? (y/n): ";
        char accChoice;
        cin >> accChoice;

        if (accChoice == 'y' || accChoice == 'Y') {
            if (temp->isUpdated) {
                alatPendakian* historyTemp = historyHead;
                while (historyTemp != nullptr) {
                    if (historyTemp->idAlat == temp->idAlat) {
                        // Update data dalam histori
                        historyTemp->nama = temp->nama;
                        historyTemp->harga = temp->harga;
                        cout << "Data alat " << temp->idAlat << " telah diperbarui di histori!" << endl;
                        break;
                    }
                    historyTemp = historyTemp->next;
                }
            } else {
               
                tambahAlatHistory(historyHead, temp->idAlat, temp->nama, temp->harga);
                cout << "Alat " << temp->nama << " telah ditambahkan ke histori!" << endl;
            }
        } else if (accChoice == 'n' || accChoice == 'N') {
            cout << "Alat " << temp->nama << " telah ditolak dan dihapus dari antrean." << endl;
        }

       
        if (prev == nullptr) {
            queueHead = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
        break;
    }

    if (!alatDitemukan) {
        cout << "Tidak ada alat untuk di-ACC." << endl;
    }
}


void updateAlatInHistory(alatPendakian*& historyHead, alatPendakian*& queueHead, alatPendakian*& queueTail) { //linkedlist update alat history
    if (historyHead == nullptr) {
        cout << "Histori kosong! Tidak ada alat yang bisa diupdate." << endl;
        return;
    } else {
        tampilkanHistori(historyHead);
    }

    int idAlat;
    cout << "Masukkan ID alat yang ingin diupdate: ";
    cin >> idAlat;

    alatPendakian* temp = historyHead;
    while (temp != nullptr) {
        if (temp-> idAlat == idAlat) {
            string newNama;
            int newHarga;
            cout << "Alat ditemukan! Masukkan data baru untuk alat ini:" << endl;
            cout << "Nama alat: ";
            cin.ignore();
            getline(cin, newNama);
            cout << "Harga alat: ";
            cin >> newHarga;

            tambahAlatQueue(queueHead, queueTail, idAlat, newNama, newHarga, true);
            cout << "Data alat dengan ID " << idAlat << " telah diupdate!" << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Alat dengan ID " << idAlat << " tidak ditemukan dalam histori!" << endl;
}

int hitungPanjang(alatPendakian* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}


void salinKeArray(alatPendakian* head, alatPendakian** arr, int length) {
    for (int i = 0; i < length; ++i) {
        arr[i] = head;
        head = head->next;
    }
}


void merge(alatPendakian** arr, int l, int m, int r) { // metode sorting Merge Sort mengurutkan  berdasarkan idAlat
    int n1 = m - l + 1;
    int n2 = r - m;

    alatPendakian** L = new alatPendakian*[n1];
    alatPendakian** R = new alatPendakian*[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i]->idAlat <= R[j]->idAlat) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(alatPendakian** arr, int l, int r) { //metode sorting merge sort pada pengurutan harga
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


int fibonacciSearch(alatPendakian** arr, int length, int idAlat) { // metode searching menggunakan Fibonacci mencari nama alat
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < length) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, length - 1);

        if (arr[i]->idAlat < idAlat) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (arr[i]->idAlat > idAlat) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            return i;
        }
    }

    if (fibMMm1 && arr[offset + 1]->idAlat == idAlat) return offset + 1;

    return -1;
}


void cariAlat(alatPendakian* head, int idAlat) { // metode sorting menggunakan fibonachi cari alat berdasarkan id
    int length = hitungPanjang(head);
    alatPendakian** arr = new alatPendakian*[length];

    
    salinKeArray(head, arr, length);
    mergeSort(arr, 0, length - 1);

    int result = fibonacciSearch(arr, length, idAlat);

    cout << "\n===== History Alat Acc =====\n";
    if (result != -1) {
        cout << "Alat ditemukan:\n";
        cout << "ID Alat: " << arr[result]->idAlat << endl;
        cout << "Nama Alat: " << arr[result]->nama << endl;
        cout << "Harga: Rp" << arr[result]->harga << endl;
    } else {
        cout << "Alat dengan ID " << idAlat << " tidak ditemukan.\n";
    }

    delete[] arr;
}

// Fungsi Partition untuk Quick Sort
int partition(alatPendakian* arr[], int low, int high) {
    int pivot = arr[high]->harga;
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j]->harga < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


int jumpSearch(alatPendakian* arr[], int n, int harga) { //metode sorting jumsearch pada mencari harga
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1]->harga < harga) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }

    while (arr[prev]->harga < harga) {
        prev++;
        if (prev == min(step, n)) return -1;
    }

    if (arr[prev]->harga == harga) return prev;
    return -1;
}


void quickSort(alatPendakian* arr[], int low, int high) { // Metode Sorting Quick Sort mengurutkan berdasarkan barang
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 
void cariHargaAlat(alatPendakian* historyHead, int hargaDicari) { // metode searching pencarian harga menggunakan Jump Search
    int count = 0;
    alatPendakian* temp = historyHead;

    // Hitung jumlah elemen dalam histori
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    // Pindahkan data ke dalam array untuk pengurutan dan pencarian
    alatPendakian* arr[count];
    temp = historyHead;
    for (int i = 0; i < count; i++) {
        arr[i] = temp;
        temp = temp->next;
    }

    // Urutkan array berdasarkan harga dengan Quick Sort
    quickSort(arr, 0, count - 1);

    
    int index = jumpSearch(arr, count, hargaDicari); // metode searching harga menggunakan Jump Search
    if (index != -1) {
        cout << "Alat ditemukan!" << endl;
        cout << "ID Alat: " << arr[index]->idAlat << endl;
        cout << "Nama Alat: " << arr[index]->nama << endl;
        cout << "Harga (Rp): " << arr[index]->harga << endl;
    } else {
        cout << "Alat dengan harga " << hargaDicari << " tidak ditemukan!" << endl;
    }
}

int findPattern(const string& text, const string& pattern) {
    int m = pattern.length();
    int n = text.length();

    if (m > n) return -1;

    vector<int> badChar(256, -1);

    for (int i = 0; i < m; i++) {
        badChar[(int) pattern[i]] = i;
    }

    int shift = 0;
    while (shift <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            return shift;
            shift += (shift + m < n) ? m - badChar[text[shift + m]] : 1;
        } else {
            shift += max(1, j - badChar[text[shift + j]]);
        }
    }
    return -1;
}

void cariNamaAlat(alatPendakian* head, const string& namaDicari) { //metode linked list mencari nama alat
    bool ditemukan = false;
    while (head != nullptr) {
        if (findPattern(head->nama, namaDicari) != -1) {
            cout << "Alat ditemukan:\n";
            cout << "ID Alat: " << head->idAlat << endl;
            cout << "Nama Alat: " << head->nama << endl;
            cout << "Harga (Rp): " << head->harga << endl;
            cout << endl;
            ditemukan = true;
        }
        head = head->next;
    }

    if (!ditemukan) {
        cout << "Alat dengan nama \"" << namaDicari << "\" tidak ditemukan.\n";
    }
}


void headeradmin(){ //
    cout << "========================================================================================================\n";
    cout << "\t\t\t\tSelamat Datang Di Toko Menu Admin\n\t\t\t\tSelamat Bekerja Dengan Giat\n\t\t\tSemangat Ya, Aku Tau Ini Berat Tapi, Pinjam Dulu Seratus !!!\n\t\t\t\t\t     emot senyum " << endl;
    cout << "========================================================================================================\n";
    cout <<"\n";
    cout <<"\n";
}
void headermanejer(){
     cout << "========================================================================================================\n";
    cout << "\t\t\t\tSelamat Datang Di Menu Manajer\n\t\t\t\tSelamat Menikmati Apa Yang Sudah Kami Buat\n\t\t\tSemangat Ya, Aku Tau Ini Berat Tapi, Pinjam Dulu Seratus !!!\n\t\t\t\t\t     emot senyum " << endl;
    cout << "========================================================================================================\n";
    cout <<"\n";
    cout <<"\n";
}


// Fungsi untuk menu manajer
void menuManajer(alatPendakian*& queueHead, alatPendakian*& queueTail, alatPendakian*& historyHead) {
    string pilih, ulang = "y";
    while (ulang == "y") {
        cout << "[1] Tambah alat baru di-ACC \n"
             << "[2] Lihat histori alat di-ACC \n"
             << "[3] Kembali\n";
        cout << "Masukkan pilihan >> ";
        cin >> pilih;
        system("cls");

        if (pilih == "1") {
            headermanejer();
            alatbarueacc(queueHead,historyHead);  
        } else if (pilih == "2") {
            headermanejer();
            tampilkanHistori(historyHead); 
        } else if (pilih == "3") {
            ulang = "t";  
        } else {
            cout << "Pilihan tidak ada" << endl;
        }
    }
}



void menuAdmin(alatPendakian*& queueHead, alatPendakian*& queueTail, alatPendakian*& historyHead) { //metode linkedlist menu admin
    string pilih, ulang = "y";
    while (ulang == "y") {
        cout << "[1] Lihat alat yang sudah di-ACC (Histori)\n"
             << "[2] tambah alat pendakian ke antrean\n"
             << "[3] Update alat pendakian\n"
             << "[4] Hapus alat dari histori\n"
             << "[5] Cari alat berdasarkan ID\n"
             << "[6] Cari alat berdasarkan harga\n" 
             << "[7] Cari alat berdasarkan nama\n" 
             << "[8] Kembali\n";
        cout << "Masukkan pilihan >> ";
        cin >> pilih;
        system("cls");

        if (pilih == "1") {
            headeradmin();
            tampilkanHistori(historyHead);
        } else if (pilih == "2") {
            headeradmin();
            int idAlat, harga;
            string namaAlat;
            cin.ignore();

            cout << "Masukkan ID alat pendakian: ";
            cin >> idAlat;
            cin.ignore();
            cout << "Masukkan nama alat pendakian: ";
            getline(cin, namaAlat);
            cout << "Masukkan harga alat pendakian: ";
            cin >> harga;
            system("cls");

            headeradmin();
            tambahAlatQueue(queueHead, queueTail, idAlat, namaAlat, harga, false);
        } else if (pilih == "3") {
            headeradmin();
            updateAlatInHistory(historyHead, queueHead, queueTail);
        } else if (pilih == "4") {
            headeradmin();
            deleteAlatFromHistori(historyHead);
        } else if (pilih == "5") {
            headeradmin();
            int idAlatDicari;
            cout << "Masukkan ID alat yang ingin dicari: ";
            cin >> idAlatDicari;
            cariAlat(historyHead, idAlatDicari);
        } else if (pilih == "6") {  
            headeradmin();
            int hargaDicari;
            cout << "Masukkan harga alat yang ingin dicari: ";
            cin >> hargaDicari;
            cariHargaAlat(historyHead, hargaDicari);  
        } else if (pilih == "7") {  
            headeradmin();
            string namaDicari;
            cin.ignore();
            cout << "Masukkan nama alat yang ingin dicari: ";
            getline(cin, namaDicari);
            cariNamaAlat(historyHead, namaDicari);
        } else if (pilih == "8") {
            ulang = "t";
        } else {
            cout << "Pilihan tidak ada" << endl;
        }
    }
}


void menuPilih(alatPendakian*& queueHead, alatPendakian*& queueTail, alatPendakian*& historyHead) { //metode linkedlist pada menu utama
    string pilih;
    while (true) {
    cout << "========================================================================================================\n";
    cout << "\t\t\t\tSelamat Datang Di Toko Alat Pendakian\n\t\t\t\t Silahkan Pilih Sesuai Role " << endl;
    cout << "========================================================================================================\n";
        cout << "1. Admin\n"
             << "2. Manajer\n"
             << "3. Keluar\n";
        cout << "Masukkan pilihan >> ";
        cin >> pilih;
        system("cls");

        if (pilih == "1") {
            headeradmin();
            menuAdmin(queueHead,queueTail, historyHead);  // Menu Admin
        } else if (pilih == "2") {
            headermanejer();
            menuManajer(queueHead, queueTail, historyHead);  // Menu Manajer
        } else if (pilih == "3") {
            break;  // tambah dari program
        } else {
            cout << "Pilihan tidak ada" << endl;
        }
    }
}

int main() {
    alatPendakian* queueHead = nullptr;  // Queue untuk alat yang perlu di-ACC
    alatPendakian* queueTail = nullptr;  // Tail dari queue
    alatPendakian* historyHead = nullptr;  // Stack untuk histori alat yang di-ACC

    menuPilih(queueHead, queueTail, historyHead);  // Masuk ke menu utama pilih

}
 