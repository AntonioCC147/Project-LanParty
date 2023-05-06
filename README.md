# [LanParty] - Temă la disciplina "Proiectarea Algoritmilor"
Tema are ca scop fixarea și punerea în practică a noțiunilor dobândite pe întreg semestrul atât în cadrul cursurilor cât și în cadrul laboratoarelor.

## Cerință: [Click](https://ocw.cs.pub.ro/courses/sda-ab/tema1)

## Structura poiectului:
```
PA-Project-LanParty
 ├── date/
 │ ├── t1/
 │ │ ├── c.in
 │ │ ├── d.in
 │ ├── ...
 │ ├── t15/
 │ │ ├── c.in
 │ │ ├── d.in
 ├── headers/
 │ ├── BSTandAVL.h
 │ ├── list.h
 │ ├── queue.h
 │ ├── stack.h
 ├── out/
 │ ├── out1.out
 │ ├── ...
 │ ├── out15.out
 ├── rezultate/
 │ ├── r1.out
 │ ├── ...
 │ ├── r15.out
 ├── src/
 │ ├── BSTandAVL.c
 │ ├── list.c
 │ ├── queue.c
 │ ├── stack.c
 ├── README.md
 ├── checker.sh
 ├── lanparty
 ├── main.c
 ├── main.h
 ├── makefile
```
## Rularea & Verificarea programului:
Pentru a putea rula întreg programul este necesară descărcarea codului sursă atașat și executarea comenzii:
```shell
./checker.sh
```
> Această comandă se poate executa doar dacă vă aflați în fișierul sursă.

## General:
- S-a creat un fișier principal `main.c` în care s-au rezolvat toate task-urile prin apeluri de funcții specifice. Fișierul `main.h` conține structurile de bază, dar și bibliotecile predefinite ale limbajului C.
- Întrucât fiecare cerință are necesități diferite (liste, stive, cozi, arbori), am ales să fac fișiere separate pentru fiecare în parte. Fișierele `.c` conțin funcțiile specifice, iar fișierele `.h` conțin antetul acestora și, la nevoie, structuri necesare rezolvării cerințelor.

## Task-uri:
### Task 1:
Ceva

### Task 2:
Ceva