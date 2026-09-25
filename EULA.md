# HiCo Thermal — End User License Agreement (EULA)

**Version 1.0 · effective 25 September 2026**

- [English](#english)
- [Bahasa Indonesia](#bahasa-indonesia)

If the two versions differ, the Bahasa Indonesia version prevails for users in Indonesia and the
English version prevails elsewhere.

---

## English

### 1. Agreement
This agreement is between you and FebriCahyaa ("the Author"), the author of HiCo Thermal ("the
Module"): the `hicod` program, its scripts, WebUI, device profiles, documentation and updates.
By flashing, installing, updating or using the Module you accept this agreement. If you do not
accept it, do not install the Module, or uninstall it.

### 2. Private software
The Module is private, proprietary software. Its source code is not public. It is **licensed,
not sold**: the Author keeps all rights, title and intellectual property in it.

### 3. What you may do
The Author grants you a personal, non-exclusive, non-transferable, revocable license to:
- install and use the Module on Android devices you own or are allowed to modify;
- receive updates through your root manager (Magisk, KernelSU, APatch) from the Author's official
  release channel.

### 4. What you may not do
Unless the Author gives written permission, you may not:
- share, re-upload, mirror, sell, rent or sublicense the Module or its zip files, in whole or in
  part (share the official release link instead);
- modify, repackage, rebrand or remove notices from the Module;
- decompile, disassemble or reverse engineer `hicod`, except where the law expressly allows it;
- remove or bypass the Flux Tweaks requirement, the integrity checks or the temperature safety
  guard;
- use the Module for any unlawful purpose.

### 5. Requirements
The Module needs a rooted device (Magisk, KernelSU or APatch), Android 9 or newer, and
**Flux Tweaks** v1.2.0 or newer, which detects the games. Without Flux the Module does nothing
and keeps the stock thermal configuration.

### 6. Risks: read before installing
While a game runs, the Module **disables thermal throttling** so the CPU and GPU can run at full
speed. You understand and accept that:
- the device, and the battery in particular, will run hotter than the manufacturer intended;
- heat can shorten battery life, reduce performance over time and, in extreme cases, damage
  hardware or cause discomfort or burns when holding the device;
- the temperature safety guard, the battery-zone protection and the kernel's critical-trip
  shutdown lower these risks but **cannot remove them**; sensor readings can be wrong or missing;
- modifying system behaviour may void your warranty and may conflict with other modules or ROMs.

Do not play while charging in hot places, do not cover the device, and stop if it becomes
uncomfortably hot. You can switch the Module off at any time (WebUI or action button: *Off*) or
restore stock thermal immediately (`hicod restore`).

### 7. Privacy
The Module does not collect, send or sell personal data. Everything it records — settings,
logs, game session history (package name, duration, temperatures) — stays on your device in
`/data/adb/.config/hico/` and is deleted when you uninstall. Update checks are made by your root
manager, which downloads `update.json` from the Author's public release repository on GitHub
under GitHub's own privacy terms. Device profiles are generated from public firmware dumps, not
from your device.

### 8. Updates and support
The Author may release updates, change features or stop development at any time. Support, if
any, is given voluntarily and without any obligation.

### 9. No warranty
THE MODULE IS PROVIDED **"AS IS"** AND **"AS AVAILABLE"**, WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
The Author does not guarantee that the Module is error-free, works on every device, or improves
performance.

### 10. Limitation of liability
To the maximum extent permitted by law, the Author is not liable for any damage or loss arising
from the use of, or inability to use, the Module, including damage to devices or batteries,
data loss, lost profits or warranty claims, even if advised of the possibility.

### 11. Third-party components and trademarks
Some installer files are third-party components under the Apache License 2.0; they are listed in
`NOTICE.md` and their own license applies to them. Flux Tweaks is a separate module with its
own license. Xiaomi, Redmi and POCO are trademarks of Xiaomi Inc.; the Module is not affiliated
with or endorsed by Xiaomi or any device manufacturer.

### 12. Termination
This license ends automatically if you break it. You must then uninstall the Module and delete
every copy. Sections 6, 9, 10 and 13 survive termination.

### 13. Governing law
This agreement is governed by the laws of the Republic of Indonesia. Any dispute is first to be
settled amicably by deliberation (*musyawarah*).

### 14. Changes and contact
The Author may update this agreement; the version shipped with an update applies from that
update on. Questions and permission requests: through the official HiCo Thermal release
repository on GitHub.

---

## Bahasa Indonesia

### 1. Perjanjian
Perjanjian ini dibuat antara Anda dan FebriCahyaa ("Pembuat"), pembuat HiCo Thermal ("Modul"):
program `hicod`, skrip, WebUI, profil perangkat, dokumentasi, dan pembaruannya. Dengan mem-flash,
memasang, memperbarui, atau menggunakan Modul, Anda menyetujui perjanjian ini. Jika tidak
setuju, jangan pasang Modul, atau copot pemasangannya.

### 2. Perangkat lunak privat
Modul adalah perangkat lunak privat dan berhak milik (*proprietary*). Kode sumbernya tidak
dipublikasikan. Modul **dilisensikan, bukan dijual**: seluruh hak, kepemilikan, dan hak kekayaan
intelektual tetap milik Pembuat.

### 3. Yang boleh Anda lakukan
Pembuat memberi Anda lisensi pribadi, non-eksklusif, tidak dapat dialihkan, dan dapat dicabut
untuk:
- memasang dan menggunakan Modul di perangkat Android milik Anda atau yang boleh Anda modifikasi;
- menerima pembaruan melalui aplikasi root manager (Magisk, KernelSU, APatch) dari kanal rilis
  resmi Pembuat.

### 4. Yang tidak boleh Anda lakukan
Tanpa izin tertulis dari Pembuat, Anda tidak boleh:
- membagikan, mengunggah ulang, membuat mirror, menjual, menyewakan, atau mensublisensikan Modul
  atau file zip-nya, sebagian maupun seluruhnya (bagikan tautan rilis resmi saja);
- mengubah, mengemas ulang, mengganti merek, atau menghapus pemberitahuan dari Modul;
- melakukan dekompilasi, disassembly, atau rekayasa balik terhadap `hicod`, kecuali jika hukum
  secara tegas mengizinkannya;
- menghapus atau mengakali syarat Flux Tweaks, pemeriksaan integritas, atau pengaman suhu;
- menggunakan Modul untuk tujuan yang melanggar hukum.

### 5. Persyaratan
Modul membutuhkan perangkat yang sudah di-root (Magisk, KernelSU, atau APatch), Android 9 atau
lebih baru, dan **Flux Tweaks** v1.2.0 atau lebih baru, yang bertugas mendeteksi game. Tanpa Flux,
Modul tidak melakukan apa pun dan tetap memakai konfigurasi thermal bawaan.

### 6. Risiko: baca sebelum memasang
Saat game berjalan, Modul **menonaktifkan thermal throttling** agar CPU dan GPU bisa bekerja
dengan kecepatan penuh. Anda memahami dan menerima bahwa:
- perangkat, terutama baterai, akan lebih panas daripada yang dimaksudkan pabrikan;
- panas dapat memperpendek umur baterai, menurunkan performa seiring waktu, dan dalam kondisi
  ekstrem merusak perangkat keras atau menimbulkan rasa tidak nyaman hingga luka bakar saat
  perangkat digenggam;
- pengaman suhu, perlindungan zona baterai, dan pemutusan darurat (*critical trip*) dari kernel
  mengurangi risiko tersebut tetapi **tidak dapat menghilangkannya**; pembacaan sensor bisa
  keliru atau tidak tersedia;
- perubahan perilaku sistem dapat membatalkan garansi dan dapat bentrok dengan modul atau ROM lain.

Jangan bermain sambil mengisi daya di tempat panas, jangan menutupi perangkat, dan berhentilah
jika perangkat terasa terlalu panas. Anda dapat mematikan Modul kapan saja (WebUI atau tombol
action: *Off*) atau langsung mengembalikan thermal bawaan (`hicod restore`).

### 7. Privasi
Modul tidak mengumpulkan, mengirim, atau menjual data pribadi. Semua yang dicatat — pengaturan,
log, riwayat sesi game (nama paket, durasi, suhu) — tetap berada di perangkat Anda di
`/data/adb/.config/hico/` dan dihapus saat Modul dicopot. Pemeriksaan pembaruan dilakukan oleh
aplikasi root manager Anda, yang mengunduh `update.json` dari repositori rilis publik Pembuat di
GitHub sesuai ketentuan privasi GitHub. Profil perangkat dibuat dari dump firmware publik, bukan
dari perangkat Anda.

### 8. Pembaruan dan dukungan
Pembuat dapat merilis pembaruan, mengubah fitur, atau menghentikan pengembangan kapan saja.
Dukungan, jika ada, diberikan secara sukarela tanpa kewajiban apa pun.

### 9. Tanpa jaminan
MODUL DISEDIAKAN **"SEBAGAIMANA ADANYA"** DAN **"SEBAGAIMANA TERSEDIA"**, TANPA JAMINAN APA PUN,
TERSURAT MAUPUN TERSIRAT, TERMASUK JAMINAN KELAYAKAN UNTUK DIPERDAGANGKAN, KESESUAIAN UNTUK
TUJUAN TERTENTU, DAN TIDAK MELANGGAR HAK PIHAK LAIN. Pembuat tidak menjamin Modul bebas dari
kesalahan, berjalan di semua perangkat, atau meningkatkan performa.

### 10. Batasan tanggung jawab
Sejauh diizinkan oleh hukum, Pembuat tidak bertanggung jawab atas kerusakan atau kerugian apa pun
yang timbul dari penggunaan atau ketidakmampuan menggunakan Modul, termasuk kerusakan perangkat
atau baterai, kehilangan data, kehilangan keuntungan, atau klaim garansi, meskipun kemungkinan
tersebut telah diberitahukan.

### 11. Komponen pihak ketiga dan merek dagang
Beberapa file installer adalah komponen pihak ketiga berlisensi Apache License 2.0; file tersebut
tercantum di `NOTICE.md` dan tunduk pada lisensinya sendiri. Flux Tweaks adalah modul terpisah
dengan lisensinya sendiri. Xiaomi, Redmi, dan POCO adalah merek dagang Xiaomi Inc.; Modul tidak
berafiliasi dengan maupun didukung oleh Xiaomi atau pabrikan perangkat mana pun.

### 12. Pengakhiran
Lisensi ini berakhir secara otomatis jika Anda melanggarnya. Anda wajib mencopot Modul dan
menghapus semua salinannya. Bagian 6, 9, 10, dan 13 tetap berlaku setelah pengakhiran.

### 13. Hukum yang berlaku
Perjanjian ini tunduk pada hukum Negara Republik Indonesia. Setiap perselisihan diselesaikan
terlebih dahulu secara musyawarah untuk mufakat.

### 14. Perubahan dan kontak
Pembuat dapat memperbarui perjanjian ini; versi yang disertakan dalam suatu pembaruan berlaku
sejak pembaruan tersebut. Pertanyaan dan permohonan izin: melalui repositori rilis resmi HiCo
Thermal di GitHub.
