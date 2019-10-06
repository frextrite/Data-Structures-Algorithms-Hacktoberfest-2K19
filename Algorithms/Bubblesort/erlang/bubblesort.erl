-module(bubblesort).
-export([sort/1]).

sort(List) ->
    sort(List, [], false).

sort( [], Acc, true ) ->
    lists:reverse( Acc );
sort( [], Acc, false ) ->
    sort( lists:reverse(Acc), [], true );
sort( [X, Y | T], Acc, _Done ) when X > Y ->
    sort( [X | T], [Y | Acc], false );
sort( [X | T], Acc, Done ) ->
    sort( T, [X | Acc], Done ).
