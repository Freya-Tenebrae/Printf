# ft_printf

This Repositorie contains my solution to the project `ft_printf` of 42 (Paris).

[![cmaginot's 42 stats](https://badge42.vercel.app/api/v2/cl1s5sord008509mlo7xr33zy/stats?cursusId=21&coalitionId=45)](https://github.com/JaeSeoKim/badge42)

[![cmaginot's 42 ft_printf Score](https://badge42.vercel.app/api/v2/cl1s5sord008509mlo7xr33zy/project/2188987)](https://github.com/JaeSeoKim/badge42)

## Using push_swap

### Cloning

```shell
git clone --recurse-submodules https://github.com/Freya-Tenebrae/ft_printf.git
```

### Compilation

```shell
make
```

### Exemple of uses

```c
 #include "includes/ft_printf.h"

int	main(void)
{
	const int		i = 42;
	const char		c = 'c';
	const wint_t	cw = u'Ϡ';
	const char		*s = "coucou";
	const wchar_t	sw[] = {u'Ϡ', u'Ϫ', u'Ϯ', u'ϖ', u'ϰ', u'Ж', u'໘', u'⤐', \
		u'⧲', 0};

	ft_printf("c     : |%c|\ncw    : |%lc|\ns     : |%s|\ns     : |%ls|\n", \
		c, cw, s, sw);
	ft_printf("i     : |%i|\no     : |%o|\nx     : |%x|\nX     : |%X|\n", \
		i, i, i, i);
	ft_printf("p(&i) : |%p|\n", &i);
}

```
```shell
gcc -Wall -Werror -Wextra -fsanitize=address -g3 main.c libftprintf.a && ./a.out
```
```
c     : |c|
cw    : |Ϡ|
s     : |coucou|
s     : |ϠϪϮϖϰЖ໘⤐⧲|
i     : |42|
o     : |52|
x     : |2a|
X     : |2A|
p(&i) : |0x7ffee6b859e0|
```

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
- [x] l (exept for undone specifier) `c and s aren't verified - lc and ls doesn't work for original printf - not tested by the moulinette`
- [x] ll (exept for undone specifier)
- [x] h (exept for undone specifier)
- [x] hh (exept for undone specifier)

### Tester :

- [x] [Tripouille](https://github.com/Tripouille/printfTester)
- [x] [Mazoise](https://github.com/Mazoise/42TESTERS-PRINTF)
- [x] [Kwevan](https://github.com/Kwevan/PRINTF_TESTER)
- [x] [gavinfielder](https://github.com/gavinfielder/pft)
- [x] [cacharle](https://github.com/cacharle/ft_printf_test)

some "error" are present on the tester of cacharle : they are due to the size of the flag Width (more than 10 000). These test work properly on "hand writen" main, but not on him test (memory error an malloc --> my ft_printf stop and send -1).
