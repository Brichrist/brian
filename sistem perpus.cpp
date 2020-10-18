/*************************************************
 HEADER DAN MACRO
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define MAX_BUKU 25 // jumlah tipe buku di perpustakaan.
#define MAX_QUERY_PEMINJAM 25 // jumlah query peminjam buku di perpustakaan.

/*************************************************
 STRUKTUR DATA
*************************************************/

struct bukuDetail{ // setiap buku memiliki data ini.
	char kode_buku[7]; // nama buku memiliki format "[a-z][a-z][a-z][a-z][0-9][0-9]" (tanpa tanda petik), setiap tipe buku memiliki kode buku yang berbeda.
	char nama_buku[22]; // nama buku.
	char nama_pengarang[19]; // nama pengarang.
	int stok_buku; // stok buku di perpustakaan.
	char tanggal_buku_masuk[11]; // tanggal buku dimasukkan di perpustakaan, dengan format "dd/mm/yyyy" (tanpa tanda petik).
};

struct peminjam_buku{ // setiap peminjam buku memiliki data ini (yang disimpan).
	char nama_peminjam[24]; // nama peminjam.
	char kode_buku_dipinjam[7]; // kode buku yang dipinjam.
	int jumlah_buku_dipinjam; // jumlah buku yang dipinjam untuk kode buku terkait.
	char tanggal_buku_dipinjam[11]; // tanggal buku dipinjam, dengan format "dd/mm/yyyy" (tanpa tanda petik).
	char tanggal_buku_dikembalikan[11]; // tanggal buku dikembalikan, dengan format "dd/mm/yyyy" (tanpa tanda petik).
};

struct Perpustakaan{ // perpustakaan memiliki data ini.
	struct bukuDetail buku[MAX_BUKU]; // perpustakaan menampung buku sejumlah MAX_BUKU.
	struct peminjam_buku peminjam[MAX_QUERY_PEMINJAM]; // perpustakaan menyimpan data query peminjam buku sejumlah MAX_QUERY_PEMINJAM.
	int JUMLAH_BUKU; // jumlah buku di perpustakaan saat ini.
	int JUMLAH_PEMINJAM; // jumlah peminjam buku di perpustakaan saat ini.
};

typedef struct Perpustakaan Perpus; // mengganti inisialisasi "struct Perpustakaan" (tanpa tanda petik) dengan "Perpus" (tanpa tanda petik).
typedef struct bukuDetail _buku;
typedef struct peminjam_buku _peminjam;

/*************************************************
 FUNGSI UNTUK STARTUP FILE
*************************************************/

Perpus startup_buku(Perpus data){
	data.JUMLAH_BUKU=0; // jumlah buku di perpustakaan saat ini 0 (nol).
	
	return data;
}

Perpus startup_peminjam(Perpus data){
	data.JUMLAH_PEMINJAM=0; // jumlah peminjam buku saat ini 0 (nol).
	
	return data;
}

/*************************************************
 FUNGSI LAIN-LAIN
*************************************************/

void clear_screen(){
/*	int i;
	for(i=0; i<70; i++) puts("");
	
	return;*/ system("cls");
}

char *replace(char *kalimat, char ganti_ini, char dengan_ini){
	int i;
	for(i=0; i<strlen(kalimat); i++){
		if(kalimat[i]==ganti_ini) kalimat[i]=dengan_ini;
	}
	
	return kalimat;
}

void generate_kode_buku(char *kode_buku){
	srand(time(NULL));
	kode_buku[0] = rand()%26+'A';
	kode_buku[1] = rand()%26+'A';
	kode_buku[2] = rand()%26+'A';
	kode_buku[3] = rand()%26+'A';
	kode_buku[4] = rand()%10+'0';
	kode_buku[5] = rand()%10+'0';
	kode_buku[6] = '\0';
	
	return;
}

int cari_kode_buku(Perpus data, char *kode_buku){ // return indeks jika ditemukan; return -1 jika tidak ditemukan.

int n;
	
	for (n=0;n<data.JUMLAH_BUKU;++n){	
		if (strcmp(data.buku[n].kode_buku,kode_buku) == 0){
			return n;}
}
return -1;
}

int hitung_stok_buku_dipinjam(Perpus data, char *kode_buku){ // hitung stok buku yang dipinjam untuk kode buku terkait.
	int i, jumlah=0;
	for(i=0; i<data.JUMLAH_PEMINJAM; i++){
		if(strcmp(data.peminjam[i].kode_buku_dipinjam, kode_buku) == 0) jumlah += data.peminjam[i].jumlah_buku_dipinjam;
	}
	return jumlah;
}

int is_num(char cek_karakter){
	if(cek_karakter<'0' || cek_karakter>'9') return 0;
	return 1;
}

