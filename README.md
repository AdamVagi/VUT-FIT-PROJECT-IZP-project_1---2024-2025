# VUT-FIT-PROJECT-IZP-project_1-2024-2025
Projekt 1 - Práce s textem

### Popis projektu
Cílem projektu je vytvořit program, který by emuloval zjednodušený algoritmus hledání kontaktů zadaných pomocí posloupnosti číslic. Vstupem programu je posloupnost číslic. Výstup programu bude obsahovat seznam kontaktů, které odpovídají zadanému číselnému filtru.

### Detailní specifikace
Program implementujte ve zdrojovém souboru ''tnine.c''. Vstupní data budou čtena ze standardního vstupu (stdin), výstup bude tisknut na standardní výstup (stdout).

### Překlad a odevzdání zdrojového souboru
Odevzdání: Odevzdejte zdrojový soubor ''tnine.c''.
Překlad: Program překládejte s následujícími argumenty:

```gcc -std=c11 -Wall -Wextra -Werror tnine.c -o tnine

### Syntax spuštění
./tnine CISLO
CISLO zde představuje hledané kritérium, sekvenci číslic 0 až 9, které reprezentují sekvenci hledaných znaků.
Pokud je program spuštěn bez argumentů, program se bude chovat, jako by hledanému kritériu odpovídal každý kontakt ze seznamu.

### Implementační detaily
Telefonní seznam jsou ASCII textová data. Každý záznam o kontaktu obsahuje dva neprázdné řádky: jméno osoby a jeho telefonní číslo. Každý řádek obsahuje maximálně 100 znaků, jinak se jedná o neplatná data. Seznam kontaktů je neuspořádaný. U všech dat nezáleží na velikosti písmen (tzv. case insensitive). Program musí podporovat alespoň 42 kontaktů.

### Kritérium nalezení kontaktu
Pro zjednodušení budeme v tomto projektu uvažovat hledání '''nepřerušené posloupnosti''' zadaných znaků/číslic v telefonním kontaktu. Nepřerušenou posloupností znaků se myslí takový podřetězec, u kterého se na každé pozici vyskytuje znak, který odpovídá jednomu ze znaků, které reprezentuje číslice na stejné pozici v zadaném řetězci. Každá číslice kromě sebe sama reprezentuje ještě následující znaky: 2 (abc), 3 (def), 4 (ghi), 5 (jkl), 6 (mno), 7 (pqrs), 8 (tuv), 9 (wxyz), 0 (+).

### Výstup programu
Výstup programu může být dvojího druhu:

žádný kontakt nenalezen,
nalezen jeden a více kontaktů.
Kontakt nenalezen
*Not found*

Pokud v telefonním seznamu neexistuje kontakt, u něhož by nějaká část odpovídala hledanému řetězci CISLO, vytiskne program toto hlášení.
*Kontakt(y) nalezen(y)*

Každý kontakt, který odpovídá hledanému kritériu, program vytiskne na jeden řádek ve formátu "JMENO, TELCISLO", kde JMENO je jméno kontaktu z telefonního seznamu a TELCISLO je záznam o telefonním čísle. Program tiskne všechny kontakty, které kritériu odpovídají. Na pořadí řádků nezáleží. Stejně tak nezáleží ani na velikosti písmen.

### Omezení v projektu a tipy
Je zakázané použít následující funkce:
volání z rodiny malloc a free - práce s dynamickou pamětí není v tomto projektu zapotřebí,
volání z rodiny fopen, fclose, fseek, fscanf, ... - práce s externími soubory (např. dočasnými) není v tomto projektu žádoucí; volání nad stdin, stdout a stderr jsou v pořádku.
volání qsort, lsearch, bsearch a hsearch - cílem je zamyslet se nad algoritmizací a strukturou dat.
### Poznámky k implementaci:
Program musí podporovat všechna správná vstupní data; může však podporovat i složitější nebo větší data. Musí však znát své vlastní limity a vstupní data vůči nim kontrolovat.
Program má zpracovávat vstupy ze stdin (nikoliv z externích souborů), což může být například vstup od uživatele pomocí klávesnice nebo z přesměrovaného souboru. Z toho také vyplývají omezení vybraných funkcí pro práci se soubory.
Program by měl podporovat alespoň 100 znakový řádek. Může být implementován i tak, že podporuje delší řádky.
Algoritmus programu lze navrhnout tak, že podporuje neomezený počet kontaktů.
### Neočekávané chování
Na chyby za běhu programu reagujte obvyklým způsobem: Na neočekávaná vstupní data (data, která váš program nepodporuje), špatný formát vstupních dat nebo chyby při volání funkcí reagujte přerušením programu se stručným a výstižným chybovým hlášením na příslušný výstup a odpovídajícím návratovým kódem. Chybová hlášení programu budou anglicky.

### Příklady vstupů a výstupů
Pomocný soubor seznam.txt telefonního seznamu:

$ cat seznam.txt
Petr Dvorak
603123456
Jana Novotna
777987654
Bedrich Smetana ml.
541141120
Příklad hledání (pro demonstraci jsou nalezená písmena ve jméně jako velká):
$ ./tnine <seznam.txt
petr dvorak, 603123456
jana novotna, 777987654
bedrich smetana ml., 541141120
$ ./tnine 12 <seznam.txt
petr dvorak, 603123456
bedrich smetana ml., 541141120
$ ./tnine 686 <seznam.txt
jana nOVOtna, 777987654
$ ./tnine 38 <seznam.txt
pETr DVorak, 603123456
bedrich smETana ml., 541141120
$ ./tnine 111 <seznam.txt
Not found
Příklad vstupu z výstupu jiného programu (tedy ani z klávesnice ani ze souboru):
$ printf "Petr Dvorak\n603123456\n" | ./tnine 38 <seznam.txt
pETr DVorak, 603123456
### Hodnocení
7/10
### Priority funkcionality
Vyhledání kontaktů, jejichž telefonní čísla začínají zadaným číslem.
Vyhledání kontaktů, jejichž jména začínají znaky, které zadané číslo reprezentuje.
(nepovinné, avšak může zlepšit hodnocení) Hledání přerušených posloupností znaků. Pokud jako první parametr programu bude -s, program najde i takové kontakty, u který mezi každými dvěma nalezenými znaky může být libovolná posloupnost jiných znaků. Důležité je, že nalezený řetězec (jména nebo telefonního čísla) musí obsahovat všechny znaky, které číslovky reprezentují, a ve stejném pořadí.