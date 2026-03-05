#include <stdio.h>  // Untuk input/output standar seperti printf dan scanf
#include <stdlib.h> // Untuk alokasi memori dinamis (malloc, free)

// Fungsi untuk membaca sejumlah nilai dari input
// Mengembalikan pointer ke array nilai yang dialokasikan secara dinamis
// dan mengisi jumlah elemen ke dalam n_count
double* bacaNilai(int *n_count) {
    int n;
    scanf("%d", &n); // Membaca jumlah nilai (n)
    *n_count = n;

    // Alokasi memori untuk n nilai
    double *values = (double *)malloc(n * sizeof(double));
    if (values == NULL) {
        // Penanganan error alokasi memori
        fprintf(stderr, "Error: Gagal mengalokasikan memori.\n");
        return NULL;
    }

    // Membaca n nilai
    for (int i = 0; i < n; i++) {
        scanf("%lf", &values[i]);
    }

    return values;
}

// Fungsi untuk menghitung jumlah total dari array nilai
double hitungJumlah(const double arr[], int size) {
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

// Fungsi untuk menghitung rata-rata dari array nilai
// Mengembalikan rata-rata, atau 0.0 jika size adalah 0 untuk menghindari pembagian dengan nol
double hitungRataRata(const double arr[], int size) {
    if (size == 0) {
        return 0.0;
    }
    double total = hitungJumlah(arr, size); // Menggunakan fungsi hitungJumlah
    return total / size;
}

// Fungsi baru untuk menghitung banyaknya nilai yang di atas atau sama dengan rata-rata
int hitungDiAtasRataRata(const double arr[], int size, double rata_rata) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= rata_rata) {
            count++;
        }
    }
    return count;
}

int main() {
    int n_values_count = 0;
    // Memanggil fungsi modular untuk membaca nilai
    double *data_values = bacaNilai(&n_values_count);

    if (data_values == NULL) {
        // Jika alokasi memori gagal, keluar dari program
        return 1;
    }

    // Memanggil fungsi modular untuk menghitung jumlah
    double total_sum = hitungJumlah(data_values, n_values_count);

    // Memanggil fungsi modular untuk menghitung rata-rata
    double average = hitungRataRata(data_values, n_values_count);

    // Memanggil fungsi baru untuk menghitung banyaknya nilai di atas atau sama dengan rata-rata
    int count_above_average = hitungDiAtasRataRata(data_values, n_values_count, average);

    // Mencetak jumlah seluruh nilai
    printf("%.0f\n", total_sum);

    // Mencetak nilai rata-rata dengan 2 digit presisi di belakang koma
    printf("%.2f\n", average);

    // Mencetak banyaknya nilai yang di atas atau sama dengan rata-rata
    printf("%d\n", count_above_average);

    // Membebaskan memori yang dialokasikan secara dinamis
    free(data_values);

    return 0;
}