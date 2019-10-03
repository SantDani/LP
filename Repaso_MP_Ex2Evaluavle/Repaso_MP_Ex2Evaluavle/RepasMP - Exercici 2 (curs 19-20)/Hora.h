#pragma once

class Hora
{
public:
	/*float getX() const { return m_x; }
	void setX(const float x) { m_x = x; }*/
	Hora();
	~Hora();
	Hora(int hora, int minut, int segon) { m_hora = hora; m_minut = minut; m_segon = segon; };
	Hora(const Hora& hora);

	bool validarHora(Hora hora);
	Hora segToHora(int segundo);
	int HoraToSeg(Hora hora);
	void setHora(const int hora) { m_hora = hora; } //porque no hace falta punto y coma? en los gett y setters
	void setMinuts(const int minut) { m_minut = minut; }
	void setSegon(const int segon) { m_segon = segon; }
	int getHora() { return m_hora; }
	int getMinut() { return m_minut; }
	int getSegon() { return m_segon; }

private:
	int m_hora;
	int m_minut;
	int m_segon;
};
