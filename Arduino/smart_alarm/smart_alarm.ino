int btn1 = 2;
int btn2 = 4;
int buzzer = 3;
int R = 5;
int G = 6;
int B = 7;

const char *SNOOZE_STATE = "snooze/state";

long long currentTime = 0;
bool buzz = false, doAlarm = true, snooze = false, disable = false;

void setup()
{
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  Serial.begin(9600);
}

void Buzz(bool &state)
{
  if (state)
    analogWrite(buzzer, LOW);
  else
    analogWrite(buzzer, HIGH);
  state = !state;
}

void DoLights(bool enable)
{
  if (enable)
  {
    digitalWrite(R, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(B, HIGH);
  }
  else
  {
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
  }
}

void loop()
{
  if (!digitalRead(btn1))
  {
    snooze = true;
  }
  else
    snooze = false;

  if (!digitalRead(btn2))
  {
    disable = true;
  }
  else
    disable = false;

  if (millis() - currentTime >= 2000 && doAlarm)
  {
    Buzz(buzz);
    currentTime = millis();

    Serial.print(SNOOZE_STATE);
    Serial.print(" ");
    Serial.println(snooze);
  }

  if (doAlarm)
  {
    DoLights(snooze);
  }
}
