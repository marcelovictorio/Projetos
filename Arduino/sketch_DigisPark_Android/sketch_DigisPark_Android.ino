/*
 * Digispark ( http://digistump.com/products/1 )
 * Fork: https://github.com/valkyrix/Digispark-Reverse-Shell-Win10
 * Concept: https://github.com/hak5darren/USB-Rubber-Ducky/wiki/Payload---Windows-10-%3A-Download-and-execute-file-with-Powershell
 * 
 * Exemplo para usar o digispark na IDE arduino: https://www.youtube.com/watch?v=LQQ1ODAR5oQ&t=179s
 * 
 *   Passos para utilização do Digispark com a IDE Arduino:
 *   1 - Instale os drivers Digistump
 *   2 - Vá em File > Preferences e cole o link http://digistump.com/package_digistump_index.json na aba "Additional Boards Manager URLs" (opção Arquivo -> Preferencias -> Urls adicionais para gerenciadores de placa.
 *   3 - Vá em Tools > Board > Boards Manager e instale Digistump AVR Boards (*)Instala driver -> opção Sketch -> Incluir biblioteca -> (Adicionar biblioteca.ZIP) -> Gerenciar bibliotecas 
 *   4 - ATENÇÃO - Clique no botão de upload do código e quando solicitado, conecte o digispark na USB (Plug in device now)
 *   
 * Placa: Tigispark (Default • 16.5mhz)
 * Created by Marcelo Costa
*/

#include "DigiKeyboard.h"
/* Init function */


void setup()
{//turn LED off while code is running, this means the device is safe to unplug as soon as the LED turns back on
  pinMode(1, OUTPUT); //LED on Model A
  digitalWrite(1, HIGH);
  
  DigiKeyboard.delay(500);
  digitalWrite(1, LOW);
  DigiKeyboard.sendKeyStroke(0);
        
  //DigiKeyboard.println("adb shell am start -a android.intent.action.CALCULATOR");
  //DigiKeyboard.println("adb shell am start -a android.settings.LOCATION_SOURCE_SETTINGS");
  DigiKeyboard.println("adb devices");






  
  
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);




  


  
  
  
}

/* Unused endless loop */
void loop() {}
