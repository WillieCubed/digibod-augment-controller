#ifndef SPEAKER_UTILS_H_
#define SPEAKER_UTILS_H_

struct Tone
{
  unsigned int frequency;
  unsigned long duration;
};

void playTone(unsigned int frequency, unsigned long duration);

void playTones(Tone *tones);

#endif // SPEAKER_UTILS_H_