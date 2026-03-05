#include <stdio.h>  // Untuk input/output standar seperti printf dan scanf
#include <stdlib.h> // Untuk alokasi memori dinamis (malloc, free)
#include <float.h>  // Untuk DBL_MAX dan DBL_MIN yang digunakan dalam pencarian min/max

// Fungsi untuk membaca sejumlah nilai dari input
// Mengembalikan pointer ke array nilai yang dialokasikan secara dinamis
// dan mengisi jumlah elemen ke dalam n_count
double* bacaNilai(int *n_count) {
    int n;
    scanf("%d", &n); // Membaca jumlah nilai (n)
    *n_count = n;

    // Jika n adalah 0 atau negatif, tidak perlu alokasi memori
    if (n <= 0) {
        return NULL;
    }

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

// Fungsi baru untuk mencari nilai minimum dalam array
double cariMinimum(const double arr[], int size) {
    if (size == 0) {
        return DBL_MAX; // Mengembalikan nilai maksimum double jika array kosong
    }
    double min_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    return min_val;
}

// Fungsi baru untuk mencari nilai maksimum dalam array
double cariMaksimum(const double arr[], int size) {
    if (size == 0) {
        return DBL_MIN; // Mengembalikan nilai minimum double jika array kosong
    }
    double max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

int main() {
    int n_values_count = 0;
    // Memanggil fungsi modular untuk membaca nilai
    double *data_values = bacaNilai(&n_values_count);

    if (data_values == NULL && n_values_count > 0) { // Jika alokasi memori gagal dan n > 0
        return 1; // Keluar dari program dengan kode error
    }

    // Jika tidak ada nilai yang dibaca (n=0)
    if (n_values_count == 0) {
        printf("0\n0.00\n0\n0\n"); // Output default untuk n=0
        if (data_values != NULL) free(data_values);
        return 0;
    }

    // Memanggil fungsi modular untuk menghitung jumlah
    double total_sum = hitungJumlah(data_values, n_values_count);

    // Memanggil fungsi modular untuk menghitung rata-rata
    double average = hitungRataRata(data_values, n_values_count);

    // Memanggil fungsi baru untuk menghitung banyaknya nilai di atas atau sama dengan rata-rata
    int count_above_average = hitungDiAtasRataRata(data_values, n_values_count, average);

    // Memanggil fungsi baru untuk mencari nilai minimum
    double min_value = cariMinimum(data_values, n_values_count);

    // Memanggil fungsi baru untuk mencari nilai maksimum
    double max_value = cariMaksimum(data_values, n_values_count);

    // Menghitung rentang nilai
    double range = max_value - min_value;

    // Mencetak jumlah seluruh nilai
    printf("%.0f\n", total_sum);

    // Mencetak nilai rata-rata dengan 2 digit presisi di belakang koma
    printf("%.2f\n", average);

    // Mencetak banyaknya nilai yang di atas atau sama dengan rata-rata
    printf("%d\n", count_above_average);

    // Mencetak rentang nilai
    printf("%.0f\n", range); // Format .0f karena contoh output menunjukkan integer

    // Membebaskan memori yang dialokasikan secara dinamis
    free(data_values);

    return 0;
}