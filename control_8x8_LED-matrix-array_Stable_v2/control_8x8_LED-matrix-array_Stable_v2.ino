// Mario's Ideas
// Testing all 64 leds in 8x8 LED matrix by lighting them up one by one
// 
//https://create.arduino.cc/projecthub/mdraber/controlling-8x8-led-matrix-without-drivers-libraries-585371?f=1#comments
//
// Modified by Rick Saffery Nov 2022
// Added functionality to reverse Mario's original sequencing 
// from right-to-left coming from bottom-to-top
//
// Added columns and rows sequences instead of single LED
//

#define R1 2
#define R2 3
#define R3 4
#define R4 5
#define R5 6
#define R6 7
#define R7 8
#define R8 9
//Columns
#define C1 10
#define C2 11
#define C3 12
#define C4 13
#define C5 A0
#define C6 A1
#define C7 A2
#define C8 A3

bool ALL_on = true;
int checkflag = 1; // essentially, this is mode-select
int wad = 60; // delay for everything but BigBlast
int wad2 = 300; // delay for BigBlast
int spin = 100; // delay for Spiral

void setup() {

   pinMode(R1, OUTPUT);
   pinMode(R2, OUTPUT);
   pinMode(R3, OUTPUT);
   pinMode(R4, OUTPUT);
   pinMode(R5, OUTPUT);
   pinMode(R6, OUTPUT);
   pinMode(R7, OUTPUT);
   pinMode(R8, OUTPUT);
   pinMode(C1, OUTPUT);
   pinMode(C2, OUTPUT);
   pinMode(C3, OUTPUT);
   pinMode(C4, OUTPUT);
   pinMode(C5, OUTPUT);
   pinMode(C6, OUTPUT);
   pinMode(C7, OUTPUT);
   pinMode(C8, OUTPUT);
// Turning all the LEDs off at the start of the sketch
  RowHigh();
  ColumnHigh();
}

void loop() {  

// BigBlast();
// rows(0);
// BigBlast();
// columns(1);
// BigBlast();
// columns(2);
Spiral(spin); // doesn't work
}

void rows(int checkflag) {
 for (int i=1;i<9;i++) {    // LED left-to-right and top-to-bottom
    for (int j=1;j<9;j++){
      
      SelectRow(i, checkflag);
      SelectColumn(j,checkflag); 
      delay(wad);
    }
  }

  for (int i=8;i>0;i--) {    // LED right-to-left and bottom-to-top
    for (int j=8;j>0;j--){
      SelectRow(i, checkflag);
      SelectColumn(j,checkflag); 
      if (i==8 and j==8) delay(wad/2); else delay(wad);
    }
  }
}  

void columns(int checkflag) {

for (int i=1;i<9;i++) {    // column left-to-right top-to-bottom
    for (int j=1;j<9;j++){
      
      if (checkflag == 1){
          SelectRow(j,checkflag);
          SelectColumn(i,checkflag);
      }
      else{
      SelectRow(i,checkflag);
      SelectColumn(j,checkflag);
      }
      
      
         if (i == 8 and checkflag == 1){
              delay(wad*.5);
         } 
         else delay(wad);{
        }
      }  
    }
  
for (int i=8;i>0;i--) {    // column right-to-left bottom-to-top
      
    for (int j=8;j>0;j--){

      if (checkflag == 1){
      SelectRow(j,checkflag);
      SelectColumn(i,checkflag);
      }
      else {
      SelectRow(i,checkflag);
      SelectColumn(j,checkflag);
      }
              if (i == 1 and checkflag == 1){
              delay(wad*.5);
         } 
         else delay(wad);{
        }
    }
  }
}