int cek_format_tanggal(char *tanggal){
	// jika tidak sesuai format, return 0.
	if(!is_num(tanggal[0]) || !is_num(tanggal[1]) || tanggal[2]!='/' || !is_num(tanggal[3]) || !is_num(tanggal[4]) || tanggal[5]!='/' || !is_num(tanggal[6]) || !is_num(tanggal[7]) || !is_num(tanggal[8]) || !is_num(tanggal[9])) return 0;
	
	// sesuaikan digit tanggal.
	if(tanggal[0]>'3') return 0;
	if(tanggal[0]=='3' && tanggal[1]>'1') return 0;
	if(tanggal[0]=='0' && tanggal[1]=='0') return 0;
	
	// sesuaikan digit bulan.
	if(tanggal[3]>'1') return 0;
	if(tanggal[3]=='1' && tanggal[4]>'2') return 0;
	if(tanggal[3]=='0' && tanggal[4]=='0') return 0;
	
	// sesuaikan digit tanggal di bulan tertentu.
	if(tanggal[3]=='0' && tanggal[4]=='2'){ // Februari.
		if(tanggal[0]=='3') return 0;
		if(tanggal[0]=='2' && tanggal[1]=='9'){
			if( ( (tanggal[8]-'0')*10 + (tanggal[9]-'0') ) % 4 != 0 ) return 0; // jika bukan tahun kabisat.
		}
	}
	else{
		if(tanggal[4]<'7' && (tanggal[4]-'0')%2==0){ // April atau Juni.
			if(tanggal[0]=='3' && tanggal[1]=='1') return 0;
		}
		else{
			if(tanggal[4]=='9' || tanggal[4]=='1'){ // September atau November.
				if(tanggal[0]=='3' && tanggal[1]=='1') return 0;
			}
		}
	}
	
	return 1;
}

int cek_format_kode_buku(char *kode_buku){
	if(!isupper(kode_buku[0])) return 0;
	if(!isupper(kode_buku[1])) return 0;
	if(!isupper(kode_buku[2])) return 0;
	if(!isupper(kode_buku[3])) return 0;
	if(!is_num(kode_buku[4])) return 0;
	if(!is_num(kode_buku[5])) return 0;
	return 1;
}

void tukar_buku(_buku *data_1, _buku *data_2){
	_buku temp = *data_1;
	*data_1 = *data_2;
	*data_2 = temp;
	
	return;
}

void tukar_peminjam(_peminjam *data_1, _peminjam *data_2){
	_peminjam temp = *data_1;
	*data_1 = *data_2;
	*data_2 = temp;
	
	return;
}

int konversi_tanggal_ke_int(char *tanggal){
	char temp[11];
	
	// 4 digit pertama untuk tahun.
	temp[0] = tanggal[6];
	temp[1] = tanggal[7];
	temp[2] = tanggal[8];
	temp[3] = tanggal[9];
	
	// 2 digit berikutnya untuk bulan.
	temp[4] = tanggal[3];
	temp[5] = tanggal[4];
	
	// 2 digit berikutnya untuk tanggal.
	temp[6] = tanggal[0];
	temp[7] = tanggal[1];
	
	// terakhir.
	temp[8] = '\0';
	
	return atoi(temp);
}

int jumlah_pinjam_buku(Perpus *data, int indeks_sekarang){ // hitung total jumlah peminjaman buku (kode buku apapun) dengan nama peminjam sama.
	int i;
	int temp = 0;
	
	for(i=0; i<data->JUMLAH_PEMINJAM; i++){
		if(strcmp( data->peminjam[i].nama_peminjam, data->peminjam[indeks_sekarang].nama_peminjam ) == 0) temp += data->peminjam[i].jumlah_buku_dipinjam;
	}
	
	return temp;
}

void urutkan_buku_tanggal(Perpus *data, int status){ // status = 0 untuk ascending, 1 untuk descending.
	int i;
	int tanggal[data->JUMLAH_BUKU]; // simpan hasil konversi tanggal ke int (untuk mempermudah pengurutan).
	
	for(i=0; i<data->JUMLAH_BUKU; i++){
		tanggal[i] = konversi_tanggal_ke_int( data->buku[i].tanggal_buku_masuk );
	}
	
	int flag;
	int temp; // untuk menukar variabel "tanggal" (tanpa tanda petik) setelah data ditukar (karena terpisah dari data).
	do{
		flag=0; // belum ada pertukaran.
		
		for(i=0; i<data->JUMLAH_BUKU-1; i++){
			if(tanggal[i] > tanggal[i+1] && status==0){ // seleksi ascending.
				tukar_buku(&data->buku[i], &data->buku[i+1]);
				flag=1;
				
				temp = tanggal[i];
				tanggal[i] = tanggal[i+1];
				tanggal[i+1] = temp;
			}
			
			if(tanggal[i] < tanggal[i+1] && status==1){ // seleksi descending.
				tukar_buku(&data->buku[i], &data->buku[i+1]);
				flag=1;
				
				temp = tanggal[i];
				tanggal[i] = tanggal[i+1];
				tanggal[i+1] = temp;
			}
		}
	} while(flag==1); // bubble sort: selama masih ada pertukaran, kompleksitas O(n^2).
	
	return;
}

void urutkan_peminjam_tanggal_pinjam(Perpus *data, int status){ // status = 0 untuk ascending, 1 untuk descending.
	int i;
	int tanggal[data->JUMLAH_PEMINJAM]; // simpan hasil konversi tanggal ke int (untuk mempermudah pengurutan).
	
	for(i=0; i<data->JUMLAH_PEMINJAM; i++){
		tanggal[i] = konversi_tanggal_ke_int( data->peminjam[i].tanggal_buku_dipinjam );
	}
	
	int flag;
	int temp; // untuk menukar variabel "tanggal" (tanpa tanda petik) setelah data ditukar (karena terpisah dari data).
	do{
		flag=0; // belum ada pertukaran.
		
		for(i=0; i<data->JUMLAH_PEMINJAM-1; i++){
			if(tanggal[i] > tanggal[i+1] && status==0){ // seleksi ascending.
				tukar_peminjam(&data->peminjam[i], &data->peminjam[i+1]);
				flag=1;
				
				temp = tanggal[i];
				tanggal[i] = tanggal[i+1];
				tanggal[i+1] = temp;
			}
			
			if(tanggal[i] < tanggal[i+1] && status==1){ // seleksi descending.
				tukar_peminjam(&data->peminjam[i], &data->peminjam[i+1]);
				flag=1;
				
				temp = tanggal[i];
				tanggal[i] = tanggal[i+1];
				tanggal[i+1] = temp;
			}
		}
	} while(flag==1); // bubble sort: selama masih ada pertukaran, kompleksitas O(n^2).
	
	return;
}

