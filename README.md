# 📊 TABLA DE PUNTUACIONES - For Anidado en C++

## 📝 Descripción del Proyecto

Este proyecto es un **ejercicio educativo** que demuestra de forma práctica cómo funcionan los **bucles `for` anidados** en C++. El programa genera una tabla de puntuaciones de jugadores en distintos niveles, realiza cálculos interactivos y determina un ganador.

Es especialmente útil para aprender:
- ✅ Bucles `for` anidados (O(n²) complejidad)
- ✅ Matrices bidimensionales (`vector<vector<int>>`)
- ✅ Procesamiento de datos en 2D (filas y columnas)
- ✅ Formateo de salida en consola (alineación, ancho fijo)
- ✅ Entrada/salida de usuario (`cin` / `cout`)

---

## 🔧 Requisitos para Ejecutarse

### Hardware Mínimo
- Procesador: Cualquiera (Pentium 4 en adelante)
- RAM: 512 MB
- Disco: 100 MB

### Software Necesario

#### ✨ Opción 1: Visual Studio Community 2026 (Recomendado - Lo que usas)
```
Versión: Microsoft Visual Studio Community 2026 (18.6.2)
Compilador: MSVC (Microsoft Visual C++)
```

**Instalación:**
1. Descarga desde: https://visualstudio.microsoft.com/vs/community/
2. Durante la instalación, selecciona: `Desktop development with C++`
3. Incluye: MSVC compiler, Windows SDK, CMake tools

#### ✨ Opción 2: MinGW (alternativa gratuita multiplataforma)
```bash
# Windows (con Chocolatey)
choco install mingw

# Linux (Debian/Ubuntu)
sudo apt-get install g++ build-essential

# macOS
brew install gcc
```

#### ✨ Opción 3: Clang/LLVM
```bash
# Todos los sistemas operativos
https://releases.llvm.org/
```

### Bibliotecas Necesarias
✅ **Todas ya están incluidas en el STL (Standard Library) de C++:**
- `<iostream>` → Entrada/salida por consola
- `<string>` → Manejo de cadenas de texto
- `<iomanip>` → Formateo de columnas
- `<vector>` → Arreglos dinámicos

**No requieren instalación adicional**, el compilador las proporciona.

---

## 🚀 Cómo Compilar y Ejecutar

### Opción A: Visual Studio (Interfaz Gráfica)

**1. Abrir el proyecto:**
```
Archivo → Abrir → Proyecto/Solución
Selecciona: ForAnidado\ForAnidado.vcxproj
```

**2. Compilar:**
```
Menú: Compilar → Compilar solución
Atajo: Ctrl + Shift + B
```

**3. Ejecutar:**
```
Menú: Depuración → Iniciar sin depuración
Atajo: Ctrl + F5
```

### Opción B: Terminal PowerShell (Línea de comandos)

```powershell
# 1. Navegar al directorio del proyecto
cd C:\Users\Nico\source\repos\ForAnidado\

# 2. Compilar con MSVC
cl /EHsc ForAnidado\ForAnidado.cpp /Fe:ForAnidado.exe

# 3. Ejecutar
.\ForAnidado.exe
```

### Opción C: Terminal CMD (Línea de comandos)

```cmd
REM 1. Navegar al directorio
cd C:\Users\Nico\source\repos\ForAnidado\

REM 2. Compilar
cl /EHsc ForAnidado\ForAnidado.cpp /Fe:ForAnidado.exe

REM 3. Ejecutar
ForAnidado.exe
```

### Opción D: Con CMake (para proyectos más grandes)

```bash
# 1. Crear carpeta de build
mkdir build
cd build

# 2. Generar archivos de compilación
cmake ..

# 3. Compilar
cmake --build . --config Release

# 4. Ejecutar
./ForAnidado.exe  # en Windows
# o
./ForAnidado      # en Linux/macOS
```

---

## 📊 Flujo del Programa - Paso a Paso

### **Paso 1: Inicialización de Variables**
```cpp
int jugadores, niveles;
int puntajeBase = 100;  // Puntaje base por jugador
int bonus = 50;         // Bonus adicional por nivel
```

**¿Qué sucede?**
- Se declaran variables para almacenar la cantidad de jugadores y niveles
- Se definen constantes para la fórmula de cálculo de puntos

**Salida esperada en consola:**
```
=== TABLA DE PUNTUACIONES ===
```

---

### **Paso 2: Entrada de Datos del Usuario**
```cpp
cout << "¿Cuantos jugadores? ";
cin >> jugadores;           // Usuario escribe: 3
cout << "¿Cuantos niveles? ";
cin >> niveles;             // Usuario escribe: 4
```

