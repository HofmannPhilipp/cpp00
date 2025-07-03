#!/bin/bash

# Dateinamen
ORIGINAL="original.log"
MYTEST="mytest.log"

# Prüfen ob beide Dateien existieren
if [[ ! -f "$ORIGINAL" || ! -f "$MYTEST" ]]; then
  echo "❌ Eine oder beide Log-Dateien fehlen!"
  exit 1
fi

# Timestamp entfernen und sortieren
strip_and_clean() {
  sed -E 's/^\[[0-9_]+\] //' "$1" | sed '/^$/d' | sort
}

# Temporäre Dateien
TMP1=$(mktemp)
TMP2=$(mktemp)

strip_and_clean "$ORIGINAL" > "$TMP1"
strip_and_clean "$MYTEST" > "$TMP2"

# Vergleich durchführen
echo "🔍 Vergleiche Logs ohne Timestamps…"
if diff -u "$TMP1" "$TMP2" > /tmp/log_diff.txt; then
  echo "✅ Die Logs sind identisch (abgesehen vom Timestamp)."
  rm "$TMP1" "$TMP2" /tmp/log_diff.txt
  exit 0
else
  echo "❌ Unterschiede gefunden:"
  echo "-------------------------"
  cat /tmp/log_diff.txt
  echo "-------------------------"
  echo "❗️ Unterschiede betreffen wahrscheinlich Werte wie 'nb_withdrawals'."
  rm "$TMP1" "$TMP2"
  exit 2
fi
