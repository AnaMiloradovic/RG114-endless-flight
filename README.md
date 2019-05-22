
# :airplane: Endless Flight 
## :memo: Kratak opis

## :wrench: Podešavanje
### Postupak instalacije i pokretanja:
* Preuzimanje ili kloniranje direktorijuma 
``` git clone https://github.com/MATF-RG18/RG114-endless-flight ```
* Pozicioniranje u direktorijum igre
``` cd RG114-endless-flight ```
* Kompilacija
``` make ```
* Pokretanje igrice
``` ./endlessFlight ```
### Ili objedinjeno:
Za instaliranje i pokretanje igre dovoljno je izvršiti sledeći kod iz terminala:
```
git clone https://github.com/MATF-RG18/RG114-endless-flight && cd RG114-endless-flight && make && ./endlessFlight
```

## :video_game: Gameplay
**Na početku** je aviončić postavljen na centralnu poziciju na stazi. **Pokretanjem igre** (taster <kbd>Space</kbd>) se generiše niz prepreka nasumičnog tipa na nasumičnim pozicijama i omogućava se avionu kretanje (pogledati tabelu ispod). Avion se kreće podrazumevanom brzinom sve dok mu igrač ne zada komandu **ubrzavanja** (<kbd>&uarr;</kbd> ili <kbd>W</kbd>), u tom slučaju se brzina povećava tri puta. Logika podrazumevanog **bodovanja** je takva da se za svaki sekund (okvirno) dobija po **1 bod** i za svako izbegnuto stablo (prepreku) se dobija po **8 bodova**, što se u slučaju ubrzanja povećava na **32 boda**. **Igra se završava** kada se igrač sudari sa nekom od prepreka i tada se može početi ispočetka (<kbd>R</kbd>) ili izaći iz igre (<kbd>Esc</kbd> ili <kbd>Q</kbd>).

### :left_right_arrow: Komande
|  Taster|Komanda  |
|--------|---------|
|<kbd>Space</kbd> | Pokretanje i pauziranje igre|
|<kbd>&larr;</kbd> ili <kbd>A</kbd> |  Skretanje ulevo|
|<kbd>&rarr;</kbd> ili <kbd>D</kbd> | Skretanje udesno|
|<kbd>&uarr;</kbd> ili <kbd>W</kbd> | Ubrzavanje aviona|
|<kbd>&darr;</kbd> ili <kbd>S</kbd> |Usporavanje aviona|
|<kbd>Esc</kbd> ili <kbd>Q</kbd> |Izlaz iz igre|
| <kbd>R</kbd> |Restartovanje igre|
