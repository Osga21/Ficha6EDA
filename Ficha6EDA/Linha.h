#pragma once
#include <windows.h>
#include "Ponto.h"
class Linha
{
private:
	Ponto pi, pf; // pi - Ponto inicial da linha
	// pf - Ponto final da linha
public:
	Linha(); // Construtor de defeito
	Linha(Ponto p1, Ponto p2);
	void desenhar(HWND janelaId, long cor); // Desenha graficamente uma linha
	float obterComprimento(); // Comprimento da linha
};