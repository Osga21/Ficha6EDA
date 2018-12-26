#define _CRT_SECURE_NO_WARNINGS
#include "Janela.h"
#include "Circulo.h"
#include "Graph.h"
#define VERDE RGB(0,255,0)
#define AZUL RGB(0,0,255)
#define VERMELHO RGB(255,0,0)
#define DEFAULT RGB(169,172,178)
#define SELECTED RGB(22,142,28)
int main() {
	//Criação de janela
	Janela janela;
	HWND janelaId;
	if (janela.Criar("Mapa Lisboa e arredores","MAPA.bmp")) {
		if ((janelaId = janela.ObterId()) != NULL) {
			
			MSG msg;
			while (GetMessage(&msg, 0, 0, 0)) {
				DispatchMessage(&msg);
				

				FILE *ficheiro;//Leitura de ponto do mapa
				ficheiro = fopen("Mapa.txt", "r");
				if (ficheiro == NULL)
					exit(1);
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
					local[i] = Circulo(coords[i],8,i);
					local[i].desenhar(janelaId, DEFAULT);				
				}
				Graph grafo(npontos);
				FILE *rede;
				rede = fopen("Rede.txt","r");

				if (rede == NULL)
					exit(1);
				
				int nedges;
				fscanf(rede,"%d",&nedges);
				int startp, endp;
				float dist;
				Edge buff;
				Ponto temp;
				for (int i = 0; i < nedges;i++) {
					fscanf(rede,"%d %d",&startp,&endp);
					dist=coords[startp].ObterDistancia(coords[endp]);
					buff = Edge(startp,endp,dist);
					grafo.InsertEdge(buff);
					printf("Inserido %d -- %d dist=%f\n", startp, endp, dist);
				}

				if (janela.Click()) {
					Ponto cursor;
					cursor = janela.ObterPonto();
					for (int i = 0; i < npontos; i++) {
						if (local[i].contem(cursor)) {
							local[i].desenhar(janelaId, SELECTED);
						}
					}

					
				}

			}
		}
	}
}