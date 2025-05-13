// #include "sales_analysis.h"

TSalesDepartment::TSalesDepartment(std::string pDepartmentName, int pEmployeeCount) {
    aDepartmentName = pDepartmentName;
    aEmployeeCount = (pEmployeeCount >= 0) ? pEmployeeCount : 0;
}

TSalesDepartment::~TSalesDepartment() {}

void TSalesDepartment::AddEmployeeSales(double pSale) {
    if (pSale >= 0) {
        aSales.push_back(pSale);
    }
}
//calcula el promedio de ventas
double TSalesDepartment::CalculateAverageSales() const {
    if (aSales.empty()) return 0.0;

    double total = 0.0;
    //recorre el array y suma las ventas
    for (double sale : aSales) {
        total += sale;
    }
    return total / aSales.size(); //divde ventas entre la cantidad
}
//compara  el promedio con un valor esperado
bool TSalesDepartment::MeetsPerformanceThreshold() const {
    double average = CalculateAverageSales();
    return average >= 50000.0;
}
//encuentra el indice del mejor empleado
int TSalesDepartment::FindTopPerformingEmployeeIndex() const {
    if (aSales.empty()) return -1; //si esta vacio retorna -1
    //define una variable con el valor de la primera venta
    double maxSale = aSales[0];
    int index = 0; // indice del empelado
    //recorre todo el array de ventas
    for (size_t i = 1; i < aSales.size(); ++i) {
        if (aSales[i] > maxSale) {
            maxSale = aSales[i];
            index = i;
        }
    }
    return index;
}

std::string TSalesDepartment::GetDepartmentName() const {
    return aDepartmentName;
}
