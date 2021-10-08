# **Követelmény specifikáció**

## *1. Jelenlegi helyzet leírása:*
Cégünk egy letisztult felhasználói felülettel rendelkező, hagyományos számológépet biztosít a megrendelőink számára. Ezt egy asztali alkalmazás formájában valósítottuk meg. Számológépünk képes az alapműveletek (szorzás, osztás, összeadás, kivonás) elvégzésére, hatványozásra, gyökvonásra, támogatja a számolást valamennyi szögfüggvénnyel (sin, cos, tg), emellett tudunk törölni, zárójelezni, valamint a már kiszámolt értékeket egy-egy változóban eltárolni.

## *2. Vágyálom rendszer leírása:*
Igény szerint szeretnénk, ha számológépünk Linux operációs rendszeren is futna. Emellett célunk, hogy minél modernebb és barátságosabb felhasználói felületet készítsünk, melyet ügyfeleink nap mint nap szívesen használnak. Fontosnak tartjuk még azt is, hogy számológépünk pontosan számoljon és hibátlanul működjön, és az esetleges hibákat minél hamarabb javítani tudjuk.

## *3.	A rendszerre vonatkozó szabályok:*
- C++ nyelven íródik
- GUI megvalósításához Visual Studio használata
- Könnyű kezelhetőség

## *4.	Jelenlegi üzleti folyamatok modellje:*
- Egyszerű matematika alapművelete elvégzése
- **Összeadás elvégzése:** első szám, a <span style="color:lightblue">„ + ”</span> gomb, majd egy másik szám megadása után a képernyőn megjelenik az összeadás eredménye
- **Kivonás elvégzése:** első szám, a <span style="color:lightblue">„ - ”</span> gomb, majd egy másik szám megadása után a képernyőn megjelenik a kivonás eredménye
- **Szorzás elvégzése:** első szám, a <span style="color:lightblue">„ * ”</span> gomb, majd egy másik szám megadása után a képernyőn megjelenik az szorzás eredménye
- **Osztás elvégzése:** első szám, a <span style="color:lightblue">„ / ”</span> gomb, majd egy másik szám megadása után a képernyőn megjelenik az osztás eredménye
- **Hatványozás elvégzése:** egy szám, majd az <span style="color:lightblue">„ x&#178; ”</span> gomb megnyomása után a képernyőn megjelenik az eredmény
- **Gyökvonás elvégzése:** a <span style="color:lightblue">„ &radic; ”</span> gomb, majd egy szám megadása után a képernyőn megjelenik a gyökvonás eredménye
- **Zárójelezés:** a műveletek elvégzési sorrendjét a <span style="color:lightblue">„ ( ”</span> és a <span style="color:lightblue">„ ) ”</span> gombok megfelelő használatával befolyásolhatjuk
- **Sin:** a <span style="color:lightblue">„ sin ”</span> gomb megnyomása után zárójelek között meg kell adni azt a számot, amelynek a szinuszát szeretnénk kiszámolni, majd az eredmény megjelenik a képernyőn
- **Cos:** a <span style="color:lightblue">„ cos ”</span> gomb megnyomása után zárójelek között meg kell adni azt a számot, amelynek a koszinuszát szeretnénk kiszámolni, majd az eredmény megjelenik a képernyőn
- **Tan:** a <span style="color:lightblue">„ tan ”</span> gomb megnyomása után zárójelek között meg kell adni azt a számot, amelynek a szinuszát szeretnénk kiszámolni, majd az eredmény megjelenik a képernyőn
- **Törlés:** a <span style="color:lightblue">„ &#9003; ”</span> gombbal tudunk karakterenként törölni, a <span style="color:lightblue">„ C ”</span> gombbal az egész eddig beírt karaktersort töröljük 
- **Egyenlőség gomb:** megnyomásával szintén a képernyőre írjuk az eredményt

## *5. Igényelt üzleti folyamatok modellje:*
- Négyzetre emelés mellett hatványozást is tudjunk elvégezni
- <span style="color:lightblue">„ x&#178; ”</span> gomb lecserélése <span style="color:lightblue">„ x<sup>y</sup> ”</span> gombra
- Változók bevezetéséhez szükséges gombok létrehozása
- Tesztek írása

## *6.	Követelmény lista:*
- Átlagos számológép 
- Alapműveletekkel tudjon számolni
- Képes legyen zárójeleket használni
- Képes legyen törölni
- Képes legyen hatványozni és gyököt vonni
- Sin, cos, tg kezelése
- Támogassa a változók használatát
- Legyen egyszerűen kezelhető

## *7.	Fogalomszótár:*
**Összeadás:** összeadás során két számból egy összeget képzünk.<br>
**Kivonás:** kivonás során két szám különbségét kapjuk meg. <br>
**Szorzás:** egy számot annyiszor veszünk összeadandóul, ahányszor a szorzó mutatja. <br>
**Osztás:** a szorzás fordított művelete. <br>
**Hatványozás:** a hatványozást egy olyan speciális szorzatként definiáltuk, amelyben a tényezők megegyeznek és a tényezők száma a hatványkitevő értékével egyezik. <br>
**Gyökvonás:** a hatványozás egyik inverz művelete. <br>
**Szögfüggvények:** trigonometrikus függvények vagy szögfüggvények eredetileg egy derékszögű háromszög egy szöge és két oldalának hányadosa közötti összefüggést írják le. <br>
**Változók:** a számítógép-tudományban azt a helyet értjük alatta, ahol egy mennyiséget tárolhatunk. <br>
**C++:** egy általános célú, magas szintű programozási nyelv. <br>
**GUI:** A grafikus felhasználói felület vagy grafikus felhasználói interfész (angolul graphical user interface, röviden GUI) a számítástechnikában olyan, a számítógép és ember közti kapcsolatot megvalósító elemek összessége, melyek a monitor képernyőjén szöveges és rajzos elemek együtteseként jelennek meg. <br>
**Visual Studio:** A Visual Studio a Microsoft több programozási nyelvet tartalmazó fejlesztőkörnyezete.

