#pragma once

class Hora
{
public:

	//Constructores
	Hora();
	//~Hora();
	Hora(float hora, float minut, float segon) { m_hora = hora; m_minut = minut; m_segon = segon; };
	Hora(const Hora& hora);

	//funcions
	bool horaValida();
	Hora segToHora(float segundo);
	float HoraToSeg(Hora hora);
	//Poligon& operator=(const Poligon& p);
	Hora operator+(const Hora& h2);
	Hora operator+(const float& segundos);
	bool operator==(const Hora& h);
	bool operator<(const Hora& h);
	Hora operator=(const Hora& h);
	

	//Set
	void setHora(const float hora) { m_hora = hora; }
	void setMinuts(const float minut) { m_minut = minut; }
	void setSegons(const float segon) { m_segon = segon; }

	//Get
	float getHora() { return m_hora; }
	float getMinuts() { return m_minut; }
	float getSegons() { return m_segon; }

private:
	float m_hora;
	float m_minut;
	float m_segon;
	const float DIA_TO_SEG = 60 * 60 * 24;
	const float HORA_TO_SEG = 60 * 60;
	const float MIN_TO_SEG = 60;
};
