# Ft_printf :heavy_check_mark:
![alt text](https://imgur.com/a/TZMkD8t)

``` 
    ft_printf("string",...)
    ft_dprintf(fd, "string",...)
    ft_snprintf(&(unsigned char), "string"),...)
```


#### Conversion specifier
```
 %s %S %r           for char   &&    utf8 string   &&   no printable string
 %c %C              for char   &&    utf8 char
 %i %I %d %D        for integer
 %u %U              for unsigned integer
 %b %B              for unsigned binary integer
 %o %O              for unsigned octal integer
 %x %X              for unsigned hexadecimal integer
 %p                 for pointer
 %f %F              for double float
 %e %E              for double float with exponent
 %g %G              for double float witout ending zero digit
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
 
 ## Credits :fr:
 
 This ft_printf made by GERMAIN Remi , for le-101 shool's projects