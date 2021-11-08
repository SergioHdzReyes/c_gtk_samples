# Compilación

    gcc -o hello main.c `pkg-config --cflags --libs gtk+-3.0` -export-dynamic