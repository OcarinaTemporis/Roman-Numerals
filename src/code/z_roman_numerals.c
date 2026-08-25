#include "array_count.h"
#include "roman_numerals.h"

typedef struct RomanNumeralToken {
    s16 value;
    u8 firstGlyph;
    u8 secondGlyph;
} RomanNumeralToken;

s32 RomanNumerals_Format(s16 value, u8* glyphs, s32 glyphCapacity) {
    static RomanNumeralToken sTokens[] = {
        { 1000, ROMAN_NUMERAL_GLYPH_M, ROMAN_NUMERAL_GLYPH_NONE },
        { 900, ROMAN_NUMERAL_GLYPH_C, ROMAN_NUMERAL_GLYPH_M },
        { 500, ROMAN_NUMERAL_GLYPH_D, ROMAN_NUMERAL_GLYPH_NONE },
        { 400, ROMAN_NUMERAL_GLYPH_C, ROMAN_NUMERAL_GLYPH_D },
        { 100, ROMAN_NUMERAL_GLYPH_C, ROMAN_NUMERAL_GLYPH_NONE },
        { 90, ROMAN_NUMERAL_GLYPH_X, ROMAN_NUMERAL_GLYPH_C },
        { 50, ROMAN_NUMERAL_GLYPH_L, ROMAN_NUMERAL_GLYPH_NONE },
        { 40, ROMAN_NUMERAL_GLYPH_X, ROMAN_NUMERAL_GLYPH_L },
        { 10, ROMAN_NUMERAL_GLYPH_X, ROMAN_NUMERAL_GLYPH_NONE },
        { 9, ROMAN_NUMERAL_GLYPH_I, ROMAN_NUMERAL_GLYPH_X },
        { 5, ROMAN_NUMERAL_GLYPH_V, ROMAN_NUMERAL_GLYPH_NONE },
        { 4, ROMAN_NUMERAL_GLYPH_I, ROMAN_NUMERAL_GLYPH_V },
        { 1, ROMAN_NUMERAL_GLYPH_I, ROMAN_NUMERAL_GLYPH_NONE },
    };
    s32 glyphCount = 0;
    s32 tokenIndex;
    s32 tokenGlyphCount;

    if ((glyphCapacity <= 0) || (value <= 0) || (value > 3999)) {
        return 0;
    }

    for (tokenIndex = 0; tokenIndex < ARRAY_COUNT(sTokens); tokenIndex++) {
        tokenGlyphCount = sTokens[tokenIndex].secondGlyph == ROMAN_NUMERAL_GLYPH_NONE ? 1 : 2;

        while (value >= sTokens[tokenIndex].value) {
            if ((glyphCount + tokenGlyphCount) > glyphCapacity) {
                return glyphCount;
            }

            glyphs[glyphCount++] = sTokens[tokenIndex].firstGlyph;
            if (tokenGlyphCount == 2) {
                glyphs[glyphCount++] = sTokens[tokenIndex].secondGlyph;
            }
            value -= sTokens[tokenIndex].value;
        }
    }

    return glyphCount;
}
