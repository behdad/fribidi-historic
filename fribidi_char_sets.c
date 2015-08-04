/* FriBidi - Library of BiDi algorithm
 * Copyright (C) 1999 Dov Grobgeld
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */
#include "fribidi.h"

#define ISO_ALEF 0xE0
#define ISO_TAV 0xFA
#define UNI_ALEF 0x05D0
#define UNI_TAV 0x05EA

FriBidiChar
fribidi_iso8859_8_to_unicode_c(guchar ch)
{
  if (ch >= ISO_ALEF && ch <= ISO_TAV)
    return ch-ISO_ALEF+UNI_ALEF;
  else
    return ch;
}

void
fribidi_iso8859_8_to_unicode(guchar *s,
			     FriBidiChar *us)
{
  int i;
  int len = strlen(s);
  
  for (i=0; i<len+1; i++)
    us[i] = fribidi_iso8859_8_to_unicode_c(s[i]);
}

guchar
fribidi_unicode_to_iso8859_8_c(FriBidiChar uch)
{
  if (uch >= UNI_ALEF && uch <= UNI_TAV)
    return (guchar)(uch-UNI_ALEF+ISO_ALEF);
  else if (uch < 256)
    return (guchar)uch;
  else
    return '�';
}

void
fribidi_unicode_to_iso8859_8(FriBidiChar *us,
			     int length,
			     guchar *s)
		     
{
  int i;
  
  for (i=0; i< length; i++)
    s[i] = fribidi_unicode_to_iso8859_8_c(us[i]);
  s[i] = 0;
}
