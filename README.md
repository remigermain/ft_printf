 |    ft_printf    |
 |        by       |
 |  Remi GERMAIN   |
 |        😎       |
 |  @Help_section  |


    ft_printf("string",...)
    ft_dprintf(fd, "string",...)
    ft_snprintf(&wuchar_t, "string"),...)

 [conversion specifier]

   s/S/r     for char && utf8 string && no printable string
   c/C       for char && utf8 char
   i/I/d/D   for integer
   u/U       for unsigned integer
   b/B       for unsigned binary integer
   o/O       for unsigned octal integer
   x/X       for unsigned hexadecimal integer
   p         for pointer
   f/F       for double integer
   e/E       for double integer with exponent
   g/G       for double integer witout ending zero digit
   n         for assign to int* the Number of characters
   m         for print errno values
   ts        for print double char*

 [extra]
   %{T_COLOR} %text %{T_EOC}  for print color
      T_WHITE, T_BLACK, T_RED, T_GREEN, T_YELLOW, T_BLUE T_PURPLE T_CYAN T_LGREY
 T_DGREY    T_LRED   T_LGREEN    L_YELLOW   T_LBLUE    T_LPURPLE   T_LCYAN

   %{B_COLOR} backgroud %{B_EOC} for backgroud color


   %{F_FORMAT} FORMAT %{F_EOC}  for special format
    DEF    BOLD     UDERLINE    BLINK    REVERSE    INVISIBLE

   @  for name foction to next parameter


 [flags ] =  #, 0, -, +, ', space
 [field ] =  123456789 , *, $
 [preci ] =  .
 [preci ] =  123456789 , *, $
 [lenght] =  h, hh, l, ll, j, z, L(only for double)