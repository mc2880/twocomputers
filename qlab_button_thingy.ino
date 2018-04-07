
volatile int gonow = 0;
volatile int golast = 0;
volatile int stopingnow = 0;
volatile int stopinglast = 0;
volatile int pausenow = 0;
volatile int pauselast = 0;
volatile int nextnow = 0;
volatile int nextlast = 0;
volatile int prevnow = 0;
volatile int prevlast = 0;



volatile int debounce = 300;


void setup() {
  //Serial.begin(9600);
  pinMode(13, INPUT_PULLDOWN); // GO
  pinMode(14, INPUT_PULLDOWN); // Stop
  pinMode(15, INPUT_PULLDOWN); // Pause
  pinMode(16, INPUT_PULLDOWN); // Next Cue
  pinMode(17, INPUT_PULLDOWN); // Prev. Cue
  
  pinMode(3,OUTPUT);  // GO LED
  analogWrite(3, 25); // GO LED BRIGHTNESS 0-255    

  attachInterrupt(digitalPinToInterrupt(13), go, HIGH);
  attachInterrupt(digitalPinToInterrupt(14), stoping, HIGH);
  attachInterrupt(digitalPinToInterrupt(15), pause, HIGH);
  attachInterrupt(digitalPinToInterrupt(16), next, HIGH);
  attachInterrupt(digitalPinToInterrupt(17), prev, HIGH);

}

void loop() {




 
}


void go(){
    //Serial.println("Go");
    gonow = millis();
    
    if  ( gonow >= golast ){

        golast= millis() + debounce;
        
        Keyboard.set_modifier(0);
        Keyboard.set_key1(KEY_SPACE);
        Keyboard.send_now();
    
        //clear the keyboard
        Keyboard.set_modifier(0);
        Keyboard.set_key1(0);
        Keyboard.send_now();
    }
  
}//go()

void stoping(){
    //Serial.println("stop");
    stopingnow = millis();
    
    if  ( stopingnow >= stopinglast ){

        stopinglast= millis() + debounce;
        
        Keyboard.set_modifier(0);
        Keyboard.set_key1(KEY_ESC);
        Keyboard.send_now();
    
        //clear the keyboard
        Keyboard.set_modifier(0);
        Keyboard.set_key1(0);
        Keyboard.send_now();
    }
  
}//stoping()

void pause(){
    //Serial.println("pause");
    pausenow = millis();
    
    if  ( pausenow >= pauselast ){
      
        pauselast= millis() + debounce;
        
        Keyboard.set_modifier(0);
        Keyboard.set_key1(KEY_P);
        Keyboard.send_now();
    
        //clear the keyboard
        Keyboard.set_modifier(0);
        Keyboard.set_key1(0);
        Keyboard.send_now();
    }
  
}//pause()

void next(){
    //Serial.println("next");
    nextnow = millis();

    if  ( nextnow >= nextlast ){
    
        nextlast= millis() + debounce;
        
        Keyboard.set_modifier(0);
        Keyboard.set_key1(KEY_UP);
        Keyboard.send_now();
    
        //clear the keyboard
        Keyboard.set_modifier(0);
        Keyboard.set_key1(0);
        Keyboard.send_now();
    }
  
}//next()

void prev(){
    //Serial.println("prev");
    prevnow = millis();
    
    if  ( prevnow >= prevlast ){
    
        prevlast= millis() + debounce;
        
        Keyboard.set_modifier(0);
        Keyboard.set_key1(KEY_DOWN);
        Keyboard.send_now();
    
        //clear the keyboard
        Keyboard.set_modifier(0);
        Keyboard.set_key1(0);
        Keyboard.send_now();
    }
  
}//prev()

