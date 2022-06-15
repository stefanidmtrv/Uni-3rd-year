%lexicon

%pronouns
lex(i, pro, singular, 1, subject).
lex(you, pro, singular, 2, subject).
lex(he, pro, singular, 3, subject).
lex(she,pro,singular,3,subject).
lex(it,pro,singular,3,subject).
lex(we,pro,plural,1,subject).
lex(you,pro,plural,2,subject).
lex(they,pro,plural,3,subject).
lex(me,pro,singular,1,object).
lex(you,pro,singular,2,object).
lex(him,pro,singular,3,object).
lex(her,pro,singular,3,object).
lex(it,pro,singular,3,object).
lex(us,pro,plural,1,object).
lex(us,pro,plural,1,object).
lex(you,pro,plural,2,object).
lex(them,pro,plural,3,object).

%verbs
lex(know,tv,singular,1,a).
lex(know,tv,singular,2,a).
lex(knows,tv,singular,3,a).
lex(know,tv,plural,_,a).
lex(see,tv,singular,1,a).
lex(see,tv,singular,2,a).
lex(sees,tv,singular,3,a).
lex(see,tv,plural,_,a).
lex(hire,tv,singular,1,a).
lex(hire,tv,singular,2,a).
lex(hires,tv,singular,3,a).
lex(hire,tv,plural,_,a).
lex(fall,iv,singular,1,_).
lex(fall,iv,singular,2,_).
lex(falls,iv,singular,3,_).
lex(fall,iv,plural,_,_).
lex(sleep,iv,singular,1,a).
lex(sleep,iv,singular,2,a).
lex(sleeps,iv,singular,3,a).
lex(sleep,iv,plural,_,a).

%determiners
lex(the,det,_).
lex(a,det,singular).
lex(two,det,plural).

%nouns
lex(man,n,singular,a).
lex(woman,n,singular,a).
lex(apple,n,singular,i).
lex(chair,n,singular,i).
lex(room,n,singular,i).
lex(men,n,plural,a).
lex(women,n,plural,a).
lex(apples,n,plural,i).
lex(chairs,n,plural,i).
lex(rooms,n,plural,i).

%prepositions
lex(on,prep).
lex(in,prep).
lex(under,prep).

%adjectives
lex(old,adj).
lex(young,adj).
lex(red,adj).
lex(short,adj).
lex(tall,adj).

%grammar rules

%A sentence consisting of a noun phrase and a verb phrase
s(s(NP,VP)) --> np(NP,Num,Per,subject,A), vp(VP,Num,Per,A).

%noun phrase definitions
%noun phrase - Der(determiner), Per (grammatical person), Num(singlular or plural),
%Z(subject or object), A(animacy), P(preposition), NBar(noun)

%noun phrase starting with a determiner
np(np(Det,NBar),Num, Per, _, A) --> det(Det,Num), nbar(NBar, Num, Per, A).

%noun phrase starting with a pronoun
np(np(Pro),Num,Per,Z,_) --> pro(Pro,Num,Per,Z).

%noun phrase with a preposition
np(np(Det,NBar,P),Num, Per, _,A) --> det(Det,Num), nbar(NBar, Num, Per, A), pp(P).


%verb phrases(transitive(TV) and intransitive(IV))
vp(vp(IV),Num,Per,A) --> v(IV,iv,Num,Per,A).
vp(vp(TV,NP),Num,Per,A) --> v(TV,tv,Num,Per,A), np(NP,_,_,object,_).

%joint phrases (adjective and a noun)
jp(N,Num,A) --> n(N,Num,A).
jp(jp(Adj,JP),Num,A) --> adj(Adj),jp(JP,Num,A).
nbar(nbar(JP),Num,3,A) --> jp(JP,Num,A).

%prepositional phrases
pp(pp(P,NP)) --> prep(P), np(NP,_,_,object,_).

%lexicon
pro(pro(Word),Num,Per,Z) --> [Word], {lex(Word,pro,Num,Per,Z)}.
det(det(Word),Num) --> [Word], {lex(Word,det,Num)}.
n(n(Word),Num,A) --> [Word], {lex(Word,n,Num,A)}.
v(v(Word),TV,Num,Per,A) --> [Word], {lex(Word,TV,Num,Per,A)}.
adj(adj(Word)) --> [Word], {lex(Word,adj)}.
prep(prep(Word)) --> [Word], {lex(Word,prep)}.