void urutkan_peminjam_tanggal_kembali(Perpus *data, int status){ // status = 0 untuk ascending, 1 untuk descending.
	int i;
	int tanggal[data->JUMLAH_PEMINJAM]; // simpan hasil konversi tanggal ke int (untuk mempermudah pengurutan).
	
	for(i=0; i<data->JUMLAH_PEMINJAM; i++){
		tanggal[i] = konversi_tanggal_ke_int( data->peminjam[i].tanggal_buku_dikembalikan );
	}
	
	int flag;
	int temp; // untuk menukar variabel "tanggal" (tanpa tanda petik) setelah data ditukar (karena terpisah dari data).
	do{
		flag=0; // belum ada pertukaran.
		
		for(i=0; i<data->JUMLAH_PEMINJAM-1; i++){
			if(tanggal[i] > tanggal[i+1] && status==0){ // seleksi ascending.
				tukar_peminjam(&data->peminjam[i], &data->peminjam[i+1]);
				flag=1;
				
				temp = tanggal[i];
				tanggal[i] = tanggal[i+1];
				tanggal[i+1] = temp;
			}
			
			if(tanggal[i] < tanggal[i+1] && status==1){ // seleksi descending.
				tukar_peminjam(&data->peminjam[i], &data->peminjam[i+1]);
				flag=1;
				
				temp = tanggal[i];
				tanggal[i] = tanggal[i+1];
				tanggal[i+1] = temp;
			}
		}
	} while(flag==1); // bubble sort: selama masih ada pertukaran, kompleksitas O(n^2).
	
	return;
}

void urutkan_peminjam_nama_dan_jumlah(Perpus *data, int status){ // status = 0 untuk ascending, 1 untuk descending.
	int i;
	
	int flag;
	do{
		flag=0; // belum ada pertukaran.
		
		for(i=0; i<data->JUMLAH_PEMINJAM-1; i++){
			if( jumlah_pinjam_buku(*&data, i) > jumlah_pinjam_buku(*&data, i+1) && status==0 ){ // seleksi ascending.
				tukar_peminjam(&data->peminjam[i], &data->peminjam[i+1]);
				flag=1;
			}
			
			if( jumlah_pinjam_buku(*&data, i) < jumlah_pinjam_buku(*&data, i+1) && status==1){ // seleksi descending.
				tukar_peminjam(&data->peminjam[i], &data->peminjam[i+1]);
				flag=1;
			}
		}
	} while(flag==1); // bubble sort: selama masih ada pertukaran, kompleksitas O(n^2).
	
	return;
}

/*************************************************
 FUNGSI UNTUK OPERASI FILE (BACA DAN TULIS)
*************************************************/

void file_baca_data_buku(Perpus *data){
	if(fopen("buku.txt", "r+")!=NULL){
		FILE *pointer_file = fopen("buku.txt", "r+");
		
		fscanf(pointer_file, "%d\n", &data->JUMLAH_BUKU);
		
		if(data->JUMLAH_BUKU!=0){
			fscanf(pointer_file, "=================================================\n");
			fscanf(pointer_file, "=            DAFTAR BUKU PERPUSTAKAAN           =\n");
			fscanf(pointer_file, "=================================================\n\n");
			
			fscanf(pointer_file, "==============================================================================================\n");
			fscanf(pointer_file, "=  Kode Buku  =        Nama Buku        =    Nama Pengarang    =   Tgl Masuk   =  Stok Buku  =\n");
			fscanf(pointer_file, "==============================================================================================\n");
			
			int i;
			for(i=0; i<data->JUMLAH_BUKU; i++){
				fscanf(pointer_file, "=");
				fscanf(pointer_file, "  %s  =", data->buku[i].kode_buku);
				fscanf(pointer_file, "  %s  =", data->buku[i].nama_buku);
				fscanf(pointer_file, "  %s  =", data->buku[i].nama_pengarang);
				fscanf(pointer_file, "  %s  =", data->buku[i].tanggal_buku_masuk);
				fscanf(pointer_file, "  %d  =\n", &data->buku[i].stok_buku);
				
				strcpy(data->buku[i].nama_buku, replace(*&data->buku[i].nama_buku, '_', ' '));
				strcpy(data->buku[i].nama_pengarang, replace(*&data->buku[i].nama_pengarang, '_', ' '));
			}
			
			fscanf(pointer_file, "==============================================================================================");
		}
		
		fclose(pointer_file);
	}
	else{
		puts("File \"buku.txt\" tidak ditemukan.");
		
		FILE *pointer_file = fopen("buku.txt", "w+");
		fprintf(pointer_file, "0\n");
		
		*data = startup_buku(*data);
		
		puts("File \"buku.txt\" sudah dibuat.");
		
		fclose(pointer_file);
	}
	
	return;
}

