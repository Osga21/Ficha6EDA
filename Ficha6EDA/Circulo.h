#pragma once
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "ponto.h"
class Circulo {
private:
	Ponto centro; // coordenadas do centro
	int raio; // raio do círculo
	int valor; // número que se escreve dentro do círculo
public:
	Circulo(); // construtor por defeito
	Circulo(Ponto c, int r, int v);
	void desenhar(HWND janelaId, long cor); // Desenha graficamente o circulo
	bool contem(Ponto p); // verifica se o ponto está dentro do circulo
};