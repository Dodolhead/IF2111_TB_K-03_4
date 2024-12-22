int main() {
    printf("[DEBUG] Memulai program START_DRIVER...\n");

    // Jalankan konfigurasi dengan file "config.txt"
    START_PURRMART("config.txt");

    // Debug data barang
    printf("\n=== DEBUG BARANG ===\n");
    debugBarang();

    // Debug data pengguna
    printf("\n=== DEBUG PENGGUNA ===\n");
    debugPengguna();

    // Debug data antrian permintaan
    printf("\n=== DEBUG ANTRIAN ===\n");
    debugAntrian();

    printf("\n[DEBUG] Program START_DRIVER selesai.\n");
    return 0;
}
