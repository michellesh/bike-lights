float minf(float x, float y) { return x < y ? x : y; }

int width = 5;

void atom() {
  // Nucleus
  for (int i = 1; i < 25; i++) {
    leds[i] = CRGB::Red;
  }

  setRing(innerRing);
  setRing(middleRing);
  Serial.println(middleRing.getTarget());
  setRing(outerRing);
}

void setRing(Ring &ring) {
  for (int i = 0; i < 24; i++) {
    int dist = abs(ring.getTarget() - i);
    dist = minf(dist, abs(ring.getTarget() - 24 - i));
    dist = minf(dist, abs(ring.getTarget() + 24 - i));
    int brightness = dist > width ? 0 : map(dist, 0, width, 255, 0);

    ring.setLED(i, ring.getColor(brightness));
  }

  ring.incTarget();
}

/*
int ringInner[] = {76, 96, 85, 99, 77, 91, 88, 82, 94, 78, 97, 86,
                   89, 79, 83, 92, 95, 80, 98, 84, 87, 90, 93, 81};
int ringMiddle[] = {26, 36, 33, 30, 49, 27, 46, 43, 40, 37, 34, 31,
                    28, 47, 44, 41, 38, 35, 32, 29, 48, 45, 42, 39};
int ringOuter[] = {51, 66, 59, 73, 63, 70, 52, 56, 60, 67, 74, 53,
                   64, 71, 57, 61, 68, 54, 65, 72, 58, 62, 69, 55};

float ringIndex = 0;

float minf(float x, float y) { return x < y ? x : y; }

void atom() {
  // Nucleus
  for (int i = 1; i < 25; i++) {
    leds[i] = CRGB::Red;
  }

  int width = 5;
  for (int i = 0; i < 24; i++) {
    int dist = abs(ringIndex - i);
    dist = minf(dist, abs(ringIndex - 24 - i));
    dist = minf(dist, abs(ringIndex + 24 - i));
    int brightness = dist > width ? 0 : map(dist, 0, width, 255, 0);

    CRGB color = CRGB::Yellow;
    leds[ringInner[i]] = color.nscale8(brightness);

    color = CRGB::Blue;
    leds[ringMiddle[i]] = color.nscale8(brightness);

    color = CRGB::Green;
    leds[ringOuter[i]] = color.nscale8(brightness);
  }

  ringIndex += 0.25;
  if (ringIndex >= 24) {
    ringIndex = 0;
  }
}
*/

/*
// Code used to find the order of the LEDs in the rings

CRGB colors[] = {CRGB::Green, CRGB::Blue, CRGB::Yellow};
int numColors = sizeof(colors) / sizeof(colors[0]);
int testIndex = -1;

int numIndices = sizeof(ringOuter) / sizeof(ringOuter[0]);

bool isIndexInArray(int index) {
  for (int i = 0; i < numIndices; i++) {
    if (ringOuter[i] == index) {
      return true;
    }
  }
  return false;
}

int nextTestIndex(int startIndex) {
  int nextIndex = startIndex + 1;
  while (isIndexInArray(nextIndex)) {
    nextIndex++;
  }
  if (nextIndex >= 100) {
    nextIndex = ringOuter[0];
  }
  Serial.println(nextIndex);
  return nextIndex;
}

void findRingOrder() {
  if (testIndex == -1) {
    testIndex = nextTestIndex(ringOuter[0]);
  }

  int buttonRead = digitalRead(BUTTON_PIN);
  if (buttonRead == HIGH && buttonState == 0) {
    buttonState = 1;
    //pattern = (pattern + 1) % NUM_PATTERNS; // Increment pattern
    testIndex = nextTestIndex(testIndex);
  } else if (buttonRead == LOW && buttonState == 1) {
    buttonState = 0;
  }

  for (int i = 0; i < numIndices; i++) {
    leds[ringOuter[i]] = colors[i % numColors];
  }
  leds[testIndex] = CRGB::Red;
}
*/