void file_baca_data_peminjam(Perpus *data){
	if(fopen("perpustakaan.txt", "r+")!=NULL){
		FILE *pointer_file = fopen("perpustakaan.txt", "r+");
		
		fscanf(pointer_file, "%d\n", &data->JUMLAH_PEMINJAM);
		
		if(data->JUMLAH_PEMINJAM!=0){
			fscanf(pointer_file, "=================================================\n");
			fscanf(pointer_file, "=             DAFTAR PEMINJAMAN BUKU            =\n");
			fscanf(pointer_file, "=================================================\n\n");
			
			fscanf(pointer_file, "==============================================================================================\n");
			fscanf(pointer_file, "=  Tgl Pinjam  =  Tgl Kembali  =  Kode Buku  =       Nama Peminjam       =  Jumlah Dipinjam  =\n");
			fscanf(pointer_file, "==============================================================================================\n");
			
			int i;
			for(i=0; i<data->JUMLAH_PEMINJAM; i++){
				fscanf(pointer_file, "=");
				fscanf(pointer_file, "  %s  =", data->peminjam[i].tanggal_buku_dipinjam);
				fscanf(pointer_file, "  %s  =", data->peminjam[i].tanggal_buku_dikembalikan);
				fscanf(pointer_file, "  %s  =", data->peminjam[i].kode_buku_dipinjam);
				fscanf(pointer_file, "  %s  =", data->peminjam[i].nama_peminjam);
				fscanf(pointer_file, "  %d  =\n", &data->peminjam[i].jumlah_buku_dipinjam);
				
				strcpy(data->peminjam[i].nama_peminjam, replace(*&data->peminjam[i].nama_peminjam, '_', ' '));
			}
			
			fscanf(pointer_file, "==============================================================================================");
		}
		
		fclose(pointer_file);
	}
	else{
		puts("File \"perpustakaan.txt\" tidak ditemukan.");
		
		FILE *pointer_file = fopen("perpustakaan.txt", "w+");
		fprintf(pointer_file, "0\n");
		
		*data = startup_peminjam(*data);
		
		puts("File \"perpustakaan.txt\" sudah dibuat.");
		
		fclose(pointer_file);
	}
	
	return;
}

void file_tulis_data_buku(Perpus *data){
	if(fopen("buku.txt", "r+")!=NULL){
		FILE *pointer_file = fopen("buku.txt", "w+");
		
		fprintf(pointer_file, "%d\n", data->JUMLAH_BUKU);
		
		if(data->JUMLAH_BUKU!=0){
			fprintf(pointer_file, "=================================================\n");
			fprintf(pointer_file, "=            DAFTAR BUKU PERPUSTAKAAN           =\n");
			fprintf(pointer_file, "=================================================\n\n");
			
			fprintf(pointer_file, "==============================================================================================\n");
			fprintf(pointer_file, "=  Kode Buku  =        Nama Buku        =    Nama Pengarang    =   Tgl Masuk   =  Stok Buku  =\n");
			fprintf(pointer_file, "==============================================================================================\n");
			
			int i;
			for(i=0; i<data->JUMLAH_BUKU; i++){
				strcpy(data->buku[i].nama_buku, replace(*&data->buku[i].nama_buku, ' ', '_'));
				strcpy(data->buku[i].nama_pengarang, replace(*&data->buku[i].nama_pengarang, ' ', '_'));
				
				fprintf(pointer_file, "=");
				fprintf(pointer_file, " %9s =", data->buku[i].kode_buku);
				fprintf(pointer_file, " %21s =", data->buku[i].nama_buku);
				fprintf(pointer_file, " %18s =", data->buku[i].nama_pengarang);
				fprintf(pointer_file, " %11s =", data->buku[i].tanggal_buku_masuk);
				fprintf(pointer_file, " %9d =\n", data->buku[i].stok_buku);
			}
			
			fprintf(pointer_file, "==============================================================================================");
		}
		
		fclose(pointer_file);
	}
	else{
		puts("File \"buku.txt\" tidak ditemukan.");
		
		FILE *pointer_file = fopen("buku.txt", "w+");
		fprintf(pointer_file, "0\n");
		
		puts("File \"buku.txt\" sudah dibuat.");
		
		fclose(pointer_file);
		
		file_tulis_data_buku(*&data);
	}
	
	return;
}

void file_tulis_data_peminjam(Perpus *data){
	if(fopen("perpustakaan.txt", "r+")!=NULL){
		FILE *pointer_file = fopen("perpustakaan.txt", "w+");
		
		fprintf(pointer_file, "%d\n", data->JUMLAH_PEMINJAM);
		
		if(data->JUMLAH_PEMINJAM!=0){
			fprintf(pointer_file, "=================================================\n");
			fprintf(pointer_file, "=             DAFTAR PEMINJAMAN BUKU            =\n");
			fprintf(pointer_file, "=================================================\n\n");
			
			fprintf(pointer_file, "==============================================================================================\n");
			fprintf(pointer_file, "=  Tgl Pinjam  =  Tgl Kembali  =  Kode Buku  =       Nama Peminjam       =  Jumlah Dipinjam  =\n");
			fprintf(pointer_file, "==============================================================================================\n");
			
			int i;
			for(i=0; i<data->JUMLAH_PEMINJAM; i++){
				strcpy(data->peminjam[i].nama_peminjam, replace(*&data->peminjam[i].nama_peminjam, ' ', '_'));
				
				fprintf(pointer_file, "=");
				fprintf(pointer_file, " %10s =", data->peminjam[i].tanggal_buku_dipinjam);
				fprintf(pointer_file, " %11s =", data->peminjam[i].tanggal_buku_dikembalikan);
				fprintf(pointer_file, " %9s  =", data->peminjam[i].kode_buku_dipinjam);
				fprintf(pointer_file, " %23s =", data->peminjam[i].nama_peminjam);
				fprintf(pointer_file, " %15d =\n", data->peminjam[i].jumlah_buku_dipinjam);
			}
			
			fprintf(pointer_file, "==============================================================================================");
		}
		
		fclose(pointer_file);
	}
	else{
		puts("File \"perpustakaan.txt\" tidak ditemukan.");
		
		FILE *pointer_file = fopen("perpustakaan.txt", "w+");
		fprintf(pointer_file, "0\n");
		
		puts("File \"perpustakaan.txt\" sudah dibuat.");
		
		fclose(pointer_file);
		
		file_tulis_data_peminjam(*&data);
	}
	
	return;
}

