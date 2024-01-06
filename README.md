# TUBES-IOT "SMART LAMP"

![UNIVERSITAS TELKOM - LOGO VERTIKAL](https://github.com/Wantenggt/TUBES-IOT/assets/146419439/0f25d0b8-5627-45ff-b266-a29cc4f6cb04)

# KELOMPOK HIKARI
* FAZRI ARDHANA - 1103202187
* RAIHAN ATHA - 1103202123
* MUHAMMAD IKHWAN MAULANA - 1103203219
* YASSER MARTIN - 1103201259
* DEWA THEISYATTA ASHARO HEISENDA - 1103204125

# PENGENALAN PROJEK
Projek kali ini yaitu membuat alat sederhana menggunakan wemos d1 mini, sensor ldr sebagai pendeteksi cahaya, relay untuk memutus daya, dan komponen yang lainnya. Jika sensor mendeteksi cahaya, nantinya lampu akan mati secara otomatis, dan juga sebaliknya jika sensor tidak mendeteksi cahaya, lampu akan menyala. Lampu juga bisa di atur dengan manual sesuai kehendak sendiri. Protokol jaringan menggunakan protokol MQTT dan broker mqtt yang digunakan adalah broker MQTT 

KENDALA YANG DIALAMI
Kami mengalami kendala yang cukup serius, yaitu alat tidak bisa dikendalikan secara otomatis. Pada saat percobaan menyambung ke broker MQTT berhasil, tetapi saat mencoba sensor tidak bisa. Sensor tidak bisa mengenali cahaya sehingga alat tidak bisa bekerja. Codingan yang dibuat juga sudah dicoba tetapi hasilnya nihil, tidak ada perubahan sama sekali. 

# LATAR BELAKANG
ALASAN MEMILIH TOPIK
Penggunaan teknologi ini membantu mengoptimalkan penggunaan energi dengan mengatur pencahayaan secara otomatis, memberikan kenyamanan dengan kemampuan kontrol jarak jauh melalui perangkat pintar, dan memberikan fleksibilitas dalam menciptakan suasana ruangan yang diinginkan.

TUJUAN PROYEK
Tujuan dari proyek ini adalah sebagai pemenuhan nilai tugas besar untuk mata kuliah IoT (Internet of Thing) dan memahami cara kerja IOT.

# TEORI DASAR
1. Alat yang dibutuhkan
* Relay ![download](https://github.com/Wantenggt/TUBES-IOT/assets/146419439/bcf08131-d9be-405f-b364-ca9c2d2ed712)
Relay adalah sebuah komponen elektronik yang berfungsi sebagai sakelar elektrik yang dikendalikan oleh arus listrik. Relay digunakan untuk mengontrol satu sirkuit listrik dengan menggunakan sinyal atau tegangan dari sirkuit lainnya.
* Breadboard ![download (1)](https://github.com/Wantenggt/TUBES-IOT/assets/146419439/656970f4-014f-4fc6-b094-a2c7584339e0)
Breadboard adalah perangkat atau papan percobaan yang digunakan dalam elektronika untuk merancang, menguji, dan menyusun prototipe rangkaian listrik tanpa harus melakukan soldering.
* Wemos d1 mini ![download (2)](https://github.com/Wantenggt/TUBES-IOT/assets/146419439/99fd7762-7dc8-4c4e-983c-9e573e33b9de)
Wemos D1 Mini adalah sebuah papan pengembangan (development board) berbasis modul WiFi yang dirancang untuk pemrograman dan prototyping dalam konteks Internet of Things (IoT).
* Sensor LDR ![download (3)](https://github.com/Wantenggt/TUBES-IOT/assets/146419439/80beeb9d-3d87-45a7-827d-9dea5ca2854e)
LDR (Light-Dependent Resistor) atau resistor tergantung cahaya adalah sebuah komponen elektronik yang memiliki resistansi yang berubah-ubah tergantung pada intensitas cahaya yang diterimanya.
* Kabel, fitting, dan stekker ![download (6)](https://github.com/Wantenggt/TUBES-IOT/assets/146419439/4f484893-9152-43b8-b153-6d312348e76b)
![download (4)](https://github.com/Wantenggt/TUBES-IOT/assets/146419439/b925ddcf-ab55-4968-8d48-593f3cef7d3f)
![download (5)](https://github.com/Wantenggt/TUBES-IOT/assets/146419439/8d92e187-9762-447e-8484-dbbfb15e6f65)
Digunakan untuk menyalakan lampu
* Kabel jumper ![download (7)](https://github.com/Wantenggt/TUBES-IOT/assets/146419439/13819b79-bc49-463c-b28d-e9ec1bed0d39)
Kabel jumper adalah kabel pendek yang digunakan dalam elektronika dan prototyping untuk menghubungkan dua titik atau komponen dalam rangkaian listrik.
* Lampu ![download (8)](https://github.com/Wantenggt/TUBES-IOT/assets/146419439/fcfe9d48-8861-4c3b-9664-c874f8d5d745)
Lampu adalah perangkat yang menghasilkan cahaya, baik sebagai sumber cahaya utama atau sebagai sumber cahaya tambahan.
* Kable USB to micro USB ![download (9)](https://github.com/Wantenggt/TUBES-IOT/assets/146419439/b287c330-1765-454a-93a9-1cc80b46f050)
Untuk menghubungkan laptop dengan wemos d1 mini

2. Koneksi yang digunakan
* WiFi - WiFi adalah teknologi nirkabel yang memungkinkan perangkat elektronik, seperti komputer, smartphone, tablet, dan perangkat lainnya, untuk terhubung ke jaringan internet atau jaringan lokal (LAN) tanpa menggunakan kabel fisik. 
* MQTT - MQTT (Message Queuing Telemetry Transport) adalah protokol komunikasi ringan yang dirancang untuk digunakan pada kondisi jaringan yang tidak stabil atau dengan bandwidth terbatas.

3. Harga
No.	Nama Barang	Jumlah	Harga
1	Relay	1	10000
2	Breadboard	2	6000
3	Wemos D1 Mini	1	27000
4	Sensor LDR	1	7000
5	Kabel	1	5000
6	Fitting	1	8000
7	Stekker	1	2000
8	Kabel Jumper	1	26000
9	Lampu	1	10000
Total			101000
![image](https://github.com/Wantenggt/TUBES-IOT/assets/146419439/af6525d7-2842-4158-a76f-26bef08c067a)

# CARA KERJA ALAT
Sensor cahaya akan mendeteksi cahaya disekitarnya. Jika sensor mendeteksi cahaya yang terang, maka lampu akan otomatis mati. Jika sensor mendeteksi cahaya redup/tidak ada cahaya, maka lampu akan hidup otomatis. Selain itu, lampu bisa diatur manual dengan semacam aplikasi.

# KESIMPULAN
Alat ini belum berhasil dibuat karena ada beberapa kesalahan yang belum bisa diselesaikan. Entah itu kesalahan dari codingan yang buat atau kesalahan dalam merangkai alat. Selanjutnya kami akan mencoba lagi agar alat ini bisa digunakan 
