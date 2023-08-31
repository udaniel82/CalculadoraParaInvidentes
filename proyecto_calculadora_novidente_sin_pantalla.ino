#include <Keypad.h>
const byte filas = 4; //cuatro  filas.
const byte columnas = 4; //cuatro columnas.
char tecla[filas][columnas] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'A','0','=','/'}
};
byte pinFilas[filas] = {7, 6, 5, 4}; //conectarse a las patillas de salida de fila del teclado.
byte pinColumnas[columnas] = {3, 2, A5, A4}; //conectarse a las patillas de las columnas del teclado.

Keypad keypad = Keypad( makeKeymap(tecla), pinFilas, pinColumnas, filas, columnas );
String leeCadena1,leeCadena2;
byte cuenta=0;
char a;
long dato1,dato2,rpt1;
double dato3,dato4,rpt2;
int r1[10], r2[10], conta, contaretro, copiado, negativo;

// parte musical
int pBuzzer=13;
int unidad=1000/1;
int doble=1000/2;
int cuarto=1000/4;
int octavo=1000/8;
double pausa=1.30;

int NOTA_C4=262;
int NOTA_A4=440;
int NOTA_E5=659; 


void setup(){
  pinMode(pBuzzer, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  char key = keypad.getKey();
  if (key=='0'||key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'){
      
      if(key=='1')
        {
          for(int i=0;i<1;i++)
          {
            tone(pBuzzer,NOTA_E5,octavo);
            delay(octavo*pausa);
          }
        }
        else if(key=='2')
        {
          for(int i=0;i<2;i++)
          {
            tone(pBuzzer,NOTA_E5,octavo);
            delay(octavo*pausa);
          }
        }
        else if(key=='3')
        {
          for(int i=0;i<3;i++)
          {
            tone(pBuzzer,NOTA_E5,octavo);
            delay(octavo*pausa);
          }
        }
        else if(key=='4')
        {
          for(int i=0;i<4;i++)
          {
            tone(pBuzzer,NOTA_E5,octavo);
            delay(octavo*pausa);
          }
        }
        else if(key=='5')
        {
          for(int i=0;i<5;i++)
          {
            tone(pBuzzer,NOTA_E5,octavo);
            delay(octavo*pausa);
          }
        }
        else if(key=='6')
        {
          for(int i=0;i<6;i++)
          {
            tone(pBuzzer,NOTA_E5,octavo);
            delay(octavo*pausa);
          }
        }
        else if(key=='7')
        {
          for(int i=0;i<7;i++)
          {
            tone(pBuzzer,NOTA_E5,octavo);
            delay(octavo*pausa);
          }
        }
        else if(key=='8')
        {
          for(int i=0;i<8;i++)
          {
            tone(pBuzzer,NOTA_E5,octavo);
            delay(octavo*pausa);
          }
        }
        else if(key=='9')
        {
          for(int i=0;i<9;i++)
          {
            tone(pBuzzer,NOTA_E5,octavo);
            delay(octavo*pausa);
          }
        }
        else if(key=='0')
        {
           for(int i=0;i<1;i++)
           {
            tone(pBuzzer,NOTA_E5,doble);
            delay(cuarto*pausa);
           }     
        }
        else
        {
          for(int i=0;i<1;i++)
           {
            tone(pBuzzer,NOTA_A4,doble);
            delay(doble*pausa);
           } 
        }
    
      if(cuenta==0){
        Serial.println(key);
        leeCadena1+=key;
        dato1=leeCadena1.toInt();
        Serial.println(dato1);
      }
      
      else if(cuenta==1){
        Serial.println(key);
        leeCadena2+=key;
        dato2=leeCadena2.toInt();
        Serial.println(dato2);
      }
   
  }

  if(key=='A'){

      leeCadena2="";
      leeCadena1="";
      dato1=0;
      dato2=0;
      dato3=0;
      dato4=0;
      cuenta=0;
      rpt1=0;
      rpt2=0;
      negativo=0;
      for(int x=0; x<10; x++)
      {
        r1[x]=0;
        r2[x]=0;
      }
      copiado=0;
      conta=0;
      contaretro=0;
      for(int i=0;i<1;i++)
      {
        tone(pBuzzer,NOTA_A4,doble);
        delay(unidad*pausa);
      }
      Serial.println(key);
      delay(unidad*pausa);
  }
  else if(key=='='&&a=='+'){
    cuenta++;
    rpt1=dato1+dato2;
    for(int i=0;i<1;i++)
    {
      tone(pBuzzer,NOTA_A4,doble);
      delay(unidad*pausa);
    }
    Serial.println(rpt1);
    delay(unidad*pausa);
    copiado=(int)rpt1;
    conta=0;
    contaretro=0;
    while(copiado>0)
    {
      r1[conta]=copiado%10;
      copiado=copiado/10;
      conta++;
    }
    for(contaretro=conta-1;contaretro>=0;contaretro--)
    {
      r2[conta-1-contaretro]=r1[contaretro];
    }
    for(int j=0;j<conta;j++)
    {
      Serial.println(r2[j]);
      switch (r2[j])
      {
        case 0: for(int i=0;i<1;i++)
                {
                  tone(pBuzzer,NOTA_E5,doble);
                  delay(cuarto*pausa);
                }
                break;
        case 1: for(int i=0;i<1;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 2: for(int i=0;i<2;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 3: for(int i=0;i<3;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 4: for(int i=0;i<4;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 5: for(int i=0;i<5;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 6: for(int i=0;i<6;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 7: for(int i=0;i<7;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 8: for(int i=0;i<8;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 9: for(int i=0;i<9;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
      }
      delay(unidad*pausa);
      delay(unidad*pausa);
    }
  }

  else if(key=='='&&a=='-'){
    cuenta++;
    if((dato1-dato2)>0)
    {
      rpt1=dato1-dato2;
    }
    else
    {
      rpt1=(dato1-dato2)*(-1);
      negativo=1;
    }
    // rpt1=dato1-dato2;
    for(int i=0;i<1;i++)
    {
      tone(pBuzzer,NOTA_A4,doble);
      delay(unidad*pausa);
      delay(unidad*pausa);
    }
    Serial.println(rpt1);
    delay(unidad*pausa);
    copiado=(int)rpt1;
    conta=0;
    contaretro=0;
    while(copiado>0)
    {
      r1[conta]=copiado%10;
      copiado=copiado/10;
      conta++;
    }
    for(contaretro=conta-1;contaretro>=0;contaretro--)
    {
      r2[conta-1-contaretro]=r1[contaretro];
    }
    if (negativo==1)
    {
      tone(pBuzzer,NOTA_A4,doble);
      delay(unidad*pausa);
      delay(unidad*pausa);
    }
    for(int j=0;j<conta;j++)
    {
      Serial.println(r2[j]);
      switch (r2[j])
      {
        case 0: for(int i=0;i<1;i++)
                {
                  tone(pBuzzer,NOTA_E5,doble);
                  delay(cuarto*pausa);
                }
                break;
        case 1: for(int i=0;i<1;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 2: for(int i=0;i<2;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 3: for(int i=0;i<3;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 4: for(int i=0;i<4;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 5: for(int i=0;i<5;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 6: for(int i=0;i<6;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 7: for(int i=0;i<7;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 8: for(int i=0;i<8;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 9: for(int i=0;i<9;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
      }
      delay(unidad*pausa);
      delay(unidad*pausa);
    }
  }
  else if(key=='='&&a=='*'){
    cuenta++;
    rpt1=dato1*dato2;
    for(int i=0;i<1;i++)
    {
      tone(pBuzzer,NOTA_A4,doble);
      delay(unidad*pausa);
      delay(unidad*pausa);
    }
    Serial.println(rpt1);
    delay(unidad*pausa);
    copiado=(int)rpt1;
    conta=0;
    contaretro=0;
    while(copiado>0)
    {
      r1[conta]=copiado%10;
      copiado=copiado/10;
      conta++;
    }
    for(contaretro=conta-1;contaretro>=0;contaretro--)
    {
      r2[conta-1-contaretro]=r1[contaretro];
    }
    for(int j=0;j<conta;j++)
    {
      Serial.println(r2[j]);
      switch (r2[j])
      {
        case 0: for(int i=0;i<1;i++)
                {
                  tone(pBuzzer,NOTA_E5,doble);
                  delay(cuarto*pausa);
                }
                break;
        case 1: for(int i=0;i<1;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 2: for(int i=0;i<2;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 3: for(int i=0;i<3;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 4: for(int i=0;i<4;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 5: for(int i=0;i<5;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 6: for(int i=0;i<6;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 7: for(int i=0;i<7;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 8: for(int i=0;i<8;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 9: for(int i=0;i<9;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
      }
      delay(unidad*pausa);
      delay(unidad*pausa);
    }
  }
  else if(key=='='&&a=='/'){
    cuenta++;
    dato3=dato1;
    dato4=dato2;
    rpt2=(dato3/dato4);
    for(int i=0;i<1;i++)
    {
      tone(pBuzzer,NOTA_A4,doble);
      delay(unidad*pausa);
      delay(unidad*pausa);
    }
    Serial.println(rpt2);
    delay(unidad*pausa);
    copiado=(int)rpt2;
    conta=0;
    contaretro=0;
    while(copiado>0)
    {
      r1[conta]=copiado%10;
      copiado=copiado/10;
      conta++;
    }
    for(contaretro=conta-1;contaretro>=0;contaretro--)
    {
      r2[conta-1-contaretro]=r1[contaretro];
    }
    for(int j=0;j<conta;j++)
    {
      Serial.println(r2[j]);
      switch (r2[j])
      {
        case 0: for(int i=0;i<1;i++)
                {
                  tone(pBuzzer,NOTA_E5,doble);
                  delay(cuarto*pausa);
                }
                break;
        case 1: for(int i=0;i<1;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 2: for(int i=0;i<2;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 3: for(int i=0;i<3;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 4: for(int i=0;i<4;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 5: for(int i=0;i<5;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 6: for(int i=0;i<6;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 7: for(int i=0;i<7;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 8: for(int i=0;i<8;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
        case 9: for(int i=0;i<9;i++)
                {
                  tone(pBuzzer,NOTA_E5,octavo);
                  delay(octavo*pausa);
                }
                break;
      }
      delay(unidad*pausa);
      delay(unidad*pausa);
    }
  }

  
  else if((key=='+'||key=='-'||key=='*'||key=='/')&&(cuenta==0)){
    cuenta++;
    a=key;
    for(int i=0;i<1;i++)
    {
      tone(pBuzzer,NOTA_C4,doble);
      delay(doble*pausa);
    }
    Serial.println(key);
  }
}
