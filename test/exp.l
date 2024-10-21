%{
    #include "y.tab.h"
%}

%%
[a-zA-Z_][a-zA-Z_0-9]* { return id ; }
[/*+-] { return op ; }
[\n] { return NL ;}
%%