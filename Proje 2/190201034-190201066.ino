#include <LiquidCrystal.h>
#include <Pushbutton.h>

const int rs = 9, en = 8, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int button1 = A0, button2 = A1, button3 = A2, button4 = A3, button5 = A4, button6 = A5, resButton = 13;
int ledRed = 3, ledGreen = 2;
int ParaUstu = 0, sayB1 = 0, sayB2 = 0, sayB3 = 0, sayB4 = 0, sayB5 = 0, sayB6 = 0, para = 0, i = 0, rnd = 0, bedel = 0, kasaPara=0, a=1;
int TL5azalacak = 0, TL10azalacak = 0, TL20azalacak = 0, TL50azalacak = 0, TL100azalacak = 0;
int TL5mik = 20, TL10mik = 20, TL20mik = 10, TL50mik = 30, TL100mik = 5, kopukmik = 30, yikamamik = 50, kurumik = 100, cilamik = 20;
int tut5, tut10, tut20, tut50, tut100, tutKopukleme, tutYikama, tutKurulama, tutCilalama;

Pushbutton pbutton1(button1);
Pushbutton pbutton2(button2);
Pushbutton pbutton3(button3);
Pushbutton pbutton4(button4);
Pushbutton pbutton5(button5);
Pushbutton pbutton6(button6);
Pushbutton pResButton(resButton);

void setup() {
if (a==1){
  hold();
  a++;
}
  if (i == 0) {
    
    lcd.begin(20, 4);
    lcd.setCursor(7, 0);
    lcd.print(para);
    lcd.print(" TL");
    lcd.setCursor(0, 2);
    lcd.print("iptal etmek icin ");
    lcd.setCursor(0, 3);
    lcd.print("RESET butonuna basin.");
  }
  else if (i == 1){
    if(a==2){
  Serial.begin(9600);
  Serial.print("Random Sayi:");
  Serial.println(rnd);
  Serial.println();
  Serial.println("Hizmetler");
  Serial.print("  Kopukleme:");
  Serial.println(kopukmik+sayB1);
  Serial.print("  Yikama Miktari:");
  Serial.println(yikamamik+sayB2);
  Serial.print("  Kurulama Miktari:");
  Serial.println(kurumik+sayB3);
  Serial.print("  Cilalama Miktari:");
  Serial.println(cilamik+sayB4);
  Serial.println();a++;
  
  }
  
    lcd.begin(20, 4);
    lcd.setCursor(0, 0);
    lcd.print("1.Kopukleme:");
    lcd.print(sayB1);
    lcd.setCursor(0, 1);
    lcd.print("2.Yikama:");
    lcd.print(sayB2);
    lcd.setCursor(0, 2);
    lcd.print("3.Kurulama:");
    lcd.print(sayB3);
    lcd.setCursor(0, 3);
    lcd.print("4.Cilalama:");
    lcd.print(sayB4);
  }
  else if (i == -1)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Para Takildi");
    lcd.setCursor(0, 1);
    lcd.print("RESET tusuna basin");
    Serial.begin(9600);
    Serial.print("Random Sayi:");
    Serial.println(rnd);
    Serial.println();
    Serial.println("Para Takildi");
    Serial.println("RESET tusuna basin");
  }
  else if (i == 2)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Yuklenen Para:");
    lcd.print(para);
    bedel = sayB1 * 15 + sayB2 * 10 + sayB3 * 5 + sayB4 * 50;
    lcd.setCursor(0, 1);
    lcd.print("Hizmet Bedeli:");
    lcd.print(bedel);
    lcd.setCursor(0, 3);

    if (para >= bedel) {
      lcd.print("Para Ustu:");
      lcd.print(para - bedel);
      ParaUstu = para - bedel;
      
kasaPara=TL5mik*5+TL10mik*10+TL20mik*20+TL50mik*50+TL100mik*100;
kasaParaKont();
    
for(TL100azalacak;ParaUstu>=100 && TL100mik>0;TL100azalacak++){
  ParaUstu-=100;
  TL100mik--;
}
for(TL50azalacak;ParaUstu>=50 && TL50mik>0;TL50azalacak++){
  ParaUstu-=50;
  TL50mik--;
}
for(TL20azalacak;ParaUstu>=20 && TL20mik>0;TL20azalacak++){
  ParaUstu-=20;
  TL20mik--;
}
for(TL10azalacak;ParaUstu>=10 && TL10mik>0;TL10azalacak++){
  ParaUstu-=10;
  TL10mik--;
}
for(TL5azalacak;ParaUstu>=5 && TL5mik>0;TL5azalacak++){
  ParaUstu-=5;
  TL5mik--;
}
if(ParaUstu>0){
  Serial.begin(9600);
  Serial.println("Kasada Para Yoktur");
  Serial.println("Paraniz Iade Ediliyor...");
  Serial.println();
  Serial.println("Kasadaki Toplam Banknotlar:");
  Serial.print("   5lik:");
  Serial.println(TL5azalacak);
  Serial.print("   10luk:");
  Serial.println(TL10azalacak);
  Serial.print("   20lik:");
  Serial.println(TL20azalacak);
  Serial.print("   50lik:");
  Serial.println(TL50azalacak);
  Serial.print("   100luk:");
  Serial.println(TL100azalacak);
  Serial.println("Para Ustu Miktari:");
  Serial.print("   5lik:");
  Serial.println(TL5mik);
  Serial.print("   10luk:");
  Serial.println(TL10mik);
  Serial.print("   20lik:");
  Serial.println(TL20mik);
  Serial.print("   50lik:");
  Serial.println(TL50mik);
  Serial.print("   100luk:");
  Serial.println(TL100mik);
  i=3;
  setup();
}
if(i==2){
    yaz();}
    i++;
  } else if(bedel>para){
    lcd.clear();
      lcd.print("EksikParaMiktari:");
      lcd.print(bedel - para);
    }
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);
  pinMode(resButton, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  
}else if(i==3){
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Kasada Yeterli");
    lcd.setCursor(4, 1);
    lcd.print("Para Yoktur");
    lcd.setCursor(0, 3);
    lcd.print("RESET tusuna basin");
}
}
void loop() {

  {
    if (pbutton1.getSingleDebouncedPress()) {
      if (i == 1 && kopukmik>0) {
        kopukmik--;
        sayB1++;
        if(kopukmik<0){
          yetersizHizmet();
        }
      }
      if (i == 0) {
        para += 5;
        TL5mik++;
      }
      setup();
    }
    if (pbutton2.getSingleDebouncedPress()) {
      if (i == 1 && yikamamik>0) {
        yikamamik--;
        sayB2++;
        if(yikamamik<0){
          yetersizHizmet();
        }
      }
      if (i == 0) {
        para += 10;
        TL10mik++;
      }
      setup();
    }
    if (pbutton3.getSingleDebouncedPress()) {
      if (i == 1 && kurumik>0) {
        kurumik--;
        sayB3++;
        if(kurumik<0){
          yetersizHizmet();
        }
      }
      if (i == 0) {
        para += 20;
        TL20mik++;
      }
      setup();
    }
    if (pbutton4.getSingleDebouncedPress()) {
      if (i == 1 && cilamik>0) {
        cilamik--;
        sayB4++;
        if(cilamik<0){
          yetersizHizmet();
        }
      }
      if (i == 0) {
        para += 50;
        TL50mik++;
      }
      setup();
    }
    if (pbutton5.getSingleDebouncedPress()) {
      if (i == 0) {
        para += 100;
        TL100mik++;
      }
      setup();
    }
    if (pbutton6.getSingleDebouncedPress()) {
      if (i == 0) {
        rnd = millis() % 4 + 1;
      }
      i++;
      if (rnd != 2) {
        digitalWrite(ledRed, LOW);
        digitalWrite(ledGreen, HIGH);
      } else {
        digitalWrite(ledRed, HIGH);
        digitalWrite(ledGreen, LOW);
        i = -1;
      }
      setup();
    }
    if(pResButton.getSingleDebouncedPress()){
      reset();
    }
  }
}

