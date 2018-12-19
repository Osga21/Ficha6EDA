#pragma once
class Janela;

class Hist
{
private:
	int* pBins;
	int nBins;
	int vmax;
	long cor_eixos;
	long cor_bins;

public:
	Hist();
	Hist(int* pbins, int nbins);
	~Hist();
	
	void Desenhar(Janela *janela);
	void SetCorEixos(long cor);
	void SetCorBins(long cor);
	float Mediana(float *dados, int ndados);
	float* Sort(float *dados, int sup, int inf);
};

