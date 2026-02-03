# Obrada slike (Brightness Filter) - WebAssembly

Ovaj projekat omogućava promenu osvetljenja (brightness) na učitanoj slici u realnom vremenu. Obrada piksela se vrši unutar **WebAssembly** modula napisanog u jeziku **C**, što omogućava brzu manipulaciju velikim nizovima podataka (pikselima).

## 📝 Opis zadatka
Korisnik prilaže sliku sa svog uređaja i pomoću parametra (input polje ili slider) zadaje vrednost za promenu osvetljenja. Program uzima originalne RGB vrednosti svakog piksela i modifikuje ih u C-u.



## 🛠 Tehnologije i alati
- **Jezik:** C (za matematičku obradu piksela)
- **Biblioteke:** `stdint.h`, `stddef.h` (za rad sa tipovima podataka i memorijom)
- **Runtime:** WebAssembly + JavaScript (Canvas API)
- **Server:** XAMPP (Apache)

## ⚙️ Kako funkcionira obrada?
1. **JavaScript:** Dohvata podatke o pikselima sa Canvas-a koristeći `getImageData`.
2. **Memorija:** Podaci se prebacuju u Wasm memoriju koristeći `HEAPU8`.
3. **C funkcija:** - Prima pokazivač na podatke.
    - Prolazi kroz svaki piksel (R, G, B kanali).
    - Dodaje zadatu vrednost parametra na svaku boju.
    - Koristi pomoćnu funkciju za ograničavanje vrednosti u opsegu od **0 do 255**.
4. **Prikaz:** Modifikovani podaci se vraćaju na Canvas i prikazuju korisniku.

## 💻 Komanda za kompajliranje
Kompajliranje je izvršeno putem Emscripten terminala:

```bash
emcc source.c -o index.html --shell-file template.html -s EXPORTED_FUNCTIONS=[_apply_filter,_malloc,_free] -s EXPORTED_RUNTIME_METHODS=[ccall,cwrap]
