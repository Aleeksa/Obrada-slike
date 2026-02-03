#include <stdint.h>
#include <stddef.h>

int clamp(int value) {
    if (value < 0) {
        return 0;
    }
    if (value > 255) {
        return 255;
    }
    return value;
}

/**
 * Primena filtera osvetljenja na sliku.
 * * @param pixels Pokazivač na niz piksela (R, G, B, A).
 * @param num_bytes Ukupan broj bajtova u nizu.
 * @param param Parametar osvetljenja (npr. -50 do 50).
 */
void apply_brightness_filter(uint8_t* pixels, size_t num_bytes, int param) {
    
    // Petlja ide kroz sve piksele (koraci od 4: R, G, B, A)
    for (size_t i = 0; i < num_bytes; i += 4) {
        
        // Čitamo R, G, B vrednosti (koristimo 'int' za proračune da ne pređemo 255)
        int old_r = pixels[i];
        int old_g = pixels[i + 1];
        int old_b = pixels[i + 2];
        // i + 3 je Alpha kanal, ostaje nepromenjen

        // Primenjujemo formulu: new_pixel = old_pixel + param
        
        // Crveni kanal
        int new_r = clamp(old_r + param);
        
        // Zeleni kanal
        int new_g = clamp(old_g + param);
        
        // Plavi kanal
        int new_b = clamp(old_b + param);

        // Vraćanje izmenjenih vrednosti u niz (castovanje nazad u 8-bitni neoznačeni ceo broj)
        pixels[i]     = (uint8_t)new_r;
        pixels[i + 1] = (uint8_t)new_g;
        pixels[i + 2] = (uint8_t)new_b;
    }
}