void yaz() {
  Serial.begin(9600);
  Serial.println("Kalan Hizmetler");
  Serial.print("   Kopukleme:");
  Serial.println(kopukmik);
  Serial.print("   Yikama Miktari:");
  Serial.println(yikamamik);
  Serial.print("   Kurulama Miktari:");
  Serial.println(kurumik);
  Serial.print("   Cilalama Miktari:");
  Serial.println(cilamik);
  Serial.println();
  Serial.println("Kasadaki Toplam Banknotlar:");
  Serial.print("   5lik:");
  Serial.println(TL5mik);
  Serial.print("   10luk:");
  Serial.println(TL10mik);
  Serial.print("   20lik:");
  Serial.println(TL20mik);
  Serial.print("   50lik:");
  Serial.println(TL50mik);
  Serial.print("   100luk:");
  Serial.println(TL100mik);
  Serial.println("Para Ustu Miktari:");
  Serial.print("   5lik:");
  Serial.println(TL5azalacak);
  Serial.print("   10luk:");
  Serial.println(TL10azalacak);
  Serial.print("   20lik:");
  Serial.println(TL20azalacak);
  Serial.print("   50lik:");
  Serial.println(TL50azalacak);
  Serial.print("   100luk:");
  Serial.println(TL100azalacak);
}
void kasaParaKont(){
  if(ParaUstu>kasaPara){
      Serial.begin(9600);
      Serial.println("Kasada yeterli para yoktur");
      i=3;
      setup();
}
}
void reset(){
  Serial.begin(9600);
  Serial.write(12);
TL5mik=tut5;
TL10mik=tut10;
TL20mik=tut20;
TL50mik=tut50;
TL100mik=tut100;

TL5azalacak = 0;
TL10azalacak = 0;
TL20azalacak = 0;
TL50azalacak = 0;
TL100azalacak = 0;

kopukmik=tutKopukleme;
yikamamik=tutYikama;
kurumik=tutKurulama;
cilamik=tutCilalama;

sayB1=0;
sayB2=0;
sayB3=0;
sayB4=0;

ParaUstu=0;
para=0;
i=0;
digitalWrite(ledRed, LOW);
digitalWrite(ledGreen, LOW);
setup();
}
void yetersizHizmet(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Yeterli Hizmet");
    lcd.setCursor(1, 1);
    lcd.print("Yoktur");
    lcd.setCursor(3, 3);
    lcd.print("RESET tusuna basin");

  Serial.begin(9600);
  Serial.println("Yeterli Hizmet Yoktur");
  Serial.println("Lutfen RESET tusuna basin");
    
}

void hold(){
tut5=TL5mik;
tut10=TL10mik;
tut20=TL20mik;
tut50=TL50mik;
tut100=TL100mik;

tutKopukleme=kopukmik;
tutYikama=yikamamik;
tutKurulama=kurumik;
tutCilalama=cilamik;
}
