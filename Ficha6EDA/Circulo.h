#pragma once
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "ponto.h"
class Circulo {
private:
	Ponto centro; // coordenadas do centro
	int raio; // raio do c�rculo
	int valor; // n�mero que se escreve dentro do c�rculo
public:
	Circulo(); // construtor por defeito
	Circulo(Ponto c, int r, int v);
	void desenhar(HWND janelaId, long cor); // Desenha graficamente o circulo
	bool contem(Ponto p); // verifica se o ponto est� dentro do circulo
};