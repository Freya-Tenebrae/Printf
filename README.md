# Printf

Ce dépôt contiens ma solution au projet `ft_printf` de 42 (Paris).

This Repositorie contains my solution to the project `ft_printf` of 42 (Paris).

[![jaeskim's 42 stats](https://badge42.herokuapp.com/api/stats/cmaginot?cursus=42cursus&privacyName=true)](https://github.com/JaeSeoKim/badge42)

[![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/cmaginot/ft_printf)](https://github.com/JaeSeoKim/badge42)

## Avancement / Advancement

### Mandatory :

#### Specifier :

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

#### Flag :

- [x] Width
- [x] -
- [x] 0
- [x] .
- [x] *

### Bonus :

#### Specifier (droped) :

- [ ] n
- [ ] f `precision in particular case doesn't work`
- [ ] e `precision in particular case doesn't work`
- [ ] g 

#### Flag :

- [x] #
- [x] +
- [x] Space
- [x] l (exept for undone specifier) `c and s doesn't work correctly - lc and ls doesn't work for original printf - not tested by the moulinette`
- [x] ll (exept for undone specifier)
- [x] h (exept for undone specifier)
- [x] hh (exept for undone specifier)

### Other

- [x] Leaks
- [x] Norm
- [x] clean code (harmonizing the code and avoid repetitions)
- [x] Securisation of memory allocation
- [ ] Manage Mandatory and Bonuses organisation
- [x] Test [Tripouille](https://github.com/Tripouille/printfTester)
- [x] Test [Mazoise](https://github.com/Mazoise/42TESTERS-PRINTF)
- [x] Test [Kwevan](https://github.com/Kwevan/PRINTF_TESTER)
- [x] Test [gavinfielder](https://github.com/gavinfielder/pft)
- [x] Test [cacharle](https://github.com/cacharle/ft_printf_test)

some "error" are present on the tester of cacharle : they are due to the size of the flag Width (more than 10 000). These test work properly on "hand writen" main, but not on him test (memory error an malloc --> my ft_printf stop and send -1).