void SelectRow(int row, int checkflag){

if (checkflag == 0 or checkflag == 2){

  if (row==1) digitalWrite(R1,LOW); else digitalWrite(R1,HIGH);
  if (row==2) digitalWrite(R2,LOW); else digitalWrite(R2,HIGH);
  if (row==3) digitalWrite(R3,LOW); else digitalWrite(R3,HIGH);
  if (row==4) digitalWrite(R4,LOW); else digitalWrite(R4,HIGH);
  if (row==5) digitalWrite(R5,LOW); else digitalWrite(R5,HIGH);
  if (row==6) digitalWrite(R6,LOW); else digitalWrite(R6,HIGH);
  if (row==7) digitalWrite(R7,LOW); else digitalWrite(R7,HIGH);
  if (row==8) digitalWrite(R8,LOW); else digitalWrite(R8,HIGH);
} 
    else if (checkflag == 1)
    {
      RowLow(); // turn all rows on, column driven dynamically one-at-a-time
    }

}

void SelectColumn(int column, int checkflag){

  if (checkflag <= 1){
    
  if (column==1) digitalWrite(C1,HIGH); else digitalWrite(C1,LOW);
  if (column==2) digitalWrite(C2,HIGH); else digitalWrite(C2,LOW);
  if (column==3) digitalWrite(C3,HIGH); else digitalWrite(C3,LOW);
  if (column==4) digitalWrite(C4,HIGH); else digitalWrite(C4,LOW);
  if (column==5) digitalWrite(C5,HIGH); else digitalWrite(C5,LOW);
  if (column==6) digitalWrite(C6,HIGH); else digitalWrite(C6,LOW);
  if (column==7) digitalWrite(C7,HIGH); else digitalWrite(C7,LOW);
  if (column==8) digitalWrite(C8,HIGH); else digitalWrite(C8,LOW);
} 
else {
  ColumnHigh(); }
}

void ShowAll(bool All_on){

if (ALL_on == true){
RowLow();
ColumnHigh();
ALL_on = false; // resets the trigger to the opposing value
}
else {
RowHigh();
ALL_on = true; // resets the trigger to the opposing value
delay(wad2);
}

delay(wad2);
return ALL_on;
}

void RowLow(){

digitalWrite(R1,LOW); 
digitalWrite(R2,LOW); 
digitalWrite(R3,LOW); 
digitalWrite(R4,LOW); 
digitalWrite(R5,LOW); 
digitalWrite(R6,LOW); 
digitalWrite(R7,LOW); 
digitalWrite(R8,LOW); 
}

void RowHigh(){

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 
}

void ColumnLow(){
digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);
}

void ColumnHigh(){

digitalWrite(C1,HIGH); 
digitalWrite(C2,HIGH); 
digitalWrite(C3,HIGH); 
digitalWrite(C4,HIGH); 
digitalWrite(C5,HIGH); 
digitalWrite(C6,HIGH); 
digitalWrite(C7,HIGH); 
digitalWrite(C8,HIGH);   
}

void BigBlast(){

ShowAll(ALL_on);
ShowAll(ALL_on);
ShowAll(ALL_on);
ShowAll(ALL_on);
ShowAll(ALL_on);
ShowAll(ALL_on);
}

void Spiral(int spin){

Lamp1(spin); 
Lamp2(spin);
Lamp3(spin);
Lamp4(spin);
}

// Global delay for Spiral
void SpiralDelay(int spin){
delay(spin);
// Turning all the LEDs off at the start of the sketch
  RowHigh();
  ColumnHigh();
delay(spin);
}

void Lamp1(int spin){

digitalWrite(R5,LOW);
digitalWrite(C5,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
//digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
//digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);

}

void Lamp2(int spin){

digitalWrite(R5,LOW);
digitalWrite(C4,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
//digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
//digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp3(int spin){

digitalWrite(R4,LOW);
digitalWrite(C4,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
//digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
//digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp4(int spin){

digitalWrite(R4,LOW);
digitalWrite(C5,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
//digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
//digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp5(int spin){

digitalWrite(R4,LOW);
digitalWrite(C5,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
//digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
//digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}