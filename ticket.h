#include <stdbool.h>
#include "model.h"

void addClientInLine(tLine * line, bool isSpecial);
void makeLineCustomers(tLine * line);
void makeListServiceWindow(tList * list);
void buildScenario(tLine * lineCustomers, tList * listServiceWindow);
void orderAttendance(tLine * lineCustomers);
void attendance(tLine * lineCustomers, tList * listServiceWindow);