**¿Qué sucede?**
- El programa solicita al usuario cuántos jugadores participarán
- Luego pide cuántos niveles (desafíos) habrá

**Entrada del usuario:**
```
¿Cuantos jugadores? 3
¿Cuantos niveles? 4
```

---

### **Paso 3: Creación de Estructuras de Datos**
```cpp
vector<string> nombres(jugadores);                          // 3 espacios para nombres
vector<vector<int>> puntajes(jugadores, vector<int>(niveles)); // Matriz 3x4
```

**¿Qué sucede?**
- Se crea un `vector` dinámico para almacenar los 3 nombres de los jugadores
- Se crea una matriz bidimensional 3×4 para guardar todos los puntajes

**Representación visual:**
```
nombres = ["", "", ""]

puntajes = [
  [0, 0, 0, 0],
  [0, 0, 0, 0],
  [0, 0, 0, 0]
]
```

---

### **Paso 4: Entrada de Nombres (FOR simple)**
```cpp
for (int i = 0; i < jugadores; i++) {
	cout << "Ingresa el nombre del jugador " << i + 1 << ": ";
	cin >> nombres[i];
}
```

**¿Qué sucede?**
- Se recorren los 3 jugadores (i = 0, 1, 2)
- Para cada uno, se pide su nombre

**Entrada del usuario:**
```
Ingresa el nombre del jugador 1: Alice
Ingresa el nombre del jugador 2: Bob
Ingresa el nombre del jugador 3: Charlie
```

**Estado de memoria después:**
```
nombres = ["Alice", "Bob", "Charlie"]
```

---

### **Paso 5: Encabezado de la Tabla**
```cpp
cout << setw(12) << " ";
for (int j = 1; j <= niveles; j++) {
	cout << setw(9) << "Nivel " + to_string(j);
}
cout << setw(9) << "| Mejor" << endl;
```

**¿Qué sucede?**
- Se imprime una fila de títulos centrados y espaciados
- `setw(9)` reserva 9 caracteres de ancho para cada columna

**Salida esperada:**
```
			 Nivel 1  Nivel 2  Nivel 3  Nivel 4| Mejor
```

---

### **Paso 6: FOR ANIDADO PRINCIPAL (El corazón del programa)**

Este es el **concepto central** del ejercicio. Se calcula y visualiza la matriz completa.

```cpp
// FOR EXTERNO: Recorre filas (jugadores)
for (int i = 0; i < jugadores; i++) {

	cout << setw(10) << left << nombres[i] << right;
	int mejorDelJugador = 0;

	// FOR INTERNO: Recorre columnas (niveles)
	for (int j = 0; j < niveles; j++) {

		// Fórmula: (fila+1) × base + (columna+1) × bonus
		int puntaje = ((i + 1) * puntajeBase) + ((j + 1) * bonus);

		puntajes[i][j] = puntaje;  // Guarda en matriz
		cout << setw(9) << puntaje;

		// Actualiza el mejor puntaje de esta fila
		if (puntaje > mejorDelJugador) {
			mejorDelJugador = puntaje;
		}
	}

	cout << setw(9) << "| " + to_string(mejorDelJugador) << endl;
}
```

#### **Explicación Detallada:**

**FOR EXTERNO (i = 0, 1, 2):**
- Itera sobre cada jugador (fila)
- Para Alice (i=0), luego Bob (i=1), luego Charlie (i=2)

**FOR INTERNO (j = 0, 1, 2, 3):**
- Para cada jugador, itera sobre cada nivel (columna)
- Calcula el puntaje usando la fórmula

**Fórmula de cálculo:**
```
puntaje = ((i + 1) × puntajeBase) + ((j + 1) × bonus)
```

**Ejemplo - Cálculo para Alice (i=0) en Nivel 1 (j=0):**
```
puntaje = ((0 + 1) × 100) + ((0 + 1) × 50)
		= (1 × 100) + (1 × 50)
		= 100 + 50
		= 150
```

**Ejemplo - Cálculo para Bob (i=1) en Nivel 3 (j=2):**
```
puntaje = ((1 + 1) × 100) + ((2 + 1) × 50)
		= (2 × 100) + (3 × 50)
		= 200 + 150
		= 350
```

#### **Matriz de Puntajes Generada:**
```
Jugador 1 (Alice):     150, 200, 250, 300  → Mejor: 300
Jugador 2 (Bob):       200, 300, 400, 500  → Mejor: 500
Jugador 3 (Charlie):   300, 400, 500, 600  → Mejor: 600
```

**Complejidad del algoritmo:**
```
Iteraciones totales = jugadores × niveles = 3 × 4 = 12 iteraciones
Complejidad: O(n²) - cuadrática
```

