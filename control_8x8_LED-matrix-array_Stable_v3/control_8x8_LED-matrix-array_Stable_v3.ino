// Mario's Ideas
// Testing all 64 leds in 8x8 LED matrix by lighting them up one by one
// 
//https://create.arduino.cc/projecthub/mdraber/-








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
int spin =9; // delay for Spiral

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

BigBlast();
rows(0);
BigBlast();   q`
thing(0);
BigBlast();
columns(1);
BigBlast();
columns(2);
Spiral(spin); 
Spiral(spin); 
Spiral(spin); 
delay(500);
}

// restore walking down each column, row-by-row
// from top-down and left-to-right

void thing(int checkflag){
for (int i=1;i<9;i++) {    // LED left-to-right and top-to-bottom
    for (int j=1;j<9;j++){
      
      SelectRow(j, checkflag);
      SelectColumn(i,checkflag); 
      delay(wad);
    }
  }

 for (int i=8;i>0;i--) {    // LED right-to-left and bottom-to-top
    for (int j=8;j>0;j--){
      SelectRow(j, checkflag);
      SelectColumn(i,checkflag); 
      if (i==8 and j==8) delay(wad/2); else delay(wad);
    }
  }


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

R5C5(spin);  //Lamp1 spiral
R5C4(spin);  //Lamp2 spiral
Lamp3(spin); //Lamp3 
Lamp4(spin); //Lamp4
Lamp5(spin); //Lamp5
Lamp6(spin); //Lamp6
Lamp7(spin); //Lamp7
Lamp8(spin); //Lamp8
Lamp9(spin); //Lamp9
Lamp10(spin);//Lamp10
Lamp11(spin);//Lamp11
Lamp12(spin);//Lamp12
Lamp13(spin);//Lamp13
Lamp14(spin);//Lamp14
Lamp15(spin);//Lamp15
Lamp16(spin);//Lamp16
Lamp17(spin);//Lamp17
Lamp18(spin);//Lamp18
Lamp19(spin);//Lamp19
Lamp20(spin);//Lamp20
Lamp21(spin);//Lamp21
Lamp22(spin);//Lamp22
Lamp23(spin);//Lamp23
Lamp24(spin);//Lamp24
Lamp25(spin);//Lamp25
Lamp26(spin);//Lamp26
Lamp27(spin);//Lamp
Lamp28(spin);//Lamp
Lamp29(spin);//Lamp
Lamp30(spin);//Lamp
Lamp31(spin);//Lamp
Lamp32(spin);//Lamp
Lamp33(spin);//Lamp
Lamp34(spin);//Lamp
Lamp35(spin);//Lamp
Lamp36(spin);//Lamp
Lamp37(spin);//Lamp
Lamp38(spin);//Lamp
Lamp39(spin);//Lamp
Lamp40(spin);//Lamp
Lamp41(spin);//Lamp
Lamp42(spin);//Lamp
Lamp43(spin);//Lamp
Lamp44(spin);//Lamp
Lamp45(spin);//Lamp
Lamp46(spin);//Lamp
Lamp47(spin);//Lamp
Lamp48(spin);//Lamp
Lamp49(spin);//Lamp
Lamp50(spin);//Lamp
Lamp51(spin);//Lamp
Lamp52(spin);//Lamp
Lamp53(spin);//Lamp
Lamp54(spin);//Lamp
Lamp55(spin);//Lamp
Lamp56(spin);//Lamp
R1C1(spin); //Lamp57 originally
Lamp58(spin);//Lamp
Lamp59(spin);//Lamp
Lamp60(spin);//Lamp
Lamp61(spin);//Lamp
Lamp62(spin);//Lamp
Lamp63(spin);//Lamp
Lamp64(spin);//Lamp

//counterclockwise rotation

Lamp64(spin);//Lamp
Lamp63(spin);//Lamp
Lamp62(spin);//Lamp
Lamp61(spin);//Lamp
Lamp60(spin);//Lamp
Lamp59(spin);//Lamp
Lamp58(spin);//Lamp
R1C1(spin); //Lamp57 originally
Lamp56(spin);//Lamp
Lamp55(spin);//Lamp
Lamp54(spin);//Lamp
Lamp53(spin);//Lamp
Lamp52(spin);//Lamp
Lamp51(spin);//Lamp
Lamp50(spin);//Lamp
Lamp49(spin);//Lamp
Lamp48(spin);//Lamp
Lamp47(spin);//Lamp
Lamp46(spin);//Lamp
Lamp45(spin);//Lamp
Lamp44(spin);//Lamp
Lamp43(spin);//Lamp
Lamp42(spin);//Lamp
Lamp41(spin);//Lamp
Lamp40(spin);//Lamp
Lamp39(spin);//Lamp
Lamp38(spin);//Lamp
Lamp37(spin);//Lamp
Lamp36(spin);//Lamp
Lamp35(spin);//Lamp
Lamp34(spin);//Lamp
Lamp33(spin);//Lamp
Lamp32(spin);//Lamp
Lamp31(spin);//Lamp
Lamp30(spin);//Lamp
Lamp29(spin);//Lamp
Lamp28(spin);//Lamp
Lamp27(spin);//Lamp
Lamp26(spin);//Lamp
Lamp25(spin);//Lamp
Lamp24(spin);//Lamp
Lamp23(spin);//Lamp
Lamp22(spin);//Lamp
Lamp21(spin);//Lamp
Lamp20(spin);//Lamp
Lamp19(spin);//Lamp
Lamp18(spin);//Lamp
Lamp17(spin);//Lamp
Lamp16(spin);//Lamp
Lamp15(spin);//Lamp
Lamp14(spin);//Lamp
Lamp13(spin);//Lamp
Lamp12(spin);//Lamp
Lamp11(spin);//Lamp
Lamp10(spin);//Lamp
Lamp9(spin);//Lamp
Lamp8(spin);//Lamp
Lamp7(spin);//Lamp
Lamp6(spin);//Lamp
Lamp5(spin);//Lamp
Lamp4(spin);//Lamp
Lamp3(spin);//Lamp
R5C4(spin);  //Lamp2 spiral
R5C5(spin);  //Lamp1 spiral

}

// Global delay for Spiral
void SpiralDelay(int spin){
delay(spin);
// Turning all the LEDs off at the start of the sketch
  RowHigh();
  ColumnHigh();
delay(spin);
}

void R5C5(int spin){

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

void R5C4(int spin){  

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
digitalWrite(C6,HIGH);

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
digitalWrite(C5, LOW);
//digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp6(int spin){

digitalWrite(R5,LOW);
digitalWrite(C6,HIGH);

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
digitalWrite(C5, LOW);
//digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp7(int spin){

digitalWrite(R6,LOW);
digitalWrite(C6,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
//digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
//digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp8(int spin){

digitalWrite(R6,LOW);
digitalWrite(C5,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
//digitalWrite(R6,HIGH); 
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

void Lamp9(int spin){

digitalWrite(R6,LOW);
digitalWrite(C4,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
//digitalWrite(R6,HIGH); 
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

void Lamp10(int spin){

digitalWrite(R6,LOW);
digitalWrite(C3,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
//digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
//digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp11(int spin){

digitalWrite(R5,LOW);
digitalWrite(C3,HIGH);

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
//digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp12(int spin){

digitalWrite(R4,LOW);
digitalWrite(C3,HIGH);

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
//digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}
void Lamp13(int spin){

digitalWrite(R3,LOW);
digitalWrite(C3,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
//digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
//digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp14(int spin){

digitalWrite(R3,LOW);
digitalWrite(C4,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
//digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
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

void Lamp15(int spin){

digitalWrite(R3,LOW);
digitalWrite(C5,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
//digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
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

void Lamp16(int spin){

digitalWrite(R3,LOW);
digitalWrite(C6,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
//digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
//digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp17(int spin){

digitalWrite(R3,LOW);
digitalWrite(C7,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
//digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
//digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}
void Lamp18(int spin){

digitalWrite(R4,LOW);
digitalWrite(C7,HIGH);

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
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
//digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp19(int spin){

digitalWrite(R5,LOW);
digitalWrite(C7,HIGH);

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
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
//digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp20(int spin){

digitalWrite(R6,LOW);
digitalWrite(C7,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
//digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
//digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp21(int spin){

digitalWrite(R7,LOW);
digitalWrite(C7,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
//digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
//digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp22(int spin){

digitalWrite(R7,LOW);
digitalWrite(C6,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
//digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
//digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp23(int spin){

digitalWrite(R7,LOW);
digitalWrite(C5,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
//digitalWrite(R7,HIGH); 
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

void Lamp24(int spin){

digitalWrite(R7,LOW);
digitalWrite(C4,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
//digitalWrite(R7,HIGH); 
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

void Lamp25(int spin){

digitalWrite(R7,LOW);
digitalWrite(C3,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
//digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
//digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp26(int spin){

digitalWrite(R7,LOW);
digitalWrite(C2,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
//digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
//digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp27(int spin){

digitalWrite(R6,LOW);
digitalWrite(C2,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
//digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
//digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp28(int spin){

digitalWrite(R5,LOW);
digitalWrite(C2,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
//digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
//digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp29(int spin){

digitalWrite(R4,LOW);
digitalWrite(C2,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
//digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
//digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp30(int spin){

digitalWrite(R3,LOW);
digitalWrite(C2,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
//digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
//digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp31(int spin){

digitalWrite(R2,LOW);
digitalWrite(C2,HIGH);

digitalWrite(R1,HIGH); 
//digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
//digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp32(int spin){

digitalWrite(R2,LOW);
digitalWrite(C3,HIGH);

digitalWrite(R1,HIGH); 
//digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
//digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp33(int spin){

digitalWrite(R2,LOW);
digitalWrite(C4,HIGH);

digitalWrite(R1,HIGH); 
//digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
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

void Lamp34(int spin){

digitalWrite(R2,LOW);
digitalWrite(C5,HIGH);

digitalWrite(R1,HIGH); 
//digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
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

void Lamp35(int spin){

digitalWrite(R2,LOW);
digitalWrite(C6,HIGH);

digitalWrite(R1,HIGH); 
//digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
//digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp36(int spin){

digitalWrite(R2,LOW);
digitalWrite(C7,HIGH);

digitalWrite(R1,HIGH); 
//digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
//digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp37(int spin){

digitalWrite(R2,LOW);
digitalWrite(C8,HIGH);

digitalWrite(R1,HIGH); 
//digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
//digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp38(int spin){

digitalWrite(R3,LOW);
digitalWrite(C8,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
//digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
//digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp39(int spin){

digitalWrite(R4,LOW);
digitalWrite(C8,HIGH);

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
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
//digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp40(int spin){

digitalWrite(R5,LOW);
digitalWrite(C8,HIGH);

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
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
//digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp41(int spin){

digitalWrite(R6,LOW);
digitalWrite(C8,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
//digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
//digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp42(int spin){

digitalWrite(R7,LOW);
digitalWrite(C8,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
//digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
//digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp43(int spin){

digitalWrite(R8,LOW);
digitalWrite(C8,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
//digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
//digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp44(int spin){

digitalWrite(R8,LOW);
digitalWrite(C7,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
//digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
//digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp45(int spin){

digitalWrite(R8,LOW);
digitalWrite(C6,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
//digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
//digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp46(int spin){

digitalWrite(R8,LOW);
digitalWrite(C5,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
//digitalWrite(R8,HIGH); 

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

void Lamp47(int spin){

digitalWrite(R8,LOW);
digitalWrite(C4,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
//digitalWrite(R8,HIGH); 

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

void Lamp48(int spin){

digitalWrite(R8,LOW);
digitalWrite(C3,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
//digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
//digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp49(int spin){

digitalWrite(R8,LOW);
digitalWrite(C2,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
//digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
//digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp50(int spin){

digitalWrite(R8,LOW);
digitalWrite(C1,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
//digitalWrite(R8,HIGH); 

//digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp51(int spin){

digitalWrite(R7,LOW);
digitalWrite(C1,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
//digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

//digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp52(int spin){

digitalWrite(R6,LOW);
digitalWrite(C1,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
//digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

//digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp53(int spin){

digitalWrite(R5,LOW);
digitalWrite(C1,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
//digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

//digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp54(int spin){

digitalWrite(R4,LOW);
digitalWrite(C1,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
//digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

//digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp55(int spin){

digitalWrite(R3,LOW);
digitalWrite(C1,HIGH);

digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
//digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

//digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp56(int spin){

digitalWrite(R2,LOW);
digitalWrite(C1,HIGH);

digitalWrite(R1,HIGH); 
//digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

//digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void R1C1(int spin){   // Lamp57 spiral

digitalWrite(R1,LOW);
digitalWrite(C1,HIGH);

//digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

//digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp58(int spin){

digitalWrite(R1,LOW);
digitalWrite(C2,HIGH);

//digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
//digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp59(int spin){

digitalWrite(R1,LOW);
digitalWrite(C3,HIGH);

//digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
//digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp60(int spin){

digitalWrite(R1,LOW);
digitalWrite(C4,HIGH);

//digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
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

void Lamp61(int spin){

digitalWrite(R1,LOW);
digitalWrite(C5,HIGH);

//digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
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

void Lamp62(int spin){

digitalWrite(R1,LOW);
digitalWrite(C6,HIGH);

//digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
//digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}



void Lamp63(int spin){

digitalWrite(R1,LOW);
digitalWrite(C7,HIGH);

//digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
//digitalWrite(C7, LOW);
digitalWrite(C8, LOW);

SpiralDelay(spin);
}

void Lamp64(int spin){

digitalWrite(R1,LOW);
digitalWrite(C8,HIGH);

//digitalWrite(R1,HIGH); 
digitalWrite(R2,HIGH); 
digitalWrite(R3,HIGH); 
digitalWrite(R4,HIGH); 
digitalWrite(R5,HIGH); 
digitalWrite(R6,HIGH); 
digitalWrite(R7,HIGH); 
digitalWrite(R8,HIGH); 

digitalWrite(C1, LOW);
digitalWrite(C2, LOW);
digitalWrite(C3, LOW);
digitalWrite(C4, LOW);
digitalWrite(C5, LOW);
digitalWrite(C6, LOW);
digitalWrite(C7, LOW);
//digitalWrite(C8, LOW);

SpiralDelay(spin);
}