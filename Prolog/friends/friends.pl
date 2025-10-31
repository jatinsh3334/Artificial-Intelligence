% Facts
likes(jatin, pizza).
likes(keshav, pasta).
likes(rahul, pizza).

% Rules
friends(X, Y) :- likes(X, Z), likes(Y, Z), X \= Y.
