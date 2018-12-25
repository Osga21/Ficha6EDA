#define _CRT_SECURE_NO_WARNINGS
#include "Janela.h"
#include "Circulo.h"
#define VERDE RGB(0,255,0)
#define AZUL RGB(0,0,255)
#define VERMELHO RGB(255,0,0)
int main() {
	//Criação de janela
	Janela janela;
	HWND janelaId;
	if (janela.Criar("Mapa Lisboa e arredores","MAPA.bmp")) {
		if ((janelaId = janela.ObterId()) != NULL) {
			
			MSG msg;
			while (GetMessage(&msg, 0, 0, 0)) {
				DispatchMessage(&msg);
				

				FILE *ficheiro;
				ficheiro = fopen("Mapa.txt", "r");
				if (ficheiro == NULL)
					return false;
				else {
					int npontos;
					fscanf(ficheiro, "%d", &npontos);
					Ponto* coords;
					Circulo* local;
					coords = new Ponto[npontos];
					local = new Circulo[npontos];
					int xcoord, ycoord;
					for (int i = 0; i < npontos; i++) {
						fscanf(ficheiro, "%d, %d", &xcoord, &ycoord);
						coords[i] = Ponto(xcoord, ycoord);
						local[i] = Circulo(coords[i],10,i+1);
						local[i].desenhar(janelaId, VERDE);

					}
				}







				if (janela.Click()) {
					
				}

			}
		}
	}
}