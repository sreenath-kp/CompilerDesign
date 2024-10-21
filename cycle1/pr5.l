%{
	#include "y.tab.h"
%}
%%
[a-zA-Z_] { return LETTER; }
[0-9] { return DIGIT; }
[\n] { return NL; }
. { return yytext[0]; }
%%