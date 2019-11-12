#include <stdbool.h>
#include "../model/model.h"

int sortByRange(int max_range, int min_range);
void addClientInLine(tLine * line, bool isSpecial);
void makeLineCustomers(tLine * line, int sizeLineCustomers);
void makeListServiceWindow(tList * list, int sizeListServiceWindow);
void buildScenario(tLine * lineCustomers, tList * listServiceWindow, int sizeLine, int sizeList);
void orderAttendance(tLine * lineCustomers);
void attendance(tLine * lineCustomers, tList * listServiceWindow);
void clearWindows(tList * list);
void blockWindow(tList * list, int windowContent);
bool hasAttendence(tList * list);
void finaleAttendence(tList * list);
