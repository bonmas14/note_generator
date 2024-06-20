#include <stdio.h>
#include <stdint.h>

const double octave_zero[12] = {
    16.35, // C0
    17.32,
    18.35,
    19.45,
    20.60,
    21.83,
    23.12,
    24.50,
    25.96,
    27.50, // A0
    29.14,
    30.87
};

char get_note_char(size_t note);

int main(int argc, char** argv) {
    puts("#pragma once");
    for (size_t i = 0; i < 9; i++) {
        printf("// octave %lu\n", i);
        for (size_t note = 0; note < 12; note++) {
            printf("#define NOTE_%c%lu %d\n", get_note_char(note), i, (uint32_t)(octave_zero[note] * (double)(1 << i)));
        }
    }
}

char get_note_char(size_t note) {
    switch (note) {
        case 0: return 'C';
        case 1: return 'c';
    
        case 2: return 'D';
        case 3: return 'd';

        case 4: return 'E';

        case 5: return 'F';
        case 6: return 'f';
    
        case 7: return 'G';
        case 8: return 'g';

        case 9: return 'A';
        case 10: return 'a';

        case 11: return 'B';
    }

    return '_';
}
