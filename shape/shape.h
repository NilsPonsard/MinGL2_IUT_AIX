/**
 *
 * @file    shape.h
 * @author  Alexandre Sollier
 * @date    Janvier 2020
 * @version 1.0
 * @brief   Représente une forme
 *
 **/

#ifndef FIG2_H
#define FIG2_H

#include "../graph/iminglinjectable.h"

/**
 * @namespace nsShape
 * @brief Espace de nom pour différentes formes
 */
namespace nsShape
{

/**
 * @class Shape
 * @brief Classe de base pour une forme
 */
class Shape: public IminGLInjectable
{

public:
    /**
     * @brief Constructeur pour la classe Shape
     * @param[in] fillColor : Couleur de remplissage de la forme
     * @param[in] borderColor : Couleur de bord de la forme
     * @fn Shape(const RGBAcolor& fillColor, const RGBAcolor& borderColor);
     */
    Shape(const RGBAcolor& fillColor, const RGBAcolor& borderColor);

    /**
     * @brief Destructeur virtuel pour la classe Shape
     * @fn virtual ~Shape() = default;
     */
    virtual ~Shape() = default;

    /**
     * @brief Retourne la couleur de remplissage
     * @fn const RGBAcolor& getFillColor() const;
     */
    const RGBAcolor& getFillColor() const;

    /**
     * @brief Retourne la couleur de bord
     * @fn const RGBAcolor& getBorderColor() const;
     */
    const RGBAcolor& getBorderColor() const;

private:
    /**
     * @brief m_fillColor : Couleur de remplissage
     */
    RGBAcolor m_fillColor;

    /**
     * @brief m_borderColor : Couleur de bord
     */
    RGBAcolor m_borderColor;

};

}

#endif // FIG2_H
