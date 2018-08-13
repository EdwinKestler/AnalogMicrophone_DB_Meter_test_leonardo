#define MicSamples (1024*2)
#define MicPin A0
// consts
#define AmpMax (1024 / 2) 
// modes

void setup() {
  // serial
  Serial.begin(115200);
  while (!Serial); // Wait untilSerial is ready - Leonardo
  Serial.println("Starting mic demo");
}

void loop() {
  MeasureAnalog();
}

// measure basic properties of the input signal
// determine if analog or digital, determine range and average.
void MeasureAnalog()
{
    long signalAvg = 0, signalMax = 0, signalMin = 1024, t0 = millis();
    for (int i = 0; i < MicSamples; i++)
    {
        int k = analogRead(MicPin);
        signalMin = min(signalMin, k);
        signalMax = max(signalMax, k);
        signalAvg += k;
    }
    signalAvg /= MicSamples;
 
    // print
    Serial.print("Time: " + String(millis() - t0));
    Serial.print(" Min: " + String(signalMin));
    Serial.print(" Max: " + String(signalMax));
    Serial.print(" Avg: " + String(signalAvg));
    Serial.print(" Span: " + String(signalMax - signalMin));
    Serial.print(", " + String(signalMax - signalAvg));
    Serial.print(", " + String(signalAvg - signalMin));
    Serial.println("");
}
