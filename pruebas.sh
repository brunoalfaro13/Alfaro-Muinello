
#!/bin/bash

EJECUTABLE="./ejercicio6"
CARPETA="../pruebas2/tests/ejercicio6"

TOTAL=0
PASADOS=0
FALLADOS=0

TEMP="salida_temporal.txt"

for entrada in "$CARPETA"/*.in.txt; do

    # Obtener el nombre del archivo sin .in.txt
    base="${entrada%.in.txt}"

    # Construir el nombre del archivo esperado
    esperado="${base}.out.txt"

    nombre=$(basename "$base")

    TOTAL=$((TOTAL + 1))

    # Verificar que exista el archivo esperado
    if [ ! -f "$esperado" ]; then
        echo "[ERROR] $nombre: no existe archivo esperado"
        FALLADOS=$((FALLADOS + 1))
        continue
    fi

    # Ejecutar el programa
    if ! "$EJECUTABLE" < "$entrada" > "$TEMP"; then
        echo "[ERROR] $nombre: el programa terminó con error"
        FALLADOS=$((FALLADOS + 1))
        continue
    fi

    # Comparar resultado obtenido con resultado esperado
    if diff -q "$TEMP" "$esperado" > /dev/null; then
        echo "[OK] $nombre"
        PASADOS=$((PASADOS + 1))
    else
        echo "[FALLO] $nombre"
        FALLADOS=$((FALLADOS + 1))

        # Mostrar diferencias
        diff -u "$esperado" "$TEMP"
    fi

done

rm -f "$TEMP"

echo ""
echo "========== RESUMEN =========="
echo "Total:    $TOTAL"
echo "Pasados:  $PASADOS"
echo "Fallados: $FALLADOS"
echo "============================="