**Salida esperada en consola:**
```
Alice                150      200      250      300| 300
Bob                  200      300      400      500| 500
Charlie              300      400      500      600| 600
```

---

### **Paso 7: Cálculo de Promedios por Nivel (FOR ANIDADO INVERTIDO)**

Aquí ocurre algo interesante: **el orden de los bucles se invierte**.

```cpp
cout << setw(10) << left << "Promedio:" << right;

// FOR EXTERNO: Recorre columnas (niveles)
for (int j = 0; j < niveles; j++) {
	int suma = 0;

	// FOR INTERNO: Recorre filas (jugadores)
	for (int i = 0; i < jugadores; i++) {
		suma += puntajes[i][j];  // Suma verticalmente
	}

	int promedio = suma / jugadores;  // División entera
	cout << setw(9) << promedio;
}
```

**¿Qué sucede?**
- El FOR externo ahora recorre **columnas** (niveles)
- El FOR interno recorre **filas** (jugadores)
- Para cada nivel, suma todos los puntajes de los jugadores

**Cálculo del Promedio - Nivel 1 (j=0):**
```
suma = Alice[0] + Bob[0] + Charlie[0]
	 = 150 + 200 + 300
	 = 650

promedio = 650 / 3 = 216 (división entera)
```

**Salida esperada:**
```
Promedio:           216      300      383      467
```

---

### **Paso 8: Determinación del Ganador**

Durante el paso 6 (FOR principal), se fue guardando el mejor puntaje general:

```cpp
if (mejorDelJugador > mejorPuntajeGeneral) {
	mejorPuntajeGeneral = mejorDelJugador;
	ganador = nombres[i];
}
```

**¿Qué sucede?**
- Se busca al jugador con el **puntaje más alto** de toda la tabla
- En este ejemplo: Charlie con 600 puntos

**Salida final:**
```
¡El ganador es Charlie con 600 puntos!
```

---

## 📥 Ejemplo Completo de Ejecución

### **Entrada del Usuario:**
```
=== TABLA DE PUNTUACIONES ===

¿Cuantos jugadores? 3
¿Cuantos niveles? 4

Ingresa el nombre del jugador 1: Alice
Ingresa el nombre del jugador 2: Bob
Ingresa el nombre del jugador 3: Charlie

```

### **Salida Completa:**
```
=== TABLA DE PUNTUACIONES ===

¿Cuantos jugadores? 3
¿Cuantos niveles? 4

Ingresa el nombre del jugador 1: Alice

Ingresa el nombre del jugador 2: Bob

Ingresa el nombre del jugador 3: Charlie

			 Nivel 1  Nivel 2  Nivel 3  Nivel 4| Mejor
----------------------------------------------------
Alice            150      200      250      300|   300
Bob              200      300      400      500|   500
Charlie          300      400      500      600|   600
----------------------------------------------------
Promedio:        216      300      383      467

¡El ganador es Charlie con 600 puntos!
```

---

## 🧮 Conceptos Clave Explicados

### **1. FOR Anidados (Nested Loops)**
```cpp
for (int i = 0; i < jugadores; i++) {        // FOR EXTERNO (filas)
	for (int j = 0; j < niveles; j++) {      // FOR INTERNO (columnas)
		// Código que se ejecuta jugadores × niveles veces
	}
}
```

**¿Por qué se llama "anidado"?**
- Un bucle está dentro de otro, como cajas rusas (muñecas matrioshka)
- El FOR interno se ejecuta completamente para cada iteración del FOR externo

**Representación visual:**
```
i=0 →  j=0, j=1, j=2, j=3  (4 iteraciones del FOR interno)
i=1 →  j=0, j=1, j=2, j=3  (4 iteraciones del FOR interno)
i=2 →  j=0, j=1, j=2, j=3  (4 iteraciones del FOR interno)
---
Total: 3 × 4 = 12 iteraciones
```

### **2. Complejidad O(n²)**
```
n = número de jugadores
m = número de niveles

Complejidad del tiempo: O(n × m)
En caso cuadrado (n = m): O(n²)

Si jugadores = niveles = 1000:
Iteraciones = 1,000,000 (1 millón)
```

### **3. Matrices Bidimensionales**
```cpp
// Declaración
vector<vector<int>> puntajes(3, vector<int>(4));

// Acceso
puntajes[0][0] = 150;  // Fila 0, Columna 0
puntajes[2][3] = 600;  // Fila 2, Columna 3

// Visualización
puntajes = [
  [150, 200, 250, 300],    // Jugador 0 (Alice)
  [200, 300, 400, 500],    // Jugador 1 (Bob)
  [300, 400, 500, 600]     // Jugador 2 (Charlie)
]
```

