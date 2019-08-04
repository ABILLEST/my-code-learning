void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  char hello[20] = "hello my bro";
  for(int counter = 0; counter <= 13; counter++){
    Serial.print("The hello is ");
    Serial.println(hello[counter]);
    }
}

void loop() {
  // put your main code here, to run repeatedly:

}
