%{
    #include "y.tab.h"
%}
%%
[a-zA-z] { return letter ; }
[0-9]+ { return digits ; }
\n {return 0 ; }
%%