/**
test cases:
?- s(Tree,[the,woman,sees,the,apples],[]).
Tree = s(np(det(the), nbar(n(woman))), vp(v(sees), np(det(the), nbar(n(apples))))).

?- s(Tree,[a, woman, knows, him] ,[]).
Tree = s(np(det(a), nbar(n(woman))), vp(v(knows), np(pro(him)))).

?- s(Tree,[two, woman, hires, a, man] ,[]).
false.

?- s(Tree,[two, women, hire, a, man] ,[]).
Tree = s(np(det(two), nbar(n(women))), vp(v(hire), np(det(a), nbar(n(man))))).

?- s(Tree,[she, knows, her] ,[]).
Tree = s(np(pro(she)), vp(v(knows), np(pro(her)))).

?- s(Tree,[she, know, the, man] ,[]).
false.

?- s(Tree,[us, see, the, apple] ,[]).
false.

?- s(Tree,[we, see, the, apple] ,[]).
Tree = s(np(pro(we)), vp(v(see), np(det(the), nbar(n(apple))))).

?- s(Tree,[i, know, a, short, man] ,[]).
Tree = s(np(pro(i)), vp(v(know), np(det(a), nbar(jp(adj(short), n(man)))))).

?- s(Tree,[he, hires, they] ,[]).
false.

?- s(Tree,[two, apples, fall] ,[]).
Tree = s(np(det(two), nbar(n(apples))), vp(v(fall))).

?- s(Tree,[the, apple, falls] ,[]).
Tree = s(np(det(the), nbar(n(apple))), vp(v(falls))).

?- s(Tree,[the, apples, fall] ,[]).
Tree = s(np(det(the), nbar(n(apples))), vp(v(fall))).

?- s(Tree,[i, sleep] ,[]).
Tree = s(np(pro(i)), vp(v(sleep))).

?- s(Tree,[you, sleep] ,[]).
Tree = s(np(pro(you)), vp(v(sleep))).

?- s(Tree,[she, sleeps] ,[]).
Tree = s(np(pro(she)), vp(v(sleeps))).

?- s(Tree,[he, sleep] ,[]).
false.

?- s(Tree,[them, sleep] ,[]).
false.

?- s(Tree,[a, men, sleep] ,[]).
false.

?- s(Tree,[the, tall, woman, sees, the, red] ,[]).
false.

?- s(Tree,[the, young, tall, man, knows, the, old, short, woman] ,[]).
Tree = s(np(det(the), nbar(jp(adj(young), jp(adj(tall), n(man))))), vp(v(knows), np(det(the), nbar(jp(adj(old), jp(adj(short), n(woman))))))).

?- s(Tree,[a, man, tall, knows, the, short, woman] ,[]).
false.

?- s(Tree,[a, man, on, a, chair, sees, a, woman, in, a, room] ,[]).
Tree = s(np(det(a), nbar(n(man)), pp(prep(on), np(det(a), nbar(n(chair))))), vp(v(sees), np(det(a), nbar(n(woman)), pp(prep(in), np(det(a), nbar(n(room))))))).

?- s(Tree,[a, man, on, a, chair, sees, a, woman, a, room, in] ,[]).
false.

?- s(Tree,[the, tall, young, woman, in, a, room, on, the, chair, in, a, room, in, the, room, sees, the, red, apples, under, the, chair] ,[]).
Tree = s(np(det(the),nbar(jp(adj(tall),jp(adj(young),n(woman)))),pp(prep(in),np(det(a),nbar(n(room)),pp(prep(on),np(det(the),nbar(n(chair)),
pp(prep(in),np(det(a),nbar(n(room)),pp(prep(in),np(det(the),nbar(n(room))))))))))),vp(v(sees),np(det(the),nbar(jp(adj(red),n(apples))),
pp(prep(under),np(det(the),nbar(n(chair))))))).


?- s(Tree,[the, woman, sees, the, apples] ,[]).
Tree = s(np(det(the), nbar(n(woman))), vp(v(sees), np(det(the), nbar(n(apples))))).

?- s(Tree,[a, woman, knows, him] ,[]).
Tree = s(np(det(a), nbar(n(woman))), vp(v(knows), np(pro(him)))).

?- s(Tree,[the, man, sleeps] ,[]).
Tree = s(np(det(the), nbar(n(man))), vp(v(sleeps))).

?- s(Tree,[the, room, sleeps] ,[]).
false.

?- s(Tree,[the, apple, sees, the, chair] ,[]).
false.

?- s(Tree,[the, rooms, know, the, man] ,[]).
false.

?- s(Tree,[the, apple, falls] ,[]).
Tree = s(np(det(the), nbar(n(apple))), vp(v(falls))).

?- s(Tree,[the, man, falls],[]).
Tree = s(np(det(the), nbar(n(man))), vp(v(falls))).


Additional tests:
?- s(Tree,[I, know,she] ,[]).
false.

?- s(Tree,[he, knows,a,tall,young,man] ,[]).
Tree = s(np(pro(he)), vp(v(knows), np(det(a), nbar(jp(adj(tall), jp(adj(young), n(man))))))).

?- s(Tree,[a, man, on, a, chair, knows, a, woman, in, a, room] ,[]).
Tree = s(np(det(a), nbar(n(man)), pp(prep(on), np(det(a), nbar(n(chair))))), vp(v(knows), np(det(a), nbar(n(woman)), pp(prep(in), np(det(a), nbar(n(room))))))). 
**/
