/* ************************************************************************** */
/*                                                          Le - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@Le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 22:28:54 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 14:33:21 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void conv_help(void)
{
  ft_printf("%{blue}__________________\n|    FT_PRINTF    |\n|        by     ");
  ft_printf("  |\n|   remi germain  |\n|                 |\n|  @Help_section ");
  ft_printf(" |\n__________________\n%{eoc}  \nft_printf(%{grey}\"string\"");
  ft_printf("%{eoc},...)\nft_dprintf(%{cyan}fd%{eoc}, %{grey}\"string\"%{eoc},");
  ft_printf("...)\nft_snprintf(%{red}&wuchar_t%{eoc}, %{grey}\"string\"%{eoc}");
  ft_printf("),...)\n  \n%{blue}[conversion specifier]%{eoc}\n\n   s/S/r     ");
  ft_printf("for char &&   utf8 string && no printable string\n   c/C       f");
  ft_printf("or char && utf8 char\n   i/I/d/D   for integer\n   u/U       for");
  ft_printf(" unsigned integer  \n   b/B       for unsigned binary integer\n ");
  ft_printf("  o/O       for unsigned octal integer\n   x/X       for unsigne");
  ft_printf("d hexadecimal integer\n   p/P       forpointer\n   f/F       for");
  ft_printf(" double integer\n   e/E       for double integer with exponent\n");
  ft_printf("   g/G       for double integer witout ending zero digit \n   n ");
  ft_printf("        for assign to int* the Number of characters\n   ts      ");
  ft_printf("  for print double char*\n\n%{blue}[extra]%{eoc}\n   %%{color} ");
  ft_printf("%text %%{eoc}  for print color\n     %{white}white, %{black}blac");
  ft_printf("k, %{red}red, %{green}green, %{yellow}yellow, %{blue}blue, ");
  ft_printf("%{purple}purple, %{cyan}cyan, %{grey}grey%{eoc} \n\n   @  for na");
  ft_printf("me foction to next parameter\n\n\n%{yellow}[flags ]%{eoc} =  #, ");
  ft_printf("0, -, +, \', space\n%{yellow}[field ]%{eoc} =  123456789 , *, $ ");
  ft_printf("\n%{yellow}[preci ]%{eoc} =  .\n%{yellow}[preci ]%{eoc} =  12345");
  ft_printf("6789 , *, $ \n%{yellow}[lenght]%{eoc} =  h, hh, l, ll, j, z, L(o");
  ft_printf("nly for double)\n");
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
