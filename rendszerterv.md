# **Rendszerterv**

## *1. A rendszer célja:*
Csapatunk szeretett volna létrehozni egy letisztult, és könnyen használható számológépet, amely az egyszerűbb matematikai problémák kiszámolására alkalmas. Nem volt célunk minden tudományos számológép által támogatott műveletet implementálni, csak azokat, amelyekre a leggyakrabban van szükség.

## *2. Projekt terv:*
### ***Projekten dolgozó fejlesztők:***
- **Mikáczó Dávid:** vezető fejlesztő
- **Sipos Edit Adrienn:** fejlesztő
- **Csontos Réka Hanga:** fejlesztő

### ***Ütemterv:***
A projekt megvalósításához rendelkezésre álló idő: **4 hét**.

-  **1. hét:** Projektmunka kitalálása, főbb funkciók átbeszélése, feladatkörök felosztása.
-  **2. hét:** Követelmény specifikáció és funkcionális specifikáció megírása.
-  **3. hét:** Rendszerterv készítése, GUI tervezése.
-  **4.hét:** Fejlesztés, tesztelés.

## *3. Funkcionális terv:*
### ***Felhasználó:***
A szoftver teljes egészéhez van hozzáférése:
- Számok összeadása
- Számok kivonása
- Számok szorzása
- Számok osztása
- Számok hatványozása
- Gyökvonás
- Szögfüggvényekkel való számolás
- Eredmények eltárolása változókban
- Zárójelezés
- Törlés

Miután a felhasználó beírta a kiszámolni kívánt problémát, az eredmény automatikusan kiírásra kerül. Az egyenlőség gomb megnyomásakor is megjelenik az eredmény a képernyőn.

### ***Számológép szoftver:***
Miután a fehasználó megadta a kiszámolni kívánt problémát, a számológép elvégzi a bemeneten kapott számokra és operátorokra az aritmetikai műveleteket, majd a kapott eredményt a képernyőre írja.

## *4. Fizikai környezet:*
A számológép Windows környezet alatt futtatható, de tervben van a bővítés, ami által Linux környezet alatt is használható lesz.

**Fejlesztői eszközök:** 
- Visual Studio
- Github
- Trello

## *5. Implementációs terv:*
A számológép C++ nyelven írodik. A felhasználói felület kinézetét a Visual Studio segítségével valósítjuk meg.

## *6. Tesztterv:*
### ***Tesztelés elvei:***
- A szoftver működésében található hibák megtalálása és javítása.
- Szeretenénk, ha számológépünk hibamentesen működne, és pontosan számolna.

### ***Tesztelés folyamata:***
- Manuális tesztelés (felhasználói felület tesztelése)
- Unit tesztelés

### ***Tesztesetek:***
- Egész számok összeadása
- Egész számok kivonása
- Egész számok szorzása
- Egész számokkal osztás
- Lebegőpontos számok összeadása
- Lebegőpontos számok kivonása
- Lebegőpontos számok szorzása
- Lebegőpontos számokkal osztás
- Gyökvonás
- Pozitív és negatív számok összeadása
- Pozitív és negatív számok szorzása
- Negatív számokkal való osztás
- Negatív számokkal való gyökvonás
- Nullával való osztás
- Nullával való szorzás
- Nullával való gyökvonás
- Zárójelezés



  