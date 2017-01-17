lab2docalc : y.tab.c lex.yy.c
	gcc y.tab.c -o lab2docal
lex.yy.c : lab2docalc.l 
	lex lab2docalc.l
y.tab.c : lab5cminustruncate.y
	yacc -d lab5cminustruncate.y
clean :
	rm *h
