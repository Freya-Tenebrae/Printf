# Printf

Ce dépôt contiens ma solution au projet `ft_printf` de 42 (Paris).

This Repositorie contains my solution to the project `ft_printf` of 42 (Paris).

[![jaeskim's 42 stats](https://badge42.herokuapp.com/api/stats/cmaginot?cursus=42cursus&privacyName=true)](https://github.com/JaeSeoKim/badge42)

[![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/cmaginot/ft_printf)](https://github.com/JaeSeoKim/badge42)

## Avancement / Advancement

### Specifier :

- [x] c
- [x] s
- [x] p
- [x] d
- [x] i
- [x] u
- [x] o
- [x] x
- [x] X
- [x] %
- [ ] n
- [ ] f `(precision with more than 20 numbers in variable aren't correct)` `need to rework precision on ft_ftoa.c (3.99999999, 6) -> 4.000000 and not 3.00000, ft_ftoa.c (3.85, 1) -> 3.9 and not 3.8`
- [ ] e `(precision with more than 20 numbers in variable aren't correct)`
- [ ] g 

### Flag :

- [x] Numbers (Width)
- [x] -
- [x] 0
- [x] .
- [x] *
- [x] +
- [x] Space
- [x] l (exept for undone specifier) `c and s doesn't work correctly`
- [x] ll (exept for undone specifier)
- [x] h (exept for undone specifier)
- [x] hh (exept for undone specifier)
- [x] #

### Other

- [x] Leaks
- [x] Norm
- [x] clean code (harmonizing the code and avoid repetitions)
- [x] Securisation of memory allocation
- [ ] Manage Mandatory and Bonuses organisation
- [ ] Test [Tripouille](https://github.com/Tripouille/printfTester)
- [ ] Test [Mazoise](https://github.com/Mazoise/42TESTERS-PRINTF)
- [ ] Test [Kwevan](https://github.com/Kwevan/PRINTF_TESTER)
- [ ] Test [gavinfielder](https://github.com/gavinfielder/pft)
- [ ] Test [cacharle](https://github.com/cacharle/ft_printf_test)
