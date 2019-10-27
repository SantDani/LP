
int main()
{
	int hora_dia;
	int hora_hora;
	int hora_min;
	int hora_seg;

	int dia = 60 * 60 * 24;
	int segundos =  3600 + 60*55 + 30 ;
	//float diasfloat = segundos / (60 * 60 * 24);
	int cantEleiminar = segundos / (60 * 60 * 24);

	//eliminamos los dias sobrantes
	int segEliminar = dia * cantEleiminar;
	segundos = segundos - segEliminar;
	hora_dia = cantEleiminar;
	//eliminamos horas
	cantEleiminar = segundos / (60 * 60);
	segEliminar = cantEleiminar * (60 * 60);
	hora_hora = cantEleiminar;
	segundos = segundos - segEliminar;
	//eliminamos minutos
	cantEleiminar = segundos / 60;
	segEliminar = cantEleiminar * 60;
	segundos = segundos - segEliminar;
	hora_min = cantEleiminar;
	// eliminamos segundos
	hora_seg = segundos;
	



	return 0;
}