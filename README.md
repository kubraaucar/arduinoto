# arduinoto
## Otonom Engel Kaçan Araç Projesi

Bu proje, Arduino tabanlı ve üç adet HC-SR04 ultrasonik sensörle donatılmış, engellerden kaçabilen bir otonom araç sistemidir. Araç, motor sürücü yardımıyla hareketini kontrol ederken, önüne çıkan engelleri sensörlerle algılayarak yön değiştirir.

---

#### Kullanılan Donanım

| Malzeme                      | Miktar | Açıklama |
|-----------------------------|--------|----------|
| Arduino UNO                 | 1 adet | Ana kontrol kartı |
| HC-SR04 Mesafe Sensörü      | 3 adet | Sol, orta ve sağ yön algılaması |
| L298N Motor Sürücü Modülü   | 1 adet | Motor kontrolü için |
| Sarı Motor ve Tekerlek Seti | 2-4 adet | Aracın hareketini sağlar |
| 4WD Araç Şasisi             | 1 adet | Gövde yapısı |
| 18650 Pil + Pil Yuvası      | 1 set  | Güç kaynağı |
| TP4056                      | 1 adet | Güvenli şarj devresi |
| Mini Breadboard             | 1 adet | Devre bağlantıları için |
| Jumper Kablo Seti           | Yeterli | Bağlantılar için |

---

#### Sistem Özellikleri

- 3 yönlü engel algılama (sol, orta, sağ)
- Engel algılandığında:
  - Ön engel: geri gidip sağa veya sola yönelir
  - Sağ veya sol engel: uygun yön seçimi yapılır
- Gerçek zamanlı motor kontrolü

## Arduino Projesi — 2905BT (Bluetooth Kontrollü Sistem)

Bu Arduino projesi, Bluetooth üzerinden dışarıdan kontrol edilebilen bir sistem için hazırlanmış bir koddur. HC-05 gibi bir Bluetooth modülü kullanarak cihaz kontrolü yapılabilir.

#### Gereksinimler

- Arduino UNO (veya benzeri)
- HC-05 / HC-06 Bluetooth modülü
- Arduino IDE

#### Uygulama Adımları

1. `2905BT.ino` dosyasını Arduino IDE ile açın
2. Gerekli bağlantıları yapın (TX-RX, VCC, GND)
3. Arduino kartınıza uygun portu seçip kodu yükleyin
4. Bluetooth bağlantısı kurarak seri komutlar gönderin