/*************************************************
 FUNGSI UNTUK TAMPILAN MENU
*************************************************/

int menu_ascending_atau_descending(){
	int temp;
	
	puts("");
	puts("Pilihan sort: ");
	puts("1. Ascending (dari kecil ke besar).");
	puts("2. Descending (dari besar ke kecil).");
	
	do{
		puts("");
		printf("Pilihan anda [1-2]: ");
		scanf("%d", &temp);
	}
	while(temp<1 || temp>2);
	
	return (temp-1); // 0 untuk ascending, 1 untuk descending.
}

void menu_tampilkan_data_buku(Perpus *data){
	if(data->JUMLAH_BUKU==0){
		puts("Tidak ada buku di perpustakaan.");
	}
	else{
		clear_screen();
		puts("=================================================");
		puts("=            DAFTAR BUKU PERPUSTAKAAN           =");
		puts("=================================================");
		puts("\n");
		
		puts("==========================================================================");
		puts("=KodeBuku=      Nama Buku       =   Nama Pengarang   = Tgl Masuk  = Stok =");
		puts("==========================================================================");
		
		int i;
		for(i=0; i<data->JUMLAH_BUKU; i++){
			printf("=");
			printf(" %-6s =", data->buku[i].kode_buku);
			printf(" %-20s =", data->buku[i].nama_buku);
			printf(" %-18s =", data->buku[i].nama_pengarang);
			printf(" %-10s =", data->buku[i].tanggal_buku_masuk);
			printf(" %-4d =", data->buku[i].stok_buku);
			puts("");
		}
		
		puts("==========================================================================");
		printf("\nKapasitas buku di perpustakaan = %d / %d.", data->JUMLAH_BUKU, MAX_BUKU); puts("");
	}
	
	return;
}

void menu_tampilkan_data_peminjam(Perpus *data){
	if(data->JUMLAH_PEMINJAM==0){
		printf("Tidak ada peminjaman buku.");
	}
	else{
		clear_screen();
		puts("=================================================");
		puts("=             DAFTAR PEMINJAMAN BUKU            =");
		puts("=================================================");
		puts("\n");
		
		puts("==========================================================================");
		puts("= Tgl Pinjam = TglKembali =KodeBuku=     Nama Peminjam    = Jml Dipinjam =");
		puts("==========================================================================");
		
		int i;
		for(i=0; i<data->JUMLAH_PEMINJAM; i++){
			printf("=");
			printf(" %-10s =", data->peminjam[i].tanggal_buku_dipinjam);
			printf(" %-10s =", data->peminjam[i].tanggal_buku_dikembalikan);
			printf(" %-6s =", data->peminjam[i].kode_buku_dipinjam);
			printf(" %-20s =", data->peminjam[i].nama_peminjam);
			printf(" %-12d =", data->peminjam[i].jumlah_buku_dipinjam);
			puts("");
		}
		
		puts("==========================================================================");
		printf("\nBatasan jumlah peminjaman buku = %d / %d.", data->JUMLAH_PEMINJAM, MAX_QUERY_PEMINJAM); puts("");
	}
	
	return;
}

void menu_tampilkan_data_peminjam_merged(Perpus *data, int status){ // status = 0 untuk ascending, 1 untuk descending.
	if(data->JUMLAH_PEMINJAM==0){
		printf("Tidak ada peminjaman buku.");
	}
	else{
		urutkan_peminjam_nama_dan_jumlah(*&data, status);
		
		clear_screen();
		puts("=================================================");
		puts("=             DAFTAR PEMINJAMAN BUKU            =");
		puts("=================================================");
		puts("\n");
		
		puts("=================================================");
		puts("=       Nama Peminjam       =  Jumlah Dipinjam  =");
		puts("=================================================");
		
		int i;
		for(i=0; i<data->JUMLAH_PEMINJAM; i++){
			if( strcmp(data->peminjam[i].nama_peminjam, data->peminjam[i+1].nama_peminjam) == 0 ){
				continue;
			}
			else{
				printf("=");
				printf("  %-23s  =", data->peminjam[i].nama_peminjam);
				printf("  %-15d  =", jumlah_pinjam_buku(*&data, i) );
				puts("");
			}
		}
		
		puts("=================================================");
		printf("\nBatasan jumlah peminjaman buku = %d / %d.", data->JUMLAH_PEMINJAM, MAX_QUERY_PEMINJAM); puts("");
	}
	
	return;
}

