/**
 *
 * @file    text.h
 * @author  Alexandre Sollier
 * @date    Janvier 2020
 * @version 1.0
 * @brief   Du texte
 *
 **/

#ifndef GUITEXT_H
#define GUITEXT_H

#include "../tools/glut_font.h"
#include "../graph/iminglinjectable.h"
#include "../transition/itransitionable.h"

/**
 * @namespace nsGui
 * @brief Espace de nom pour des éléments d'interface complexes
 */
namespace nsGui {

/**
 * @class Text
 * @brief Gère l'affichage d'un texte
 */
class Text : public IminGLInjectable, public nsTransition::ITransitionable
{
public:
    /**
     * @brief TransitionIds : Liste de toutes les transitions que cet élément peut exécuter
     */
    enum TransitionIds {
        TRANSITION_COLOR_RGB, /**< Transition pour la couleur RGB */
        TRANSITION_COLOR_ALPHA, /**< Transition pour la transparence */
        TRANSITION_POSITION, /**< Transition pour la position */
    };

    /**
     * @brief VerticalAlignment : Liste de tout les alignements verticaux supportés
     */
    enum VerticalAlignment {
        ALIGNV_TOP, /**< Le texte sera aligné verticallement en haut */
        ALIGNV_CENTER, /**< Le texte sera aligné verticallement au centre */
        ALIGNV_BOTTOM, /**< Le texte sera aligné verticallement en bas */
    };

    /**
     * @brief HorizontalAlignment : Liste de tout les alignements horizontaux supportés
     */
    enum HorizontalAlignment {
        ALIGNH_LEFT, /**< Le texte sera aligné horizontalement a gauche */
        ALIGNH_CENTER, /**< Le texte sera aligné horizontalement au centre */
        ALIGNH_RIGHT, /**< Le texte sera aligné horizontalement a droite */
    };

    /**
     * @brief Constructeur pour la classe Text
     * @param[in] position : Position du texte
     * @param[in] content : Contenu du texte
     * @param[in] textColor : Couleur du texte
     * @param[in] textFont : Police du texte (8x13 Bitmap par défaut)
     * @param[in] horizontalAlignment : Alignement horizontal du texte (Alignement a gauche par défaut)
     * @param[in] verticalAlignment : Alignement vertical du texte (Alignement en bas par défaut)
     * @fn Text(const Vec2D &position, const std::string &content,
         const RGBAcolor &textColor, const GlutFont::GlutFonts &textFont = GlutFont::GlutFonts::BITMAP_8_BY_13,
         const HorizontalAlignment &horizontalAlignment = ALIGNH_LEFT,
         const VerticalAlignment &verticalAlignment = ALIGNV_BOTTOM);
     */
    Text(const Vec2D &position, const std::string &content,
         const RGBAcolor &textColor, const GlutFont::GlutFonts &textFont = GlutFont::GlutFonts::BITMAP_8_BY_13,
         const HorizontalAlignment &horizontalAlignment = ALIGNH_LEFT,
         const VerticalAlignment &verticalAlignment = ALIGNV_BOTTOM);

    virtual void draw(MinGL& window) const override;

    virtual void getValues(const int &id, std::vector<float> &values) override;
    virtual void setValues(const int &id, const std::vector<float> &values) override;

    /**
     * @brief Calcule la largeur de ce texte
     * @return La largeur du texte
     * @fn int computeWidth() const;
     */
    int computeWidth() const;

    /**
     * @brief Calcule la hauteur de ce texte
     * @return La hauteur du texte
     * @fn int computeHeight() const;
     */
    int computeHeight() const;

    /**
     * @brief Calcule la position visible du texte, calculée avec l'alignement vertical et horizontal
     * @return La position visible, en haut a gauche
     * @fn Vec2D computeVisibleposition() const;
     */
    Vec2D computeVisiblePosition() const;

    /**
     * @brief Calcule la position de fin visible du texte, calculée avec l'alignement vertical et horizontal
     * @return La position visible, en bas a droite
     * @fn Vec2D computeVisibleEndPosition() const;
     */
    Vec2D computeVisibleEndPosition() const;

    /**
     * @brief Récupère le contenu du texte
     * @return Une référence constante vers m_content
     * @fn const std::string& getContent() const;
     */
    const std::string& getContent() const;

    /**
     * @brief Définit le nouveau contenu du texte
     * @param[in] content : Nouveau contenu
     * @fn void setContent(const std::string &content);
     */
    void setContent(const std::string &content);

private:
    /**
     * @brief m_position : Position du texte
     */
    Vec2D m_position;

    /**
     * @brief m_content : Contenu du texte
     */
    std::string m_content;

    /**
     * @brief m_textColor : Couleur du texte
     */
    RGBAcolor m_textColor;

    /**
     * @brief m_textFont : Police du texte
     */
    GlutFont m_textFont;

    /**
     * @brief m_horizontalAlignment : Alignement horizontal du texte
     */
    HorizontalAlignment m_horizontalAlignment;

    /**
     * @brief m_verticalAlignment : Alignement vertical du texte
     */
    VerticalAlignment m_verticalAlignment;
};

} // namespace nsGui

#endif // GUITEXT_H
