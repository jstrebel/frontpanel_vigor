// Pins für die Steuerung des 74HC4051
const int S0 = 2;
const int S1 = 3;
const int S2 = 4;

// Pin für das Lesen des Signals
const int Z = 5;

void setup() {
 // Setze die Steuerpins als Ausgänge
 pinMode(S0, OUTPUT);
 pinMode(S1, OUTPUT);
 pinMode(S2, OUTPUT);

 // Setze den Z-Pin als Eingang
 pinMode(Z, INPUT);

 // Starte die serielle Kommunikation
 Serial.begin(9600);
}

void loop() {
 // Durchlaufe alle 8 Kanäle
 for (int channel = 0; channel < 8; channel++) {
   // Setze die Steuerpins entsprechend dem aktuellen Kanal
   digitalWrite(S0, bitRead(channel, 0));
   digitalWrite(S1, bitRead(channel, 1));
   digitalWrite(S2, bitRead(channel, 2));

   // Lese den Wert vom Z-Pin
   int value = digitalRead(Z);

   // Gib den Kanal und den gelesenen Wert aus
   Serial.print("Kanal ");
   Serial.print(channel);
   Serial.print(": ");
   Serial.println(value);

   // Kurze Verzögerung für die Stabilität
   delay(100);
 }

 // Warte eine Sekunde, bevor der nächste Durchlauf beginnt
 delay(1000);
}