### **4. Formateo con `setw()` e `iomanip`**
```cpp
#include <iomanip>

cout << setw(9) << "texto";  // Reserva 9 caracteres de ancho
cout << left << "texto";      // Alineación a la izquierda
cout << right << "texto";     // Alineación a la derecha (por defecto)
```

**Ejemplo:**
```
setw(9) + "150"  →  "      150"  (3 espacios + texto)
left + setw(9) + "Alice"  →  "Alice    "  (texto + 4 espacios)
```

---

## 🔍 Flujo de Control Resumido

```
INICIO
  ↓
Mostrar título
  ↓
Pedir número de jugadores (3)
Pedir número de niveles (4)
  ↓
Crear vector nombres[3]
Crear matriz puntajes[3][4]
  ↓
FOR i = 0 a 2
  Pedir nombre del jugador i
FIN FOR
  ↓
Mostrar encabezado de tabla
  ↓
FOR i = 0 a 2 (jugadores)          ← FOR EXTERNO
  Imprimir nombre del jugador i
  FOR j = 0 a 3 (niveles)          ← FOR INTERNO
	Calcular puntaje[i][j]
	Guardar en matriz
	Imprimir puntaje
	Actualizar mejor del jugador
  FIN FOR INTERNO
  Imprimir mejor del jugador
  Actualizar ganador general
FIN FOR EXTERNO
  ↓
FOR j = 0 a 3 (niveles)            ← FOR EXTERNO (INVERTIDO)
  suma = 0
  FOR i = 0 a 2 (jugadores)        ← FOR INTERNO
	suma += puntajes[i][j]
  FIN FOR INTERNO
  promedio = suma / jugadores
  Imprimir promedio
FIN FOR EXTERNO
  ↓
Mostrar ganador
  ↓
FIN
```

---

## 🐛 Solución de Problemas

### **Problema: "No se abre el proyecto"**
```
Solución: Asegúrate de que Visual Studio está instalado con
C++ Desktop Development. Intenta:
1. Abre Visual Studio Installer
2. Modifica la instalación
3. Marca "Desktop development with C++"
```

### **Problema: "Error de compilación CS0246"**
```
Solución: Verifica que todos los #include estén presentes:
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
```

### **Problema: "El programa no pide entrada"**
```
Solución: Ejecuta con Ctrl+F5 (sin depuración)
Si usas Ctrl+F5, la ventana de consola permanece abierta
```

### **Problema: "Números negativos o errores"**
```
Solución: Verifica que ingreses números válidos (positivos)
Ejemplo válido: 3 jugadores, 4 niveles
```

---

## 📚 Recursos Adicionales

### Conceptos de C++ Relacionados
- **Vectores:** https://cplusplus.com/reference/vector/vector/
- **Iomanip:** https://cplusplus.com/reference/iomanip/
- **For loops:** https://cplusplus.com/doc/tutorial/control/

### Para Practicar Más
1. **Ejercicio 1 - Tabla de Multiplicar:** Modifica para multiplicaciones
2. **Ejercicio 2 - Triángulo de Asteriscos:** Dibuja formas con bucles anidados
3. **Ejercicio 3 - Asientos de Cine:** Matriz con caracteres

---

## 📋 Archivos del Proyecto

```
ForAnidado/
├── ForAnidado.cpp              ← Código fuente principal
├── ForAnidado.vcxproj          ← Archivo de proyecto Visual Studio
├── ForAnidado.vcxproj.filters  ← Filtros del proyecto
└── README.md                   ← Este archivo
```

---

## 👨‍💻 Autor

**Ejercicio original comentado para propósitos educativos**

Demuestra:
- Bucles FOR anidados
- Procesamiento de matrices 2D
- Entrada/salida en consola
- Algoritmos básicos (búsqueda del máximo, promedio)
- Complejidad O(n²)

---

## 📞 Preguntas Frecuentes

**P: ¿Puedo cambiar los valores de puntajeBase y bonus?**
R: ¡Sí! Modifica estas líneas en el código:
```cpp
int puntajeBase = 100;  // Cambia a 50, 200, etc.
int bonus = 50;         // Cambia a 25, 100, etc.
```

**P: ¿Qué pasa si ingreso 0 jugadores?**
R: Los vectores quedarán vacíos y el programa terminará sin errores (pero sin mostrar tabla).

**P: ¿Cómo ingreso números muy grandes?**
R: Puedes ingresar valores como 1000, 10000, etc. El programa recalculará automáticamente.

**P: ¿Por qué la división de promedio es entera?**
R: Porque la variable `promedio` es `int`. Para decimales, cámbiala a `float` o `double`.

---

**Última actualización:** 2026  
**Estado:** ✅ Compilación exitosa  
**Licencia:** Educativo (uso libre)
