/*
    Problem: Run on Arduino for temperature & humidity sensor DHT11
*/
//// Librería Genérica Simular Arduino
#include <iostream>
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11 

using namespace std;

#define INLINE inline __attribute__((always_inline))

using SenseType = float;   // user-defined types = ADT = abstract data type
using PortType  = uint8_t; // unsigned int 8-bits = fixed size int

void delay(int ms) { for (int i=1; i<ms; i++); }

class SensorTemp { // Class = user defined type definition (define-and-use)
private: // default private visibility
    SenseType temp;
    SenseType moist;
    PortType  port=2;
    DHT *dht;
public:
    void begin(PortType p) { 
        dht = new DHT(DHTPIN, DHTTYPE);
        dht->begin();
    }
    void read() {
       temp=dht->readTemperature();
       moist=dht->readHumidity();
    }
    friend ostream& operator << (ostream &os,  SensorTemp &s) {
        os << "temp = " << s.temp << "ºC" << endl; // Add humidity value
        return os;
    }
};

SensorTemp th; // use = instance = objeto

void setup() {
    th.begin(2);    // method (dot-operator)
}

void loop() {
    th.read();
    cout << th; // attribute (dot-operator)
    delay(1000);
}
