#include "time.h"

int* GetTime()
{
	// Zeit in s seit 1970 holen
	std::time_t t;
	t = std::time(0);
	// Zeit in Datum umwandeln
	std::tm* tnow;
	tnow = std::localtime(&t);
	// Einzelne Werte in Array Speichern
	int *nowtime = new int[4];
	nowtime[0] = tnow -> tm_mday;
	nowtime[1] = tnow -> tm_mon + 1;
	nowtime[2] = tnow -> tm_year + 1970;
	return nowtime;
}