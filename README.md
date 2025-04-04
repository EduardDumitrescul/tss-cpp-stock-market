# C++ Stock Market
> Proiect Testarea Sistemelor Software

## Setup software
- [C++ 20](https://en.cppreference.com/w/cpp/20)
- [CMake >= 3.30](https://cmake.org/)
- IDE: [CLion](https://www.jetbrains.com/clion/)
- testing framework: [googletest 1.14.0](http://google.github.io/googletest/)
- OS: Windows 11, Ubuntu 24.04, EndeavoursOS 6.13

## Terminologie:
- **stock** = o acțiune reprezintă o unitate de proprietate într-o companie, de obicei sub formă de acțiuni. Acesta oferă acționarului un drept asupra unei părți din activele și profiturile companiei.
- [stock market](https://en.wikipedia.org/wiki/Stock_market) = bursa de valori este o platformă sau o rețea unde acțiunile (și alte instrumente financiare, cum ar fi obligațiunile, mărfurile etc.) sunt cumpărate și vândute.
- **trader** = un trader este o persoană sau o entitate care cumpără și vinde instrumente financiare (precum acțiuni, obligațiuni, mărfuri etc.) pe piața de capital.
- **order** = un ordin reprezintă o instrucțiune dată de un investitor sau trader de a cumpăra sau vinde o anumită cantitate de instrument financiar (de exemplu, acțiuni) la un preț anume sau sub anumite condiții. Exemple de ordine sunt ordinele de piață, ordinele limită și ordinele stop.
- **order book** = cartea de ordine este o listă în timp real, organizată, a ordinelor de cumpărare și vânzare pentru o anumită acțiune sau alt activ pe piață. Ea arată cantitatea și prețul ordinelor plasate de traderi care nu au fost încă executate, oferind o imagine asupra dinamicii cererii și ofertei pe piață.

## Platforme existente
- **https://www.xtb.com/ro**
- **https://www.interactivebrokers.com/**
- **https://robinhood.com/eu/en/about/crypto/**

## Business Logic

### Plasarea unui ordin de cumpărare sau vânzare

Un **ordin** poate fi de mai multe tipuri:

- **Ordin de piață (Market Order)**: Când un trader plasează un ordin de piață, acesta cumpără sau vinde acțiuni la prețul actual de pe piață. Ordinul va fi executat imediat, respectând prețul de pe piața de valori.
  
- **Ordin limită (Limit Order)**: Un ordin limită este un ordin de a cumpăra sau vinde acțiuni doar la un preț specificat. Dacă prețul acțiunii ajunge la valoarea dorită, ordinul va fi executat. Dacă prețul nu ajunge la acea valoare, ordinul va rămâne în **cartea de ordine** și va aștepta să fie îndeplinit.

- **Ordin stop (Stop Order)**: Un ordin stop este activat când prețul acțiunii atinge un anumit prag. Acesta este de obicei folosit pentru a limita pierderile sau pentru a asigura profituri într-o tranzacție.

### Interacțiunea cu Cartea de Ordine

- **Plasarea unui ordin într-o carte de ordine**: Când un trader plasează un ordin, acesta este adăugat într-o **carte de ordine** pentru o anumită acțiune sau activ financiar. De exemplu, un trader poate plasa un ordin de cumpărare limită de 100 de acțiuni ale unei companii la prețul de 50 lei pe acțiune. Această comandă va fi vizibilă pentru alți traderi în **cartea de ordine**.
  
- **Executarea ordinelor**: Dacă există un alt trader care plasează un ordin de vânzare care coincide cu ordinul de cumpărare al unui alt trader (de exemplu, vinde 100 de acțiuni la 50 lei pe acțiune), atunci ordinul va fi executat automat.

### Actualizarea continuă a cărții de ordine

Cartea de ordine se actualizează în timp real. Când un **ordin** este executat, acesta dispare din listă. Dacă prețul unui activ se modifică, **cartea de ordine** va reflecta aceste schimbări. Traderii vor putea vizualiza mereu ofertele disponibile de cumpărare și vânzare.
