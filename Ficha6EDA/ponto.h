#pragma once
class Ponto {
private:
	int x, y; // coordenadas do ponto
public:
	Ponto(); // construtor por omissão
	Ponto(int x0, int y0); //construtor para atribuição
	void AtribuirXY(int novo_x, int novo_y); // novas coordenadas
	float ObterDistancia(Ponto p2); // calcula a distancia a um ponto p2
	int ObterX(); // devolve a coordenada x
	int ObterY(); // devolve a coordenada y
};