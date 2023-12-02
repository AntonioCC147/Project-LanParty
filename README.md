# [LanParty] - Proiect la Disciplina "Proiectarea Algoritmilor"
Proiectul are ca scop fixarea și punerea în practică a noțiunilor dobândite pe întreg semestrul atât în cadrul cursurilor, cât și în cadrul laboratoarelor.

## Cerință: [CLICK](https://ocw.cs.pub.ro/courses/sda-ab/tema1)

## Structura Proiectului:
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
 │ ├── tasksFunctions.h
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
 │ ├── tasksFunctions.c
 ├── README.md
 ├── checker.sh
 ├── lanparty
 ├── main.c
 ├── main.h
 ├── makefile
```
## Rularea & Verificarea Programului:
Pentru a putea rula întreg programul este necesară descărcarea codului sursă atașat și executarea comenzii:
```shell
./checker.sh
```
> Această comandă se poate executa doar dacă vă aflați în fișierul în care se află și codul sursă.

## Informații Generale:
- S-a creat un fișier principal `main.c` în care s-au rezolvat toate task-urile prin apeluri de funcții specifice.
- Fișierul `main.h` conține structurile de bază, dar și bibliotecile predefinite ale limbajului `C`.
- Întrucât fiecare cerință are necesități diferite (liste, stive, cozi, arbori), am ales să fac fișiere separate pentru fiecare în parte.
- Fișierele `.c` conțin funcțiile specifice, iar fișierele `.h` conțin antetele acestora și, la nevoie, structuri necesare rezolvării cerințelor.

## Rezolvarea Task-urilor:
### Task 1:
- Citirea din fișiere s-a făcut în funția `main()` din fișierul `main.c`. Aici s-a creat o listă și s-au introdus în ordine echipele, împreună cu numele jucătorilor și detaliile specifice acestora.

### Task 2:
- Pentru acest task am creat mai multe funcții de determinare a punctajelor corespunzătoare. Ulterior am aflat numărul maxim de echipe ce pot rămâne folosind o simplă instrucțiune repetitivă, apoi am început să șterge echipele cu cel mai slab scor.
- Ștergerea am făcut-o astfel: La fiecare pas, determinam cel mai slab punctaj, apoi ștergeam echipa din listă. Ulterior, reluam algoritmul și se determina următoarea echipă care avea cel mai mic scor, din cele rămase anterior și așa mai departe.
- Pentru cazul în care două echipe au același scor, am eliminat pur și simplu prima echipă care îmi ieșea în cale, conform totodată și cerinței.

### Task 3:
- Acesta consider că a fost cel mai complicat task pe care a trebuit să-l fac. Am creat coada corespunzătoare meciurilor dintre echipe și am introdus echipele acolo.
- Ulterior, am scos echipele două câte două și am verificat care dintre ele are punctajul mai mare. Le-am introdus în cele două stive după caz, dar am și actualizat punctajul echipei câștigătoare.
- În tot acest timp, afișam câștigătorii după formatul cerut și eliminam lista cu cei învinși.
- Ultimele 8 echipe au fost salvate într-o listă specială conform task-ului, iar mai apoi s-a continuat afișarea echipelor până la cea câștigătoare.

### Task 4:
- La acest task m-am folosit de lista creată mai sus. Am inserat echipele într-un `BST`, iar algoritmul și-a făcut singur treaba.
- De asemenea, am ținut cont și de cazurile când două echipe pot avea același punctaj.

### Task 5:
- Ultimul task a fost rezolvat transformând `BST`-ul de mai sus într-un `AVL` prin echilibrare și afișând doar echipele de pe nivelul 2 al arborelui.

## Probleme Întâlnite:
- În `main.c` dacă se elimină linia de cod `67` care conține:
```c
(teamList[i]->teamName)[strlen(teamList[i]->teamName) - 1] = '\0';
```
afișările echipelor s-ar face eronat, punându-se o linie goală între echipe.
- La task-ul 3 am observat că în fișierele de intrare apăreau câteva spații în plus, astfel că a trebuit să fac eliminarea spațiilor manual.
