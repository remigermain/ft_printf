/* ************************************************************************** */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 15:34:47 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 18:57:02 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void conv_help(void)
{
  char *str;

  str = "%{blue}__________________\n|    FT_PRINTF    |\n|        by       |\n"
  "|   remi germain  |\n"
  "|                 |\n|  @Help_section  |\n__________________\n%{eoc}  \nft_p"
  "rintf(%{grey}\"string\"%{eoc},...)\nft_dprintf(%{cyan}fd%{eoc}, %{grey}\"str"
  "ing\"%{eoc},...)\nft_snprintf(%{red}&wuchar_t%{eoc}, %{grey}\"string\"%{eoc}"
  ",...)\n  \n%{blue}[conversion specifier]%{eoc}\n"
  "\n   s/S/r     for char &&   utf8 string && no printable string\n   c/C    "
  "   for char && utf8 char\n   i/I/d/D   for integer\n   u/U       for unsign"
  "ed integer  \n   b/B       for unsigned binary integer\n   o/O       for un"
  "signed octal integer\n   x/X       for unsigned hexadecimal integer\n   p/P"
  "       forpointer\n   f/F       for double integer\n   e/E       for double"
  " integer with exponent\n   g/G       for double integer witout ending zero d"
  "igit \n   n         for assign to int* the Number of characters\n   ts      "
  " for print double char*\n\n%{blue}[extra]%{eoc}\n   %%{color} %text %%{eoc} "
  " for print color\n     %{white}white, %{black}black, %{red}red, %{green}gree"
  "n, %{yellow}yellow, %{blue}blue, %{purple}purple, %{cyan}cyan, %{grey}grey"
  "%{eoc} \n\n   @  for name foction to next parameter\n\n\n%{yellow}[flags ]"
  "%{eoc} =  #, 0, -, +, \', space\n%{yellow}[field ]%{eoc} =  123456789 , *,"
  " $ \n%{yellow}[preci ]%{eoc} =  .\n%{yellow}[preci ]%{eoc} =  123456789 , "
  "*,$ \n%{yellow}[lenght]%{eoc} =  h, hh, l, ll, j, z, L(only for double)\n";
   ft_printf(str);
}

int   conv_other(t_pf *lst, char *str, int index)
{
  char *other;

	lst_putoption(lst, str, index);
  other = va_arg(lst->va_copy, char*);
  if (strncmp(other, "help", 4) == 0)
    conv_help();
  return (index + 1);
}
