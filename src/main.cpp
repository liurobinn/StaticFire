#include <Arduino.h>
#include <Servo.h>

double offsetX=4;
double offsetY=0;
int t;

float pitch;
float roll;

Servo X08_X;
Servo X08_Y;

struct TVC {

        double pos;

        void servo_init(){

                X08_X.attach(3);
                X08_Y.attach(4);

                X08_X.write(90+offsetX);
                X08_Y.write(90+offsetY);
                delay(100);

        }

        void X80_testX(){

                pos= 90 + offsetX;
                Serial.println(pos);
                for (pos = 90 + offsetX; pos >= 82 +offsetX; pos -= 1) {

                        X08_X.write(pos);
                        delay(10);
                }
                delay(15);

                for (pos = 82 +offsetX; pos <= 98 + offsetX; pos += 1) {

                        X08_X.write(pos);
                        delay(10);
                }
                delay(15);

                for (pos = 98 + offsetX; pos >= 90 + offsetX; pos -= 1) {
                        X08_X.write(pos);
                        delay(10);
                }

                X08_X.write(90 + offsetX);
                delay(100);
        }

        void X80_testY(){

                pos= 90 + offsetY;
                Serial.println(pos);
                for (pos = 90 + offsetY; pos >= 75 +offsetY; pos -= 1) {

                        X08_Y.write(pos);
                        delay(10);
                }
                delay(15);

                for (pos = 75 +offsetY; pos <= 105 + offsetY; pos += 1) {

                        X08_Y.write(pos);
                        delay(10);
                }
                delay(15);

                for (pos = 105 + offsetY; pos >= 90 + offsetY; pos -= 1) {
                        X08_Y.write(pos);
                        delay(10);
                }

                X08_Y.write(90 + offsetY);
                delay(100);
        }

        void X80_test(){

                for (t=0; t>= 0 && t <=1440; t++) {
                        roll=asin(0.05*cos((3.14/180)*t));
                        pitch=asin(0.07*sin((3.14/180)*t));

                        X08_X.write(roll * 180+90+offsetX);
                        X08_Y.write(pitch * 180+90+offsetY);

                        delay(1);
                }

                X08_X.write(90+offsetX);
                X08_Y.write(90+offsetY);
                delay(100);

        }
        void X80_fire(){

                for (t=0; t>= 0 && t <=5760; t++) {
                        roll=asin(0.05*cos((3.14/180)*t));
                        pitch=asin(0.07*sin((3.14/180)*t));

                        X08_X.write(roll * 180+90+offsetX);
                        X08_Y.write(pitch * 180+90+offsetY);

                        delay(1);
                }

                X08_X.write(90+offsetX);
                X08_Y.write(90+offsetY);
                delay(100);

        }
        void X08_ejection(){

                delay(3000);
                
                for (pos=90+offsetY; pos >= 30 +offsetY; pos -= 1) {

                        X08_Y.write(pos);
                        delay(5);
                }
                delay(30);

                

                for (pos=30+offsetY; pos <= 90 +offsetY; pos += 1) {

                        X08_Y.write(pos);
                        delay(1);
                }
                delay(40);
                        
                
                delay(15);
        }


};
struct PYRO {

        void init(){
                pinMode(20,OUTPUT);
        }

        void fire(){
                digitalWrite(20,HIGH);
                //digitalWrite(16,LOW);
                delay(3000);
                digitalWrite(20,LOW);
                //digitalWrite(16,HIGH);
                delay(1);
        }

};
struct Buzzer {
        void init(){
                pinMode(10,OUTPUT);
        }

        void initIndicator(){

                int repeat;

                for (repeat=1; repeat<= 5; repeat++) {
                        digitalWrite(10,HIGH);
                        delay(200);
                        digitalWrite(10,LOW);
                        delay(200);
                }
        }
};
struct LED {
        void init(){
                pinMode(14, OUTPUT);
                pinMode(15, OUTPUT);
                pinMode(16, OUTPUT);

        }

        void initIndicator(){
                digitalWrite(14,LOW);
                delay(200);
                digitalWrite(14,HIGH);
                delay(200);
                digitalWrite(15,LOW);
                delay(200);
                digitalWrite(15,HIGH);
                delay(200);
                digitalWrite(16,LOW);
                delay(200);
                digitalWrite(16,HIGH);
                delay(200);
        }

};
struct COUNTDOWN {
        void startIndicator(){
                digitalWrite(10,HIGH);
                delay(1000);
                digitalWrite(10,LOW);
                delay(1000);
                digitalWrite(10,HIGH);
                delay(1000);
                digitalWrite(10,LOW);
                delay(1000);
        }
        void countdown(){
                int i=1;
                int counter;
                for(counter=2; counter >0; counter--) {
                        for (i=1; i<=counter; i++) {
                                digitalWrite(10,HIGH);
                                digitalWrite(14,LOW);
                                delay(200);
                                digitalWrite(10,LOW);
                                digitalWrite(14,HIGH);
                                delay(200);
                        }
                        digitalWrite(10,LOW);
                        digitalWrite(14,HIGH);
                        delay(10000);
                }
                int finalCount;
                for (finalCount=0; finalCount <= 10; finalCount++){
                digitalWrite(10,HIGH);
                digitalWrite(14,LOW);
                delay(500);
                digitalWrite(10,LOW);
                digitalWrite(14,HIGH);
                delay(500);
              }
        }
};
struct TVC tvc;
struct PYRO pyro;
struct COUNTDOWN countdown;
struct Buzzer buzzer;
struct LED led;
void setup(){
        //led.init();
        //buzzer.init();
        pyro.init();
/*
        tvc.servo_init();
        tvc.X80_testX();
        tvc.X80_testY();
        tvc.X80_test();
        pyro.init();
        led.initIndicator();
        buzzer.initIndicator();
        countdown.countdown();

*/
        delay(1000);
        pyro.fire();
        pinMode(13,OUTPUT);
/*
        tvc.X80_fire();

        tvc.servo_init();
        tvc.X08_ejection();
*/

}

void loop(){
        digitalWrite(13, HIGH);
        delay(1000);
        digitalWrite(13, LOW);
        delay(1000);
}
