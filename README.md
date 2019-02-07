# Ft_printf :heavy_check_mark:
<img src="https://i.imgur.com/XdwBogU.png" width="450"> <img src="https://i.imgur.com/LN3sIhS.png" height="500" width="650">

``` 
    ft_printf("string",...)
    ft_dprintf(fd, "string",...)
    ft_sprintf(&str, "string",...)
```


#### Conversion specifier
```
 %s %S %r           for char strings   &&    utf8 strings   &&   no printable string
 %c %C              for char   &&    utf8 char
 %i %I %d %D        for integer
 %u %U              for unsigned integer
 %b %B              for unsigned binary integer
 %o %O              for unsigned octal integer
 %x %X              for unsigned hexadecimal integer
 %p                 for pointer
 %f %F              for float
 %e %E              for float with exponent
 %g %G              for float witout ending zero digit
 %n                 for assign to int* the Number of characters
 %m                 for print errno values
 %ts                for print double char*
 %@                 for launch special fonction
 %{T_COLOR}         for put color   &&    backround color   &&    format
```

#### Option
```
 [flags ] =  #, 0, -, +, ', space
 [field ] =  123456789 , *, $
 [preci ] =  .
 [preci ] =  123456789 , *, $
 [lenght] =  h, hh, l, ll, j, z, L(only for double)
 ````
#### Helper
```
ft_printf(%@, "help");
 ````

 <img src="https://i.imgur.com/K3BjTX5.png" width= 50%>

 
 
 ## Credits :fr:
 
 This ft_printf made by GERMAIN Remi , for le-101 shool's projects