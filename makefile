anotherLang.exe: lex.yy.c anotherLang.tab.c
	gcc lex.yy.c anotherLang.tab.c -o anotherLang.exe

lex.yy.c: anotherLang.tab.c anotherLang.l
	flex anotherLang.l

anotherLang.tab.c: anotherLang.y
	bison -d -v anotherLang.y

clean: 
	del -f lex.yy.c anotherLang.tab.c anotherLang.tab.h anotherLang.exe out.c out.exe