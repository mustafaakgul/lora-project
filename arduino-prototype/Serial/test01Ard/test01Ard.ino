void setup() {
 Serial.begin(9600); /* haberleşme hızını ayarlayıp haberleşmeyi başlattık */
}
void loop() {
 Serial.println("Merhaba Dunya"); /* aktarmak istedigimiz veriyi yazdık */
 /* 
 mesajımızı yeni satırda yazmak için Serial.println, 
 aynı satırda yazdırmak için Serial.print kullanmalıyız
 */
 delay(1000); // Bir saniye bekle
}
