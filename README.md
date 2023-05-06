# [LanParty] - Temă
Checker-ul este o aplicație de testare automată a temelor. Este un produs open-source realizat de către și pentru studenții din Facultatea de Automatică și Calculatoare - UPB, și este menit atât să usureze munca asistenților de a corecta teme cât și sa ofere studenților o evaluare cât mai obiectivă.

## Rularea checker-ului
Pentru a verifica functionarea checker-ului va trebui sa descarcati tot depozitul de mai sus, dupa aceasta deschideti un terminal in folderul in care se afla depozitul descarcat si scrieti urmatoarea comanda:
```shell
./checker.sh
```
## Structura directoarelor:
```
lan-party-02-checker
 ├── date/
 │ ├── t1/
 │ │ ├── c.in
 │ │ ├── d.in
 │ ├── ...
 │ │ ├── ...
 │ │ ├── ...
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
 ├── lanparty (Executable)
 ├── main.c
 ├── main.h
 ├── makefile
```