void menu_input_data_buku(Perpus *data){
	if(data->JUMLAH_BUKU==MAX_BUKU){
		puts("Maaf, jumlah tipe buku di perpustakaan sudah penuh.");
		return;
	}
	
	int dikonfirmasi=0;
	char konfirmasi_input[10];
	
	do{
		clear_screen();
		generate_kode_buku(*&data->buku[data->JUMLAH_BUKU].kode_buku);
		
		do{
			printf("Nama Buku [1-21]: ");
			gets( data->buku[data->JUMLAH_BUKU].nama_buku );
		} while( strlen(data->buku[data->JUMLAH_BUKU].nama_buku)<1 || strlen(data->buku[data->JUMLAH_BUKU].nama_buku)>21 || data->buku[data->JUMLAH_BUKU].nama_buku[0]==' ' );
		
		do{
			printf("Nama Pengarang [1-18]: ");
			gets( data->buku[data->JUMLAH_BUKU].nama_pengarang );
		} while( strlen(data->buku[data->JUMLAH_BUKU].nama_pengarang)<1 || strlen(data->buku[data->JUMLAH_BUKU].nama_pengarang)>18 || data->buku[data->JUMLAH_BUKU].nama_pengarang[0]==' ' );
		
		do{
			printf("Tanggal Stok Buku [DD/MM/YYYY]: ");
			gets( data->buku[data->JUMLAH_BUKU].tanggal_buku_masuk );
		} while( strlen(data->buku[data->JUMLAH_BUKU].tanggal_buku_masuk)!=10 || cek_format_tanggal( *&data->buku[data->JUMLAH_BUKU].tanggal_buku_masuk ) == 0 );
		
		do{
			printf("Stok Buku Masuk [0-1000]: ");
			scanf("%d", &data->buku[data->JUMLAH_BUKU].stok_buku);
			getchar();
		} while( data->buku[data->JUMLAH_BUKU].stok_buku<0 || data->buku[data->JUMLAH_BUKU].stok_buku>1000 );
		
		puts("");
		printf("Kode Buku        : %s", data->buku[data->JUMLAH_BUKU].kode_buku); puts("");
		printf("Nama Buku        : %s", data->buku[data->JUMLAH_BUKU].nama_buku); puts("");
		printf("Nama Pengarang   : %s", data->buku[data->JUMLAH_BUKU].nama_pengarang); puts("");
		printf("Tanggal Stok Buku: %s", data->buku[data->JUMLAH_BUKU].tanggal_buku_masuk); puts("");
		printf("Stok Buku Masuk  : %d", data->buku[data->JUMLAH_BUKU].stok_buku); puts(""); puts("");
		
		fflush(stdin);
		do{
			puts(""); printf("Apakah data buku di atas sudah benar \n[Y -> input data, N -> ulang proses, X -> batalkan input]? ");
			gets(konfirmasi_input);
		} while(strlen(konfirmasi_input)!=1 || ( konfirmasi_input[0]!='Y' && konfirmasi_input[0]!='N' && konfirmasi_input[0]!='X' ) );
		
		switch(konfirmasi_input[0]){
			case 'Y':
				data->JUMLAH_BUKU++; // tanpa break.
				puts("Data buku telah dicatat.");
				file_tulis_data_buku(*&data);
			case 'X':
				dikonfirmasi=1;
		}
	} while(dikonfirmasi==0);
	
	return;
}

