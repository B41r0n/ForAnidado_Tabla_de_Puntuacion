/*
 * ============================================================
 *  TABLA DE PUNTUACIONES - For anidado en C++
 *  Autor original: Grupo 6
 *  
 * ============================================================
 *
 
 *
 * ============================================================
 *  

 *  1. VELOCIDAD REAL: El compilador traduce el código a
 *     instrucciones de máquina ANTES de ejecutarlo.
 *     Python o Java lo interpretan/traducen EN TIEMPO DE
 *     EJECUCIÓN → siempre más lento.
 *
 *  2. CONTROL DE MEMORIA: Los arreglos aquí viven en stack/heap
 *     directamente. No hay garbage collector pausando el programa.
 *
 *  3. OPTIMIZACIÓN DEL FOR ANIDADO: El compilador puede
 *     vectorizar (SIMD) los loops internos automáticamente.
 *     Un intérprete no puede hacer eso.
 *
 *  4. TIPADO ESTRICTO: `int puntajes[J][N]` → el compilador
 *     detecta errores de tipo en compilación, no en ejecución.
 *
 *  5. PORTABILIDAD BINARIA: Compilas una vez → ejecutable.exe
 *     Sin instalar runtime, sin VM, sin intérprete.
 *
 * "Este for anidado O(jugadores × niveles)
 *  en C++ compilado corre directamente en la CPU. En Python el mismo
 *  loop tiene overhead de interpretación en CADA iteración."
 * ============================================================
 */

 // Librerías estándar de C++
#include <iostream>   // cout, cin — entrada/salida por consola
#include <string>     // tipo string — cadenas de texto
#include <iomanip>    // setw — formateo de columnas (ancho fijo)
#include <vector>     // vector — arreglos dinámicos (necesario para MSVC)
using namespace std;

int main() {

    // ── Variables de configuración de la tabla ──────────────────
    int jugadores, niveles;
    int puntajeBase = 100;  // Puntaje base por jugador (escala según fila)
    int bonus = 50;         // Bonus adicional por nivel (escala según columna)

    cout << "=== TABLA DE PUNTUACIONES ===" << endl;
    cout << endl;

    // ── Entrada de datos: tamaño de la tabla ────────────────────
    // El usuario define cuántas filas (jugadores) y columnas (niveles)
    // tendrá la tabla. Esto hace el programa flexible/reutilizable.
    cout << "¿Cuantos jugadores? ";
    cin >> jugadores;
    cout << "¿Cuantos niveles? ";
    cin >> niveles;
    cout << endl;

    // ── Estructuras de datos ────────────────────────────────────
    // NOTA IMPORTANTE: En MSVC (Visual Studio), los arreglos de
    // tamaño variable (VLA) como  int arr[n]  NO están permitidos
    // porque no son estándar C++. Se usan vector<> en su lugar.
    //
    // nombres[i]     → nombre del jugador i
    // puntajes[i][j] → puntaje del jugador i en el nivel j
    vector<string> nombres(jugadores);
    vector<vector<int>> puntajes(jugadores, vector<int>(niveles));

    int mejorPuntajeGeneral = 0;  // Acumula el mejor puntaje global
    string ganador = "";          // Nombre del jugador con mejor puntaje

    // ── Recolección de nombres (for simple) ─────────────────────
    // Recorre cada jugador (índice i) y pide su nombre.
    // Es un for de UNA dimensión: solo recorre filas.
    for (int i = 0; i < jugadores; i++) {
        cout << "Ingresa el nombre del jugador " << i + 1 << ": ";
        cin >> nombres[i];
        cout << endl;
    }

    cout << endl;

    // ── Encabezado de la tabla ───────────────────────────────────
    // Imprime la fila de títulos: espaciado fijo con setw(n).
    // setw(n) reserva n caracteres para el siguiente valor.
    cout << setw(12) << " ";
    for (int j = 1; j <= niveles; j++) {
        // Concatena "Nivel " + número de columna (1-indexado para mostrar)
        cout << setw(9) << "Nivel " + to_string(j);
    }
    cout << setw(9) << "| Mejor" << endl;

    // Línea separadora: longitud dinámica según cantidad de columnas
    cout << string(12 + (niveles * 9) + 9, '-') << endl;

    // ── FOR ANIDADO PRINCIPAL ────────────────────────────────────
    // Complejidad: O(jugadores × niveles) → O(n²) en caso cuadrado
    //
    // FOR EXTERNO: recorre filas → cada jugador (i)
    for (int i = 0; i < jugadores; i++) {

        // Imprime nombre del jugador alineado a la izquierda
        cout << setw(10) << left << nombres[i] << right;

        int mejorDelJugador = 0;  // Resetea el mejor por jugador en cada fila

        // FOR INTERNO: recorre columnas → cada nivel (j)
        // Para cada celda (i,j) calcula y almacena el puntaje.
        // Fórmula: (fila+1)*base + (columna+1)*bonus
        // → los puntajes crecen tanto horizontal como verticalmente
        for (int j = 0; j < niveles; j++) {

            // Cálculo del puntaje de la celda actual
            int puntaje = ((i + 1) * puntajeBase) + ((j + 1) * bonus);

            // Guarda en la matriz 2D para usarlo luego en promedios
            puntajes[i][j] = puntaje;

            // Imprime valor en la columna correspondiente
            cout << setw(9) << puntaje;

            // Actualiza el mejor puntaje de esta fila (jugador)
            if (puntaje > mejorDelJugador) {
                mejorDelJugador = puntaje;
            }
        }
        // ── Fin FOR interno ──────────────────────────────────────

        // Muestra el mejor puntaje del jugador al final de su fila
        cout << setw(9) << "| " + to_string(mejorDelJugador) << endl;

        // Compara con el mejor global para determinar el ganador
        if (mejorDelJugador > mejorPuntajeGeneral) {
            mejorPuntajeGeneral = mejorDelJugador;
            ganador = nombres[i];
        }
    }
    // ── Fin FOR externo ──────────────────────────────────────────

    // Línea separadora final
    cout << string(12 + (niveles * 9) + 9, '-') << endl;

    // ── Fila de promedios por nivel (otro for anidado) ───────────
    // FOR EXTERNO: recorre columnas (niveles) → j
    // FOR INTERNO: recorre filas (jugadores) → i
    // Aquí el orden está INVERTIDO respecto al principal.
    // Propósito: sumar todos los valores de cada columna.
    cout << setw(10) << left << "Promedio:" << right;
    for (int j = 0; j < niveles; j++) {
        int suma = 0;

        // Suma todos los puntajes de la columna j
        for (int i = 0; i < jugadores; i++) {
            suma += puntajes[i][j];
        }

        // División entera — promedio truncado (no redondeado)
        int promedio = suma / jugadores;
        cout << setw(9) << promedio;
    }
    cout << endl;
    cout << endl;

    // ── Resultado final: anuncio del ganador ─────────────────────
    // El jugador con el mayor "mejorDelJugador" de toda la tabla
    cout << "¡El ganador es " << ganador << " con " << mejorPuntajeGeneral << " puntos!" << endl;

    return 0;  // 0 = ejecución exitosa (convención estándar)
}

