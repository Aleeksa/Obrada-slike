# Image Processing (Brightness Filter) - WebAssembly

This project enables real-time brightness adjustment on an uploaded image. Pixel processing is performed within a **WebAssembly** module written in **C**, allowing for high-speed manipulation of large data arrays (pixels).

## 📝 Task Overview
The user uploads an image from their device and specifies a brightness value using a parameter (input field or slider). The program takes the original RGB values of each pixel and modifies them in C.



## 🛠 Technologies & Tools
- **Language:** C (for mathematical pixel processing)
- **Libraries:** `stdint.h`, `stddef.h` (for data types and memory management)
- **Runtime:** WebAssembly + JavaScript (Canvas API)
- **Server:** XAMPP (Apache)

## ⚙️ How the Processing Works
1. **JavaScript:** Fetches pixel data from the Canvas using `getImageData`.
2. **Memory:** Data is transferred to the Wasm linear memory using `HEAPU8`.
3. **C Function:** - Receives a pointer to the data buffer.
    - Iterates through each pixel (R, G, B channels).
    - Adds the specified parameter value to each color component.
    - Uses a helper function to clamp the values within the **0 to 255** range.
4. **Rendering:** Modified data is sent back to the Canvas and displayed to the user.



## 💻 Compilation Command
Compilation is performed via the Emscripten terminal:

```bash
emcc source.c -o index.html --shell-file template.html -s EXPORTED_FUNCTIONS=[_apply_filter,_malloc,_free] -s EXPORTED_RUNTIME_METHODS=[ccall,cwrap]
