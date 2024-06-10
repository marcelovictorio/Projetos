/*
 * Referencias
 * https://rodolfomarianocy.medium.com/hardware-hacking-com-placa-de-arduino-para-inje%C3%A7%C3%A3o-de-comandos-via-powershell-e-formas-de-b340e31cdc85
 * https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
 * https://forum.arduino.cc/t/problem-with-keyboard-h-and-atmega32u4/455667
 * 
 * https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/
 * https://docs.arduino.cc/built-in-examples/communication/ASCIITable
 * https://forum.arduino.cc/t/typing-extended-ascii-characters-using-arduino-micro-as-a-hid/268986/13
 * https://www.youtube.com/watch?v=xJClVZAs0wQ&t=201s (recuperar bootloader)
 * Também funciona na placa USB (tipo pendrive Lily GO)
 * Placa MEGA32UA (Selecionar Ferramentas->Placa: "Arduino Leonardo")
 * Pinos: 1 +5v 
 *        2 GND
 *        3 RST
 * 
 * 
 * Por: marcelo Costa - 19/08/2022 - ok
 * 
 */


#include "Keyboard.h"
/*função de pressionar, que servirá para nossa tecla enter.*/
void typeKey(int key){
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}
/*função para digitar / */
void bar(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('q');
  Keyboard.releaseAll();
}

/*função para digitar | */
void pipe(){
  Keyboard.press(KEY_LEFT_SHIFT);  // press and hold Shift
  // 100 0x64  236 0xEC  Keyboard Non-US \ and | *3;*6
  Keyboard.press(0xEC);
  Keyboard.releaseAll();
}

/*função para digitar \ */
void barinv(){
  
  // 100 0x64  236 0xEC  Keyboard Non-US \ and | *3;*6
  Keyboard.press(0xEC);
  Keyboard.releaseAll();

  //49  0x31  185 0xB9  Keyboard \ and |
  //Keyboard.write(0xB9); //barra invertida ok
}

/*função para digitar : */
void dotdot(){
  // Não está funcionendo
  Keyboard.press(KEY_LEFT_SHIFT);  // press and hold Shift
  //: 0x33  187 0xBB  Keyboard ; and : *4
  Keyboard.press(0xBB);
  Keyboard.releaseAll();
}

void setup() {
  /*iniciando*/
  Keyboard.begin();

for (int i = 0; i <= 9; i++) {
  
      delay(2000);
      /*junção da tecla Windows+R*/
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('r');
      Keyboard.releaseAll();
      
      delay(500);
    
      /*
      Keyboard.print("notepad");  
        delay(500);
      typeKey(KEY_RETURN);
      delay(750);
     */
     
      Keyboard.print("PowerShell");
      delay(250);
      typeKey(KEY_RETURN);
      delay(250);
    
             
     // Resultado esperado no Windows PowerShell:
     // Get-ItemProperty HKLM:/Software/Wow6432Node/Microsoft/Windows/CurrentVersion/Uninstall/* | Select-Object DisplayName, DisplayVersion | Sort-Object -Property DisplayName -Unique | Format-Table -AutoSize

    Keyboard.print("Get-ItemProperty HKLM");
    Keyboard.write(63); 
    
    bar();
    Keyboard.print("Software");
    bar();
    Keyboard.print("Wow6432Node");
    bar();
    Keyboard.print("Microsoft");
    bar();
    Keyboard.print("Windows");  
    bar();
    Keyboard.print("CurrentVersion");  
    bar();
    Keyboard.print("Uninstall");    
    barinv();
    Keyboard.print("* ");
    pipe();
    Keyboard.print("Select-Object DisplayName, DisplayVersion ");
    pipe();
    Keyboard.print("Sort-Object -Property DisplayName -Unique ");
    pipe();
    Keyboard.print("Format-Table -AutoSize");
       
    /*acionando enter*/
    
    typeKey(KEY_RETURN);
   
}

  /* Pressionar Windows + Seta para Esquerda */
  delay(1000); // Aguardar 1 segundo antes de pressionar as teclas finais
  Keyboard.press(KEY_LEFT_GUI);  // Pressionar tecla Windows
  Keyboard.press(KEY_LEFT_ARROW);  // Pressionar seta para esquerda
  delay(50);
  Keyboard.releaseAll();  // Liberar todas as teclas

/*acabando*/
Keyboard.end();
  
}
void loop(){
}
