:-dynamic father/2.
:-dynamic mother/2.
:-dynamic parent/2.
:-dynamic child/2.
:-dynamic aunt/2.
:-dynamic uncle/2.
:-dynamic son/2.
:-dynamic daughter/2.
:-dynamic male/1.
:-dynamic female/1.
:-dynamic siblings/2.
:-dynamic brother/2.
:-dynamic sister/2.
:-dynamic grandfather/2.
:-dynamic grandmother/2.
:-dynamic relatives/2.
:-dynamic relative/2.

male(X):-son(X,_);father(X,_);grandfather(X,_);brother(X,_);uncle(X,_).
female(X):-daughter(X,_);mother(X,_);grandmother(X,_);sister(X,_);aunt(X,_).
parent(X,Y):-son(Y,X);daughter(Y,X).
parent(X,Y):-father(X,Y);mother(X,Y).
child(X,Y):-parent(Y,X).
grandfather(X,Z):-father(X,Y),parent(Y,Z).
grandmother(X,Z):-mother(X,Y),parent(Y,Z).
aunt(X,Y):-sister(X,A),parent(A,Y).
uncle(X,Y):-brother(X,A),parent(A,Y).
siblings(X,Y):-parent(Z,X),parent(Z,Y).
siblings(X,Y):-brother(X,Y);sister(X,Y).
sibling(Y,X):-siblings(X,Y).
relatives(X,Y):-parent(X,Y);grandfather(X,Y);grandmother(X,Y);aunt(X,Y);uncle(X,Y);brother(X,Y);sister(X,Y);siblings(X,Y).
relatives(Y,X):-parent(Y,X);grandfather(Y,X);grandmother(Y,X);aunt(Y,X);uncle(Y,X);brother(Y,X);sister(Y,X);sibling(X,Y).
relative(Y,X):-relatives(X,Y).