// Définition des broches de sortie
const int STEP_PIN = 8;
const int DIR_PIN = 9;
const int EN_PIN = 10;
/*
const int STEP_PIN2 = 2;
const int DIR_PIN2 = 3;
const int EN_PIN2 = 4;
*/
// Configuration des variables
const int STEPS_PER_REV = 500; // Nombre de pas par tour
const int SPEED = 500; // Vitesse en microsecondes entre chaque pas
int step_count = 0; // Compteur de pas
int step_count2 = 0;
int test = 1;

void setup() {
  // Définition des broches en sortie
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(EN_PIN, OUTPUT);
/*
  pinMode(STEP_PIN2, OUTPUT);
  pinMode(DIR_PIN2, OUTPUT);
  pinMode(EN_PIN2, OUTPUT);
*/
  // Activation du moteur
  digitalWrite(EN_PIN, LOW);
  //digitalWrite(EN_PIN2, LOW);
}

void loop() {
  if (test == 1){
    // Changement de direction
    digitalWrite(DIR_PIN, HIGH);
    //digitalWrite(DIR_PIN2, LOW); // pour faire tourner le moteur dans le sens horaire
    //digitalWrite(DIR_PIN, LOW);  // pour faire tourner le moteur dans le sens anti-horaire

    // Arrêter le moteur lorsqu'il a effectué un tour complet
    if (abs(step_count) == STEPS_PER_REV) {
      //digitalWrite(EN_PIN, HIGH); // Désactivation du moteur
      //digitalWrite(EN_PIN2, HIGH);
      test = 0;
      step_count = 0;
      delay(1000); // Attente de 1 seconde
      //digitalWrite(EN_PIN, LOW); // Réactivation du moteur
      //step_count = 0; // Réinitialisation du compteur de pas
    } else{
      // Faire avancer le moteur d'un pas
      digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(SPEED);
      digitalWrite(STEP_PIN, LOW);
      delayMicroseconds(SPEED);

  /*
      digitalWrite(STEP_PIN2, HIGH);
      delayMicroseconds(SPEED);
      digitalWrite(STEP_PIN2, LOW);
      delayMicroseconds(SPEED);*/
    }

    // Incrémentation ou décrémentation du compteur de pas selon la direction
    if (digitalRead(DIR_PIN) == HIGH) {
      step_count++;
    } else {
      step_count--;
    }
  /*
    if (digitalRead(DIR_PIN2) == LOW) {
      step_count2++;
    } else {
      step_count2--;
    }
  */
  } else{
    // Changement de direction
    digitalWrite(DIR_PIN, LOW);
    //digitalWrite(DIR_PIN2, LOW); // pour faire tourner le moteur dans le sens horaire
    //digitalWrite(DIR_PIN, LOW);  // pour faire tourner le moteur dans le sens anti-horaire

    // Arrêter le moteur lorsqu'il a effectué un tour complet
    if (abs(step_count) == STEPS_PER_REV) {
      digitalWrite(EN_PIN, HIGH); // Désactivation du moteur
      //digitalWrite(EN_PIN2, HIGH);

      delay(1000); // Attente de 1 seconde
      //digitalWrite(EN_PIN, LOW); // Réactivation du moteur
      //step_count = 0; // Réinitialisation du compteur de pas
    } else{
      // Faire avancer le moteur d'un pas
      digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(SPEED);
      digitalWrite(STEP_PIN, LOW);
      delayMicroseconds(SPEED);

  /*
      digitalWrite(STEP_PIN2, HIGH);
      delayMicroseconds(SPEED);
      digitalWrite(STEP_PIN2, LOW);
      delayMicroseconds(SPEED);*/
    }

    // Incrémentation ou décrémentation du compteur de pas selon la direction
    if (digitalRead(DIR_PIN) == HIGH) {
      step_count++;
    } else {
      step_count--;
    }
  /*
    if (digitalRead(DIR_PIN2) == LOW) {
      step_count2++;
    } else {
      step_count2--;
    }
  */
  }
}