void menu_input_data_peminjam(Perpus *data){
	if(data->JUMLAH_PEMINJAM==MAX_QUERY_PEMINJAM){
		puts("Maaf, jumlah peminjaman buku telah melampaui batas yang dicatat.");
		return;
	}
	
	int dikonfirmasi=0;
	char konfirmasi_input[10];
	
	int indeks; // simpan indeks dari kode buku yang akan dipinjam.
	int stok_buku_dipinjam, stok_buku_tersedia; // simpan stok buku yang dipinjam dan yang dapat dipinjam (tersedia).
	
	do{	
		do{
			clear_screen();
			
			do{
				printf("Kode Buku yang akan Dipinjam [A-Z][A-Z][A-Z][A-Z][0-9][0-9]: ");
				gets( data->peminjam[data->JUMLAH_PEMINJAM].kode_buku_dipinjam );
			} while( strlen(data->peminjam[data->JUMLAH_PEMINJAM].kode_buku_dipinjam)!=6 || cek_format_kode_buku(*&data->peminjam[data->JUMLAH_PEMINJAM].kode_buku_dipinjam) == 0);
			
			indeks = cari_kode_buku(*data, *&data->peminjam[data->JUMLAH_PEMINJAM].kode_buku_dipinjam);
			
			puts("");
			if(indeks != -1){
				puts("Anda akan meminjam buku: ");
				printf("Kode Buku         : %s", data->buku[indeks].kode_buku); puts("");
				printf("Nama Buku         : %s", data->buku[indeks].nama_buku); puts("");
				printf("Nama Pengarang    : %s", data->buku[indeks].nama_pengarang); puts("");
				printf("Tanggal Stok Buku : %s", data->buku[indeks].tanggal_buku_masuk); puts("");
				printf("Stok Buku Masuk   : %d", data->buku[indeks].stok_buku); puts("");
				
				stok_buku_dipinjam = hitung_stok_buku_dipinjam(*data, data->peminjam[data->JUMLAH_PEMINJAM].kode_buku_dipinjam);
				
				if(stok_buku_dipinjam < data->buku[indeks].stok_buku){
					stok_buku_tersedia = data->buku[indeks].stok_buku - stok_buku_dipinjam;
					printf("Stok Buku Tersedia: %d", stok_buku_tersedia); puts("");
				}
				else{
					puts("");
					puts("Maaf, saat ini buku yang anda pilih tidak tersedia.");
					return;
				}
			}
			else{
				puts("Buku yang anda cari tidak ditemukan.");
				return;
			}
			
			fflush(stdin);
			do{
				puts(""); printf("Apakah anda ingin melanjutkan peminjaman buku \n[Y -> lanjutkan, N -> cari buku lain, X -> batalkan peminjaman]? ");
				gets(konfirmasi_input);
			} while(strlen(konfirmasi_input)!=1 || ( konfirmasi_input[0]!='Y' && konfirmasi_input[0]!='N' && konfirmasi_input[0]!='X' ) );
			
			switch(konfirmasi_input[0]){
				case 'Y':
					dikonfirmasi=1;
					break;
				case 'X':
					puts("Peminjaman buku dibatalkan.");
					return;
			}
		} while(dikonfirmasi == 0);
		dikonfirmasi=0; // variabel akan digunakan kembali.
		
		do{
			printf("\nNama Peminjam [1-23]: ");
			gets( data->peminjam[data->JUMLAH_PEMINJAM].nama_peminjam );
		} while( strlen(data->peminjam[data->JUMLAH_PEMINJAM].nama_peminjam)<1 || strlen(data->peminjam[data->JUMLAH_PEMINJAM].nama_peminjam)>23 || data->peminjam[data->JUMLAH_PEMINJAM].nama_peminjam[0]==' ' );
		
		do{
			printf("Tanggal Buku Dipinjam [DD/MM/YYYY]: ");
			gets( data->peminjam[data->JUMLAH_PEMINJAM].tanggal_buku_dipinjam );
		} while( strlen(data->peminjam[data->JUMLAH_PEMINJAM].tanggal_buku_dipinjam)!=10 || cek_format_tanggal( *&data->peminjam[data->JUMLAH_PEMINJAM].tanggal_buku_dipinjam ) == 0 );
		
		do{
			printf("Tanggal Buku Dikembalikan [DD/MM/YYYY]: ");
			gets( data->peminjam[data->JUMLAH_PEMINJAM].tanggal_buku_dikembalikan );
		} while( strlen(data->peminjam[data->JUMLAH_PEMINJAM].tanggal_buku_dikembalikan)!=10 || cek_format_tanggal( *&data->peminjam[data->JUMLAH_PEMINJAM].tanggal_buku_dikembalikan ) == 0 );
		
		do{
			printf("Jumlah Buku yang Dipinjam [0-%d]: ", stok_buku_tersedia);
			scanf("%d", &data->peminjam[data->JUMLAH_PEMINJAM].jumlah_buku_dipinjam);
			getchar();
		} while( data->peminjam[data->JUMLAH_PEMINJAM].jumlah_buku_dipinjam<0 || data->peminjam[data->JUMLAH_PEMINJAM].jumlah_buku_dipinjam > stok_buku_tersedia );
		
		puts("");
		printf("Kode Buku Dipinjam: %s", data->peminjam[data->JUMLAH_PEMINJAM].kode_buku_dipinjam); puts("");
		printf("Nama Peminjam     : %s", data->peminjam[data->JUMLAH_PEMINJAM].nama_peminjam); puts("");
		printf("Tanggal Pinjam    : %s", data->peminjam[data->JUMLAH_PEMINJAM].tanggal_buku_dipinjam); puts("");
		printf("Tanggal Kembali   : %s", data->peminjam[data->JUMLAH_PEMINJAM].tanggal_buku_dikembalikan); puts("");
		printf("Stok Buku Dipinjam: %d", data->peminjam[data->JUMLAH_PEMINJAM].jumlah_buku_dipinjam); puts(""); puts("");
		
		fflush(stdin);
		do{
			puts(""); printf("Apakah data peminjaman buku di atas sudah benar \n[Y -> input data, N -> ulang proses, X -> batalkan input]? ");
			gets(konfirmasi_input);
		} while(strlen(konfirmasi_input)!=1 || ( konfirmasi_input[0]!='Y' && konfirmasi_input[0]!='N' && konfirmasi_input[0]!='X' ) );
		
		switch(konfirmasi_input[0]){
			case 'Y':
				data->JUMLAH_PEMINJAM++; // tanpa break.
				puts("Data peminjaman telah dicatat.");
				file_tulis_data_peminjam(*&data);
			case 'X':
				dikonfirmasi=1;
		}
	} while(dikonfirmasi==0);
	
	return;
}

