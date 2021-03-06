/**
 * @file glut_font.cpp
 * @brief Classe utilitaire pour utiliser facilement les polices de Glut
 * @author SOLLIER Alexandre
 * @version 1.0
 * @date 28 décembre 2019
 */

#include "../tools/glut_font.h"

#include <GL/freeglut_std.h>

GlutFont::GlutFont(const GlutFont::GlutFonts &font)
    : m_font(font)
{} // GlutFont()

void *GlutFont::convertForGlut() const
{
    // Check the current font and return the right Glut identifier
    switch (m_font)
    {
        case BITMAP_9_BY_15:
            return GLUT_BITMAP_9_BY_15;
        case BITMAP_TIMES_ROMAN_10:
            return GLUT_BITMAP_TIMES_ROMAN_10;
        case BITMAP_TIMES_ROMAN_24:
            return GLUT_BITMAP_TIMES_ROMAN_24;
        case BITMAP_HELVETICA_10:
            return GLUT_BITMAP_HELVETICA_10;
        case BITMAP_HELVETICA_12:
            return GLUT_BITMAP_HELVETICA_12;
        case BITMAP_HELVETICA_18:
            return GLUT_BITMAP_HELVETICA_18;
        default:
            return GLUT_BITMAP_8_BY_13;
    }
} // convertForGlut()
