#include <WiFi.h>
#include "index.h"
#include "processo.h"
#include "historico.h"

// ========== CONFIG WI-FI ==========
const char* ssid = "WAM";
const char* password = "12345678";

WiFiServer server(80);
String header;

// ========== GPIO - SAÍDAS ==========
const int saidas[] = {23, 22, 21, 19, 18, 17, 16, 4};
String nomes[] = {"D23", "D22", "D21", "D19", "D18", "TX2", "RX2", "D4"};
bool estados[8] = {false, false, false, false, false, false, false, false};
String textos[] = {"MAGAZINE", "VÁCUO", "SOLTAR PEÇA", "AVANÇO", "RECUO"};

// ========== VARIÁVEIS DE PROCESSO ==========
float ultimoTempoProcesso = 0.0;
const int ledProcesso = 16;
String historicoProcessos = "";
unsigned long startMillis;
int contadorCliques = 0;

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 8; i++) {
    pinMode(saidas[i], OUTPUT);
    digitalWrite(saidas[i], LOW);
  }

  // Entradas (sensores)
  pinMode(36, INPUT); 
  pinMode(39, INPUT); 
  pinMode(34, INPUT); 
  pinMode(32, INPUT);
  pinMode(33, INPUT); 
  pinMode(25, INPUT); 
  pinMode(26, INPUT); 
  pinMode(27, INPUT);

  WiFi.softAP(ssid, password);
  Serial.println("Wi-Fi conectado.");
  Serial.println(WiFi.softAPIP());

  server.begin();
  startMillis = millis();
}

String getHoraAtual() {
  unsigned long tempoSeg = (millis() - startMillis) / 1000;
  int horas = (tempoSeg / 3600) % 24;
  int minutos = (tempoSeg / 60) % 60;
  int segundos = tempoSeg % 60;
  char buffer[16];
  sprintf(buffer, "%02d:%02d:%02d", horas, minutos, segundos);
  return String(buffer);
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    String currentLine = "", header = "";
    unsigned long startTime = 0, endTime = 0;

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        header += c;

        if (c == '\n') {
          if (currentLine.length() == 0) {

            // === PROCESSO AUTOMÁTICO ===
            if (header.indexOf("GET /processo") >= 0) {
              startTime = millis();
              digitalWrite(ledProcesso, HIGH);

              client.println("HTTP/1.1 200 OK");
              client.println("Content-type:text/html\r\n");
              client.print(PROCESSO_HTML);
              client.flush();

              // ========= ETAPAS DO PROCESSO =========
              digitalWrite(saidas[0], HIGH); 
              delay(1000); 
              digitalWrite(saidas[0], LOW); // avanço e recuo do magazine

              digitalWrite(saidas[3], HIGH); 
              delay(1500);
              digitalWrite(saidas[3], LOW);
              digitalWrite(saidas[1], HIGH);  
              delay(2000);            
              digitalWrite(saidas[4], HIGH); // pegar a peça e recuar
              delay(2000);

              digitalWrite(saidas[1], LOW);
              digitalWrite(saidas[2], HIGH); // soltar a peça
              delay(200); 
              digitalWrite(saidas[4], LOW);
              digitalWrite(saidas[2], LOW); // desliga tudo

              endTime = millis();
              digitalWrite(ledProcesso, LOW);

              ultimoTempoProcesso = (endTime - startTime) / 1000.0;
              String horaAtual = getHoraAtual();
              contadorCliques++;
              String registro = String(contadorCliques) + "º Processo: " + String(ultimoTempoProcesso, 2) + "s<br>";
              historicoProcessos = registro + historicoProcessos;

              Serial.printf("%d;%.2f;%s\n", contadorCliques, ultimoTempoProcesso, horaAtual.c_str());

              delay(500);
              client.printf("<script>document.getElementById('statusProcesso').innerText += '\\nTempo total: %.2f segundos.';</script>", ultimoTempoProcesso);
              delay(500);
              client.println("<script>setTimeout(()=>{window.location.href='/'}, 4000);</script>");
              break;
            }

            // === HISTÓRICO DE PROCESSOS ===
            else if (header.indexOf("GET /tempo") >= 0) {
              client.println("HTTP/1.1 200 OK");
              client.println("Content-type:text/html\r\n");
              client.print(HISTORICO_HTML_INICIO);
              client.print(historicoProcessos);
              client.print(HISTORICO_HTML_FIM);
              break;
            }

            // === STATUS DOS SENSORES EM JSON ===
            else if (header.indexOf("GET /status") >= 0) {
              client.println("HTTP/1.1 200 OK");
              client.println("Content-Type: application/json\r\n");
              client.print("{");
              client.printf("\"ED0\": %d,", digitalRead(36));
              client.printf("\"ED1\": %d,", digitalRead(39));
              client.printf("\"ED2\": %d,", digitalRead(34));
              client.printf("\"ED3\": %d,", digitalRead(32));
              client.printf("\"ED4\": %d,", digitalRead(33));
              client.printf("\"ED5\": %d,", digitalRead(25));
              client.printf("\"ED6\": %d,", digitalRead(26));
              client.printf("\"ED7\": %d",  digitalRead(27));
              client.print("}");
              break;
            }

            // === CONTROLE MANUAL ===
            else {
              for (int i = 0; i < 8; i++) {
                String onCmd = "GET /" + nomes[i] + "/on";
                String offCmd = "GET /" + nomes[i] + "/off";
                if (header.indexOf(onCmd) >= 0) {
                  digitalWrite(saidas[i], HIGH); estados[i] = true;
                } else if (header.indexOf(offCmd) >= 0) {
                  digitalWrite(saidas[i], LOW); estados[i] = false;
                }
              }

              client.println("HTTP/1.1 200 OK");
              client.println("Content-type:text/html\r\n");

              client.print(MAIN_PAGE);  // Início do HTML

              for (int i = 0; i < 8; i++) {
                client.printf("<a href='/%s/%s'>", nomes[i].c_str(), estados[i] ? "off" : "on");
                String texto = (i < 5) ? textos[i] : nomes[i];
                client.printf("<div class='btn-text'>%s</div>", texto.c_str());
                client.printf("<button class='%s'>%s %s</button></a>",
                              estados[i] ? "btn-off" : "btn-on",
                              estados[i] ? "OFF = " : "ON = ",
                              nomes[i].c_str());
              }

              client.print(HTML_FIM);  // Fim do HTML
              break;
            }

          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    client.stop();
  }
}