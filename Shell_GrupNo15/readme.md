İşletim Sistemleri Proje Ödevi

Proje Grubundaki Öğrencilerin Ad-Soyad-Numaraları :

Turgay Teymurov G191210552,
Tarik Bukucu G191210048, 
Beyza Celebi G191210009, 
Fuat Berkay Bilgin G191210384,
Emirhan Ersoz G191210096
	
Tasarıma Genel Bakış :
Program 4 farklı bölümden oluşmaktadır.
	
	
-Main programin basladigi yerdir. 

-Prompt programimizin baslaigi komut dizisini gosteren ve islemleri alan programdir. 
	Kabuk yazisini gosterir. Girilen komutlarin uzunlugunu kontrol eder. 
	Uzunluklari uygunsa command islem gonderir
-Command programi ana komut islemlerinin yapildigi programdir. 
	Gelen input burada parse edilir. 
	komuttan once bosluk silme islemi yapilir
	Komutun bos olma durumu gibi durumlar kontrol edilir.
	Baska proses cagirma isleminde child proses kontrolu burada yapilir.
	
Dosyaların açıklamaları:

main.c - Bu dosya main fonksiyonun kaynak dosyasıdır.
prompt.c - Bu dosya prompt isleminin gerceklestigi fonksiyonu bulunduran dosyadir
command.c - Bu dosya komutlari gerceklestirdigimiz dosyadir.
prompt.h - Bu dosya prompt header dosyasidir.
command.h - Bu dosya command header dosyasidir.
makefile - Bu dosya makefile'dir.Programın derlenmesi ve çalışması için komutlar içerir.
readme.md - Bu dosya şu an okunan proje hakkında bir bilgilendirme dosyasıdır.
shell - Bu Programın executable halidir.
	
Derleme:
Makefile bulunduğu konumda terminal açılır. "make" yazılır.
	
Çalıştırma:
Klasorde terminal açılır. Projeyi çalıştırmak için terminale sadece "make" yazmak ardindan ./bin/shell yazilmalidir.

Karşılaşılan zorluklar:
Showpid yaparken komut dizinini yazmakta bunu engelleyemedik.
	
Kaynaklar:
https://github.com/
https://man7.org/
https://stackoverflow.com/

