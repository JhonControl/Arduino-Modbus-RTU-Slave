#include <modbus.h>
#include <modbusDevice.h>
#include <modbusRegBank.h>
#include <modbusSlave.h>

// Url creador codigo  -- 
//https://code.google.com/p/arduino-modbus-slave/downloads/detail?name=MODBUS.zip&can=2&q=/




//Setup the brewtrollers register bank
//All of the data accumulated will be stored here
modbusDevice regBank;
//Create the modbus slave protocol handler
modbusSlave slave;

///salida pwm pin 9
#define  LED 9 

  
int conta=0;
 
void setup()
{   
  

conta=0;



//Assign the modbus device ID.  
  regBank.setId(1);

// Añade Salida analógica registra 40.001-40.020 al banco de registros
  regBank.add(40001);  
  regBank.add(40002);  
  regBank.add(40003);  
  regBank.add(40004);  
  regBank.add(40005);  
  regBank.add(40006);  
  regBank.add(40007);  
  regBank.add(40008);  
  regBank.add(40009);  
  regBank.add(40010);  
  regBank.add(40100);  
  regBank.add(40101);  

  slave._device = &regBank;  
  slave.setBaud(19200);   //19200 None   
}

void loop()
{  
    
 while(1)
  {
    
//     regBank.set(40000,analogRead(A0));      

    regBank.set(40100,conta);
    regBank.set(40101,conta);
      
      
//       digitalWrite(13,regBank.get(1));  
      
      
      
  conta++; 
  delay(1000);
      
     slave.run();  
  }
}

