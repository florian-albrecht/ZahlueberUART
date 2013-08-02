void setup(){
  Serial.begin(9600);
}

double zahl;

void loop(){
  if(Serial.available() > 0){
    zahl = getnumber();
    Serial.println(zahl);
  }
}

double getnumber(){
  double number = 0;
  boolean minus = false;
  if(Serial.available() > 0){
    double get[20];
    int i = 0;
    int l = 1;
    double c = 1;
    while(Serial.available() > 0){
      //Umrechnung von Ascii auf Zahl
      get[i] = Serial.read() - 48;
      //- ist in ASCII 45 und wäre dann jetzt -3
      if(get[i] == -3){
        //wieder zurücksetzen, um restliche richtig einzutragen
        i--;
        //Merkmechanismus, um später eine negative Zahl auszugeben
        minus = true;
      }
      i++;
      //kleine Zeitverzögerung, um der Schnittstelle Zeit zu lassen
      delay(30);
    }
    i--;
    while(i>=0){
      //Zusammenrechnung der verschiedenen Werte mit entsprechender 10er-Potenz
      number += get[i]*l;
      l *= 10;
      i--;
    }
  }
  //wenn erstes Zeichen minus, dann wird number mit -1 multiplizieren
  if(minus){
    number *= -1;
  }
  return number;
}
