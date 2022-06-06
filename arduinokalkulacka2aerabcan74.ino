int a;
int b;
char calSignal;
void setup() {
Serial.begin(9600);
Serial.println("Zadaj vstup pre vypocet");
while (Serial.available() == 0) {} 

a = Serial.parseInt(); 
Serial.print(a);
calSignal = Serial.read();
Serial.print(calSignal);
b = Serial.parseInt();
Serial.print(b);//zobraz b
Serial.println(" ");
//Serial.print("Solution = ");
Serial.print(solve(a, b));
Serial.println("");
Serial.println("Ak chcete urobit dalsi vypocet, stlacte cervene tlacidlo Reset na Arduine UNO !");
}
int solve(int a, int b) {
int result;
switch (calSignal) {
case '+' :
result = a + b;
return result;
break;
case '-' :
result = a - b;
return result;
break;
case 'x' :
result = a * b;
return result;
break;
case '/' :
result = a / b;
if(b=0);
Serial.println("nulou sa delit neda");
return result;
break;
case '*' :
result = a * b;
return result;
break;
case '.' :
result = a * b;
return result;
break;
case '%' :
result = a % b;
break;
case 'm':
result = a*a;
return result;
break;
case 'o':
float area;
float side;
side = sqrt(a);
result = sqrt(a);
break;
return result;
break;
default :
Serial.println("Co to je za operator? Nespravny: calSignal");
}
}
void loop() {
}