void menu_edit_data_buku(Perpus *data){
	if(data->JUMLAH_BUKU==0){
		puts("Tidak ada buku di perpustakaan.");
		return;
	}
	
	int dikonfirmasi=0;
	char konfirmasi_input[10];
	
	char kode_buku[7];
	int indeks; // simpan indeks dari kode buku yang akan diubah.
	
	do{
		do{
			clear_screen();
			
			do{
				printf("Kode Buku yang akan Diubah [A-Z][A-Z][A-Z][A-Z][0-9][0-9]: ");
				gets(kode_buku);
			} while(strlen(kode_buku)!=6 || cek_format_kode_buku(kode_buku)==0);
			
			indeks = cari_kode_buku(*data, kode_buku);
			
			puts("");
			if(indeks != -1){
				puts("Anda akan mengubah data buku: ");
				printf("Kode Buku         : %s", data->buku[indeks].kode_buku); puts("");
				printf("Nama Buku         : %s", data->buku[indeks].nama_buku); puts("");
				printf("Nama Pengarang    : %s", data->buku[indeks].nama_pengarang); puts("");
				printf("Tanggal Stok Buku : %s", data->buku[indeks].tanggal_buku_masuk); puts("");
				printf("Stok Buku Masuk   : %d", data->buku[indeks].stok_buku); puts("");
			}
			else{
				puts("Buku yang anda cari tidak ditemukan.");
				return;
			}
			
			fflush(stdin);
			do{
				puts(""); printf("Apakah anda ingin melanjutkan pengubahan data buku \n[Y -> lanjutkan, N -> cari buku lain, X -> batalkan pengubahan]? ");
				gets(konfirmasi_input);
			} while(strlen(konfirmasi_input)!=1 || ( konfirmasi_input[0]!='Y' && konfirmasi_input[0]!='N' && konfirmasi_input[0]!='X' ) );
			
			switch(konfirmasi_input[0]){
				case 'Y':
					dikonfirmasi=1;
					break;
				case 'X':
					puts("Pengubahan data buku dibatalkan.");
					return;
			}
		} while(dikonfirmasi == 0);
		dikonfirmasi=0; // variabel akan digunakan kembali.
		
		do{
			printf("\nNama Buku [1-21]: ");
			gets( data->buku[indeks].nama_buku );
		} while( strlen(data->buku[indeks].nama_buku)<1 || strlen(data->buku[indeks].nama_buku)>21 || data->buku[indeks].nama_buku[0]==' ' );
		
		do{
			printf("Nama Pengarang [1-18]: ");
			gets( data->buku[indeks].nama_pengarang );
		} while( strlen(data->buku[indeks].nama_pengarang)<1 || strlen(data->buku[indeks].nama_pengarang)>18 || data->buku[indeks].nama_pengarang[0]==' ' );
		
		do{
			printf("Tanggal Stok Buku [DD/MM/YYYY]: ");
			gets( data->buku[indeks].tanggal_buku_masuk );
		} while( strlen(data->buku[indeks].tanggal_buku_masuk)!=10 || cek_format_tanggal( *&data->buku[indeks].tanggal_buku_masuk ) == 0 );
		
		do{
			printf("Stok Buku Masuk [0-1000]: ");
			scanf("%d", &data->buku[indeks].stok_buku);
			getchar();
		} while( data->buku[indeks].stok_buku<0 || data->buku[indeks].stok_buku>1000 );
		
		puts("");
		printf("Kode Buku        : %s", data->buku[indeks].kode_buku); puts("");
		printf("Nama Buku        : %s", data->buku[indeks].nama_buku); puts("");
		printf("Nama Pengarang   : %s", data->buku[indeks].nama_pengarang); puts("");
		printf("Tanggal Stok Buku: %s", data->buku[indeks].tanggal_buku_masuk); puts("");
		printf("Stok Buku Masuk  : %d", data->buku[indeks].stok_buku); puts(""); puts("");
		
		fflush(stdin);
		do{
			puts(""); printf("Apakah data buku di atas sudah benar \n[Y -> input data, N -> ulang proses, X -> batalkan input]? ");
			gets(konfirmasi_input);
		} while(strlen(konfirmasi_input)!=1 || ( konfirmasi_input[0]!='Y' && konfirmasi_input[0]!='N' && konfirmasi_input[0]!='X' ) );
		
		switch(konfirmasi_input[0]){
			case 'Y':
				dikonfirmasi=1;
				puts("Data buku telah dicatat.");
				file_tulis_data_buku(*&data);
				break;
			case 'X':
				dikonfirmasi=1;
				puts("Pengubahan data dibatalkan.");
				file_baca_data_buku(*&data);
				break;
		}
	} while(dikonfirmasi==0);
	
	return;
}

/*************************************************
 FUNGSI MAIN
*************************************************/

int main(){
	Perpus data;
	
	file_baca_data_buku(&data);
	file_baca_data_peminjam(&data);
	
	int pilihan;
	
	do{
		clear_screen();
		
		puts("=================================================");
		puts("=              PERPUSTAKAAN \"Library\"           ="); // stray '\' tidak dibaca (tambah 2 karakter).
		puts("=================================================");
		puts("1. Tampilkan Data Buku.");
		puts("2. Tampilkan Data Peminjaman Buku.");
		puts("3. Tampilkan Data Peminjaman Buku \n   (diurutkan berdasarkan nama peminjam yang sama dan total peminjaman).");
		puts("4. Masukkan Data Buku Baru.");
		puts("5. Masukkan Data Peminjaman Buku.");
		puts("6. Ubah Data Buku.");
//		puts("6. Urutkan Data Buku berdasarkan Tanggal Buku Masuk.");
//		puts("7. Urutkan Data Peminjaman Buku berdasarkan Tanggal Buku Dipinjam.");
//		puts("8. Urutkan Data Peminjaman Buku berdasarkan Tanggal Buku Dikembalikan.");
		
		do{
			puts("");
			printf("Pilihan anda [1-5, 0 untuk simpan data dan keluar dari program]: ");
			scanf("%d", &pilihan);
		}
		while(pilihan<0 || pilihan>9);
		
		getchar();
		
		switch(pilihan){
			case 1:
				menu_tampilkan_data_buku(&data);
				getchar();
				break;
			case 2:
				menu_tampilkan_data_peminjam(&data);
				getchar();
				break;
			case 3:
				menu_tampilkan_data_peminjam_merged( &data, menu_ascending_atau_descending() );
				getchar(); getchar();
				break;
			case 4:
				menu_input_data_buku(&data);
				getchar();
				break;
			case 5:
				menu_input_data_peminjam(&data);
				getchar();
				break;
			case 6:
				menu_edit_data_buku(&data);
				getchar(); getchar();
				break;
//			case 6:
//				urutkan_buku_tanggal( &data, menu_ascending_atau_descending() );
//				puts("");
//				puts("Data buku telah diurutkan.");
//				getchar(); getchar();
//				break;
//			case 7:
//				urutkan_peminjam_tanggal_pinjam( &data, menu_ascending_atau_descending() );
//				puts("");
//				puts("Data peminjaman buku telah diurutkan.");
//				getchar(); getchar();
//				break;
//			case 8:
//				urutkan_peminjam_tanggal_kembali( &data, menu_ascending_atau_descending() );
//				puts("");
//				puts("Data peminjaman buku telah diurutkan.");
//				getchar(); getchar();
//				break;
		}
	} while(pilihan!=0);
	
	file_tulis_data_buku(&data);
	file_tulis_data_peminjam(&data);
	
	clear_screen();
	puts("Terima kasih telah menggunakan aplikasi ini.");
	getchar();
	
	return 0;
}
