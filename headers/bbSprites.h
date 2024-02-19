/** 
* @brief
 *
 *
 *
*/

#ifndef BBSPRITES_H
#define BBSPRITES_H

#include "../headers/system_includes.h"

/** @name sfSprite is the basic object drawn to the viewport
 * bbSprites is a container for sfSprites used in a single bbMap
 **/
///@{
typedef struct { //bbSprites

	sfSprite** m_Sprites;
	bbDictionary* m_Dictionary;

} bbSprites;
///@}
#endif //BBSPRITES_H