// Incluir la biblioteca GSM 
#include <GSM.h>

#define PINNUMBER "" 

// inicializa la instancia de la biblioteca
GSM gsmAccess ; 
GSM_SMS sms ; 

// inicializa los pines de receptor del sensor, y del led
int pinReceptor = 2;
int lectura = 0;
int pinLed = 3;

void setup ( ) { 
  // inicializa las comunicaciones serie y espere a que el puerto se abra: 
  Serial. begin( 9600 ) ; 
  while ( ! Serial ) { 
    ; // espera a que el puerto serial se conecte. Necesario solo para puerto USB nativo 
  } 

  Serie . println ( "SMS Messages Sender" ) ; 

  // estado de conexión
  bool notConnected = true; 

  // Si la tarjeta SIM tiene PIN, pasarlo como un parámetro de begin () entre comillas 
  while ( notConnected ) { 
    if ( gsmAccess. begin( PinNumber ) == GSM_READY ) {
      notConnected = false ; 
    } else { 
      Serial . println ( "No conectado" ) ; 
      delay ( 1000 ) ; 
    } 
  } 

  Serial . println ( "GSM inicializado" ); 
  
  // Declara los pines de receptor y led como entrada y salida respectivamente
  pinMode(pinReceptor, INPUT);
  pinMode(pinLed, OUTPUT);
} 

void loop ( ) { 

  lectura = digitalRead(pinReceptor);
  if(lectura == 1) {
     char remoteNum “4427896543” ;  // número de teléfono para enviar sms
     readSerial ( remoteNum ) ; 
     Serial . println ( remoteNum ) ; 

     // sms text 

     char txtMsg = “El contenedor está lleno ” ; 
     readSerial( txtMsg ) ; 
     Serial.println ( "ENVIANDO" ) ; 
     Serial.println ( ) ; 
     Serial.println ( "Mensaje:" ) ; 
     Serial.println ( txtMsg ) ; 

     // enviar el mensaje
     sms.beginSMS ( remoteNum ) ; 
     sms.print( txtMsg ) ; 
     sms.endSMS ( ) ; 
     Serial.println ( " \ n COMPLETE! \ n " ) ; 
     digitalWrite(pinLed, lectura);
  }
  Serial.println(lectura);

} 
