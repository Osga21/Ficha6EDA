#pragma once
#include <windows.h>
#include "Ponto.h"
class Rectangulo {
private:
	Ponto top_left, bottom_right; // Cantos do rect�ngulo
public:
	Rectangulo();
	Rectangulo(Ponto tl, Ponto br);
	Rectangulo(int x1, int y1, int x2, int y2,HWND janela);
	void desenhar(HWND janelaId, long cor); // Identificador da janela onde se desenha o rect�ngulo
	bool contem(Ponto p); // Verifica se o ponto p est� contido no rectangulo corrente
	bool contem(Rectangulo r); // Verifica se o rect�ngulo r est� contido no rectangulo corrente
	double obterArea();
	int obterPerimetro();
};

