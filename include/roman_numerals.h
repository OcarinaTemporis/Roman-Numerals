#ifndef ROMAN_NUMERALS_H
#define ROMAN_NUMERALS_H

#include "ultra64.h"

typedef enum RomanNumeralGlyph {
    ROMAN_NUMERAL_GLYPH_I,
    ROMAN_NUMERAL_GLYPH_V,
    ROMAN_NUMERAL_GLYPH_X,
    ROMAN_NUMERAL_GLYPH_L,
    ROMAN_NUMERAL_GLYPH_C,
    ROMAN_NUMERAL_GLYPH_D,
    ROMAN_NUMERAL_GLYPH_M,
    ROMAN_NUMERAL_GLYPH_MAX
} RomanNumeralGlyph;

#define ROMAN_NUMERAL_GLYPH_NONE 0xFF
#define ROMAN_NUMERAL_MAX_GLYPHS 16
#define AMMO_ROMAN_GLYPH_ADVANCES { 2, 6, 6, 4, 4, 4, 4 }

/** format a value as Roman glyphs */
s32 RomanNumerals_Format(s16 value, u8* glyphs, s32 glyphCapacity);

#endif
