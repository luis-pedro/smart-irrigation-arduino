// Projeto Rega Automática
// Desenvolvido por: Luis Pedro do Carmo Costa

const int ledVerde = 2;
const int ledVermelho = 3;
const int sensorUmidade = A0; // pino do sensor

int leituraSensor;
int limiteSeco = 650;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  
  Serial.begin(9600); // para monitorar os valores
}

void loop() {

  leituraSensor = analogRead(sensorUmidade); // lê o sensor

  Serial.print("Umidade: ");
  Serial.println(leituraSensor);

  if (leituraSensor > limiteSeco) {
    // Está seco
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);
  } else {
    // Está úmido
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, LOW);
  }

  delay(1000);
}